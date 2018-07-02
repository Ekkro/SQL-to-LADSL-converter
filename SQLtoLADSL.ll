%{

#include <cstdlib>
#include <cerrno>
#include <climits>
#include <string>
#include "SQLtoLADSL.tab.h"

#undef yywrap
#define yywrap() 1

#define yyterminate() return END
%}

%option noyywrap nounput batch debug

as              [Aa][Ss]
before          [Bb][Ee][Ff][Oo][Rr][Ee]
join            [Jj][Oo][Ii][Nn]
right           [Rr][Ii][Gg][Hh][Tt]
left            [Ll][Ee][Ff][Tt]
full            [Ff][Uu][Ll][Ll]
inner           [Ii][Nn][Nn][Ee][Rr]
on              [Oo][Nn]
between         [Bb][Ee][Tt][Ww][Ee][Ee][Nn]
exists          [Ee][Xx][Ii][Ss][Tt][Ss]
from            [Ff][Rr][Oo][Mm]
groupby         [Gg][Rr][Oo][Uu][Pp][ ]*[Bb][Yy]
orderby         [Oo][Rr][Dd][Ee][Rr][ ]*[Bb][Yy]
having          [Hh][Aa][Vv][Ii][Nn][Gg]
in              [Ii][Nn]
is              [Ii][Ss]
not             [Nn][Oo][Tt]
select          [Ss][Ee][Ll][Ee][Cc][Tt]
where           [Ww][Hh][Ee][Rr][Ee]
asc             [Aa][Ss][Cc]
desc            [Dd][Ee][Ss][Cc]
any             [Aa][Nn][Yy]
all             [Aa][Ll][Ll]
substring       [Ss][Uu][Bb][Ss][Tt][Rr]([In][Nn][Gg])?

Or              ([oO][rR]|\|\|)
and             ([aA][nN][dD]|&&)
eq              (=|==)
ne              (!=|<>)
le              "<="
ge              ">="
mais            "+"
div             "/"
mul             "*"
men             "-"

Not             ([nN][oO][tT]|!)
true            [Tt][Rr][Uu][Ee]
false           [Ff][Aa][Ll][Ss][Ee]

int             [0-9]+
float           ([0-9]*\.[0-9]+|[0-9]+\.[0.9]*)
name            [A-Za-z][A-Za-z0-9_]*
Date            (0?[1-9]|1[0-2])[\/](0?[1-9]|[12]\d|3[01])[\/](19|20)\d{2}

%%

<INITIAL>{as}                  { return AS; }
<INITIAL>{before}              { return BEFORE; }
<INITIAL>{full}                { return FULL; }
<INITIAL>{inner}               { return INNER; }
<INITIAL>{on}                  { return ON; }
<INITIAL>{between}             { return BETWEEN; }
<INITIAL>{exists}              { return EXISTS; }
<INITIAL>{from}                { return FROM; }
<INITIAL>{groupby}             { return GROUPBY; }
<INITIAL>{orderby}             { return ORDERBY; }
<INITIAL>{having}              { return HAVING; }
<INITIAL>{in}                  { return IN; }
<INITIAL>{is}                  { return IS; }
<INITIAL>{Not}                 { return NOT; }
<INITIAL>{select}              { return SELECT; }
<INITIAL>{where}               { return WHERE; }
<INITIAL>{asc}                 { return ASC; }
<INITIAL>{desc}                { return DESC; }
<INITIAL>{any}                 { return ANY; }
<INITIAL>{all}                 { return ALL; }
<INITIAL>{right}               { return RIGHT; }


<INITIAL>{int}                 { yylval->str = new std::string( yytext );
                                     return CONSTANT; }

<INITIAL>{float}               { yylval->str = new std::string( yytext );
                                     return CONSTANT; }

<INITIAL>{Date}                { yylval->str = new std::string( yytext );
                                     return DATE; }

<INITIAL>{true}                { yylval->str = new std::string( yytext );
                                    return BOOL; }

<INITIAL>{false}                { yylval->str = new std::string( yytext );
                                    return BOOL; }



<INITIAL>{Or}                  { yylval->str = new string(yytext);
                                    return BBOP; }

<INITIAL>{and}                 { yylval->str = new string(yytext);
                                    return BBOP; }

<INITIAL>{le}                  { yylval->str = new string(yytext);
                                    return BBOP; }

<INITIAL>{ge}                  { yylval->str = new string(yytext);
                                    return BBOP; }

<INITIAL>{eq}                  { yylval->str = new string(yytext);
                                    return BBOP; }

<INITIAL>{ne}                  { yylval->str = new string(yytext);
                                    return BBOP; }

<INITIAL>{mul}                  { yylval->str = new string(yytext);
                                    return IBOP; }

<INITIAL>{mais}                  { yylval->str = new string(yytext);
                                    return IBOP; }

<INITIAL>{div}                  { yylval->str = new string(yytext);
                                    return IBOP; }

<INITIAL>{men}                  { yylval->str = new string(yytext);
                                    return IBOP; }

<INITIAL>{left}                  { yylval->str = new string(yytext);
                                    return IBOP; }


%%

int main(void)
{
    yylex();
    return 0;
}