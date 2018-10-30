/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "SQLtoLADSL.y" /* yacc.c:339  */


 #include "SQLtoLADSL.hpp"

 int yylex(void);
 void yyerror(const char* s);

string a = "";
Graph mainGraph;
Graph g;
Ltree l;
vector<Ltree> trees;
int itr = 0;
vector<par> types;
int itr2 = 0;



#line 85 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    SELECT = 258,
    WHERE = 259,
    GROUPBY = 260,
    ORDERBY = 261,
    HAVING = 262,
    AS = 263,
    AND = 264,
    OR = 265,
    EXISTS = 266,
    BETWEEN = 267,
    JOIN = 268,
    INNER = 269,
    LEFT = 270,
    RIGHT = 271,
    FULL = 272,
    ON = 273,
    IN = 274,
    ANDOP = 275,
    BEFORE = 276,
    IS = 277,
    END = 278,
    INTERVAL = 279,
    LIKE = 280,
    REGEX = 281,
    VIRGULA = 282,
    PVIRGULA = 283,
    PA = 284,
    PF = 285,
    NAME = 286,
    ATTRIBUTE = 287,
    BBOP = 288,
    BOP = 289,
    IBOP = 290,
    NOT = 291,
    ASC = 292,
    DESC = 293,
    DATE = 294,
    CONSTANT = 295,
    BOOL = 296,
    ANY = 297,
    ALL = 298,
    FROM = 299
  };
#endif
/* Tokens.  */
#define SELECT 258
#define WHERE 259
#define GROUPBY 260
#define ORDERBY 261
#define HAVING 262
#define AS 263
#define AND 264
#define OR 265
#define EXISTS 266
#define BETWEEN 267
#define JOIN 268
#define INNER 269
#define LEFT 270
#define RIGHT 271
#define FULL 272
#define ON 273
#define IN 274
#define ANDOP 275
#define BEFORE 276
#define IS 277
#define END 278
#define INTERVAL 279
#define LIKE 280
#define REGEX 281
#define VIRGULA 282
#define PVIRGULA 283
#define PA 284
#define PF 285
#define NAME 286
#define ATTRIBUTE 287
#define BBOP 288
#define BOP 289
#define IBOP 290
#define NOT 291
#define ASC 292
#define DESC 293
#define DATE 294
#define CONSTANT 295
#define BOOL 296
#define ANY 297
#define ALL 298
#define FROM 299

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 20 "SQLtoLADSL.y" /* yacc.c:355  */

    std::string *str;
    int integer;

#line 215 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 232 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  21
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   156

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  66
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  122

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   299

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    48,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    45,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    46,     2,    47,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   101,   101,   102,   109,   110,   113,   114,   118,   119,
     122,   128,   131,   132,   135,   136,   139,   140,   143,   144,
     145,   146,   147,   148,   149,   152,   153,   154,   155,   156,
     159,   162,   176,   191,   194,   195,   196,   211,   212,   213,
     225,   234,   235,   242,   249,   257,   258,   261,   262,   266,
     279,   280,   283,   284,   288,   289,   292,   293,   296,   297,
     307,   327,   335,   342,   350,   357,   364
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SELECT", "WHERE", "GROUPBY", "ORDERBY",
  "HAVING", "AS", "AND", "OR", "EXISTS", "BETWEEN", "JOIN", "INNER",
  "LEFT", "RIGHT", "FULL", "ON", "IN", "ANDOP", "BEFORE", "IS", "END",
  "INTERVAL", "LIKE", "REGEX", "VIRGULA", "PVIRGULA", "PA", "PF", "NAME",
  "ATTRIBUTE", "BBOP", "BOP", "IBOP", "NOT", "ASC", "DESC", "DATE",
  "CONSTANT", "BOOL", "ANY", "ALL", "FROM", "'='", "'{'", "'}'", "' '",
  "$accept", "Final", "SelectBlock", "WHERE_", "GROUPBY_", "ORDERBY_",
  "selectList", "selectListN", "selectListNSub", "fromList", "subfromList",
  "Join", "whereList", "ExpR", "Exp", "Term", "Factor", "Args", "Args1",
  "groupbyList", "groupbyListSub", "orderbyList", "orderbyListSub",
  "order", "Literal", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,    61,   123,   125,    32
};
# endif

