 #include <stdio.h>                                                                                                                      
 #include <strings.h>
 #include <vector>
 #include <iostream>
 #include <map>
 #include <utility>
#include <set>
#include <algorithm>
using namespace std;


bool has(vector<string> v, string s);

vector<int> subvector (vector<int> v1, vector<int> v2);

string relacao_entre(vector<string> v, string s);

string relacao_entre_arrays(vector<string> v, vector<string> s);

void graphWork();

void graphWorkAux(int x);

void joinAtr(string start);

void joinAtrD(string s, vector<string> v);

void joinFilters(string start);

void joinFiltersM(vector<string> v);

void joinFiltersD(vector<string> v);

void joinGroupby(string start);

void joinGroupbyAux(string gb);

void removeTable(string start);

string giveMeStart(string root);

void next();

void trabalha(int ind);

void trabalhaaux(int ind, int count);

void cleanexp();

void addexp(string exp);

void aux(string exp);

void merge(vector<string> v);

void resolveS(int indice, string type);

void resolve(int indice);


