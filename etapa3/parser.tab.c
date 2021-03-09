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
#line 1 "parser.y" /* yacc.c:339  */

#include<stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "token_info.h"
#define YYERROR_VERBOSE 1

extern void *arvore;

extern int yylineno;
int yylex(void);
int yyerror (char const *s);

#line 80 "parser.tab.c" /* yacc.c:339  */

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

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.h".  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
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
    TK_PR_INT = 258,
    TK_PR_FLOAT = 259,
    TK_PR_BOOL = 260,
    TK_PR_CHAR = 261,
    TK_PR_STRING = 262,
    TK_PR_IF = 263,
    TK_PR_THEN = 264,
    TK_PR_ELSE = 265,
    TK_PR_WHILE = 266,
    TK_PR_DO = 267,
    TK_PR_INPUT = 268,
    TK_PR_OUTPUT = 269,
    TK_PR_RETURN = 270,
    TK_PR_CONST = 271,
    TK_PR_STATIC = 272,
    TK_PR_FOREACH = 273,
    TK_PR_FOR = 274,
    TK_PR_SWITCH = 275,
    TK_PR_CASE = 276,
    TK_PR_BREAK = 277,
    TK_PR_CONTINUE = 278,
    TK_PR_CLASS = 279,
    TK_PR_PRIVATE = 280,
    TK_PR_PUBLIC = 281,
    TK_PR_PROTECTED = 282,
    TK_PR_END = 283,
    TK_PR_DEFAULT = 284,
    TK_OC_LE = 285,
    TK_OC_GE = 286,
    TK_OC_EQ = 287,
    TK_OC_NE = 288,
    TK_OC_AND = 289,
    TK_OC_OR = 290,
    TK_OC_SL = 291,
    TK_OC_SR = 292,
    TK_LIT_INT = 293,
    TK_LIT_FLOAT = 294,
    TK_LIT_FALSE = 295,
    TK_LIT_TRUE = 296,
    TK_LIT_CHAR = 297,
    TK_LIT_STRING = 298,
    TK_IDENTIFICADOR = 299,
    TOKEN_ERRO = 300
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 15 "parser.y" /* yacc.c:355  */

	TOKEN_INFO *valor_lexico;
    node_t *no;

#line 171 "parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 188 "parser.tab.c" /* yacc.c:358  */

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
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   674

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  67
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  115
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  198

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    58,     2,    62,     2,    64,    59,     2,
      51,    52,    60,    50,    47,    57,     2,    63,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    56,    46,
       2,    55,     2,    61,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    48,     2,    49,    66,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    53,    65,    54,     2,     2,     2,     2,
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
      45
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    77,    77,    80,    81,    84,    85,    89,    90,    91,
      92,    93,    96,    97,    98,    99,   100,   101,   105,   106,
     109,   110,   113,   114,   115,   119,   122,   123,   127,   128,
     132,   133,   134,   135,   139,   140,   144,   145,   146,   147,
     151,   152,   153,   154,   155,   156,   160,   161,   162,   163,
     167,   170,   171,   175,   178,   179,   182,   185,   194,   197,
     200,   204,   208,   209,   210,   214,   217,   225,   226,   229,
     230,   231,   235,   241,   245,   246,   250,   257,   264,   265,
     266,   267,   268,   269,   270,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   291,   292,   293,   294,   295,   296,   299,   300,   303,
     304,   306,   307,   308,   309,   310
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TK_PR_INT", "TK_PR_FLOAT", "TK_PR_BOOL",
  "TK_PR_CHAR", "TK_PR_STRING", "TK_PR_IF", "TK_PR_THEN", "TK_PR_ELSE",
  "TK_PR_WHILE", "TK_PR_DO", "TK_PR_INPUT", "TK_PR_OUTPUT", "TK_PR_RETURN",
  "TK_PR_CONST", "TK_PR_STATIC", "TK_PR_FOREACH", "TK_PR_FOR",
  "TK_PR_SWITCH", "TK_PR_CASE", "TK_PR_BREAK", "TK_PR_CONTINUE",
  "TK_PR_CLASS", "TK_PR_PRIVATE", "TK_PR_PUBLIC", "TK_PR_PROTECTED",
  "TK_PR_END", "TK_PR_DEFAULT", "TK_OC_LE", "TK_OC_GE", "TK_OC_EQ",
  "TK_OC_NE", "TK_OC_AND", "TK_OC_OR", "TK_OC_SL", "TK_OC_SR",
  "TK_LIT_INT", "TK_LIT_FLOAT", "TK_LIT_FALSE", "TK_LIT_TRUE",
  "TK_LIT_CHAR", "TK_LIT_STRING", "TK_IDENTIFICADOR", "TOKEN_ERRO", "';'",
  "','", "'['", "']'", "'+'", "'('", "')'", "'{'", "'}'", "'='", "':'",
  "'-'", "'!'", "'&'", "'*'", "'?'", "'#'", "'/'", "'%'", "'|'", "'^'",
  "$accept", "programa_star", "programa", "def", "tipo", "literais",
  "global", "lista", "varglobal", "funcao", "func_header", "func_params",
  "func_prim_arg", "func_block", "func_commands", "comando",
  "cmd_decl_var", "lista_decl_var", "inic_decl_var", "cmd_attrib",
  "cmd_io", "cmd_func_call", "cmd_func_call_args", "cmd_shift", "shift_op",
  "cmd_simple_keyword", "cmd_fluxo", "cmd_fluxo_else", "cmd_iter",
  "unary_op", "binary_op", "exp", "exp_unit", "exp_value", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,    59,    44,    91,    93,
      43,    40,    41,   123,   125,    61,    58,    45,    33,    38,
      42,    63,    35,    47,    37,   124,    94
};
# endif

