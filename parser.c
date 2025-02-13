/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NUMBER = 258,
     ID = 259,
     IF = 260,
     ELSE = 261,
     WHILE = 262,
     FOR = 263,
     FUNCTION = 264,
     RETURN = 265,
     BREAK = 266,
     CONTINUE = 267,
     AND = 268,
     NOT = 269,
     OR = 270,
     LOC = 271,
     TRUE = 272,
     FALSE = 273,
     NIL = 274,
     ASSIGNMENT = 275,
     PLUS = 276,
     MINUS = 277,
     MUL = 278,
     DIV = 279,
     MOD = 280,
     EQUAL_TO = 281,
     NOT_EQUAL_TO = 282,
     PLUS_PLUS = 283,
     MINUS_MINUS = 284,
     GREATER_THAN = 285,
     LESS_THAN = 286,
     GREATER_THAN_OR_EQUAL = 287,
     LESS_THAN_OR_EQUAL = 288,
     STRING = 289,
     LEFT_BRACE = 290,
     RIGHT_BRACE = 291,
     LEFT_BRACKET = 292,
     RIGHT_BRACKET = 293,
     LEFT_PARENTHESIS = 294,
     RIGHT_PARENTHESIS = 295,
     SEMICOLON = 296,
     COMMA = 297,
     COLON = 298,
     DOUBLE_COLON = 299,
     DOT = 300,
     DOUBLE_DOT = 301,
     UMINUS = 302
   };
#endif
/* Tokens.  */
#define NUMBER 258
#define ID 259
#define IF 260
#define ELSE 261
#define WHILE 262
#define FOR 263
#define FUNCTION 264
#define RETURN 265
#define BREAK 266
#define CONTINUE 267
#define AND 268
#define NOT 269
#define OR 270
#define LOC 271
#define TRUE 272
#define FALSE 273
#define NIL 274
#define ASSIGNMENT 275
#define PLUS 276
#define MINUS 277
#define MUL 278
#define DIV 279
#define MOD 280
#define EQUAL_TO 281
#define NOT_EQUAL_TO 282
#define PLUS_PLUS 283
#define MINUS_MINUS 284
#define GREATER_THAN 285
#define LESS_THAN 286
#define GREATER_THAN_OR_EQUAL 287
#define LESS_THAN_OR_EQUAL 288
#define STRING 289
#define LEFT_BRACE 290
#define RIGHT_BRACE 291
#define LEFT_BRACKET 292
#define RIGHT_BRACKET 293
#define LEFT_PARENTHESIS 294
#define RIGHT_PARENTHESIS 295
#define SEMICOLON 296
#define COMMA 297
#define COLON 298
#define DOUBLE_COLON 299
#define DOT 300
#define DOUBLE_DOT 301
#define UMINUS 302




/* Copy the first part of user declarations.  */
#line 1 "parser.y"