#define YYPACT_NINF -63

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-63)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       7,    54,     5,   -63,   107,    74,   -16,   -63,   -63,   107,
     -63,   -63,   -63,   -63,   -63,   -27,    13,   -63,     4,   -63,
     -63,   -63,   107,    22,    74,   -63,    46,    74,     1,    74,
      74,   -63,   -63,   -19,    16,   -21,   -63,    36,    55,    56,
      59,   -63,     7,    -3,   -63,    43,   -63,   -63,   -63,    42,
     -63,    74,    74,   -63,   -63,   -63,   -63,    29,    94,    46,
      75,     3,   -19,   -19,    71,    94,   -63,   -63,    26,   -19,
      70,   -63,     2,    78,    57,   113,    60,    69,    26,    22,
      94,    94,    74,    76,   -63,    73,   -63,   -63,   113,    80,
      83,    64,   -63,   -63,    77,   -63,    38,    82,     2,    85,
     -63,    28,   -63,   113,   113,    74,   113,   -63,   113,   -63,
     -63,   -63,    79,   -63,   -19,    72,   -63,   113,    86,   -63,
     113,   -63
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     0,     0,    60,    61,    11,     0,
      62,    63,    64,    65,    66,     0,    10,    12,    14,    37,
      41,     1,     0,     0,    46,    44,     0,     0,     0,     0,
       0,    43,    38,    47,     0,    45,    25,     0,     0,     0,
       0,    18,     0,     5,    16,     0,    13,    15,    39,    40,
      42,     0,     0,    26,    27,    28,    29,     0,     0,     0,
       7,    19,    48,    49,    23,     0,     4,    34,    30,    33,
      41,    17,     0,     9,     0,     0,     0,    34,     0,    33,
       0,     0,     0,     0,    60,     6,    50,    53,     0,     0,
      21,     0,    24,    35,    31,    32,     0,     0,     0,     8,
      54,    56,     3,     0,     0,     0,     0,    51,     0,    58,
      59,    57,     0,    20,    36,     0,    55,     0,     0,    22,
       0,    52
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -63,   -63,    87,   -63,   -63,   -63,   -63,   -63,    93,   -63,
      62,   -63,   -63,    63,   -62,    -1,    -2,   -63,   -63,   -63,
      24,   -63,    19,   -63,   -50
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,    60,    73,    89,    15,    16,    17,    43,
      44,    45,    66,    67,    68,    69,    19,    34,    35,    85,
      86,    99,   100,   111,    20
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      18,    58,    22,    78,    23,    21,    51,    25,    70,    83,
       1,    74,    28,    24,    29,    70,    30,    26,    94,    95,
      31,    75,    87,    33,    59,    91,    18,    52,    48,    49,
      70,    70,    47,    84,     7,    80,    81,    29,   101,    30,
      27,    10,    11,    12,    13,    14,    50,   105,    87,    53,
      62,    63,    32,   112,   113,    29,   115,    30,   101,    36,
      37,    38,    39,    40,    79,   109,   110,   119,    54,    55,
     121,    29,    56,    30,    61,    29,    64,    41,     4,    76,
      72,    96,    82,     5,    88,     6,     7,    81,    90,     8,
       9,    92,    42,    10,    11,    12,    13,    14,     4,    93,
      98,   103,   118,     5,   114,     6,     7,    97,   102,   104,
       9,   106,   108,    10,    11,    12,    13,    14,     4,   120,
      46,    71,   107,    65,   117,     6,     7,   116,    77,    57,
       9,     4,     0,    10,    11,    12,    13,    14,     6,     7,
       0,     0,     0,     9,    84,     7,    10,    11,    12,    13,
      14,     0,    10,    11,    12,    13,    14
};

