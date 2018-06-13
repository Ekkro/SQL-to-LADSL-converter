#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <utility>
using namespace std;
class Ltree {

    vector<String> ltree;
    //vector<pair<String,String>> ltree; possivelmente será necessário alterar o codigo para esta ltree
    Public:
//        Ltree() {ltree = new vector<string>();}
        String Parent(int indice){
            String res = "NULL";
            int aux = (indice-1)/2;
            if ( aux <0 || aux >= ltree.size()) {
                return res;
            }else{ return ltree[aux]; }
            }

        int ind_Parent(int indice){
            int aux = (indice-1)/2;
            if ( aux <0 || aux >= ltree.size()) {
                return -1;
            }else{ return aux; }
            }

        String left_child(int indice){
            String res = "NULL";
            int aux = 2*indice+1;
            if ( aux <0 || aux >= ltree.size()) {
                return res;
            }else{ return ltree[aux]; }
            }

        int ind_left_child(int indice){
            int aux = 2*indice+1;
            if ( aux <0 || aux >= ltree.size()) {
                return -1;
            }else{ return aux; }
            }

        String right_child(int indice){
            String res = "NULL";
            int aux = 2*indice+2;
            if ( aux <0 || aux >= ltree.size()) {
                return res;
            }else{ return ltree[aux]; }
            }

        int ind_right_child(int indice){
            int aux = 2*indice+2;
            if ( aux <0 || aux >= ltree.size()) {
                return -1;
            }else{ return aux; }
            }

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

        vector<int> parents(int i){
           vector<int> res;
           for (int ind = i;ind_Parent(i)>=0;i = ind_Parent(i)) {
               res.insert(i);
           }
           return res;
        }

