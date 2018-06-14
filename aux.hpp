#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <utility>
using namespace std;
class Graph {
    string root;
    map<string, pair<string,string> > join;
    vector<pair <string,string> > groupby;
    map<string,map<string,int> > tables; //int-> 0=Measure, 1 = Dimension
    map<string, vector<string> > filter;
    vector<string> select;
        public:

        int num_attributes(string str){
            return tables[str].size();
        }

        void add_filter(string Table,string filter, int type = -1){
            tables[Table].insert(pair<string,int>(filter,type));
        }

        void remove_filter(string Table,string filter){
            tables[Table].erase(filter);
        }

        int search_filter_in_table(string table, string filter){
            for(map<string,int>::iterator it = tables[table].begin(); it != tables[table].end(); ++it) {
                if (it->first.compare(filter)==0) {return 1;}
            }
            return 0;
        }

        vector<string> search_filter(string filter){
            vector<string> aux;
            for(map<string, map<string,int> >::iterator it = tables.begin(); it != tables.end(); ++it) {
                if (search_filter_in_table(it->first,filter)) {
                    aux.push_back(it->first);
                }
            }
            return aux;
        }

        int search_table(string table){
            for(map<string, map<string,int> >::iterator it = tables.begin(); it != tables.end(); ++it) {
                if (it->first.compare(table)==0) {return 1;}
            }
            return 0;
        }

        void add_table(string Table, string filter, int type){
            map<string,int> aux;
            aux[filter] = type;
            pair<map<string, int>::iterator, bool > result;
            tables.insert(pair<string,map<string,int> >(Table, aux));
        }

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

        void add_groupby(string Table,string filter){
            groupby.push_back(pair<string,string>(Table,filter));
        }

        //groupby é um vetor, groupby[i] é um par
        void remove_groupby(string Table,string filter){
            for (int i = 0; i < groupby.size(); i++) {
                if ((groupby[i].first.compare(Table)==0) && (groupby[i].second.compare(filter)==0)) {
                    groupby.erase(groupby.begin() + i);
                    break;
                }
            }
        }

        void add_map_filter(string Table, string Filter){
            //filter[Table].push_back(filter);
            filter[ Table ].push_back(Filter);
        }

        void remove_map_Table_filter(string Table){
            filter.erase(Table);
        }

        void remove_map_filter(string Table,string Filter){
            for (int i = 0; i < filter[Table].size(); i++) {
                if (filter[Table][i].compare(Filter)==0){
                    filter[Table].erase(filter[Table].begin() + i);
                    break;
                }
            }
        }

        void add_select(string Table){
            select.push_back(Table);
        }

        void remove_select(string Table){
            for (int i = 0; i < select.size(); i++) {
                if (select[i].compare(Table)==0) {
                    select.erase(select.begin() + i);
                    break;
                }
            }
        }

//        int is_measured(string filter){
//            if (attribute_type[filter] == 1) {
//                return 1;
//            }else return 0;
//        }
//
//        int is_dimension(string filter){
//            if (attribute_type[filter] == 2) {
//                return 1;
//            }else return 0;
//        }

//        void add_table(string Table, string name){
//            Graph[Table].insert(filter,str);
//        }
//
        int isThe_same_Table_array(vector<string> v){
            int res = 1;
            for(vector<string>::iterator it = v.begin(); it != v.end(); ++it) {
                if (!isThe_same_Table(v[0],it)) {
                    res = 0;
                    break;
                }
            }
            return res;
        }
        int isThe_same_Table(string attribute1, string attribute2){
            if ( relacao_entre_arrays(search_filter(attribute1),search_filter(attribute2))=="NULL") {
                return 0;
            }else {return 1;}
         }
};

class Ltree {

