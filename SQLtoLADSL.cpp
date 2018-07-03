#include <regex>
#include "SQLtoLADSL.hpp"
using namespace std;



bool has(vector<string> v, string s){
    return  (find(v.begin(), v.end(), s) != v.end());
}



    /* ..................................................... */
    /* .....................GRAPH.......................... */
    /* ..................................................... */


        Graph Graph::clone(vector<string> v){
            Graph newgraph;
            //root
            //join
            //retirar de filter os filtros
            newgraph.root = root;
            newgraph.join = vector<vector<string> >(join);
           // newgraph.tables = map<string,map<string,string> >(tables);

            map<string, vector<string> > f;
            map<string,map<string,string> > t;
            vector<pair <string,string> > g;
            vector<string> notEmpty;

            for(map<string,vector<string> >::iterator it = filter.begin(); it != filter.end(); ++it) {
                vector<string> aux;
                for(vector<string>::iterator i = (it->second).begin(); i != (it->second).end(); ++i) {
                    if (has(v, *i)) {
                        aux.push_back(*i);
                    }
                }
                if (!aux.empty()) {
                    notEmpty.push_back(it->first);
                    f.insert(pair<string, vector<string> >((it->first), aux));
                }
            }

            newgraph.filter = f;

            for(map<string,map<string, string> >::iterator it = tables.begin(); it != tables.end(); ++it) {
                map<string, string> aux;
                for(map<string, string>::iterator i = (it->second).begin(); i != (it->second).end(); ++i) {
                    if (has(notEmpty, i->first) || has(v,i->first)) {
                        aux.insert(pair<string, string> (i->first, i->second));
                    }
                }
                t.insert(pair<string, map<string, string> > ((it->first), aux));
            }

            newgraph.tables= t;

            for(vector<pair<string, string> >::iterator it = groupby.begin(); it != groupby.end(); ++it) {
                //if (has(notEmpty,it->second)) {
                    g.push_back(*it);
                //}
            }

            newgraph.groupby = g;

            return newgraph;

        }

        void Graph::newRoot(string newRoot){
            root = newRoot;
        }
            /* calculates the number of attributes of table */
            /* arguments : name of a table */
            /* returns : the number of attributes */

        int Graph::num_attributes(string str){
            return tables[str].size();
        }

            /* add a filter */
            /* arguments : name of a table */
            /* arguments : filter name */
            /* arguments : filter type */
/*
        void Graph::add_filter(string Table,string filter, int type ){
            tables[Table].insert(pair<string,int>(filter,type));
        }
*/
            /* remove a filter from a table */
            /* arguments : name of a table */
            /* arguments : filter name */
/*
        void Graph::remove_filter(string Table,string filter){
            tables[Table].erase(filter);
        }
*/
            /* to serach for a filter in table */
            /* arguments : name of a table */
            /* arguments : filter name */
            /* return : found the filter in the table
                        [ 1 -> found himself ]
                        [ 0 -> if not found  ]
             */
        int Graph::search_filter_in_table(string table, string filter){
            for(map<string,string>::iterator it = tables[table].begin(); it != tables[table].end(); ++it) {
                if (it->first.compare(filter)==0) {return 1;}
            }
            return 0;
        }


            /* tables that have the filter */
            /* arguments : filter name */
            /* return : set of tables */
        vector<string> Graph::search_filter(string filter){
            vector<string> aux;
            for(map<string, map<string,string> >::iterator it = tables.begin(); it != tables.end(); ++it) {
                if (search_filter_in_table(it->first,filter)) {
                    aux.push_back(it->first);
                }
            }
            return aux;
        }

            /* look for a table */
            /* arguments : name of the table */
            /* return : if you found it or not
                        [ 1 -> found himself ]
                        [ 0 -> if not found  ]
             */
        int Graph::search_table(string table){
            for(map<string, map<string,string> >::iterator it = tables.begin(); it != tables.end(); ++it) {
                if (it->first.compare(table)==0) {return 1;}
            }
            return 0;
        }

            /* add a table */
            /* arguments : name of a table */
            /* arguments : filter name */

        void Graph::add_table(string Table, string filter, string type){
            map<string,string> aux = tables[Table];
            aux[filter] = type;
            tables[Table] = aux;
        }


            /* remove a table */
            /* arguments : name of a table */
        /*
        void Graph::remove_table(string Table){
            tables.erase(Table);
        }
        */

        void Graph::add_join(string fk,string table1, string table2){
            vector<string> aux ;
            aux.push_back(fk);
            aux.push_back(table1);
            aux.push_back(table2);
            join.push_back(aux);
        }

