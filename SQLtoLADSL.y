%{                                                                    
 #include <stdio.h>                                                                                                                      
 #include <strings.h>
 #include "SQLtoLADSL.h"
%}
%token SELECT FROM WHERE GROUPBY ORDERBY HAVING NAME AS  
%token AND OR EXISTS NOT BETWEEN JOIN INNER LEFT RIGHT FULL ON CONSTANT BOOL IN ASC DESC DATE ANDOP ANY ALL
%token LIKE BOP  

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
                 ';'                                                               { fprintf(out,"resultado\n"); }     

WHERE_         : WHERE       whereList                                             { ; }
               |                                                                   { ; }
               ;

GROUPBY_       : GROUPBY    groupbyList                                                   { ; }
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

fromList       : subfromList                                                       { aux->sizetables++; } 
               | subfromList ',' fromList                                          { aux->sizetables++; }
               ;

subfromList    : NAME                                                              { ; } 
               | Join NAME                                                         { ; } 
               | Join NAME ON Literal '=' Literal                                    {$$ = add_key($2,$4,$6); } 
               | Join NAME AS NAME                                                 {$$ = add_rename($2,$4); }
               | Join NAME AS NAME ON Literal '=' Literal                            {$$ = add_key($2,$6,$8);add_rename($2,$4); }
               | '{' SelectBlock '}'                                               {$$ = from_select($2); } 
               | '{' SelectBlock '}' AS NAME                                       {$$ = from_select($2); add_renameT($2,$5); } 
               ;

Join           : JOIN                                                              { ; } 
               | INNER JOIN                                                        { ; }
               | LEFT JOIN                                                         { ; }
               | RIGHT JOIN                                                        { ; }
               | FULL JOIN                                                         { ; } 
               ;

whereList      : whereListSub                                                      {$$ = $1 ; }
               | whereListSub OL whereList                                         {opLogic($1,$2,$3); }
               ;

whereListSub   : Expr                                                              {add_Literalfilter($1,table); }
               | '(' whereList ')'                                                 { ; }
               | NAME IN Inlist                                                    {$$ = add_in($1,$3); }
               | NAME BETWEEN Literal AND Literal                                    {$$ = add_filter($1,$3,'>',table); add_filter($1,$5,'<',table); }
               | EXISTS '(' SelectBlock ')' ';'                                    { ; }
               | Expr LIKE Expr                                                    { ; }                                        
               ;

groupbyList    : groupbyListSub                                                    {$$ =$1  ; } 
               | groupbyListSub  ',' groupbyList                                   { ; }
               ;

groupbyListSub : HAVING NAME '(' Literal ')' BOP Literal                           { ; }
				 | Literal
               ;

orderbyList    : orderbyListSub                                                    { ; }
               | orderbyListSub ',' orderbyList                                    { ; }                                            
                                       
               ;

orderbyListSub : NAME 	 	                                                      {add_orderby($1); }
             | NAME order                                                       {add_orderby($1,$2); }                                         
               ;

order          : ASC                                                               { $$ = $1; }
               | DESC                                                              { $$ = $1; }
               ;

OL             : AND                                                               {$$ = $1 ; }
               | ANDOP                                                             {$$ = $1 ; }
               | OR                                                                {$$ = $1 ; }
               ;

Literal        : NAME                                                              {$$ = $1 ; }
               | NAME'.'NAME                                                       {$$ = $3 ; table = $1; }
               | DATE                                                              {$$ = $1 ; }
               | CONSTANT                                                          {$$ = $1 ; }
               | BOOL                                                              {$$ = $1 ; }
               | ANY                                                               {$$ = $1 ; }
               | ALL                                                               {$$ = $1 ; }
               ;


Expr           : Literal                                                            {$$ = $1 ; }
               | NOT Expr                                                          {$$ = not($2) ; }
               | Expr BOP Expr                                                     {$$ = bop($1,$2,$3) ; }
               | Expr '=' Expr                                                     {$$ = add_key($1,$2,$3) ; }
               | NAME '(' Expr ')'                                                 {$$ = func($1,$3) ; }
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
