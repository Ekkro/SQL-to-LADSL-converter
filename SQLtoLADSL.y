%{                                                                    
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

void add_simplefilter(char* filter,char* table, Select select){
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
*/
%}
%token SELECT FROM WHERE GROUPBY ORDERBY HAVING NAME AS  
%token AND OR EXISTS OP NOT BETWEEN JOIN INNER LEFT RIGHT FULL ON CONSTANT SHIFT BOOL IN ASC DESC COMPARISSON DATE ANDOP ANY ALL
%%  

SelectBlock    : SELECT     selectList                                             
                 FROM       fromList                                              
                 WHERE_                                                          
                 GROUPBY_                                                       
                 ORDERBY_                                                      
                 ';'                                                               { fprintf(out,"resultado\n"); }     

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
               | selectListNSub ',' selectListN                                    { ; }// ver melhor
               ;

selectListNSub : Expr                                                              {add_select($1); } 
               | Expr AS NAME                                                      {add_select($1);add_rename($1,$3,table); }
               ;

fromList       : subfromList                                                       { aux->sizetables++; } 
               | subfromList ',' fromList                                          { aux->sizetables++; }// ver melhor
               ;

subfromList    : NAME                                                              { ; } 
               | Join NAME                                                         { ; } 
               | Join NAME ON SIMPLE '=' SIMPLE                                    {$$ = add_key($2,$4,$6); } 
               | Join NAME AS NAME                                                 {$$ = add_rename($2,$4); }
               | Join NAME AS NAME ON SIMPLE '=' SIMPLE                            {$$ = add_key($2,$6,$8);add_rename($2,$4); }
               | '{' SelectBlock '}'                                               {$$ = from_select($2); } 
               | '{' SelectBlock '}' AS NAME                                       {$$ = from_select($2); add_renameT($2,$5); } 
               ;

Join           : JOIN                                                              { ; } 
               | INNER JOIN                                                        { ; }
               | LEFT JOIN                                                         { ; }
               | RIGHT JOIN                                                        { ; }
               | FULL JOIN                                                         { ; } 
               ;

whereList      : whereListSub                                                      {$$ = $2 ; }
               | whereListSub OL whereList                                         {opLogic($1,$2,$3); }
               ;

whereListSub   : Expr                                                              {add_simplefilter($1,table); }
               | '(' whereList ')'                                                 { ; }
               | NAME IN Inlist                                                    {$$ = add_in($1,$3); }
               | NAME BETWEEN SIMPLE AND SIMPLE                                    {$$ = add_filter($1,$3,'>',table); add_filter($1,$5,'<',table); }
               | EXISTS '(' SelectBlock ')' ';'                                    { ; }
               | Expr LIKE Expr                                                    { ; }                                        
               ;

groupbyList    : groupbyListSub                                                    {$$ =  ; } 
               | groupbyListSub  ',' groupbyList                                   { ; }
               ;

groupbyListSub : SIMPLE                                                            {add_groupby($1); } 
               | HAVING NAME '(' SIMPLE ')' BOP SIMPLE                             { ; }//?????? 
               ;

orderbyList    : orderbyListSub                                                    { ; }
               | orderbyListSub ',' orderbyList                                    { ; }                                            
               ;

orderbyListSub : SIMPLE                                                            {add_orderby($1,""); }
               | NAME order                                                        {add_orderby($1,$2); }                                          
               ;

order          : ASC                                                               { $$ = $1; }
               | DESC                                                              { $$ = $1; }
               ;

OL             : AND                                                               {$$ = $1 ; }
               | ANDOP                                                             {$$ = $1 ; }
               | OR                                                                {$$ = $1 ; }
               ;

SIMPLE         : NAME                                                              {$$ = $1 ; }//string
               | NAME'.'NAME                                                       {$$ = $3 ; table = $1; }
               | DATE                                                              {$$ = $1 ; }
               | CONSTANT                                                          {$$ = $1 ; }
               | BOOL                                                              {$$ = $1 ; }
               | ANY                                                               {$$ = $1 ; }
               | ALL                                                               {$$ = $1 ; }
               ;

Expr        : SIMPLE                                                               {$$ = $1 ; }//a.atributo
               | NOT Expr                                                          {$$ = not($2) ; }//not ....
              //| NAME'.'NAME '=' NAME'.'NAME                                       {add_key()}
               | Expr BOP Expr                                                     {$$ = bop($1,$2,$3) ; }// a > b
               | NAME '(' Expr ')'                                                 {$$ = func($1,$3) ; }// sum(....)
               | '('SelectBlock')'                                                 { ; }
               ;

BOP            : COMPARISSON                                                       {$$ = $1 ; }// <,>si
               | SHIFT                                                             {$$ = $1 ; }// <<, >>
               | OP                                                                {$$ = $1 ; }// +, -
               | '='                                                               {$$ = $1 ; }
               ;

Inlist         : SIMPLE                                                            {$$ = $1 ; }
               | SIMPLE  ','  Inlist                                               {$$ = $1 ; }
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