//        // join[Table] é um par
//        void Graph::remove_join(string fk){
//            join.erase(fk);
//        }


            /* add a filter to the group by */
            /* arguments : name of a table */
            /* arguments : filter name */
        void Graph::add_groupby(string Table,string filter){
            groupby.push_back(pair<string,string>(Table,filter));
        }

            /* remove a filter to the group by */
            /* arguments : name of a table */
            /* arguments : filter name */
        void Graph::remove_groupby(string Table,string filter){
            for (int i = 0; i < groupby.size(); i++) {
                if ((groupby[i].first.compare(Table)==0) && (groupby[i].second.compare(filter)==0)) {
                    groupby.erase(groupby.begin() + i);
                    break;
                }
            }
        }

            /* add a filter to map filters */
            /* arguments : filter name */
            /* arguments : expression */
        void Graph::add_map_filter(string Filter, string expression){
            filter[ Filter ].push_back(expression);
        }

        bool Graph::search_map_filter(string s){
            for(map<string,vector<string> >:: iterator it = filter.begin(); it != filter.end() ; ++it){
              if(it->first.compare(s) == 0){
                return true;
              }
            }
            return false;
        }

        string Graph::search_map_filter2(string s){
          for(map<string,vector<string> >:: iterator it = filter.begin(); it != filter.end() ; ++it){
            for(vector<string>:: iterator it2 = it->second.begin(); it2 != it->second.end() ; ++it2){
              if(it2->compare(s) == 0){
                return it->first;
              }
            }
          }
          return s;
        }

        string Graph::search_table_filter(string s){
          string aux = search_map_filter2(s);
          vector<string> aux2 = search_filter(aux);
          return aux2[0];
        }

            /* remove a filter to map filters */
            /* arguments : name of a table */
        void Graph::remove_map_Table_filter(string Table){
            filter.erase(Table);
        }

            /* remove a filter to map filters */
            /* arguments : name of a table */
            /* arguments : filter name */
        void Graph::remove_map_filter(string Table,string Filter){
            for (int i = 0; i < filter[Table].size(); i++) {
                if (filter[Table][i].compare(Filter)==0){
                    filter[Table].erase(filter[Table].begin() + i);
                    break;
                }
            }
        }

            /* adds a table to the Selects */
            /* arguments : name of a table */
        void Graph::add_select(string sel, string alias){
            select.push_back(pair<string,string>(sel,alias));
        }

            /* remove a table to the Selects */
            /* arguments : name of a table */
        /*
        void Graph::remove_select(string Table){
            for (int i = 0; i < select.size(); i++) {
                if (select[i].compare(Table)==0) {
                    select.erase(select.begin() + i);
                    break;
                }
            }
        }
*/
            /* whether it is measured or not */
            /* arguments : name of a table */
            /* arguments : filter name */
            /* return : if you found it or not
                        [ 1 -> found himself ]
                        [ 0 -> if not found  ]
             */
        int Graph::is_measured(string Table, string filter){
            if (tables[Table][filter].compare("measure") == 0) {
                return 1;
            }else return 0;
        }

            /* whether it is dimension or not */
            /* arguments : name of a table */
            /* arguments : filter name */
            /* return : if you found it or not
                        [ 1 -> found himself ]
                        [ 0 -> if not found  ]
             */
        int Graph::is_dimension(string Table, string filter){
            if (tables[Table][filter].compare("dimension") == 0) {
                return 1;
            }else return 0;
        }
            /* add a table */
            /* arguments : name of a table */
            /* arguments : filter name */
/*
        void Graph::add_table(string Table, string name){
            Graph[Table].insert(filter,str);
        }
*/

            /* test if two attributes are from the same table */
            /* arguments : name of the first attribute */
            /* arguments : name of the second attribute */
            /* return : whether they are from the same table or not
                        [ 1 -> if they are ]
                        [ 0 -> if no       ]
             */
//        int Graph::isThe_same_Table(string attribute1, string attribute2){
//            vector<string> v1 = search_filter(attribute1);
//            vector<string> v2 = search_filter(attribute2);
//            vector<string>::iterator it;
//            vector<string> inter(max(v1.size(),v2.size()));
//
//            it = set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),inter.begin());
//            if (inter.size() > 0) {
//                return 1;
//            }
//            else return 0;
//        }

        int Graph::isThe_same_Table(string attribute1, string attribute2){
         if ( relacao_entre_arrays(search_filter(attribute1),search_filter(attribute2))=="NULL") {
             return 0;
         }else {return 1;}
        }

        int Graph::isThe_same_Table_array(vector<string> v){
         int res = 1;
         for(vector<string>::iterator it = v.begin(); it != v.end(); ++it) {
             if (!isThe_same_Table(v[0],*it)) {
                 res = 0;
                 break;
             }
         }
         return res;
        }

