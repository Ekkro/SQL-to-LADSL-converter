%{

//#include <cstdlib>
//#include <cerrno>
//#include <climits>
//#include <string>
using namespace std;

//#undef yywrap
//#define yywrap() 1

//%option noyywrap nounput batch debug
#define yyterminate() return END
%}

%option noyywrap
%option nounput
%option noinput
%option yylineno

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
groupby         [ \t\n]*[Gg][Rr][Oo][Uu][Pp][ ]*[Bb][Yy][ \t\n]*
orderby         [ \t\n]*[Oo][Rr][Dd][Ee][Rr][ ]*[Bb][Yy][ \t\n]*
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
interval        [Ii][Nn][Tt][Ee][Rr][Vv][Aa][Ll]

Or              ([ \t\n]*+[oO][rR][ \t\n]*+|\|\|)
and             ([ \t\n]*+[aA][nN][dD][ \t\n]*|&&)
eq              [ \t\n]*[(=|==)][ \t\n]*
ne              [ \t\n]*[(!=|<>)][ \t\n]*
le              [ \t\n]*[<][=][ \t\n]*
l              [ \t\n]*[<][ \t\n]*
g              [ \t\n]*[>][ \t\n]*
ge              [ \t\n]*[>][=][ \t\n]*
mais            [ \t\n]*[+][ \t\n]*
div             [ \t\n]*[/][ \t\n]*
mul             [ \t\n]*[*][ \t\n]*
men             [ \t\n]*[-][ \t\n]*
virg            [ \t\n]*[,][ \t\n]*
pa            [ \t\n]*[(][ \t\n]*
pf            [ \t\n]*[)][ \t\n]*
pvirg           [ \t\n]*[;][ \t\n]*

Not             ([nN][oO][tT]|!)
true            [Tt][Rr][Uu][Ee]
false           [Ff][Aa][Ll][Ss][Ee]

int             [0-9]+
float           ([0-9]*\.[0-9]+|[0-9]+\.[0.9]*)
attribute       [A-Za-z][A-Za-z0-9_]*[.][A-Za-z][A-Za-z0-9_]*
name            [A-Za-z':][:'A-Za-z0-9_]*



string          \"[^"\n]*["\n]

stringp          \'[^'\n]*['\n]


Date            [ \t\n]*[dD][aA][tT][eE][ \t\n]+['][:0-9]*[']


%%

<INITIAL>{virg}                { return VIRGULA; }
<INITIAL>{pa}                { return PA; }
<INITIAL>{pf}                { return PF; }
<INITIAL>{pvirg}                { return PVIRGULA; }
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
<INITIAL>{interval}            { return INTERVAL; }



<INITIAL>{int}                 { yylval.str = new std::string( yytext );
                                     return CONSTANT; }

<INITIAL>{float}               { yylval.str = new std::string( yytext );
                                     return CONSTANT; }

<INITIAL>{Date}                { yylval.str = new std::string( yytext );
                                     return DATE; }

<INITIAL>{true}                { yylval.str = new std::string( yytext );
                                    return BOOL; }

<INITIAL>{false}                { yylval.str = new std::string( yytext );
                                    return BOOL; }



<INITIAL>{Or}                  { yylval.str = new string(yytext);
                                    return OR; }

<INITIAL>{and}                 { yylval.str = new string(yytext);
                                    return AND; }

<INITIAL>{le}                  { yylval.str = new string(yytext);
                                    return BBOP; }

<INITIAL>{l}                  { yylval.str = new string(yytext);
                                    return BBOP; }

<INITIAL>{g}                  { yylval.str = new string(yytext);
                                    return BBOP; }

<INITIAL>{ge}                  { yylval.str = new string(yytext);
                                    return BBOP; }

<INITIAL>{eq}                  { yylval.str = new string(yytext);
                                    return BBOP; }

<INITIAL>{ne}                  { yylval.str = new string(yytext);
                                    return BBOP; }

<INITIAL>{mul}                  { yylval.str = new string(yytext);
                                    return IBOP; }

<INITIAL>{mais}                  { yylval.str = new string(yytext);
                                    return IBOP; }

<INITIAL>{div}                  { yylval.str = new string(yytext);
                                    return IBOP; }

<INITIAL>{men}                  { yylval.str = new string(yytext);
                                    return IBOP; }

<INITIAL>{left}                  { yylval.str = new string(yytext);
                                    return IBOP; }

<INITIAL>{attribute}                 { yylval.str = new std::string( yytext );
                                     return ATTRIBUTE; }

<INITIAL>{name}                 { yylval.str = new std::string( yytext );
                                     return NAME; }

<INITIAL>{string}                 { yylval.str = new std::string( yytext );
                                    return CONSTANT; }

<INITIAL>{stringp}                 { yylval.str = new std::string( yytext );
                                    return CONSTANT; }



%%