#define YYPACT_NINF -134

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-134)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      65,  -134,  -134,  -134,  -134,  -134,   130,     7,  -134,    65,
     -12,  -134,  -134,   -37,     9,  -134,  -134,   -28,    -2,    10,
      95,  -134,   -28,    13,   -21,     8,  -134,  -134,    11,    15,
      27,    17,   152,   562,   130,    70,    28,  -134,  -134,    -9,
    -134,    20,    26,    37,  -134,  -134,  -134,  -134,  -134,  -134,
     156,  -134,  -134,  -134,    36,    55,   130,  -134,    51,    52,
      57,  -134,   562,   562,  -134,  -134,  -134,  -134,  -134,  -134,
    -134,  -134,  -134,  -134,  -134,  -134,  -134,     3,  -134,   562,
    -134,  -134,  -134,  -134,  -134,  -134,  -134,    50,   533,  -134,
    -134,    20,   130,    20,    63,  -134,  -134,   562,   562,   562,
      75,    -4,  -134,  -134,   156,  -134,  -134,    66,    72,    78,
    -134,   151,   188,   562,   225,  -134,  -134,  -134,  -134,  -134,
    -134,  -134,  -134,  -134,  -134,  -134,  -134,  -134,   562,  -134,
    -134,  -134,  -134,   587,  -134,    20,  -134,    -7,    73,   262,
      74,   299,   533,  -134,   189,    20,    83,  -134,  -134,    84,
     116,   -37,   126,   336,  -134,   373,   562,  -134,  -134,   562,
     562,   -15,  -134,   562,  -134,  -134,  -134,    20,   116,  -134,
     131,   -37,  -134,   612,   410,   447,   484,   562,   102,  -134,
    -134,  -134,   -37,  -134,  -134,   562,  -134,  -134,    87,    63,
     533,  -134,  -134,   521,    91,  -134,   -37,  -134
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     7,     8,     9,    10,    11,     0,     0,     2,     4,
       0,     5,     6,     0,     0,     1,     3,    22,     0,    21,
       0,    25,    22,     0,     0,     0,    26,    19,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    70,    71,     0,
      35,     0,     0,     0,    40,    41,    42,    43,    44,    45,
      38,    73,    27,    18,     0,     0,     0,    29,     0,     0,
      22,    20,     0,     0,    58,    15,    14,    13,    17,    12,
      16,    59,    60,   112,   113,   114,   115,   109,    78,     0,
      79,    80,    81,    82,    83,    84,   111,     0,    69,   106,
     107,     0,     0,     0,     0,    67,    68,     0,    64,     0,
       0,    51,    46,    34,    37,    39,    23,     0,     0,    32,
      28,     0,     0,     0,     0,   108,    93,    94,    95,    96,
      97,    98,   100,    99,    85,    86,    91,    87,     0,    88,
      89,    90,    92,     0,    49,     0,    47,     0,     0,     0,
       0,    62,    56,    65,     0,     0,    50,    36,    24,    33,
       0,     0,     0,     0,   101,     0,     0,   102,    48,     0,
       0,     0,    61,    64,    54,    55,    53,     0,     0,    30,
      75,     0,   110,     0,     0,     0,     0,     0,     0,    63,
      52,    31,     0,    72,    77,     0,   104,   103,     0,     0,
      57,    66,    74,     0,     0,   105,     0,    76
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -134,  -134,   135,  -134,     0,     2,  -134,    22,  -134,  -134,
    -134,   125,  -131,  -133,   -46,  -134,  -134,   -83,  -134,   -92,
    -134,   -17,   -11,  -134,   -13,  -134,  -134,  -134,  -134,  -134,
    -134,   -32,  -128,    64
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     7,     8,     9,    41,    72,    11,    18,    19,    12,
      13,    26,    59,    21,    42,    43,    44,   102,   146,    45,
      46,    86,   140,    48,   100,    49,    50,   183,    51,    87,
     133,   141,    89,    90
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      10,    88,   138,    47,   105,   157,    14,    15,   134,    10,
     136,     1,     2,     3,     4,     5,    20,    54,   170,   169,
      24,    95,    96,    25,    56,    58,   144,    95,    96,    55,
     111,   112,    17,    47,    91,    93,    23,   181,   184,    97,
     177,   159,    98,   145,    27,   186,    99,   114,    99,   192,
      61,   113,   158,    22,    98,    60,   108,    28,   147,    53,
      57,    64,   166,   197,   101,   139,    62,   142,     1,     2,
       3,     4,     5,     1,     2,     3,     4,     5,    63,    94,
     103,   153,     6,   104,   180,   106,    92,    47,    73,    74,
      75,    76,   135,   107,    77,   109,   155,   194,     1,     2,
       3,     4,     5,    29,   110,    24,    30,   137,    31,    32,
      33,    34,    35,   143,    36,   148,   149,    37,    38,     1,
       2,     3,     4,     5,   174,   150,   162,   175,   176,   160,
     167,   168,    56,     1,     2,     3,     4,     5,   171,    39,
     191,   182,   177,   196,    16,   190,   165,    52,   178,    40,
      58,   115,   179,   193,     0,     0,     0,     0,     0,     1,
       2,     3,     4,     5,    29,     0,     0,    30,    58,    31,
      32,    33,    34,    35,     0,    36,     0,     0,    37,    38,
       0,   116,   117,   118,   119,   120,   121,   122,   123,     0,
      65,    66,    67,    68,    69,    70,    71,     0,     0,     0,
      39,   124,     0,   151,     0,     0,     0,     0,   125,     0,
     126,   127,   128,     0,   129,   130,   131,   132,   116,   117,
     118,   119,   120,   121,   122,   123,     0,    65,    66,    67,
      68,    69,    70,   164,     0,     0,     0,     0,   124,     0,
     152,     0,     0,     0,     0,   125,     0,   126,   127,   128,
       0,   129,   130,   131,   132,   116,   117,   118,   119,   120,
     121,   122,   123,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   124,     0,   154,     0,     0,
       0,     0,   125,     0,   126,   127,   128,     0,   129,   130,
     131,   132,   116,   117,   118,   119,   120,   121,   122,   123,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   161,   124,     0,     0,     0,     0,     0,     0,   125,
       0,   126,   127,   128,     0,   129,   130,   131,   132,   116,
     117,   118,   119,   120,   121,   122,   123,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   163,     0,     0,   124,
       0,     0,     0,     0,     0,     0,   125,     0,   126,   127,
     128,     0,   129,   130,   131,   132,   116,   117,   118,   119,
     120,   121,   122,   123,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   172,   124,     0,     0,     0,
       0,     0,     0,   125,     0,   126,   127,   128,     0,   129,
     130,   131,   132,   116,   117,   118,   119,   120,   121,   122,
     123,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   124,     0,     0,     0,     0,     0,   173,
     125,     0,   126,   127,   128,     0,   129,   130,   131,   132,
     116,   117,   118,   119,   120,   121,   122,   123,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     124,     0,   187,     0,     0,     0,     0,   125,     0,   126,
     127,   128,     0,   129,   130,   131,   132,   116,   117,   118,
     119,   120,   121,   122,   123,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   188,   124,     0,     0,
       0,     0,     0,     0,   125,     0,   126,   127,   128,     0,
     129,   130,   131,   132,   116,   117,   118,   119,   120,   121,
     122,   123,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   124,     0,     0,     0,     0,     0,
     189,   125,     0,   126,   127,   128,     0,   129,   130,   131,
     132,   116,   117,   118,   119,   120,   121,   122,   123,     0,
       0,     0,     0,   116,   117,   118,   119,   120,   121,   122,
     123,   124,     0,   195,     0,     0,     0,     0,   125,     0,
     126,   127,   128,   124,   129,   130,   131,   132,     0,     0,
     125,     0,   126,   127,   128,     0,   129,   130,   131,   132,
      73,    74,    75,    76,     0,     0,    77,     0,     0,     0,
       0,     0,    78,    79,     0,     0,     0,     0,     0,    80,
      81,    82,    83,    84,    85,    73,    74,    75,    76,     0,
       0,    77,     0,     0,     0,     0,     0,    78,   156,     0,
       0,     0,     0,     0,    80,    81,    82,    83,    84,    85,
      73,    74,    75,    76,     0,     0,    77,     0,     0,     0,
       0,     0,    78,   185,     0,     0,     0,     0,     0,    80,
      81,    82,    83,    84,    85
};