/* ........................................................................ */
    /* ..................................................... */
    /* .....................LTREE.......................... */
    /* ..................................................... */
        Ltree::Ltree(){
            ltree = vector<string>();
        }

        Ltree::Ltree(string s){
            ltree = vector<string>();
            ltree.push_back(s);
        }

            /*
               calculates the parent
                arguments : childs index
                retuens : return parrent
            */
        string Ltree::Parent(int indice){
            string res = "NULL";
            int aux = (indice-1)/2;
            if ( aux <0 || aux >= ltree.size()) {
                return res;
            }else{ return ltree[aux]; }
            }


            /*
                left child
                arguments : fathers index
                retuens : return son of the left
            */
        string Ltree::left_child(int indice){
            string res = "NULL";
            int aux = 2*indice+1;
            if ( aux <0 || aux >= ltree.size()) {
                return res;
            }else{ return ltree[aux]; }
            }


            /*
                left child index
                arguments : fathers index
                retuens : return the left child index
            */
        int Ltree::ind_left_child(int indice){
            int aux = 2*indice+1;
            if ( aux <0 || aux >= ltree.size()) {
                return aux;
            }else{ return aux; }
            }

            /*
                rigth child
                arguments : fathers index
                retuens : return son of the rigth
            */
        string Ltree::right_child(int indice){
            string res = "NULL";
            int aux = 2*indice+2;
            if ( aux <0 || aux >= ltree.size()) {
                return res;
            }else{ return ltree[aux]; }
            }

            /*
                rigth child index
                arguments : fathers index
                retuens : return the rigth child index
            */
        int Ltree::ind_right_child(int indice){
            int aux = 2*indice+2;
            if ( aux <0 || aux >= ltree.size()) {
                return aux;
            }else{ return aux; }
            }

            /*
                computes the list of all children
                arguments : fathers index
                retuens : returns the list of all children
            */
        vector<string> Ltree::childs_aux(vector<string> v1, vector<string> v2){
          for(int x = 0; x < v2.size(); x++){
            v1.push_back(v2[x]);
          }
          return v1;
        }


        vector<string> Ltree::childs(int ind){
               vector<string> res;
               string aux = right_child(ind);
               if (aux.compare("NULL") != 0) {
                   res.push_back(aux);
                   res = childs_aux(res,childs(ind_right_child(ind)));
               }
               aux = left_child(ind);
               if (aux.compare("NULL") != 0) {
                   res.push_back(aux);
                   res = childs_aux(res,childs(ind_left_child(ind)));
               }
               return res;
           }



        void Ltree::erasechilds(int ind){
            ltree.reserve(1+ind);
            if (ltree[ind].compare("NULL") != 0) {
                ltree[ind] = "NULL";
                erasechilds(ind_left_child(ind));
                erasechilds(ind_right_child(ind));
            }
        }
            /*
                adds a filter to the tree
                arguments : filter
                arguments : index
            */
        void Ltree::add(string value ,int indice ){
          int x = ltree.size();
          while(x<=indice){
              ltree.push_back("NULL");
              x++;
          }
          ltree[indice] = value;
        }

            /*
                computes the index of a filter
                arguments : filter
                return : index
            */
        int Ltree::indice(string value){
           for ( int i = 0; i < ltree.size(); i++ ) {
               if (!ltree[i].compare(value)) {
                   return i;
               }
           }
           return -1;
        }

            /*
                change the position of one filter,
                by the position of the other
                arguments : index1
                arguments : index2
            */
        void Ltree::swap(int indice1,int indice2 ){
            string aux;
            ltree.reserve(1+max(indice1,indice2));
            aux = ltree[indice1];
            ltree[indice1] = ltree[indice2];
            ltree[indice2] = aux;
        }


            /*
                calculates the father, common to both,closer
                arguments : index1
                arguments : index2
                return : father
            */
        string Ltree::common_ancestor( int indice1, int indice2 ){
            ltree.reserve(1+max(indice1,indice2));
            vector<int> parent_1 = parents(indice1);
            vector<int> parent_2 = parents(indice2);
            for ( int i = 0;i < parent_1.size(); i++) {
              for ( int j = 0; j < parent_2.size();j++)
                if (parent_1[i] == parent_2[j]) {
                    return(ltree[parent_1[i]]);
                }
            }
            return "NULL";
        }

            /*
                merge the current vector with another
                arguments : vector
            */
        void Ltree::merge(vector<string> vec){
            for ( int i = 0; ltree.size(); i++) {
                if ((!ltree[i].compare("NULL")) && (vec[i].compare("NULL")==0)) {
                    ltree[i] = vec[i];
                }
            }
        }

            /*
                separates into two trees (AUX)
                arguments : vector
                arguments : index1
                arguments : index2
            */
        vector<string> Ltree::split_aux(vector<string> res, int indice1, int indice2){
            if (!ltree[indice2].compare("NULL")) {
                return res;
            }
            res[indice1] = ltree[indice2];
            vector<string> aux1 = Ltree::split_aux(res,ind_left_child(indice1),ind_left_child(indice2));
            vector<string> aux2 = Ltree::split_aux(res,ind_right_child(indice1),ind_right_child(indice2));
            //return aux1.merge(aux2);
            return res;
        }

            /*
                separates into two trees
                arguments : index1
                arguments : index2
            */
        vector<string> Ltree::split(int indice1, int indice2){
            vector<string> res;
            ltree.reserve(1+max(indice1,indice2));
            return  Ltree::split_aux(res,indice1,indice2);
        }

            /*
                add a tree to the current tree
                arguments : vector
                arguments : current tree index
                arguments : vector index
            */
        void Ltree::add_tree(vector<string> v, int ind, int n){
          if(n < v.size()){
                while(ltree.size()<=ind){
                  ltree.push_back("NULL");
                }
                ltree.at(ind)=v[n];
                if (v[n].compare("NULL") != 0) {
                  add_tree(v,ind_left_child(ind),ind_left_child(n));
                  add_tree(v,ind_right_child(ind),ind_right_child(n));
                }
            }
        }

            /*
                search for the closest node that is an or
                arguments : parent index
                arguments : favourite child
            */
            /*
        void Ltree::search_nextOR_aux(int parent, int favourite_child){
            if (favourite_child) {
               swap(parent,ind_right_child(parent));
               add("NULL",ind_left_child(parent));
               add("NULL",ind_right_child(parent));
            }else{
               swap(parent, ind_left_child(parent));
               add("NULL",ind_left_child(parent));
               add("NULL",ind_right_child(parent));
                }
        }
*/