        String common_ancestor( int indice1, int indice2 ){
            vector<int> parent_1 = parents(indice1);
            vector<int> parent_2 = parents(indice2);
            for ( int i = 0;i < parent_1.size(); i++) {
              for ( int j = 0; j < parent_2.size();j++)){}
                if (parent_1[i] == parent_2[j]) {
                    return(ltree[parent_1[i]]);
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
            if (!ltree[indice2].compare("NULL")) {
                return res;
            }
            res[indice1] = ltree[indice2];
            vector<String> aux1 = ltree.split_aux(res,ind_left_child(indice1),ind_left_child(indice2));
            vector<String> aux2 = ltree.split_aux(res,ind_right_child(indice1),ind_right_child(indice2));
            return aux1.merge(aux2);

        }

        vector<String> split(int indice1, int indice2){
            vector<String> res;
            return  ltree.split_aux(res,indice1,indice2);
        }

        void add_tree(vector<String> v,int ind, int n=0){
                if (v[n] != "NULL") {
                    ltree.add(v[n],ind);
                    add_tree(v,ind_left_child(ind),ind_left_child(n));
                    add_tree(v,ind_right_child(ind),ind_right_child(n));
                }
        }

        void search_nextOR_aux(int parent, int favourite_child){
            if (favourite_child) {
               ltree.swap(parent, ind_right_child(parent));
               ltree.add("NULL",ind_left_child(parent));
               ltree.add("NULL",ind_right_child(parent));
            }else{
               ltree.swap(parent, ind_left_child(parent));
               ltree.add("NULL",ind_left_child(parent));
               ltree.add("NULL",ind_right_child(parent));
                }

        }

        void search_nextOR(Graph g ,int ind){
            if (left_child(ind_left_child(ind)) == "OR" && g.isThe_same_Table(ltree.left_child(left_child(ind_left_child(ind))),ltree.right_child(left_child(ind_left_child(ind)))) {
                search_nextOR_aux(ind_left_child(ind_left_child(ind)),0);
                search_nextOR_aux(ind_right_child(ind_left_child(ind)),1);
            }else{
                search_nextOR_aux(ind_left_child(ind_left_child(ind)),0);
                search_nextOR_aux(ind_right_child(ind_right_child(ind)),1);
            }

        }


        void funcao(Graph g, int x=0){
            if(ltree.ltree[x] == "OR" && g.isThe_same_Table(ltree.left_child(x),ltree.right_child(x)){
                int parent = ltree.ind_Parent(x);
                    vector<String> s = ltree.split(0,parent);
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


}

class Graph {
    String root;
    Map<String, pair<String,String> > join;
    vector<pair <String,String> > groupby;
    Map<String,Map<String,int> > tables; //int-> 0=Measure, 1 = Dimension
    Map<String, vector<String> > filter;
    vector<String> select;
        Public:

        int num_attributes(String str){
            return tables[str].size();
        }

        void add_filter(String Table,String filter, int type = -1){
            tables[Table].insert(pair<String,int>(filter,type));
        }

        void remove_filter(String Table,String filter){
            tables[Table].erase(filter);
        }

        int search_filter_in_table(String table, String filter){
            for(map<String,int>::iterator it = tables[Table].begin(); it != tables[Table].end(); ++it) {
                if (it->first.compare(filter)==0) {return 1;}
            }
            return 0;
        }

        int search_table(String table){
            for(map<String,Map<String,int>>::iterator it = tables.begin(); it != tables.end(); ++it) {
                if (it->frist.compare(Table)==0) {return 1;}
            }
            return 0;
        }

        void add_table(String Table, String filter, int type){
            map<String,int> aux;
            aux[filter] = type;
            tables.insert(pair<String,Map<String,int>(Table, aux));
        }

        void remove_table(String Table){
            tables.erase(Table);
        }

        void add_join(String Table,String filter, String type ){
            join[Table].insert(pair<String,String>(filter,type));
        }

        void remove_join(String Table,String filter){
            join[Table].erase(filter);
        }

        void add_groupby(String Table,String filter){
            groupby.push_back(pair<String,String>(Table,filter));
        }

        void remove_groupby(String Table,String filter){
            for (int i = 0; i < groupby.size(); i++) {
                if ((groupby[i].getKey().compare(Table)==0) && (groupby[i].getValue().compare(filter)==0)) {
                    groupby.erase(groupby.begin() + i);
                    break();
                }
            }
        }

        void add_map_filter(String Table, String filter){
            filter[Table].push_back(filter);
        }

        void remove_map_Table_filter(String Table){
            filter.erase(Table);
        }

        void remove_map_filter(String Table,String filter){
            for (int i = 0; i < filter[Table].size(); i++) {
                if (filter[Table][i].compare(Table)==0){
                    filter[Table].erase(filter[Table].begin() + i);
                    break();
                }
            }
        }

        void add_select(String Table){
            select.push_back(Table);
        }

        void remove_select(String Table){
            for (int i = 0; i < select.size(); i++) {
                if (select[i].compare(Table)==0) {
                    select.erase(select.begin() + i);
                    break();
                }
            }
        }

        int is_measured(String filter){
            if (attribute_type[filter] == 1) {
                return 1;
            }else return 0;
        }

        int is_dimension(String filter){
            if (attribute_type[filter] == 2) {
                return 1;
            }else return 0;
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

String a = "A";
Graph g;
LTree l;

void graphWork(){
  while (!g.join.empty()) {
    graphWorkAux(1);
  }
  graphWorkAux(0);
}



void graphWorkAux(int x){
  //pega nas pontas
  String start = giveMeStart(g.root);
  //juntar filtros do mesmo atributo dessa tabela, no final a tabela terá aoenas letras.
  joinAtr(start);
  //juntar tudo
  joinFilters(start);
  //remover tabela e adicionar como atributo às seguintes
  if(x == 1)removeTable(start);
}

void joinAtr(String start){
  //pega nos filtros no mesmo atributo
  Map<String,int> work = g.tables[start];
  vetor<String> v;
  vector<String,int> new_elements;
  for(Map<String,int>::iterator it = work.begin(); it != work.end(); ++it) {
    String s = it->first;
    vector<String> v = g.filter[s];
    if(it->secound == 0){ //se for medida
      joinAtrM(s,v);
    }else{                //se for dimensao
      joinAtrD(s,v);
    }
    new_elements.append(a,it->secound);
  }
  g.tables[start] = new_elements;
}

void joinAtrM(String s, vector<String> v){
  vector<String> resolvidos;
  vector<String> relacoes;
  resolvidos.append(v[0]);
  for(x = 1; x < v.lenght() < v; x++){
    relacoes.append(relacao_entre(resolvidos,v[x]));
    resolvidos.append(v[x]);
  }
  next();
  if(resolvidos.size()>1){
    cout << a << "=filter(" << s << ",";
    for(x = v.lenght(); x > 0; x--){ // letra = filter(OR(AND(a,b)),c);
      cout << relacoes[x-1] << "("<< resolvidos[x] << ",";
    }
    cout << v[0] << ")";
    for(x = 0; x < relacoes.lenght(); x++){
      cout << ")";
    cout << ")\n";
  }else{
    cout << a << "=filter(" << s << v[0] << ")\n"
  }
}

void joinAtrD(String s, vector<String> v){
  vector<String> resolvidos;
  vector<String> relacoes;
  resolvidos.append(v[0]);
  for(x = 1; x < v.lenght() < v; x++){
    relacoes.append(relacao_entre(resolvidos,v[x],s));
    resolvidos.append(v[x]);
  next();
  cout << a << "=filter("<< s << v[0] << ")\n";
  for(x = 1; x < resolvidos.lenght(); x++){ // letra = AND/OR(filter(),letra_anterior);
    String aux = a;
    next();
    cout << a << "=";
    if(relacoes[x-1].compare("AND")){
      cout << "hadamard";
    }else{
      cout << "hadamardOR";
    }
    cout << "(filter(" << s << "," <<resolvidos[x] << ")," << aux << ")\n";
  }
}

void joinFilters(String start){
  //pega nos filtros da mesma tabela
  Map<String,int> work = g.tables[start];
  vector<String> medidas;
  vector<String> dimensoes;
  for(Map<String,int>::iterator it = work.begin(); it != work.end(); ++it) {
    String s = it->first;
    if(it->secound == 0){ //se for medida
      medidas.append(s);
    }else{                //se for dimensao
      dimensoes.append(s)
    }
  }
  if( medidas.size() == 1){
    String aux = medias[0];
  }else{
    joinFiltersM(medidas);
    String aux = a;
  }
  if( dimensoes.size() == 1){
    String aux2 = medias[0];
  }else{
    joinFiltersD(dimensoes);
    if(dimensoes.size()>0 && medidas.size()>0){
    String aux2 = a;
  }
    next();
    cout << a << "=" << "krao(" << aux << "," << aux2 << ")\n";
  }
}

void joinFiltersM(vector<String> v){
  next();
  cout << a << "= hadamard(" << v[0] << "," << v[1] << ")\n";
  for(int x = 1; x < v.lenght() ; x++){
    String aux = a;
    next();
    cout << a << "=" << "hadamard(" << aux << "," << v[x] << ")\n";
  }
}

void joinFiltersD(vector<String> v){
  next();
  cout << a << "= krao(" << v[0] << "," << v[1] << ")\n";
  for(int x = 1; x < v.lenght() ; x++){
    String aux = a;
    next();
    cout << a << "=" << "krao(" << aux << "," << v[x] << ")\n";
  }
}


void removeTable(String start){
  vector<String> removedKeys;
  String alpha = a;
  for(Map<String,pair<String,String>>::iterator it = g.join.begin(); it != g.join.end(); ++it) {
    if(it->secound->secound.compare(start)){
      next();
      cout << a << "=" << "dot(" << it->first << "," << alpha << ")\n";
      Map<String,int> aux = g.tables[start];
      aux[a] = 1;           //possivel zona a melhorar
      g.tables[start] = aux;
      removedKeys.append(it->first);
    }
  }
  for(int x = 0; x< removedKeys.lenght(); x++){
    g.join.erase(removedKeys[x]);
  }
}



String giveMeStart(String root){
  vector<String> values;
  for(Map<String,pair<String,String>>::iterator it = g.join.begin(); it != g.join.end(); ++it) {
    values.push_back(it->secound);
  }
  for(x = 0; x < values.lenght(); x++){
    if(values[x]->first==root){
      return giveMeStart(values[x]->secound);
    }
  }
  return root;
}


void next(){
  if(a[a.lenght()-1] == "Z"){
    a.append("A");
  }else{
    a[a.lenght()-1]++;
  }
}