    vector<string> ltree;
    //vector<pair<string,string>> ltree; possivelmente será necessário alterar o codigo para esta ltree
    public:
//        Ltree() {ltree = new vector<string>();}
        string Parent(int indice){
            string res = "NULL";
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

        string left_child(int indice){
            string res = "NULL";
            int aux = 2*indice+1;
            if ( aux <0 || aux >= ltree.size()) {
                return res;
            }else{ return ltree[aux]; }
            }

        vector<string>::iterator it_left_child(vector<string>::iterator indice){
            indice = indice+1;
            return indice;
            }

        int ind_left_child(int indice){
            int aux = 2*indice+1;
            if ( aux <0 || aux >= ltree.size()) {
                return -1;
            }else{ return aux; }
            }

        string right_child(int indice){
            string res = "NULL";
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

        void add(string value ,int indice ){ ltree[indice] = value; }

        int indice(string value){
           for ( int i = 0; i < ltree.size(); i++ ) {
               if (!ltree[i].compare(value)) {
                   return i;
               }
           }
           return -1;
        }

        void swap(int indice1,int indice2 ){
            string aux;
            aux = ltree[indice1];
            ltree[indice1] = ltree[indice2];
            ltree[indice2] = aux;
        }

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

        void merge(vector<string> vec){
            for ( int i = 0; ltree.size(); i++) {
                if ((!ltree[i].compare("NULL")) && (vec[i].compare("NULL")==0)) {
                    ltree[i] = vec[i];
                }
            }
        }

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

        vector<string> split(int indice1, int indice2){
            vector<string> res;
            return  Ltree::split_aux(res,indice1,indice2);
        }

        void add_tree(vector<string> v, vector<string>::iterator ind, int n=0){
                if (v[n] != "NULL") {
                    ltree.insert(ind,v[n]);
                    add_tree(v,it_left_child(ind),it_left_child(n));
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
            if (left_child(ind_left_child(ind)) == "OR" && (g.isThe_same_Table_array(childs(x))==0)){
                search_nextOR_aux(ind_left_child(ind_left_child(ind)),0);
                search_nextOR_aux(ind_right_child(ind_left_child(ind)),1);
            }
            else{
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

        vector<int> subvector (vector<int> v1, vector<int> v2){
            vector<int> res(max(lenght(v1),lenght(v2));
            vector<int>::iterator aux;
            aux =std::set_intersection (v1.begin(), v1.end(), v2.begin(), v2.end(), res.begin());
            res.resize(aux-res.begin());
            return res;
        }


        string relacao_entre(vector<string> v, string s){
            vector<int> aux = parents(s);
            for(vector<string>::iterator it = v.begin(); it != v.end(); ++it) {
                aux = subvector(aux,parents(it));

            }

            if (aux.size()) {
                return ltree[aux[0]];
            }else {return "NULL";}
        }

        string relacao_entre_arrays(vector<string> v, vector<string> s){
            for(vector<string>::iterator it = v.begin()+1; it != v.end(); ++it) {
                s.push_back(v);
            }
            return relacao_entre(s,v[0]);
        }

};


string a = "A";
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
  string start = giveMeStart(g.root);
  //juntar filtros do mesmo atributo dessa tabela, no final a tabela terá aoenas letras.
  joinAtr(start);
  //juntar tudo
  joinFilters(start);
  //remover tabela e adicionar como atributo às seguintes
  if(x == 1)removeTable(start);
}

void joinAtr(string start){
  //pega nos filtros no mesmo atributo
  map<string,int> work = g.tables[start];
  vetor<string> v;
  vector<string,int> new_elements;
  for(map<string,int>::iterator it = work.begin(); it != work.end(); ++it) {
    string s = it->first;
    vector<string> v = g.filter[s];
    if(it->secound == 0){ //se for medida
      joinAtrM(s,v);
    }else{                //se for dimensao
      joinAtrD(s,v);
    }
    new_elements.append(a,it->secound);
  }
  g.tables[start] = new_elements;
}

void joinAtrM(string s, vector<string> v){
  vector<string> resolvidos;
  vector<string> relacoes;
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

void joinAtrD(string s, vector<string> v){
  vector<string> resolvidos;
  vector<string> relacoes;
  resolvidos.append(v[0]);
  for(x = 1; x < v.lenght() < v; x++){
    relacoes.append(relacao_entre(resolvidos,v[x],s));
    resolvidos.append(v[x]);
  next();
  cout << a << "=filter("<< s << v[0] << ")\n";
  for(x = 1; x < resolvidos.lenght(); x++){ // letra = AND/OR(filter(),letra_anterior);
    string aux = a;
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

void joinFilters(string start){
  //pega nos filtros da mesma tabela
  map<string,int> work = g.tables[start];
  vector<string> medidas;
  vector<string> dimensoes;
  for(map<string,int>::iterator it = work.begin(); it != work.end(); ++it) {
    string s = it->first;
    if(it->secound == 0){ //se for medida
      medidas.append(s);
    }else{                //se for dimensao
      dimensoes.append(s)
    }
  }
  if( medidas.size() == 1){
    string aux = medias[0];
  }else{
    joinFiltersM(medidas);
    string aux = a;
  }
  if( dimensoes.size() == 1){
    string aux2 = medias[0];
  }else{
    joinFiltersD(dimensoes);
    if(dimensoes.size()>0 && medidas.size()>0){
    string aux2 = a;
  }
    next();
    cout << a << "=" << "krao(" << aux << "," << aux2 << ")\n";
  }
}

void joinFiltersM(vector<string> v){
  next();
  cout << a << "= hadamard(" << v[0] << "," << v[1] << ")\n";
  for(int x = 1; x < v.lenght() ; x++){
    string aux = a;
    next();
    cout << a << "=" << "hadamard(" << aux << "," << v[x] << ")\n";
  }
}

void joinFiltersD(vector<string> v){
  next();
  cout << a << "= krao(" << v[0] << "," << v[1] << ")\n";
  for(int x = 1; x < v.lenght() ; x++){
    string aux = a;
    next();
    cout << a << "=" << "krao(" << aux << "," << v[x] << ")\n";
  }
}


void removeTable(string start){
  vector<string> removedKeys;
  string alpha = a;
  for(map<string,pair<string,string>>::iterator it = g.join.begin(); it != g.join.end(); ++it) {
    if(it->secound->secound.compare(start)){
      next();
      cout << a << "=" << "dot(" << it->first << "," << alpha << ")\n";
      map<string,int> aux = g.tables[start];
      aux[a] = 1;           //possivel zona a melhorar
      g.tables[start] = aux;
      removedKeys.append(it->first);
    }
  }
  for(int x = 0; x< removedKeys.lenght(); x++){
    g.join.erase(removedKeys[x]);
  }
}



string giveMeStart(string root){
  vector<string> values;
  for(map<string,pair<string,string>>::iterator it = g.join.begin(); it != g.join.end(); ++it) {
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