/*
     string Ltree::relacao_entre(vector<string> v, int s){
         vector<int> aux = parents(s);
         int i = 0;
         for(vector<string>::iterator it = v.begin(); it != v.end(); ++it) {
             aux = subvector(aux,parents(i));
             i++;
         }
         if (aux.size()) {
             return ltree[aux[0]];
         }else {return "NULL";}//nunca acontece em teoria mas quem sabe
     }

*/
        /*
            search for the closest node that is an or
            arguments : parent index
            arguments : favourite child
        */
    int Ltree::ind_Parent(int indice){
        int aux = (indice-1)/2;
        if ( aux <0 || aux >= ltree.size()) {
            return -1;
        }else{ return aux; }
    }
        /*
            all the parents of given node
            arguments : child index
            return : vector with all parents
        */
    vector<int> Ltree::parents(int i){
       vector<int> res;
//       vector<int>::iterator it;
 //      it = res.begin();
       for (int ind = i;ind_Parent(ind)>=0;i = ind_Parent(ind)) {
           //res.insert(i);
           res.push_back(ind);
       }
       return res;
    }

    string Ltree::all_same_table_aux(int indice){
      ltree.reserve(1+indice);
      if(ltree[indice].compare("AND")==0 || ltree[indice].compare("OR")==0){
        return all_same_table_aux(ind_left_child(indice));
      }else{
        return mainGraph.search_table_filter(ltree[indice]);
      }
    }
    bool Ltree::all_same_table(int indice){
      ltree.reserve(1+indice);
      string s =all_same_table_aux(indice);
      vector<string> aux = childs(indice);
      string s2;
      for(vector<string>::iterator it = aux.begin(); it != aux.end(); ++it) {
        if(it->compare("AND")!=0 && it->compare("OR")!=0 && it->compare("NULL")!=0){
          s2 = mainGraph.search_table_filter(*it);
          if(s2.compare(s) != 0){
            return false;
          }
        }
      }
      return true;
    }

    bool Ltree::dependencies(int indice){
      ltree.reserve(1+indice);
      if(ltree[indice].compare("AND") == 0){
        return dependencies(ind_left_child(indice)) && dependencies(ind_right_child(indice));
      }
      if(ltree[indice].compare("OR") == 0){
        return all_same_table(indice);
      }
      return true;
    }
