 %{ /* -*- C++ -*- */
#include <cstdlib>
#include <cerrno>
#include <climits>
#include <string>

#undef yywrap
#define yywrap() 1

#define yyterminate() return token::END
 %}

%option noyywrap nounput batch debug

as              [Aa][Ss]
before          [Bb][Ee][Ff][Oo][Rr][Ee]
join            [Jj][Oo][Ii][Nn]
rigth           [Rr][Ii][Gg][Tt][Hh]
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

or              ([oO][rR]|\|\|)
and             ([aA][nN][dD]|&&)
eq              (=|==)
ne              (!=|<>)
le              <=
ge              >=
left            <<
right           >>
mais            +
div             /
mul             *
men             -

not             ([nN][oO][tT]|!)
true            [Tt][Rr][Uu][Ee]
false           [Ff][Aa][Ll][Ss][Ee]

int             [0-9]+
float           ([0-9]*\.[0-9]+|[0-9]+\.[0.9]*)
date            [\"'][0-9]{4}-[0-9]{2}-[0-9]{2}[\"']

name            [A-Za-z][A-Za-z0-9_]*

    %{
#define YY_USER_ACTION yylloc->columns (yyleng);
    %}

%x MLCOMMENT REGEXPRESSION
%%
%{
   yylloc->step ();
     typedef yy::laq_parser::token token;
       void toLower(std::string& str);
%}

<INITIAL>{and}                 { return token::AND; }
<INITIAL>{as}                  { return token::AS; }
<INITIAL>{before}              { return token::BEFORE; }
<INITIAL>{rigth}               { return token::RIGTH; }
<INITIAL>{left}                { return token::LEFT; }
<INITIAL>{full}                { return token::FULL; }
<INITIAL>{inner}               { return token::INNER; }
<INITIAL>{on}                  { return token::ON; }
<INITIAL>{between}             { return token::BETWEEN; }
<INITIAL>{exists}              { return token::EXISTS; }
<INITIAL>{from}                { return token::FROM; }
<INITIAL>{groupby}             { return token::GROUPBY; }
<INITIAL>{orderby}             { return token::ORDERBY; }
<INITIAL>{having}              { return token::HAVING; }
<INITIAL>{in}                  { return token::IN; }
<INITIAL>{is}                  { return token::IS; }
<INITIAL>{not}                 { return token::NOT; }
<INITIAL>{or}                  { return token::OR; }
<INITIAL>{select}              { return token::SELECT; }
<INITIAL>{where}               { return token::WHERE; }
<INITIAL>{asc}                 { return token::ASC; }
<INITIAL>{desc}                { return token::DESC; }
<INITIAL>{any}                 { return token::ANY; }
<INITIAL>{all}                 { return token::ALL; }
<INITIAL>{left}                { return token::LEFT; }
<INITIAL>{right}               { return token::RIGTH; }


left            <<
right           >>

<INITIAL>{int}                 { yylval->sval = new std::string( yytext );
                                     return token::INT;
                                                                    }
<INITIAL>{float}               { yylval->sval = new std::string( yytext );
                                     return token::FLOAT;
                                                                    }
<INITIAL>{date}                { yylval->sval = new std::string( yytext );
                                     return token::DATE;
                                                                    }

<INITIAL>{or}                  { yyval->sval = new string(yytext);
                                    return token::BBOP; }

<INITIAL>{and}                 { yyval->sval = new string(yytext);
                                    return token::BBOP; }

<INITIAL>{le}                  { yyval->sval = new string(yytext);
                                    return token::BBOP; }

<INITIAL>{ge}                  { yyval->sval = new string(yytext);
                                    return token::BBOP; }

<INITIAL>{eq}                  { yyval->sval = new string(yytext);
                                    return token::BBOP; }

<INITIAL>{ne}                  { yyval->sval = new string(yytext);
                                    return token::BBOP; }

<INITIAL>{mul}                  { yyval->sval = new string(yytext);
                                    return token::IBOP; }

<INITIAL>{mais}                  { yyval->sval = new string(yytext);
                                    return token::IBOP; }

<INITIAL>{div}                  { yyval->sval = new string(yytext);
                                    return token::IBOP; }
                                    return token::IBOP; }

<INITIAL>{men}                  { yyval->sval = new string(yytext);
                                    return token::IBOP; }

%%


void
laq::driver::scan_begin() {
      yy_flex_debug = trace_scanning;
        if (file.empty() || file == "-") {
                yyin = stdin;
                  }
          else if (!(yyin = fopen(file.c_str(), "r"))) {
                  error("Cannot open " + file + ": " + strerror(errno));
                      exit(EXIT_FAILURE);
                        }
}

void
laq::driver::scan_end() {
      fclose(yyin);
}

void
toLower(std::string& str) {
      for (char& c : str)
              c = (char) tolower(c);
}
