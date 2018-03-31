%{
/* Declaraçoes C diversas */

#include "y.tab.h"
%}

Abrev ER
%%

AND|and 		                        	{ return AND; }
AS|as    						{ return AS; }
BEFORE|before		        			{ return BEFORE; }
BETWEEN|between			        		{ return BETWEEN; }
EXISTS|exists 				        	{ yylval.subtok = 0; return EXISTS; }
FROM|from   						{ return FROM; }
GROUP[ \t]*BY|group[ \t]*by		        	{ return GROUP; }
ORDER[ \t]*BY|order[ \t]*by		        	{ return ORDERBY; }
HAVING|having 						{ return HAVING; }
IN|in     						{ return IN; }
IS|is     						{ return IS; }
JOIN|join   						{ return JOIN; }
NOT|not    						{ return NOT; }
OR|or     						{ return OR; }
SELECT|select						{ return SELECT; }
WHERE|where 						{ return WHERE; }

    /* numbers */

-?[0-9]+                	                	{ yylval.intval = atoi(yytext); return INTNUM; } 

-?[0-9]+"."[0-9]* |
-?"."[0-9]+ |
-?[0-9]+E[-+]?[0-9]+ |
-?[0-9]+"."[0-9]*E[-+]?[0-9]+ |
-?"."[0-9]+E[-+]?[0-9]+ 	                	{ yylval.floatval = atof(yytext) ;return APPROXNUM; }
    
	/* booleans */
TRUE    						{ yylval.intval = 1; return BOOL; }
FALSE   						{ yylval.intval = 0; return BOOL; }



    /* operators */
[ -+&~ | ^ / % *(), .; !]                               { return yytext[0]; }

"&&"                                                    { return ANDOP; }
"||"                                                    { return OR; }
"="                                                     { yylval.subtok = 4; return COMPARISON; }
"<=>"                                                   { yylval.subtok = 12; return COMPARISON; }
">="                                                    { yylval.subtok = 6;return COMPARISON; }
">"                                                     { yylval.subtok = 2; return COMPARISON; }
"<="                                                    { yylval.subtok = 5; return COMPARISON; }
"<"                                                     { yylval.subtok = 1; return COMPARISON; }
"!="|"<>"                                               { yylval.subtok = 3; return COMPARISON; }
"<<"                                                    { yylval.subtok = 1; return SHIFT; }
">>"                                                    { yylval.subtok = 2; return SHIFT; }
":="                                                    { return ASSIGN; }

    /* functions */

SUBSTR(ING)?/"("                                        { return FSUBSTRING; }
TRIM/"("                                                { return FTRIM; }
DATE_ADD/"("                                            { return FDATE_ADD; }
DATE_SUB/"("                                            { return FDATE_SUB; }

    /* NOMES */

date \'.*\'                                             { yylval.strval = strdup(yytext);return NOME;; }
[A - Za - z][A - Za - z0 - 9_]*                         { yylval.strval = strdup(yytext);return NOME;; }



%%
                     
int main(){
    yylex();
    return 0;
}