/*
    void Ltree::search_nextOR(Graph g ,int ind){
      if (left_child(ind_left_child(ind)) == "OR" && (g.isThe_same_Table_array(childs(ind))==0)){
            search_nextOR_aux(ind_left_child(ind_left_child(ind)),0);
            search_nextOR_aux(ind_right_child(ind_left_child(ind)),1);
      }else{
          if (right_child(ind_left_child(ind)) == "OR" && (g.isThe_same_Table_array(childs(ind))==0)){
            search_nextOR_aux(ind_left_child(ind_left_child(ind)),0);
            search_nextOR_aux(ind_right_child(ind_right_child(ind)),1);
          }
      }

    }


    void Ltree::funcao(Graph g, int x){
      if(ltree[x] == "OR" && (g.isThe_same_Table_array(childs(x))==0)){
            int parent = ind_Parent(x);
                vector<string> s = split(0,parent);
                add_tree(s,ind_left_child(x),0);
                add_tree(s,ind_right_child(x),0);
                add("OR",parent);
                search_nextOR(g,parent);
      }else{
        if(ltree[x]!="NULL"){
          funcao(g,(ind_left_child(x)));
          funcao(g,(ind_right_child(x)));
        }
      }
    }
*/
     int Ltree::push_aux(int ind){
        ltree.reserve(1+ind);
         if (left_child(ind)!= "NULL"){
             int child = ind_left_child(ind);
             swap(child,ind);
             push_aux(child);
         }
         if (right_child(ind)!= "NULL"){
             int child = ind_right_child(ind);
             swap(child,ind);
             push_aux(child);
         }
         return ind;
     }

    void Ltree::pushLT(int ind){
      ltree.reserve(1+ind);
      swap(ind,ind_Parent(ind));
      int last = push_aux(ind);
      ltree.erase(ltree.begin() + last);
    }


     void Ltree::rewrite(int ind){
       ltree.reserve(1+ind);
       if((ltree[ind]=="AND" || ltree[ind]=="OR")){
         if (left_child(ind)== "NULL"){
           pushLT(ind_right_child(ind));
         }
         if(right_child(ind) == "NULL"){
           pushLT(ind_left_child(ind));
         }
       }
       if(ltree[ind]!="NULL"){
         rewrite(ind_left_child(ind));
         rewrite(ind_right_child(ind));
         }
    }
    Ltree create_tree(string term, string type){
        Ltree res ;
        if (type.compare("JOIN") == 0) {
            res.add("NULL",0);
        }else{
            res.add(term,0);
            res.add("NULL",1);
            res.add("NULL",2);
        }
        return res;
    }

    Ltree join_trees(Ltree l1, Ltree l2, string type){
        Ltree res;
        res.add(type,0);
        res.add_tree(l1.ltree, 1,0);
        res.add_tree(l2.ltree, 2,0);
        return res;
    }

    string getTable(string attribute) {
        int ind = attribute.find(".");
        if (ind != (-1)) {
            attribute = attribute.substr(ind);
        }
        vector<string> v = mainGraph.search_filter(attribute);
        if (v.size() < 1 || v.size() > 2) {
            return "";
        }else{
            return v[0];
        }
    }

     vector<int> subvector (vector<int> v1, vector<int> v2){
         vector<int> res(max(v1.size(),v2.size()));
         vector<int>::iterator aux;
         aux = set_intersection (v1.begin(), v1.end(), v2.begin(), v2.end(), res.begin());
         res.resize(aux-res.begin());
         return res;
     }

    string relacao_entre(vector<string> v, string s){
        vector<int> aux = l.parents(l.indice(s));
        for(vector<string>::iterator it = v.begin(); it != v.end(); ++it) {
            aux = subvector(aux,l.parents(l.indice(*it)));

        }

        if (aux.size()) {
            int x = aux[0];
            l.ltree.reserve(1+x);
            return l.ltree[x];
        }else {return "NULL";}
    }

    string relacao_entre_arrays(vector<string> v, vector<string> s){
        for(vector<string>::iterator it = v.begin()+1; it != v.end(); ++it) {
            s.push_back(*it);
        }
        return relacao_entre(s,v[0]);
    }


void next(){
  if(a[a.length()-1] == 'Z'){
    a.append("A");
  }else{
    a[a.length()-1]++;
  }
}

void joinAtrD(vector<string> v, string type){
  if(v.size()>=1){
    next();
    cout << a << " = filter(" << v[0];
    for(vector<string>::iterator it = v.begin()+1; it != v.end(); ++it) {
      cout << " " << type << " " << *it;
    }
    cout << ")\n";
  }
}

void joinAtr(string start, string type){
  //pega nos filtros no mesmo atributo
  //map<string,int> work = g.tables[start];
  map<string,string> work( g.tables[start] );
  vector<string> v;
  //vector<string,int> new_elements;
  map<string,string> new_elements;
  for(map<string,string>::iterator it = work.begin(); it != work.end(); ++it) {
    string s = it->first;
    //vector<string> v = g.filter[s];
    if((it->second).compare("measure") == 0 || s.find(".")==string::npos){ //se for medida
      new_elements.insert(pair<string,string>(it->first,it->second));
    }else{
      vector<string> v ( g.filter[s] );
      joinAtrD(v,type);
      new_elements.insert(pair<string,string>(a,it->second));
    }
  }
  g.tables[start] = new_elements;
}


void joinFiltersD(vector<string> v, string type){
  next();
  string s;
  if(type.compare("AND") == 0){
    s = "krao";
  }else{
    s = "kraoOR";
  }
  cout << a << " = "<< s <<"(" << v[0] << ", " << v[1] << ")\n";
  for(vector<string>::iterator it = v.begin()+2; it != v.end(); ++it) {
    string aux = a;
    next();
    cout << a << " = " << s <<"(" << aux << ", " << *it << ")\n";
  }
}

void joinFilters(string start, string type){
  //pega nos filtros da mesma tabela
  string aux;
  string aux2;
  map<string,string> work (g.tables[start]);
  vector<string> medidas;
  vector<string> dimensoes;
  for(map<string,string>::iterator it = work.begin(); it != work.end(); ++it) {
    string s = it->first;
    if((it->second).compare("measure") == 0){ //se for medida
      vector<string> filters= g.filter[s];
      for(vector<string>::iterator it = filters.begin(); it != filters.end(); ++it){
        medidas.push_back(*it);
      }
    }else{                //se for dimensao
      dimensoes.push_back(s);
    }
  }
  joinAtrD(medidas,type);
  aux = a;
  if(dimensoes.size() > 0){
    if( dimensoes.size() == 1){
      aux2 = dimensoes[0];
    }else{
      joinFiltersD(dimensoes,type);
      aux2 = a;
    }
  }
  if(dimensoes.size()>0 && medidas.size()>0){
    next(); // verificar se é and ou or entre aux1 e aux2
    if(type.compare("AND") == 0){
      cout << a << " = " << "krao" << "(" << aux << ", " << aux2 << ")\n";
    }else{
      cout << a << " = " << "kraoOR" << "(" << aux << ", " << aux2 << ")\n";
    }
  }
  if(dimensoes.size()>0){
    map<string,string> t;
    t[a]="dimension";
    g.tables[start] = t;
  }else{
    if(medidas.size()>0){
      map<string,string> t;
      t[a]="measure";
      g.tables[start] = t;
    }
  }
}