static const yytype_int16 yycheck[] =
{
       0,    33,    94,    20,    50,   133,     6,     0,    91,     9,
      93,     3,     4,     5,     6,     7,    53,    38,   151,   150,
      48,    36,    37,    51,    16,    25,    30,    36,    37,    50,
      62,    63,    44,    50,    34,    35,    14,   168,   171,    48,
      55,    48,    51,    47,    46,   173,    55,    79,    55,   182,
      28,    48,   135,    44,    51,    44,    56,    47,   104,    46,
      52,    44,   145,   196,    44,    97,    51,    99,     3,     4,
       5,     6,     7,     3,     4,     5,     6,     7,    51,    51,
      54,   113,    17,    46,   167,    49,    16,   104,    38,    39,
      40,    41,    92,    38,    44,    44,   128,   189,     3,     4,
       5,     6,     7,     8,    52,    48,    11,    44,    13,    14,
      15,    16,    17,    38,    19,    49,    44,    22,    23,     3,
       4,     5,     6,     7,   156,    47,    52,   159,   160,    56,
      47,    47,    16,     3,     4,     5,     6,     7,    12,    44,
      38,    10,    55,    52,     9,   177,   144,    22,   161,    54,
     150,    87,   163,   185,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,    -1,    -1,    11,   168,    13,
      14,    15,    16,    17,    -1,    19,    -1,    -1,    22,    23,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,    -1,
      38,    39,    40,    41,    42,    43,    44,    -1,    -1,    -1,
      44,    50,    -1,    52,    -1,    -1,    -1,    -1,    57,    -1,
      59,    60,    61,    -1,    63,    64,    65,    66,    30,    31,
      32,    33,    34,    35,    36,    37,    -1,    38,    39,    40,
      41,    42,    43,    44,    -1,    -1,    -1,    -1,    50,    -1,
      52,    -1,    -1,    -1,    -1,    57,    -1,    59,    60,    61,
      -1,    63,    64,    65,    66,    30,    31,    32,    33,    34,
      35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    50,    -1,    52,    -1,    -1,
      -1,    -1,    57,    -1,    59,    60,    61,    -1,    63,    64,
      65,    66,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    50,    -1,    -1,    -1,    -1,    -1,    -1,    57,
      -1,    59,    60,    61,    -1,    63,    64,    65,    66,    30,
      31,    32,    33,    34,    35,    36,    37,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,    50,
      -1,    -1,    -1,    -1,    -1,    -1,    57,    -1,    59,    60,
      61,    -1,    63,    64,    65,    66,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    50,    -1,    -1,    -1,
      -1,    -1,    -1,    57,    -1,    59,    60,    61,    -1,    63,
      64,    65,    66,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    50,    -1,    -1,    -1,    -1,    -1,    56,
      57,    -1,    59,    60,    61,    -1,    63,    64,    65,    66,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      50,    -1,    52,    -1,    -1,    -1,    -1,    57,    -1,    59,
      60,    61,    -1,    63,    64,    65,    66,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    -1,    -1,
      -1,    -1,    -1,    -1,    57,    -1,    59,    60,    61,    -1,
      63,    64,    65,    66,    30,    31,    32,    33,    34,    35,
      36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    50,    -1,    -1,    -1,    -1,    -1,
      56,    57,    -1,    59,    60,    61,    -1,    63,    64,    65,
      66,    30,    31,    32,    33,    34,    35,    36,    37,    -1,
      -1,    -1,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,    50,    -1,    52,    -1,    -1,    -1,    -1,    57,    -1,
      59,    60,    61,    50,    63,    64,    65,    66,    -1,    -1,
      57,    -1,    59,    60,    61,    -1,    63,    64,    65,    66,
      38,    39,    40,    41,    -1,    -1,    44,    -1,    -1,    -1,
      -1,    -1,    50,    51,    -1,    -1,    -1,    -1,    -1,    57,
      58,    59,    60,    61,    62,    38,    39,    40,    41,    -1,
      -1,    44,    -1,    -1,    -1,    -1,    -1,    50,    51,    -1,
      -1,    -1,    -1,    -1,    57,    58,    59,    60,    61,    62,
      38,    39,    40,    41,    -1,    -1,    44,    -1,    -1,    -1,
      -1,    -1,    50,    51,    -1,    -1,    -1,    -1,    -1,    57,
      58,    59,    60,    61,    62
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,    17,    68,    69,    70,
      71,    73,    76,    77,    71,     0,    69,    44,    74,    75,
      53,    80,    44,    74,    48,    51,    78,    46,    47,     8,
      11,    13,    14,    15,    16,    17,    19,    22,    23,    44,
      54,    71,    81,    82,    83,    86,    87,    88,    90,    92,
      93,    95,    78,    46,    38,    50,    16,    52,    71,    79,
      44,    74,    51,    51,    44,    38,    39,    40,    41,    42,
      43,    44,    72,    38,    39,    40,    41,    44,    50,    51,
      57,    58,    59,    60,    61,    62,    88,    96,    98,    99,
     100,    71,    16,    71,    51,    36,    37,    48,    51,    55,
      91,    44,    84,    54,    46,    81,    49,    38,    71,    44,
      52,    98,    98,    48,    98,   100,    30,    31,    32,    33,
      34,    35,    36,    37,    50,    57,    59,    60,    61,    63,
      64,    65,    66,    97,    84,    71,    84,    44,    86,    98,
      89,    98,    98,    38,    30,    47,    85,    81,    49,    44,
      47,    52,    52,    98,    52,    98,    51,    99,    84,    48,
      56,    49,    52,    47,    44,    72,    84,    47,    47,    79,
      80,    12,    49,    56,    98,    98,    98,    55,    91,    89,
      84,    79,    10,    94,    80,    51,    99,    52,    49,    56,
      98,    38,    80,    98,    86,    52,    52,    80
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    67,    68,    69,    69,    70,    70,    71,    71,    71,
      71,    71,    72,    72,    72,    72,    72,    72,    73,    73,
      74,    74,    75,    75,    75,    76,    77,    77,    78,    78,
      79,    79,    79,    79,    80,    80,    81,    81,    81,    81,
      82,    82,    82,    82,    82,    82,    83,    83,    83,    83,
      84,    84,    84,    84,    85,    85,    86,    86,    87,    87,
      87,    88,    89,    89,    89,    90,    90,    91,    91,    92,
      92,    92,    93,    93,    94,    94,    95,    95,    96,    96,
      96,    96,    96,    96,    96,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    98,    98,    98,    98,    98,    98,    99,    99,   100,
     100,   100,   100,   100,   100,   100
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     3,
       3,     1,     1,     4,     5,     2,     3,     4,     3,     2,
       4,     5,     2,     3,     3,     2,     3,     2,     1,     2,
       1,     1,     1,     1,     1,     1,     2,     3,     4,     3,
       2,     1,     4,     3,     2,     2,     3,     6,     2,     2,
       2,     4,     1,     3,     0,     3,     6,     1,     1,     2,
       1,     1,     6,     1,     2,     0,     9,     6,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     5,     5,     7,     1,     1,     2,     1,
       4,     1,     1,     1,     1,     1
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
        case 2:
#line 77 "parser.y" /* yacc.c:1646  */
    { arvore = (yyvsp[0].no); }
#line 1511 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 80 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = join_nodes((yyvsp[-1].no), (yyvsp[0].no)); }
#line 1517 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 81 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = NULL; }
#line 1523 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 84 "parser.y" /* yacc.c:1646  */
    { }
#line 1529 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 85 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = (yyvsp[0].no); }
#line 1535 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 89 "parser.y" /* yacc.c:1646  */
    { }
#line 1541 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 90 "parser.y" /* yacc.c:1646  */
    { }
#line 1547 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 91 "parser.y" /* yacc.c:1646  */
    {  }
#line 1553 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 92 "parser.y" /* yacc.c:1646  */
    { }
#line 1559 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 93 "parser.y" /* yacc.c:1646  */
    { }
#line 1565 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 96 "parser.y" /* yacc.c:1646  */
    { char str[16]; sprintf(str,"%c",(yyvsp[0].valor_lexico)->valor.c); (yyval.no) = cria_nodo(str,(yyvsp[0].valor_lexico)); }
#line 1571 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 97 "parser.y" /* yacc.c:1646  */
    { char str[16]; sprintf(str,"false"); (yyval.no) = cria_nodo(str,(yyvsp[0].valor_lexico)); }
#line 1577 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 98 "parser.y" /* yacc.c:1646  */
    { char str[16]; sprintf(str,"%f",(yyvsp[0].valor_lexico)->valor.f); (yyval.no) = cria_nodo(str,(yyvsp[0].valor_lexico)); }
#line 1583 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 99 "parser.y" /* yacc.c:1646  */
    { char str[16]; sprintf(str,"%d",(yyvsp[0].valor_lexico)->valor.i); (yyval.no) = cria_nodo(str,(yyvsp[0].valor_lexico)); }
#line 1589 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 100 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = cria_nodo((yyvsp[0].valor_lexico)->valor.s,(yyvsp[0].valor_lexico)); }
#line 1595 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 101 "parser.y" /* yacc.c:1646  */
    { char str[16]; sprintf(str,"true"); (yyval.no) = cria_nodo(str,(yyvsp[0].valor_lexico)); }
#line 1601 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 105 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = (yyvsp[-1].no); }
#line 1607 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 106 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = (yyvsp[-1].no); }
#line 1613 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 109 "parser.y" /* yacc.c:1646  */
    { /* variaveis sem inicializacao nao fazem parte da arvore */ }
#line 1619 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 110 "parser.y" /* yacc.c:1646  */
    { }
#line 1625 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 113 "parser.y" /* yacc.c:1646  */
    { free((yyvsp[0].valor_lexico)); }
#line 1631 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 114 "parser.y" /* yacc.c:1646  */
    { free((yyvsp[-3].valor_lexico)); free((yyvsp[-1].valor_lexico)); }
#line 1637 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 115 "parser.y" /* yacc.c:1646  */
    { free((yyvsp[-4].valor_lexico)); free((yyvsp[-1].valor_lexico)); }
#line 1643 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 119 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = (yyvsp[0].no); }
#line 1649 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 122 "parser.y" /* yacc.c:1646  */
    { free((yyvsp[-1].valor_lexico)); }
#line 1655 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 123 "parser.y" /* yacc.c:1646  */
    { free((yyvsp[-1].valor_lexico)); }
#line 1661 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 127 "parser.y" /* yacc.c:1646  */
    { }
#line 1667 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 128 "parser.y" /* yacc.c:1646  */
    { }
#line 1673 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 132 "parser.y" /* yacc.c:1646  */
    { free((yyvsp[-2].valor_lexico)); }
#line 1679 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 133 "parser.y" /* yacc.c:1646  */
    { free((yyvsp[-2].valor_lexico)); }
#line 1685 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 134 "parser.y" /* yacc.c:1646  */
    { free((yyvsp[0].valor_lexico)); }
#line 1691 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 135 "parser.y" /* yacc.c:1646  */
    { free((yyvsp[0].valor_lexico)); }
#line 1697 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 139 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = (yyvsp[-1].no); }
#line 1703 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 140 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = NULL; }
#line 1709 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 144 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = join_nodes((yyvsp[-2].no), (yyvsp[0].no)); }
#line 1715 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 145 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = join_nodes((yyvsp[-1].no), NULL); }
#line 1721 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 146 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = join_nodes((yyvsp[0].no), NULL); }
#line 1727 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 147 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = join_nodes((yyvsp[-1].no), (yyvsp[0].no)); }
#line 1733 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 151 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = (yyvsp[0].no); }
#line 1739 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 152 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = (yyvsp[0].no); }
#line 1745 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 153 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = (yyvsp[0].no); }
#line 1751 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 154 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = (yyvsp[0].no); }
#line 1757 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 155 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = (yyvsp[0].no); }
#line 1763 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 156 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = (yyvsp[0].no); }
#line 1769 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 160 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = (yyvsp[0].no); }
#line 1775 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 161 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = (yyvsp[0].no); }
#line 1781 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 162 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = (yyvsp[0].no); }
#line 1787 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 163 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = (yyvsp[0].no); }
#line 1793 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 167 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = cria_nodo("<=",NULL); 
        char str2[16]; sprintf(str2,"%s",(yyvsp[-1].valor_lexico)->valor.s); node_t* aux = cria_nodo(str2,(yyvsp[-1].valor_lexico));
         add_child((yyval.no), aux); add_child((yyval.no), (yyvsp[0].no));  }
