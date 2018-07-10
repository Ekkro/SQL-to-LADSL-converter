%{

 #include "SQLtoLADSL.hpp"

 int yylex(void);
 void yyerror(const char* s);

string a = "";
Graph mainGraph;
Graph g;
Ltree l;
vector<Ltree> trees;
int itr = 0;
vector<par> types;
int itr2 = 0;


%}

%union{
    std::string *str;
    int integer;
}

%token SELECT WHERE GROUPBY ORDERBY HAVING AS
%token AND OR EXISTS BETWEEN JOIN INNER LEFT RIGHT FULL ON IN ANDOP BEFORE IS END
%token LIKE REGEX VIRGULA PVIRGULA
/*%token REGEX*/


%token <str> NAME
%token <str> ATTRIBUTE
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
Final : SelectBlock
SelectBlock    : SELECT     selectList
                 FROM       fromList
                 WHERE_
                 GROUPBY_
                 ORDERBY_
                 PVIRGULA                                         {
                                                                   l = trees[0];mainGraph.newRoot(giveMeRoot(mainGraph.root));print_tree();l.rewrite(0);print_tree();resolve(0);returnf(); }

WHERE_         : WHERE       whereList                       { ; }
               |                                              {;}
               ;

GROUPBY_       : GROUPBY    groupbyList                      { ; }
               |                                              {;}
               ;


ORDERBY_       : ORDERBY    orderbyList                      { ; }
               |                                              {;}
               ;

selectList     : selectListN                                 {
                                    mainGraph.add_table("lineitem","shipdate","dimension");
                                    mainGraph.add_table("lineitem","extendedprice","measure");
                                    mainGraph.add_table("lineitem","discount","measure");
                                    mainGraph.add_table("lineitem","quantity","measure");
                                  }
               | IBOP                                         { mainGraph.add_select("*","") ; }
               ;

selectListN    : selectListNSub                              {;}
               | selectListN VIRGULA  selectListNSub          {;}
               ;

selectListNSub : Term                                        {mainGraph.add_select(types[$1].expr,""); /*cout << types[$1].expr << "\n"*/;}
               | Term AS NAME                                {mainGraph.add_select(types[$1].expr,*$3);}
               ;

fromList       : subfromList                                 { ; }
               | fromList VIRGULA subfromList                { ; }
               ;

subfromList    : NAME                                        {mainGraph.newRoot(*$1); }
               | Join NAME                                   { ; }
               | Join NAME ON Literal '=' Literal            {mainGraph.add_join(types[$6].type,getTable(types[$4].type),getTable(types[$6].type));}
               | Join NAME AS NAME                           {mainGraph.tables[*$4]=mainGraph.tables[*$2];}
               | Join NAME AS NAME ON Literal '=' Literal    {mainGraph.add_join(types[$8].type,getTable(types[$6].type),getTable(types[$8].type)); mainGraph.tables[*$4]=mainGraph.tables[*$2]; }
               | '{' SelectBlock '}'                         { ; }
               | '{' SelectBlock '}' AS NAME                 { ; }
               ;

Join           : JOIN                                        {/*$$ = "Normal"*/;}
               | INNER JOIN                                  {/*$$ = "Inner"*/;}
               | LEFT JOIN                                   {/*$$ = "Left"*/;}
               | RIGHT JOIN                                  {/*$$ = "Rigth"*/;}
               | FULL JOIN                                   {/*$$ = "Full"*/;}
               ;

whereList      : Exp                                         { cout << "where\n"; }
               ;

ExpR           : Exp AND Exp                                 {$$ = $1; cout << "3\n";change_trees(join_trees(trees[$1],trees[$3],"AND"),$1); }
               | Exp OR  Exp                                {$$ = $1; change_trees(join_trees(trees[$1],trees[$3],"OR"),$1); }
               ;