#include "scanner.h"
#define YYDEBUG 1
void yyerror(char* yaccProvidedMessage);
extern int yylineno;
extern struct expr* lvalue_expr(Node sym);
extern char* yytext;
extern FILE* yyin;
int a=0;
int apot_not=0;
int apotimisi_not=0;
int scope=0;
int cont=0;
int cont1=0;
int cont2=0;
int apotimisi_and=0;
int apotimisi_or=0;
int tmpAnd1=0;
int mikrotero=0;
int tmpMikr=0;
int tmpAnd2=0;
int yylex();
char* newtempname();
int LoopCounter=0;
int flag=0;
int f=0;
int isInFunc=0;
int StartJump=-1; // gia ta jumps stis edoles if
int EndJump=-1;  //  ---//---
HashTable p;
struct forloop;
void Quad_Print();
void resettemp();
struct stmt_t* merge(struct stmt_t* l1,struct stmt_t* l2);
struct expr* Insert(struct expr* x);
void pushLoop(int label, struct LabelStack**top);
void pushIf(int label, struct IfStack**top);
int popLoop(struct LabelStack**top);
int popIf(struct IfStack**top);
void pushLabel(struct LabelStack**top,int label);
void pushOffset(int offset);
int pop_and_top();
int pop(struct LabelStack**top);
void patchlist(int list,int label);
void emit (enum iopcode op,struct expr* arg1,struct expr* arg2, struct expr* result, unsigned label, unsigned line);
void check_arith (struct expr* e, const char* context);
unsigned nextquadlabel();
Node newtemp();
struct stmt_t* makelist(int quadno);
void backpatch(struct stmt_t *list, int quadno);
struct expr* newexpr(enum expr_t t);
struct expr* newexpr_conststring(char *s);
struct expr* newexpr_constnum (double i);
struct expr* newexpr_constbool (unsigned int b);
struct expr* newexpr_constnil();
struct expr* emit_iftableitem(struct expr* e);
char* newtempfuncname();
void exitscopespace(void);
void resetformalargoffset(void);
void resetfunctionoffset(void);
void enterscopespace(void);
void inccurrsopeoffset(void);
void printstack();
enum scopespace_t currscopespace(void);
unsigned currscopeoffset(void);
void restorecurrscopeoffset(unsigned n);
struct expr* member_item(struct expr* lv, char* name);
struct expr* make_call(struct expr* lv, struct expr* reversed_elist);
void patchlabel(unsigned quadNo, unsigned label);
void pushB(struct stmt_t* breakList, struct stmt_t* continueList);
int popB();
void pushC(struct stmt_t* breakList, struct stmt_t* continueList);
int popC();
int popAND();
void pushAND(int quadNo);


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 81 "parser.y"
{
    int intVal;
    char* stringVal;
    float floatVal;
    struct forloop* forVal;
    struct expr* exprVal;
    struct call* call;
    struct SymbolTableEntry *tptr;
    struct Lc_stack_t* loop;
}
/* Line 193 of yacc.c.  */
#line 278 "parser.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 291 "parser.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   552

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  100
/* YYNRULES -- Number of states.  */
#define YYNSTATES  184

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   302

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    12,    14,    16,    18,
      20,    22,    24,    26,    28,    30,    34,    38,    42,    46,
      50,    54,    58,    62,    66,    67,    72,    73,    78,    79,
      85,    86,    92,    94,    96,   100,   103,   106,   109,   112,
     115,   118,   120,   124,   126,   128,   130,   134,   136,   138,
     141,   144,   146,   150,   155,   159,   164,   169,   172,   179,
     181,   183,   187,   193,   195,   199,   200,   204,   208,   210,
     214,   220,   224,   226,   227,   230,   234,   236,   240,   242,
     244,   246,   248,   250,   252,   256,   257,   262,   264,   267,
     272,   274,   278,   282,   283,   284,   292,   300,   303,   306,
     309
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      49,     0,    -1,    50,    -1,    50,    51,    -1,    -1,    52,
      41,    -1,    80,    -1,    83,    -1,    87,    -1,    90,    -1,
      88,    -1,    89,    -1,    75,    -1,    70,    -1,    41,    -1,
      52,    21,    52,    -1,    52,    22,    52,    -1,    52,    23,
      52,    -1,    52,    24,    52,    -1,    52,    25,    52,    -1,
      52,    30,    52,    -1,    52,    32,    52,    -1,    52,    31,
      52,    -1,    52,    33,    52,    -1,    -1,    52,    26,    53,
      52,    -1,    -1,    52,    27,    54,    52,    -1,    -1,    52,
      13,    55,    85,    52,    -1,    -1,    52,    15,    56,    85,
      52,    -1,    57,    -1,    58,    -1,    39,    52,    40,    -1,
      22,    52,    -1,    14,    52,    -1,    28,    60,    -1,    60,
      28,    -1,    29,    60,    -1,    60,    29,    -1,    59,    -1,
      60,    20,    52,    -1,    60,    -1,    62,    -1,    67,    -1,
      39,    70,    40,    -1,    76,    -1,     4,    -1,    16,     4,
      -1,    44,     4,    -1,    61,    -1,    60,    45,     4,    -1,
      60,    37,    52,    38,    -1,    62,    45,     4,    -1,    62,
      37,    52,    38,    -1,    62,    39,    66,    40,    -1,    60,
      63,    -1,    39,    70,    40,    39,    66,    40,    -1,    64,
      -1,    65,    -1,    39,    66,    40,    -1,    46,     4,    39,
      66,    40,    -1,    52,    -1,    66,    42,    52,    -1,    -1,
      37,    66,    38,    -1,    37,    68,    38,    -1,    69,    -1,
      68,    42,    69,    -1,    35,    52,    43,    52,    36,    -1,
      72,    73,    74,    -1,     4,    -1,    -1,     9,    71,    -1,
      39,    77,    40,    -1,    75,    -1,    35,    50,    36,    -1,
       3,    -1,    34,    -1,    19,    -1,    17,    -1,    18,    -1,
       4,    -1,    77,    42,     4,    -1,    -1,     5,    39,    52,
      40,    -1,     6,    -1,    78,    51,    -1,    78,    51,    79,
      51,    -1,     7,    -1,    39,    52,    40,    -1,    81,    82,
      51,    -1,    -1,    -1,     8,    39,    66,    41,    85,    52,
      41,    -1,    86,    84,    66,    40,    84,    51,    84,    -1,
      11,    41,    -1,    12,    41,    -1,    10,    41,    -1,    10,
      52,    41,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   114,   114,   117,   118,   122,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   148,   154,   160,   166,   172,
     178,   185,   192,   201,   208,   208,   232,   232,   257,   257,
     280,   280,   301,   302,   305,   306,   312,   328,   341,   356,
     369,   384,   388,   411,   412,   413,   414,   418,   423,   436,
     452,   457,   461,   464,   478,   479,   485,   486,   500,   508,
     509,   513,   524,   534,   544,   559,   563,   577,   594,   595,
     604,   619,   631,   632,   635,   658,   670,   679,   682,   683,
     684,   685,   686,   690,   700,   711,   714,   740,   746,   750,
     759,   764,   796,   816,   822,   824,   855,   869,   876,   883,
     892
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMBER", "ID", "IF", "ELSE", "WHILE",
  "FOR", "FUNCTION", "RETURN", "BREAK", "CONTINUE", "AND", "NOT", "OR",
  "LOC", "TRUE", "FALSE", "NIL", "ASSIGNMENT", "PLUS", "MINUS", "MUL",
  "DIV", "MOD", "EQUAL_TO", "NOT_EQUAL_TO", "PLUS_PLUS", "MINUS_MINUS",
  "GREATER_THAN", "LESS_THAN", "GREATER_THAN_OR_EQUAL",
  "LESS_THAN_OR_EQUAL", "STRING", "LEFT_BRACE", "RIGHT_BRACE",
  "LEFT_BRACKET", "RIGHT_BRACKET", "LEFT_PARENTHESIS", "RIGHT_PARENTHESIS",
  "SEMICOLON", "COMMA", "COLON", "DOUBLE_COLON", "DOT", "DOUBLE_DOT",
  "UMINUS", "$accept", "program", "new_stmt", "stmt", "expr", "@1", "@2",
  "@3", "@4", "term", "assignexpr", "primary", "lvalue", "member", "call",
  "callsuffix", "normcall", "methodcall", "elist", "objectdef", "indexed",
  "indexedelem", "funcdef", "funcname", "funcprefix", "funcargs",
  "funcbody", "block", "const", "idlist", "ifprefix", "elseprefix",
  "ifstmt", "whilestart", "whilecond", "whilestmt", "N", "M", "forprefix",
  "forstmt", "break", "continue", "returnstmt", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    48,    49,    50,    50,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    53,    52,    54,    52,    55,    52,
      56,    52,    52,    52,    57,    57,    57,    57,    57,    57,
      57,    57,    58,    59,    59,    59,    59,    59,    60,    60,
      60,    60,    61,    61,    61,    61,    62,    62,    62,    63,
      63,    64,    65,    66,    66,    66,    67,    67,    68,    68,
      69,    70,    71,    71,    72,    73,    74,    75,    76,    76,
      76,    76,    76,    77,    77,    77,    78,    79,    80,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      90
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     0,     4,     0,     4,     0,     5,
       0,     5,     1,     1,     3,     2,     2,     2,     2,     2,
       2,     1,     3,     1,     1,     1,     3,     1,     1,     2,
       2,     1,     3,     4,     3,     4,     4,     2,     6,     1,
       1,     3,     5,     1,     3,     0,     3,     3,     1,     3,
       5,     3,     1,     0,     2,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     3,     0,     4,     1,     2,     4,
       1,     3,     3,     0,     0,     7,     7,     2,     2,     2,
       3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     2,     1,    78,    48,     0,    90,     0,    73,
       0,     0,     0,     0,     0,    81,    82,    80,     0,     0,
       0,    79,     4,    65,     0,    14,     0,     3,     0,    32,
      33,    41,    43,    51,    44,    45,    13,     0,    12,    47,
       0,     6,     0,     7,    93,     8,    10,    11,     9,     0,
      65,    72,    74,    99,     0,    97,    98,    36,    49,    35,
       0,    37,     0,    39,     0,     0,    63,     0,     0,    68,
       0,     0,    50,    28,    30,     0,     0,     0,     0,     0,
      24,    26,     0,     0,     0,     0,     5,     0,    38,    40,
       0,    65,     0,     0,    57,    59,    60,     0,    65,     0,
      85,     0,    88,     0,     0,    65,     0,     0,   100,     0,
      77,     0,    66,     0,    67,     0,    34,    46,    94,    94,
      15,    16,    17,    18,    19,     0,     0,    20,    22,    21,
      23,    42,     0,     0,    52,     0,     0,     0,    54,    83,
       0,    71,    76,    87,     0,     0,    92,     0,    86,    94,
       0,     0,    64,    69,    65,     0,     0,    25,    27,    53,
      61,    65,    55,    56,    75,     0,    89,    91,    93,     0,
       0,     0,    29,    31,     0,    84,     0,     0,    70,    58,
      62,    93,    95,    96
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    27,    66,   125,   126,   118,   119,    29,
      30,    31,    32,    33,    34,    94,    95,    96,    67,    35,
      68,    69,    36,    52,    37,   101,   141,    38,    39,   140,
      40,   144,    41,    42,   104,    43,   105,   155,    44,    45,
      46,    47,    48
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -164
static const yytype_int16 yypact[] =
{
    -164,     3,   168,  -164,  -164,  -164,   -30,  -164,    -7,    15,
      17,     0,     8,   226,    48,  -164,  -164,  -164,   226,     9,
       9,  -164,  -164,    75,   197,  -164,    51,  -164,   274,  -164,
    -164,  -164,   387,  -164,    27,  -164,  -164,    76,  -164,  -164,
     168,  -164,    77,  -164,  -164,  -164,  -164,  -164,  -164,   226,
     226,  -164,  -164,  -164,   295,  -164,  -164,  -164,  -164,  -164,
      58,   -22,    27,   -22,   122,   226,   478,   -32,   -12,  -164,
     337,    47,  -164,  -164,  -164,   226,   226,   226,   226,   226,
    -164,  -164,   226,   226,   226,   226,  -164,   226,  -164,  -164,
     226,   226,    86,   113,  -164,  -164,  -164,   226,   226,   114,
     116,    87,   115,   226,   168,   226,   358,    18,  -164,    95,
    -164,   251,  -164,   226,  -164,    93,  -164,   104,  -164,  -164,
       4,     4,  -164,  -164,  -164,   226,   226,   506,   506,   506,
     506,   478,   414,   -28,  -164,   106,   435,     2,  -164,  -164,
      28,  -164,  -164,  -164,   168,   379,  -164,    29,  -164,  -164,
     104,   226,   478,  -164,   226,   226,   226,   506,   506,  -164,
    -164,   226,  -164,  -164,  -164,   142,  -164,  -164,  -164,   226,
     456,    44,   519,   493,    56,  -164,   168,   316,  -164,  -164,
    -164,  -164,  -164,  -164
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -164,  -164,   125,   -39,    -2,  -164,  -164,  -164,  -164,  -164,
    -164,  -164,    80,  -164,    88,  -164,  -164,  -164,   -48,  -164,
    -164,    33,   -20,  -164,  -164,  -164,  -164,    54,  -164,  -164,
    -164,  -164,  -164,  -164,  -164,  -164,  -163,  -112,  -164,  -164,
    -164,  -164,  -164
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_int16 yytable[] =
{
      28,   102,   107,     3,    71,   176,   112,   156,    54,    49,
     113,    57,   160,     5,   113,    90,    59,    91,   183,    51,
       4,     5,    70,    92,    93,    14,   114,    77,    78,    79,
     115,    13,    50,    14,    15,    16,    17,   169,    28,    18,
     109,    55,   163,   133,   113,    19,    20,   106,    60,    56,
     137,    21,    58,    26,    23,    72,    24,   147,    53,   149,
     113,    26,    28,   111,    97,   146,    98,     9,   164,   168,
     165,   113,    99,   120,   121,   122,   123,   124,     4,     5,
     127,   128,   129,   130,   179,   131,   113,   117,   132,    13,
     134,    14,    15,    16,    17,   136,   180,    18,   113,    61,
      63,   145,    28,    19,    20,   166,   171,    62,    62,    21,
      65,   152,    23,   174,    24,   100,   103,   135,   138,    26,
     139,   143,    22,   157,   158,     4,     5,     6,    65,     7,
       8,     9,    10,    11,    12,   150,    13,   181,    14,    15,
      16,    17,    28,   154,    18,   161,   175,    64,   153,   170,
      19,    20,     0,   172,   173,   142,    21,    22,   110,    23,
       0,    24,     0,    25,     0,     0,    26,   177,     0,     0,
       0,     4,     5,     6,    28,     7,     8,     9,    10,    11,
      12,     0,    13,     0,    14,    15,    16,    17,     0,     0,
      18,     0,     0,     0,     0,     0,    19,    20,     0,     0,
       4,     5,    21,    22,     0,    23,     9,    24,     0,    25,
       0,    13,    26,    14,    15,    16,    17,     0,     0,    18,
       0,     0,     0,     0,     0,    19,    20,     0,     0,     4,
       5,    21,     0,     0,    23,     0,    24,     0,     0,     0,
      13,    26,    14,    15,    16,    17,     0,     0,    18,     0,
       0,     0,     0,     0,    19,    20,     0,     0,     0,     0,
      21,     0,     0,    23,    73,    24,    74,     0,     0,     0,
      26,     0,    75,    76,    77,    78,    79,    80,    81,     0,
       0,    82,    83,    84,    85,     0,     0,    73,     0,    74,
       0,     0,     0,     0,   151,    75,    76,    77,    78,    79,
      80,    81,     0,     0,    82,    83,    84,    85,    73,     0,
      74,     0,     0,     0,     0,    86,    75,    76,    77,    78,
      79,    80,    81,     0,     0,    82,    83,    84,    85,    73,
       0,    74,     0,     0,     0,     0,   108,    75,    76,    77,
      78,    79,    80,    81,     0,     0,    82,    83,    84,    85,
      73,     0,    74,     0,     0,     0,     0,   182,    75,    76,
      77,    78,    79,    80,    81,     0,     0,    82,    83,    84,
      85,    73,     0,    74,     0,     0,     0,   116,     0,    75,
      76,    77,    78,    79,    80,    81,     0,     0,    82,    83,
      84,    85,    73,     0,    74,     0,     0,     0,   148,     0,
      75,    76,    77,    78,    79,    80,    81,    87,     0,    82,
      83,    84,    85,     0,     0,    88,    89,     0,     0,   167,
       0,     0,     0,     0,    90,     0,    91,    73,     0,    74,
       0,     0,    92,    93,     0,    75,    76,    77,    78,    79,
      80,    81,     0,     0,    82,    83,    84,    85,    73,     0,
      74,     0,   159,     0,     0,     0,    75,    76,    77,    78,
      79,    80,    81,     0,     0,    82,    83,    84,    85,    73,
       0,    74,     0,   162,     0,     0,     0,    75,    76,    77,
      78,    79,    80,    81,     0,     0,    82,    83,    84,    85,
       0,    73,   178,    74,     0,     0,     0,     0,     0,    75,
      76,    77,    78,    79,    80,    81,    73,     0,    82,    83,
      84,    85,     0,     0,    75,    76,    77,    78,    79,    80,
      81,     0,     0,    82,    83,    84,    85,    75,    76,    77,
      78,    79,    -1,    -1,     0,     0,    -1,    -1,    -1,    -1,
      75,    76,    77,    78,    79,    80,    81,     0,     0,    82,
      83,    84,    85
};

static const yytype_int16 yycheck[] =
{
       2,    40,    50,     0,    24,   168,    38,   119,    10,    39,
      42,    13,    40,     4,    42,    37,    18,    39,   181,     4,
       3,     4,    24,    45,    46,    16,    38,    23,    24,    25,
      42,    14,    39,    16,    17,    18,    19,   149,    40,    22,
      60,    41,    40,    91,    42,    28,    29,    49,    39,    41,
      98,    34,     4,    44,    37,     4,    39,   105,    41,    41,
      42,    44,    64,    65,    37,   104,    39,     9,    40,    40,
      42,    42,    45,    75,    76,    77,    78,    79,     3,     4,
      82,    83,    84,    85,    40,    87,    42,    40,    90,    14,
       4,    16,    17,    18,    19,    97,    40,    22,    42,    19,
      20,   103,   104,    28,    29,   144,   154,    19,    20,    34,
      35,   113,    37,   161,    39,    39,    39,     4,     4,    44,
       4,     6,    35,   125,   126,     3,     4,     5,    35,     7,
       8,     9,    10,    11,    12,    40,    14,   176,    16,    17,
      18,    19,   144,    39,    22,    39,     4,    22,   115,   151,
      28,    29,    -1,   155,   156,   101,    34,    35,    36,    37,
      -1,    39,    -1,    41,    -1,    -1,    44,   169,    -1,    -1,
      -1,     3,     4,     5,   176,     7,     8,     9,    10,    11,
      12,    -1,    14,    -1,    16,    17,    18,    19,    -1,    -1,
      22,    -1,    -1,    -1,    -1,    -1,    28,    29,    -1,    -1,
       3,     4,    34,    35,    -1,    37,     9,    39,    -1,    41,
      -1,    14,    44,    16,    17,    18,    19,    -1,    -1,    22,
      -1,    -1,    -1,    -1,    -1,    28,    29,    -1,    -1,     3,
       4,    34,    -1,    -1,    37,    -1,    39,    -1,    -1,    -1,
      14,    44,    16,    17,    18,    19,    -1,    -1,    22,    -1,
      -1,    -1,    -1,    -1,    28,    29,    -1,    -1,    -1,    -1,
      34,    -1,    -1,    37,    13,    39,    15,    -1,    -1,    -1,
      44,    -1,    21,    22,    23,    24,    25,    26,    27,    -1,
      -1,    30,    31,    32,    33,    -1,    -1,    13,    -1,    15,
      -1,    -1,    -1,    -1,    43,    21,    22,    23,    24,    25,
      26,    27,    -1,    -1,    30,    31,    32,    33,    13,    -1,
      15,    -1,    -1,    -1,    -1,    41,    21,    22,    23,    24,
      25,    26,    27,    -1,    -1,    30,    31,    32,    33,    13,
      -1,    15,    -1,    -1,    -1,    -1,    41,    21,    22,    23,
      24,    25,    26,    27,    -1,    -1,    30,    31,    32,    33,
      13,    -1,    15,    -1,    -1,    -1,    -1,    41,    21,    22,
      23,    24,    25,    26,    27,    -1,    -1,    30,    31,    32,
      33,    13,    -1,    15,    -1,    -1,    -1,    40,    -1,    21,
      22,    23,    24,    25,    26,    27,    -1,    -1,    30,    31,
      32,    33,    13,    -1,    15,    -1,    -1,    -1,    40,    -1,
      21,    22,    23,    24,    25,    26,    27,    20,    -1,    30,
      31,    32,    33,    -1,    -1,    28,    29,    -1,    -1,    40,
      -1,    -1,    -1,    -1,    37,    -1,    39,    13,    -1,    15,
      -1,    -1,    45,    46,    -1,    21,    22,    23,    24,    25,
      26,    27,    -1,    -1,    30,    31,    32,    33,    13,    -1,
      15,    -1,    38,    -1,    -1,    -1,    21,    22,    23,    24,
      25,    26,    27,    -1,    -1,    30,    31,    32,    33,    13,
      -1,    15,    -1,    38,    -1,    -1,    -1,    21,    22,    23,
      24,    25,    26,    27,    -1,    -1,    30,    31,    32,    33,
      -1,    13,    36,    15,    -1,    -1,    -1,    -1,    -1,    21,
      22,    23,    24,    25,    26,    27,    13,    -1,    30,    31,
      32,    33,    -1,    -1,    21,    22,    23,    24,    25,    26,
      27,    -1,    -1,    30,    31,    32,    33,    21,    22,    23,
      24,    25,    26,    27,    -1,    -1,    30,    31,    32,    33,
      21,    22,    23,    24,    25,    26,    27,    -1,    -1,    30,
      31,    32,    33
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    49,    50,     0,     3,     4,     5,     7,     8,     9,
      10,    11,    12,    14,    16,    17,    18,    19,    22,    28,
      29,    34,    35,    37,    39,    41,    44,    51,    52,    57,
      58,    59,    60,    61,    62,    67,    70,    72,    75,    76,
      78,    80,    81,    83,    86,    87,    88,    89,    90,    39,
      39,     4,    71,    41,    52,    41,    41,    52,     4,    52,
      39,    60,    62,    60,    50,    35,    52,    66,    68,    69,
      52,    70,     4,    13,    15,    21,    22,    23,    24,    25,
      26,    27,    30,    31,    32,    33,    41,    20,    28,    29,
      37,    39,    45,    46,    63,    64,    65,    37,    39,    45,
      39,    73,    51,    39,    82,    84,    52,    66,    41,    70,
      36,    52,    38,    42,    38,    42,    40,    40,    55,    56,
      52,    52,    52,    52,    52,    53,    54,    52,    52,    52,
      52,    52,    52,    66,     4,     4,    52,    66,     4,     4,
      77,    74,    75,     6,    79,    52,    51,    66,    40,    41,
      40,    43,    52,    69,    39,    85,    85,    52,    52,    38,
      40,    39,    38,    40,    40,    42,    51,    40,    40,    85,
      52,    66,    52,    52,    66,     4,    84,    52,    36,    40,
      40,    51,    41,    84
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 5:
#line 122 "parser.y"
    {
    if((yyvsp[(1) - (2)].exprVal)->type==boolexpr_e){
        (yyvsp[(1) - (2)].exprVal)->sym=newtemp();
        if (apotimisi_and==1){
            patchlabel(tmpAnd2,nextquadlabel()+1);
            apotimisi_and=0;
        }
        backpatch((yyvsp[(1) - (2)].exprVal)->truelist,nextquadlabel()+1);
        emit(assign,newexpr_constbool(1),NULL,(yyvsp[(1) - (2)].exprVal),nextquadlabel(),yylineno);
        emit(jump,NULL,NULL,NULL,nextquadlabel()+3,yylineno);
        backpatch((yyvsp[(1) - (2)].exprVal)->falselist,nextquadlabel()+1);
        emit(assign,newexpr_constbool(0),NULL,(yyvsp[(1) - (2)].exprVal),nextquadlabel(),yylineno);
    }
}
    break;

  case 14:
#line 144 "parser.y"
    {resettemp();}
    break;

  case 15:
#line 148 "parser.y"
    {
        (yyval.exprVal)=newexpr(arithexpr_e);
        (yyval.exprVal)->sym=newtemp();
        (yyval.exprVal)=lvalue_expr((yyval.exprVal)->sym);
        emit(add,(yyvsp[(1) - (3)].exprVal),(yyvsp[(3) - (3)].exprVal),(yyval.exprVal),nextquadlabel(),yylineno);
    }
    break;

  case 16:
#line 154 "parser.y"
    {
        (yyval.exprVal)=newexpr(arithexpr_e);
        (yyval.exprVal)->sym=newtemp();
        (yyval.exprVal)=lvalue_expr((yyval.exprVal)->sym);
        emit(sub,(yyvsp[(1) - (3)].exprVal),(yyvsp[(3) - (3)].exprVal),(yyval.exprVal),nextquadlabel(),yylineno);
    }
    break;

  case 17:
#line 160 "parser.y"
    {
        (yyval.exprVal)=newexpr(arithexpr_e);
        (yyval.exprVal)->sym=newtemp();
        (yyval.exprVal)=lvalue_expr((yyval.exprVal)->sym);
        emit(mul,(yyvsp[(1) - (3)].exprVal),(yyvsp[(3) - (3)].exprVal),(yyval.exprVal),nextquadlabel(),yylineno);
    }
    break;

  case 18:
#line 166 "parser.y"
    {
        (yyval.exprVal)=newexpr(arithexpr_e);
        (yyval.exprVal)->sym=newtemp();
        (yyval.exprVal)=lvalue_expr((yyval.exprVal)->sym);
        emit(divv,(yyvsp[(1) - (3)].exprVal),(yyvsp[(3) - (3)].exprVal),(yyval.exprVal),nextquadlabel(),yylineno);
    }
    break;

  case 19:
#line 172 "parser.y"
    {
        (yyval.exprVal)=newexpr(arithexpr_e);
        (yyval.exprVal)->sym=newtemp();
        (yyval.exprVal)=lvalue_expr((yyval.exprVal)->sym);
        emit(mod,(yyvsp[(1) - (3)].exprVal),(yyvsp[(3) - (3)].exprVal),(yyval.exprVal),nextquadlabel(),yylineno);
    }
    break;

  case 20:
#line 178 "parser.y"
    {
        (yyval.exprVal) = newexpr(boolexpr_e);
        (yyval.exprVal)->truelist = makelist(nextquadlabel());
        (yyval.exprVal)->falselist = makelist(nextquadlabel()+1);
        emit(if_greater,(yyvsp[(1) - (3)].exprVal),(yyvsp[(3) - (3)].exprVal),NULL,nextquadlabel(),yylineno);
        emit(jump,NULL,NULL,NULL,nextquadlabel()+1,yylineno);
    }
    break;

  case 21:
#line 185 "parser.y"
    {
        (yyval.exprVal) = newexpr(boolexpr_e);
        (yyval.exprVal)->truelist = makelist(nextquadlabel());
        (yyval.exprVal)->falselist = makelist(nextquadlabel()+1);
        emit(if_greatereq,(yyvsp[(1) - (3)].exprVal),(yyvsp[(3) - (3)].exprVal),NULL,nextquadlabel(),yylineno);
        emit(jump,NULL,NULL,NULL,nextquadlabel(),yylineno);
    }
    break;

  case 22:
#line 192 "parser.y"
    {
        (yyval.exprVal) = newexpr(boolexpr_e);
        (yyval.exprVal)->truelist = makelist(nextquadlabel());
        (yyval.exprVal)->falselist = makelist(nextquadlabel()+1);
        emit(if_less,(yyvsp[(1) - (3)].exprVal),(yyvsp[(3) - (3)].exprVal),NULL,nextquadlabel(),yylineno);
        emit(jump,NULL,NULL,NULL,nextquadlabel(),yylineno);
        tmpMikr=(yyval.exprVal)->falselist->quadNo;
        mikrotero=1;
    }
    break;

  case 23:
#line 201 "parser.y"
    {
        (yyval.exprVal) = newexpr(boolexpr_e);
        (yyval.exprVal)->truelist = makelist(nextquadlabel());
        (yyval.exprVal)->falselist = makelist(nextquadlabel()+1);
        emit(if_lesseq,(yyvsp[(1) - (3)].exprVal),(yyvsp[(3) - (3)].exprVal),NULL,nextquadlabel(),yylineno);
        emit(jump,NULL,NULL,NULL,nextquadlabel(),yylineno);
    }
    break;

  case 24:
#line 208 "parser.y"
    {
        if((yyvsp[(1) - (2)].exprVal)->type==boolexpr_e && apotimisi_not==1){
            (yyvsp[(1) - (2)].exprVal)->sym=newtemp();
            backpatch((yyvsp[(1) - (2)].exprVal)->truelist,nextquadlabel()+1);
            emit(assign,newexpr_constbool(1),NULL,(yyvsp[(1) - (2)].exprVal),nextquadlabel(),yylineno);
            emit(jump,NULL,NULL,NULL,nextquadlabel()+3,yylineno);
            backpatch((yyvsp[(1) - (2)].exprVal)->falselist,nextquadlabel()+1);
            emit(assign,newexpr_constbool(0),NULL,(yyvsp[(1) - (2)].exprVal),nextquadlabel(),yylineno);
        }
    }
    break;

  case 25:
#line 217 "parser.y"
    {
        if((yyvsp[(4) - (4)].exprVal)->type==boolexpr_e && apotimisi_not==1){
            (yyvsp[(1) - (4)].exprVal)->sym=newtemp();
            backpatch((yyvsp[(4) - (4)].exprVal)->truelist,nextquadlabel()+1);
            emit(assign,newexpr_constbool(1),NULL,(yyvsp[(4) - (4)].exprVal),nextquadlabel(),yylineno);
            emit(jump,NULL,NULL,NULL,nextquadlabel()+3,yylineno);
            backpatch((yyvsp[(4) - (4)].exprVal)->falselist,nextquadlabel()+1);
            emit(assign,newexpr_constbool(0),NULL,(yyvsp[(4) - (4)].exprVal),nextquadlabel(),yylineno);
        }
        (yyval.exprVal) = newexpr(boolexpr_e);
        (yyval.exprVal)->truelist = makelist(nextquadlabel());
        (yyval.exprVal)->falselist = makelist(nextquadlabel()+1);
        emit(if_eq,(yyvsp[(1) - (4)].exprVal),(yyvsp[(4) - (4)].exprVal),NULL,nextquadlabel(),yylineno);
        emit(jump,NULL,NULL,NULL,nextquadlabel(),yylineno);
    }
    break;

  case 26:
#line 232 "parser.y"
    {
            if((yyvsp[(1) - (2)].exprVal)->type==boolexpr_e && apotimisi_not==1){
                (yyvsp[(1) - (2)].exprVal)->sym=newtemp();
                backpatch((yyvsp[(1) - (2)].exprVal)->truelist,nextquadlabel()+1);
                emit(assign,newexpr_constbool(1),NULL,(yyvsp[(1) - (2)].exprVal),nextquadlabel(),yylineno);
                emit(jump,NULL,NULL,NULL,nextquadlabel()+3,yylineno);
                backpatch((yyvsp[(1) - (2)].exprVal)->falselist,nextquadlabel()+1);
                emit(assign,newexpr_constbool(0),NULL,(yyvsp[(1) - (2)].exprVal),nextquadlabel(),yylineno);
            }
        }
    break;

  case 27:
#line 242 "parser.y"
    {
        if((yyvsp[(4) - (4)].exprVal)->type==boolexpr_e && apotimisi_not==1){
            (yyvsp[(4) - (4)].exprVal)->sym=newtemp();
            backpatch((yyvsp[(4) - (4)].exprVal)->truelist,nextquadlabel()+1);
            emit(assign,newexpr_constbool(1),NULL,(yyvsp[(4) - (4)].exprVal),nextquadlabel(),yylineno);
            emit(jump,NULL,NULL,NULL,nextquadlabel()+3,yylineno);
            backpatch((yyvsp[(4) - (4)].exprVal)->falselist,nextquadlabel()+1);
            emit(assign,newexpr_constbool(0),NULL,(yyvsp[(4) - (4)].exprVal),nextquadlabel(),yylineno);
        }
        (yyval.exprVal) = newexpr(boolexpr_e);
        (yyval.exprVal)->truelist = makelist(nextquadlabel());
        (yyval.exprVal)->falselist = makelist(nextquadlabel()+1);
        emit(if_noteq,(yyvsp[(1) - (4)].exprVal),(yyvsp[(4) - (4)].exprVal),NULL,nextquadlabel(),yylineno);
        emit(jump,NULL,NULL,NULL,nextquadlabel(),yylineno);
    }
    break;

  case 28:
#line 257 "parser.y"
    {
        apotimisi_and=1;
        if((yyvsp[(1) - (2)].exprVal)->type!=boolexpr_e){
            (yyvsp[(1) - (2)].exprVal)->truelist = makelist(nextquadlabel());
            (yyvsp[(1) - (2)].exprVal)->falselist = makelist(nextquadlabel()+1);
            emit(if_eq,(yyvsp[(1) - (2)].exprVal),newexpr_constbool(1),NULL,nextquadlabel(),yylineno);
            emit(jump,NULL,NULL,NULL,nextquadlabel(),yylineno);
            //backpatch($1->falselist, nextquadlabel()+3);
            tmpAnd1=(yyvsp[(1) - (2)].exprVal)->falselist->quadNo; 
        }
    }
    break;

  case 29:
#line 267 "parser.y"
    {
        (yyval.exprVal)=newexpr(boolexpr_e);                       /*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!AND*/
        backpatch((yyvsp[(1) - (5)].exprVal)->truelist,(yyvsp[(4) - (5)].intVal)+1); // true s1
        if((yyvsp[(5) - (5)].exprVal)->type!=boolexpr_e){
            (yyvsp[(5) - (5)].exprVal)->truelist = makelist(nextquadlabel());
            (yyvsp[(5) - (5)].exprVal)->falselist = makelist(nextquadlabel()+1);
            emit(if_eq,(yyvsp[(5) - (5)].exprVal),newexpr_constbool(1),NULL,nextquadlabel(),yylineno);
            emit(jump,NULL,NULL,NULL,nextquadlabel(),yylineno);
        }
        (yyval.exprVal)->truelist=(yyvsp[(5) - (5)].exprVal)->truelist;
        (yyval.exprVal)->falselist=merge((yyvsp[(1) - (5)].exprVal)->falselist,(yyvsp[(5) - (5)].exprVal)->falselist);
        tmpAnd2=(yyvsp[(5) - (5)].exprVal)->truelist->quadNo;
    }
    break;

  case 30:
#line 280 "parser.y"
    {
        apotimisi_or=1;
        if((yyvsp[(1) - (2)].exprVal)->type!=boolexpr_e){
            (yyvsp[(1) - (2)].exprVal)->truelist = makelist(nextquadlabel());
            (yyvsp[(1) - (2)].exprVal)->falselist = makelist(nextquadlabel()+1);
            emit(if_eq,(yyvsp[(1) - (2)].exprVal),newexpr_constbool(1),NULL,nextquadlabel(),yylineno);
            emit(jump,NULL,NULL,NULL,nextquadlabel(),yylineno);
        }
    }
    break;

  case 31:
#line 288 "parser.y"
    {
        (yyval.exprVal)=newexpr(boolexpr_e);                       /*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!AND*/
        backpatch((yyvsp[(1) - (5)].exprVal)->falselist,(yyvsp[(4) - (5)].intVal)+1); // true s1
        if((yyvsp[(5) - (5)].exprVal)->type!=boolexpr_e){
            (yyvsp[(5) - (5)].exprVal)->truelist = makelist(nextquadlabel());
            (yyvsp[(5) - (5)].exprVal)->falselist = makelist(nextquadlabel()+1);
            emit(if_eq,(yyvsp[(5) - (5)].exprVal),newexpr_constbool(1),NULL,nextquadlabel(),yylineno);
            emit(jump,NULL,NULL,NULL,nextquadlabel(),yylineno);
        }
        (yyval.exprVal)->truelist=merge((yyvsp[(1) - (5)].exprVal)->truelist,(yyvsp[(5) - (5)].exprVal)->truelist);
        (yyval.exprVal)->falselist=(yyvsp[(5) - (5)].exprVal)->falselist;
        backpatch((yyvsp[(1) - (5)].exprVal)->truelist,nextquadlabel()+1);
    }
    break;

  case 32:
#line 301 "parser.y"
    {(yyval.exprVal)=(yyvsp[(1) - (1)].exprVal);}
    break;

  case 33:
#line 302 "parser.y"
    {(yyval.exprVal)=(yyvsp[(1) - (1)].exprVal);}
    break;

  case 34:
#line 305 "parser.y"
    { (yyval.exprVal)=(yyvsp[(2) - (3)].exprVal); }
    break;

  case 35:
#line 306 "parser.y"
    { 
        check_arith((yyvsp[(2) - (2)].exprVal),"unary minus");
        (yyval.exprVal)=newexpr(arithexpr_e);
        (yyval.exprVal)->sym=newtemp();
        emit(uminus,(yyvsp[(2) - (2)].exprVal),NULL,(yyval.exprVal),nextquadlabel(),yylineno);
    }
    break;

  case 36:
#line 312 "parser.y"
    {                        /*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!NOT*/
        apot_not=1;
        (yyval.exprVal)=newexpr(boolexpr_e);
        apotimisi_not=1;
        (yyval.exprVal)->sym=(yyvsp[(2) - (2)].exprVal)->sym;
        if((yyvsp[(2) - (2)].exprVal)->type==boolexpr_e){
            (yyval.exprVal)->truelist=(yyvsp[(2) - (2)].exprVal)->falselist;
            (yyval.exprVal)->falselist=(yyvsp[(2) - (2)].exprVal)->truelist;
        }
        else{
            (yyval.exprVal)->truelist=makelist(nextquadlabel()+1);
            (yyval.exprVal)->falselist=makelist(nextquadlabel());
            emit(if_eq,(yyvsp[(2) - (2)].exprVal),newexpr_constbool(1),NULL,nextquadlabel(),yylineno);
            emit(jump,NULL,NULL,NULL,nextquadlabel(),yylineno);
        } 
    }
    break;

  case 37:
#line 328 "parser.y"
    {
        check_arith((yyvsp[(2) - (2)].exprVal),"++lvalue");
        if((yyvsp[(2) - (2)].exprVal)->type==tableitem_e){
            (yyval.exprVal)=emit_iftableitem((yyvsp[(2) - (2)].exprVal));
            emit(add,(yyval.exprVal),newexpr_constnum(1),(yyval.exprVal),nextquadlabel(),yylineno);
        }
        else{
            emit(add,(yyvsp[(2) - (2)].exprVal),newexpr_constnum(1),(yyvsp[(2) - (2)].exprVal),nextquadlabel(),yylineno);
            (yyval.exprVal)=newexpr(arithexpr_e);
            (yyval.exprVal)->sym=newtemp();
            emit(assign,(yyvsp[(2) - (2)].exprVal),NULL,(yyval.exprVal),nextquadlabel(),yylineno);
        }
    }
    break;

  case 38:
#line 341 "parser.y"
    {
        check_arith((yyvsp[(1) - (2)].exprVal),"lvalue++");
        (yyval.exprVal)=newexpr(var_e);
        (yyval.exprVal)->sym=newtemp();
        if((yyvsp[(1) - (2)].exprVal)->type==tableitem_e){
            struct expr* val=emit_iftableitem((yyvsp[(1) - (2)].exprVal));
            emit(assign,val,NULL,(yyval.exprVal),nextquadlabel(),yylineno);
            emit(add,val,newexpr_constnum(1),val,nextquadlabel(),yylineno);
            emit(tablesetelem, (yyvsp[(1) - (2)].exprVal),(yyvsp[(1) - (2)].exprVal)->index,val,nextquadlabel(),yylineno);
        }
        else{
            emit(assign,(yyvsp[(1) - (2)].exprVal),NULL,(yyval.exprVal),nextquadlabel(),yylineno);
            emit(add,(yyvsp[(1) - (2)].exprVal),newexpr_constnum(1),(yyvsp[(1) - (2)].exprVal),nextquadlabel(),yylineno);
        }
    }
    break;

  case 39:
#line 356 "parser.y"
    {
        check_arith((yyvsp[(2) - (2)].exprVal),"--lvalue");
        if((yyvsp[(2) - (2)].exprVal)->type==tableitem_e){
            (yyval.exprVal)=emit_iftableitem((yyvsp[(2) - (2)].exprVal));
            emit(sub,(yyval.exprVal),newexpr_constnum(1),(yyval.exprVal),nextquadlabel(),yylineno);
        }
        else{
            emit(sub,(yyvsp[(2) - (2)].exprVal),newexpr_constnum(1),(yyvsp[(2) - (2)].exprVal),nextquadlabel(),yylineno);
            (yyval.exprVal)=newexpr(arithexpr_e);
            (yyval.exprVal)->sym=newtemp();
            emit(assign,(yyvsp[(2) - (2)].exprVal),NULL,(yyval.exprVal),nextquadlabel(),yylineno);
        }
    }
    break;

  case 40:
#line 369 "parser.y"
    {
        check_arith((yyvsp[(1) - (2)].exprVal),"lvalue--");
        (yyval.exprVal)=newexpr(var_e);
        (yyval.exprVal)->sym=newtemp();
        if((yyvsp[(1) - (2)].exprVal)->type==tableitem_e){
            struct expr* val=emit_iftableitem((yyvsp[(1) - (2)].exprVal));
            emit(assign,val,NULL,(yyval.exprVal),nextquadlabel(),yylineno);
            emit(sub,val,newexpr_constnum(1),val,nextquadlabel(),yylineno);
            emit(tablesetelem, (yyvsp[(1) - (2)].exprVal),(yyvsp[(1) - (2)].exprVal)->index,val,nextquadlabel(),yylineno);
        }
        else{
            emit(assign,(yyvsp[(1) - (2)].exprVal),NULL,(yyval.exprVal),nextquadlabel(),yylineno);
            emit(sub,(yyvsp[(1) - (2)].exprVal),newexpr_constnum(1),(yyvsp[(1) - (2)].exprVal),nextquadlabel(),yylineno);
        }
    }
    break;

  case 41:
#line 384 "parser.y"
    { (yyval.exprVal)=(yyvsp[(1) - (1)].exprVal); }
    break;

  case 42:
#line 388 "parser.y"
    {
    if((yyvsp[(3) - (3)].exprVal)->type==boolexpr_e){
        (yyvsp[(3) - (3)].exprVal)->sym=newtemp();
        backpatch((yyvsp[(3) - (3)].exprVal)->truelist,nextquadlabel()+1);
        emit(assign,newexpr_constbool(1),NULL,(yyvsp[(3) - (3)].exprVal),nextquadlabel(),yylineno);
        emit(jump,NULL,NULL,NULL,nextquadlabel()+3,yylineno);
        backpatch((yyvsp[(3) - (3)].exprVal)->falselist,nextquadlabel()+1);
        emit(assign,newexpr_constbool(0),NULL,(yyvsp[(3) - (3)].exprVal),nextquadlabel(),yylineno);
    }
    if((yyvsp[(1) - (3)].exprVal)->type==tableitem_e){
        emit(tablesetelem,(yyvsp[(1) - (3)].exprVal)->index,(yyvsp[(3) - (3)].exprVal),(yyvsp[(1) - (3)].exprVal),nextquadlabel(),yylineno);
        (yyval.exprVal)=emit_iftableitem((yyvsp[(1) - (3)].exprVal));
        (yyval.exprVal)->type=assignexpr_e;
    }
    else{   
        emit(assign,(yyvsp[(3) - (3)].exprVal),NULL,(yyvsp[(1) - (3)].exprVal),nextquadlabel(),yylineno);
        (yyval.exprVal)=newexpr(assignexpr_e);
        (yyval.exprVal)->sym=newtemp();
        emit(assign,(yyvsp[(1) - (3)].exprVal),NULL,(yyval.exprVal),nextquadlabel(),yylineno);
    }
}
    break;

  case 43:
#line 411 "parser.y"
    {(yyval.exprVal)=emit_iftableitem((yyvsp[(1) - (1)].exprVal));}
    break;

  case 45:
#line 413 "parser.y"
    {(yyval.exprVal)=(yyvsp[(1) - (1)].exprVal);}
    break;

  case 46:
#line 414 "parser.y"
    {
            (yyval.exprVal)=newexpr(programfunc_e);
            (yyval.exprVal)->sym=(yyvsp[(2) - (3)].tptr);
        }
    break;

  case 47:
#line 418 "parser.y"
    {(yyval.exprVal)=(yyvsp[(1) - (1)].exprVal);}
    break;

  case 48:
#line 423 "parser.y"
    {  
        Node sym;
        int i;
        sym=SymTable_Lookup(p,(yyvsp[(1) - (1)].stringVal),GLOBAL,scope);
        if(sym==NULL){
            sym=SymTable_Insert(p,(yyvsp[(1) - (1)].stringVal),1,GLOBAL,scope,yylineno); 
            sym->space=currscopespace();
            sym->offset=currscopeoffset();
            inccurrsopeoffset();
        }
        (yyval.exprVal)=lvalue_expr(sym);
        (yyval.exprVal)->sym->name=(yyvsp[(1) - (1)].stringVal);
}
    break;

  case 49:
#line 436 "parser.y"
    { 
            Node sym;
            if(SymTable_Lookup(p,(yyvsp[(2) - (2)].stringVal),LIBFUNC,-1)!=NULL){
                printf("Error: Collision with %s library function. Cannot declare local %s.\n",(yyvsp[(2) - (2)].stringVal),(yyvsp[(2) - (2)].stringVal));
                break;
            }
            sym=SymTable_Lookup(p,(yyvsp[(2) - (2)].stringVal),LOCAL,scope);
            if(sym==NULL){      
                sym=SymTable_Insert(p,(yyvsp[(2) - (2)].stringVal),1,LOCAL,scope,yylineno);
                sym->space=currscopespace();
                sym->offset=currscopeoffset();
                inccurrsopeoffset();
            }
            (yyval.exprVal)=lvalue_expr(sym);
            (yyval.exprVal)->sym->name=(yyvsp[(2) - (2)].stringVal);
}
    break;

  case 50:
#line 452 "parser.y"
    {
            if(SymTable_Lookup(p,(yyvsp[(2) - (2)].stringVal),GLOBAL,0)==NULL){ 
                printf("Error: No global variable %s exists.\n",(yyvsp[(2) - (2)].stringVal));
            }
        }
    break;

  case 52:
#line 461 "parser.y"
    {
    (yyval.exprVal)=member_item((yyvsp[(1) - (3)].exprVal),(yyvsp[(3) - (3)].stringVal));
}
    break;

  case 53:
#line 464 "parser.y"
    {
    if((yyvsp[(3) - (4)].exprVal)->type==boolexpr_e){
        (yyvsp[(3) - (4)].exprVal)->sym=newtemp();
        backpatch((yyvsp[(3) - (4)].exprVal)->truelist,nextquadlabel()+1);
        emit(assign,newexpr_constbool(1),NULL,(yyvsp[(3) - (4)].exprVal),nextquadlabel(),yylineno);
        emit(jump,NULL,NULL,NULL,nextquadlabel()+3,yylineno);
        backpatch((yyvsp[(3) - (4)].exprVal)->falselist,nextquadlabel()+1);
        emit(assign,newexpr_constbool(0),NULL,(yyvsp[(3) - (4)].exprVal),nextquadlabel(),yylineno);
    }
    (yyvsp[(1) - (4)].exprVal)=emit_iftableitem((yyvsp[(1) - (4)].exprVal));
    (yyval.exprVal)=newexpr(tableitem_e);
    (yyval.exprVal)->sym=(yyvsp[(1) - (4)].exprVal)->sym;
    (yyval.exprVal)->index=(yyvsp[(3) - (4)].exprVal);
}
    break;

  case 55:
#line 479 "parser.y"
    {
    emit(tablegetelem,(yyvsp[(1) - (4)].exprVal),(yyvsp[(3) - (4)].exprVal),(yyvsp[(1) - (4)].exprVal),nextquadlabel(),yylineno);
}
    break;

  case 56:
#line 485 "parser.y"
    {(yyval.exprVal)=make_call((yyvsp[(1) - (4)].exprVal),(yyvsp[(3) - (4)].exprVal));}
    break;

  case 57:
#line 486 "parser.y"
    {
    struct expr*temp=(yyvsp[(2) - (2)].call)->elist;
    if(temp!=NULL){
        while (temp->next!=NULL) {
            temp=temp->next;
        }
        (yyvsp[(1) - (2)].exprVal)=emit_iftableitem((yyvsp[(1) - (2)].exprVal));
        if((yyvsp[(2) - (2)].call)->method){
            temp->next=(yyvsp[(1) - (2)].exprVal);
            (yyvsp[(1) - (2)].exprVal)=emit_iftableitem(member_item((yyvsp[(1) - (2)].exprVal),(yyvsp[(2) - (2)].call)->name));
        }
        (yyval.exprVal)=make_call((yyvsp[(1) - (2)].exprVal),(yyvsp[(2) - (2)].call)->elist);
    }
}
    break;

  case 58:
#line 500 "parser.y"
    {
        struct expr* temp=newexpr(programfunc_e);
        temp->sym=(yyvsp[(2) - (6)].tptr);
        (yyval.exprVal)=make_call(temp,(yyvsp[(5) - (6)].exprVal));
    }
    break;

  case 61:
#line 513 "parser.y"
    {
    struct call* c=(struct call*)malloc(sizeof(struct call));
    memset(c,0,sizeof(struct call));
    (yyval.call)=c;
    (yyval.call)->elist=(yyvsp[(2) - (3)].exprVal);
    (yyval.call)->method=0;
    (yyval.call)->name=NULL;
}
    break;

  case 62:
#line 524 "parser.y"
    {
    struct call* c=(struct call*)malloc(sizeof(struct call));
    memset(c,0,sizeof(struct call));
    (yyval.call)=c;
    (yyval.call)->elist=(yyvsp[(4) - (5)].exprVal);
    (yyval.call)->method=1;
    (yyval.call)->name=strdup((yyvsp[(2) - (5)].stringVal));
}
    break;

  case 63:
#line 534 "parser.y"
    {
    if((yyvsp[(1) - (1)].exprVal)->type==boolexpr_e){
        (yyvsp[(1) - (1)].exprVal)->sym=newtemp();
        backpatch((yyvsp[(1) - (1)].exprVal)->truelist,nextquadlabel()+1);
        emit(assign,newexpr_constbool(1),NULL,(yyvsp[(1) - (1)].exprVal),nextquadlabel(),yylineno);
        emit(jump,NULL,NULL,NULL,nextquadlabel()+3,yylineno);
        backpatch((yyvsp[(1) - (1)].exprVal)->falselist,nextquadlabel()+1);
        emit(assign,newexpr_constbool(0),NULL,(yyvsp[(1) - (1)].exprVal),nextquadlabel(),yylineno);
    }
}
    break;

  case 64:
#line 544 "parser.y"
    {
    if((yyvsp[(3) - (3)].exprVal)->type==boolexpr_e){
        (yyvsp[(3) - (3)].exprVal)->sym=newtemp();
        backpatch((yyvsp[(3) - (3)].exprVal)->truelist,nextquadlabel()+1);
        emit(assign,newexpr_constbool(1),NULL,(yyvsp[(3) - (3)].exprVal),nextquadlabel(),yylineno);
        emit(jump,NULL,NULL,NULL,nextquadlabel()+3,yylineno);
        backpatch((yyvsp[(3) - (3)].exprVal)->falselist,nextquadlabel()+1);
        emit(assign,newexpr_constbool(0),NULL,(yyvsp[(3) - (3)].exprVal),nextquadlabel(),yylineno);
    }
    struct expr*tmp=(yyvsp[(1) - (3)].exprVal);
    while(tmp->next != NULL){
        tmp=tmp->next;
    }
    tmp->next=(yyvsp[(3) - (3)].exprVal);
}
    break;

  case 65:
#line 559 "parser.y"
    {(yyval.exprVal)=newexpr_constnil();}
    break;

  case 66:
#line 563 "parser.y"
    {
    int i=0;
    struct expr*t= newexpr(newtable_e);
    t->sym=newtemp();
    emit(tablecreate,t,NULL,NULL,nextquadlabel(),yylineno);
    struct expr*tmp=(yyvsp[(2) - (3)].exprVal);
    if(tmp->type!=nil_e){
        while(tmp!=NULL){
            emit(tablesetelem,newexpr_constnum(i++),tmp,t,nextquadlabel(),yylineno);
            tmp=tmp->next;
        }
    }
    (yyval.exprVal)=t;
}
    break;

  case 67:
#line 577 "parser.y"
    {
    int i=0;
    struct expr*t= newexpr(newtable_e);
    t->sym=newtemp();
    emit(tablecreate,t,NULL,NULL,nextquadlabel(),yylineno);
    struct expr*tmp=(yyvsp[(2) - (3)].exprVal);
    if(tmp->type!=nil_e){
        while(tmp!=NULL){
            emit(tablesetelem,tmp->index,tmp->value,t,nextquadlabel(),yylineno);
            tmp=tmp->next;
        }
    }
    (yyval.exprVal)=t;
}
    break;

  case 69:
#line 595 "parser.y"
    {
            struct expr*tmp=(yyvsp[(1) - (3)].exprVal);
            while(tmp->next != NULL){
                tmp = tmp->next;
            }
            tmp->next=(yyvsp[(3) - (3)].exprVal);
            (yyval.exprVal)=(yyvsp[(1) - (3)].exprVal);
}
    break;

  case 70:
#line 604 "parser.y"
    {
    if((yyvsp[(2) - (5)].exprVal)->type==boolexpr_e){
        (yyvsp[(2) - (5)].exprVal)->sym=newtemp();
        backpatch((yyvsp[(2) - (5)].exprVal)->truelist,nextquadlabel()+1);
        emit(assign,newexpr_constbool(1),NULL,(yyvsp[(2) - (5)].exprVal),nextquadlabel(),yylineno);
        emit(jump,NULL,NULL,NULL,nextquadlabel()+3,yylineno);
        backpatch((yyvsp[(2) - (5)].exprVal)->falselist,nextquadlabel()+1);
        emit(assign,newexpr_constbool(0),NULL,(yyvsp[(2) - (5)].exprVal),nextquadlabel(),yylineno);
    }
    (yyval.exprVal)=newexpr(tableitem_e);
    (yyval.exprVal)->index=(yyvsp[(2) - (5)].exprVal);
    (yyval.exprVal)->value=(yyvsp[(4) - (5)].exprVal);
}
    break;

  case 71:
#line 619 "parser.y"
    {
    exitscopespace();
    (yyvsp[(1) - (3)].tptr)->value.funcVal->args=(yyvsp[(3) - (3)].intVal);
    int quadNo=pop(&topLabel);
    patchlabel(quadNo,nextquadlabel()+2);
    int offset=pop_and_top();
    restorecurrscopeoffset(offset);
    (yyval.tptr)=(yyvsp[(1) - (3)].tptr);
    emit(funcend,NULL,NULL,lvalue_expr((yyvsp[(1) - (3)].tptr)),nextquadlabel(),yylineno);
}
    break;

  case 72:
#line 631 "parser.y"
    { (yyval.stringVal)=(yyvsp[(1) - (1)].stringVal); }
    break;

  case 73:
#line 632 "parser.y"
    { (yyval.stringVal) = newtempfuncname(); }
    break;

  case 74:
#line 635 "parser.y"
    {
    if(SymTable_Lookup(p,(yyvsp[(2) - (2)].stringVal),LIBFUNC,-1)!=NULL) {
        printf("Error: User function %s, collision with %s library function.\n",(yyvsp[(2) - (2)].stringVal),(yyvsp[(2) - (2)].stringVal));
    }
    else if(SymTable_Lookup(p,(yyvsp[(2) - (2)].stringVal),USERFUNC,scope)!=NULL) {
        printf("Error: %s already defined.\n", (yyvsp[(2) - (2)].stringVal));
    }
    else {
        (yyval.tptr)=SymTable_Insert(p,(yyvsp[(2) - (2)].stringVal),1,USERFUNC,scope,yylineno);
        (yyval.tptr)->value.funcVal->iaddress=nextquadlabel();
        pushLabel(&topLabel,nextquadlabel());
        emit(jump,NULL,NULL,NULL,nextquadlabel(),yylineno);
        emit(funcstart,NULL,NULL,lvalue_expr((yyval.tptr)),nextquadlabel(),yylineno);
        pushOffset(currscopeoffset());
        enterscopespace();
        resetformalargoffset();
    }
    int tmp_scope=scope;
    scope++;
    if(scope>max_scope) max_scope=scope;
}
    break;

  case 75:
#line 658 "parser.y"
    {
    if(flag!=1) {
        if(SymTable_Lookup(p,(yyvsp[(2) - (3)].stringVal),FORMAL,scope)==0){
            SymTable_Insert(p,(yyvsp[(2) - (3)].stringVal),1,FORMAL,tmp_scope,yylineno);
            tmp_scope++;
        }
    }
    enterscopespace();
    resetfunctionoffset();
}
    break;

  case 76:
#line 670 "parser.y"
    {
    SymTable_Hide(p,scope); 
    scope--; 
    tmp_scope--;
    (yyval.intVal)=currscopeoffset();
    exitscopespace();
}
    break;

  case 78:
#line 682 "parser.y"
    { (yyval.exprVal)=newexpr_constnum((yyvsp[(1) - (1)].intVal)); }
    break;

  case 79:
#line 683 "parser.y"
    { (yyval.exprVal)=newexpr_conststring((yyvsp[(1) - (1)].stringVal)); }
    break;

  case 80:
#line 684 "parser.y"
    { (yyval.exprVal)=newexpr_constnil(); }
    break;

  case 81:
#line 685 "parser.y"
    { (yyval.exprVal)=newexpr_constbool(1); }
    break;

  case 82:
#line 686 "parser.y"
    { (yyval.exprVal)=newexpr_constbool(0); }
    break;

  case 83:
#line 690 "parser.y"
    {   
        flag=0;
        if(SymTable_Lookup(p,(yyvsp[(1) - (1)].stringVal),LIBFUNC,-1)!=NULL){
            printf("Error: Collision with %s library function. Cannot be used as formal.\n",(yyvsp[(1) - (1)].stringVal));
            break;
        }
        if(SymTable_Lookup(p,(yyvsp[(1) - (1)].stringVal),FORMAL,scope)==NULL){
            SymTable_Insert(p,(yyvsp[(1) - (1)].stringVal),1,FORMAL,scope,yylineno);
        }
}
    break;

  case 84:
#line 700 "parser.y"
    {  
        flag=0;
        if(SymTable_Lookup(p,(yyvsp[(3) - (3)].stringVal),LIBFUNC,-1)!=NULL){
            printf("Error: Collision with %s library function. Cannot be used as formal.\n",(yyvsp[(3) - (3)].stringVal));
            break;
        }
        if(SymTable_Lookup(p,(yyvsp[(3) - (3)].stringVal),FORMAL,scope)==NULL){
            SymTable_Insert(p,(yyvsp[(3) - (3)].stringVal),1,FORMAL,scope,yylineno);
        }    
        else printf("Error: Variable %s already defined at line %d.\n",(yyvsp[(3) - (3)].stringVal),yylineno);
}
    break;

  case 85:
#line 711 "parser.y"
    {flag=1;}
    break;

  case 86:
#line 714 "parser.y"
    {
    struct expr* tmp1=newexpr_constbool(1);
    struct expr* tmp2=newexpr(var_e);
    struct expr* tmp3=newexpr_constbool(0);
    (yyval.intVal)=nextquadlabel();
    if((yyvsp[(3) - (4)].exprVal)->type==boolexpr_e){
        pushIf(nextquadlabel()-2,&topIf1);
        tmp2->sym=newtemp();
        emit(assign,tmp1,NULL,tmp2,nextquadlabel(),yylineno);
        int pop=popIf(&topIf1);
        patchlabel(pop,nextquadlabel());
        patchlabel(pop+1,nextquadlabel()+2);
        emit(jump,NULL,NULL,0,nextquadlabel()+3,yylineno);
        emit(assign,tmp3,NULL,tmp2,nextquadlabel(),yylineno);
        emit(if_eq, tmp2, tmp1,NULL,nextquadlabel()+3,yylineno);  
        pushIf(nextquadlabel(),&topIf2);
        emit(jump,NULL,NULL,0,nextquadlabel(),yylineno);
    }
    else{
        emit(if_eq,(yyvsp[(3) - (4)].exprVal),tmp1,NULL,nextquadlabel()+3,yylineno);  
        pushIf(nextquadlabel(),&topIf2);
        emit(jump,NULL,NULL,0,nextquadlabel(),yylineno);
    }
}
    break;

  case 87:
#line 740 "parser.y"
    { 
    (yyval.intVal)=nextquadlabel();
    emit(jump,NULL,NULL,NULL,nextquadlabel(),yylineno); // an den isxuei to if paei sto else
    pushIf(nextquadlabel(),&topIf3);
}
    break;

  case 88:
#line 746 "parser.y"
    { 
    int pop=popIf(&topIf2);
    patchlabel(pop,nextquadlabel()+1);
}
    break;

  case 89:
#line 750 "parser.y"
    { 
    int pop=popIf(&topIf2);
    int pop1=popIf(&topIf3);
    patchlabel((yyvsp[(3) - (4)].intVal),nextquadlabel()+1);
    patchlabel(pop,pop1+1);
}
    break;

  case 90:
#line 759 "parser.y"
    {
    (yyval.intVal)=nextquadlabel();
    pushLoop(nextquadlabel()+1,&topWhile1);
}
    break;

  case 91:
#line 764 "parser.y"
    {
    (yyval.intVal)=nextquadlabel();
    struct expr* tmp1=newexpr_constbool(1);
    struct expr* tmp2=newexpr(var_e);
    struct expr* tmp3=newexpr_constbool(0);

    if((yyvsp[(2) - (3)].exprVal)->type==boolexpr_e){
        pushLoop(nextquadlabel()-2,&topWhile);
        tmp2->sym=newtemp();
        emit(assign,tmp1,NULL,tmp2,nextquadlabel(),yylineno);
        int pop=popLoop(&topWhile);
        patchlabel(pop,nextquadlabel());
        patchlabel(pop+1,nextquadlabel()+2);
        emit(jump,NULL,NULL,0,nextquadlabel()+3,yylineno);
        emit(assign,tmp3,NULL,tmp2,nextquadlabel(),yylineno);
        if(apotimisi_and==1 && apot_not==0){
            patchlabel(tmpAnd1,nextquadlabel());
            apotimisi_and=0;
        }
        pushLoop(nextquadlabel(),&topWhile2);
        emit(if_eq,tmp2,tmp1,NULL,nextquadlabel()+3,yylineno);
        pushLoop(nextquadlabel(),&topWhile3);
        emit(jump,NULL,NULL,NULL,nextquadlabel(),yylineno);
    }
    else {
        emit(if_eq,(yyvsp[(2) - (3)].exprVal),tmp1,NULL,nextquadlabel(),yylineno);
        pushLoop(nextquadlabel(),&topWhile3);
        emit(jump,NULL,NULL,NULL,nextquadlabel(),yylineno);
        pushLoop(nextquadlabel()+1,&topWhile2);
    }
}
    break;

  case 92:
#line 796 "parser.y"
    {
    int pop1,pop2,pop3;
    pop1=popLoop(&topWhile1);
    pop2=popLoop(&topWhile2);
    pop3=popLoop(&topWhile3);
    if(apotimisi_or==1 && apot_not==0)patchlabel(pop1,3);
    else patchlabel(pop1,pop2);
    int c=popC();
    if (c!=-1){
        patchlabel(c,pop1);
    }
    emit(jump,NULL,NULL,newexpr_constnum((yyvsp[(1) - (3)].intVal)),pop1,yylineno);
    patchlabel((yyvsp[(2) - (3)].intVal),pop2);
    patchlabel(pop3,nextquadlabel()+1);
    int b=popB();
    if(b!=-1) {
        patchlabel(b,nextquadlabel()+1);
    }
}
    break;

  case 93:
#line 816 "parser.y"
    { 
    (yyval.intVal)=nextquadlabel();
    emit(jump,NULL,NULL,NULL,0,yylineno); 
    }
    break;

  case 94:
#line 822 "parser.y"
    { (yyval.intVal)=nextquadlabel(); }
    break;

  case 95:
#line 824 "parser.y"
    {
    struct stmt_t* c=(struct stmt_t*)malloc(sizeof(struct stmt_t));
    struct expr* tmp1=newexpr_constbool(1);
    struct expr* tmp2=newexpr(var_e);
    struct expr* tmp3=newexpr_constbool(0);
    if((yyvsp[(6) - (7)].exprVal)->type==boolexpr_e){
        pushLoop(nextquadlabel()-2,&topFor);
        tmp2->sym=newtemp();
        emit(assign,tmp1,NULL,tmp2,nextquadlabel(),yylineno);
        int pop=popLoop(&topFor);
        patchlabel(pop,nextquadlabel());
        patchlabel(pop+1,nextquadlabel()+2);
        emit(jump,NULL,NULL,0,nextquadlabel()+3,yylineno);
        emit(assign,tmp3,NULL,tmp2,nextquadlabel(),yylineno);
        if(mikrotero==1 ){
            patchlabel(tmpMikr,nextquadlabel());
            apotimisi_and=0;
        }
        pushLoop(nextquadlabel(),&topFor2);
        emit(if_eq,tmp2,tmp1,NULL,nextquadlabel()+3,yylineno);
    }
    else{
        pushLoop(nextquadlabel(),&topFor2);
        emit(if_eq,(yyvsp[(6) - (7)].exprVal),tmp1,NULL,nextquadlabel(),yylineno);
    }
    struct forloop* f= (struct forloop*) malloc(sizeof(struct forloop)); 
    (yyval.forVal)=f;
    (yyval.forVal)->test=(yyvsp[(5) - (7)].intVal);
    (yyval.forVal)->enter=nextquadlabel();
}
    break;

  case 96:
#line 855 "parser.y"
    {
   patchlabel((yyvsp[(1) - (7)].forVal)->enter,(yyvsp[(5) - (7)].intVal)+1);
   patchlabel((yyvsp[(2) - (7)].intVal),nextquadlabel()+1);
   patchlabel((yyvsp[(5) - (7)].intVal),(yyvsp[(1) - (7)].forVal)->test+1);
   patchlabel((yyvsp[(7) - (7)].intVal),(yyvsp[(2) - (7)].intVal)+2);
   int c=popC();
    if (c!=-1){
        patchlabel(c,(yyvsp[(2) - (7)].intVal)+2);
    }
   patchlabel(popLoop(&topFor2),(yyvsp[(5) - (7)].intVal)+2);
   int b=popB();
   if(b!=-1) patchlabel(b,nextquadlabel()+1);
}
    break;

  case 97:
#line 869 "parser.y"
    {
    struct stmt_t* b=(struct stmt_t*)malloc(sizeof(struct stmt_t));
    b->quadNo=nextquadlabel();
    pushB(b,NULL);
    emit(jump,NULL,NULL,NULL,nextquadlabel(),yylineno);
}
    break;

  case 98:
#line 876 "parser.y"
    {
    struct stmt_t* c=(struct stmt_t*)malloc(sizeof(struct stmt_t));
    c->quadNo=nextquadlabel();
    pushC(c,NULL);
    emit(jump,NULL,NULL,NULL,nextquadlabel(),yylineno);
}
    break;

  case 99:
#line 883 "parser.y"
    {
    if(isInFunc==0)printf("Return outside function.\n");
    else{
        isInFunc=0;
        struct expr* tmp=newexpr_constnil();
        emit(ret,NULL,NULL,tmp,nextquadlabel(),yylineno);
        emit(jump,NULL,NULL,NULL,nextquadlabel()+2,yylineno);
    }
}
    break;

  case 100:
#line 892 "parser.y"
    {
    if(isInFunc==0)printf("Return outside function.\n");
    else{
    isInFunc=0;
    if((yyvsp[(2) - (3)].exprVal)->type==boolexpr_e){
        (yyvsp[(2) - (3)].exprVal)->sym=newtemp();
        backpatch((yyvsp[(2) - (3)].exprVal)->truelist,nextquadlabel()+1);
        emit(assign,newexpr_constbool(1),NULL,(yyvsp[(2) - (3)].exprVal),nextquadlabel(),yylineno);
        emit(jump,NULL,NULL,NULL,nextquadlabel()+3,yylineno);
        backpatch((yyvsp[(2) - (3)].exprVal)->falselist,nextquadlabel()+1);
        emit(assign,newexpr_constbool(0),NULL,(yyvsp[(2) - (3)].exprVal),nextquadlabel(),yylineno);
    }
    emit(ret,NULL,NULL,(yyvsp[(2) - (3)].exprVal),nextquadlabel(),yylineno);
    (yyval.exprVal)=(yyvsp[(2) - (3)].exprVal);
    emit(jump,NULL,NULL,NULL,nextquadlabel()+2,yylineno);
    }
}
    break;


/* Line 1267 of yacc.c.  */
#line 2761 "parser.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 914 "parser.y"

void Quad_Print(){
    FILE *fptr = fopen("quads.txt", "a");
    if(fptr == NULL){
		printf("Error could not open file\n");
    }
    fprintf(fptr,"\n%-6s %-15s %-10s %-10s %-10s %-10s\n", "quad#", "opcode", "result", "arg1", "arg2","label");
    for(int i=0;i<currQuad;i++){
        if (quads[i].op == 0) {
            if (quads[i].arg1->type==constnum_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10d\n", i+1, "assign", quads[i].result->sym->name, (int)quads[i].arg1->numConst);
            }
            else if(quads[i].arg1->type==boolexpr_e){
                if(quads[i].arg1->boolConst=='1'){ 
                    fprintf(fptr,"%-6d %-15s %-10s %-10s\n", i+1, "assign",quads[i].result->sym->name , "'true'");
                }
                else if(quads[i].arg1->boolConst=='0'){
                    fprintf(fptr,"%-6d %-15s %-10s %-10s\n", i+1, "assign",quads[i].result->sym->name , "'false'");
                }  
                else  fprintf(fptr,"%-6d %-15s %-10s %-10s\n", i+1, "assign",quads[i].result->sym->name , quads[i].arg1->sym->name);     
            }
            else if(quads[i].arg1->type==nil_e){  
                fprintf(fptr,"%-6d %-15s %-10s %-10s\n", i+1, "assign", quads[i].result->sym->name, "nil");
            }
            else if(quads[i].arg1->type==conststring_e) { 
                fprintf(fptr,"%-6d %-15s %-10s %-10s\n", i+1, "assign", quads[i].result->sym->name, quads[i].arg1->strConst);
            }
            else if(quads[i].arg1->type==constbool_e && quads[i].arg1->boolConst==1) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s\n", i+1, "assign", quads[i].result->sym->name, "'true'");
            }
            else if(quads[i].arg1->type==constbool_e && quads[i].arg1->boolConst==0) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s\n", i+1, "assign", quads[i].result->sym->name, "'false'");
            }
            else if (quads[i].arg1->type==var_e) { 
                fprintf(fptr,"%-6d %-15s %-10s %-10s\n", i+1, "assign", quads[i].result->sym->name, quads[i].arg1->sym->name);
            }
            else if (quads[i].arg1->type==newtable_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s\n", i+1, "assign", quads[i].result->sym->name, quads[i].arg1->sym->name);
            }
            else if (quads[i].arg1->type==assignexpr_e) { 
                fprintf(fptr,"%-6d %-15s %-10s %-10s\n", i+1, "assign", quads[i].result->sym->name, quads[i].arg1->sym->name);
            }
            
        } 
        else if (quads[i].op == 1) {
            if (quads[i].arg1->type == constnum_e && quads[i].arg2->type == constnum_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10d %-10d\n", i+1, "add", quads[i].result->sym->name, (int)quads[i].arg1->numConst, (int)quads[i].arg2->numConst);
            }
            else if (quads[i].arg1->type == var_e && quads[i].arg2->type == constnum_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10d\n", i+1, "add", quads[i].result->sym->name, quads[i].arg1->sym->name, (int)quads[i].arg2->numConst);
            }
            else if (quads[i].arg1->type == constnum_e && quads[i].arg2->type == var_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10d %-10s\n", i+1, "add", quads[i].result->sym->name, (int)quads[i].arg1->numConst, quads[i].arg2->sym->name);
            }
            else if (quads[i].arg1->type == var_e && quads[i].arg2->type == var_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "add", quads[i].result->sym->name, quads[i].arg1->sym->name, quads[i].arg2->sym->name);
            }
            else if (quads[i].arg1->type == var_e && quads[i].arg2->type == arithexpr_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "add", quads[i].result->sym->name, quads[i].arg1->sym->name, quads[i].arg2->sym->name);
            }
            else if (quads[i].arg1->type == arithexpr_e && quads[i].arg2->type == var_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "add", quads[i].result->sym->name, quads[i].arg1->sym->name, quads[i].arg2->sym->name);
            }
            else if (quads[i].arg1->type == arithexpr_e && quads[i].arg2->type == arithexpr_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "add", quads[i].result->sym->name, quads[i].arg1->sym->name, quads[i].arg2->sym->name);
            }
        }
        else if(quads[i].op==2) {
            if (quads[i].arg1->type == constnum_e && quads[i].arg2->type == constnum_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10d %-10d\n", i+1, "sub", quads[i].result->sym->name, (int)quads[i].arg1->numConst, (int)quads[i].arg2->numConst);
            }
            else if (quads[i].arg1->type == var_e && quads[i].arg2->type == constnum_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10d\n", i+1, "sub", quads[i].result->sym->name, quads[i].arg1->sym->name, (int)quads[i].arg2->numConst);
            }
            else if (quads[i].arg1->type == constnum_e && quads[i].arg2->type == var_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10d %-10s\n", i+1, "sub", quads[i].result->sym->name, (int)quads[i].arg1->numConst, quads[i].arg2->sym->name);
            }
            else if (quads[i].arg1->type == var_e && quads[i].arg2->type == var_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "sub", quads[i].result->sym->name, quads[i].arg1->sym->name, quads[i].arg2->sym->name);
            }
            else if (quads[i].arg1->type == var_e && quads[i].arg2->type == arithexpr_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "sub", quads[i].result->sym->name, quads[i].arg1->sym->name, quads[i].arg2->sym->name);
            }
            else if (quads[i].arg1->type == arithexpr_e && quads[i].arg2->type == var_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "sub", quads[i].result->sym->name, quads[i].arg1->sym->name, quads[i].arg2->sym->name);
            }
            else if (quads[i].arg1->type == arithexpr_e && quads[i].arg2->type == arithexpr_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "sub", quads[i].result->sym->name, quads[i].arg1->sym->name, quads[i].arg2->sym->name);
            }
        }
        else if(quads[i].op==3) {
            if (quads[i].arg1->type == constnum_e && quads[i].arg2->type == constnum_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10d %-10d\n", i+1, "mul", quads[i].result->sym->name, (int)quads[i].arg1->numConst, (int)quads[i].arg2->numConst);
            }
            else if (quads[i].arg1->type == var_e && quads[i].arg2->type == constnum_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10d\n", i+1, "mul", quads[i].result->sym->name, quads[i].arg1->sym->name, (int)quads[i].arg2->numConst);
            }
            else if (quads[i].arg1->type == constnum_e && quads[i].arg2->type == var_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10d %-10s\n", i+1, "mul", quads[i].result->sym->name, (int)quads[i].arg1->numConst, quads[i].arg2->sym->name);
            }
            else if (quads[i].arg1->type == var_e && quads[i].arg2->type == var_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "mul", quads[i].result->sym->name, quads[i].arg1->sym->name, quads[i].arg2->sym->name);
            }
            else if (quads[i].arg1->type == var_e && quads[i].arg2->type == arithexpr_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "mul", quads[i].result->sym->name, quads[i].arg1->sym->name, quads[i].arg2->sym->name);
            }
            else if (quads[i].arg1->type == arithexpr_e && quads[i].arg2->type == var_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "mul", quads[i].result->sym->name, quads[i].arg1->sym->name, quads[i].arg2->sym->name);
            }
            else if (quads[i].arg1->type == arithexpr_e && quads[i].arg2->type == arithexpr_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "mul", quads[i].result->sym->name, quads[i].arg1->sym->name, quads[i].arg2->sym->name);
            }
        }
        else if(quads[i].op==4) {
            if (quads[i].arg1->type == constnum_e && quads[i].arg2->type == constnum_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10d %-10d\n", i+1, "div", quads[i].result->sym->name, (int)quads[i].arg1->numConst, (int)quads[i].arg2->numConst);
            }
            else if (quads[i].arg1->type == var_e && quads[i].arg2->type == constnum_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10d\n", i+1, "div", quads[i].result->sym->name, quads[i].arg1->sym->name, (int)quads[i].arg2->numConst);
            }
            else if (quads[i].arg1->type == constnum_e && quads[i].arg2->type == var_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10d %-10s\n", i+1, "div", quads[i].result->sym->name, (int)quads[i].arg1->numConst, quads[i].arg2->sym->name);
            }
            else if (quads[i].arg1->type == var_e && quads[i].arg2->type == var_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "div", quads[i].result->sym->name, quads[i].arg1->sym->name, quads[i].arg2->sym->name);
            }
            else if (quads[i].arg1->type == var_e && quads[i].arg2->type == arithexpr_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "div", quads[i].result->sym->name, quads[i].arg1->sym->name, quads[i].arg2->sym->name);
            }
            else if (quads[i].arg1->type == arithexpr_e && quads[i].arg2->type == var_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "div", quads[i].result->sym->name, quads[i].arg1->sym->name, quads[i].arg2->sym->name);
            }
            else if (quads[i].arg1->type == arithexpr_e && quads[i].arg2->type == arithexpr_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "div", quads[i].result->sym->name, quads[i].arg1->sym->name, quads[i].arg2->sym->name);
            }
        }
        else if(quads[i].op==5) {
            if (quads[i].arg1->type == constnum_e && quads[i].arg2->type == constnum_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10d %-10d\n", i+1, "mod", quads[i].result->sym->name, (int)quads[i].arg1->numConst, (int)quads[i].arg2->numConst);
            }
            else if (quads[i].arg1->type == var_e && quads[i].arg2->type == constnum_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10d\n", i+1, "mod", quads[i].result->sym->name, quads[i].arg1->sym->name, (int)quads[i].arg2->numConst);
            }
            else if (quads[i].arg1->type == constnum_e && quads[i].arg2->type == var_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10d %-10s\n", i+1, "mod", quads[i].result->sym->name, (int)quads[i].arg1->numConst, quads[i].arg2->sym->name);
            }
            else if (quads[i].arg1->type == var_e && quads[i].arg2->type == var_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "mod", quads[i].result->sym->name, quads[i].arg1->sym->name, quads[i].arg2->sym->name);
            }
            else if (quads[i].arg1->type == var_e && quads[i].arg2->type == arithexpr_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "mod", quads[i].result->sym->name, quads[i].arg1->sym->name, quads[i].arg2->sym->name);
            }
            else if (quads[i].arg1->type == arithexpr_e && quads[i].arg2->type == var_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "mod", quads[i].result->sym->name, quads[i].arg1->sym->name, quads[i].arg2->sym->name);
            }
            else if (quads[i].arg1->type == arithexpr_e && quads[i].arg2->type == arithexpr_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "mod", quads[i].result->sym->name, quads[i].arg1->sym->name, quads[i].arg2->sym->name);
            }
        }
        else if(quads[i].op==6) {
            if(quads[i].arg1->type==constbool_e)return;
            else if(quads[i].arg1->type==conststring_e)return;
            else if(quads[i].arg1->type==constnum_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10d\n", i+1, "uminus", quads[i].result->sym->name,(int)quads[i].arg1->numConst);
            }
            else if(quads[i].arg1->type==var_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s\n", i+1, "uminus", quads[i].result->sym->name,quads[i].arg1->sym->name);
            }
        }
        else if (quads[i].op == 10) { // ==
           if(quads[i].arg1->type==constnum_e && quads[i].arg2->type==constbool_e){
            if(quads[i].arg2->boolConst==1)fprintf(fptr,"%-6d %-27s %-10d %-10s %-10d\n", i+1, "if_eq",(int)quads[i].arg1->numConst,"'true'",(int)quads[i].label);
                else fprintf(fptr,"%-6d %-27s %-10d %-10s %-10d\n", i+1, "if_eq",(int)quads[i].arg1->numConst,"'false'",(int)quads[i].label);
            }
            else if(quads[i].arg1->type==constnum_e && quads[i].arg2->type==constbool_e && quads[i].arg2->boolConst==1) {
                fprintf(fptr,"%-6d %-27s %-10d %-10s %-10d\n", i+1, "if_eq",(int)quads[i].arg1->numConst,"'true'",(int)quads[i].label);
            }
            else if(quads[i].arg1->type==constnum_e && quads[i].arg2->type==constbool_e && quads[i].arg2->boolConst==0) {
                fprintf(fptr,"%-6d %-27s %-10d %-10s %-10d\n", i+1, "if_eq",(int)quads[i].arg1->numConst,"'false'",(int)quads[i].label);
            }
            else if(quads[i].arg1->type==constnum_e && quads[i].arg2->type==constnum_e) {
                fprintf(fptr,"%-6d %-27s %-10d %-10d %-10d\n", i+1, "if_eq",(int)quads[i].arg1->numConst,(int)quads[i].arg2->numConst,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==constnum_e && quads[i].arg2->type==arithexpr_e) {
                fprintf(fptr,"%-6d %-27s %-10d %-10s %-10d\n", i+1, "if_eq",(int)quads[i].arg1->numConst,quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==constnum_e && quads[i].arg2->type==conststring_e) {
                fprintf(fptr,"%-6d %-27s %-10d %-10s %-10d\n", i+1, "if_eq",(int)quads[i].arg1->numConst,quads[i].arg2->strConst,(int)quads[i].label);
            }
             else if(quads[i].arg1->type==constnum_e && quads[i].arg2->type==var_e) {
                fprintf(fptr,"%-6d %-27s %-10d %-10s %-10d\n", i+1, "if_eq",(int)quads[i].arg1->numConst,quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==constnum_e && quads[i].arg2->type==programfunc_e) {
                fprintf(fptr,"%-6d %-27s %-10d %-10s %-10d\n", i+1, "if_eq",(int)quads[i].arg1->numConst,quads[i].arg2->sym->value.funcVal->name,(int)quads[i].label);
            }
            /*arg1 is bool*/
            else if(quads[i].arg1->type==constbool_e && quads[i].arg2->type==constbool_e){
                char*arg1,*arg2;
                if(quads[i].arg1->boolConst==1){
                    arg1="'true'";
                } 
                else arg1="'false'";
                if(quads[i].arg2->boolConst==1){
                    arg2="'true'";
                } 
                else arg2="'false'";
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_eq",arg1,arg2,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==constbool_e && quads[i].arg2->type==constnum_e){
                if(quads[i].arg1->boolConst==1) fprintf(fptr,"%-6d %-27s %-10s %-10d %-10d\n", i+1, "if_eq","'true'",(int)quads[i].arg2->numConst,(int)quads[i].label);
                else fprintf(fptr,"%-6d %-27s %-10s %-10d %-10d\n", i+1, "if_eq","'false'",(int)quads[i].arg2->numConst,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==constbool_e && quads[i].arg2->type==arithexpr_e){
                if(quads[i].arg1->boolConst==1) fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_eq","'true'",quads[i].arg2->sym->name,(int)quads[i].label);
                else fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_eq","'false'",quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==constbool_e && quads[i].arg2->type==conststring_e){
                if(quads[i].arg1->boolConst==1) fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_eq","'true'",quads[i].arg2->strConst,(int)quads[i].label);
                else fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_eq","'false'",quads[i].arg2->strConst,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==constbool_e && quads[i].arg2->type==var_e){
                if(quads[i].arg1->boolConst==1) fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_eq","'true'",quads[i].arg2->sym->name,(int)quads[i].label);
                else fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_eq","'false'",quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==boolexpr_e && quads[i].arg2->type==var_e){
                if(quads[i].arg1->boolConst==1) fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_eq","'true'",quads[i].arg2->sym->name,(int)quads[i].label);
                else fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_eq","'false'",quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==constbool_e && quads[i].arg2->type==programfunc_e) {
                if(quads[i].arg1->boolConst==1) fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_eq","'true'",quads[i].arg2->sym->value.funcVal->name,(int)quads[i].label);
                else fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_eq","'false'",quads[i].arg2->sym->value.funcVal->name,(int)quads[i].label);
            }
            /*arg1 is variable*/
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==constbool_e && quads[i].arg2->boolConst==1){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_eq",quads[i].arg1->sym->name,"'true'",(int)quads[i].label);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==constbool_e && quads[i].arg2->boolConst==0){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_eq",quads[i].arg1->sym->name,"'false'",(int)quads[i].label);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==constnum_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10d %-10d\n", i+1, "if_eq",quads[i].arg1->sym->name,(int)quads[i].arg2->numConst,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==arithexpr_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_eq",quads[i].arg1->sym->name,quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==conststring_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_eq",quads[i].arg1->sym->name,quads[i].arg2->strConst,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==var_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_eq",quads[i].arg1->sym->name,quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==programfunc_e) {
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_eq",quads[i].arg1->sym->name,quads[i].arg2->sym->value.funcVal->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==boolexpr_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-15d\n", i+1, "if_eq", quads[i].arg1->sym->name, "'true'",(int)quads[i].label);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==assignexpr_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-15d\n", i+1, "if_eq", quads[i].arg1->sym->name, quads[i].arg2->sym->name,(int)quads[i].label);
            }
            /*arg1 is assign*/
            else if(quads[i].arg1->type==assignexpr_e && quads[i].arg2->type==constbool_e && quads[i].arg2->boolConst==1) {
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_eq",quads[i].arg1->sym->name,"'true'",(int)quads[i].label);
            }
            else if(quads[i].arg1->type==assignexpr_e && quads[i].arg2->type==constbool_e && quads[i].arg2->boolConst==0) {
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_eq",quads[i].arg1->sym->name,"'false'",(int)quads[i].label);
            }
            /*arg1 is arithmetical expression*/
            else if(quads[i].arg1->type==arithexpr_e && quads[i].arg2->type==constbool_e && quads[i].arg2->boolConst==1){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_eq",quads[i].arg1->sym->name,"'true'",(int)quads[i].label);
            }
            else if(quads[i].arg1->type==arithexpr_e && quads[i].arg2->type==constbool_e && quads[i].arg2->boolConst==0){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_eq",quads[i].arg1->sym->name,"'false'",(int)quads[i].label);
            }
            else if(quads[i].arg1->type==arithexpr_e && quads[i].arg2->type==constnum_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10d %-10d\n", i+1, "if_eq",quads[i].arg1->sym->name,(int)quads[i].arg2->numConst,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==arithexpr_e && quads[i].arg2->type==arithexpr_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_eq",quads[i].arg1->sym->name,quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==arithexpr_e && quads[i].arg2->type==conststring_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_eq",quads[i].arg1->sym->name,quads[i].arg2->strConst,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==arithexpr_e && quads[i].arg2->type==var_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_eq",quads[i].arg1->sym->name,quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==arithexpr_e && quads[i].arg2->type==programfunc_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_eq",quads[i].arg1->sym->name,quads[i].arg2->sym->value.funcVal->name,(int)quads[i].label);
            }
            /*arg1 is string*/
            else if(quads[i].arg1->type==conststring_e && quads[i].arg2->type==constbool_e && quads[i].arg2->boolConst==1){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_eq",quads[i].arg1->strConst,"'true'",(int)quads[i].label);
            }
            else if(quads[i].arg1->type==conststring_e && quads[i].arg2->type==constbool_e && quads[i].arg2->boolConst==0){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_eq",quads[i].arg1->strConst,"'false'",(int)quads[i].label);
            }
            else if(quads[i].arg1->type==conststring_e && quads[i].arg2->type==constnum_e) {
                fprintf(fptr,"%-6d %-27s %-10s %-10d %-10d\n", i+1, "if_eq",quads[i].arg1->strConst,(int)quads[i].arg2->numConst,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==conststring_e && quads[i].arg2->type==arithexpr_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_eq",quads[i].arg1->strConst,quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==conststring_e && quads[i].arg2->type==conststring_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_eq",quads[i].arg1->strConst,quads[i].arg2->strConst,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==conststring_e && quads[i].arg2->type==var_e) {
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_eq",quads[i].arg1->strConst,quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==conststring_e && quads[i].arg2->type==programfunc_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_eq",quads[i].arg1->strConst,quads[i].arg2->sym->value.funcVal->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==programfunc_e && quads[i].arg2->type==constbool_e){
                if(quads[i].arg2->boolConst==1) fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_eq",quads[i].arg1->sym->value.funcVal->name,"'true'",(int)quads[i].label);
                else fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_eq",quads[i].arg1->sym->value.funcVal->name,"'false'",(int)quads[i].label);
            }
        }
        else if (quads[i].op == 11) { // !=
            if(quads[i].arg1->type==constnum_e && quads[i].arg2->type==constbool_e && quads[i].arg2->boolConst==1){
                fprintf(fptr,"%-6d %-27s %-10d %-10s %-10d\n", i+1, "if_noteq",(int)quads[i].arg1->numConst,"'true'",(int)quads[i].label);
            }
            else if(quads[i].arg1->type==constnum_e && quads[i].arg2->type==constbool_e && quads[i].arg2->boolConst==0){
                fprintf(fptr,"%-6d %-27s %-10d %-10s %-10d\n", i+1, "if_noteq",(int)quads[i].arg1->numConst,"'false'",(int)quads[i].label);
            }
            else if(quads[i].arg1->type==constnum_e && quads[i].arg2->type==constnum_e) {
                fprintf(fptr,"%-6d %-27s %-10d %-10d %-10d\n", i+1, "if_noteq",(int)quads[i].arg1->numConst,(int)quads[i].arg2->numConst,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==constnum_e && quads[i].arg2->type==arithexpr_e) {
                fprintf(fptr,"%-6d %-27s %-10d %-10s %-10d\n", i+1, "if_noteq",(int)quads[i].arg1->numConst,quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==constnum_e && quads[i].arg2->type==conststring_e) {
                fprintf(fptr,"%-6d %-27s %-10d %-10s %-10d\n", i+1, "if_noteq",(int)quads[i].arg1->numConst,quads[i].arg2->strConst,(int)quads[i].label);
            }
             else if(quads[i].arg1->type==constnum_e && quads[i].arg2->type==var_e) {
                fprintf(fptr,"%-6d %-27s %-10d %-10s %-10d\n", i+1, "if_noteq",(int)quads[i].arg1->numConst,quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==constnum_e && quads[i].arg2->type==programfunc_e) {
                fprintf(fptr,"%-6d %-27s %-10d %-10s %-10d\n", i+1, "if_noteq",(int)quads[i].arg1->numConst,quads[i].arg2->sym->value.funcVal->name,(int)quads[i].label);
            }
            /*arg1 is bool*/
            else if(quads[i].arg1->type==constbool_e && quads[i].arg2->type==constbool_e){
                char*arg1,*arg2;
                if(quads[i].arg1->boolConst==1){
                    arg1="'true'";
                } 
                else arg1="'false'";
                if(quads[i].arg2->boolConst==1){
                    arg2="'true'";
                } 
                else arg2="'false'";
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_noteq",arg1,arg2,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==constbool_e && quads[i].arg2->type==constnum_e){
                if(quads[i].arg1->boolConst==1) fprintf(fptr,"%-6d %-27s %-10s %-10d %-10d\n", i+1, "if_noteq","'true'",(int)quads[i].arg2->numConst,(int)quads[i].label);
                else fprintf(fptr,"%-6d %-27s %-10s %-10d %-10d\n", i+1, "if_noteq","'false'",(int)quads[i].arg2->numConst,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==constbool_e && quads[i].arg2->type==arithexpr_e){
                if(quads[i].arg1->boolConst==1) fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_noteq","'true'",quads[i].arg2->sym->name,(int)quads[i].label);
                else fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_noteq","'false'",quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==constbool_e && quads[i].arg2->type==conststring_e){
                if(quads[i].arg1->boolConst==1) fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_noteq","'true'",quads[i].arg2->strConst,(int)quads[i].label);
                else fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_noteq","'false'",quads[i].arg2->strConst,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==constbool_e && quads[i].arg2->type==var_e){
                if(quads[i].arg1->boolConst==1) fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_noteq","'true'",quads[i].arg2->sym->name,(int)quads[i].label);
                else fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_noteq","'false'",quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==constbool_e && quads[i].arg2->type==programfunc_e) {
                if(quads[i].arg1->boolConst==1) fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_noteq","'true'",quads[i].arg2->sym->value.funcVal->name,(int)quads[i].label);
                else fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_noteq","'false'",quads[i].arg2->sym->value.funcVal->name,(int)quads[i].label);
            }
            /*arg1 is variable*/
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==constbool_e && quads[i].arg2->boolConst==1){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_noteq",quads[i].arg1->sym->name,"'true'",(int)quads[i].label);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==constbool_e && quads[i].arg2->boolConst==0){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_noteq",quads[i].arg1->sym->name,"'false'",(int)quads[i].label);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==constnum_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10d %-10d\n", i+1, "if_noteq",quads[i].arg1->sym->name,(int)quads[i].arg2->numConst,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==arithexpr_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_noteq",quads[i].arg1->sym->name,quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==conststring_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_noteq",quads[i].arg1->sym->name,quads[i].arg2->strConst,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==var_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_noteq",quads[i].arg1->sym->name,quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==programfunc_e) {
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_noteq",quads[i].arg1->sym->name,quads[i].arg2->sym->value.funcVal->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==boolexpr_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-15d\n", i+1, "if_noteq", quads[i].arg1->sym->name, "'true'",(int)quads[i].label);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==assignexpr_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-15d\n", i+1, "if_noteq", quads[i].arg1->sym->name, quads[i].arg2->sym->name,(int)quads[i].label);
            }
            /*arg1 is arithmetical expression*/
            else if(quads[i].arg1->type==arithexpr_e && quads[i].arg2->type==constbool_e && quads[i].arg2->boolConst==1){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_noteq",quads[i].arg1->sym->name,"'true'",(int)quads[i].label);
            }
            else if(quads[i].arg1->type==arithexpr_e && quads[i].arg2->type==constbool_e && quads[i].arg2->boolConst==0){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_noteq",quads[i].arg1->sym->name,"'false'",(int)quads[i].label);
            }
            else if(quads[i].arg1->type==arithexpr_e && quads[i].arg2->type==constnum_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10d %-10d\n", i+1, "if_noteq",quads[i].arg1->sym->name,(int)quads[i].arg2->numConst,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==arithexpr_e && quads[i].arg2->type==arithexpr_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_noteq",quads[i].arg1->sym->name,quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==arithexpr_e && quads[i].arg2->type==conststring_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_noteq",quads[i].arg1->sym->name,quads[i].arg2->strConst,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==arithexpr_e && quads[i].arg2->type==var_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_noteq",quads[i].arg1->sym->name,quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==arithexpr_e && quads[i].arg2->type==programfunc_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_noteq",quads[i].arg1->sym->name,quads[i].arg2->sym->value.funcVal->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==boolexpr_e && quads[i].arg2->type==var_e){
                if(quads[i].arg1->boolConst==1) fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_eq","'true'",quads[i].arg2->sym->name,(int)quads[i].label);
                else fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_eq","'false'",quads[i].arg2->sym->name,(int)quads[i].label);
            }
            /*arg1 is string*/
            else if(quads[i].arg1->type==conststring_e && quads[i].arg2->type==constbool_e){
                if(quads[i].arg2->boolConst==1) printf("%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_noteq",quads[i].arg1->strConst,"'true'",(int)quads[i].label);
                else fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_noteq",quads[i].arg1->strConst,"'false'",(int)quads[i].label);
            }
            else if(quads[i].arg1->type==conststring_e && quads[i].arg2->type==constnum_e) {
                fprintf(fptr,"%-6d %-27s %-10s %-10d %-10d\n", i+1, "if_noteq",quads[i].arg1->strConst,(int)quads[i].arg2->numConst,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==conststring_e && quads[i].arg2->type==arithexpr_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_noteq",quads[i].arg1->strConst,quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==conststring_e && quads[i].arg2->type==conststring_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_noteq",quads[i].arg1->strConst,quads[i].arg2->strConst,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==conststring_e && quads[i].arg2->type==var_e) {
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_noteq",quads[i].arg1->strConst,quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==conststring_e && quads[i].arg2->type==programfunc_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_noteq",quads[i].arg1->strConst,quads[i].arg2->sym->value.funcVal->name,(int)quads[i].label);
            }
        }
        else if (quads[i].op == 12) { // <=
            if(quads[i].arg1->type==constnum_e && quads[i].arg2->type==constnum_e) {
                fprintf(fptr,"%-6d %-27s %-10d %-10d %-10d\n", i+1, "if_lesseq",(int)quads[i].arg1->numConst,(int)quads[i].arg2->numConst,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==constnum_e && quads[i].arg2->type==arithexpr_e) {
                fprintf(fptr,"%-6d %-27s %-10d %-10s %-10d\n", i+1, "if_lesseq",(int)quads[i].arg1->numConst,quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==constnum_e && quads[i].arg2->type==var_e) {
                fprintf(fptr,"%-6d %-27s %-10d %-10s %-10d\n", i+1, "if_lesseq",(int)quads[i].arg1->numConst,quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==constnum_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10d %-10d\n", i+1, "if_lesseq",quads[i].arg1->sym->name,(int)quads[i].arg2->numConst,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==arithexpr_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_lesseq",quads[i].arg1->sym->name,quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==var_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_lesseq",quads[i].arg1->sym->name,quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==boolexpr_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-15d\n", i+1, "if_lesseq", quads[i].arg1->sym->name, "'true'",(int)quads[i].label);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==assignexpr_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-15d\n", i+1, "if_lesseq", quads[i].arg1->sym->name, quads[i].arg2->sym->name,(int)quads[i].label);
            }
            /*arg1 is arithmetical expression*/
            else if(quads[i].arg1->type==arithexpr_e && quads[i].arg2->type==constnum_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10d %-10d\n", i+1, "if_lesseq",quads[i].arg1->sym->name,(int)quads[i].arg2->numConst,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==arithexpr_e && quads[i].arg2->type==arithexpr_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_lesseq",quads[i].arg1->sym->name,quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==arithexpr_e && quads[i].arg2->type==var_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_lesseq",quads[i].arg1->sym->name,quads[i].arg2->sym->name,(int)quads[i].label);
            }
        }
        else if (quads[i].op == 13) { // >=
            if(quads[i].arg1->type==constnum_e && quads[i].arg2->type==constnum_e) {
                fprintf(fptr,"%-6d %-27s %-10d %-10d %-10d\n", i+1, "if_greatereq",(int)quads[i].arg1->numConst,(int)quads[i].arg2->numConst,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==constnum_e && quads[i].arg2->type==arithexpr_e) {
                fprintf(fptr,"%-6d %-27s %-10d %-10s %-10d\n", i+1, "if_greatereq",(int)quads[i].arg1->numConst,quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==constnum_e && quads[i].arg2->type==var_e) {
                fprintf(fptr,"%-6d %-27s %-10d %-10s %-10d\n", i+1, "if_greatereq",(int)quads[i].arg1->numConst,quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==constnum_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10d %-10d\n", i+1, "if_greatereq",quads[i].arg1->sym->name,(int)quads[i].arg2->numConst,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==arithexpr_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_greatereq",quads[i].arg1->sym->name,quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==var_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_greatereq",quads[i].arg1->sym->name,quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==boolexpr_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-15d\n", i+1, "if_greatereq", quads[i].arg1->sym->name, "'true'",(int)quads[i].label);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==assignexpr_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-15d\n", i+1, "if_greatereq", quads[i].arg1->sym->name, quads[i].arg2->sym->name,(int)quads[i].label);
            }
            /*arg1 is arithmetical expression*/
            else if(quads[i].arg1->type==arithexpr_e && quads[i].arg2->type==constnum_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10d %-10d\n", i+1, "if_greatereq",quads[i].arg1->sym->name,(int)quads[i].arg2->numConst,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==arithexpr_e && quads[i].arg2->type==arithexpr_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_greatereq",quads[i].arg1->sym->name,quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==arithexpr_e && quads[i].arg2->type==var_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_greatereq",quads[i].arg1->sym->name,quads[i].arg2->sym->name,(int)quads[i].label);
            }

        }
        else if (quads[i].op == 14) { // <
            if(quads[i].arg1->type==constnum_e && quads[i].arg2->type==constnum_e) {
                fprintf(fptr,"%-6d %-27s %-10d %-10d %-10d\n", i+1, "if_less",(int)quads[i].arg1->numConst,(int)quads[i].arg2->numConst,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==constnum_e && quads[i].arg2->type==arithexpr_e) {
                fprintf(fptr,"%-6d %-27s %-10d %-10s %-10d\n", i+1, "if_less",(int)quads[i].arg1->numConst,quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==constnum_e && quads[i].arg2->type==var_e) {
                fprintf(fptr,"%-6d %-27s %-10d %-10s %-10d\n", i+1, "if_less",(int)quads[i].arg1->numConst,quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==constnum_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10d %-10d\n", i+1, "if_less",quads[i].arg1->sym->name,(int)quads[i].arg2->numConst,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==arithexpr_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_less",quads[i].arg1->sym->name,quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==var_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_less",quads[i].arg1->sym->name,quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==boolexpr_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-15d\n", i+1, "if_less", quads[i].arg1->sym->name, "'true'",(int)quads[i].label);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==assignexpr_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-15d\n", i+1, "if_less", quads[i].arg1->sym->name, quads[i].arg2->sym->name,(int)quads[i].label);
            }
            /*arg1 is arithmetical expression*/
            else if(quads[i].arg1->type==arithexpr_e && quads[i].arg2->type==constnum_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10d %-10d\n", i+1, "if_less",quads[i].arg1->sym->name,(int)quads[i].arg2->numConst,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==arithexpr_e && quads[i].arg2->type==arithexpr_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_less",quads[i].arg1->sym->name,quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==arithexpr_e && quads[i].arg2->type==var_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_less",quads[i].arg1->sym->name,quads[i].arg2->sym->name,(int)quads[i].label);
            }
        }
        else if (quads[i].op == 15) { // >
            if(quads[i].arg1->type==constnum_e && quads[i].arg2->type==constnum_e) {
                fprintf(fptr,"%-6d %-27s %-10d %-10d %-10d\n", i+1, "if_greater",(int)quads[i].arg1->numConst,(int)quads[i].arg2->numConst,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==constnum_e && quads[i].arg2->type==arithexpr_e) {
                fprintf(fptr,"%-6d %-27s %-10d %-10s %-10d\n", i+1, "if_greater",(int)quads[i].arg1->numConst,quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==constnum_e && quads[i].arg2->type==var_e) {
                fprintf(fptr,"%-6d %-27s %-10d %-10s %-10d\n", i+1, "if_greater",(int)quads[i].arg1->numConst,quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==constnum_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10d %-10d\n", i+1, "if_greater",quads[i].arg1->sym->name,(int)quads[i].arg2->numConst,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==arithexpr_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_greater",quads[i].arg1->sym->name,quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==var_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_greater",quads[i].arg1->sym->name,quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==boolexpr_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-15d\n", i+1, "if_greater", quads[i].arg1->sym->name, "'true'",(int)quads[i].label);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==assignexpr_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-15d\n", i+1, "if_greater", quads[i].arg1->sym->name, quads[i].arg2->sym->name,(int)quads[i].label);
            }
            /*arg1 is arithmetical expression*/
            else if(quads[i].arg1->type==arithexpr_e && quads[i].arg2->type==constnum_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10d %-10d\n", i+1, "if_greater",quads[i].arg1->sym->name,(int)quads[i].arg2->numConst,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==arithexpr_e && quads[i].arg2->type==arithexpr_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_greater",quads[i].arg1->sym->name,quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==arithexpr_e && quads[i].arg2->type==var_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_greater",quads[i].arg1->sym->name,quads[i].arg2->sym->name,(int)quads[i].label);
            }
        }
        else if (quads[i].op == 16) {
            if(quads[i].arg1->type!=programfunc_e){
                fprintf(fptr,"%-6d %-15s %-10s\n", i+1, "call",quads[i].arg1->sym->name); 
            }
            else fprintf(fptr,"%-6d %-15s %-10s\n", i+1, "call",quads[i].arg1->sym->value.funcVal->name); 
        }
        else if (quads[i].op == 17) {
            if(quads[i].arg1->type==constnum_e) {
                fprintf(fptr,"%-6d %-15s %-10d\n", i+1, "param",(int)quads[i].arg1->numConst); 
            }
            else if(quads[i].arg1->type==var_e) {
                fprintf(fptr,"%-6d %-15s %-10s\n", i+1, "param",quads[i].arg1->sym->name); 
            }
            else if(quads[i].arg1->type==conststring_e) {
                fprintf(fptr,"%-6d %-15s %-10s\n", i+1, "param",quads[i].arg1->strConst); 
            }
            else if(quads[i].arg1->type==constbool_e) {
                fprintf(fptr,"%-6d %-15s %-6d\n", i+1, "param",quads[i].arg1->boolConst);
            }
            else if(quads[i].arg1->type==boolexpr_e) {
                fprintf(fptr,"%-6d %-15s %-10s\n", i+1, "param",quads[i].arg1->sym->name);
            }
        }
        else if (quads[i].op == 19) { 
            fprintf(fptr,"%-6d %-15s %-10s\n", i+1, "getretval",quads[i].result->sym->name);
        }
        else if (quads[i].op == 18) { 
            if(quads[i].result->type==constbool_e){
                if(quads[i].result->boolConst==1) fprintf(fptr,"%-6d %-15s %s\n", i+1, "return","'true'");
                else fprintf(fptr,"%-6d %-15s %-10s\n", i+1, "return","'false'");
            }
            else if(quads[i].result->type==constnum_e){
                fprintf(fptr,"%-6d %-15s %-10d\n", i+1, "return",(int)quads[i].result->numConst);
            }
            else if(quads[i].result->type==arithexpr_e){
                fprintf(fptr,"%-6d %-15s %-10s\n", i+1, "return",quads[i].result->sym->name);
            }
            else if(quads[i].result->type==conststring_e){
                fprintf(fptr,"%-6d %-15s %-10s\n", i+1, "return",quads[i].result->strConst);
            }
            else if(quads[i].result->type==var_e){
                fprintf(fptr,"%-6d %-15s %-10s \n", i+1, "return",quads[i].result->sym->name);
            }
            else if(quads[i].result->type==nil_e){
                fprintf(fptr,"%-6d %-15s\n", i+1, "return");
            }
        }
        else if(quads[i].op==20) {
            fprintf(fptr,"%-6d %-15s %-10s\n", i+1, "funcstart", quads[i].result->sym->value.funcVal->name);
        }
        else if(quads[i].op==21) {
            fprintf(fptr,"%-6d %-15s %-10s\n", i+1, "funcend", quads[i].result->sym->value.funcVal->name);
        }
        else if (quads[i].op == 22) {
            fprintf(fptr,"%-6d %-15s %-10s\n", i+1, "tablecreate",quads[i].arg1->sym->name);
        }
        else if (quads[i].op == 23) {
                if(quads[i].arg2->type==constbool_e) {
                    if(quads[i].arg2->boolConst==1)fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablegetelem",quads[i].result->sym->name,quads[i].arg1->sym->name,"'true'");
                    else fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablegetelem",quads[i].result->sym->name,quads[i].arg1->sym->name,"'false'");
                }
                else if(quads[i].arg2->type==constnum_e){
                    fprintf(fptr,"%-6d %-15s %-10s %-10s %-10d\n", i+1, "tablegetelem",quads[i].result->sym->name,quads[i].arg1->sym->name,(int)quads[i].arg2->numConst);
                }
                else if(quads[i].arg2->type==arithexpr_e){
                    fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablegetelem",quads[i].result->sym->name,quads[i].arg1->sym->name,quads[i].arg2->sym->name);
                }
                else if(quads[i].arg2->type==conststring_e) {
                    fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablegetelem",quads[i].result->sym->name,quads[i].arg1->sym->name,quads[i].arg2->strConst);
                }
                else if(quads[i].arg2->type==var_e) {
                    fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablegetelem",quads[i].result->sym->name,quads[i].arg1->sym->name,quads[i].arg2->sym->name);
                }
        }
        else if (quads[i].op == 24) {
            if(quads[i].arg1->type==tableitem_e && quads[i].arg2->type==conststring_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,quads[i].arg1->sym->name,quads[i].arg2->strConst);
            }
            else if(quads[i].arg1->type==constnum_e && quads[i].arg2->type==newtable_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10d %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,(int)quads[i].arg1->numConst,quads[i].arg2->sym->name);
            }
            /*arg1 is function*/
            else if(quads[i].arg1->type==programfunc_e && quads[i].arg2->type==constbool_e){
                if(quads[i].arg2->boolConst==1)fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,quads[i].arg1->sym->value.funcVal->name,"'true'");
                else fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,quads[i].arg1->sym->value.funcVal->name,"'false'");
            }
            else if(quads[i].arg1->type==programfunc_e && quads[i].arg2->type==constnum_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10d\n", i+1, "tablesetelem",quads[i].result->sym->name,quads[i].arg1->sym->value.funcVal->name,(int)quads[i].arg2->numConst);
            }
            else if(quads[i].arg1->type==programfunc_e && quads[i].arg2->type==arithexpr_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,quads[i].arg1->sym->value.funcVal->name,quads[i].arg2->sym->name);
            }
            else if(quads[i].arg1->type==programfunc_e && quads[i].arg2->type==boolexpr_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,quads[i].arg1->sym->value.funcVal->name,quads[i].arg2->sym->name);
            }
            else if(quads[i].arg1->type==programfunc_e && quads[i].arg2->type==conststring_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,quads[i].arg1->sym->value.funcVal->name,quads[i].arg2->strConst);
            }
            else if(quads[i].arg1->type==programfunc_e && quads[i].arg2->type==var_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,quads[i].arg1->sym->value.funcVal->name,quads[i].arg2->sym->name);
            }
            else if(quads[i].arg1->type==programfunc_e && quads[i].arg2->type==programfunc_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,quads[i].arg1->sym->value.funcVal->name,quads[i].arg2->sym->value.funcVal->name);
            }
            /*arg1 is number*/
            if(quads[i].arg1->type==constnum_e && quads[i].arg2->type==constbool_e){
                if(quads[i].arg2->boolConst==1) fprintf(fptr,"%-6d %-15s %-10s %-10d %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,(int)quads[i].arg1->numConst,"'true'");
                else fprintf(fptr,"%-6d %-15s %-10s %-10d %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,(int)quads[i].arg1->numConst,"'false'");
            }
            else if(quads[i].arg1->type==constnum_e && quads[i].arg2->type==constnum_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10d %-10d\n", i+1, "tablesetelem",quads[i].result->sym->name,(int)quads[i].arg1->numConst,(int)quads[i].arg2->numConst);
            }
            else if(quads[i].arg1->type==constnum_e && quads[i].arg2->type==arithexpr_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10d %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,(int)quads[i].arg1->numConst,quads[i].arg2->sym->name);
            }
            else if(quads[i].arg1->type==constnum_e && quads[i].arg2->type==assignexpr_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10d %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,(int)quads[i].arg1->numConst,quads[i].arg2->sym->name);
            }
            else if(quads[i].arg1->type==constnum_e && quads[i].arg2->type==boolexpr_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10d %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,(int)quads[i].arg1->numConst,quads[i].arg2->sym->name);
            }
            else if(quads[i].arg1->type==constnum_e && quads[i].arg2->type==conststring_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10d %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,(int)quads[i].arg1->numConst,quads[i].arg2->strConst);
            }
             else if(quads[i].arg1->type==constnum_e && quads[i].arg2->type==var_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10d %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,(int)quads[i].arg1->numConst,quads[i].arg2->sym->name);
            }
            else if(quads[i].arg1->type==constnum_e && quads[i].arg2->type==programfunc_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10d %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,(int)quads[i].arg1->numConst,quads[i].arg2->sym->value.funcVal->name);
            }
            /*arg1 is bool*/
            else if(quads[i].arg1->type==constbool_e && quads[i].arg2->type==constbool_e){
                char*arg1,*arg2;
                if(quads[i].arg1->boolConst==1){
                    arg1="'true'";
                } 
                else arg1="'false'";
                if(quads[i].arg2->boolConst==1){
                    arg2="'true'";
                } 
                else arg2="'false'";
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,arg1,arg2);
            }
            else if(quads[i].arg1->type==constbool_e && quads[i].arg2->type==constnum_e){
                if(quads[i].arg1->boolConst==1) fprintf(fptr,"%-6d %-15s %-10s %-10s %-10d\n", i+1, "tablesetelem",quads[i].result->sym->name,"'true'",(int)quads[i].arg2->numConst);
                else fprintf(fptr,"%-6d %-15s %-10s %-10s %-10d\n", i+1, "tablesetelem",quads[i].result->sym->name,"'false'",(int)quads[i].arg2->numConst);
            }
            else if(quads[i].arg1->type==constbool_e && quads[i].arg2->type==arithexpr_e){
                if(quads[i].arg1->boolConst==1) fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,"'true'",quads[i].arg2->sym->name);
                else fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,"'false'",quads[i].arg2->sym->name);
            }
            else if(quads[i].arg1->type==constbool_e && quads[i].arg2->type==boolexpr_e){
                if(quads[i].arg1->boolConst==1) fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,"'true'",quads[i].arg2->sym->name);
                else fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,"'false'",quads[i].arg2->sym->name);
            }
            else if(quads[i].arg1->type==constbool_e && quads[i].arg2->type==conststring_e){
                if(quads[i].arg1->boolConst==1) fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,"'true'",quads[i].arg2->strConst);
                else fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,"'false'",quads[i].arg2->strConst);
            }
            else if(quads[i].arg1->type==constbool_e && quads[i].arg2->type==var_e){
                if(quads[i].arg1->boolConst==1) fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,"'true'",quads[i].arg2->sym->name);
                else fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,"'false'",quads[i].arg2->sym->name);
            }
            else if(quads[i].arg1->type==constbool_e && quads[i].arg2->type==programfunc_e) {
                if(quads[i].arg1->boolConst==1) fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,"'true'",quads[i].arg2->sym->value.funcVal->name);
                else fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,"'false'",quads[i].arg2->sym->value.funcVal->name);
            }
            /*arg1 is variable*/
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==constbool_e){
                if(quads[i].arg2->boolConst==1) fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,quads[i].arg1->sym->name,"'true'");
                else fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,quads[i].arg1->sym->name,"'false'");
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==constnum_e){
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10d\n", i+1, "tablesetelem",quads[i].result->sym->name,quads[i].arg1->sym->name,(int)quads[i].arg2->numConst);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==arithexpr_e){
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,quads[i].arg1->sym->name,quads[i].arg2->sym->name);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==boolexpr_e){
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,quads[i].arg1->sym->name,quads[i].arg2->sym->name);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==conststring_e){
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,quads[i].arg1->sym->name,quads[i].arg2->strConst);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==var_e){
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,quads[i].arg1->sym->name,quads[i].arg2->sym->name);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==programfunc_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,quads[i].arg1->sym->name,quads[i].arg2->sym->value.funcVal->name);
            }
            /*arg1 is arithmetical expression*/
            else if(quads[i].arg1->type==arithexpr_e && quads[i].arg2->type==constbool_e){
                if(quads[i].arg2->boolConst==1) fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,quads[i].arg1->sym->name,"'true'");
                else fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,quads[i].arg1->sym->name,"'false'");
            }
            else if(quads[i].arg1->type==arithexpr_e && quads[i].arg2->type==constnum_e){
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10d\n", i+1, "tablesetelem",quads[i].result->sym->name,quads[i].arg1->sym->name,(int)quads[i].arg2->numConst);
            }
            else if(quads[i].arg1->type==arithexpr_e && quads[i].arg2->type==arithexpr_e){
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,quads[i].arg1->sym->name,quads[i].arg2->sym->name);
            }
            else if(quads[i].arg1->type==arithexpr_e && quads[i].arg2->type==boolexpr_e){
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,quads[i].arg1->sym->name,quads[i].arg2->sym->name);
            }
            else if(quads[i].arg1->type==arithexpr_e && quads[i].arg2->type==conststring_e){
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,quads[i].arg1->sym->name,quads[i].arg2->strConst);
            }
            else if(quads[i].arg1->type==arithexpr_e && quads[i].arg2->type==var_e){
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,quads[i].arg1->sym->name,quads[i].arg2->sym->name);
            }
            else if(quads[i].arg1->type==arithexpr_e && quads[i].arg2->type==programfunc_e){
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,quads[i].arg1->sym->name,quads[i].arg2->sym->value.funcVal->name);
            }
            /*arg1 is string*/
            else if(quads[i].arg1->type==conststring_e && quads[i].arg2->type==constbool_e){
                if(quads[i].arg2->boolConst==1) fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,quads[i].arg1->strConst,"'true'");
                else fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,quads[i].arg1->strConst,"'false'");
            }
            else if(quads[i].arg1->type==conststring_e && quads[i].arg2->type==boolexpr_e){
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,quads[i].arg1->strConst,quads[i].arg2->sym->name);
            }
            else if(quads[i].arg1->type==conststring_e && quads[i].arg2->type==constnum_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10d\n", i+1, "tablesetelem",quads[i].result->sym->name,quads[i].arg1->strConst,(int)quads[i].arg2->numConst);
            }
            else if(quads[i].arg1->type==conststring_e && quads[i].arg2->type==arithexpr_e){
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,quads[i].arg1->strConst,quads[i].arg2->sym->name);
            }
            else if(quads[i].arg1->type==conststring_e && quads[i].arg2->type==conststring_e){
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,quads[i].arg1->strConst,quads[i].arg2->strConst);
            }
            else if(quads[i].arg1->type==conststring_e && quads[i].arg2->type==var_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,quads[i].arg1->strConst,quads[i].arg2->sym->name);
            }
            else if(quads[i].arg1->type==conststring_e && quads[i].arg2->type==assignexpr_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,quads[i].arg1->strConst,quads[i].arg2->sym->name);
            }
            else if(quads[i].arg1->type==conststring_e && quads[i].arg2->type==programfunc_e){
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,quads[i].arg1->strConst,quads[i].arg2->sym->value.funcVal->name);
            }
            else if(quads[i].arg1->type==conststring_e && quads[i].arg2->type==newtable_e){
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,quads[i].arg1->strConst,quads[i].arg2->sym->name);
            }
        }
        else if (quads[i].op == 25) {
            if(quads[i].label==0) fprintf(fptr,"%-6d %-49s \n", i+1, "jump"); 
            else fprintf(fptr,"%-6d %-49s %-d\n", i+1, "jump",(int)quads[i].label);
        }
    }
    fclose(fptr);
}  

