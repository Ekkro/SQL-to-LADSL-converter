%{                                                                    
 #include <stdio.h>                                                                                                                      
 #include <strings.h>                                                  
 /* Declaracoes C diversas */                                          
 %}                                                                    
                                                                       

%token SELECT FROM WHERE GROUPBY ORDERBY HAVING NOME AS  
%token AND OR EXISTS OP NOT BETWEEN JOIN INNER LEFT RIGHT FULL ON CONSTANTE
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

listaSelect : listaSelectN														{ ; }
            | '*'                                      					        { ; }
            ;

listaSelectN : COMPLEXO													        { ; }
			 | COMPLEXO ',' listaSelectN 		    		 				    { ; }
             ;

listaFrom   : sublistaFrom														{ ; }
			| sublistaFrom ',' listaFrom										{ ; }

sublistaFrom: SIMPLES
			| Join SIMPLES             		 									{ ; }
		  	| Join SIMPLES ON SIMPLES '=' SIMPLES 								{ ; }
		  	| Join SIMPLES AS NOME 												{ ; }
		  	| Join SIMPLES AS NOME ON SIMPLES '=' SIMPLES 						{ ; }
          	| BlocoSelect                          								{ ; }
          	| BlocoSelect AS NOME                                       		{ ; }
          	;

Join		: JOIN 																{ ; }
			| INNER JOIN 														{ ; }
			| LEFT JOIN 														{ ; }
			| RIGHT JOIN 														{ ; }
			| FULL JOIN 														{ ; }
			;

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

OL 			: AND                                                 		        { ; }
   			| OR                                                  		        { ; }
   			| OL EXISTS '(' BlocoSelect ')' ';'                  		        { ; }
   			| NOT														        { ; }
   			;

SIMPLES 	: NOME														        { ; }
        	| CONSTANTE													        { ; }
        	;


COMPLEXO 	: SIMPLES													        { ; }
         	| COMPLEXO OP COMPLEXO										        { ; }
         	| NOME '(' COMPLEXO ')'										        { ; }
         	| COMPLEXO AS NOME											        { ; }
         	;






%%
int main(int argc, char **argv){

  yyparse();



	return 0;
}