void joinGroupbyAux(string gb, string start){
  string alpha = a;
  next();
  cout << a << " = krao(" << alpha << "," << gb << ")\n";
  map<string,string> work;
  work[a]="dimension";
  g.tables[start]=work;
}

void joinGroupby(string start){
  if(g.groupby.size()>0 && g.tables[start].size()>0){
    for(vector<pair<string,string> >::iterator it = g.groupby.begin(); it != g.groupby.end(); ++it) {
      if((it->first).compare(start) == 0){
        joinGroupbyAux(it->second,start);
      }
    }
  }
}

void removeTable(string start){
  vector<vector <string> > Keys;
  string alpha = a;
  if (g.tables[start].size() <= 1) {
    for(vector<vector<string> >::iterator it = g.join.begin(); it != g.join.end(); ++it) {
      if((it->at(2)).compare(start) == 0){
        if(g.tables[start].size() > 0){
          next();
          cout << a << " = " << "dot(" << alpha << ", " << it->at(0)<< ")\n";
          map<string,string> aux = g.tables[it->at(1)];
          aux[a] = "dimension";
          g.tables[it->at(1)] = aux;
        }
      }else{
        Keys.push_back(*it);
      }
    }
    g.join = Keys;
  }
}

string giveMeStart(string root){
  if(g.join.size() > 0){
    for(vector<vector<string> >::iterator it = g.join.begin(); it != g.join.end(); ++it) {
      if((it->at(1)).compare(root) == 0){
        //cout << it->at(1) << "\n";
        return giveMeStart(it->at(2));
      }
    }
  }
  return root;
}

string giveMeFinish(string root, vector<string> v){
  if(mainGraph.join.size() > 0){
    for(vector<vector<string> >::iterator it = mainGraph.join.begin(); it != mainGraph.join.end(); ++it) {
      if(has(v,it->at(1)) && !(has(v,it->at(2)))){
        return it->at(2);
      }
    }
  }
  return root;
}

void print_tables3(){
  cout << "======================" << "\n";
  for(map<string,map<string,string> >::iterator it = g.tables.begin(); it != g.tables.end(); ++it) {
    cout << it->first << ":\n";
    for(map<string,string>::iterator it2 = g.tables[it->first].begin(); it2 != g.tables[it->first].end(); ++it2) {
      cout << it2->first <<"\n";
    }
  }
  cout << "--------------------" << "\n";
}


void graphWorkAux(int x,string type){
  //pega nas pontas
  string start = giveMeStart(g.root);
  //juntar filtros do mesmo atributo dessa tabela, no final a tabela terá aoenas letras.
  joinAtr(start, type);
  //juntar tudo
  joinFilters(start, type);
  //juntar groupbys
  //joinGroupby(start, type);
  joinGroupby(start);
  //remover tabela e adicionar como atributo às seguintes
  if(x == 1)removeTable(start);
}

void graphWork(string type){
  while (!g.join.empty()) {// parar quando só houver uma tabela com atributos
    graphWorkAux(1,type);
  }
  graphWorkAux(0,type);
}




//void trabalha(int ind){
//  trabalhaaux(l.ind_left_child(ind),string tabela1);
//  trabalhaaux(l.ind_right_child(ind),string tabela2);
//}
//
//void trabalhaaux(int ind, int count){
//    if(is_the_same_table_array(childs(ind)) == 0 )
//      if(left_child(ind) == "AND" || right_child(ind) == "AND")
//        trabalhaaux(int ind);
//}
/*
void cleanexp(){
current_expression.clear();
current_expression2.clear();
}

void addexp(string exp){
if (current_expression.empty()){
    current_expression = exp;
    return;
}
current_expression2 = exp;
}

void aux(string exp){
if (current_expression2.empty()){
    mainGraph.add_map_filter( current_expression, exp);
}else {
    mainGraph.add_join(current_expression2,getTable(current_expression),getTable(current_expression2));
}
}
*/


void print_tables2(){
  cout << "======================" << "\n";
  for(map<string,map<string,string> >::iterator it = mainGraph.tables.begin(); it != mainGraph.tables.end(); ++it) {
    cout << it->first << ":\n";
    for(map<string,string>::iterator it2 = mainGraph.tables[it->first].begin(); it2 != mainGraph.tables[it->first].end(); ++it2) {
      cout << it2->first <<"\n";
    }
  }
  cout << "--------------------" << "\n";
}

