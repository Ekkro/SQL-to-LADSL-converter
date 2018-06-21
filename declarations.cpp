 //#include <stdio.h>                                                                                                                      
 //#include <strings.h>
 //#include <vector>
 //#include <iostream>
 //#include <map>
 //#include <utility>
 #include "SQLtoLADSL.hpp"
using namespace std;



string a = "A";
Graph g;
Ltree l;


    /* ..................................................... */
    /* .....................GRAPH.......................... */
    /* ..................................................... */


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
        void Graph::add_filter(string Table,string filter, int type ){
            tables[Table].insert(pair<string,int>(filter,type));
        }

            /* remove a filter from a table */
            /* arguments : name of a table */
            /* arguments : filter name */
        void Graph::remove_filter(string Table,string filter){
            tables[Table].erase(filter);
        }

            /* to serach for a filter in table */
            /* arguments : name of a table */
            /* arguments : filter name */
            /* return : found the filter in the table
                        [ 1 -> found himself ]
                        [ 0 -> if not found  ]
             */
        int Graph::search_filter_in_table(string table, string filter){
            for(map<string,int>::iterator it = tables[table].begin(); it != tables[table].end(); ++it) {
                if (it->first.compare(filter)==0) {return 1;}
            }
            return 0;
        }
        

            /* tables that have the filter */
            /* arguments : filter name */
            /* return : set of tables */
        vector<string> Graph::search_filter(string filter){
            vector<string> aux;
            for(map<string, map<string,int> >::iterator it = tables.begin(); it != tables.end(); ++it) {
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
            for(map<string, map<string,int> >::iterator it = tables.begin(); it != tables.end(); ++it) {
                if (it->first.compare(table)==0) {return 1;}
            }
            return 0;
        }

            /* add a table */
            /* arguments : name of a table */
            /* arguments : filter name */
        void Graph::add_table(string Table, string filter, int type){
            map<string,int> aux;
            aux[filter] = type;
            pair<map<string, int>::iterator, bool > result;
            tables.insert(pair<string,map<string,int> >(Table, aux));
        }

            /* remove a table */
            /* arguments : name of a table */
        void Graph::remove_table(string Table){
            tables.erase(Table);
        }

        // join[Table] é um par
//        voidGraph:: add_join(string Table,string filter, string type ){
//            pair<map<string, string>::iterator, bool > result;
//            join[Table].insert(pair<string,string>(filter,type));
//        }

        // join[Table] é um par
//        void Graph::remove_join(string Table,string filter){
//            join[Table].erase(filter);
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
            if (tables[Table][filter] == 0) {
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
            if (tables[Table][filter] == 1) {
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
         }else {return "NULL";}
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
     

     void Ltree::func(int ind){
       if((ltree[ind]=="AND" || ltree[ind]=="OR")){
         if (left_child(ind)== "NULL"){
           pushLT(ind_right_child(ind));
         }
         if(right_child(ind) == "NULL"){
           pushLT(ind_left_child(ind));
         }
       }
       if(ltree[ind]!="NULL"){
         func(ind_left_child(ind));
         func(ind_right_child(ind));
         }
    }
/* ........................................................................ */

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
                return l.ltree[x];
            }else {return "NULL";}
        }

        string relacao_entre_arrays(vector<string> v, vector<string> s){
            for(vector<string>::iterator it = v.begin()+1; it != v.end(); ++it) {
                s.push_back(*it);
            }
            return relacao_entre(s,v[0]);
        }




void graphWork(){
  while (!g.join.empty()) {
    graphWorkAux(1);
  }
  graphWorkAux(0);
}

void graphWorkAux(int x){
  //pega nas pontas
  string start = giveMeStart(g.root);
  //juntar filtros do mesmo atributo dessa tabela, no final a tabela terá aoenas letras.
  joinAtr(start);
  //juntar tudo
  joinFilters(start);
  //juntar groupbys
  joinGroupby(start);
  //remover tabela e adicionar como atributo às seguintes
  if(x == 1)removeTable(start);
}

void joinAtr(string start){
  //pega nos filtros no mesmo atributo
  //map<string,int> work = g.tables[start];
  map<string,int> work( g.tables[start] );
  vector<string> v;
  //vector<string,int> new_elements;
  map<string,int> new_elements;
  for(map<string,int>::iterator it = work.begin(); it != work.end(); ++it) {
    string s = it->first;
    //vector<string> v = g.filter[s];
    vector<string> v ( g.filter[s] );
    if(it->second == 1){ //se for medida
      new_elements.insert(pair<string,int>(it->first,it->second));
    }else{                //se for dimensao
      joinAtrD(s,v);
      new_elements.insert(pair<string,int>(a,it->second));
    }
  }
  g.tables[start] = new_elements;
}

