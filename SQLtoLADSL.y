%{                                                                    
 #include <stdio.h>                                                                                                                      
 #include <strings.h>

 /* Declaracoes C diversas */                                          

typedef struct node{
    char* string;
    node* next;
}Node;

typedef struct nodes{
	char* nome_tabela;
    Node node;
    nodes* next;
}Nodes;

typedef struct  select{
    Select selects[10];
    Node renumeacoes;
    Node conteudo_select;
    Node conteudo_orderby;
    Nodes tabelas;
}Select;

void add_rename(char* rename, Select select){
	Node aux = new Node;
	aux->string = rename;
	aux->next = select->renumeacoes;
	select->renumeacoes=aux;
}

FILE* out;
int flag = 0;
char* tabela;

void add_simplefilter(char* filter,char* tabela, Select select){
  Nodes aux = select->tabelas;
  while(aux!=NULL && strcmp(aux->nome_tabela,tabela) == 0)aux=aux->next;
  if(aux == NULL){
    //add tabela
  }else{
    //add filter
  }
}

void add_filter(char* atributo1, char* atributo2, char* op, char* tabela, Select select){
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
*/
%}

%token SELECT FROM WHERE GROUPBY ORDERBY HAVING NAME AS  
%token AND OR EXISTS OP NOT BETWEEN JOIN INNER LEFT RIGHT FULL ON CONSTANT SHIFT BOOL IN ASC DESC COMPARISSON DATE ANDOP ANY ALL
%%  

SelectBlock    : SELECT     selectList                                             { ; }
                 FROM       fromList                                               { ; }
                 WHERE_                                                            { ; }
                 GROUPBY_                                                          { ; }
                 ORDERBY_                                                          { ; }
                 ';'                                                               { ; }     

WHERE_         : WHERE       whereList                                             { ; }
               |                                                                   { ; }
               ;

GROUPBY_       : GROUPBY    groupbyList                                            { ; }
               |                                                                   { ; }
               ;

ORDERBY_       : ORDERBY    orderbyList                                            { ; }
               |                                                                   { ; }
               ;

selectList     : selectListN                                                       { ; }
               | '*'                                                               { ; }
               ;

selectListN    : selectListNSub                                                    { ; } 
               | selectListNSub ',' selectListN                                    { ; }
               ;

selectListNSub : COMPLEX                                                           { add_select($1,tabela); } 
               | COMPLEX AS NAME                                                   { add_select($1);add_rename($1,$3,tabela); }
               ;

fromList       : subfromList                                                       { ; } 
               | subfromList ',' fromList                                          { ; }
               ;

subfromList    : NAME                                                              { ; } 
               | Join NAME                                                         { ; } 
               | Join NAME ON NAME '=' NAME                                        { add_filter($4,$6,'=',tabela); } 
               | Join NAME AS NAME                                                 { add_rename($2,$4); }
               | Join NAME AS NAME ON NAME '=' NAME                                { add_filter($6,$8,'=',tabela);add_rename($2,$4); }
               | '{' SelectBlock '}'                                               { ; } 
               | '{' SelectBlock '}' AS NAME                                       { add_rename($2,$5); } 
               ;

Join           : JOIN                                                              { ; } 
               | INNER JOIN                                                        { ; }
               | LEFT JOIN                                                         { ; }
               | RIGHT JOIN                                                        { ; }
               | FULL JOIN                                                         { ; } 
               ;


whereList      : whereListSub                                                      { ; }
               | whereListSub OL whereList                                         { ; }
               ;

whereListSub   : COMPLEX                                                           { add_simplefilter($1,tabela); }
               | '(' whereList ')'                                                 { ; }
               | NAME IN Inlist                                                    { add_in($1,$3); }//a in(......)
               | NAME BETWEEN SIMPLE AND SIMPLE                                    { add_filter($1,$3,'>',tabela); add_filter($1,$5,'<',tabela); }
               | EXISTS '(' SelectBlock ')' ';'                                    { ; }                                        
               ;

groupbyList    : groupbyListSub                                                    { ; } 
               | groupbyListSub  ',' groupbyList                                   { ; }
               ;

groupbyListSub : NAME                                                              { add_groupby($1); } 
               | HAVING NAME '(' SIMPLE ')' BOP SIMPLE                             { ; }//?????? 
               ;

orderbyList    : orderbyListSub                                                    { ; }
               | orderbyListSub ',' orderbyList                                    { ; }                                            
               ;

orderbyListSub : NAME                                                              { add_orderby($1); }
               | NAME order                                                        { add_orderby($1); }                                          
               ;

order          : ASC                                                               { ; }
               | DESC                                                              { ; }
               ;


OL             : AND                                                               { ; }
               | ANDOP                                                             { ; }
               | OR                                                                { ; }
               ;

SIMPLE         : NAME                                                              { ; }
               | NAME'.'NAME                                                       { tabela = $1; }
               | DATE                                                              { ; }
               | CONSTANT                                                          { ; }
               | BOOL                                                              { ; }
               | ANY                                                               { ; }
               | ALL                                                               { ; }
               ;


COMPLEX        : SIMPLE                                                            { ; }//a.atributo
               | NOT COMPLEX                                                       { ; }//not ....
               | COMPLEX BOP COMPLEX                                               { ; }// a > b
               | NAME '(' COMPLEX ')'                                              { ; }// sum(....)
               ;


BOP            : COMPARISSON                                                       { ; }// <,>,==
               | SHIFT                                                             { ; }// <<, >>
               | OP                                                                { ; }// +, -
//             | NAME                                                              { ; }//???
               ;

Inlist         : SIMPLE                                                            { ; }
               | SIMPLE  ','  Inlist                                               { ; }
               ;

%%
int main(int argc, char **argv){

    out = fopen("name.vm", "w");
    if (out == NULL){
        printf("Error opening file!\n");
        exit(1);
    }
    //char codigo[1023*1024];
    fprintf(out, "start\n"); 
    yyparse();
    fprintf(out, "stop\n");
    
    fclose(out);
    return 0;
}
