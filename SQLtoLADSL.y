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
stringstream ss;


%}

%union{
    std::string *str;
    int integer;
}

%token SELECT WHERE GROUPBY ORDERBY HAVING AS
%token AND OR EXISTS BETWEEN JOIN INNER LEFT RIGHT FULL ON IN ANDOP BEFORE IS INTERVAL
%token LIKE REGEX VIRGULA PVIRGULA PA PF
/*%token REGEX*/


%token END 0 "end of file"
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
%type <str> orderbyList
%type <str> orderbyListSub
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
                 PVIRGULA
                 "end of file"                                        {mainfun(); }

WHERE_         : WHERE       whereList                       { ; }
               |                                              {;}
               ;

GROUPBY_       : GROUPBY    groupbyList                      { ; }
               |                                              {;}
               ;


ORDERBY_       : ORDERBY    orderbyList                      { ; }
               |                                             { ; }
               ;

selectList     : selectListN                                 {
  mainGraph.add_table("lineitem","extendedprice","measure");
  mainGraph.add_table("lineitem","discount","measure");
  mainGraph.add_table("lineitem","shipdate","measure");
  mainGraph.add_table("lineitem","quantity","measure");
                                  }
               | IBOP                                         { mainGraph.add_select("*","") ; }
               ;

selectListN    : selectListNSub                              {;}
               | selectListN VIRGULA  selectListNSub          {;}
               ;

selectListNSub : Term                                        {mainGraph.add_select(types[$1].expr,"");}
               | Term AS NAME                                {mainGraph.add_select(types[$1].expr,*$3);}
               ;

fromList       : subfromList                                 { ; }
               | fromList VIRGULA subfromList                { ; }
               ;

subfromList    : NAME                                        {mainGraph.newRoot(*$1);}
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

whereList      : Exp                                        { ; }
               ;

ExpR           : Exp AND Exp                                {if($1 != -1){
                                                                if($3 != -1){
                                                                  change_trees(join_trees(trees[$1],trees[$3],"AND"),$1);
                                                                }
                                                                $$ = $1;
                                                            }else{
                                                                if($3 != -1){
                                                                  $$ = $3;
                                                                }else{
                                                                  $$ = -1;
                                                                }
                                                            }
                                                          }

               | Exp OR  Exp                                {if($1 != -1){
                                                               if($3 != -1){
                                                                 change_trees(join_trees(trees[$1],trees[$3],"OR"),$1);
                                                               }
                                                               $$ = $1;
                                                           }else{
                                                               if($3 != -1){
                                                                 $$ = $3;
                                                               }else{
                                                                 $$ = -1;
                                                               }
                                                           }
                                                         }
               ;

Exp            : Term                                        {if(types[$1].type!="JOIN"){mainGraph.add_map_filter(types[$1].type,types[$1].expr);$$ = itr;
                                                                                          trees.push_back( create_tree(types[$1].expr,types[$1].type));itr++;}
                                                              else($$ = -1);}
               | ExpR                                        {$$ = $1 ; }
               | PA ExpR PF                                {$$ = $2 ;}
               | Literal BETWEEN Term AND Term              {string s = types[$1].expr;
                                                            string s2 = types[$1].expr;
                                                             s.append(" <= ");
                                                             s2.append(" >= ");
                                                             s.append(types[$3].expr);
                                                             s2.append(types[$5].expr);
                                                             mainGraph.add_map_filter(types[$1].type,s);
                                                             mainGraph.add_map_filter(types[$1].type,s2);
                                                             trees.push_back( create_tree(s,types[$1].type));itr+=1 ;
                                                             trees.push_back( create_tree(s2,types[$1].type));itr+=1 ;
                                                             change_trees(join_trees(trees[itr-2],trees[itr-1],"AND"),itr-2);
                                                             $$ = itr-2;
                                                           }
               ;

Term           : Factor                                      {$$ = $1;}
               | PA Term PF                                {$$ = $2;}
               | Term BBOP Term                              {$$ = $1;
                                                              //cout << "1\n";
                                                              types[$1].expr.append(*$2);
                                                              types[$1].expr.append(types[$3].expr);
                                                                        if((types[$1].type.size()!=0)&&(types[$3].type.size()!=0)){
                                                                              mainGraph.add_join(types[$3].type,getTable(types[$1].type),getTable(types[$3].type));
                                                                              types[$1].type = "JOIN";
                                                                    /*    }else{
                                                                              types[$1].type = "NOT JOIN";*/
                                                                        }
                                                                }

               | Term IBOP Term                              {$$ = $1;
                                                            types[$1].expr.append(*$2);
                                                            types[$1].expr.append(types[$3].expr) ;
                                                            types[$1].type.append(types[$3].type);
                                                            //cout << types[$1].expr;
                                                            }
               ;


Factor         : Literal                                     {$$ = $1;}
               | NAME PA Args PF                           {$$ = $3;
                                                              string s = "";
                                                              s.append(*$1);
                                                              s.append("(");
                                                              s.append(types[$3].expr);
                                                              s.append(")");
                                                              types[$3].expr = s;}
               | INTERVAL Factor Factor                   {$$ = $2;
                                                              string s = "INTERVAL ";
                                                              s.append(types[$2].expr);
                                                              s.append(" ");
                                                              s.append(types[$3].expr);
                                                              types[$2].expr = s;}

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

groupbyList    : groupbyListSub                              { ; }
               | groupbyList VIRGULA groupbyListSub              { ; }
               ;

groupbyListSub : HAVING NAME PA Literal PF BBOP Literal    { ; }
               | Literal                                     {string Table = getTable(types[$1].expr);
                                                              mainGraph.add_groupby(Table,types[$1].expr);}
               ;

orderbyList    : orderbyListSub                              { ; }
               | orderbyList VIRGULA orderbyListSub          { ; }
               ;

orderbyListSub : Literal                                     { ; }
               | Literal order                               { ; }
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
                                                              //string s = getTable(*$1);
                                                                par novo;
                                                                novo.type = *$1;
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
                                                                  itr2 ++;
                                                                }

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

    yyparse();
    string s = ss.str();
    cout << s;

    return 0;
}