void pushAND(int quadNo) {
    struct stmt_t *newStmt = (struct stmt_t *)malloc(sizeof(struct stmt_t));
    if (newStmt == NULL) {
        return;
    }
    newStmt->quadNo = quadNo;
    newStmt->next = NULL;
    if (topHeadAnd1 == NULL) {
        topHeadAnd1 = newStmt;
        butomHeadAnd1 = newStmt;
    } else {
        newStmt->next = topHeadAnd1;
        topHeadAnd1 = newStmt;
    }
}

int popAND() {
    if (topHeadAnd1 == NULL) {
        return -1;
    }
    int quadNo = topHeadAnd1->quadNo;
    struct stmt_t *temp = topHeadAnd1;
    if (topHeadAnd1 == butomHeadAnd1) {
        topHeadAnd1 = NULL;
        butomHeadAnd1 = NULL;
    } else {
        topHeadAnd1 = topHeadAnd1->next;
    }
    free(temp);
    return quadNo;
}

struct stmt_t* makelist(int quadno){
	struct stmt_t*list = (struct stmt_t*)malloc(sizeof(struct stmt_t));
	if(list==NULL)return NULL;
	list->quadNo=quadno;
	list->next=NULL;
	return list;
}

void backpatch(struct stmt_t *list, int quadno){
    struct stmt_t *tmp=list;
	while (tmp!=NULL){
    	patchlabel(tmp->quadNo, quadno);
		tmp=tmp->next;
	}
}

