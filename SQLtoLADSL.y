%{

 #include <stdio.h>
 #include <strings.h>
 #include "SQLtoLADSL.hpp"

 void yyerror(char *s);
 int yylex(void);

%}

%union{
    string *str;
    int integer;

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

%type <integer> Literal
%type <str> Join
%type <integer> ExpR
%type <integer> Exp
%type <integer> Term
%type <integer> Factor
%type <str> groupbyList
%type <str> groupbyListSub
%type <str> order
%type <integer> Args1
%type <integer> Args
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
                 ';'                                         { l = trees[0];resolve(0); }

WHERE_         : WHERE       whereList                       { ; }
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

selectListNSub : Term                                        {mainGraph.add_select(types[$1].expr); }
               | Term AS NAME                                {mainGraph.add_select(types[$1].expr); /*add_rename(types[$1],$3,table); */}
               ;

fromList       : subfromList                                 { ; }
               | fromList ',' subfromList                    { ; }
               ;

subfromList    : NAME                                        { mainGraph.newRoot(*$1); }
               | Join NAME                                   { ; }
               | Join NAME ON Literal '=' Literal            {mainGraph.add_join(types[$6].type,getTable(types[$4].type),getTable(types[$6].type));}
               | Join NAME AS NAME                           {/*add_rename($2,types[$4])*/;}
               | Join NAME AS NAME ON Literal '=' Literal    {mainGraph.add_join(types[$8].type,getTable(types[$6].type),getTable(types[$8].type)); /*add_rename($2,types[$4]);*/ }
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

ExpR           : Exp AND Exp                                {$$ = $1;trees[ $1 ] = join_trees(trees[$1],trees[$3],"AND"); }
               | Exp OR  Exp                                {$$ = $1;trees[ $1 ] = join_trees( trees[$1],trees[$3],"OR"); }//delete $3
               ;

Exp            : Term                                        {$$ = itr;trees[ itr++ ] =  create_tree(types[$1].expr,types[$1].type) ; }
               | ExpR                                        {$$ = $1 ; }
               | '(' ExpR ')'                                {$$ = $2 ; }
               ;

Term           : Factor                                      {$$ = $1;}
               | Term BBOP Term                              {$$ = $1;
                                                              types[$1].expr.append(*$2);
                                                              types[$1].expr.append(types[$3].expr);
                                                                        if((types[$1].type.size()!=0)&&(types[$3].type.size()!=0)){
                                                                              mainGraph.add_join(types[$3].type,getTable(types[$1].type),getTable(types[$3].type));
                                                                              types[$1].type = "JOIN";
                                                                        }else{
                                                                              mainGraph.add_map_filter(types[$1].type,types[$1].expr);
                                                                              types[$1].type = "NOT JOIN";
                                                                        }}

               | Term IBOP Term                              {$$ = $1; types[$1].expr.append(*$2);
                                                            types[$1].expr.append(types[$3].expr) ;
                                                            types[$1].type.append(types[$3].type); }
/*             | Term '/' Factor                             { ; }
               | Term '+' Factor                             { ; }
               | Term '-' Factor                             { ; }
               | Term '*' Factor                             { ; }
*/
               ;

Factor         : Literal                                     {$$ = $1;}
               | NAME '(' Args ')'                           {$$ = $3;
                                                              string s = "";
                                                              s.append(*$1);
                                                              s.append("(");
                                                              s.append(types[$3].expr);
                                                              s.append(")");
                                                              types[$3].expr = s;}
               | NOT Factor                                  {$$ = $2;
                                                              string s = "";
                                                              s.append(*$1);
                                                              s.append(" ");
                                                              s.append(types[$2].expr);
                                                              types[$2].expr = s;}
               ;

Args           : Args1                                       {$$ = $1;}
               |                                             { ; }
               ;

Args1          : Term                                        {$$ = $1 ; }
               | Args1 ',' Term                              {$$ = $1;
                                                            types[$1].expr.append( ",");
                                                            types[$1].expr.append(types[$3].expr) ;
                                                            types[$1].type.append(types[$3].type); }
               | Args1 ' ' Term                              {$$ = $1;
                                                            types[$1].expr.append( " ");
                                                            types[$1].expr.append(types[$3].expr) ;
                                                            types[$1].type.append(types[$3].type); }
               ;
/*
               | NAME IN Inlist                              { ; }
               | NAME BETWEEN Literal AND Literal            { ; }
               | EXISTS '(' SelectBlock ')' ';'              { ; }
               | Literal LIKE REGEX                          { ; }// expressao regular
               ;
*/

groupbyList    : groupbyListSub                              { ; }
               | groupbyList ',' groupbyListSub              { ; }
               ;

groupbyListSub : HAVING NAME '(' Literal ')' BBOP Literal    { ; }
               | Literal                                     {string Table = getTable(types[$1].expr);
                                                              string s = Table;
                                                              s.append(".");
                                                              s.append(types[$1].expr);
                                                              mainGraph.add_groupby(Table,s);}
               ;

orderbyList    : orderbyListSub                              { ; }
               | orderbyList ',' orderbyListSub              { ; }

               ;

orderbyListSub : NAME                                        { ; }
               | NAME order                                  { ; }
               ;

order          : ASC                                         { ; }
               | DESC                                        { ; }
/*               ;

OL             : AND                                         {$$ = $1 ; }
               | ANDOP                                       {$$ = $1 ; }
               | OR                                          {$$ = $1 ; }
               ;
*/
Literal        : NAME                                        {string s = getTable(*$1);
                                                               s.append(".");
                                                              $$ = itr2;
                                                              if(!s.compare(".")){
                                                                  types[itr2].type = "";
                                                                  types[itr2++].expr = *$1;
                                                              }else{
                                                                  s.append(*$1);
                                                                  types[itr2].type = s;
                                                                  types[itr2++].expr = s;
                                                              }}


               | NAME '.' NAME                               {$$ = itr2;
                                                              string s = "";
                                                              s.append(*$1);
                                                              s.append(".");
                                                              s.append(*$3);
                                                              types[itr2++].type = s;
                                                              types[itr2++].expr = s;}

               | DATE                                        {$$ = itr2;
                                                              types[itr2].expr = *$1 ;
                                                              types[itr2++].type = "";}

               | CONSTANT                                    {$$ = itr2;
                                                              types[itr2].expr = *$1 ;
                                                              types[itr2++].type = "";}

               | BOOL                                        {$$ = itr2;
                                                              types[itr2].expr = *$1 ;
                                                              types[itr2++].type = "";}

               | ANY                                         {$$ = itr2;
                                                              types[itr2].expr = *$1 ;
                                                              types[itr2++].type = "";}

               | ALL                                         {$$ = itr2;
                                                              types[itr2].expr = *$1 ;
                                                              types[itr2++].type = "";}
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

    FILE *  out = fopen("name.vm", "w");
    if (out == NULL){
        printf("Error opening file!\n");
        exit(1);
    }
//    char codigo[1023*1024];
    fprintf(out, "start\n");
    yyparse();
    fprintf(out, "stop\n");

    fclose(out);
    return 0;
}