void merge(vector<string> v){
// g
// mainGraph
  pair<string,string> aux;
  string table;
  for(map<string,map<string, string> >::iterator it = g.tables.begin(); it != g.tables.end(); ++it) {
    if (!((it->second).empty())) {
        for(map<string, string> ::iterator i = (it->second).begin(); i != (it->second).end(); ++it) {
            aux = pair<string,string>(i->first,i->second);
            table = it->first;
            break;
        }
        break;
      }
  }

  mainGraph.tables[table].insert(aux);
  //empty table
  vector<string> emptyfilter;

  map<string, vector<string> > newfilter;
  for(map<string,vector<string> >::iterator it = mainGraph.filter.begin(); it != mainGraph.filter.end(); ++it) {
      vector<string> aux;
      for(vector<string>::iterator i = (it->second).begin(); i != (it->second).end(); ++i) {
          if (!has(v, *i)) {
              aux.push_back(*i);
          }
      }
      if (!aux.empty()) {
          newfilter.insert(pair<string,vector<string> >(it->first,aux));
      }else{ emptyfilter.push_back(it->first);}
      //acrescenta no empty
      }
      mainGraph.filter = newfilter;
      vector<pair<string,string> > eraseIt;

  for(map<string,map<string, string> >::iterator it = mainGraph.tables.begin(); it != mainGraph.tables.end(); ++it) {
     // se it->second->first in empty elimina map<string,string>
      for(map<string, string>::iterator i = (it->second).begin(); i != (it->second).end(); ++i) {
          if (has(emptyfilter, i->first) || has(v,i->first)) {
              eraseIt.push_back(make_pair(it->first, i->first));
          }
      }
  }
  for(vector<pair<string,string> >::iterator it = eraseIt.begin(); it != eraseIt.end(); ++it) {
      mainGraph.tables[it->first].erase(it->second);
  }
}
/*
void dot_all(){
  for(vector<vector<string> >::iterator it = mainGraph.join.begin(); it != mainGraph.join.end(); ++it) {
    string key = it->at(0);
    string table = it->at(1);
    string table2 = it->at(2);
    map<string,string> aux = mainGraph.tables[table];
    for(map<string,string>::iterator it = mainGraph.tables[table2].begin(); it != mainGraph.tables[table2].end(); ++it) {
      next();
      cout << a << " = " << "dot(" << it->first << ", " << key << ")\n";
      aux[a] = "dimension";
    }
    mainGraph.tables[table] = aux;
  }
}*/
void print_tables(){
  cout << "======================" << "\n";
  for(map<string,map<string,string> >::iterator it = g.tables.begin(); it != g.tables.end(); ++it) {
    cout << it->first << ":\n";
    for(map<string,string>::iterator it2 = g.tables[it->first].begin(); it2 != g.tables[it->first].end(); ++it2) {
      cout << it2->first <<"\n";
    }
  }
  cout << "--------------------" << "\n";
}


void print_tree(){
  for(int x = 0; x<l.ltree.size(); x++){
    cout << l.ltree[x] << "\n";
  }
  cout << "\n";
}

void dot_all_aux(string start){
  string alpha = a;
  if (mainGraph.tables[start].size() <= 1) {
    for(vector<vector<string> >::iterator it = mainGraph.join.begin(); it != mainGraph.join.end(); ++it) {
      if((it->at(2)).compare(start) == 0){
        if(mainGraph.tables[start].size() > 0){
          map<string,string> aux = mainGraph.tables[it->at(1)];
          for(map<string,string>::iterator it2 = mainGraph.tables[start].begin(); it2 != mainGraph.tables[start].end(); ++it2){
            if(!mainGraph.search_map_filter(it2->first)){
              next();
              cout << a << " = " << "dot(" << it2->first << ", " << it->at(0) << ")\n";
              aux[a] = "dimension";
              l.ltree[l.indice(it2->first)] = a;
            }else{
              for(vector<string>::iterator it3 = mainGraph.filter[it2->first].begin(); it3 != mainGraph.filter[it2->first].end(); ++it3){
                next();
                cout << a << " = " << "dot(" << *it3 << ", " << it->at(0) << ")\n";
                aux[a] = "dimension";
                l.ltree[l.indice(*it3)] = a;
              }
            }
          }
          mainGraph.tables[it->at(1)] = aux;
          mainGraph.tables[it->at(2)].clear();
        }
      }
    }
  }
}


void dot_all(){
  vector<string> aux;
  aux.push_back(mainGraph.root);
  string start;
  for(int x = 0; x < mainGraph.tables.size(); x++){
    start = giveMeFinish(mainGraph.root,aux);
    dot_all_aux(start);
    aux.push_back(start);
  }
}


