%{
/* Declaraçoes C diversas */

#include "y.tab.h"
%}

Abrev ER
%%

AND|and 		                        	{ return AND; }
AS|as    						{ return AS; }
BEFORE|before		        			{ return BEFORE; }
JOIN|join		        			{ return JOIN; }
RIGTH|rigth		        			{ return RIGTH; }
LEFT|left		        			{ return LEFT; }
FULL|full		        			{ return FULL; }
INNER|inner		        			{ return INNER; }
ON|on		        		        	{ return ON; }
BETWEEN|between			        		{ return BETWEEN; }
EXISTS|exists 				        	{ yylval.subtok = 0; return EXISTS; }
FROM|from   						{ return FROM; }
GROUP[ \t]*BY|group[ \t]*by		        	{ return GROUP; }
ORDER[ \t]*BY|order[ \t]*by		        	{ return ORDERBY; }
HAVING|having 						{ return HAVING; }
IN|in     						{ return IN; }
IS|is     						{ return IS; }
NOT|not    						{ return NOT; }
OR|or     						{ return OR; }
SELECT|select						{ return SELECT; }
WHERE|where 						{ return WHERE; }
ASC|asc                         {return ASC;}
DESC|desc                       {return DESC;}
ANY|any                         {return ANY;}
ALL|all                         {return ALL;}


    /* numbers */

-?[0-9]+                	                	{ yylval.intval = atoi(yytext); return CONSTANTE; }

-?[0-9]+"."[0-9]* |
-?"."[0-9]+ |
-?[0-9]+E[-+]?[0-9]+ |
-?[0-9]+"."[0-9]*E[-+]?[0-9]+ |
-?"."[0-9]+E[-+]?[0-9]+ 	                	{ yylval.floatval = atof(yytext) ;return CONSTANTE; }

	/* booleans */
TRUE    						{ yylval.intval = 1; return BOOL; }
FALSE   						{ yylval.intval = 0; return BOOL; }



    /* operators*/

"&&"                                                    { yylval.strval = strdup(yytext);return ANDOP; }
"||"                                                    { yylval.strval = strdup(yytext);return OR; }
"="                                                     { yylval.strval = strdup(yytext);return BBOP; }
"<=>"                                                   { yylval.strval = strdup(yytext);return BBOP; }
">="                                                    { yylval.strval = strdup(yytext);return BBOP; }
">"                                                     { yylval.strval = strdup(yytext);return BBOP; }
"<="                                                    { yylval.strval = strdup(yytext);return BBOP; }
"<"                                                     { yylval.strval = strdup(yytext);return BBOP; }
"!="|"<>"                                               { yylval.strval = strdup(yytext);return BBOP; }//alterar
"<<"                                                    { yylval.strval = strdup(yytext);return IBOP; }
">>"                                                    { yylval.strval = strdup(yytext);return IBOP; }
":="                                                    { yylval.strval = strdup(yytext);return ASSIGN; }

"*"                                                     { yylval.strval = strdup(yytext); return IBOP: }
"/"                                                     { yylval.strval = strdup(yytext); return IBOP: }
"+"                                                     { yylval.strval = strdup(yytext); return IBOP: }
"-"                                                     { yylval.strval = strdup(yytext); return IBOP: }
    /* functions */

SUBSTR(ING)?/"("                                        { yylval.strval = strdup(yytext);return FSUBSTRING; }
TRIM/"("                                                { yylval.strval = strdup(yytext);return FTRIM; }
DATE_ADD/"("                                            { yylval.strval = strdup(yytext);return FDATE_ADD; }
DATE_SUB/"("                                            { yylval.strval = strdup(yytext);return FDATE_SUB; }

    /* NAMES */

date \'.*\'                                             { yylval.strval = strdup(yytext);return NAME; }
[A - Za - z][A - Za - z0 - 9_]*                         { yylval.strval = strdup(yytext);return NAME; }
"(.*?)"                                                 { yylval.strval = strdup(yytext);return REGEX; }



%%

int main(){
    yylex();
    return 0;
}
