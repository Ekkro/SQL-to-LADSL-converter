/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 1 "SQLtoLADSL.y"
                                                                    
 #include <stdio.h>                                                                                                                      
 #include <strings.h>
 #include "SQLtoLADSL.h"
#line 26 "y.tab.c"

#if ! defined(YYSTYPE) && ! defined(YYSTYPE_IS_DECLARED)
/* Default: YYSTYPE is the semantic value type. */
typedef int YYSTYPE;
# define YYSTYPE_IS_DECLARED 1
#endif

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define SELECT 257
#define FROM 258
#define WHERE 259
#define GROUPBY 260
#define ORDERBY 261
#define HAVING 262
#define NAME 263
#define AS 264
#define AND 265
#define OR 266
#define EXISTS 267
#define OP 268
#define NOT 269
#define BETWEEN 270
#define JOIN 271
#define INNER 272
#define LEFT 273
#define RIGHT 274
#define FULL 275
#define ON 276
#define CONSTANT 277
#define SHIFT 278
#define BOOL 279
#define IN 280
#define ASC 281
#define DESC 282
#define COMPARISSON 283
#define DATE 284
#define ANDOP 285
#define ANY 286
#define ALL 287
#define LIKE 288
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    3,    3,    4,    4,    5,    5,    1,    1,    9,
    9,   10,   10,    2,    2,   12,   12,   12,   12,   12,
   12,   12,   13,   13,   13,   13,   13,    6,    6,   15,
   15,   15,   15,   15,   15,    7,    7,   18,   18,    8,
    8,   20,   20,   21,   21,   16,   16,   16,   14,   14,
   14,   14,   14,   14,   14,   11,   11,   11,   11,   11,
   19,   19,   19,   19,   17,   17,
};
static const YYINT yylen[] = {                            2,
    8,    2,    0,    2,    0,    2,    0,    1,    1,    1,
    3,    1,    3,    1,    3,    1,    2,    6,    4,    8,
    3,    5,    1,    2,    2,    2,    2,    1,    3,    1,
    3,    3,    5,    5,    3,    1,    3,    7,    1,    1,
    3,    1,    2,    1,    1,    1,    1,    1,    1,    3,
    1,    1,    1,    1,    1,    1,    2,    3,    4,    3,
    1,    1,    1,    1,    1,    3,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    0,   52,   53,   51,   54,   55,    9,
    0,    0,    8,    0,    0,   56,    0,    0,    0,    0,
    0,    0,    0,   63,   62,   61,   64,    0,    0,   50,
   60,   16,   23,    0,    0,    0,    0,    0,    0,    0,
    0,   11,   13,    0,   59,   24,   25,   26,   27,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    2,    0,
    0,    0,    0,   15,    0,    0,    0,    0,    0,    0,
    0,    0,   46,   48,   47,    0,    0,    0,    4,   39,
    0,    0,    0,    0,    0,   22,    0,    0,   32,    0,
   31,    0,   29,    0,    0,    0,    6,    0,    1,    0,
    0,    0,    0,    0,    0,   37,   44,   45,   43,    0,
    0,   18,   33,   66,   34,    0,   41,    0,    0,   20,
    0,   38,
};
static const YYINT yydgoto[] = {                         20,
   12,   39,   52,   63,   83,   59,   79,   97,   13,   14,
   60,   40,   41,   16,   61,   76,   89,   81,   28,   98,
  109,
};
static const YYINT yysindex[] = {                      -233,
   27,    0,   -8,   49,    0,    0,    0,    0,    0,    0,
 -233, -227,    0,   -2,   90,    0,   49, -220, -243,    3,
 -116,   49, -218,    0,    0,    0,    0,   49,   14,    0,
    0,    0,    0, -225, -219, -214, -213, -233, -206,   15,
 -201,    0,    0,   51,    0,    0,    0,    0,    0,  -62,
   38, -196, -116, -253, -198,  -18,   31,   16,    0,   81,
 -251, -189, -184,    0, -195, -193, -183, -193, -193, -233,
   40,   49,    0,    0,    0,   38, -181,   33,    0,    0,
   41, -171,   37, -177,   39,    0, -164,   58,    0,   62,
    0,   51,    0,   66, -189, -265,    0,   61,    0, -193,
 -193, -193, -193,   48, -193,    0,    0,    0,    0, -171,
   47,    0,    0,    0,    0,   68,    0, -193,   51,    0,
 -193,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,  -41,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -148,  -43,    0,    0,    0,  -32,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  -55,  -57,
    0,    0,    0,    6,    0,    0,    0,    0,    0,    0,
    0,  -54,    0,   17,   28,  -20,    0,    0,    0,  -11,
  -22,    0,   52,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   78,    0,    0,
  -53,    0,    0,   71,    0,    0,    0,   85,    0,    0,
    0,   87,    0,    0,    0,  -34,    0,   54,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,
};
static const YYINT yygindex[] = {                        13,
    0,   63,    0,    0,    0,  -50,   19,    7,   96,    0,
   32,    0,    0,   65,    0,    0,   18,    0,    1,    0,
    0,
};
#define YYTABLESIZE 373
static const YYINT yytable[] = {                         49,
   12,   14,   49,    3,    5,   36,   38,   71,   57,   42,
   65,   57,    2,   73,   74,  107,  108,   49,   28,   49,
   49,   17,   66,    1,   42,   93,   57,   18,   57,   30,
   21,   17,   15,   75,   25,   19,   28,   18,   49,   26,
   49,   22,   30,   31,   43,   46,   58,   30,   29,   58,
   50,   47,   51,   15,   45,   58,   48,   49,   53,   44,
   17,   54,   55,   62,   58,   67,   11,   84,   10,   78,
   70,   21,   77,   78,   27,   17,   82,   58,   18,   86,
   91,   94,   90,    5,   95,    6,   21,    5,   11,    6,
    7,   96,    8,    9,    7,   99,    8,    9,  100,  101,
  102,  103,  104,   92,  110,  105,  115,  118,  119,   10,
    7,   27,   40,  106,   19,   64,  117,   42,   49,  121,
  114,   49,    0,    0,    0,   65,   80,   35,    0,   19,
   85,    0,   87,   88,    0,    0,   49,    0,   49,    0,
    0,   27,    0,   65,    0,   35,   32,    0,    0,    0,
   27,    0,    0,    0,   33,   34,   35,   36,   37,   80,
    0,    0,    0,    0,  111,  112,  113,   88,    0,  116,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  120,    0,    0,  122,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   14,   14,   14,    3,    3,    5,   36,    0,    0,
    0,    0,    0,    0,   12,    0,   49,    0,   49,   49,
    0,    0,   49,   49,   49,   57,   49,   57,   57,    0,
    0,   57,   57,   57,    0,   57,   49,   28,   28,   49,
   49,   49,    0,   49,   49,   49,   49,   49,   30,   30,
    0,   68,   57,   30,   30,   57,    0,   49,    0,    0,
    0,   69,   49,   58,   49,   58,   58,   49,    0,   58,
   58,   58,    1,   30,    0,   17,   17,   17,   56,    0,
    0,   24,   57,    0,    4,    0,   21,   21,   21,    3,
   58,   25,    5,   58,    6,    4,   26,    0,    0,    7,
   56,    8,    9,    5,   57,    6,    4,    0,    0,    0,
    7,    3,    8,    9,    5,    0,    6,    4,   24,    0,
    0,    7,    0,    8,    9,    5,    0,    6,   25,   19,
   19,   19,    7,   26,    8,    9,   49,   49,   49,    0,
    0,    0,   49,   49,   65,   65,   35,   35,   24,   65,
   65,   35,   35,   23,    0,    0,    0,   24,   25,    0,
    0,    0,   49,   26,    0,    0,    0,   25,   72,   65,
    0,   35,   26,
};
static const YYINT yycheck[] = {                         41,
   44,   59,   44,   59,   59,   59,  123,   58,   41,   44,
  264,   44,    0,  265,  266,  281,  282,   59,   41,   61,
   41,   40,  276,  257,   59,   76,   59,   46,   61,   41,
  258,   40,    1,  285,  278,    4,   59,   46,   59,  283,
   61,   44,  263,   41,  263,  271,   41,   59,   17,   44,
   38,  271,  259,   22,   41,   40,  271,  271,   44,   28,
   44,  263,  125,  260,   59,  264,   40,  263,   42,  263,
   40,   44,  262,  263,   61,   59,  261,   40,   46,  263,
   41,  263,   70,  277,   44,  279,   59,  277,   40,  279,
  284,  263,  286,  287,  284,   59,  286,  287,  276,   61,
  265,   44,   41,   72,   44,   40,   59,   61,   41,  258,
   59,   61,   59,   95,   44,   53,  110,   22,   41,  119,
  103,   44,   -1,   -1,   -1,   41,   62,   41,   -1,   59,
   66,   -1,   68,   69,   -1,   -1,   59,   -1,   61,   -1,
   -1,   61,   -1,   59,   -1,   59,  263,   -1,   -1,   -1,
   61,   -1,   -1,   -1,  271,  272,  273,  274,  275,   95,
   -1,   -1,   -1,   -1,  100,  101,  102,  103,   -1,  105,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  118,   -1,   -1,  121,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  259,  260,  261,  260,  261,  261,  261,   -1,   -1,
   -1,   -1,   -1,   -1,  258,   -1,  258,   -1,  260,  261,
   -1,   -1,  264,  265,  266,  258,  268,  260,  261,   -1,
   -1,  264,  265,  266,   -1,  268,  278,  260,  261,  260,
  261,  283,   -1,  285,  265,  266,  288,  268,  260,  261,
   -1,  270,  285,  265,  266,  288,   -1,  278,   -1,   -1,
   -1,  280,  283,  258,  285,  260,  261,  288,   -1,  264,
  265,  266,  257,  285,   -1,  259,  260,  261,  263,   -1,
   -1,  268,  267,   -1,  269,   -1,  259,  260,  261,  263,
  285,  278,  277,  288,  279,  269,  283,   -1,   -1,  284,
  263,  286,  287,  277,  267,  279,  269,   -1,   -1,   -1,
  284,  263,  286,  287,  277,   -1,  279,  269,  268,   -1,
   -1,  284,   -1,  286,  287,  277,   -1,  279,  278,  259,
  260,  261,  284,  283,  286,  287,  259,  260,  261,   -1,
   -1,   -1,  265,  266,  260,  261,  260,  261,  268,  265,
  266,  265,  266,  264,   -1,   -1,   -1,  268,  278,   -1,
   -1,   -1,  285,  283,   -1,   -1,   -1,  278,  288,  285,
   -1,  285,  283,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 288
#define YYUNDFTOKEN 312
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'","'*'",0,"','",0,"'.'",0,0,0,0,0,0,0,0,0,0,0,0,"';'",0,
"'='",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,"SELECT","FROM","WHERE","GROUPBY","ORDERBY","HAVING","NAME","AS","AND","OR",
"EXISTS","OP","NOT","BETWEEN","JOIN","INNER","LEFT","RIGHT","FULL","ON",
"CONSTANT","SHIFT","BOOL","IN","ASC","DESC","COMPARISSON","DATE","ANDOP","ANY",
"ALL","LIKE",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : SelectBlock",
"SelectBlock : SELECT selectList FROM fromList WHERE_ GROUPBY_ ORDERBY_ ';'",
"WHERE_ : WHERE whereList",
"WHERE_ :",
"GROUPBY_ : GROUPBY groupbyList",
"GROUPBY_ :",
"ORDERBY_ : ORDERBY orderbyList",
"ORDERBY_ :",
"selectList : selectListN",
"selectList : '*'",
"selectListN : selectListNSub",
"selectListN : selectListNSub ',' selectListN",
"selectListNSub : Expr",
"selectListNSub : Expr AS NAME",
"fromList : subfromList",
"fromList : subfromList ',' fromList",
"subfromList : NAME",
"subfromList : Join NAME",
"subfromList : Join NAME ON Literal '=' Literal",
"subfromList : Join NAME AS NAME",
"subfromList : Join NAME AS NAME ON Literal '=' Literal",
"subfromList : '{' SelectBlock '}'",
"subfromList : '{' SelectBlock '}' AS NAME",
"Join : JOIN",
"Join : INNER JOIN",
"Join : LEFT JOIN",
"Join : RIGHT JOIN",
"Join : FULL JOIN",
"whereList : whereListSub",
"whereList : whereListSub OL whereList",
"whereListSub : Expr",
"whereListSub : '(' whereList ')'",
"whereListSub : NAME IN Inlist",
"whereListSub : NAME BETWEEN Literal AND Literal",
"whereListSub : EXISTS '(' SelectBlock ')' ';'",
"whereListSub : Expr LIKE Expr",
"groupbyList : groupbyListSub",
"groupbyList : groupbyListSub ',' groupbyList",
"groupbyListSub : HAVING NAME '(' Literal ')' BOP Literal",
"groupbyListSub : Literal",
"orderbyList : orderbyListSub",
"orderbyList : orderbyListSub ',' orderbyList",
"orderbyListSub : NAME",
"orderbyListSub : NAME order",
"order : ASC",
"order : DESC",
"OL : AND",
"OL : ANDOP",
"OL : OR",
"Literal : NAME",
"Literal : NAME '.' NAME",
"Literal : DATE",
"Literal : CONSTANT",
"Literal : BOOL",
"Literal : ANY",
"Literal : ALL",
"Expr : Literal",
"Expr : NOT Expr",
"Expr : Expr BOP Expr",
"Expr : NAME '(' Expr ')'",
"Expr : '(' SelectBlock ')'",
"BOP : COMPARISSON",
"BOP : SHIFT",
"BOP : OP",
"BOP : '='",
"Inlist : Literal",
"Inlist : Literal ',' Inlist",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 135 "SQLtoLADSL.y"
int main(int argc, char **argv){

    out = fopen("name.vm", "w");
    if (out == NULL){
        printf("Error opening file!\n");
        exit(1);
    }
    char codigo[1023*1024];
    fprintf(out, "start\n"); 
    yyparse();
    fprintf(out, "stop\n");
    
    fclose(out);
    return 0;
}
#line 396 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 22 "SQLtoLADSL.y"
	{ fprintf(out,"resultado\n"); }
break;
case 2:
#line 24 "SQLtoLADSL.y"
	{ ; }
break;
case 3:
#line 25 "SQLtoLADSL.y"
	{ ; }
break;
case 4:
#line 28 "SQLtoLADSL.y"
	{ ; }
break;
case 5:
#line 29 "SQLtoLADSL.y"
	{ ; }
break;
case 6:
#line 32 "SQLtoLADSL.y"
	{ ; }
break;
case 7:
#line 33 "SQLtoLADSL.y"
	{ ; }
break;
case 8:
#line 36 "SQLtoLADSL.y"
	{ ; }
break;
case 9:
#line 37 "SQLtoLADSL.y"
	{ ; }
break;
case 10:
#line 40 "SQLtoLADSL.y"
	{ ; }
break;
case 11:
#line 41 "SQLtoLADSL.y"
	{ ; }
break;
case 12:
#line 44 "SQLtoLADSL.y"
	{add_select(yystack.l_mark[0]); }
break;
case 13:
#line 45 "SQLtoLADSL.y"
	{add_select(yystack.l_mark[-2]);add_rename(yystack.l_mark[-2],yystack.l_mark[0],table); }
break;
case 14:
#line 48 "SQLtoLADSL.y"
	{ aux->sizetables++; }
break;
case 15:
#line 49 "SQLtoLADSL.y"
	{ aux->sizetables++; }
break;
case 16:
#line 52 "SQLtoLADSL.y"
	{ ; }
break;
case 17:
#line 53 "SQLtoLADSL.y"
	{ ; }
break;
case 18:
#line 54 "SQLtoLADSL.y"
	{yyval = add_key(yystack.l_mark[-4],yystack.l_mark[-2],yystack.l_mark[0]); }
break;
case 19:
#line 55 "SQLtoLADSL.y"
	{yyval = add_rename(yystack.l_mark[-2],yystack.l_mark[0]); }
break;
case 20:
#line 56 "SQLtoLADSL.y"
	{yyval = add_key(yystack.l_mark[-6],yystack.l_mark[-2],yystack.l_mark[0]);add_rename(yystack.l_mark[-6],yystack.l_mark[-4]); }
break;
case 21:
#line 57 "SQLtoLADSL.y"
	{yyval = from_select(yystack.l_mark[-1]); }
break;
case 22:
#line 58 "SQLtoLADSL.y"
	{yyval = from_select(yystack.l_mark[-3]); add_renameT(yystack.l_mark[-3],yystack.l_mark[0]); }
break;
case 23:
#line 61 "SQLtoLADSL.y"
	{ ; }
break;
case 24:
#line 62 "SQLtoLADSL.y"
	{ ; }
break;
case 25:
#line 63 "SQLtoLADSL.y"
	{ ; }
break;
case 26:
#line 64 "SQLtoLADSL.y"
	{ ; }
break;
case 27:
#line 65 "SQLtoLADSL.y"
	{ ; }
break;
case 28:
#line 68 "SQLtoLADSL.y"
	{yyval = yystack.l_mark[0] ; }
break;
case 29:
#line 69 "SQLtoLADSL.y"
	{opLogic(yystack.l_mark[-2],yystack.l_mark[-1],yystack.l_mark[0]); }
break;
case 30:
#line 72 "SQLtoLADSL.y"
	{add_Literalfilter(yystack.l_mark[0],table); }
break;
case 31:
#line 73 "SQLtoLADSL.y"
	{ ; }
break;
case 32:
#line 74 "SQLtoLADSL.y"
	{yyval = add_in(yystack.l_mark[-2],yystack.l_mark[0]); }
break;
case 33:
#line 75 "SQLtoLADSL.y"
	{yyval = add_filter(yystack.l_mark[-4],yystack.l_mark[-2],'>',table); add_filter(yystack.l_mark[-4],yystack.l_mark[0],'<',table); }
break;
case 34:
#line 76 "SQLtoLADSL.y"
	{ ; }
break;
case 35:
#line 77 "SQLtoLADSL.y"
	{ ; }
break;
case 36:
#line 80 "SQLtoLADSL.y"
	{yyval =yystack.l_mark[0]  ; }
break;
case 37:
#line 81 "SQLtoLADSL.y"
	{ ; }
break;
case 38:
#line 84 "SQLtoLADSL.y"
	{ ; }
break;
case 40:
#line 88 "SQLtoLADSL.y"
	{ ; }
break;
case 41:
#line 89 "SQLtoLADSL.y"
	{ ; }
break;
case 42:
#line 93 "SQLtoLADSL.y"
	{add_orderby(yystack.l_mark[0]); }
break;
case 43:
#line 94 "SQLtoLADSL.y"
	{add_orderby(yystack.l_mark[-1],yystack.l_mark[0]); }
break;
case 44:
#line 97 "SQLtoLADSL.y"
	{ yyval = yystack.l_mark[0]; }
break;
case 45:
#line 98 "SQLtoLADSL.y"
	{ yyval = yystack.l_mark[0]; }
break;
case 46:
#line 101 "SQLtoLADSL.y"
	{yyval = yystack.l_mark[0] ; }
break;
case 47:
#line 102 "SQLtoLADSL.y"
	{yyval = yystack.l_mark[0] ; }
break;
case 48:
#line 103 "SQLtoLADSL.y"
	{yyval = yystack.l_mark[0] ; }
break;
case 49:
#line 106 "SQLtoLADSL.y"
	{yyval = yystack.l_mark[0] ; }
break;
case 50:
#line 107 "SQLtoLADSL.y"
	{yyval = yystack.l_mark[0] ; table = yystack.l_mark[-2]; }
break;
case 51:
#line 108 "SQLtoLADSL.y"
	{yyval = yystack.l_mark[0] ; }
break;
case 52:
#line 109 "SQLtoLADSL.y"
	{yyval = yystack.l_mark[0] ; }
break;
case 53:
#line 110 "SQLtoLADSL.y"
	{yyval = yystack.l_mark[0] ; }
break;
case 54:
#line 111 "SQLtoLADSL.y"
	{yyval = yystack.l_mark[0] ; }
break;
case 55:
#line 112 "SQLtoLADSL.y"
	{yyval = yystack.l_mark[0] ; }
break;
case 56:
#line 116 "SQLtoLADSL.y"
	{yyval = yystack.l_mark[0] ; }
break;
case 57:
#line 117 "SQLtoLADSL.y"
	{yyval = not(yystack.l_mark[0]) ; }
break;
case 58:
#line 119 "SQLtoLADSL.y"
	{yyval = bop(yystack.l_mark[-2],yystack.l_mark[-1],yystack.l_mark[0]) ; }
break;
case 59:
#line 120 "SQLtoLADSL.y"
	{yyval = func(yystack.l_mark[-3],yystack.l_mark[-1]) ; }
break;
case 60:
#line 121 "SQLtoLADSL.y"
	{ ; }
break;
case 61:
#line 124 "SQLtoLADSL.y"
	{yyval = yystack.l_mark[0] ; }
break;
case 62:
#line 125 "SQLtoLADSL.y"
	{yyval = yystack.l_mark[0] ; }
break;
case 63:
#line 126 "SQLtoLADSL.y"
	{yyval = yystack.l_mark[0] ; }
break;
case 64:
#line 127 "SQLtoLADSL.y"
	{yyval = yystack.l_mark[0] ; }
break;
case 65:
#line 130 "SQLtoLADSL.y"
	{yyval = yystack.l_mark[0] ; }
break;
case 66:
#line 131 "SQLtoLADSL.y"
	{yyval = yystack.l_mark[-2] ; }
break;
#line 858 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