struct stmt_t* merge(struct stmt_t* l1,struct stmt_t* l2){
    struct stmt_t *temp = NULL;
	if (l1==NULL){
		return l2;
	}
	else 
    if (l2==NULL){
		return l1;
    }
	else {
        temp=l1;
	    while (temp->next!=NULL){
		    temp=temp->next;
	    }
	    temp->next=l2;
    }
	return l1;
}

void pushC(struct stmt_t* breakList, struct stmt_t* continueList) { // continue; 
    struct Lc_stack_t* newNode = (struct Lc_stack_t*)malloc(sizeof(struct Lc_stack_t));
    if (newNode == NULL) {
        exit(EXIT_FAILURE);
    }
    newNode->breakList = breakList;
    newNode->continueList = continueList;
    newNode->next = NULL;
    newNode->counter = 0;

    if (lcs_topC == NULL) {
        lcs_topC = newNode;
        lsc_bottomC = newNode;
    } else {
        newNode->next = lcs_topC;
        lcs_topC = newNode;
    }
}

int popC() {
    if (lcs_topC == NULL) {
        return -1;
    }
    struct Lc_stack_t* temp = lcs_topC;
    int quadNo = temp->breakList->quadNo; // Αποθήκευση του quadNo
    lcs_topC = lcs_topC->next;
    free(temp);

    if (lcs_topC == NULL) {
        lsc_bottomC = NULL;
    }

    return quadNo;
}

