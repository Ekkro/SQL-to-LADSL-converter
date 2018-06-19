#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <utility>
#include <set>
#include <algorithm>
//#include "declarations.cpp"
using namespace std;

    /* ..................................................... */
    /* .....................GRAPH.......................... */
    /* ..................................................... */

class Graph {
    /* ..................................................... */
    /* ... */
    string root;

    /* .....JOIN......
           
           structure to save the joins 
            key => name of the table
            Values => ( , )
         */
    
    map<string, pair<string,string> > join;

    /* ..... GROUPBY .....

           structure to save the groupby
            ( , )
         */
    vector<pair <string,string> > groupby;
    
    /* .....TABLES.....

           structure to save the tables
            key => name of the table
            Values => 
                |key => name of the filter
                |Values => filter type  [ type = 0 it is a measure   ]
                                        [ type = 1 it is a dimension ]
         */
    map<string,map<string,int> > tables; 
    
    /* ......FILTER.....
           
           structure to save the filters
            key => name of the table
            Values => filter set 
         */
    map<string, vector<string> > filter;
    
    /* ......SELECT......
       
           structure to save the selects
           set tables
         */
    vector<string> select;

    /* ..................................................... */

        public:

            /* calculates the number of attributes of table */
            /* arguments : name of a table */
            /* returns : the number of attributes */
        int num_attributes(string str){
            return tables[str].size();
        }

            /* add a filter */
            /* arguments : name of a table */
            /* arguments : filter name */
            /* arguments : filter type */
        void add_filter(string Table,string filter, int type = -1){
            tables[Table].insert(pair<string,int>(filter,type));
        }

            /* remove a filter from a table */
            /* arguments : name of a table */
            /* arguments : filter name */
        void remove_filter(string Table,string filter){
            tables[Table].erase(filter);
        }

            /* to serach for a filter in table */
            /* arguments : name of a table */
            /* arguments : filter name */
            /* return : found the filter in the table
                        [ 1 -> found himself ]
                        [ 0 -> if not found  ]
             */
        int search_filter_in_table(string table, string filter){
            for(map<string,int>::iterator it = tables[table].begin(); it != tables[table].end(); ++it) {
                if (it->first.compare(filter)==0) {return 1;}
            }
            return 0;
        }
        

