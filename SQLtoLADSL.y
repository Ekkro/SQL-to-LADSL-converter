%{                                                                    
 #include <stdio.h>                                                                                                                      
 #include <strings.h>                                                  
 /* Declaracoes C diversas */                                          
 %}                                                                    
                                                                       

%token SELECT FROM WHERE GROUPBY ORDERBY HAVING NOME AS  
%token AND OR EXISTS OP NOT BETWEEN
%%  


BlocoSelect : SELECT     listaSelect                     				        { ; }
              FROM       listaFrom                       				        { ; }
              WHERE_     			                      				        { ; }
              GROUPBY_   		                         				        { ; }
              ORDERBY_   		                         				        { ; }
              

WHERE_ 		: WHERE  	 listaWhere                            			        { ; }
       		|                                                 			        { ; }
       		;

GROUPBY_ 	: GROUPBY    listaGB                              			        { ; }
         	|                                               			        { ; }
         	;

ORDERBY_	: ORDERBY    listaOB                               			        { ; }
       		|                                                 			        { ; }
       		;

listaSelect : COMPLEXO													        { ; }
			| COMPLEXO ',' listaSelect 		    		 				        { ; }
            | '*'                                      					        { ; }
            ;


listaFrom 	: SIMPLES virgula listaFrom
			| Join SIMPLES virgula listaFrom              		 				{ ; }
		  	| Join SIMPLES ON SIMPLES '=' SIMPLES virgula listaFrom				{ ; }
		  	| Join SIMPLES AS NOME virgula listaFrom							{ ; }
		  	| Join SIMPLES AS NOME ON SIMPLES '=' SIMPLES virgula listaFrom		{ ; }
          	| BlocoSelect                          								{ ; }
          	| BlocoSelect AS NOME                                       		{ ; }
          	|
          	;

Join		: JOIN 																{ ; }
			| INNER JOIN 														{ ; }
			| LEFT JOIN 														{ ; }
			| RIGHT JOIN 														{ ; }
			| FULL JOIN 														{ ; }
			;
/*
ASNNOME 	: AS NOME                                        			        { ; }
        	|                                                			        { ; }
        	;
*/
listaWhere 	: COMPLEXO													        { ; }
			| COMPLEXO OL  listaWhere                    				        { ; }
           	| BETWEEN SIMPLES AND SIMPLES               				        { ; }                                            
           	;

listaGB 	: COMPLEXO															{ ; }
			| COMPLEXO ',' listaGB               					            { ; }
        	| COMPLEXO HAVING listaHaving                                       { ; }
        	;

listaOB 	: SIMPLES													        { ; }
			| SIMPLES NOME														{ ; }
			| SIMPLES ',' listaOB                       			        	{ ; }                                               
        	;

listaHaving : COMPLEXO													        { ; }
			| COMPLEXO OL  listaHaving                    				        { ; }
			;

virgula 	: ','                                            			        { ; }
        	|                                                			        { ; }
        	;

OL 			: AND                                                 		        { ; }
   			| OR                                                  		        { ; }
   			| OL EXISTS '(' BlocoSelect ')' ';'                  		        { ; }
   			| NOT														        { ; }
   			;

/*TESTE
SIMPLES  	: NOME                                          			        { ; }
         	| NOME AS NOME                                  			        { ; }
         	;
*/

SIMPLES 	: NOME														        { ; }
        	| CONSTANTE													        { ; }
        	;


COMPLEXO 	: SIMPLES													        { ; }
         	| COMPLEXO OP COMPLEXO										        { ; }
         	| NOME '(' COMPLEXO ')'										        { ; }
         	| COMPLEXO AS NOME											        { ; }
         	;


OP      




%%
int main(int argc, char **argv){

  yyparse();



	return 0;
}