void pushB(struct stmt_t* breakList, struct stmt_t* continueList) { // break;
    struct Lc_stack_t* newNode = (struct Lc_stack_t*)malloc(sizeof(struct Lc_stack_t));
    if (newNode == NULL) {
        exit(EXIT_FAILURE);
    }
    newNode->breakList = breakList;
    newNode->continueList = continueList;
    newNode->next = NULL;
    newNode->counter = 0;
    if (lcs_topB == NULL) {
        lcs_topB = newNode;
        lsc_bottomB = newNode;
    } else {
        newNode->next = lcs_topB;
        lcs_topB = newNode;
    }
}

int popB() {
    if (lcs_topB == NULL) {
        return -1;
    }
    struct Lc_stack_t* temp = lcs_topB;
    lcs_topB = lcs_topB->next;
    if (lcs_topB == NULL) {
        lsc_bottomB = NULL;
    }
    return temp->breakList->quadNo;
}

void pushIf(int label,struct IfStack** top){
    struct IfStack* newnode=(struct IfStack*)malloc(sizeof(struct IfStack));
    if (newnode==NULL) return;
    newnode->label=label;
    newnode->next=*top;
    *top=newnode;
}

int popIf(struct IfStack** top){
    struct IfStack* temp;
    if (*top==NULL) return -1; 
    int pop=(*top)->label;
    temp=*top;
    *top=(*top)->next;
    free(temp);
    return pop;
}

