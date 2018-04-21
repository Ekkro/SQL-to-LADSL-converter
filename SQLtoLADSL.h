 #include <stdio.h>                                                                                                                      
 #include <strings.h>


typedef struct node{
  char* string;
  node* next;
}Node;

typedef struct  select{
  int sizeSelects;
  Select selects[10];
  Node alias;
  Node return_values;
  Node orderby;
  int sizetables;
  Node tables[1];
}Select;

FILE* out;
int flag = 0;
char* tables;

void add_rename(char* rename, Select select);

void add_Literalfilter(char* filter,char* table, Select select);

void add_filter(char* atributo1, char* atributo2, char* op, char* table, Select select);

void join (int flag, char* atributo1, char* atributo2);