void joinAtrD(string s, vector<string> v){
  vector<string> resolvidos;
  vector<string> relacoes;
  resolvidos.push_back(v[0]);
  for(int x = 1; x < v.size(); x++){
    relacoes.push_back(relacao_entre(resolvidos,v[x]));
    resolvidos.push_back(v[x]);
  }
  next();
  if(resolvidos.size()>1){
    cout << a << "=filter(" << s <<resolvidos.back() << relacoes.back();
    for(int x = v.size()-2; x > 0; x--){
      cout << "("<< s << resolvidos[x] << relacoes[x-1];
    }
    cout << s << resolvidos[0];
    for(int x = 0; x < relacoes.size()-1; x++)
      cout << ")";
    cout << ")\n";
  }else{
    cout << a << "=filter("  << v[0] << ")\n";
  }
}

void joinFilters(string start){
  //pega nos filtros da mesma tabela
  string aux;
  string aux2;
  map<string,int> work = g.tables[start];
  vector<string> medidas;
  vector<string> dimensoes;
  for(map<string,int>::iterator it = work.begin(); it != work.end(); ++it) {
    string s = it->first;
    if(it->second == 0){ //se for medida
      vector<string> filters= g.filter[s];
      for(vector<string>::iterator it = filters.begin(); it != filters.end(); ++it){
        medidas.push_back(*it);
      }
    }else{                //se for dimensao
      dimensoes.push_back(s);
    }
  }
  if( medidas.size() == 1){
    aux = medidas[0];
  }else{
    joinFiltersM(medidas);
    aux = a;
  }
  if( dimensoes.size() == 1){
    aux2 = medidas[0];
  }else{
    joinFiltersD(dimensoes);
    aux2 = a;
  }
  if(dimensoes.size()>0 && medidas.size()>0){
    next(); // verificar se é and ou or entre aux1 e aux2
    string relacao =relacao_entre_arrays(medidas,dimensoes);
    cout << a << "=" << relacao << "(" << aux << "," << aux2 << ")\n";
  }
}

void joinFiltersM(vector<string> v){
  vector<string> resolvidos;
  vector<string> relacoes;
  resolvidos.push_back(v[0]);
  for(int x = 1; x < v.size(); x++){
    relacoes.push_back(relacao_entre(resolvidos,v[x]));
    resolvidos.push_back(v[x]);
  }
  next();  // a > 3 ; b < 6 ; u > 6
  if(resolvidos.size()>1){
    cout << a << "=filter(" << resolvidos.back() << relacoes.back();
    for(int x = v.size()-2; x > 0; x--){
      cout << "("<< resolvidos[x] << relacoes[x-1];
    }
    cout << v[0];
    for(int x = 0; x < relacoes.size()-1; x++)
      cout << ")";
    cout << ")\n";
  }else{
    cout << a << "=filter("  << v[0] << ")\n";
  }
}

void joinFiltersD(vector<string> v){
  next();
  cout << a << "= krao(" << v[0] << "," << v[1] << ")\n";
  for(int x = 1; x < v.size() ; x++){
    string aux = a;
    next();
    cout << a << "=" << "krao(" << aux << "," << v[x] << ")\n";
  }
}

void joinGroupby(string start){
  for(vector<pair<string,string> >::iterator it = g.groupby.begin(); it != g.groupby.end(); ++it) {
    if(it->first.compare(start)){
      joinGroupbyAux(it->second);
    }
  }
}

void joinGroupbyAux(string gb){
  string alpha = a;
  next();
  cout << a << "=krao(" << alpha << "," << gb << ")\n";
}

void removeTable(string start){
  vector<string> removedKeys;
  string alpha = a;
  for(map<string,pair<string,string> >::iterator it = g.join.begin(); it != g.join.end(); ++it) {
    if(it->second.second.compare(start)){
      next();
      cout << a << "=" << "dot(" << alpha << "," << it->first << ")\n";
      map<string,int> aux = g.tables[start];
      aux[a] = 1;           //possivel zona a melhorar
      g.tables[start] = aux;
      removedKeys.push_back(it->first);
    }
  }
  for(int x = 0; x< removedKeys.size(); x++){
    g.join.erase(removedKeys[x]);
  }
}

string giveMeStart(string root){
  vector<pair<string, string> > values;
  for(map<string,pair<string,string> >::iterator it = g.join.begin(); it != g.join.end(); ++it) {
    values.push_back(it->second);
  }
  for(int x = 0; x < values.size(); x++){
    if(values[x].first==root){
      return giveMeStart(values[x].second);
    }
  }
  return root;
}

void next(){
  if(a[a.length()-1] == 'Z'){
    a.append("A");
  }else{
    a[a.length()-1]++;
  }
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

int main(){
    return 0;
}