            /* tables that have the filter */
            /* arguments : filter name */
            /* return : set of tables */
        vector<string> search_filter(string filter){
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
        int search_table(string table){
            for(map<string, map<string,int> >::iterator it = tables.begin(); it != tables.end(); ++it) {
                if (it->first.compare(table)==0) {return 1;}
            }
            return 0;
        }

            /* add a table */
            /* arguments : name of a table */
            /* arguments : filter name */
        void add_table(string Table, string filter, int type){
            map<string,int> aux;
            aux[filter] = type;
            pair<map<string, int>::iterator, bool > result;
            tables.insert(pair<string,map<string,int> >(Table, aux));
        }

            /* remove a table */
            /* arguments : name of a table */
        void remove_table(string Table){
            tables.erase(Table);
        }

        // join[Table] é um par
//        void add_join(string Table,string filter, string type ){
//            pair<map<string, string>::iterator, bool > result;
//            join[Table].insert(pair<string,string>(filter,type));
//        }

        // join[Table] é um par
//        void remove_join(string Table,string filter){
//            join[Table].erase(filter);
//        }


            /* add a filter to the group by */
            /* arguments : name of a table */
            /* arguments : filter name */
        void add_groupby(string Table,string filter){
            groupby.push_back(pair<string,string>(Table,filter));
        }

            /* remove a filter to the group by */
            /* arguments : name of a table */
            /* arguments : filter name */
        void remove_groupby(string Table,string filter){
            for (int i = 0; i < groupby.size(); i++) {
                if ((groupby[i].first.compare(Table)==0) && (groupby[i].second.compare(filter)==0)) {
                    groupby.erase(groupby.begin() + i);
                    break;
                }
            }
        }

            /* add a filter to map filters */
            /* arguments : name of a table */
            /* arguments : filter name */
        void add_map_filter(string Table, string Filter){
            filter[ Table ].push_back(Filter);
        }

            /* remove a filter to map filters */
            /* arguments : name of a table */
        void remove_map_Table_filter(string Table){
            filter.erase(Table);
        }

            /* remove a filter to map filters */
            /* arguments : name of a table */
            /* arguments : filter name */
        void remove_map_filter(string Table,string Filter){
            for (int i = 0; i < filter[Table].size(); i++) {
                if (filter[Table][i].compare(Filter)==0){
                    filter[Table].erase(filter[Table].begin() + i);
                    break;
                }
            }
        }

            /* adds a table to the Selects */
            /* arguments : name of a table */
        void add_select(string Table){
            select.push_back(Table);
        }

            /* remove a table to the Selects */
            /* arguments : name of a table */
        void remove_select(string Table){
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
        int is_measured(string Table, string filter){
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
        int is_dimension(string Table, string filter){
            if (tables[Table][filter] == 1) {
                return 1;
            }else return 0;
        }
            /* add a table */
            /* arguments : name of a table */
            /* arguments : filter name */
/*
        void add_table(string Table, string name){
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
        int isThe_same_Table(string attribute1, string attribute2){
            vector<string> v1 = search_filter(attribute1);
            vector<string> v2 = search_filter(attribute2);
            vector<string>::iterator it;
            vector<string> inter(max(v1.size(),v2.size()));

            it = set_intresection(v1.begin(),v1.end(),v2.begin,v2.end(),back_inserter(inter));
            if (inter.size() > 0) {
                return 1;
            }
            else return 0;
         }

};

    /* ..................................................... */
    /* .....................LTREE.......................... */
    /* ..................................................... */

class Ltree {

    /* ............................................... */
    /* .....ltree.........

            structure to represent the logical tree
    */

    vector<string> ltree;
    
    /* ............................................... */
    //vector<pair<string,string>> ltree; possivelmente será necessário alterar o codigo para esta ltree

    public:
    
//        Ltree() {ltree = new vector<string>();}
    
            /* 
               calculates the parent
                arguments : childs index 
                retuens : return parrent
            */
        string Parent(int indice){
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
        string left_child(int indice){
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
        int ind_left_child(int indice){
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
        string right_child(int indice){
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
        int ind_right_child(int indice){
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
        vector<string> childs(int ind){
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
        void add(string value ,int indice ){ ltree[indice] = value; }

            /* 
                computes the index of a filter
                arguments : filter
                return : index
            */
        int indice(string value){
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
        void swap(int indice1,int indice2 ){
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
        string common_ancestor( int indice1, int indice2 ){
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
        void merge(vector<string> vec){
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
        vector<string> split_aux(vector<string> res, int indice1, int indice2){
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
        vector<string> split(int indice1, int indice2){
            vector<string> res;
            return  Ltree::split_aux(res,indice1,indice2);
        }

            /* 
                add a tree to the current tree
                arguments : vector
                arguments : current tree index
                arguments : vector index
            */
        void add_tree(vector<string> v, int ind, int n=0){
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
        void search_nextOR_aux(int parent, int favourite_child){
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


        /* 
            search for the closest node that is an or
            arguments : parent index
            arguments : favourite child
        */
    int ind_Parent(int indice){
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
    vector<int> parents(int i){
       vector<int> res;
       vector<int>::iterator it;
       it = res.begin();
       for (int ind = i;ind_Parent(i)>=0;i = ind_Parent(i)) {
           //res.insert(i);
           it = res.insert (it , i);
       }
       return res;
    }


     string relacao_entre(vector<string> v, int s){
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



    void search_nextOR(Graph g ,int ind){
      if (left_child(ind_left_child(ind)) == "OR" && (g.isThe_same_Table_array(childs(x))==0)){
            search_nextOR_aux(ind_left_child(ind_left_child(ind)),0);
            search_nextOR_aux(ind_right_child(ind_left_child(ind)),1);
      }else{
          if (right_child(ind_left_child(ind)) == "OR" && (g.isThe_same_Table_array(childs(x))==0)){
            search_nextOR_aux(ind_left_child(ind_left_child(ind)),0);
            search_nextOR_aux(ind_right_child(ind_right_child(ind)),1);
          }
      }

    }


    void funcao(Graph g, int x=0){
      if(ltree.ltree[x] == "OR" && (g.isThe_same_Table_array(childs(x))==0)){
            int parent = ltree.ind_Parent(x);
                vector<string> s = ltree.split(0,parent);
                ltree.add_tree(s,ltree.ind_left_child(x));
                ltree.add_tree(s,ltree.ind_right_child(x));
                ltree.add("OR",parent);
                ltree.searh_nextOR(g,parent);
      }else{
        if(t.ltree!="NULL"){
          funcao(g,(ltree.ind_left_child(x));
          funcao(g,(ltree.ind_right_child(x));
        }
      }
    }
    
    void pushLT(int ind){
     swap(ind,ind_Parent(ind));
     int last = pushLT(ind);
     ltree.erase(vec.begin() + last);
     }
     
     int push_aux(int ind){
         if (left_child(ind)!= NULL){
             int child = ind_left_child(ind);
             swap(child,ind);
             push_aux(child);
         }
         if (right_child(ind)!= NULL){
             int child = ind_right_child(ind);
             swap(child,ind);
             push_aux(child);
         }
         return ind;
     }

     void func(int ind){
       if((ltree[ind]=="AND" || ltree[ind]=="OR"){
         if (left_child(ind)== NULL){
           pushLT(ind_right_child(ind));
         }
         if(right_child(ind) == NULL){
           pushLT(ind_left_child(ind));
         }
       }
       if(ltree[ind]!="NULL"){
         func(left_child(ind));
         func(right_child(ind));
         }
    }
};
