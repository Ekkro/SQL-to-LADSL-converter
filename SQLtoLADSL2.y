%{
 #include <stdio.h>
 #include <strings.h>
 #include "SQLtoLADSL.hpp"

%}

%union{
    string *str;
    //pair<string,string> pair;
    par *pair;
    Ltree tree;

}

%token SELECT WHERE GROUPBY ORDERBY HAVING AS
%token AND OR EXISTS BETWEEN JOIN INNER LEFT RIGHT FULL ON IN ANDOP
%token LIKE REGEX
/*%token REGEX*/


%token <str> NAME
%token <str> BBOP
%token <str> BOP
%token <str> IBOP
%token <str> NOT
%token <str> ASC
%token <str> DESC
%token <str> DATE
%token <str> CONSTANT
%token <str> BOOL
%token <str> ANY
%token <str> ALL
%token <str> FROM

%type <pair> Literal
%type <str> Join
%type <tree> ExpR
%type <tree> Exp
%type <pair> Term
%type <pair> Factor
%type <str> groupbyList
%type <str> groupbyListSub
%type <str> order
%type <pair> Args1
%type <pair> Args
/*%type <str> Inlist*/



/*
union para definir tipos
token para terminais
type para nao terminais

*/
%left AND
%left OR
%left IBOP
%left BBOP
/*
%precedence OR
%precedence IBOP
%precedence BBOP
%precedence FROM
%precedence OR
%precedence BOP
%precedence FROM
%left AND
%left OR
%left BOP
%right FROM
%nonassoc
%right '='
%left OP
%right NOT
%left COMPARISSON
%left SHIFT
%left BOP
*/

%%

SelectBlock    : SELECT     selectList
                 FROM       fromList
                 WHERE_
                 GROUPBY_
                 ORDERBY_
                 ';'                                         { ; }

WHERE_         : WHERE       whereList                       {l.funcao(g);}
               |                                             { ; }
               ;

GROUPBY_       : GROUPBY    groupbyList                      { ; }
               |                                             { ; }
               ;

ORDERBY_       : ORDERBY    orderbyList                      { ; }
               |                                             { ; }
               ;

selectList     : selectListN                                 { ; }
               | '*'                                         { ; }
               ;

selectListN    : selectListNSub                              { ; }
               | selectListN ',' selectListNSub              { ; }
               ;

selectListNSub : Term                                        {add_select($1.expr); }
               | Term AS NAME                                {add_select($1.expr); /*add_rename($1,$3,table); */}
               ;

fromList       : subfromList                                 { ; }
               | fromList ',' subfromList                    { ; }
               ;

subfromList    : NAME                                        { g.newRoot($1); }
               | Join NAME                                   { ; }
               | Join NAME ON Literal '=' Literal            {add_join($6.type,getTable($4.type),getTable($6.type));}
               | Join NAME AS NAME                           {/*add_rename($2,$4)*/;}
               | Join NAME AS NAME ON Literal '=' Literal    {add_join($6.type,getTable($4.type),getTable($6.type)); /*add_rename($2,$4);*/ }
               | '{' SelectBlock '}'                         { ; }
               | '{' SelectBlock '}' AS NAME                 { ; }
               ;

Join           : JOIN                                        {/*$$ = "Normal"*/;}
               | INNER JOIN                                  {/*$$ = "Inner"*/;}
               | LEFT JOIN                                   {/*$$ = "Left"*/;}
               | RIGHT JOIN                                  {/*$$ = "Rigth"*/;}
               | FULL JOIN                                   {/*$$ = "Full"*/;}
               ;

whereList      : Exp                                         { ; }
               ;

ExpR           : Exp AND Exp                                {$$ = join_trees($1,$3,"AND"); }
               | Exp OR  Exp                                {$$ = join_trees($1,$3,"OR"); }
               ;

Exp            : Term                                        {$$ = cria_arvore($1.expr,$1.type) ; }
               | ExpR                                        {$$ = $1 ; }
               | '(' ExpR ')'                                {$$ = $2 ; }
               ;

