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
[ -+&~ | ^ / % *(), .; ! =]                             { return yytext[0]; }

"&&"                                                    { return ANDOP; }
"||"                                                    { return OR; }
//"="                                                     { yylval.subtok = 4; return BOP; }
"<=>"                                                   { yylval.subtok = 12; return BOP; }
">="                                                    { yylval.subtok = 6;return BOP; }
">"                                                     { yylval.subtok = 2; return BOP; }
"<="                                                    { yylval.subtok = 5; return BOP; }
"<"                                                     { yylval.subtok = 1; return BOP; }
"!="|"<>"                                               { yylval.subtok = 3; return BOP; }
"<<"                                                    { yylval.subtok = 1; return BOP; }
">>"                                                    { yylval.subtok = 2; return BOP; }
":="                                                    { return ASSIGN; }

"*"                                                     { yylval.cha = 'm' ; return BOP: }
"/"                                                     { yylval.cha = 'd' ; return BOP: }
"+"                                                     { yylval.cha = 'P' ; return BOP: }
"-"                                                     { yylval.cha = 'M' ; return BOP: }
    /* functions */

SUBSTR(ING)?/"("                                        { return FSUBSTRING; }
TRIM/"("                                                { return FTRIM; }
DATE_ADD/"("                                            { return FDATE_ADD; }
DATE_SUB/"("                                            { return FDATE_SUB; }

    /* NAMES */

date \'.*\'                                             { yylval.strval = strdup(yytext);return NAME; }
[A - Za - z][A - Za - z0 - 9_]*                         { yylval.strval = strdup(yytext);return NAME; }



%%
                     
int main(){
    yylex();
    return 0;
}