#line 1801 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 170 "parser.y" /* yacc.c:1646  */
    { free((yyvsp[0].valor_lexico)); (yyval.no) = NULL; }
#line 1807 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 171 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = cria_nodo("<=",NULL); 
        char str2[16]; sprintf(str2,"%s",(yyvsp[-3].valor_lexico)->valor.s); node_t* aux = cria_nodo(str2,(yyvsp[-3].valor_lexico));
         add_child((yyval.no), aux); add_child((yyval.no), (yyvsp[-2].no));  
         (yyval.no) = join_nodes((yyval.no), (yyvsp[0].no)); }
#line 1816 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 175 "parser.y" /* yacc.c:1646  */
    { free((yyvsp[-2].valor_lexico)); (yyval.no) = (yyvsp[0].no); }
#line 1822 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 178 "parser.y" /* yacc.c:1646  */
    { free((yyvsp[-1].valor_lexico)); char str[16]; sprintf(str,"%s",(yyvsp[0].valor_lexico)->valor.s); (yyval.no) = cria_nodo(str,(yyvsp[0].valor_lexico)); }
#line 1828 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 179 "parser.y" /* yacc.c:1646  */
    { free((yyvsp[-1].valor_lexico)); (yyval.no) = (yyvsp[0].no); }
#line 1834 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 182 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = cria_nodo("=", NULL); 
        char str2[16]; sprintf(str2,"%s",(yyvsp[-2].valor_lexico)->valor.s); node_t* aux = cria_nodo(str2,(yyvsp[-2].valor_lexico)); 
        add_child((yyval.no), aux); add_child((yyval.no), (yyvsp[0].no)); }
