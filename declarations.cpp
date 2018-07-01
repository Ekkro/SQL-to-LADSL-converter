 //#include <stdio.h>
 //#include <strings.h>
 //#include <vector>
 //#include <iostream>
 //#include <map>
 //#include <utility>
#include <regex>
#include "SQLtoLADSL.hpp"
using namespace std;



string a = "A";
Graph mainGraph;
Graph g;
Ltree l;


/* ........................................................................ */

    /* ..................................................... */
    /* .....................DECLARATIONS.......................... */
    /* ..................................................... */

        bool has(vector<string> v, string s){
            return  (find(v.begin(), v.end(), s) != v.end());
        }

        Ltree create_tree(string term, string type){
            Ltree res ;
            if (type.compare("JOIN") == 0) {
                res.add("NULL",0);
            }else{
                res.add(term,0);
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
  next();
  if(v.size()>1){
    cout << a << "=filter(" << v[0];
    for(vector<string>::iterator it = v.begin()+1; it != v.end(); ++it) {
      cout << type << *it;
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
    if(it->second.compare("measure") == 0){ //se for medida
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
  cout << a << "="<< s <<"(" << v[0] << "," << v[1] << ")\n";
  for(vector<string>::iterator it = v.begin()+1; it != v.end(); ++it) {
    string aux = a;
    next();
    cout << a << "=" << s <<"(" << aux << "," << *it << ")\n";
  }
}

void joinFilters(string start, string type){
  //pega nos filtros da mesma tabela
  string aux;
  string aux2;
  map<string,string> work = g.tables[start];
  vector<string> medidas;
  vector<string> dimensoes;
  for(map<string,string>::iterator it = work.begin(); it != work.end(); ++it) {
    string s = it->first;
    if(it->second.compare("measure") == 0){ //se for medida
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
  if( dimensoes.size() == 1){
    aux2 = medidas[0];
  }else{
    joinFiltersD(dimensoes,type);
    aux2 = a;
  }
  if(dimensoes.size()>0 && medidas.size()>0){
    next(); // verificar se é and ou or entre aux1 e aux2
    if(type.compare("AND") == 0)
      cout << a << "=" << "krao" << "(" << aux << "," << aux2 << ")\n";
    else{
      cout << a << "=" << "kraoOR" << "(" << aux << "," << aux2 << ")\n";
    }

  }
}


void joinGroupbyAux(string gb){
  string alpha = a;
  next();
  cout << a << "=krao(" << alpha << "," << gb << ")\n";
}

void joinGroupby(string start){
  for(vector<pair<string,string> >::iterator it = g.groupby.begin(); it != g.groupby.end(); ++it) {
    if(it->first.compare(start)){
      joinGroupbyAux(it->second);
    }
  }
}

void removeTable(string start){
  vector<vector <string> > Keys;
  string alpha = a;
  if (g.tables[start].size() == 1) {
      for(vector<vector<string> >::iterator it = g.join.begin(); it != g.join.end(); ++it) {
        if(it->at(2).compare(start)){
          next();
          cout << a << "=" << "dot(" << alpha << "," << it->at(0)<< ")\n";
          map<string,string> aux = g.tables[it->at(1)];
          aux[a] = "dimension";
          g.tables[it->at(1)] = aux;
        }
        else{
          Keys.push_back(*it);
        }
      }
      g.join = Keys;
      }
}

string giveMeStart(string root){
  for(vector<vector<string> >::iterator it = g.join.begin(); it != g.join.end(); ++it) {
    if(it->at(1).compare(root)){
        return giveMeStart(it->at(2));
    }
  }
  return root;
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
  while (!g.filter.empty()) {// parar quando só houver uma tabela com atributos
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
void merge(vector<string> v){
  // g
  // mainGraph
  pair<string,string> aux;
  string table;
  for(map<string,map<string, string> >::iterator it = g.tables.begin(); it != g.tables.end(); ++it) {
      if (!(it->second.empty())) {
          for(map<string, string> ::iterator i = it->second.begin(); i != it->second.end(); ++it) {
              aux = pair<string,string>(i->first,i->second);
              table = it->first;
              break;
          }
          break;
    }
  }

    mainGraph.tables[table].insert(aux);
   //empty table
   vector<string> emptytable;

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
        }else{ emptytable.push_back(it->first);}
        //acrescenta no empty
        }
        mainGraph.filter = newfilter;
        vector<pair<string,string> > eraseIt;

    for(map<string,map<string, string> >::iterator it = mainGraph.tables.begin(); it != mainGraph.tables.end(); ++it) {
       // se it->second->first in empty elimina map<string,string>
        for(map<string, string>::iterator i = (it->second).begin(); i != (it->second).end(); ++i) {
            if (has(emptytable, i->first)) {
                eraseIt.push_back(make_pair(it->first, i->first));
            }
        }
    }
    for(vector<pair<string,string> >::iterator it = eraseIt.begin(); it != eraseIt.end(); ++it) {
        mainGraph.tables[it->first].erase(it->second);
    }

}

void dot_all(){
  for(vector<vector<string> >::iterator it = mainGraph.join.begin(); it != mainGraph.join.end(); ++it) {
    string key = it->at(0);
    string table = it->at(1);
    string table2 = it->at(2);
    map<string,string> aux = mainGraph.tables[table];
    for(map<string,string>::iterator it = mainGraph.tables[table2].begin(); it != mainGraph.tables[table2].end(); ++it) {
      next();
      cout << a << "=" << "dot(" << it->first << "," << key << ")\n";
      aux[a] = "dimension";
    }
    mainGraph.tables[table] = aux;
  }
}


void resolveS(int indice, string type){
  vector<string> v =  l.childs(indice);
  g = mainGraph.clone(v);
  graphWork(type);
  l.ltree[indice] = a;
  l.erasechilds(indice);
  merge(v); //between mainGraph and g...
  //^^cuidado com vários filters no memso atributo, retirar de table e filter apenas se g.filter(atributo)==mainGraph.filter(atributo), caso contrário apenas retira as entradas iguais
}


void resolve(int indice){
  if(l.ltree[indice].compare("OR") == 0){
    resolve(l.ind_left_child(indice));
    resolve(l.ind_right_child(indice));
    if(l.dependencies(indice) != true){
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









int main(){
    return 0;
}
