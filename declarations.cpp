 #include <stdio.h>                                                                                                                      
 #include <strings.h>
 #include "SQLtoLADSL.hpp"


/*

string a = "A";
Graph g;
LTree l;

*/

 vector<int> subvector (vector<int> v1, vector<int> v2){
     vector<int> res(max(v1.size(),v2.size()));
     vector<int>::iterator aux;
     aux = set_intersection (v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(res));
     res.resize(aux-res.begin());
     return res;
 }


int isThe_same_Table(string attribute1, string attribute2){
 if ( relacao_entre_arrays(search_filter(attribute1),search_filter(attribute2))=="NULL") {
     return 0;
 }else {return 1;}
}

int isThe_same_Table_array(vector<string> v){
 int res = 1;
 for(vector<string>::iterator it = v.begin(); it != v.end(); ++it) {
     if (!isThe_same_Table(v[0],*it)) {
         res = 0;
         break;
     }
 }
 return res;
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
  map<string,int> work = g.tables[start];
  vetor<string> v;
  vector<string,int> new_elements;
  for(map<string,int>::iterator it = work.begin(); it != work.end(); ++it) {
    string s = it->first;
    vector<string> v = g.filter[s];
    if(it->secound == 1){ //se for medida
      new_elements.insert(it->first,it->secound);
    }else{                //se for dimensao
      joinAtrD(s,v);
      new_elements.insert(a,it->secound);
    }
  }
  g.tables[start] = new_elements;
}

void joinAtrD(string s, vector<string> v){
  vector<string> resolvidos;
  vector<string> relacoes;
  resolvidos.insert(v[0]);
  for(x = 1; x < v.lenght() < v; x++){
    relacoes.insert(relacao_entre(resolvidos,v[x]));
    resolvidos.insert(v[x]);
  }
  next();
  if(resolvidos.size()>1){
    cout << a << "=filter(" << s <<resolvidos.back() << relacoes.back();
    for(x = v.lenght()-2; x > 0; x--){
      cout << "("<< s << resolvidos[x] << relacoes[x-1];
    }
    cout << s << resolvidos[0];
    for(x = 0; x < relacoes.lenght()-1; x++){
      cout << ")";
    cout << ")\n";
  }else{
    cout << a << "=filter("  << v[0] << ")\n"
  }
}}

void joinFilters(string start){
  //pega nos filtros da mesma tabela
  map<string,int> work = g.tables[start];
  vector<string> medidas;
  vector<string> dimensoes;
  for(map<string,int>::iterator it = work.begin(); it != work.end(); ++it) {
    string s = it->first;
    if(it->secound == 0){ //se for medida
      vector<string> filters= filter[s];
      for(vector<string>::iterator it = filters.begin(); it != filters.end(); ++it){
        string aux3 = s+it;
        medidas.insert(aux3);
      }
    }else{                //se for dimensao
      dimensoes.insert(s)
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
    string aux2 = a;
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
  resolvidos.insert(v[0]);
  for(x = 1; x < v.lenght() < v; x++){
    relacoes.insert(relacao_entre(resolvidos,v[x]));
    resolvidos.insert(v[x]);
  }
  next();  // a > 3 ; b < 6 ; u > 6
  if(resolvidos.size()>1){
    cout << a << "=filter(" << resolvidos.back() << relacoes.back();
    for(x = v.lenght()-2; x > 0; x--){
      cout << "("<< resolvidos[x] << relacoes[x-1];
    }
    cout << v[0];
    for(x = 0; x < relacoes.lenght()-1; x++){
      cout << ")";
    cout << ")\n";
  }else{
    cout << a << "=filter("  << v[0] << ")\n"
  }
}}

void joinFiltersD(vector<string> v){
  next();
  cout << a << "= krao(" << v[0] << "," << v[1] << ")\n";
  for(int x = 1; x < v.lenght() ; x++){
    string aux = a;
    next();
    cout << a << "=" << "krao(" << aux << "," << v[x] << ")\n";
  }
}

void joinGroupby(string start){
  for(vector<pair<string,string>>::iterator it = g.join.begin(); it != g.join.end(); ++it) {
    if(it->first.compare(start)){
      joinGroupbyAux(it->secound);
    }
  }
}

void joinGroupbyAux(string gb){
  string alpha = a;
  next();
  cout << a << "=krao(" << alpha << "," << gb << ")\n"
}

void removeTable(string start){
  vector<string> removedKeys;
  string alpha = a;
  for(map<string,pair<string,string>>::iterator it = g.join.begin(); it != g.join.end(); ++it) {
    if(it->secound->secound.compare(start)){
      next();
      cout << a << "=" << "dot(" << alpha << "," << it->first << ")\n";
      map<string,int> aux = g.tables[start];
      aux[a] = 1;           //possivel zona a melhorar
      g.tables[start] = aux;
      removedKeys.insert(it->first);
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

void trabalha(int ind){
  trabalhaaux(ind_left_child(ind),string tabela1);
  trabalhaaux(ind_right_child(ind),string tabela2);
}

void trabalhaaux(int ind, int count){
    if(is_the_same_table_array(childs(ind)) == 0 )
      if(left_child(ind) == "AND" || right_child(ind) == "AND")
        trabalhaaux(int ind);
}
