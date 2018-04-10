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

 /* Declaracoes C diversas */                                          
                                                                   
                                                                       

int flag1 = 0;
int counter = 0;
FILE* out;

void join (int flag, char* atributo1, char* atributo2){
    switch(flag){
        case 1:
               fprintf(out, "filter( %s = %s)\n",atributo1,atributo2);
               break;
        case 2:
              fprintf(out, "filter( %s != NULL)\n",atributo1);
              break;
        case 3:
              fprintf(out, "filter( %s != NULL)\n",atributo2);
              break;
        default:
              fprintf(out, "");
      }
}


#line 51 "y.tab.c"

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
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    2,    5,    7,    9,   10,    0,    4,    4,    6,    6,
    8,    8,    1,    1,   14,   14,    3,    3,   16,   16,
   16,   16,   16,   16,   16,   18,   18,   18,   18,   18,
   11,   11,   19,   19,   19,   12,   12,   21,   21,   13,
   13,   13,   13,   23,   23,   20,   20,   20,   17,   17,
   17,   17,   15,   15,   15,   15,   15,   15,   22,   22,
   22,   22,   24,   24,
};
static const YYINT yylen[] = {                            2,
    0,    0,    0,    0,    0,   13,    2,    0,    2,    0,
    2,    0,    1,    1,    1,    3,    1,    3,    1,    2,
    6,    4,    8,    3,    5,    1,    2,    2,    2,    2,
    1,    3,    1,    5,    5,    1,    3,    1,    7,    1,
    2,    3,    4,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    2,    3,    4,    3,    3,    1,    1,
    1,    1,    1,    3,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    0,   51,   52,   50,   14,    1,   13,
    0,   53,    0,    0,    0,    0,   59,    0,   62,   61,
   60,    0,    0,   49,    0,   58,    0,    0,   57,   16,
    0,    0,   56,   26,    0,    0,    0,    0,    0,    2,
    0,   19,    0,   64,   27,   28,   29,   30,    0,    0,
    0,    0,    0,    0,    3,   18,    0,    0,    0,    0,
    7,    0,    0,    0,    0,    0,    0,   25,    0,    0,
   46,   48,   47,    0,    0,    4,    0,    0,    0,    0,
   32,    0,    9,   38,    0,    0,    0,   21,    0,    0,
    0,    0,    0,    5,    0,   35,   34,    0,   37,    0,
   11,    0,    0,   23,    0,   44,   45,    0,    0,    6,
    0,   42,    0,    0,   43,   39,
};
static const YYINT yydgoto[] = {                          2,
    9,   16,   40,   55,   50,   76,   65,   94,   86,  103,
   61,   83,  101,   10,   11,   41,   12,   43,   64,   74,
   85,   23,  109,   26,
};
static const YYINT yysindex[] = {                      -237,
   -5,    0,  -39, -225,    0,    0,    0,    0,    0,    0,
    5,    0, -188, -225, -161, -232,    0, -236,    0,    0,
    0, -225, -225,    0,  -16,    0,  -18, -118,    0,    0,
 -161, -188,    0,    0, -235, -228, -220, -216, -237,    0,
   14,    0, -197,    0,    0,    0,    0,    0,  -57, -189,
 -118, -257, -190, -206,    0,    0, -182, -178, -176,   53,
    0, -161, -171, -218, -163, -168,   44,    0, -237, -188,
    0,    0,    0, -206, -238,    0, -154, -151,   72, -147,
    0, -149,    0,    0,   75, -141,   60,    0,   64, -188,
   84, -238, -173,    0, -138,    0,    0, -188,    0,    0,
    0,  -11,   67,    0,   86,    0,    0, -173,   85,    0,
 -199,    0, -173, -188,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,  -41,    0,    0,    0,    0,    0,    0,    0,
 -130,    0,    0,    0,   -9,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -30,    0,    0,    0,    0,    0,
    1,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  -55,    0,    0,    0,    0,    0,    0,    0,    0,  -51,
    0,   21,   39,    0,    0,    0,    0,    0,    0,    0,
    0,  -53,   29,  -46,  -50,   42,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -45,   71,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  -42,
    0,    0,    0,    0,    0,    0,    0,    0,   73,    0,
    0,    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                       -29,
    0,    0,   80,    0,    0,    0,    0,    0,    0,    0,
   59,   43,  -92,  112,    8,    0,    2,    0,    0,    0,
    0,   25,    0,  105,
};
#define YYTABLESIZE 314
static const YYINT yytable[] = {                         49,
   14,   49,   49,   17,   39,   33,   57,    8,   10,   49,
   63,   15,   31,   36,   25,  112,   40,   49,   58,    1,
  115,   27,   33,   82,   24,   28,   29,   32,   63,   42,
   31,   54,  108,   25,   54,   45,    8,    3,    5,   79,
    6,   55,   46,    4,   55,    7,   71,   72,   22,   54,
   47,    5,   42,    6,   48,   63,    3,   51,    7,   55,
   60,   62,    4,   17,   20,   52,   73,   53,   19,   54,
    5,   80,    6,   59,   24,   63,   84,    7,   20,   20,
   66,   62,   24,   21,   67,   22,   68,   53,    5,  100,
    6,   97,   69,   84,  102,    7,   75,   24,   70,  105,
   22,   17,   18,    5,   78,    6,   19,   77,   87,  102,
    7,   88,   89,   91,  102,  116,   20,   90,   92,   93,
   95,   21,   96,   98,  104,  110,  111,   15,  113,   12,
   56,   41,   81,   30,   99,  114,   44,    0,    0,    0,
    0,    0,    0,    0,   24,    0,    0,    0,    0,    0,
    0,    0,   34,   35,   36,   37,   38,    0,    5,    0,
    6,    0,    0,    0,    0,    7,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   17,   17,   17,   33,   33,    8,    8,
   10,   33,   33,   31,   31,   36,   49,    0,   49,   49,
    0,   49,   49,   49,   49,    0,   49,   63,   49,   63,
   63,   33,   63,   63,   63,   63,   49,   63,   49,   49,
   13,   49,    0,   49,   17,   18,    0,   63,   54,   19,
   54,   54,   63,    0,   63,   54,   54,    3,   55,   20,
   55,   55,    0,    4,   21,   55,   55,   17,   18,  106,
  107,    5,   19,    6,    0,   54,    0,    0,    7,   20,
   20,   20,   20,    0,    0,   55,    0,   21,   53,   53,
    0,   53,   53,   53,   53,    0,   53,   24,   24,   24,
   22,   22,   22,    0,    0,    0,   53,    0,    0,    0,
    0,   53,    0,   53,
};
static const YYINT yycheck[] = {                         41,
   40,   44,   44,   59,  123,   59,  264,   59,   59,   39,
   41,    4,   59,   59,   13,  108,   59,   59,  276,  257,
  113,   14,   41,  262,  263,  258,  263,   44,   59,   28,
   23,   41,   44,   32,   44,  271,   42,  263,  277,   69,
  279,   41,  271,  269,   44,  284,  265,  266,   44,   59,
  271,  277,   51,  279,  271,   54,  263,   44,  284,   59,
  267,   54,  269,  263,   44,  263,  285,  125,  268,  259,
  277,   70,  279,  264,  263,   74,   75,  284,  278,   59,
  263,   74,   44,  283,  263,   44,  263,   59,  277,  263,
  279,   90,   40,   92,   93,  284,  260,   59,  270,   98,
   59,  263,  264,  277,   61,  279,  268,  276,  263,  108,
  284,  263,   41,  263,  113,  114,  278,  265,   44,  261,
   61,  283,   59,   40,  263,   59,   41,  258,   44,   59,
   51,   59,   74,   22,   92,  111,   32,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  263,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  271,  272,  273,  274,  275,   -1,  277,   -1,
  279,   -1,   -1,   -1,   -1,  284,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  259,  260,  261,  260,  261,  260,  261,
  261,  265,  266,  260,  261,  261,  258,   -1,  260,  261,
   -1,  263,  264,  265,  266,   -1,  268,  258,  270,  260,
  261,  285,  263,  264,  265,  266,  278,  268,  281,  282,
  280,  283,   -1,  285,  263,  264,   -1,  278,  258,  268,
  260,  261,  283,   -1,  285,  265,  266,  263,  258,  278,
  260,  261,   -1,  269,  283,  265,  266,  263,  264,  281,
  282,  277,  268,  279,   -1,  285,   -1,   -1,  284,  259,
  260,  261,  278,   -1,   -1,  285,   -1,  283,  260,  261,
   -1,  263,  264,  265,  266,   -1,  268,  259,  260,  261,
  259,  260,  261,   -1,   -1,   -1,  278,   -1,   -1,   -1,
   -1,  283,   -1,  285,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 285
#define YYUNDFTOKEN 312
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'","'*'",0,"','",0,0,0,0,0,0,0,0,0,0,0,0,0,0,"';'",0,"'='",
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"SELECT","FROM","WHERE","GROUPBY","ORDERBY","HAVING","NAME","AS","AND","OR",
"EXISTS","OP","NOT","BETWEEN","JOIN","INNER","LEFT","RIGHT","FULL","ON",
"CONSTANT","SHIFT","BOOL","IN","ASC","DESC","COMPARISSON","DATE","ANDOP",0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : SelectBlock",
"$$1 :",
"$$2 :",
"$$3 :",
"$$4 :",
"$$5 :",
"SelectBlock : SELECT selectList $$1 FROM fromList $$2 WHERE_ $$3 GROUPBY_ $$4 ORDERBY_ $$5 ';'",
"WHERE_ : WHERE whereList",
"WHERE_ :",
"GROUPBY_ : GROUPBY groupbyList",
"GROUPBY_ :",
"ORDERBY_ : ORDERBY orderbyList",
"ORDERBY_ :",
"selectList : selectListN",
"selectList : '*'",
"selectListN : COMPLEX",
"selectListN : COMPLEX ',' selectListN",
"fromList : subfromList",
"fromList : subfromList ',' fromList",
"subfromList : SIMPLE",
"subfromList : Join NAME",
"subfromList : Join NAME ON NAME '=' NAME",
"subfromList : Join NAME AS NAME",
"subfromList : Join NAME AS NAME ON NAME '=' NAME",
"subfromList : '{' SelectBlock '}'",
"subfromList : '{' SelectBlock '}' AS NAME",
"Join : JOIN",
"Join : INNER JOIN",
"Join : LEFT JOIN",
"Join : RIGHT JOIN",
"Join : FULL JOIN",
"whereList : whereListSub",
"whereList : whereListSub OL whereList",
"whereListSub : COMPLEX",
"whereListSub : SIMPLE BETWEEN SIMPLE AND SIMPLE",
"whereListSub : EXISTS '(' SelectBlock ')' ';'",
"groupbyList : groupbyListSub",
"groupbyList : groupbyListSub ',' groupbyList",
"groupbyListSub : SIMPLE",
"groupbyListSub : HAVING NAME '(' SIMPLE ')' BOP SIMPLE",
"orderbyList : NAME",
"orderbyList : SIMPLE order",
"orderbyList : SIMPLE ',' orderbyList",
"orderbyList : SIMPLE order ',' orderbyList",
"order : ASC",
"order : DESC",
"OL : AND",
"OL : ANDOP",
"OL : OR",
"SIMPLE : NAME",
"SIMPLE : DATE",
"SIMPLE : CONSTANT",
"SIMPLE : BOOL",
"COMPLEX : SIMPLE",
"COMPLEX : NOT COMPLEX",
"COMPLEX : COMPLEX BOP COMPLEX",
"COMPLEX : NAME '(' COMPLEX ')'",
"COMPLEX : COMPLEX AS NAME",
"COMPLEX : NAME IN Inlist",
"BOP : NAME",
"BOP : COMPARISSON",
"BOP : SHIFT",
"BOP : OP",
"Inlist : SIMPLE",
"Inlist : SIMPLE ',' Inlist",

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
#line 146 "SQLtoLADSL.y"
int main(int argc, char **argv){

    out = fopen("name.vm", "w");
    if (out == NULL){
        printf("Error opening file!\n");
        exit(1);
    }
    //char codigo[1023*1024];
    fprintf(out, "start\n"); 
    yyparse();
    fprintf(out, "stop\n");
    
    fclose(out);
    return 0;
}
#line 401 "y.tab.c"

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
#line 36 "SQLtoLADSL.y"
	{ fprintf(out, "{\n");; }
break;
case 2:
#line 37 "SQLtoLADSL.y"
	{ ; }
break;
case 3:
#line 38 "SQLtoLADSL.y"
	{ ; }
break;
case 4:
#line 39 "SQLtoLADSL.y"
	{ ; }
break;
case 5:
#line 40 "SQLtoLADSL.y"
	{ ; }
break;
case 6:
#line 41 "SQLtoLADSL.y"
	{ fprintf(out, "}\n");}
break;
case 7:
#line 43 "SQLtoLADSL.y"
	{ ; }
break;
case 8:
#line 44 "SQLtoLADSL.y"
	{ ; }
break;
case 9:
#line 47 "SQLtoLADSL.y"
	{ ; }
break;
case 10:
#line 48 "SQLtoLADSL.y"
	{ ; }
break;
case 11:
#line 51 "SQLtoLADSL.y"
	{ ; }
break;
case 12:
#line 52 "SQLtoLADSL.y"
	{ ; }
break;
case 13:
#line 55 "SQLtoLADSL.y"
	{ fprintf(out, "SELECT("); }
break;
case 14:
#line 56 "SQLtoLADSL.y"
	{ fprintf(out, "SELECT *\n"); }
break;
case 15:
#line 59 "SQLtoLADSL.y"
	{ fprintf(out, ")\n"); }
break;
case 16:
#line 60 "SQLtoLADSL.y"
	{ ; }
break;
case 17:
#line 63 "SQLtoLADSL.y"
	{ ; }
break;
case 18:
#line 64 "SQLtoLADSL.y"
	{ ; }
break;
case 19:
#line 67 "SQLtoLADSL.y"
	{ ; }
break;
case 20:
#line 68 "SQLtoLADSL.y"
	{ ; }
break;
case 21:
#line 69 "SQLtoLADSL.y"
	{ join(flag1,yystack.l_mark[-2],yystack.l_mark[0]);}
break;
case 22:
#line 70 "SQLtoLADSL.y"
	{ fprintf(out, "change( %s , %s)\n",yystack.l_mark[-2],yystack.l_mark[0]); }
break;
case 23:
#line 71 "SQLtoLADSL.y"
	{ fprintf(out, "change( %s , %s)\n",yystack.l_mark[-6],yystack.l_mark[-4]); join(flag1,yystack.l_mark[-2],yystack.l_mark[0]); }
break;
case 24:
#line 72 "SQLtoLADSL.y"
	{ fprintf(out, "{\n"); }
break;
case 25:
#line 73 "SQLtoLADSL.y"
	{ ; }
break;
case 26:
#line 76 "SQLtoLADSL.y"
	{ flag1 = 1; }
break;
case 27:
#line 77 "SQLtoLADSL.y"
	{ flag1 = 1; }
break;
case 28:
#line 78 "SQLtoLADSL.y"
	{ flag1 = 2; }
break;
case 29:
#line 79 "SQLtoLADSL.y"
	{ flag1 = 3; }
break;
case 30:
#line 80 "SQLtoLADSL.y"
	{ flag1 = 0; }
break;
case 31:
#line 84 "SQLtoLADSL.y"
	{ ; }
break;
case 32:
#line 85 "SQLtoLADSL.y"
	{ ; }
break;
case 33:
#line 88 "SQLtoLADSL.y"
	{ ; }
break;
case 34:
#line 89 "SQLtoLADSL.y"
	{ fprintf(out, "filter( %s > %s)\nfilter(%s < %s)\n",yystack.l_mark[-4],yystack.l_mark[-2],yystack.l_mark[-4],$); }
break;
case 35:
#line 90 "SQLtoLADSL.y"
	{ ; }
break;
case 36:
#line 93 "SQLtoLADSL.y"
	{ ; }
break;
case 37:
#line 94 "SQLtoLADSL.y"
	{ ; }
break;
case 38:
#line 97 "SQLtoLADSL.y"
	{ fprintf(out, "group( %s)\n",yystack.l_mark[0]); }
break;
case 39:
#line 98 "SQLtoLADSL.y"
	{ fprintf(out, "filter( %s '(' %s ')' %s %s)\n",yystack.l_mark[-5],yystack.l_mark[-3],yystack.l_mark[-1],yystack.l_mark[0]); }
break;
case 40:
#line 101 "SQLtoLADSL.y"
	{ ; }
break;
case 41:
#line 102 "SQLtoLADSL.y"
	{ ; }
break;
case 42:
#line 103 "SQLtoLADSL.y"
	{ ; }
break;
case 43:
#line 104 "SQLtoLADSL.y"
	{ ; }
break;
case 44:
#line 107 "SQLtoLADSL.y"
	{ ; }
break;
case 45:
#line 108 "SQLtoLADSL.y"
	{ ; }
break;
case 46:
#line 112 "SQLtoLADSL.y"
	{ fprintf(out, "&"); }
break;
case 47:
#line 113 "SQLtoLADSL.y"
	{ fprintf(out, "&"); }
break;
case 48:
#line 114 "SQLtoLADSL.y"
	{ fprintf(out, "|"); }
break;
case 49:
#line 117 "SQLtoLADSL.y"
	{ ; }
break;
case 50:
#line 118 "SQLtoLADSL.y"
	{ ; }
break;
case 51:
#line 119 "SQLtoLADSL.y"
	{ ; }
break;
case 52:
#line 120 "SQLtoLADSL.y"
	{ ; }
break;
case 53:
#line 124 "SQLtoLADSL.y"
	{ fprintf(out, "%s",yystack.l_mark[0]); while(counter>0){
                                                                                                            fprintf(out, ")");
                                                                                                            counter--;}
                                                                                                            fprintf(out, "\n");}
break;
case 54:
#line 128 "SQLtoLADSL.y"
	{ fprintf(out, "NOT"); }
break;
case 55:
#line 129 "SQLtoLADSL.y"
	{ fprintf(out, "%s",yystack.l_mark[-1]); }
break;
case 56:
#line 130 "SQLtoLADSL.y"
	{ fprintf(out, "%s(",yystack.l_mark[-3]); counter++; }
break;
case 57:
#line 131 "SQLtoLADSL.y"
	{ fprintf(out, "change(%s)",yystack.l_mark[0]); }
break;
case 58:
#line 132 "SQLtoLADSL.y"
	{ fprintf(out, "IN(%s,",yystack.l_mark[-2]); }
break;
case 59:
#line 135 "SQLtoLADSL.y"
	{ fprintf(out, "%s(",yystack.l_mark[0]); counter++; }
break;
case 60:
#line 136 "SQLtoLADSL.y"
	{ fprintf(out, "%s",yystack.l_mark[0]); }
break;
case 61:
#line 137 "SQLtoLADSL.y"
	{ fprintf(out, "%s",yystack.l_mark[0]); }
break;
case 62:
#line 138 "SQLtoLADSL.y"
	{ fprintf(out, "%s",yystack.l_mark[0]); }
break;
case 63:
#line 141 "SQLtoLADSL.y"
	{ fprintf(out, "%s)\n",yystack.l_mark[0]); }
break;
case 64:
#line 142 "SQLtoLADSL.y"
	{ fprintf(out, "%s, ",yystack.l_mark[-2]); }
break;
#line 862 "y.tab.c"
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
