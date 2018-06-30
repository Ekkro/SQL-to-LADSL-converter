%{
 #include <stdio.h>
 #include <strings.h>
 #include "SQLtoLADSL.hpp"

%}

%union{
    string str;
    //pair<string,string> pair;
    par pair;

}

%token SELECT FROM WHERE GROUPBY ORDERBY HAVING AS
%token AND OR EXISTS BETWEEN JOIN INNER LEFT RIGHT FULL ON IN ANDOP 
%token LIKE REGEX
/*%token REGEX*/


%token <str> NAME 
%token <str> BOP 
%token <str> NOT
%token <str> ASC
%token <str> DESC
%token <str> DATE
%token <str> CONSTANT
%token <str> BOOL
%token <str> ANY
%token <str> ALL

%type <pair> Literal
%type <str> Join
%type <str> ExpR
%type <str> Term
%type <str> Factor
%type <str> groupbyList
%type <str> groupbyListSub
%type <str> order
/*%type <str> Inlist*/



/*
union para definir tipos
token para terminais
type para nao terminais

*/
%precedence OR
%precedence BOP
%precedence FROM

/*
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

selectListNSub : ExpR                                        {add_select($1); }
               | ExpR AS NAME                                {add_select($1); /*add_rename($1,$3,table); */}
               ;

fromList       : subfromList                                 { ; }
               | fromList ',' subfromList                    { ; }
               ;

subfromList    : NAME                                        { g.newRoot($1); }
               | Join NAME                                   { ; }
               | Join NAME ON Literal '=' Literal            {add_join($6,getTable($4),getTable($6));}
               | Join NAME AS NAME                           {/*add_rename($2,$4)*/;}
               | Join NAME AS NAME ON Literal '=' Literal    {add_join($6,getTable($4),getTable($6)); /*add_rename($2,$4);*/ }
               | '{' SelectBlock '}'                         { ; }
               | '{' SelectBlock '}' AS NAME                 { ; }
               ;

Join           : JOIN                                        {$$ = "Normal";}
               | INNER JOIN                                  {$$ = "Inner";}
               | LEFT JOIN                                   {$$ = "Left";}
               | RIGHT JOIN                                  {$$ = "Rigth";}
               | FULL JOIN                                   {$$ = "Full";}
               ;

whereList      : ExpR                                        { ; }
               ;

ExpR           : Exp BOP Exp                                 { ; }
               | Exp                                         { ; }
               ;

Exp            : Term                                        { ; }
               | Exp OR Term                                 { ; }
               ;

Term           : Factor                                      {$$ = $1;}
               | Term AND Factor                             { ; }
               | Term BOP Factor                             { ; }
               | Term FROM Factor                            { ; }
/*             | Term '/' Factor                             { ; }
               | Term '+' Factor                             { ; }
               | Term '-' Factor                             { ; }
               | Term '*' Factor                             { ; }
*/
               ;

Factor         : Literal                                     {$$ = $1;}
               | NAME '(' Args ')'                           { ; }
               | NOT Factor                                  {$$ = $2;}
               | '(' ExpR ')'                                {$$ = $2;}
               ;

Args           : Args1                                       { ; }
               |                                             { ; }
               ;

Args1          : Exp                                         { ; }
               | Args1 ',' Exp                               { ; }
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

groupbyListSub : HAVING NAME '(' Literal ')' BOP Literal     { ; }
               | Literal                                     {string Table = getTable($1);
                                                              add_groupby(Table,$1);}
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
Literal        : NAME                                        {string s = getTable($1); 
                                                              $<literal>$ = s+"."+$1;
                                                              $<type>$ = "dimension";}

               | NAME'.'NAME                                 {$<literal>$ = $1+"."+$3;
                                                              $<type>$ = "dimension"
                                                              addexp($1+$3);}//?

               | DATE                                        {$<literal>$ = $1 ;
                                                              $<type>$ = "measure"}

               | CONSTANT                                    {$<literal>$ = $1 ;
                                                              $<type>$ = "measure"}

               | BOOL                                        {$<literal>$ = $1 ;
                                                              $<type>$ = "measure"}

               | ANY                                         {$<literal>$ = $1 ;
                                                              $<type>$ = "measure"}

               | ALL                                         {$<literal>$ = $1 ;
                                                              $<type>$ = "measure"}
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
