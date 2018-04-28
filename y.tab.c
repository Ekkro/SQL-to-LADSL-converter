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
#define NOT 268
#define BETWEEN 269
#define JOIN 270
#define INNER 271
#define LEFT 272
#define RIGHT 273
#define FULL 274
#define ON 275
#define CONSTANT 276
#define BOOL 277
#define IN 278
#define ASC 279
#define DESC 280
#define DATE 281
#define ANDOP 282
#define ANY 283
#define ALL 284
#define LIKE 285
#define BOP 286
#define OP 287
#define COMPARISSON 288
#define SHIFT 289
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    3,    3,    4,    4,    5,    5,    1,    1,    9,
    9,   10,   10,    2,    2,   12,   12,   12,   12,   12,
   12,   12,   13,   13,   13,   13,   13,    6,    6,   15,
   15,   15,   15,   15,   15,    7,    7,   18,   18,    8,
    8,   19,   19,   20,   20,   16,   16,   16,   14,   14,
   14,   14,   14,   14,   14,   11,   11,   11,   11,   11,
   11,   17,   17,
};
static const YYINT yylen[] = {                            2,
    8,    2,    0,    2,    0,    2,    0,    1,    1,    1,
    3,    1,    3,    1,    3,    1,    2,    6,    4,    8,
    3,    5,    1,    2,    2,    2,    2,    1,    3,    1,
    3,    3,    5,    5,    3,    1,    3,    7,    1,    1,
    3,    1,    2,    1,    1,    1,    1,    1,    1,    3,
    1,    1,    1,    1,    1,    1,    2,    3,    3,    4,
    3,    1,    3,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    0,   52,   53,   51,   54,   55,    9,
    0,    0,    8,    0,    0,   56,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   50,   61,   16,   23,
    0,    0,    0,    0,    0,    0,    0,    0,   11,   13,
   58,    0,   60,   24,   25,   26,   27,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    2,    0,    0,    0,
    0,   15,    0,    0,    0,    0,    0,    0,    0,    0,
   46,   48,   47,    0,    0,    0,    4,   39,    0,    0,
    0,    0,    0,   22,    0,    0,   32,    0,   31,    0,
   29,    0,    0,    0,    6,    0,    1,    0,    0,    0,
    0,    0,    0,   37,   44,   45,   43,    0,    0,   18,
   33,   63,   34,    0,   41,    0,    0,   20,    0,   38,
};
static const YYINT yydgoto[] = {                         20,
   12,   36,   50,   61,   81,   57,   77,   95,   13,   14,
   58,   37,   38,   16,   59,   74,   87,   79,   96,  107,
};
static const YYINT yysindex[] = {                      -233,
   19,    0,  -12,   41,    0,    0,    0,    0,    0,    0,
 -233, -226,    0,   -8,  -56,    0,   41, -241, -248,    4,
 -117,   41, -217,   41,   41,  -40,    0,    0,    0,    0,
 -223, -219, -216, -215, -233, -199,   18, -200,    0,    0,
    0,  -52,    0,    0,    0,    0,    0,  -59,   31, -192,
 -117, -235, -194,  -36,   32,    9,    0,  -50, -251, -198,
 -181,    0, -190, -188, -179, -188, -188, -233,   46,   41,
    0,    0,    0,   31, -173,   36,    0,    0,   48, -169,
   38, -177,   39,    0, -166,   57,    0,   61,    0,  -52,
    0,   63, -198, -236,    0,   62,    0, -188, -188, -188,
 -188,   50, -188,    0,    0,    0,    0, -169,   44,    0,
    0,    0,    0,   66,    0, -188, -176,    0, -188,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,  -41,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -146,  -42,    0,    0,    0,  -11,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -51,  -47,    0,    0,    0,
    0,   -2,    0,    0,    0,    0,    0,    0,    0,  -46,
    0,    8,   60,  -34,    0,    0,    0,   74,  -22,    0,
   54,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   67,    0,    0,  -43,    0,
    0,   70,    0,    0,    0,   76,    0,    0,    0,   86,
    0,    0,    0,  -18,    0,   59,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                        23,
    0,   65,    0,    0,    0,  -39,   27,   13,  101,    0,
   52,    0,    0,   72,    0,    0,   24,    0,    0,    0,
};
#define YYTABLESIZE 368
static const YYINT yytable[] = {                         49,
   43,   12,   49,   17,   25,   35,   49,    3,   25,   18,
   25,   14,    5,   71,   72,   36,   69,   49,   28,   49,
   25,   27,    2,    1,   49,   42,   49,   17,   63,   57,
   73,   21,   57,   18,   91,   22,   28,   24,   59,   64,
   42,   59,  105,  106,   28,   40,   44,   57,   56,   57,
   45,   17,   15,   46,   47,   19,   59,   48,   11,   49,
   10,   51,   52,   75,   76,   53,   17,   60,   26,   65,
   56,   68,   82,   15,   76,   41,   42,    5,    6,   80,
   11,   18,    7,   84,    8,    9,   89,    5,    6,   92,
   88,   93,    7,   94,    8,    9,   97,   98,  100,   99,
  101,  102,  103,   21,  116,  108,  117,   49,  113,  119,
   49,   10,    7,   19,   30,   62,   62,   40,   21,  104,
  115,   90,   39,    0,  112,   49,   35,   49,   19,    0,
    0,   78,   30,    0,   62,   83,    0,   85,   86,    0,
    0,    0,    0,    0,   35,   29,    0,    0,    0,    0,
    0,    0,   30,   31,   32,   33,   34,    0,    0,    0,
    0,    0,    0,    0,   78,    0,    0,    0,    0,  109,
  110,  111,   86,    0,  114,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  118,    0,    0,
  120,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   23,    3,    3,
    0,   14,   14,   14,    5,   12,   49,   36,   49,   49,
    0,    0,   49,   49,   49,   49,   49,    0,    0,   24,
   49,   49,   66,   24,   70,   24,    0,   28,   28,    0,
   49,   67,    0,   49,   49,   24,   57,   49,   57,   57,
   49,   49,   57,   57,   57,   59,    0,   59,   59,    0,
    0,   59,   59,   59,    0,    1,   17,   17,   17,    0,
   57,   54,    0,   57,    0,   55,    4,    0,    0,   59,
    0,    3,   59,    0,    5,    6,    4,    0,    0,    7,
    0,    8,    9,   54,    5,    6,    0,   55,    4,    7,
    0,    8,    9,    3,    0,    0,    5,    6,    4,    0,
    0,    7,    0,    8,    9,    0,    5,    6,   21,   21,
   21,    7,    0,    8,    9,   49,   49,   49,   19,   19,
   19,   49,   49,   30,   30,   62,   62,    0,   30,   30,
   62,   62,    0,    0,    0,   35,   35,    0,   49,    0,
   35,   35,    0,    0,    0,   30,    0,   62,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   35,
};
static const YYINT yycheck[] = {                         41,
   41,   44,   44,   40,   61,  123,   41,   59,   61,   46,
   61,   59,   59,  265,  266,   59,   56,   59,   41,   61,
   61,  263,    0,  257,   59,   44,   61,   40,  264,   41,
  282,  258,   44,   46,   74,   44,   59,  286,   41,  275,
   59,   44,  279,  280,   41,  263,  270,   59,   40,   61,
  270,   44,    1,  270,  270,    4,   59,   35,   40,  259,
   42,   44,  263,  262,  263,  125,   59,  260,   17,  264,
   40,   40,  263,   22,  263,   24,   25,  276,  277,  261,
   40,   46,  281,  263,  283,  284,   41,  276,  277,  263,
   68,   44,  281,  263,  283,  284,   59,  275,  265,   61,
   44,   41,   40,   44,   61,   44,   41,   41,   59,  286,
   44,  258,   59,   44,   41,   51,   41,   59,   59,   93,
  108,   70,   22,   -1,  101,   59,   41,   61,   59,   -1,
   -1,   60,   59,   -1,   59,   64,   -1,   66,   67,   -1,
   -1,   -1,   -1,   -1,   59,  263,   -1,   -1,   -1,   -1,
   -1,   -1,  270,  271,  272,  273,  274,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   93,   -1,   -1,   -1,   -1,   98,
   99,  100,  101,   -1,  103,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  116,   -1,   -1,
  119,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  264,  260,  261,
   -1,  259,  260,  261,  261,  258,  258,  261,  260,  261,
   -1,   -1,  264,  265,  266,  260,  261,   -1,   -1,  286,
  265,  266,  269,  286,  285,  286,   -1,  260,  261,   -1,
  282,  278,   -1,  285,  286,  286,  258,  282,  260,  261,
  285,  286,  264,  265,  266,  258,   -1,  260,  261,   -1,
   -1,  264,  265,  266,   -1,  257,  259,  260,  261,   -1,
  282,  263,   -1,  285,   -1,  267,  268,   -1,   -1,  282,
   -1,  263,  285,   -1,  276,  277,  268,   -1,   -1,  281,
   -1,  283,  284,  263,  276,  277,   -1,  267,  268,  281,
   -1,  283,  284,  263,   -1,   -1,  276,  277,  268,   -1,
   -1,  281,   -1,  283,  284,   -1,  276,  277,  259,  260,
  261,  281,   -1,  283,  284,  259,  260,  261,  259,  260,
  261,  265,  266,  260,  261,  260,  261,   -1,  265,  266,
  265,  266,   -1,   -1,   -1,  260,  261,   -1,  282,   -1,
  265,  266,   -1,   -1,   -1,  282,   -1,  282,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  282,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 289
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
"EXISTS","NOT","BETWEEN","JOIN","INNER","LEFT","RIGHT","FULL","ON","CONSTANT",
"BOOL","IN","ASC","DESC","DATE","ANDOP","ANY","ALL","LIKE","BOP","OP",
"COMPARISSON","SHIFT",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"illegal-symbol",
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
"Expr : Expr '=' Expr",
"Expr : NAME '(' Expr ')'",
"Expr : '(' SelectBlock ')'",
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
#line 136 "SQLtoLADSL.y"
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
#line 388 "y.tab.c"

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
#line 23 "SQLtoLADSL.y"
	{ fprintf(out,"resultado\n"); }
break;
case 2:
#line 25 "SQLtoLADSL.y"
	{ ; }
break;
case 3:
#line 26 "SQLtoLADSL.y"
	{ ; }
break;
case 4:
#line 29 "SQLtoLADSL.y"
	{ ; }
break;
case 5:
#line 30 "SQLtoLADSL.y"
	{ ; }
break;
case 6:
#line 33 "SQLtoLADSL.y"
	{ ; }
break;
case 7:
#line 34 "SQLtoLADSL.y"
	{ ; }
break;
case 8:
#line 37 "SQLtoLADSL.y"
	{ ; }
break;
case 9:
#line 38 "SQLtoLADSL.y"
	{ ; }
break;
case 10:
#line 41 "SQLtoLADSL.y"
	{ ; }
break;
case 11:
#line 42 "SQLtoLADSL.y"
	{ ; }
break;
case 12:
#line 45 "SQLtoLADSL.y"
	{add_select(yystack.l_mark[0]); }
break;
case 13:
#line 46 "SQLtoLADSL.y"
	{add_select(yystack.l_mark[-2]);add_rename(yystack.l_mark[-2],yystack.l_mark[0],table); }
break;
case 14:
#line 49 "SQLtoLADSL.y"
	{ aux->sizetables++; }
break;
case 15:
#line 50 "SQLtoLADSL.y"
	{ aux->sizetables++; }
break;
case 16:
#line 53 "SQLtoLADSL.y"
	{ ; }
break;
case 17:
#line 54 "SQLtoLADSL.y"
	{ ; }
break;
case 18:
#line 55 "SQLtoLADSL.y"
	{yyval = add_key(yystack.l_mark[-4],yystack.l_mark[-2],yystack.l_mark[0]); }
break;
case 19:
#line 56 "SQLtoLADSL.y"
	{yyval = add_rename(yystack.l_mark[-2],yystack.l_mark[0]); }
break;
case 20:
#line 57 "SQLtoLADSL.y"
	{yyval = add_key(yystack.l_mark[-6],yystack.l_mark[-2],yystack.l_mark[0]);add_rename(yystack.l_mark[-6],yystack.l_mark[-4]); }
break;
case 21:
#line 58 "SQLtoLADSL.y"
	{yyval = from_select(yystack.l_mark[-1]); }
break;
case 22:
#line 59 "SQLtoLADSL.y"
	{yyval = from_select(yystack.l_mark[-3]); add_renameT(yystack.l_mark[-3],yystack.l_mark[0]); }
break;
case 23:
#line 62 "SQLtoLADSL.y"
	{ ; }
break;
case 24:
#line 63 "SQLtoLADSL.y"
	{ ; }
break;
case 25:
#line 64 "SQLtoLADSL.y"
	{ ; }
break;
case 26:
#line 65 "SQLtoLADSL.y"
	{ ; }
break;
case 27:
#line 66 "SQLtoLADSL.y"
	{ ; }
break;
case 28:
#line 69 "SQLtoLADSL.y"
	{yyval = yystack.l_mark[0] ; }
break;
case 29:
#line 70 "SQLtoLADSL.y"
	{opLogic(yystack.l_mark[-2],yystack.l_mark[-1],yystack.l_mark[0]); }
break;
case 30:
#line 73 "SQLtoLADSL.y"
	{add_Literalfilter(yystack.l_mark[0],table); }
break;
case 31:
#line 74 "SQLtoLADSL.y"
	{ ; }
break;
case 32:
#line 75 "SQLtoLADSL.y"
	{yyval = add_in(yystack.l_mark[-2],yystack.l_mark[0]); }
break;
case 33:
#line 76 "SQLtoLADSL.y"
	{yyval = add_filter(yystack.l_mark[-4],yystack.l_mark[-2],'>',table); add_filter(yystack.l_mark[-4],yystack.l_mark[0],'<',table); }
break;
case 34:
#line 77 "SQLtoLADSL.y"
	{ ; }
break;
case 35:
#line 78 "SQLtoLADSL.y"
	{ ; }
break;
case 36:
#line 81 "SQLtoLADSL.y"
	{yyval =yystack.l_mark[0]  ; }
break;
case 37:
#line 82 "SQLtoLADSL.y"
	{ ; }
break;
case 38:
#line 85 "SQLtoLADSL.y"
	{ ; }
break;
case 40:
#line 89 "SQLtoLADSL.y"
	{ ; }
break;
case 41:
#line 90 "SQLtoLADSL.y"
	{ ; }
break;
case 42:
#line 94 "SQLtoLADSL.y"
	{add_orderby(yystack.l_mark[0]); }
break;
case 43:
#line 95 "SQLtoLADSL.y"
	{add_orderby(yystack.l_mark[-1],yystack.l_mark[0]); }
break;
case 44:
#line 98 "SQLtoLADSL.y"
	{ yyval = yystack.l_mark[0]; }
break;
case 45:
#line 99 "SQLtoLADSL.y"
	{ yyval = yystack.l_mark[0]; }
break;
case 46:
#line 102 "SQLtoLADSL.y"
	{yyval = yystack.l_mark[0] ; }
break;
case 47:
#line 103 "SQLtoLADSL.y"
	{yyval = yystack.l_mark[0] ; }
break;
case 48:
#line 104 "SQLtoLADSL.y"
	{yyval = yystack.l_mark[0] ; }
break;
case 49:
#line 107 "SQLtoLADSL.y"
	{yyval = yystack.l_mark[0] ; }
break;
case 50:
#line 108 "SQLtoLADSL.y"
	{yyval = yystack.l_mark[0] ; table = yystack.l_mark[-2]; }
break;
case 51:
#line 109 "SQLtoLADSL.y"
	{yyval = yystack.l_mark[0] ; }
break;
case 52:
#line 110 "SQLtoLADSL.y"
	{yyval = yystack.l_mark[0] ; }
break;
case 53:
#line 111 "SQLtoLADSL.y"
	{yyval = yystack.l_mark[0] ; }
break;
case 54:
#line 112 "SQLtoLADSL.y"
	{yyval = yystack.l_mark[0] ; }
break;
case 55:
#line 113 "SQLtoLADSL.y"
	{yyval = yystack.l_mark[0] ; }
break;
case 56:
#line 117 "SQLtoLADSL.y"
	{yyval = yystack.l_mark[0] ; }
break;
case 57:
#line 118 "SQLtoLADSL.y"
	{yyval = not(yystack.l_mark[0]) ; }
break;
case 58:
#line 119 "SQLtoLADSL.y"
	{yyval = bop(yystack.l_mark[-2],yystack.l_mark[-1],yystack.l_mark[0]) ; }
break;
case 59:
#line 120 "SQLtoLADSL.y"
	{yyval = add_key(yystack.l_mark[-2],yystack.l_mark[-1],yystack.l_mark[0]) ; }
break;
case 60:
#line 121 "SQLtoLADSL.y"
	{yyval = func(yystack.l_mark[-3],yystack.l_mark[-1]) ; }
break;
case 61:
#line 122 "SQLtoLADSL.y"
	{ ; }
break;
case 62:
#line 131 "SQLtoLADSL.y"
	{yyval = yystack.l_mark[0] ; }
break;
case 63:
#line 132 "SQLtoLADSL.y"
	{yyval = yystack.l_mark[-2] ; }
break;
#line 838 "y.tab.c"
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