#line 1842 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 185 "parser.y" /* yacc.c:1646  */
    { char str[16]; sprintf(str,"%s",(yyvsp[-5].valor_lexico)->valor.s); node_t* aux = cria_nodo(str,(yyvsp[-5].valor_lexico)); 
        node_t* aux2 = cria_nodo("[]",NULL); 
        add_child(aux2, aux); add_child(aux2,(yyvsp[-3].no)); 
        (yyval.no) = cria_nodo("=", NULL);
        add_child((yyval.no), aux2); add_child((yyval.no), (yyvsp[0].no));
        }
#line 1853 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 194 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = cria_nodo("input", NULL); 
        char str2[16]; sprintf(str2,"%s",(yyvsp[0].valor_lexico)->valor.s); node_t* aux = cria_nodo(str2,(yyvsp[0].valor_lexico));
        add_child((yyval.no),aux); }
#line 1861 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 197 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = cria_nodo("output", NULL); 
        char str2[16]; sprintf(str2,"%s",(yyvsp[0].valor_lexico)->valor.s); node_t* aux = cria_nodo(str2,(yyvsp[0].valor_lexico));
        add_child((yyval.no),aux); }
#line 1869 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 200 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = cria_nodo("output", NULL); add_child((yyval.no),(yyvsp[0].no)); }
#line 1875 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 204 "parser.y" /* yacc.c:1646  */
    { char str[16]; sprintf(str,"call %s",(yyvsp[-3].valor_lexico)->valor.s); (yyval.no) = cria_nodo(str,(yyvsp[-3].valor_lexico)); add_child((yyval.no),(yyvsp[-1].no)); }
