%{                                                                    
 #include <stdio.h>                                                                                                                      
 #include <strings.h>                                                  
 /* Declaracoes C diversas */                                          
 %}                                                                    
                                                                       

%token SELECT FROM WHERE GROUPBY ORDERBY HAVING NOME AS  
%token AND OR EXISTS OP NOT BETWEEN
%%  


BlocoSelect : SELECT     listaSelect                     { ; }
              FROM       listaFrom                       { ; }
              WHERE_     listaWhere                      { ; }
              GROUPBY_   listaGB                         { ; }
              ORDERBY_   listaOB                         { ; }
              

WHERE_ : WHERE                                           { ; }
       |                                                 { ; }
       ;

GROUPBY_ : GROUPBY                                       { ; }
         |                                               { ; }
         ;

ORDERBY_: ORDERBY                                        { ; }
       |                                                 { ; }
       ;
HAVING_ : HAVING                                         { ; }
        |                                                { ; }
        ;

listaSelect : ATRIBUTOF ASNNOME virgula  listaSelect     { ; }
            | '*'                                        { ; }
            ;


listaFrom : NOME ASNNOME  virgula listaFrom            { ; }
          | BlocoSelect ASNNOME                          { ; }
          |                                              { ; }
          ;
ASNNOME : AS NOME                                        { ; }
        |                                                { ; }
        ;

listaWhere : ATRIBUTOF OL  listaWhere                    { ; }
           | BETWEEN ATRIBUTO AND ATRIBUTO               { ; }
           |                                             { ; }
           ;
listaGB : ATRIBUTO virgula listaGB HAVING_               { ; }
        |                                                { ; }
        ;
listaOB : ATRIBUTO virgula listaOB                       { ; }
        |                                                { ; }
        ;
virgula : ','                                            { ; }
        |                                                { ; }
        ;
OL : AND                                                 { ; }
   | OR                                                  { ; }
   | OL_ EXISTS '(' BlocoSelect ')' ';'                  { ; }
   | NOT                                                 { ; }
   ;
OL_ : OL                                                 { ; }
    |                                                    { ; }
    ;

ATRIBUTO : NOME                                          { ; }
         | NOME AS NOME                                  { ; }
         ;
ATRIBUTOF : NOME                                         { ; }
          | NOME '(' ATRIBUTOF ')'                     { ; }
        /* este Nome ( atributof ) seria funçao, mas como temos o lex assim
        neste momento é como se fosse um nome.
        se quisermos distingir, temos que obrigar a que atributos 
        tenham <nomeTabela>_nome e assim um nome so seria funcao
        e o outro um atributo. Temos de ver se cobre todos os casos.
        */
          | NOME OP ATRIBUTOF                            { ; }
          ;

SIMPLES : NOME
        | CONSTANTE
        ;


COMPLEXO : SIMPLES
         | COMPLEXO OP COMPLEXO
         | NOME '(' COMPLEXO ')'
         | COMPLEXO AS NOME
         ;


OP      




%%
int main(int argc, char **argv){

  yyparse();



	return 0;
}