void pushLabel(struct LabelStack**top,int label) {
    struct LabelStack* newnode=(struct LabelStack*)malloc(sizeof(struct LabelStack));
    if (newnode==NULL) return;
    newnode->label=label;
    newnode->next=*top;
    *top=newnode;
}

int pop(struct LabelStack**top) {
    if (*top==NULL) return -1; 
    int pop=(*top)->label;
    struct LabelStack* temp=*top;
    (*top)=(*top)->next;
    return pop;
}

void pushLoop(int label,struct LabelStack** top) {
    struct LabelStack* newnode=(struct LabelStack*)malloc(sizeof(struct LabelStack));
    if (newnode==NULL) return;
    newnode->label=label;
    newnode->next=*top;
    *top=newnode;
}

int popLoop(struct LabelStack** top) {
    struct LabelStack* temp;
    if (top==NULL) return -1; 
    int pop=(*top)->label;
    temp=*top;
    *top=(*top)->next;
    free(temp);
    return pop;
}


void pushOffset(int offset) {
    struct OffsetStack* newnode=(struct OffsetStack*)malloc(sizeof(struct OffsetStack));
    if (newnode==NULL) return;
    newnode->offset=offset;
    newnode->next=topOffset;
    topOffset=newnode;
}

int pop_and_top() {
    if (topOffset==NULL) return -1; 
    int pop=topOffset->offset;
    struct OffsetStack* temp=topOffset;
    topOffset=topOffset->next;  
    if(topOffset!=NULL)return topOffset->offset;
    else return -1;
}