#line 1881 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 208 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = (yyvsp[0].no); }
#line 1887 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 209 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = join_nodes((yyvsp[-2].no),(yyvsp[0].no)); }
#line 1893 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 210 "parser.y" /* yacc.c:1646  */
    { }
#line 1899 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 214 "parser.y" /* yacc.c:1646  */
    { char str[16]; sprintf(str,"call %s",(yyvsp[-2].valor_lexico)->valor.s); node_t* aux = cria_nodo(str,(yyvsp[-2].valor_lexico)); 
       char str2[16]; sprintf(str2,"%d",(yyvsp[0].valor_lexico)->valor.i); node_t* aux2 = cria_nodo(str2,(yyvsp[0].valor_lexico)); 
       add_child((yyvsp[-1].no), aux); add_child((yyvsp[-1].no), aux2); (yyval.no) = (yyvsp[-1].no); }
#line 1907 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 217 "parser.y" /* yacc.c:1646  */
    { char str[16]; sprintf(str,"%s",(yyvsp[-5].valor_lexico)->valor.s); node_t* aux = cria_nodo(str,(yyvsp[-5].valor_lexico)); 
        node_t* aux2 = cria_nodo("[]",NULL); 
        add_child(aux2, aux); add_child(aux2,(yyvsp[-3].no)); 
        char str3[16]; sprintf(str3,"%d",(yyvsp[0].valor_lexico)->valor.i); node_t* aux3 = cria_nodo(str3,(yyvsp[0].valor_lexico));
        add_child((yyvsp[-1].no), aux2); add_child((yyvsp[-1].no), aux3); (yyval.no) = (yyvsp[-1].no);
        }
