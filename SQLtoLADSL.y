%{                                                                    
 #include <stdio.h>                                                                                                                      
 #include <strings.h>                                                  
 /* Declaracoes C diversas */                                          
 %}                                                                    
                                                                       

%token SELECT FROM WHERE GROUPBY ORDERBY HAVING Name AS  
%token AND OR EXISTS OP NOT BETWEEN JOIN INNER LEFT RIGHT FULL ON CONSTANTE
%%  


SelectBlock : SELECT     selectList                                              { ; }
              FROM       fromList                                                { ; }
              WHERE_                                                             { ; }
              GROUPBY_                                                           { ; }
              ORDERBY_                                                           { ; }              

WHERE_       : WHERE       whereList                                             { ; }
             |                                                                   { ; }
             ;

GROUPBY_     : GROUPBY    groupbyList                                            { ; }
             |                                                                   { ; }
             ;

ORDERBY_     : ORDERBY    orderbyList                                            { ; }
             |                                                                   { ; }
             ;

selectList   : selectListN                                                       { ; }
             | '*'                                                               { ; }
             ;

selectListN  : COMPLEX                                                           { ; }
             | COMPLEX ',' selectListN                                           { ; }
             ;

fromList     : subfromList                                                       { ; }
             | subfromList ',' fromList                                          { ; }
             ;

subfromList  : SIMPLE                                                            { ; }
             | Join SIMPLE                                                       { ; }
             | Join SIMPLE ON SIMPLE '=' SIMPLE                                  { ; }
             | Join SIMPLE AS Name                                               { ; }
             | Join SIMPLE AS Name ON SIMPLE '=' SIMPLE                          { ; }
             | SelectBlock                                                       { ; }
             | SelectBlock AS Name                                               { ; }
             ;

Join         : JOIN                                                              { ; }
             | INNER JOIN                                                        { ; }
             | LEFT JOIN                                                         { ; }
             | RIGHT JOIN                                                        { ; }
             | FULL JOIN                                                         { ; }
             ;

whereList    : COMPLEX                                                           { ; }
             | COMPLEX OL  whereList                                             { ; }
             | BETWEEN SIMPLE AND SIMPLE                                         { ; }                                            
             ;

groupbyList  : COMPLEX                                                           { ; }
             | COMPLEX ',' groupbyList                                           { ; }
             | COMPLEX HAVING havingList                                         { ; }
             ;

orderbyList  : SIMPLE                                                            { ; }
             | SIMPLE Name                                                       { ; }
             | SIMPLE ',' orderbyList                                            { ; }                                               
             ;

havingList   : COMPLEX                                                           { ; }
             | COMPLEX OL  havingList                                            { ; }
             ;

OL           : AND                                                               { ; }
             | OR                                                                { ; }
             | OL EXISTS '(' SelectBlock ')' ';'                                 { ; }
             | NOT                                                               { ; }
             ;

SIMPLE       : Name                                                              { ; }
             | CONSTANTE                                                         { ; }
             ;

COMPLEX      : SIMPLE                                                            { ; }
             | COMPLEX BOP COMPLEX                                               { ; }
             | Name '(' COMPLEX ')'                                              { ; }
             | COMPLEX AS Name                                                   { ; }
             ;

BOP          : Name                                                              { ; } 
             | COMPARISSON                                                       { ; }
             | OP                                                                { ; }
             ;




%%
int main(int argc, char **argv){

  yyparse();
    return 0;
}