struct expr* newexpr(enum expr_t t){
    struct expr* e=(struct expr*)malloc(sizeof(struct expr));
    memset(e,0,sizeof(struct expr));
    e->type=t;
    return e;
}

void resettemp(){
    tempcounter=0;
}

char* newtempfuncname() {
    int length_counter;
    char* new_n;
    length_counter = snprintf(NULL, 0, "%d", tempfuncounter);
    new_n = (char*)malloc((length_counter + 4) * sizeof(char)); 
    sprintf(new_n, "_f%d", tempfuncounter);
    tempfuncounter++;
    return new_n;
}

char* newtempname() {
    int length_counter;
    char* new_n;
    length_counter = snprintf(NULL, 0, "%d", tempcounter);
    new_n = (char*)malloc((length_counter + 4) * sizeof(char)); 
    sprintf(new_n, "_t%d", tempcounter);
    tempcounter++;
    return new_n;
}

Node newtemp() {
    Node n = (Node)malloc(sizeof(struct SymbolTableEntry));
    int x;
    int length_counter;
    char* new_n;
    n->name = newtempname();
    n->type = GLOBAL;
    n->offset = 0;
    n->space = programvar;
    n->scope = 0; 
    n->line = yylineno;
    SymTable_Insert(p, n->name, 1, GLOBAL, scope, yylineno);
    return n;
}