#line 1918 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 225 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = cria_nodo("<<",(yyvsp[0].valor_lexico)); }
#line 1924 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 226 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = cria_nodo(">>",(yyvsp[0].valor_lexico)); }
#line 1930 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 229 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = cria_nodo("return", NULL); add_child((yyval.no),(yyvsp[0].no)); }
#line 1936 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 230 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = cria_nodo("break", NULL);  }
#line 1942 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 231 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = cria_nodo("continue", NULL);  }
#line 1948 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 235 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.no) = cria_nodo("if", NULL);
        add_child((yyval.no), (yyvsp[-3].no));
        add_child((yyval.no), (yyvsp[-1].no));
        add_child((yyval.no), (yyvsp[0].no));
        }
#line 1959 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 241 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = (yyvsp[0].no); }
#line 1965 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 245 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = (yyvsp[0].no);}
#line 1971 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 246 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = NULL; }
#line 1977 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 250 "parser.y" /* yacc.c:1646  */
    {
        (yyval.no) = cria_nodo("for", NULL);
        add_child((yyval.no), (yyvsp[-6].no));
        add_child((yyval.no), (yyvsp[-4].no));
        add_child((yyval.no), (yyvsp[-2].no));
        add_child((yyval.no), (yyvsp[0].no));
    }
#line 1989 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 257 "parser.y" /* yacc.c:1646  */
    {
        (yyval.no) = cria_nodo("while", NULL);
        add_child((yyval.no), (yyvsp[-3].no));
        add_child((yyval.no), (yyvsp[0].no));
    }
#line 1999 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 264 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = cria_nodo("+", NULL); }
#line 2005 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 265 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = cria_nodo("-", NULL); }
#line 2011 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 266 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = cria_nodo("!", NULL); }
#line 2017 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 267 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = cria_nodo("&", NULL); }
#line 2023 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 268 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = cria_nodo("*", NULL); }
#line 2029 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 269 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = cria_nodo("?", NULL); }
#line 2035 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 270 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = cria_nodo("#", NULL); }
#line 2041 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 273 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = cria_nodo("+", NULL); }
#line 2047 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 274 "parser.y" /* yacc.c:1646  */
    {  (yyval.no) = cria_nodo("-", NULL); }
#line 2053 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 275 "parser.y" /* yacc.c:1646  */
    {  (yyval.no) = cria_nodo("*", NULL); }
#line 2059 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 276 "parser.y" /* yacc.c:1646  */
    {  (yyval.no) = cria_nodo("/", NULL); }
#line 2065 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 277 "parser.y" /* yacc.c:1646  */
    {  (yyval.no) = cria_nodo("%", NULL); }