Exp            : Term                                        {$$ = itr;trees.push_back( create_tree(types[$1].expr,types[$1].type));itr++ ; }
               | ExpR                                        {$$ = $1 ; }
               | '(' ExpR ')'                                {$$ = $2 ; }
               | Literal BETWEEN Term AND Term                {$$ = itr;
                                                             string s = types[$1].expr;
                                                             string s2 = types[$1].expr;
                                                              s.append("<=");
                                                              s2.append(">=");
                                                              s.append(types[$3].expr);
                                                              s2.append(types[$5].expr);
                                                                trees.push_back( create_tree(s,types[$1].type));itr++ ;
                                                              trees.push_back( create_tree(s2,types[$1].type));itr++ ;
                                                                change_trees(join_trees(trees[$1],trees[$3],"AND"),$1);
                                                                }
               ;

Term           : Factor                                      {$$ = $1;}
               | '(' Term ')'                                {$$ = $2;}
               | Term BBOP Term                              {$$ = $1;
                                                                cout << "1\n";
                                                              types[$1].expr.append(*$2);
                                                              types[$1].expr.append(types[$3].expr);
                                                                        if((types[$1].type.size()!=0)&&(types[$3].type.size()!=0)){
                                                                              mainGraph.add_join(types[$3].type,getTable(types[$1].type),getTable(types[$3].type));
                                                                              types[$1].type = "JOIN";
                                                                        }else{
                                                                              mainGraph.add_map_filter(types[$1].type,types[$1].expr);
                                                                              types[$1].type = "NOT JOIN";
                                                                        }
                                                                cout << "2\n";
                                                                }

               | Term IBOP Term                              {$$ = $1; types[$1].expr.append(*$2);
                                                            types[$1].expr.append(types[$3].expr) ;
                                                            types[$1].type.append(types[$3].type); }
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
               | Args1 VIRGULA  Term                              {$$ = $1;
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

groupbyList    : groupbyListSub                              { cout << "gb\n"; }
               | groupbyList VIRGULA groupbyListSub              { ; }
               ;

groupbyListSub : HAVING NAME '(' Literal ')' BBOP Literal    { ; }
               | Literal                                     {string Table = getTable(types[$1].expr);
                                                              string s = Table;
                                                              s.append(".");
                                                              s.append(types[$1].expr);
                                                              mainGraph.add_groupby(Table,s);}
;

orderbyList    : orderbyListSub                              { ; }
               | orderbyList VIRGULA orderbyListSub              { ; }

               ;

orderbyListSub : Literal                                     { ; }
               | Literal order                                  { ; }
               ;

order          : ASC                                         { ; }
               | DESC                                        { ; }
                ;
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
                                                                par novo;
                                                                novo.type = "";
                                                                novo.expr = *$1;
                                                                  types.push_back(novo);
                                                                  itr2 ++;
                                                              }else{
                                                                  s.append(*$1);
                                                                par novo;
                                                                novo.type = s;
                                                                novo.expr = s;
                                                                  types.push_back(novo);
                                                                  itr2 ++;
                                                              }}


               | ATTRIBUTE                                    {$$ = itr2;
                                                              cout << *$1 << "\n";
                                                              string s = getTable(*$1);
                                                                par novo;
                                                                novo.type = s;
                                                                novo.expr = *$1;
                                                                  types.push_back(novo);
                                                                  itr2 ++;}

               | DATE                                        {$$ = itr2;
                                                                par novo;
                                                                novo.type = "";
                                                                novo.expr = *$1;
                                                                  types.push_back(novo);
                                                                  itr2 ++;}

               | CONSTANT                                    {$$ = itr2;
                                                                par novo;
                                                                novo.type = "";
                                                                novo.expr = *$1;
                                                                  types.push_back(novo);
                                                                  itr2 ++;}

               | BOOL                                        {$$ = itr2;
                                                                par novo;
                                                                novo.type = "";
                                                                novo.expr = *$1;
                                                                  types.push_back(novo);
                                                                  itr2 ++;}

               | ANY                                         {$$ = itr2;
                                                                par novo;
                                                                novo.type = "";
                                                                novo.expr = *$1;
                                                                  types.push_back(novo);
                                                                  itr2 ++;}

               | ALL                                         {$$ = itr2;
                                                                par novo;
                                                                novo.type = "";
                                                                novo.expr = *$1;
                                                                  types.push_back(novo);
                                                                  itr2 ++;}
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
#include "lex.yy.c"
#include "SQLtoLADSL.cpp"
 void yyerror(const char*s){
    printf("parsing aborted: %s\n",s);
 }


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