static const yytype_int8 yycheck[] =
{
       1,     4,     4,    65,     5,     0,    27,     9,    58,     7,
       3,     8,     8,    29,    33,    65,    35,    44,    80,    81,
      22,    18,    72,    24,    27,    75,    27,    48,    29,    30,
      80,    81,    31,    31,    32,     9,    10,    33,    88,    35,
      27,    39,    40,    41,    42,    43,    30,     9,    98,    13,
      51,    52,    30,   103,   104,    33,   106,    35,   108,    13,
      14,    15,    16,    17,    65,    37,    38,   117,    13,    13,
     120,    33,    13,    35,    31,    33,    47,    31,    24,     8,
       5,    82,    12,    29,     6,    31,    32,    10,    31,    35,
      36,    31,    46,    39,    40,    41,    42,    43,    24,    30,
      27,    18,    30,    29,   105,    31,    32,    31,    28,    45,
      36,    29,    27,    39,    40,    41,    42,    43,    24,    33,
      27,    59,    98,    29,    45,    31,    32,   108,    65,    42,
      36,    24,    -1,    39,    40,    41,    42,    43,    31,    32,
      -1,    -1,    -1,    36,    31,    32,    39,    40,    41,    42,
      43,    -1,    39,    40,    41,    42,    43
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    50,    51,    24,    29,    31,    32,    35,    36,
      39,    40,    41,    42,    43,    55,    56,    57,    64,    65,
      73,     0,    65,    64,    29,    65,    44,    27,     8,    33,
      35,    65,    30,    64,    66,    67,    13,    14,    15,    16,
      17,    31,    46,    58,    59,    60,    57,    31,    64,    64,
      30,    27,    48,    13,    13,    13,    13,    51,     4,    27,
      52,    31,    64,    64,    47,    29,    61,    62,    63,    64,
      73,    59,     5,    53,     8,    18,     8,    62,    63,    64,
       9,    10,    12,     7,    31,    68,    69,    73,     6,    54,
      31,    73,    31,    30,    63,    63,    64,    31,    27,    70,
      71,    73,    28,    18,    45,     9,    29,    69,    27,    37,
      38,    72,    73,    73,    64,    73,    71,    45,    30,    73,
      33,    73
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    51,    52,    52,    53,    53,    54,    54,
      55,    55,    56,    56,    57,    57,    58,    58,    59,    59,
      59,    59,    59,    59,    59,    60,    60,    60,    60,    60,
      61,    62,    62,    63,    63,    63,    63,    64,    64,    64,
      64,    65,    65,    65,    65,    66,    66,    67,    67,    67,
      68,    68,    69,    69,    70,    70,    71,    71,    72,    72,
      73,    73,    73,    73,    73,    73,    73
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     8,     2,     0,     2,     0,     2,     0,
       1,     1,     1,     3,     1,     3,     1,     3,     1,     2,
       6,     4,     8,     3,     5,     1,     2,     2,     2,     2,
       1,     3,     3,     1,     1,     3,     5,     1,     3,     3,
       3,     1,     4,     3,     2,     1,     0,     1,     3,     3,
       1,     3,     7,     1,     1,     3,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:
#line 107 "SQLtoLADSL.y" /* yacc.c:1646  */
    {mainfun(); }
#line 1402 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 109 "SQLtoLADSL.y" /* yacc.c:1646  */
    { ; }
#line 1408 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 110 "SQLtoLADSL.y" /* yacc.c:1646  */
    {;}
#line 1414 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 113 "SQLtoLADSL.y" /* yacc.c:1646  */
    { ; }
#line 1420 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 114 "SQLtoLADSL.y" /* yacc.c:1646  */
    {;}
#line 1426 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 118 "SQLtoLADSL.y" /* yacc.c:1646  */
    { ; }
#line 1432 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 119 "SQLtoLADSL.y" /* yacc.c:1646  */
    { ; }
#line 1438 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 122 "SQLtoLADSL.y" /* yacc.c:1646  */
    {
  mainGraph.add_table("lineitem","extendedprice","measure");
  mainGraph.add_table("lineitem","discount","measure");
  mainGraph.add_table("lineitem","shipdate","measure");
  mainGraph.add_table("lineitem","quantity","measure");
                                  }
#line 1449 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 128 "SQLtoLADSL.y" /* yacc.c:1646  */
    { mainGraph.add_select("*","") ; }
#line 1455 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 131 "SQLtoLADSL.y" /* yacc.c:1646  */
    {;}
#line 1461 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 132 "SQLtoLADSL.y" /* yacc.c:1646  */
    {;}
#line 1467 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 135 "SQLtoLADSL.y" /* yacc.c:1646  */
    {mainGraph.add_select(types[(yyvsp[0].integer)].expr,"");}
#line 1473 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 136 "SQLtoLADSL.y" /* yacc.c:1646  */
    {mainGraph.add_select(types[(yyvsp[-2].integer)].expr,*(yyvsp[0].str));}
#line 1479 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 139 "SQLtoLADSL.y" /* yacc.c:1646  */
    { ; }
#line 1485 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 140 "SQLtoLADSL.y" /* yacc.c:1646  */
    { ; }
#line 1491 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 143 "SQLtoLADSL.y" /* yacc.c:1646  */
    {mainGraph.newRoot(*(yyvsp[0].str));}
#line 1497 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 144 "SQLtoLADSL.y" /* yacc.c:1646  */
    { ; }
#line 1503 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 145 "SQLtoLADSL.y" /* yacc.c:1646  */
    {mainGraph.add_join(types[(yyvsp[0].integer)].type,getTable(types[(yyvsp[-2].integer)].type),getTable(types[(yyvsp[0].integer)].type));}
#line 1509 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 146 "SQLtoLADSL.y" /* yacc.c:1646  */
    {mainGraph.tables[*(yyvsp[0].str)]=mainGraph.tables[*(yyvsp[-2].str)];}
#line 1515 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 147 "SQLtoLADSL.y" /* yacc.c:1646  */
    {mainGraph.add_join(types[(yyvsp[0].integer)].type,getTable(types[(yyvsp[-2].integer)].type),getTable(types[(yyvsp[0].integer)].type)); mainGraph.tables[*(yyvsp[-4].str)]=mainGraph.tables[*(yyvsp[-6].str)]; }
#line 1521 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 148 "SQLtoLADSL.y" /* yacc.c:1646  */
    { ; }
#line 1527 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 149 "SQLtoLADSL.y" /* yacc.c:1646  */
    { ; }
#line 1533 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 152 "SQLtoLADSL.y" /* yacc.c:1646  */
    {/*$$ = "Normal"*/;}
#line 1539 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 153 "SQLtoLADSL.y" /* yacc.c:1646  */
    {/*$$ = "Inner"*/;}
#line 1545 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 154 "SQLtoLADSL.y" /* yacc.c:1646  */
    {/*$$ = "Left"*/;}
#line 1551 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 155 "SQLtoLADSL.y" /* yacc.c:1646  */
    {/*$$ = "Rigth"*/;}
#line 1557 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 156 "SQLtoLADSL.y" /* yacc.c:1646  */
    {/*$$ = "Full"*/;}
#line 1563 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 159 "SQLtoLADSL.y" /* yacc.c:1646  */
    { ; }
#line 1569 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 162 "SQLtoLADSL.y" /* yacc.c:1646  */
    {if((yyvsp[-2].integer) != -1){
                                                                if((yyvsp[0].integer) != -1){
                                                                  change_trees(join_trees(trees[(yyvsp[-2].integer)],trees[(yyvsp[0].integer)],"AND"),(yyvsp[-2].integer));
                                                                }
                                                                (yyval.integer) = (yyvsp[-2].integer);
                                                            }else{
                                                                if((yyvsp[0].integer) != -1){
                                                                  (yyval.integer) = (yyvsp[0].integer);
                                                                }else{
                                                                  (yyval.integer) = -1;
                                                                }
                                                            }
                                                          }
#line 1587 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 176 "SQLtoLADSL.y" /* yacc.c:1646  */
    {if((yyvsp[-2].integer) != -1){
                                                               if((yyvsp[0].integer) != -1){
                                                                 change_trees(join_trees(trees[(yyvsp[-2].integer)],trees[(yyvsp[0].integer)],"OR"),(yyvsp[-2].integer));
                                                               }
                                                               (yyval.integer) = (yyvsp[-2].integer);
                                                           }else{
                                                               if((yyvsp[0].integer) != -1){
                                                                 (yyval.integer) = (yyvsp[0].integer);
                                                               }else{
                                                                 (yyval.integer) = -1;
                                                               }
                                                           }
                                                         }
#line 1605 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 191 "SQLtoLADSL.y" /* yacc.c:1646  */
    {if(types[(yyvsp[0].integer)].type!="JOIN"){mainGraph.add_map_filter(types[(yyvsp[0].integer)].type,types[(yyvsp[0].integer)].expr);(yyval.integer) = itr;
                                                                                          trees.push_back( create_tree(types[(yyvsp[0].integer)].expr,types[(yyvsp[0].integer)].type));itr++;}
                                                              else((yyval.integer) = -1);}
#line 1613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 194 "SQLtoLADSL.y" /* yacc.c:1646  */
    {(yyval.integer) = (yyvsp[0].integer) ; }
#line 1619 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 195 "SQLtoLADSL.y" /* yacc.c:1646  */
    {(yyval.integer) = (yyvsp[-1].integer) ;}
#line 1625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 196 "SQLtoLADSL.y" /* yacc.c:1646  */
    {string s = types[(yyvsp[-4].integer)].expr;
                                                            string s2 = types[(yyvsp[-4].integer)].expr;
                                                             s.append(" <= ");
                                                             s2.append(" >= ");
                                                             s.append(types[(yyvsp[-2].integer)].expr);
                                                             s2.append(types[(yyvsp[0].integer)].expr);
                                                             mainGraph.add_map_filter(types[(yyvsp[-4].integer)].type,s);
                                                             mainGraph.add_map_filter(types[(yyvsp[-4].integer)].type,s2);
                                                             trees.push_back( create_tree(s,types[(yyvsp[-4].integer)].type));itr+=1 ;
                                                             trees.push_back( create_tree(s2,types[(yyvsp[-4].integer)].type));itr+=1 ;
                                                             change_trees(join_trees(trees[itr-2],trees[itr-1],"AND"),itr-2);
                                                             (yyval.integer) = itr-2;
                                                           }
#line 1643 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 211 "SQLtoLADSL.y" /* yacc.c:1646  */
    {(yyval.integer) = (yyvsp[0].integer);}
#line 1649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 212 "SQLtoLADSL.y" /* yacc.c:1646  */
    {(yyval.integer) = (yyvsp[-1].integer);}
#line 1655 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 213 "SQLtoLADSL.y" /* yacc.c:1646  */
    {(yyval.integer) = (yyvsp[-2].integer);
                                                              //cout << "1\n";
                                                              types[(yyvsp[-2].integer)].expr.append(*(yyvsp[-1].str));
                                                              types[(yyvsp[-2].integer)].expr.append(types[(yyvsp[0].integer)].expr);
                                                                        if((types[(yyvsp[-2].integer)].type.size()!=0)&&(types[(yyvsp[0].integer)].type.size()!=0)){
                                                                              mainGraph.add_join(types[(yyvsp[0].integer)].type,getTable(types[(yyvsp[-2].integer)].type),getTable(types[(yyvsp[0].integer)].type));
                                                                              types[(yyvsp[-2].integer)].type = "JOIN";
                                                                    /*    }else{
                                                                              types[$1].type = "NOT JOIN";*/
                                                                        }
                                                                }
#line 1671 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 225 "SQLtoLADSL.y" /* yacc.c:1646  */
    {(yyval.integer) = (yyvsp[-2].integer);
                                                            types[(yyvsp[-2].integer)].expr.append(*(yyvsp[-1].str));
                                                            types[(yyvsp[-2].integer)].expr.append(types[(yyvsp[0].integer)].expr) ;
                                                            types[(yyvsp[-2].integer)].type.append(types[(yyvsp[0].integer)].type);
                                                            //cout << types[$1].expr;
                                                            }
#line 1682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 234 "SQLtoLADSL.y" /* yacc.c:1646  */
    {(yyval.integer) = (yyvsp[0].integer);}
#line 1688 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 235 "SQLtoLADSL.y" /* yacc.c:1646  */
    {(yyval.integer) = (yyvsp[-1].integer);
                                                              string s = "";
                                                              s.append(*(yyvsp[-3].str));
                                                              s.append("(");
                                                              s.append(types[(yyvsp[-1].integer)].expr);
                                                              s.append(")");
                                                              types[(yyvsp[-1].integer)].expr = s;}
#line 1700 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 242 "SQLtoLADSL.y" /* yacc.c:1646  */
    {(yyval.integer) = (yyvsp[-1].integer);
                                                              string s = "INTERVAL ";
                                                              s.append(types[(yyvsp[-1].integer)].expr);
                                                              s.append(" ");
                                                              s.append(types[(yyvsp[0].integer)].expr);
                                                              types[(yyvsp[-1].integer)].expr = s;}
#line 1711 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 249 "SQLtoLADSL.y" /* yacc.c:1646  */
    {(yyval.integer) = (yyvsp[0].integer);
                                                              string s = "";
                                                              s.append(*(yyvsp[-1].str));
                                                              s.append(" ");
                                                              s.append(types[(yyvsp[0].integer)].expr);
                                                              types[(yyvsp[0].integer)].expr = s;}
#line 1722 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 257 "SQLtoLADSL.y" /* yacc.c:1646  */
    {(yyval.integer) = (yyvsp[0].integer);}
#line 1728 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 258 "SQLtoLADSL.y" /* yacc.c:1646  */
    { ; }
#line 1734 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 261 "SQLtoLADSL.y" /* yacc.c:1646  */
    {(yyval.integer) = (yyvsp[0].integer) ; }
#line 1740 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 262 "SQLtoLADSL.y" /* yacc.c:1646  */
    {(yyval.integer) = (yyvsp[-2].integer);
                                                            types[(yyvsp[-2].integer)].expr.append( ",");
                                                            types[(yyvsp[-2].integer)].expr.append(types[(yyvsp[0].integer)].expr) ;
                                                            types[(yyvsp[-2].integer)].type.append(types[(yyvsp[0].integer)].type); }
#line 1749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 266 "SQLtoLADSL.y" /* yacc.c:1646  */
    {(yyval.integer) = (yyvsp[-2].integer);
                                                            types[(yyvsp[-2].integer)].expr.append( " ");
                                                            types[(yyvsp[-2].integer)].expr.append(types[(yyvsp[0].integer)].expr) ;
                                                            types[(yyvsp[-2].integer)].type.append(types[(yyvsp[0].integer)].type); }
#line 1758 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 279 "SQLtoLADSL.y" /* yacc.c:1646  */
    { ; }
#line 1764 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 280 "SQLtoLADSL.y" /* yacc.c:1646  */
    { ; }
#line 1770 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 283 "SQLtoLADSL.y" /* yacc.c:1646  */
    { ; }
#line 1776 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 284 "SQLtoLADSL.y" /* yacc.c:1646  */
    {string Table = getTable(types[(yyvsp[0].integer)].expr);
                                                              mainGraph.add_groupby(Table,types[(yyvsp[0].integer)].expr);}
#line 1783 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 288 "SQLtoLADSL.y" /* yacc.c:1646  */
    { ; }
#line 1789 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 289 "SQLtoLADSL.y" /* yacc.c:1646  */
    { ; }
#line 1795 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 292 "SQLtoLADSL.y" /* yacc.c:1646  */
    { ; }
#line 1801 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 293 "SQLtoLADSL.y" /* yacc.c:1646  */
    { ; }
#line 1807 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 296 "SQLtoLADSL.y" /* yacc.c:1646  */
    { ; }
#line 1813 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 297 "SQLtoLADSL.y" /* yacc.c:1646  */
    { ; }
#line 1819 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 307 "SQLtoLADSL.y" /* yacc.c:1646  */
    {string s = getTable(*(yyvsp[0].str));
                                                               s.append(".");
                                                              (yyval.integer) = itr2;
                                                              if(!s.compare(".")){
                                                                par novo;
                                                                novo.type = "";
                                                                novo.expr = *(yyvsp[0].str);
                                                                  types.push_back(novo);
                                                                  itr2 ++;
                                                              }else{
                                                                  s.append(*(yyvsp[0].str));
                                                                par novo;
                                                                novo.type = s;
                                                                novo.expr = s;
                                                                  types.push_back(novo);
                                                                  itr2 ++;
                                                              }}
#line 1841 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 327 "SQLtoLADSL.y" /* yacc.c:1646  */
    {(yyval.integer) = itr2;
                                                              //string s = getTable(*$1);
                                                                par novo;
                                                                novo.type = *(yyvsp[0].str);
                                                                novo.expr = *(yyvsp[0].str);
                                                                types.push_back(novo);
                                                                itr2 ++;}
#line 1853 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 335 "SQLtoLADSL.y" /* yacc.c:1646  */
    {(yyval.integer) = itr2;
                                                                par novo;
                                                                novo.type = "";
                                                                novo.expr = *(yyvsp[0].str);
                                                                  types.push_back(novo);
                                                                  itr2 ++;}
#line 1864 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 342 "SQLtoLADSL.y" /* yacc.c:1646  */
    {(yyval.integer) = itr2;
                                                                par novo;
                                                                novo.type = "";
                                                                novo.expr = *(yyvsp[0].str);
                                                                  types.push_back(novo);
                                                                  itr2 ++;
                                                                }
#line 1876 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 350 "SQLtoLADSL.y" /* yacc.c:1646  */
    {(yyval.integer) = itr2;
                                                                par novo;
                                                                novo.type = "";
                                                                novo.expr = *(yyvsp[0].str);
                                                                  types.push_back(novo);
                                                                  itr2 ++;}
#line 1887 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 357 "SQLtoLADSL.y" /* yacc.c:1646  */
    {(yyval.integer) = itr2;
                                                                par novo;
                                                                novo.type = "";
                                                                novo.expr = *(yyvsp[0].str);
                                                                  types.push_back(novo);
                                                                  itr2 ++;}
#line 1898 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 364 "SQLtoLADSL.y" /* yacc.c:1646  */
    {(yyval.integer) = itr2;
                                                                par novo;
                                                                novo.type = "";
                                                                novo.expr = *(yyvsp[0].str);
                                                                  types.push_back(novo);
                                                                  itr2 ++;}
#line 1909 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1913 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 377 "SQLtoLADSL.y" /* yacc.c:1906  */

#include "lex.yy.c"
#include "SQLtoLADSL.cpp"
 void yyerror(const char*s){
    printf("parsing aborted: %s\n",s);
 }


int main(int argc, char **argv){

    FILE *  out = fopen("name.vm", "w");
    if (out == NULL){
        printf("Error opening file!\n");
        exit(1);
    }
//    char codigo[1023*1024];
    fprintf(out, "start\n");
    yyparse();
    fprintf(out, "stop\n");

    fclose(out);
    return 0;
}
