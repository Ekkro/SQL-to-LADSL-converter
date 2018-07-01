#include <regex>
#include "declarations.hpp"

string a = "A";
Graph mainGraph;
Graph g;
Ltree l;
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
                if (aux.empty()) {
                    notEmpty.push_back(it->first);
                    f.insert(pair<string, vector<string> >((it->first), aux));
                }
            }

            newgraph.filter = f;

            for(map<string,map<string, string> >::iterator it = tables.begin(); it != tables.end(); ++it) {
                map<string, string> aux;
                for(map<string, string>::iterator i = (it->second).begin(); i != (it->second).end(); ++i) {
                    if (has(notEmpty, i->first)) {
                        aux.insert(pair<string, string> (i->first, i->second));
                    }
                }
                t.insert(pair<string, map<string, string> > ((it->first), aux));
            }

            newgraph.tables= t;

            for(vector<pair<string, string> >::iterator it = groupby.begin(); it != groupby.end(); ++it) {
                if (has(notEmpty,it->second)) {
                    g.push_back(*it);
                }
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
        /*
        void Graph::add_table(string Table, string filter, int type){
            map<string,int> aux;
            aux[filter] = type;
            pair<map<string, int>::iterator, bool > result;
            tables.insert(pair<string,map<string,int> >(Table, aux));
        }
        */

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
        void Graph::add_select(string Table){
            select.push_back(Table);
        }

            /* remove a table to the Selects */
            /* arguments : name of a table */
        void Graph::remove_select(string Table){
            for (int i = 0; i < select.size(); i++) {
                if (select[i].compare(Table)==0) {
                    select.erase(select.begin() + i);
                    break;
                }
            }
        }

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
                return -1;
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
                return -1;
            }else{ return aux; }
            }

            /*
                computes the list of all children
                arguments : fathers index
                retuens : returns the list of all children
            */
        vector<string> Ltree::childs(int ind){
               vector<string> res;
               string aux = right_child(ind);
               if (aux.compare("NULL") != 0) {
                   res.push_back(aux);
                   res.insert(res.end(),childs(ind_right_child(ind)).begin(),childs(ind_right_child(ind)).end());
               }
               aux = left_child(ind);
               if (aux.compare("NULL") != 0) {
                   res.push_back(aux);
                   res.insert(res.end(),childs(ind_left_child(ind)).begin(),childs(ind_left_child(ind)).end());
               }
               return res;
           }

        void Ltree::erasechilds(int ind){
            if (ltree[ind].compare("NULL")) {
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
        void Ltree::add(string value ,int indice ){ ltree[indice] = value; }

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
            return  Ltree::split_aux(res,indice1,indice2);
        }

            /*
                add a tree to the current tree
                arguments : vector
                arguments : current tree index
                arguments : vector index
            */
        void Ltree::add_tree(vector<string> v, int ind, int n){
                vector<string>::iterator it_ind = v.begin() + ind;
                if (v[n] != "NULL") {
                    ltree.insert(it_ind,v[n]);
                    add_tree(v,ind_left_child(ind),ind_left_child(n));
                    add_tree(v,ind_right_child(ind),ind_right_child(n));
                }
        }

            /*
                search for the closest node that is an or
                arguments : parent index
                arguments : favourite child
            */
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
      if(ltree[indice].compare("AND")==0 || ltree[indice].compare("OR")==0){
        return all_same_table_aux(ind_left_child(indice));
      }else{
        smatch m;
        regex e ("\\.([^ ]+)\\ ");
        regex_search (ltree[indice],m,e);
        string s = m[1];
        return getTable(s);
      }
    }
    bool Ltree::all_same_table(int indice){
      string s =all_same_table_aux(indice);
      vector<string> aux = childs(indice);
      smatch m;
      regex e ("\\.([^ ]+)\\ ");
      string s2;
      for(vector<string>::iterator it = aux.begin(); it != aux.end(); ++it) {
        if(it->compare("AND")!=0 && it->compare("OR")!=0){
          regex_search (*it,m,e);
          s2 = getTable(m[1]);
          if(s2.compare(s) != 0){
            return false;
          }
        }
      }
      return true;
    }

    bool Ltree::dependencies(int indice){
      if(ltree[indice].compare("NULL") == 0){
        return true;
      }
      if(ltree[indice].compare("OR") == 0){
        return all_same_table(indice);
      }
      return dependencies(ind_left_child(indice)) && dependencies(ind_right_child(indice));
    }

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

     int Ltree::push_aux(int ind){
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
     swap(ind,ind_Parent(ind));
     int last = push_aux(ind);
     ltree.erase(ltree.begin() + last);
     }


     void Ltree::rewrite(int ind){
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
