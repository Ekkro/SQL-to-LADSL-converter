 #include <stdio.h>                                                                                                                      
 #include <strings.h>

 /* Declaracoes C diversas */                                          

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

void add_rename(char* rename, Select select){
  Node aux = new Node;
  aux->string = rename;
  aux->next = select->alias;
  select->alias=aux;
}

void add_Literalfilter(char* filter,char* table, Select select){
  Node aux = new Node;
  aux->string = filter;
  aux->next = select->tables[hash(table,select->sizetables)];
  select->tables[hash(table,select->sizetables)] = aux;
}

void add_filter(char* atributo1, char* atributo2, char* op, char* table, Select select){
  printf
}

/*
void join (int flag, char* atributo1, char* atributo2){
    switch(flag){
        case 1:
               fprintf(out, "filter( %s = %s)\n",atributo1,atributo2);
               break;
        case 2:
              fprintf(out, "filter( %s != NULL)\n",atributo1);
              break;
        case 3:
              fprintf(out, "filter( %s != NULL)\n",atributo2);
              break;
        default:
              fprintf(out, "");
      }
}
%}
