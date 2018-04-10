%{                                                                    
 #include <stdio.h>                                                                                                                      
 #include <strings.h>                                                  
 /* Declaracoes C diversas */                                          
 %}                                                                    
                                                                       

%token SELECT FROM WHERE GROUPBY ORDERBY HAVING Name AS  
%token AND OR EXISTS OP NOT BETWEEN JOIN INNER LEFT RIGHT FULL ON CONSTANT
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

subfromList  : SIMPLE                                                            { ; } // tabela
             | Join SIMPLE                                                       { ; } // Join tabela
             | Join SIMPLE ON SIMPLE '=' SIMPLE                                  { ; } // Join tabela1 on tabela1.key = tabela2.key
             | Join SIMPLE AS Name                                               { ; } // Join tabela1 as tabela
             | Join SIMPLE AS Name ON SIMPLE '=' SIMPLE                          { ; } // Join tablea1 as tabela on tabela.key = tabela2.key
             | '{' SelectBlock '}'                                               { ; } // {Select...}
             | '{' SelectBlock '}' AS Name                                       { ; } // {Select...} as tabela
             ;

Join         : JOIN                                                              { ; }
             | INNER JOIN                                                        { ; }
             | LEFT JOIN                                                         { ; }
             | RIGHT JOIN                                                        { ; }
             | FULL JOIN                                                         { ; }
             ;


whereList    : whereListSub                                                      { ; }
             | whereListSub OL whereList                                         { ; } 
             ;

whereListSub : COMPLEX                                                           { ; } 
             | SIMPLE BETWEEN SIMPLE AND SIMPLE                                  { ; }
             | EXISTS '(' SelectBlock ')' ';'                                    { ; }                                           
             ;

groupbyList  : SIMPLE                                                            { ; } 
             | SIMPLE  ',' groupbyList                                           { ; }
             | SIMPLE HAVING havingList                                          { ; }
             | SIMPLE HAVING havingList ',' groupbyList                          { ; }
             ;

orderbyList  : SIMPLE                                                            { ; }
             | SIMPLE Name                                                       { ; }
             | SIMPLE ',' orderbyList                                            { ; }
             | SIMPLE Name ',' orderbyList                                       { ; }                                              
             ;

havingList   : COMPLEX                                                           { ; }
             | COMPLEX OL  havingList                                            { ; }
             ;

OL           : AND                                                               { ; }
             | OR                                                                { ; }
             ;

SIMPLE       : Attribute                                                         { ; } // tabela.atributo
		     | Name                                                              { ; } // string
             | CONSTANT                                                          { ; } // 1
             ;

COMPLEX      : SIMPLE                                                            { ; }
			 | NOT COMPLEX                                                       { ; }
             | COMPLEX BOP COMPLEX                                               { ; }
             | OP '(' COMPLEX ')'                                                { ; }
             | COMPLEX AS Name                                                   { ; }
             ;

OP           : Name                                                              { ; } // in
		     | Name OP                                                           { ; } // not in
		     ;

BOP          : Name                                                              { ; } // a like b -> like(a,b)
             | COMPARISSON                                                       { ; } // a > b -> (a > b)
             | IOP                                                               { ; } // a + b -> (a + b)
             ;




%%
int main(int argc, char **argv){

  yyparse();
    return 0;
}
