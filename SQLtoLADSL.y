%{                                                                    
 #include <stdio.h>                                                                                                                      
 #include <strings.h>
 #include "SQLtoLADSL.hpp"

    string current_expression;
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

WHERE_         : WHERE       whereList                                             {l.funcao(g);}
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

fromList       : subfromList                                                       { ; } 
               | subfromList ',' fromList                                          { ; }
               ;

subfromList    : NAME                                                              { g.newRoot($1); } 
               | Join NAME                                                         { ; } 
               | Join NAME ON Literal '=' Literal                                  {string Table = metadata_Table();
                                                                                    string type = metadata_type();
                                                                                    string filter();
                                                                                    add_join(Table,filter,type);} 
               
               | Join NAME AS NAME                                                 {add_rename($2,$4);}
               | Join NAME AS NAME ON Literal '=' Literal                          {string Table = metadata_table();
                                                                                    string type = metadata_type();
                                                                                    string filter(); 
                                                                                    add_join(Table,filter,type);
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

whereList      : whereListSub                                                      { ; }
               | whereListSub OL whereList                                         { ; }
               ;

whereListSub   : Expr                                                              {add_map_filter($1,current_expression); }
               | '(' whereList ')'                                                 { ; }
               | NAME IN Inlist                                                    { ; }
               | NAME BETWEEN Literal AND Literal                                  { ; }
               | EXISTS '(' SelectBlock ')' ';'                                    { ; }
               | Expr LIKE Expr                                                    { ; }                                        
               ;

groupbyList    : groupbyListSub                                                    {$$ =$1  ; } 
               | groupbyListSub  ',' groupbyList                                   { ; }
               ;

groupbyListSub : HAVING NAME '(' Literal ')' BOP Literal                           { ; }
	       | Literal                                                           {string Table = metadata_Table($1);
                                                                                    add_groupby(Table,$1);}
               ;

orderbyList    : orderbyListSub                                                    { ; }
               | orderbyListSub ',' orderbyList                                    { ; }                                            
                                       
               ;

orderbyListSub : NAME 	 	                                                   {string Table = metadata_Table($1); add_groupby(Table,$1); }
               | NAME order                                                        {string Table = metadata_Table($1); add_groupby(Table,$1); }                                         
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
