%{                                                                    
 #include <stdio.h>                                                                                                                      
 #include <strings.h>

 /* Declaracoes C diversas */                                          

typedef struct node{
    char* string;
    node* next;
}Node;

typedef struct nodes{
    Node node;
    nodes* next;
}Nodes;

typedef struct  select{
    int cardinalidade;
    int parent;
    Node atributos;
    Node keys;
    Nodes tabelas;
    int* select;
}Select;

typedef struct selects{
    SELECT atual
    selects* next
}Selects;


                                                                   

int flag1 = 0;
int counter = 0;
FILE* out;

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

%token SELECT FROM WHERE GROUPBY ORDERBY HAVING NAME AS  
%token AND OR EXISTS OP NOT BETWEEN JOIN INNER LEFT RIGHT FULL ON CONSTANT SHIFT BOOL IN ASC DESC COMPARISSON DATE ANDOP ANY ALL
%%  

SelectBlock : SELECT     selectList                                              { fprintf(out, "{\n");; }
              FROM       fromList                                                { ; }
              WHERE_                                                             { ; }
              GROUPBY_                                                           { ; }
              ORDERBY_                                                           { ; }
              ';'                                                                { fprintf(out, "}\n");}     

WHERE_       : WHERE       whereList                                             { ; }
             |                                                                   { ; }
             ;

GROUPBY_     : GROUPBY    groupbyList                                            { ; }
             |                                                                   { ; }
             ;

ORDERBY_     : ORDERBY    orderbyList                                            { ; }
             |                                                                   { ; }
             ;

selectList   : selectListN                                                       { fprintf(out, "SELECT("); }
             | '*'                                                               { fprintf(out, "SELECT *\n"); }
             ;

selectListN  : COMPLEX                                                           { fprintf(out, ")\n"); } 
             | COMPLEX ',' selectListN                                           { ; }
             ;

fromList     : subfromList                                                       { ; } 
             | subfromList ',' fromList                                          { ; }
             ;

subfromList  : SIMPLE                                                            { ; } 
             | Join NAME                                                         { ; } 
             | Join NAME ON NAME '=' NAME                                        { join(flag1,$4,$6);} 
             | Join NAME AS NAME                                                 { fprintf(out, "change( %s , %s)\n",$2,$4); }
             | Join NAME AS NAME ON NAME '=' NAME                                { fprintf(out, "change( %s , %s)\n",$2,$4); join(flag1,$6,$8); }
             | '{' SelectBlock '}'                                               { fprintf(out, "{\n"); } 
             | '{' SelectBlock '}' AS NAME                                       { ; } //add nome
             ;

Join         : JOIN                                                              { flag1 = 1; } //
             | INNER JOIN                                                        { flag1 = 1; } //
             | LEFT JOIN                                                         { flag1 = 2; } //filter($4 != NULL)
             | RIGHT JOIN                                                        { flag1 = 3; } //filter($6 != NULL)
             | FULL JOIN                                                         { flag1 = 0; } //0 filtros
             ;


whereList    : whereListSub                                                      { ; }
             | whereListSub OL whereList                                         { ; }
             ;

whereListSub : COMPLEX                                                           { ; } //add_filter($1):: filter( 
             | SIMPLE BETWEEN SIMPLE AND SIMPLE                                  { fprintf(out, "filter( %s > %s)\nfilter(%s < %s)\n",$1,$3,$1,$5); }
             | EXISTS '(' SelectBlock ')' ';'                                    { ; } //?                                          
             ;

groupbyList  : groupbyListSub                                                    { ; } 
             | groupbyListSub  ',' groupbyList                                   { ; }
             ;

groupbyListSub: SIMPLE                                                           { fprintf(out, "group( %s)\n",$1); } 
              | HAVING NAME '(' SIMPLE ')' BOP SIMPLE                            { fprintf(out, "filter( %s '(' %s ')' %s %s)\n",$2,$4,$6,$7); } 
              ;

orderbyList  : NAME                                                              { ; }
             | SIMPLE order                                                      { ; }
             | SIMPLE ',' orderbyList                                            { ; }
             | SIMPLE order ',' orderbyList                                      { ; }                                              
             ;

order        : ASC                                                               { ; }
             | DESC                                                              { ; }
             ;


OL           : AND                                                               { fprintf(out, "&"); }
             | ANDOP                                                             { fprintf(out, "&"); }
             | OR                                                                { fprintf(out, "|"); }
             ;

SIMPLE       : NAME                                                              { ; }
             | DATE                                                              { ; }
             | CONSTANT                                                          { ; }
             | BOOL                                                              { ; }
             | ANY                                                               { ; }
             | ALL                                                               { ; }
             ;


COMPLEX      : SIMPLE                                                            { fprintf(out, "%s",$1); while(counter>0){
                                                                                                            fprintf(out, ")");
                                                                                                            counter--;}
                                                                                                            fprintf(out, "\n");} //return simple
             | NOT COMPLEX                                                       { fprintf(out, "NOT"); } //return(Not(complex))
             | COMPLEX BOP COMPLEX                                               { fprintf(out, "%s",$2); } //return(BOP(complex))
             | NAME '(' COMPLEX ')'                                              { fprintf(out, "%s(",$1); counter++; } //return(op(complex))
             | COMPLEX AS NAME                                                   { fprintf(out, "change(%s)",$3); } //return complex , add NAME
             | NAME IN Inlist                                                    { fprintf(out, "IN(%s,",$1); }
             | '('COMPLEX OL COMPLEX ')'                                         { fprintf(stderr, "%s\n", );}
             ;

BOP          : NAME                                                              { fprintf(out, "%s(",$1); counter++; } // return NAME
             | COMPARISSON                                                       { fprintf(out, "%s",$1); } // return comparisson
             | SHIFT                                                             { fprintf(out, "%s",$1); } // return comparisson
             | OP                                                                { fprintf(out, "%s",$1); } // return iop
             ;

Inlist       : SIMPLE                                                            { fprintf(out, "%s)\n",$1); }
             | SIMPLE  ','  Inlist                                               { fprintf(out, "%s, ",$1); }
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
