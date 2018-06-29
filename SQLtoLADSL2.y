%{
 #include <stdio.h>
 #include <strings.h>
 #include "SQLtoLADSL.hpp"

    string currentexpression1;
    string currentexpression12;
    int current = 0;
%}

typedef struct{
    string literal;
    string type;
} par;

%union{
    string str;
    //pair<string,string> pair;
    par pair;

}

%token SELECT FROM WHERE GROUPBY ORDERBY HAVING AS
%token AND OR EXISTS BETWEEN JOIN INNER LEFT RIGHT FULL ON CONSTANT BOOL IN ASC DESC DATE ANDOP ANY ALL
%token LIKE


%token <str> NAME 
%token <str> BOP NOT
%token <str> NOT

%type <pair> literal


/*
union para definir tipos
token para terminais
type para nao terminais

*/
%right '='
%left OP
%right NOT
%left COMPARISSON
%left SHIFT
%left BOP

%%

SelectBlock    : SELECT     selectList
                 FROM       fromList
                 WHERE_
                 GROUPBY_
                 ORDERBY_
                 ';'                                                               { ; }

WHERE_         : WHERE       whereList                                             {l.funcao(g);}
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
               | selectListN ',' selectListNSub                                    { ; }
               ;

selectListNSub : Expr                                                              {add_select($1); }
               | Expr AS NAME                                                      {add_select($1); /*add_rename($1,$3,table); */}
               ;

fromList       : subfromList                                                       { ; }
               | fromList ',' subfromList                                          { ; }
               ;

subfromList    : NAME                                                              { g.newRoot($1); }
               | Join NAME                                                         { ; }
               | Join NAME ON Literal '=' Literal                                  {add_join($6,getTable($4),getTable($6));}
               | Join NAME AS NAME                                                 {/*add_rename($2,$4)*/;}
               | Join NAME AS NAME ON Literal '=' Literal                          {add_join($6,getTable($4),getTable($6)); /*add_rename($2,$4);*/ }
               | '{' SelectBlock '}'                                               { ; }
               | '{' SelectBlock '}' AS NAME                                       { ; }
               ;

Join           : JOIN                                                              { ; }
               | INNER JOIN                                                        { ; }
               | LEFT JOIN                                                         { ; }
               | RIGHT JOIN                                                        { ; }
               | FULL JOIN                                                         { ; }
               ;

whereList      : ExpR                                                              { ; }
               ;

ExpR           : Exp BBOP Exp                                                      { ; }
               | Exp                                                               { ; }
               ;

Exp            : Term                                                              { ; }
               | Exp OR Term                                                       { ; }
               ;

Term           : Factor                                                            { ; }
               | Term AND Factor                                                   { ; }
               | Term IBOP Factor                                                  { ; }
               | Term From Factor                                                  { ; }
/*             | Term '/' Factor                                                   { ; }
               | Term '+' Factor                                                   { ; }
               | Term '-' Factor                                                   { ; }
               | Term '*' Factor                                                   { ; }
*/
               ;

Factor         : Literal                                                           { ; }
               | NAME '(' Args ')'                                                 { ; }
               | NOT Factor                                                        { ; }
               | '(' ExpR ')'                                                      { ; }
               ;

Args           : Args1                                                             { ; }
               |                                                                   { ; }
               ;

Args1          : Exp
               | Args1 ',' Exp                                                     { ; }
               ;
/*
               | NAME IN Inlist                                                    { ; }
               | NAME BETWEEN Literal AND Literal                                  { ; }
               | EXISTS '(' SelectBlock ')' ';'                                    { ; }
               | Literal LIKE REGEX                                                { ; }// expressao regular
               ;
*/

groupbyList    : groupbyListSub                                                    {$$ =$1; }
               | groupbyList ',' groupbyListSub                                    { ; }
               ;

groupbyListSub : HAVING NAME '(' Literal ')' BBOP Literal                          { ; }
               | Literal                                                           {string Table = getTable($1); add_groupby(Table,$1);}
               ;

orderbyList    : orderbyListSub                                                    { ; }
               | orderbyList ',' orderbyListSub                                    { ; }

               ;

orderbyListSub : NAME                                                              { ; }
               | NAME order                                                        { ; }
               ;

order          : ASC                                                               { $$ = $1; }
               | DESC                                                              { $$ = $1; }
/*               ;

OL             : AND                                                               {$$ = $1 ; }
               | ANDOP                                                             {$$ = $1 ; }
               | OR                                                                {$$ = $1 ; }
               ;
*/
Literal        : NAME                                                              {string s = getTable($1); 
                                                                                    $<literal>$ = s+"."+$1;
                                                                                    $<type>$ = "dimension";}
               | NAME'.'NAME                                                       {$<literal>$ = $1+"."+$3;
                                                                                    $<type>$ = "dimension"
                                                                                    addexp($1+$3);}//?
               | DATE                                                              {$<literal>$ = $1 ;
                                                                                    $<type>$ = "measure"}
               | CONSTANT                                                          {$<literal>$ = $1 ;
                                                                                    $<type>$ = "measure"}
               | BOOL                                                              {$<literal>$ = $1 ;
                                                                                    $<type>$ = "measure"}
               | ANY                                                               {$<literal>$ = $1 ;
                                                                                    $<type>$ = "measure"}
               | ALL                                                               {$<literal>$ = $1 ;
                                                                                    $<type>$ = "measure"}
               ;


/*
Expr           : Literal                                                           {$$ = $1 ; }
               | NOT Expr                                                          {$$ = $1 + $2 ; }
               | Expr BOP Expr                                                     {$$ = $1+$2+$3 ; }
               | Expr '=' Expr                                                     {$$ = $1+$2+$3 ; }
               | NAME '(' Expr ')'                                                 {$$ = $1+$2+$3+$4 ; }
               | '('SelectBlock')'                                                 { ; }
               ;

*/
Inlist         : Literal                                                           {$$ = $1 ; }
               | InList ',' Literal                                                {$$ = $3 ; }
               ;

%%
int main(int argc, char **argv){

    out = fopen("name.vm", "w");
    if (out == NULL){
        printf("Error opening file!\n");
        exit(1);
    }
    char codigo[1023*1024];
    fprintf(out, "start\n");
    yyparse();
    fprintf(out, "stop\n");

    fclose(out);
    return 0;
}
