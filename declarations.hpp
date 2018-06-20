 #include <stdio.h>                                                                                                                      
 #include <strings.h>
 #include <vector>
 #include <iostream>
 #include <map>
 #include <utility>
 #include "SQLtoLADSL.hpp"
using namespace std;


vector<int> subvector (vector<int> v1, vector<int> v2);

int isThe_same_Table(string attribute1, string attribute2);

int isThe_same_Table_array(vector<string> v);

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

