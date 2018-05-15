#include <vector>
#include <string>
#include <iostream>
#include <map>
using namespace std;
class Ltree {

    vector<String> ltree;
    Public:
//        Ltree() {ltree = new vector<string>();}
        String Parent(int indice){ return ltree[(indice-1)/2]; } 
        int ind_Parent(int indice){ return ((indice-1)/2); } 
        
        String left_child(int indice){ return ltree[(2*indice+1)]; } 
        int ind_left_child(int indice){ return (2*indice+1); } 
        
        String right_child(int indice){ return ltree[(2*indice+2)]; } 
        int ind_right_child(int indice){ return (2*indice+2); } 
        
        void add(String value ,int indice ){ ltree[indice] = value; }

        int indice(String value){
           for ( int i = 0; i < ltree.size(); i++ ) {
               if (!ltree[i].compare(value)) {
                   return i;
               }
           }
           return -1;
        }
        
        void swap(int indice1,int indice2 ){
            String aux;
            aux = ltree[indice1]; 
            ltree[indice1] = ltree[indice2];
            ltree[indice2] = aux;
        }
        
        vector<Strings> parents(int i){
           vector<String> res;
           for (int ind = i;ind_Parent[i]>0;i = ind_Parent(i)) {
               res.insert(Parent(i));
           }
           return res;
        }

        String common_ancestor( int indice1, int indice2 ){
            vector<String> parrent_1 = parrents(indice1);
            vector<String> parrent_2 = parrents(indice2);
            for ( int i = 0;i < min(parrent_1.size(),parrent_2.size()); i++) {
                if (!parrent_1[i].compare(parrent_2[i])) {
                    return(parrent_1[i]);
                }
            }
        }
        void merge(vector<String> vec){
            for ( int i = 0; ltree.size(); i++) {
                if ((!ltree[i].compare("NULL")) && (vec.compare("NULL")==0)) {
                    ltree[i] = vec[i]
                }
            }
        }

        vector<String> split_aux(vector<String> res, int indice1, int indice2){
            if (ltree[indice2].compare("NULL")) {
                return res;
            }
            res[indice1] = ltree[indice2];
            vector<String> aux1 = ltree.split_aux(res,ind_left_child(indice1),ind_right_child(indice2));
           // vector<String> aux2 = ltree.split_aux(res,ind_left_child(indice1),ind_right_child(indice2));
            return aux1.merge(aux1);
            
        }

        vector<String> split(int indice1, int indice2){
            vector<String> res;
            return  ltree.split_aux(res,indice1,indice2);
        }

}

class Graph {
    
    Map<String, vector< vector<String> > > graph;
    Map<String, String> attribute_table;
    Public:
        int num_attributes(String str){
            int count = 0;
            for (int i = 0;graph[str].size(); i++) {
                if (graph[str][i][1].compare("NULL")) { // diffrent strings
                    count++;
                }
            }
            return count;
        }
        void add_filter(String Table,String filter, String str){
            graph[Table].insert(filter,str);
            attribute1[filter] = Table;
        }
        void add_table(String Table, String name){
            graph[Table].insert(filter,str);
        }

        int isThe_same_Table(String attribute1, String attribute2){
            if (!attribute_table[attribute1].compare(attribute_table[attribute2])) {
                return 1;
            }
            else return 0;
        
 }