Term           : Factor                                      {$$ = $1;}
               | Term BBOP Term                              {$$.expr = $1.expr+$2+$3.expr;
                                                                        if(($1.type.size()!=0)&&($3.type.size()!=0)){
                                                                              (add_join($2.type,getTable($1.type),getTable($2.type));
                                                                        }else{
                                                                              add_map_filter($1.type,$1.expr+$2+$3.expr);
                                                                        }
                                                              $$.type = $1.type;}
               | Term IBOP Term                              {$$.expr = $1.expr+$2+$3.expr ; $$.type = $1.type + $3.type; }
/*             | Term '/' Factor                             { ; }
               | Term '+' Factor                             { ; }
               | Term '-' Factor                             { ; }
               | Term '*' Factor                             { ; }
*/
               ;

Factor         : Literal                                     {$$.expr = $1;}
               | NAME '(' Args ')'                           {$$.expr = $1+"("+$3.expr+")"; $$.type = $3.type; }
               | NOT Factor                                  {$$.expr = $1+$2.expr; $$.type = $2.type;}
               ;

Args           : Args1                                       {$$ = $1 ; }
               |                                             { ; }
               ;

Args1          : Term                                        {$$ = $1 ; }
               | Args1 ',' Term                              {$$.expr = $1.expr+"."+$3.expr ; $$.type = $1.type + $3.type; }
               | Args1 ' ' Term                              {$$.expr = $1.expr+"."+$3.expr ; $$.type = $1.type + $3.type; }
               ;
/*
               | NAME IN Inlist                              { ; }
               | NAME BETWEEN Literal AND Literal            { ; }
               | EXISTS '(' SelectBlock ')' ';'              { ; }
               | Literal LIKE REGEX                          { ; }// expressao regular
               ;
*/

groupbyList    : groupbyListSub                              {$$ = $1;}
               | groupbyList ',' groupbyListSub              { ; }
               ;

groupbyListSub : HAVING NAME '(' Literal ')' BBOP Literal    { ; }
               | Literal                                     {string Table = getTable($1.expr);
                                                              add_groupby(Table,Table+"."+$1.expr);}
               ;

orderbyList    : orderbyListSub                              { ; }
               | orderbyList ',' orderbyListSub              { ; }

               ;

orderbyListSub : NAME                                        { ; }
               | NAME order                                  { ; }
               ;

order          : ASC                                         {$$ = $1;}
               | DESC                                        {$$ = $1;}
/*               ;

OL             : AND                                         {$$ = $1 ; }
               | ANDOP                                       {$$ = $1 ; }
               | OR                                          {$$ = $1 ; }
               ;
*/
Literal        : NAME                                        {string s = getTable($1)+".";
                                                              $$.expr = s+$1;
                                                              $$.type = "";}

               | NAME'.'NAME                                 {$$.expr = $1+"."+$3;
                                                              $$.type = $1+"."+$3;}

               | DATE                                        {$$.expr = $1 ;
                                                              $$.type = "";}

               | CONSTANT                                    {$$.expr = $1 ;
                                                              $$.type = "";}

               | BOOL                                        {$$.expr = $1 ;
                                                              $$.type = "";}

               | ANY                                         {$$.expr = $1 ;
                                                              $$.type = "";}

               | ALL                                         {$$.expr = $1 ;
                                                              $$.type = "";}
               ;


/*
Expr           : Literal                                     {$$ = $1 ; }
               | NOT Expr                                    {$$ = $1 + $2 ; }
               | Expr BOP Expr                               {$$ = $1+$2+$3 ; }
               | Expr '=' Expr                               {$$ = $1+$2+$3 ; }
               | NAME '(' Expr ')'                           {$$ = $1+$2+$3+$4 ; }
               | '('SelectBlock')'                           { ; }
               ;

*/
/*
Inlist         : Literal                                     {$$ = $1;}
               | Inlist ',' Literal                          {$$ = $3;}
               ;
*/

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