void expand(void){
    assert(total==currQuad);       
    struct quad*p=(struct quad*)malloc(NEW_SIZE);
    if(quads){
        memcpy(p,quads,CURR_SIZE);
        free(quads);
    }
    quads=p;
    total=total+EXPAND_SIZE;
}

void emit (enum iopcode op,struct expr* arg1,struct expr* arg2, struct expr* result, unsigned label, unsigned line){
    if (currQuad==total){
        expand();
    }
    struct quad*p=quads+(currQuad++);
    p->op=op;
    p->arg1=arg1;
    p->arg2=arg2;
    p->result=result;
    p->label=label;
    p->line=line;
}

unsigned nextquadlabel(){
    return currQuad;
}

void yyerror(char* yaccProvidedMessage){
    fprintf(stderr, "%s: at line %d, before token: %s\n", yaccProvidedMessage, yylineno, yytext);
    fprintf(stderr, "INPUT NOT VALID\n");
}

struct expr* newexpr_conststring(char *s){
    struct expr* e=newexpr(conststring_e);
    e->strConst=strdup(s);
    return e;
}

struct expr* newexpr_constnum (double i){
    struct expr* e=newexpr(constnum_e);
    e->numConst=i;
    return e;
}

struct expr* newexpr_constbool (unsigned int b) {
   struct expr* e = newexpr(constbool_e);
   e->boolConst = !!b;
   return e;
}

struct expr* newexpr_constnil(){
	struct expr* e=newexpr(nil_e);
    e->numConst=0;
    return e;
}

struct expr* emit_iftableitem(struct expr* e){      //e=t
    if(e->type!=tableitem_e) {
        return e;
    }
    else {
        struct expr* result=newexpr(var_e);
        result->sym=newtemp();      //_t0
        emit(tablegetelem,e,e->index,result,nextquadlabel(),yylineno);   
        return result;      //epistrefei to _t0
    }
}

void patchlabel(unsigned quadNo, unsigned label){
    assert(quadNo<currQuad);
    quads[quadNo].label=label;
}

void patchlist(int list,int label){
    while(list){
        int next=quads[list].label;
        quads[list].label=label;
        list=next;
    }
}

struct expr* member_item (struct expr* lv, char* name){     //lv=t name="a"
    lv=emit_iftableitem(lv);  //tablegetelem t "a" _t0      lv=_t0
    struct expr* ti=newexpr(tableitem_e);   
    ti->sym=lv->sym;    //_t0
    ti->index=newexpr_conststring(name);    //"a"
    return ti;      //pinakas
}

struct expr* lvalue_expr(Node sym){
    assert(sym);
    struct expr* e=(struct expr*)malloc(sizeof(struct expr));
    memset(e,0,sizeof(struct expr));
    e->next=(struct expr*)0;
    e->sym=sym;
    switch(sym->type){
        case LOCAL: e->type=var_e; break;
        case FORMAL: e->type= var_e; break;
        case GLOBAL: e->type=var_e; break;
        case LIBFUNC: e->type= libraryfunc_e; break;
        case USERFUNC: e->type=programfunc_e; break;
    }
    return e;
}


void check_arith (struct expr* e, const char* context) {
if (e->type == constbool_e ||
    e->type == conststring_e ||
    e->type == nil_e ||
    e->type == newtable_e ||
    e->type == programfunc_e ||
    e->type == libraryfunc_e ||
    e->type == boolexpr_e )
    printf("Illegal expr used in %s!", context);
}
void enterscopespace(void){
    ++scopeSpaceCounter;
}

void exitscopespace(void){
    assert(scopeSpaceCounter>1);
    --scopeSpaceCounter;
}

void resetformalargoffset(void){
    formalArgOffset=0;
}

void resetfunctionoffset(void){
    functionLocalOffset=0;
}

unsigned currscopeoffset(void){
    switch(currscopespace()){
        case programvar: return programVarOffset;
        case functionlocal: return functionLocalOffset;
        case formalarg: return formalArgOffset;
        default: assert(0);
    }
}

enum scopespace_t currscopespace(void){
  if(scopeSpaceCounter==1){
    return programvar;
  }
  else {
    if(scopeSpaceCounter%2==0){
      return formalarg;
    }
    else {
      return functionlocal;
    }
  }
}

void restorecurrscopeoffset(unsigned n){
    switch (currscopespace()){
        case programvar: programVarOffset=n; break;
        case functionlocal: functionLocalOffset=n; break;
        case formalarg: formalArgOffset=n; break;
        default: assert(0);
    }
}

struct expr* make_call(struct expr* lv, struct expr* reversed_elist){
    struct expr* prev,*next,*list,*current,*func,*result;
    current=reversed_elist;
    prev=NULL;
    next=NULL;
    while (current!=NULL) {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    list=prev;
    func=emit_iftableitem(lv);
    if(reversed_elist->type!=nil_e){
        while(list){
            emit(param,list,NULL,NULL,0,0);
            list=list->next;
        }  
    }    
    emit(call,func,NULL,NULL,0,0);  
    result=newexpr(var_e);
    result->sym=newtemp();
    emit(getretval,NULL,NULL,result,0,0);
    return result;
}

void inccurrsopeoffset(void){
    switch (currscopespace()) {
        case programvar: ++programVarOffset; break;
        case functionlocal: ++functionLocalOffset; break;
        case formalarg: ++formalArgOffset; break;
        default: assert(0);
    }
}

int main(int argc, char* argv[]){
    p=SymTable_new();
    SymTable_Insert(p,"print",0,LIBFUNC,-1,0);
    SymTable_Insert(p,"input",0,LIBFUNC,-1,0);
    SymTable_Insert(p,"objectmemberkey",0,LIBFUNC,-1,0);
    SymTable_Insert(p,"objecttotalmember",0,LIBFUNC,-1,0);
    SymTable_Insert(p,"objectcopy",0,LIBFUNC,-1,0);
    SymTable_Insert(p,"totalarguments",0,LIBFUNC,-1,0);
    SymTable_Insert(p,"argument",0,LIBFUNC,-1,0);
    SymTable_Insert(p,"typeof",0,LIBFUNC,-1,0);
    SymTable_Insert(p,"strtonum",0,LIBFUNC,-1,0);
    SymTable_Insert(p,"sqrt",0,LIBFUNC,-1,0);
    SymTable_Insert(p,"cos",0,LIBFUNC,-1,0);
    SymTable_Insert(p,"sin",0,LIBFUNC,-1,0);
    if(argc > 1){
        if(!(yyin = fopen(argv[1], "r"))){
            fprintf(stderr, "Cannot read file: %s\n", argv[1]);
            return 1;
        }
    } 
    else {
        yyin = stdin;
    }
    yyparse();
    SymTable_Print(p,max_scope);
    Quad_Print();
    return 0;
}