void resolveS(int indice, string type){
  vector<string> v =  l.childs(indice);
  g = mainGraph.clone(v);
  graphWork(type);
  l.ltree.reserve(1+indice);
  l.ltree[indice] = a;
  l.erasechilds(l.ind_left_child(indice));
  l.erasechilds(l.ind_right_child(indice));
  merge(v); //between mainGraph and g...
//^^cuidado com vários filters no memso atributo, retirar de table e filter apenas se g.filter(atributo)==mainGraph.filter(atributo), caso contrário apenas retira as entradas iguais
}


void resolve(int indice){
  l.ltree.reserve(1+indice);
  if(l.ltree[indice].compare("OR") == 0){
    resolve(l.ind_left_child(indice));
    resolve(l.ind_right_child(indice));
    if(l.dependencies(indice) == true){
      resolveS(indice,"OR");
    }else{
      dot_all();
      resolve(indice);
    }
  }
  if(l.ltree[indice].compare("AND") == 0){
    if(has(l.childs(indice),"OR")){
      resolve(l.ind_left_child(indice));
      resolve(l.ind_right_child(indice));
      resolveS(indice,"AND");
    }else{
      resolveS(indice,"AND");
    }
  }
}

void returnf(){
  vector<string> aux;
  vector<string> aux2;
  string alpha = a;
  if(mainGraph.select[0].first.compare("*")!=0){
    for(vector<pair<string,string> >::iterator it = mainGraph.select.begin(); it != mainGraph.select.end(); ++it) {
      if((it->second).compare("")==0){
        next();
        cout << a << "= filter(" << it->first << ")\n";
        string alpha2 = a;
        next();
        cout << a << " = krao(" << alpha << "," << alpha <<")\n";
        aux.push_back(a);
      }else{
        string s = it->first;
        size_t found = s.find("(");
        s.erase (0,found);
        s.pop_back();
        next();
        cout << a << " =map" << s << ")\n";
        string alpha2 = a;
        next();
        cout << a << " = krao(" << alpha2 << "," << alpha <<")\n";
        s = it->first;
        s.erase (found,s.size()-found);
        cout << it->second << " = " << s << "(" << a << ")\n";
        aux.push_back(it->second);
      }
    }
    cout << "return(" << aux[0];
    for(vector<string>::iterator it = aux.begin()+1; it != aux.end(); ++it) {
      cout << ", " << *it;
    }
    cout << ")\n";
  }else{
    cout << "return(" << a << ")\n";
  }
}
void change_trees(Ltree t2, int ind){
  for(int x = 0; x < trees.size(); x++ ){
    if(x == ind){
      trees[x]=t2;
    }
  }
}

void copy_tree(Ltree t){
  for(int x = 0; x<t.ltree.size(); x++){
    l.ltree.push_back(t.ltree[x]);
  }
}



void print_trees(){
  for(int x = 0; x<trees.size(); x++){
    for(int y = 0; y<trees[x].ltree.size(); y++){
      cout << trees[x].ltree[y] << "\n";
    }
    cout << "\n";
  }
  cout << "\n";
}

void print_joins(){
  for(int x = 0; x < mainGraph.join.size();x++){
    for(int y = 0; y < mainGraph.join[x].size();y++){
      cout <<  mainGraph.join[x].at(y) << " ,";
    }
    cout << "\n";
  }
}



int main(){
  mainGraph.add_table("lineitem_l","lineitem_l.extendedprice","measure");
  mainGraph.add_table("lineitem_l","lineitem_l.discount","measure");
  mainGraph.add_table("lineitem_l","lineitem_l.shipdate","dimension");
  mainGraph.add_table("lineitem_l","lineitem_l.quantity","measure");
  mainGraph.add_select("sum(lineitem_l.extendedprice * lineitem_l.discount)","revenue");
  //mainGraph.add_select("lineitem_l.quantity","");
  mainGraph.newRoot("lineitem_l");
  mainGraph.add_map_filter("lineitem_l.shipdate","lineitem_l.shipdate >= '1994-01-01'");
  trees.push_back(create_tree("lineitem_l.shipdate >= '1994-01-01'","lineitem_l.shipdate"));
  mainGraph.add_map_filter("lineitem_l.shipdate","lineitem_l.shipdate < '1994-01-01' + interval '1' year");
  trees.push_back(create_tree("lineitem_l.shipdate < '1994-01-01' + interval '1' year","lineitem_l.shipdate"));
  change_trees(join_trees(trees[0],trees[1],"AND"),0);
  mainGraph.add_map_filter("lineitem_l.discount","lineitem_l.discount between 0.06 - 0.01 and 0.06 + 0.01");
  trees.push_back(create_tree("lineitem_l.discount between 0.06 - 0.01 and 0.06 + 0.01","lineitem_l.discount"));
  change_trees(join_trees(trees[0],trees[2],"AND"),0);
  mainGraph.add_map_filter("lineitem_l.quantity","lineitem_l.quantity < 24");
  trees.push_back(create_tree("lineitem_l.quantity < 24","lineitem_l.quantity"));
  change_trees(join_trees(trees[0],trees[3],"AND"),0);
  copy_tree(trees[0]);
  print_tree();
  resolve(0);
  returnf();
  return 0;
}
