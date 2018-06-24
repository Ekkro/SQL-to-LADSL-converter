%{                                                                    
 #include <stdio.h>                                                                                                                      
 #include <strings.h>
 #include "SQLtoLADSL.hpp"

    string current_expression;
    string current_expression2;
    int current = 0;
%}
%token SELECT FROM WHERE GROUPBY ORDERBY HAVING AS  
%token AND OR EXISTS BETWEEN JOIN INNER LEFT RIGHT FULL ON CONSTANT BOOL IN ASC DESC DATE ANDOP ANY ALL
%token LIKE 

%token <string> NAME BOP NOT

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

ORDERBY_       : ORDERBY    orderbyList                                                  { ; }
               |                                                                   { ; }
               ;

selectList     : selectListN                                                       { ; }
               | '*'                                                               { ; }
               ;

selectListN    : selectListNSub                                                    { ; } 
               | selectListNSub ',' selectListN                                    { ; } 
               ;

selectListNSub : Expr                                                              {add_select($1); } 
               | Expr AS NAME                                                      {add_select($1);add_rename($1,$3,table); }
               ;

fromList       : subfromList                                                       { ; } 
               | subfromList ',' fromList                                          { ; }
               ;

subfromList    : NAME                                                              { g.newRoot($1); } 
               | Join NAME                                                         { ; } 
               | Join NAME ON Literal '=' Literal                                  {add_join($6,getTable($4),getTable($6));} 
               
               | Join NAME AS NAME                                                 {add_rename($2,$4);}
               | Join NAME AS NAME ON Literal '=' Literal                          {add_join($6,getTable($4),getTable($6)); 
                                                                                    add_rename($2,$4); }
               | '{' SelectBlock '}'                                               { ; } 
               | '{' SelectBlock '}' AS NAME                                       { ; } 
               ;

Join           : JOIN                                                              { ; } 
               | INNER JOIN                                                        { ; }
               | LEFT JOIN                                                         { ; }
               | RIGHT JOIN                                                        { ; }
               | FULL JOIN                                                         { ; } 
               ;

whereList      : whereListSub                                                      { l.ltree[current] = current_expression; }
               | whereList OL whereList                                         { ; }
               | '(' whereList ')'                                                 { ; }
               ;

whereListSub   : Expr                                                              {aux($1,current_expression,current_expression2); 
                                                                                    cleanexp();}
               | NAME IN Inlist                                                    { ; }
               | NAME BETWEEN Literal AND Literal                                  { ; }
               | EXISTS '(' SelectBlock ')' ';'                                    { ; }
               | Expr LIKE Expr                                                    { ; }                                        
               ;

groupbyList    : groupbyListSub                                                    {$$ =$1  ; } 
               | groupbyListSub  ',' groupbyList                                   { ; }
               ;

groupbyListSub : HAVING NAME '(' Literal ')' BOP Literal                           { ; }
	       | Literal                                                           {string Table = getTable($1);
                                                                                    add_groupby(Table,$1);}
               ;

orderbyList    : orderbyListSub                                                    { ; }
               | orderbyListSub ',' orderbyList                                    { ; }                                            
                                       
               ;

orderbyListSub : NAME 	 	                                                   {;}
               | NAME order                                                        {;}
               ;

order          : ASC                                                               { $$ = $1; }
               | DESC                                                              { $$ = $1; }
               ;

OL             : AND                                                               {$$ = $1 ; }
               | ANDOP                                                             {$$ = $1 ; }
               | OR                                                                {$$ = $1 ; }
               ;

Literal        : NAME                                                              {$$ = $1 ; }
               | NAME'.'NAME                                                       {$$ = $3 ; addexp($3);}
               /* | NAME'_'NAME                                                       {$$ = $3 ; addexp($3);}*/
               | DATE                                                              {$$ = $1 ; }
               | CONSTANT                                                          {$$ = $1 ; }
               | BOOL                                                              {$$ = $1 ; }
               | ANY                                                               {$$ = $1 ; }
               | ALL                                                               {$$ = $1 ; }
               ;


Expr           : Literal                                                            {$$ = $1 ; }
               | NOT Expr                                                          {$$ = $1 + $2 ; }
               | Expr BOP Expr                                                     {$$ = $1+$2+$3 ; }
               | Expr '=' Expr                                                     {$$ = $1+$2+$3 ; }
               | NAME '(' Expr ')'                                                 {$$ = $1+$2+$3+$4 ; }
               | '('SelectBlock')'                                                 { ; }
               ;


Inlist         : Literal                                                            {$$ = $1 ; }
               | Literal  ','  Inlist                                               {$$ = $1 ; }
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