#line 2071 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 278 "parser.y" /* yacc.c:1646  */
    {  (yyval.no) = cria_nodo("|", NULL); }
#line 2077 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 279 "parser.y" /* yacc.c:1646  */
    {  (yyval.no) = cria_nodo("&", NULL); }
#line 2083 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 280 "parser.y" /* yacc.c:1646  */
    {  (yyval.no) = cria_nodo("^", NULL); }
#line 2089 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 281 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = cria_nodo("<=",(yyvsp[0].valor_lexico)); }
#line 2095 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 282 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = cria_nodo(">=",(yyvsp[0].valor_lexico)); }
#line 2101 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 283 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = cria_nodo("==",(yyvsp[0].valor_lexico)); }
#line 2107 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 284 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = cria_nodo("!=",(yyvsp[0].valor_lexico)); }
#line 2113 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 285 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = cria_nodo("&&",(yyvsp[0].valor_lexico)); }
#line 2119 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 286 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = cria_nodo("||",(yyvsp[0].valor_lexico)); }
#line 2125 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 287 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = cria_nodo(">>",(yyvsp[0].valor_lexico)); }
#line 2131 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 288 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = cria_nodo("<<",(yyvsp[0].valor_lexico)); }
#line 2137 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 291 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = (yyvsp[-1].no); }
#line 2143 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 292 "parser.y" /* yacc.c:1646  */
    { add_child((yyvsp[-1].no),(yyvsp[-2].no)); add_child((yyvsp[-1].no),(yyvsp[0].no)); (yyval.no) = (yyvsp[-1].no);  }
#line 2149 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 293 "parser.y" /* yacc.c:1646  */
    { add_child((yyvsp[-3].no),(yyvsp[-4].no)); add_child((yyvsp[-3].no),(yyvsp[-1].no)); (yyval.no) = (yyvsp[-3].no);  }
#line 2155 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 294 "parser.y" /* yacc.c:1646  */
    {  (yyval.no) = cria_nodo("?:", NULL); add_child((yyval.no),(yyvsp[-4].no)); add_child((yyval.no),(yyvsp[-2].no)); add_child((yyval.no),(yyvsp[0].no)); }
#line 2161 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 295 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = cria_nodo("?:", NULL); add_child((yyval.no),(yyvsp[-6].no)); add_child((yyval.no),(yyvsp[-4].no)); add_child((yyval.no),(yyvsp[-1].no)); }
#line 2167 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 296 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = (yyvsp[0].no); }
#line 2173 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 299 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = (yyvsp[0].no); }
#line 2179 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 300 "parser.y" /* yacc.c:1646  */
    { add_child((yyvsp[-1].no),(yyvsp[0].no)); (yyval.no) = (yyvsp[-1].no); }
#line 2185 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 303 "parser.y" /* yacc.c:1646  */
    { char str[16]; sprintf(str,"%s",(yyvsp[0].valor_lexico)->valor.s); (yyval.no) = cria_nodo(str,(yyvsp[0].valor_lexico)); }
#line 2191 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 304 "parser.y" /* yacc.c:1646  */
    { char str[16]; sprintf(str,"%s",(yyvsp[-3].valor_lexico)->valor.s); node_t* aux = cria_nodo(str,(yyvsp[-3].valor_lexico)); 
    	(yyval.no) = cria_nodo("[]",NULL); add_child((yyval.no),aux); add_child((yyval.no),(yyvsp[-1].no)); }
#line 2198 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 306 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = (yyvsp[0].no); }
#line 2204 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 307 "parser.y" /* yacc.c:1646  */
    { char str[16]; sprintf(str,"%d",(yyvsp[0].valor_lexico)->valor.i); (yyval.no) = cria_nodo(str,(yyvsp[0].valor_lexico)); }
#line 2210 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 308 "parser.y" /* yacc.c:1646  */
    { char str[16]; sprintf(str,"%f",(yyvsp[0].valor_lexico)->valor.f); (yyval.no) = cria_nodo(str,(yyvsp[0].valor_lexico)); }
#line 2216 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 309 "parser.y" /* yacc.c:1646  */
    { char str[16]; sprintf(str,"%d",(yyvsp[0].valor_lexico)->valor.b); (yyval.no) = cria_nodo(str,(yyvsp[0].valor_lexico)); }
#line 2222 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 310 "parser.y" /* yacc.c:1646  */
    { char str[16]; sprintf(str,"%d",(yyvsp[0].valor_lexico)->valor.b); (yyval.no) = cria_nodo(str,(yyvsp[0].valor_lexico)); }
#line 2228 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 2232 "parser.tab.c" /* yacc.c:1646  */
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
#line 313 "parser.y" /* yacc.c:1906  */

/*
    TODO: REESCREVER ISSO AQUI QUE TIROU PONTO NA ETAPA2
*/
int yyerror(const char *str)
{
    fprintf(stderr,"error: %s in line %d\n", str, yylineno);
    return 1;
}


