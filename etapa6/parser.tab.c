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

#include "iloc_generator.h"

#include<stdio.h>
#include <stdlib.h>
#include <string.h>

#define YYERROR_VERBOSE 1

extern void *arvore;

extern int yylineno;
int yylex(void);
int yyerror (char const *s);

STACK* hash_stack;
int v_type;
int v_static;
int v_const;
int f_type;

CODE_BLOCK* iloc_code;
int has_main_function;
char *return_label;


#line 93 "parser.tab.c" /* yacc.c:339  */

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
#line 37 "parser.y" /* yacc.c:355  */

	TOKEN_INFO *valor_lexico;
    node_t *no;

#line 184 "parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 201 "parser.tab.c" /* yacc.c:358  */

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
#define YYLAST   425

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  69
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  50
/* YYNRULES -- Number of rules.  */
#define YYNRULES  137
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  228

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
      67,    55,    68,    61,     2,     2,     2,     2,     2,     2,
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
       0,    99,    99,   111,   112,   115,   116,   120,   121,   122,
     123,   124,   127,   128,   129,   130,   131,   132,   136,   137,
     140,   141,   144,   145,   146,   150,   160,   160,   168,   168,
     179,   180,   184,   189,   194,   199,   206,   207,   211,   212,
     213,   214,   218,   219,   220,   221,   222,   223,   224,   228,
     228,   232,   232,   236,   236,   241,   241,   247,   247,   255,
     263,   274,   274,   293,   293,   309,   312,   317,   331,   349,
     358,   367,   378,   387,   388,   389,   393,   397,   406,   407,
     410,   413,   414,   418,   418,   425,   429,   429,   430,   434,
     434,   444,   444,   452,   453,   454,   455,   456,   457,   458,
     462,   463,   464,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   483,   484,   485,   486,
     498,   507,   510,   511,   512,   513,   516,   517,   518,   521,
     522,   524,   525,   526,   527,   528,   529,   530
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
  "'<'", "'>'", "$accept", "programa_star", "programa", "def", "tipo",
  "literais", "global", "lista", "varglobal", "funcao", "func_header",
  "$@1", "$@2", "func_params", "func_prim_arg", "func_block",
  "func_commands", "comando", "cmd_scope", "$@3", "cmd_decl_var", "$@4",
  "$@5", "$@6", "$@7", "lista_decl_var", "$@8", "$@9", "inic_decl_var",
  "cmd_attrib", "cmd_io", "cmd_func_call", "cmd_func_call_args",
  "cmd_shift", "shift_op", "cmd_simple_keyword", "cmd_fluxo", "$@10",
  "cmd_fluxo_else", "$@11", "cmd_iter", "$@12", "$@13", "unary_op",
  "low_precedence", "high_precedence", "exp", "exp_high", "exp_unit",
  "exp_value", YY_NULLPTR
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
      42,    63,    35,    47,    37,   124,    94,    60,    62
};
# endif

#define YYPACT_NINF -170

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-170)))

#define YYTABLE_NINF -64

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     366,  -170,  -170,  -170,  -170,  -170,   260,    19,  -170,   366,
     -21,  -170,  -170,   -24,     4,  -170,  -170,    -6,     6,    17,
      93,  -170,    21,    29,   -12,    27,  -170,    36,  -170,  -170,
      37,   374,   218,   260,   388,  -170,  -170,  -170,    90,  -170,
    -170,  -170,    28,    43,  -170,  -170,  -170,  -170,  -170,  -170,
    -170,   171,  -170,    27,  -170,    34,    53,     9,  -170,    44,
    -170,    51,    52,  -170,  -170,  -170,  -170,  -170,  -170,  -170,
    -170,  -170,  -170,  -170,  -170,  -170,  -170,  -170,    23,  -170,
     218,  -170,  -170,  -170,  -170,  -170,  -170,  -170,   346,   194,
      89,  -170,  -170,  -170,   260,  -170,    54,  -170,  -170,   218,
     218,   218,    57,   171,    73,  -170,   171,  -170,  -170,  -170,
      69,   260,  -170,    80,    81,   218,   218,   218,   -11,   218,
    -170,  -170,  -170,  -170,   218,   243,  -170,  -170,  -170,  -170,
    -170,  -170,  -170,  -170,  -170,  -170,  -170,  -170,  -170,   268,
      73,  -170,    73,    98,    16,    92,    -3,   194,  -170,    71,
     -10,  -170,  -170,  -170,   106,   104,  -170,    78,    79,   146,
      89,   148,   108,   218,    89,   218,  -170,  -170,    73,  -170,
     -27,   107,   -19,  -170,   218,  -170,   381,   115,   119,   120,
     395,   -24,   158,  -170,   318,  -170,   293,   156,   162,  -170,
     218,   218,   218,   130,  -170,  -170,  -170,    73,   124,   395,
    -170,   179,   -24,  -170,   218,  -170,    89,  -170,   176,   185,
     194,  -170,  -170,    73,  -170,  -170,  -170,  -170,   186,   117,
      98,  -170,   -24,  -170,   140,  -170,   -24,  -170
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     7,     8,     9,    10,    11,     0,     0,     2,     4,
       0,     5,     6,     0,     0,     1,     3,    22,     0,    21,
       0,    25,    22,     0,     0,     0,    19,     0,    83,    91,
       0,     0,     0,     0,     0,    89,    81,    82,     0,    49,
      37,    51,     0,     0,    43,    42,    44,    45,    46,    47,
      48,    40,    85,     0,    18,     0,     0,     0,    27,    22,
      20,     0,     0,    69,    15,    14,    13,    17,    12,    16,
      70,    71,   132,   133,   134,   135,   137,   136,   129,    93,
       0,    94,    95,    96,    97,    98,    99,   131,     0,    80,
     121,   125,   126,    57,     0,    53,     0,    78,    79,     0,
      75,     0,     0,     0,     0,    36,    39,    41,    29,    23,
       0,     0,    31,     0,     0,     0,     0,     0,     0,     0,
     127,   102,   100,   101,     0,     0,   111,   112,   113,   114,
     115,   107,   103,   104,   105,   106,   108,   109,   110,     0,
       0,    55,     0,     0,     0,     0,    73,    67,    76,     0,
      60,    52,    38,    24,     0,    34,    30,     0,     0,     0,
     116,     0,     0,     0,   117,     0,   122,    58,     0,    54,
       0,     0,     0,    72,    75,    50,     0,     0,    59,    35,
       0,     0,     0,   130,     0,   128,     0,     0,     0,    56,
       0,     0,     0,     0,    74,    65,    66,     0,     0,     0,
      32,    88,     0,   124,     0,   119,   118,   123,     0,     0,
      68,    77,    64,     0,    33,    86,    84,    92,     0,     0,
       0,    62,     0,   120,     0,    87,     0,    90
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -170,  -170,   192,  -170,     0,    26,  -170,    13,  -170,  -170,
    -170,  -170,  -170,   151,  -169,  -159,   -44,  -170,  -170,  -170,
    -170,  -170,  -170,  -170,  -170,  -137,  -170,  -170,  -170,  -141,
    -170,   -16,    42,  -170,    38,  -170,  -170,  -170,  -170,  -170,
    -170,  -170,  -170,  -170,  -170,  -150,   -31,    97,  -131,   139
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     7,     8,     9,    41,    71,    11,    18,    19,    12,
      13,    25,    53,    58,   114,    21,    42,    43,    44,   103,
      45,   104,   142,   168,   140,   151,   198,   177,   178,    46,
      47,    87,   145,    49,   102,    50,    51,    61,   216,   222,
      52,    96,    62,    88,   125,   139,   146,    90,    91,    92
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      10,    89,   171,   167,    48,   169,    14,   107,   166,    10,
     184,   200,     1,     2,     3,     4,     5,    97,    98,    15,
     176,   190,   201,    17,   121,   111,    55,    23,   101,    20,
     214,   189,   121,    93,    95,    48,   192,   -63,    56,   122,
      60,   160,    24,   217,   174,   -26,   123,   122,    22,   118,
     124,   121,    26,   203,   123,   205,   184,   113,   124,   149,
     212,   112,   152,   225,    27,   172,   122,   227,   144,    24,
     147,   117,   -28,   123,   100,    54,   221,   124,    57,   224,
      59,    63,   105,   109,   157,   158,   159,    48,   161,   106,
      48,   110,    24,   162,   141,   148,     1,     2,     3,     4,
       5,    28,   115,   116,    29,   143,    30,    31,    32,    33,
      34,   154,    35,   121,   121,    36,    37,   150,   153,   126,
     127,   128,   129,   130,   155,   175,    97,    98,   122,   122,
     181,   182,   187,   156,   188,   123,   123,    38,    99,   124,
     124,   100,   170,   121,   173,   101,    39,    40,   131,   132,
     179,   180,   133,   134,   135,   136,   137,   138,   122,   208,
     209,   210,   197,   191,   186,   123,   -61,   199,   211,   124,
     202,   213,   192,   218,     1,     2,     3,     4,     5,    28,
     113,   121,    29,   121,    30,    31,    32,    33,    34,   215,
      35,   121,   226,    36,    37,   183,   122,   121,   122,   113,
     185,    16,   196,   123,   108,   123,   122,   124,   206,   124,
     193,   121,   122,   123,   207,    38,   194,   124,     0,   123,
     121,   121,   164,   124,    39,   219,   122,   120,     0,   121,
       0,     0,     0,   123,     0,   122,   122,   124,   223,     0,
       0,   220,   123,   123,   122,     0,   124,   124,     0,     0,
       0,   123,     0,     0,     0,   124,    72,    73,    74,    75,
      76,    77,    78,     1,     2,     3,     4,     5,    79,    80,
       0,     0,     0,     0,     0,    81,    82,    83,    84,    85,
      86,    72,    73,    74,    75,    76,    77,    78,     0,     0,
       0,     0,     0,    79,   163,     0,     0,     0,     0,     0,
      81,    82,    83,    84,    85,    86,    72,    73,    74,    75,
      76,    77,    78,     0,     0,     0,     0,     0,    79,   165,
       0,     0,     0,     0,     0,    81,    82,    83,    84,    85,
      86,    72,    73,    74,    75,    76,    77,    78,     0,     0,
       0,     0,     0,    79,   204,     0,     0,     0,     0,     0,
      81,    82,    83,    84,    85,    86,    72,    73,    74,    75,
      76,    77,    78,     0,     0,     0,     0,     0,    79,     1,
       2,     3,     4,     5,     0,    81,    82,    83,    84,    85,
      86,     0,     0,     6,    72,    73,    74,    75,    76,    77,
      78,     1,     2,     3,     4,     5,     0,   119,     1,     2,
       3,     4,     5,     0,    94,     0,     0,     0,     0,     0,
       0,   111,    64,    65,    66,    67,    68,    69,    70,    64,
      65,    66,    67,    68,    69,   195
};

static const yytype_int16 yycheck[] =
{
       0,    32,   143,   140,    20,   142,     6,    51,   139,     9,
     160,   180,     3,     4,     5,     6,     7,    36,    37,     0,
      30,    48,   181,    44,    35,    16,    38,    14,    55,    53,
     199,   168,    35,    33,    34,    51,    55,    47,    50,    50,
      27,    52,    48,   202,    47,    51,    57,    50,    44,    80,
      61,    35,    46,   184,    57,   186,   206,    57,    61,   103,
     197,    52,   106,   222,    47,    49,    50,   226,    99,    48,
     101,    48,    51,    57,    51,    46,   213,    61,    51,   220,
      44,    44,    54,    49,   115,   116,   117,   103,   119,    46,
     106,    38,    48,   124,    94,    38,     3,     4,     5,     6,
       7,     8,    51,    51,    11,    51,    13,    14,    15,    16,
      17,   111,    19,    35,    35,    22,    23,    44,    49,    30,
      31,    32,    33,    34,    44,    54,    36,    37,    50,    50,
      52,    52,   163,    52,   165,    57,    57,    44,    48,    61,
      61,    51,    44,    35,    52,    55,    53,    54,    59,    60,
      44,    47,    63,    64,    65,    66,    67,    68,    50,   190,
     191,   192,    47,    56,    56,    57,    47,    47,    38,    61,
      12,    47,    55,   204,     3,     4,     5,     6,     7,     8,
     180,    35,    11,    35,    13,    14,    15,    16,    17,    10,
      19,    35,    52,    22,    23,    49,    50,    35,    50,   199,
      52,     9,   176,    57,    53,    57,    50,    61,    52,    61,
     172,    35,    50,    57,    52,    44,   174,    61,    -1,    57,
      35,    35,   125,    61,    53,    49,    50,    88,    -1,    35,
      -1,    -1,    -1,    57,    -1,    50,    50,    61,    52,    -1,
      -1,    56,    57,    57,    50,    -1,    61,    61,    -1,    -1,
      -1,    57,    -1,    -1,    -1,    61,    38,    39,    40,    41,
      42,    43,    44,     3,     4,     5,     6,     7,    50,    51,
      -1,    -1,    -1,    -1,    -1,    57,    58,    59,    60,    61,
      62,    38,    39,    40,    41,    42,    43,    44,    -1,    -1,
      -1,    -1,    -1,    50,    51,    -1,    -1,    -1,    -1,    -1,
      57,    58,    59,    60,    61,    62,    38,    39,    40,    41,
      42,    43,    44,    -1,    -1,    -1,    -1,    -1,    50,    51,
      -1,    -1,    -1,    -1,    -1,    57,    58,    59,    60,    61,
      62,    38,    39,    40,    41,    42,    43,    44,    -1,    -1,
      -1,    -1,    -1,    50,    51,    -1,    -1,    -1,    -1,    -1,
      57,    58,    59,    60,    61,    62,    38,    39,    40,    41,
      42,    43,    44,    -1,    -1,    -1,    -1,    -1,    50,     3,
       4,     5,     6,     7,    -1,    57,    58,    59,    60,    61,
      62,    -1,    -1,    17,    38,    39,    40,    41,    42,    43,
      44,     3,     4,     5,     6,     7,    -1,    51,     3,     4,
       5,     6,     7,    -1,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    16,    38,    39,    40,    41,    42,    43,    44,    38,
      39,    40,    41,    42,    43,    44
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,    17,    70,    71,    72,
      73,    75,    78,    79,    73,     0,    71,    44,    76,    77,
      53,    84,    44,    76,    48,    80,    46,    47,     8,    11,
      13,    14,    15,    16,    17,    19,    22,    23,    44,    53,
      54,    73,    85,    86,    87,    89,    98,    99,   100,   102,
     104,   105,   109,    81,    46,    38,    50,    51,    82,    44,
      76,   106,   111,    44,    38,    39,    40,    41,    42,    43,
      44,    74,    38,    39,    40,    41,    42,    43,    44,    50,
      51,    57,    58,    59,    60,    61,    62,   100,   112,   115,
     116,   117,   118,    73,    16,    73,   110,    36,    37,    48,
      51,    55,   103,    88,    90,    54,    46,    85,    82,    49,
      38,    16,    52,    73,    83,    51,    51,    48,   115,    51,
     118,    35,    50,    57,    61,   113,    30,    31,    32,    33,
      34,    59,    60,    63,    64,    65,    66,    67,    68,   114,
      93,    73,    91,    51,   115,   101,   115,   115,    38,    85,
      44,    94,    85,    49,    73,    44,    52,   115,   115,   115,
      52,   115,   115,    51,   116,    51,   117,    94,    92,    94,
      44,    98,    49,    52,    47,    54,    30,    96,    97,    44,
      47,    52,    52,    49,   114,    52,    56,   115,   115,    94,
      48,    56,    55,   103,   101,    44,    74,    47,    95,    47,
      83,    84,    12,   117,    51,   117,    52,    52,   115,   115,
     115,    38,    94,    47,    83,    10,   107,    84,   115,    49,
      56,    94,   108,    52,    98,    84,    52,    84
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    69,    70,    71,    71,    72,    72,    73,    73,    73,
      73,    73,    74,    74,    74,    74,    74,    74,    75,    75,
      76,    76,    77,    77,    77,    78,    80,    79,    81,    79,
      82,    82,    83,    83,    83,    83,    84,    84,    85,    85,
      85,    85,    86,    86,    86,    86,    86,    86,    86,    88,
      87,    90,    89,    91,    89,    92,    89,    93,    89,    94,
      94,    95,    94,    96,    94,    97,    97,    98,    98,    99,
      99,    99,   100,   101,   101,   101,   102,   102,   103,   103,
     104,   104,   104,   106,   105,   105,   108,   107,   107,   110,
     109,   111,   109,   112,   112,   112,   112,   112,   112,   112,
     113,   113,   113,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   115,   115,   115,   115,
     115,   115,   116,   116,   116,   116,   117,   117,   117,   118,
     118,   118,   118,   118,   118,   118,   118,   118
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     3,
       3,     1,     1,     4,     5,     2,     0,     4,     0,     5,
       3,     2,     4,     5,     2,     3,     3,     2,     3,     2,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     0,
       4,     0,     3,     0,     4,     0,     5,     0,     4,     2,
       1,     0,     5,     0,     4,     2,     2,     3,     6,     2,
       2,     2,     4,     1,     3,     0,     3,     6,     1,     1,
       2,     1,     1,     0,     7,     1,     0,     3,     0,     0,
      10,     0,     7,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     5,     5,
       7,     1,     3,     5,     5,     1,     1,     2,     4,     1,
       4,     1,     1,     1,     1,     1,     1,     1
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

/* User initialization code.  */
#line 29 "parser.y" /* yacc.c:1429  */
{
	hash_stack = create_stack();
    iloc_code = create_code();
    return_label = NULL;
    has_main_function = 0;
}

#line 1323 "parser.tab.c" /* yacc.c:1429  */
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
#line 99 "parser.y" /* yacc.c:1646  */
    { arvore = (yyvsp[0].no); pop_stack(hash_stack); 
        ILOC_add_rbss_offset(iloc_code);
        print_iloc(iloc_code); 
        print_iloc_to_file(iloc_code); 
        free_iloc(iloc_code); 
        if(has_main_function == 0){
            printf("ERROR: Could not find main function. \n");
            return 100;
        }
    }
#line 1514 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 111 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = join_nodes((yyvsp[-1].no), (yyvsp[0].no)); }
#line 1520 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 112 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = NULL; }
#line 1526 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 115 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = NULL; }
#line 1532 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 116 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = (yyvsp[0].no); }
#line 1538 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 120 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = cria_nodo("0", NULL); /* enum C_INT has value 0 */}
#line 1544 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 121 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = cria_nodo("1", NULL); /* C_FLOAT has value 1 */}
#line 1550 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 122 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = cria_nodo("2", NULL); }
#line 1556 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 123 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = cria_nodo("3", NULL); }
#line 1562 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 124 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = cria_nodo("4", NULL); }
#line 1568 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 127 "parser.y" /* yacc.c:1646  */
    { char str[16]; sprintf(str,"%c",(yyvsp[0].valor_lexico)->valor.c); (yyval.no) = cria_nodo(str,(yyvsp[0].valor_lexico)); (yyval.no)->tipo = N_CHAR; }
#line 1574 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 128 "parser.y" /* yacc.c:1646  */
    { char str[16]; sprintf(str,"false"); (yyval.no) = cria_nodo(str,(yyvsp[0].valor_lexico)); (yyval.no)->tipo = N_BOOLEAN; }
#line 1580 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 129 "parser.y" /* yacc.c:1646  */
    { char str[16]; sprintf(str,"%f",(yyvsp[0].valor_lexico)->valor.f); (yyval.no) = cria_nodo(str,(yyvsp[0].valor_lexico)); (yyval.no)->tipo = N_FLOAT;  }
#line 1586 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 130 "parser.y" /* yacc.c:1646  */
    { char str[16]; sprintf(str,"%d",(yyvsp[0].valor_lexico)->valor.i); (yyval.no) = ILOC_cria_nodo(str, (yyvsp[0].valor_lexico), "lit", hash_stack); (yyval.no)->tipo = N_INT;  }
#line 1592 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 131 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = cria_nodo((yyvsp[0].valor_lexico)->valor.s,(yyvsp[0].valor_lexico)); (yyval.no)->tipo = N_STRING; }
#line 1598 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 132 "parser.y" /* yacc.c:1646  */
    { char str[16]; sprintf(str,"true"); (yyval.no) = cria_nodo(str,(yyvsp[0].valor_lexico)); (yyval.no)->tipo = N_BOOLEAN;  }
#line 1604 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 136 "parser.y" /* yacc.c:1646  */
    { int r = ILOC_add_global_var(hash_stack, "global_static", (yyvsp[-2].no), (yyvsp[-1].no)); if(r != 0) return r;}
#line 1610 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 137 "parser.y" /* yacc.c:1646  */
    { int r = ILOC_add_global_var(hash_stack, "global_non_static", (yyvsp[-2].no), (yyvsp[-1].no));  if(r != 0) return r;  }
#line 1616 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 140 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = join_nodes((yyvsp[-2].no), (yyvsp[0].no)); }
#line 1622 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 141 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = (yyvsp[0].no); }
#line 1628 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 144 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = cria_nodo((yyvsp[0].valor_lexico)->valor.s,(yyvsp[0].valor_lexico)); (yyval.no)->tam = -1; }
#line 1634 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 145 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = cria_nodo((yyvsp[-3].valor_lexico)->valor.s,(yyvsp[-3].valor_lexico)); (yyval.no)->tam = (yyvsp[-1].valor_lexico)->valor.i; free_token((yyvsp[-1].valor_lexico)); }
#line 1640 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 146 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = cria_nodo((yyvsp[-4].valor_lexico)->valor.s,(yyvsp[-4].valor_lexico)); (yyval.no)->tam = (yyvsp[-1].valor_lexico)->valor.i; free_token((yyvsp[-1].valor_lexico)); }
#line 1646 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 150 "parser.y" /* yacc.c:1646  */
    { 
        add_child((yyvsp[-1].no), (yyvsp[0].no)); 
        (yyval.no) = (yyvsp[-1].no); 
        iloc_code = ILOC_add_func_code((yyvsp[-1].no),(yyvsp[0].no), iloc_code, hash_stack, return_label);
        if(strcmp((yyvsp[-1].no)->label, "main") == 0) has_main_function = 1;
        free(return_label);
        return_label = NULL;
        }
#line 1659 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 160 "parser.y" /* yacc.c:1646  */
    {  hash_stack = ILOC_put_stack(hash_stack, "function");  }
#line 1665 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 161 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.no) = cria_nodo((yyvsp[-2].valor_lexico)->valor.s, (yyvsp[-2].valor_lexico));
        f_type = atoi((yyvsp[-3].no)->label);
        int r = ILOC_add_function(hash_stack, (yyvsp[-2].valor_lexico), (yyvsp[-3].no), 0, (yyvsp[0].no), (yyval.no)); if(r!=0) return r;
        return_label = create_label();
         
      }
#line 1677 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 168 "parser.y" /* yacc.c:1646  */
    {  hash_stack = put_stack(hash_stack); }
#line 1683 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 169 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.no) = cria_nodo((yyvsp[-2].valor_lexico)->valor.s, (yyvsp[-2].valor_lexico));
        f_type = atoi((yyvsp[-3].no)->label);
        int r = ILOC_add_function(hash_stack, (yyvsp[-2].valor_lexico), (yyvsp[-3].no), 1, (yyvsp[0].no), (yyval.no)); if(r!=0) return r;
        return_label = create_label();
        
     }
#line 1695 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 179 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = (yyvsp[-1].no); }
#line 1701 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 180 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = NULL; }
#line 1707 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 184 "parser.y" /* yacc.c:1646  */
    { 
        node_t* aux_node = cria_nodo((yyvsp[-2].valor_lexico)->valor.s, (yyvsp[-2].valor_lexico));
        int r = ILOC_add_func_arg(hash_stack, (yyvsp[-2].valor_lexico), (yyvsp[-3].no), 0); if(r!=0) return r;
        (yyval.no) = join_nodes(aux_node, (yyvsp[0].no)); 
     }
#line 1717 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 189 "parser.y" /* yacc.c:1646  */
    { 
        node_t* aux_node = cria_nodo((yyvsp[-2].valor_lexico)->valor.s, (yyvsp[-2].valor_lexico));
        int r = ILOC_add_func_arg(hash_stack, (yyvsp[-2].valor_lexico), (yyvsp[-3].no), 1); if(r!=0) return r;
        (yyval.no) = join_nodes(aux_node, (yyvsp[0].no));
     }
#line 1727 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 194 "parser.y" /* yacc.c:1646  */
    { 
        int r = ILOC_add_func_arg(hash_stack, (yyvsp[0].valor_lexico), (yyvsp[-1].no), 0); if(r!=0) return r;
        (yyval.no) = cria_nodo((yyvsp[0].valor_lexico)->valor.s, (yyvsp[0].valor_lexico));
       
     }
#line 1737 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 199 "parser.y" /* yacc.c:1646  */
    { 
        int r = ILOC_add_func_arg(hash_stack, (yyvsp[0].valor_lexico), (yyvsp[-1].no), 1); if(r!=0) return r;
        (yyval.no) = cria_nodo((yyvsp[0].valor_lexico)->valor.s, (yyvsp[0].valor_lexico));
     }
#line 1746 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 206 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = (yyvsp[-1].no);   hash_stack = pop_stack(hash_stack); }
#line 1752 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 207 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = NULL;  hash_stack = pop_stack(hash_stack); }
#line 1758 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 211 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = join_nodes((yyvsp[-2].no), (yyvsp[0].no)); (yyval.no)->code = concat_iloc_code((yyvsp[-2].no)->code,(yyvsp[0].no)->code); }
#line 1764 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 212 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = (yyvsp[-1].no); }
#line 1770 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 213 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = (yyvsp[0].no); }
#line 1776 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 214 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = join_nodes((yyvsp[-1].no), (yyvsp[0].no)); (yyval.no)->code = concat_iloc_code((yyvsp[-1].no)->code,(yyvsp[0].no)->code);}
#line 1782 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 218 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = (yyvsp[0].no);  }
#line 1788 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 219 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = (yyvsp[0].no); }
#line 1794 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 220 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = (yyvsp[0].no); }
#line 1800 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 221 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = (yyvsp[0].no); }
#line 1806 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 222 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = (yyvsp[0].no); }
#line 1812 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 223 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = (yyvsp[0].no); }
#line 1818 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 224 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = (yyvsp[0].no); }
#line 1824 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 228 "parser.y" /* yacc.c:1646  */
    {  hash_stack = put_stack(hash_stack); }
#line 1830 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 228 "parser.y" /* yacc.c:1646  */
    {  (yyval.no) = (yyvsp[-1].no); hash_stack = pop_stack(hash_stack); }
#line 1836 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 232 "parser.y" /* yacc.c:1646  */
    {v_type = atoi((yyvsp[0].no)->label);}
#line 1842 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 232 "parser.y" /* yacc.c:1646  */
    { 
       libera_nodo((yyvsp[-2].no));
        (yyval.no) = (yyvsp[0].no); 
    }
#line 1851 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 236 "parser.y" /* yacc.c:1646  */
    { v_type = atoi((yyvsp[0].no)->label);}
#line 1857 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 236 "parser.y" /* yacc.c:1646  */
    { 
        v_static = 1;
        libera_nodo((yyvsp[-2].no));
        (yyval.no) = (yyvsp[0].no); 
    }
#line 1867 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 241 "parser.y" /* yacc.c:1646  */
    { v_type = atoi((yyvsp[0].no)->label); }
#line 1873 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 241 "parser.y" /* yacc.c:1646  */
    { 
        v_static = 1;
        v_const = 1;
        libera_nodo((yyvsp[-2].no));
        (yyval.no) = (yyvsp[0].no); 
    }
#line 1884 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 247 "parser.y" /* yacc.c:1646  */
    {v_type = atoi((yyvsp[0].no)->label);}
#line 1890 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 247 "parser.y" /* yacc.c:1646  */
    { 
        v_const = 1;
        libera_nodo((yyvsp[-2].no));
        (yyval.no) = (yyvsp[0].no); 
    }
#line 1900 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 255 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.no) = cria_nodo("<=",NULL); 
        node_t* aux = cria_nodo((yyvsp[-1].valor_lexico)->valor.s, NULL);
        add_child((yyval.no), aux); 
        add_child((yyval.no), (yyvsp[0].no));  
        int r = ILOC_verify_var_declaration(hash_stack, (yyvsp[-1].valor_lexico), v_type, (yyvsp[0].no), v_static, v_const); if( r != 0 ) { return r; }
        ILOC_add_local_var((yyval.no), aux, (yyvsp[0].no), "initialized", hash_stack);
    }
#line 1913 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 263 "parser.y" /* yacc.c:1646  */
    { 
        int r = ILOC_verify_var_declaration(hash_stack, (yyvsp[0].valor_lexico), v_type, NULL, v_static, v_const);
        if( r != 0 ) {
            return r;
        }
        (yyval.no) = cria_nodo("decl", NULL);
        node_t* aux = cria_nodo((yyvsp[0].valor_lexico)->valor.s, NULL);
        add_child((yyval.no), aux);

        ILOC_add_local_var((yyval.no), aux, NULL, "not_initialized", hash_stack);
    }
#line 1929 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 274 "parser.y" /* yacc.c:1646  */
    { 

        node_t* aux = cria_nodo((yyvsp[-1].valor_lexico)->valor.s, NULL);
        int r = ILOC_verify_var_declaration(hash_stack, (yyvsp[-1].valor_lexico), v_type, (yyvsp[0].no), v_static, v_const); if(r != 0) return r;
        free(aux->label);
        free(aux);

         }
#line 1942 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 281 "parser.y" /* yacc.c:1646  */
    { 

        (yyval.no) = cria_nodo("<=",NULL); 
        node_t* aux = cria_nodo((yyvsp[-4].valor_lexico)->valor.s, NULL);
        add_child((yyval.no), aux);
        add_child((yyval.no), (yyvsp[-3].no));
        
        (yyval.no) = join_nodes((yyval.no), (yyvsp[0].no));
        ILOC_add_local_var((yyval.no), (yyval.no)->children[0], (yyval.no)->children[1], "initialized", hash_stack);
        (yyval.no)->code = concat_iloc_code((yyval.no)->code, (yyvsp[0].no)->code);

        }
#line 1959 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 293 "parser.y" /* yacc.c:1646  */
    { 

        int r = ILOC_verify_var_declaration(hash_stack, (yyvsp[0].valor_lexico), v_type, NULL, v_static, v_const); if(r != 0) return r;

        }
#line 1969 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 297 "parser.y" /* yacc.c:1646  */
    { 

        (yyval.no) = cria_nodo("decl", NULL);
        node_t* aux = cria_nodo((yyvsp[-3].valor_lexico)->valor.s, NULL);
        add_child((yyval.no), aux);
        (yyval.no) = join_nodes((yyval.no), (yyvsp[0].no));

        ILOC_add_local_var((yyval.no), aux, NULL, "not_initialized", hash_stack);
        (yyval.no)->code = concat_iloc_code((yyval.no)->code, (yyvsp[0].no)->code);
    }
#line 1984 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 309 "parser.y" /* yacc.c:1646  */
    {    
        (yyval.no) = ILOC_cria_nodo((yyvsp[0].valor_lexico)->valor.s,(yyvsp[0].valor_lexico), "ident", hash_stack);
    }
#line 1992 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 312 "parser.y" /* yacc.c:1646  */
    {
        (yyval.no) = (yyvsp[0].no); 
    }
#line 2000 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 317 "parser.y" /* yacc.c:1646  */
    { 
        
        (yyval.no) = cria_nodo("=", NULL); 
        node_t* aux = cria_nodo((yyvsp[-2].valor_lexico)->valor.s,(yyvsp[-2].valor_lexico)); 
        add_child((yyval.no), aux); 
        add_child((yyval.no), (yyvsp[0].no));
        
        int r = cmd_attrib(hash_stack, (yyvsp[-2].valor_lexico), (yyvsp[0].no), 0);
       
        if( r != 0) {
            return r;
        }
        (yyval.no)->code = ILOC_cmd_attrib((yyvsp[-2].valor_lexico)->valor.s, hash_stack, (yyvsp[0].no)); 
        }
#line 2019 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 331 "parser.y" /* yacc.c:1646  */
    { 
        char str[16]; 
        sprintf(str,"%s",(yyvsp[-5].valor_lexico)->valor.s); 
        node_t* aux = cria_nodo(str,(yyvsp[-5].valor_lexico)); 
        node_t* aux2 = cria_nodo("[]",NULL); 
        add_child(aux2, aux); 
        add_child(aux2,(yyvsp[-3].no)); 
        (yyval.no) = cria_nodo("=", NULL);
        add_child((yyval.no), aux2); 
        add_child((yyval.no), (yyvsp[0].no));
        int r = cmd_attrib(hash_stack, (yyvsp[-5].valor_lexico), (yyvsp[0].no), 1);
        if( r != 0) {
            return r;
        } 
        }
#line 2039 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 349 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.no) = cria_nodo("input", NULL); 
        char str2[16]; sprintf(str2,"%s",(yyvsp[0].valor_lexico)->valor.s); node_t* aux = cria_nodo(str2,(yyvsp[0].valor_lexico));
        add_child((yyval.no),aux); 
        int r = verify_type_io(hash_stack, (yyvsp[0].valor_lexico), "input", 0);
        if (r != 0) {
            return r;
        }
    }
#line 2053 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 358 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.no) = cria_nodo("output", NULL); 
        char str2[16]; sprintf(str2,"%s",(yyvsp[0].valor_lexico)->valor.s); node_t* aux = cria_nodo(str2,(yyvsp[0].valor_lexico));
        add_child((yyval.no),aux);
        int r = verify_type_io(hash_stack, (yyvsp[0].valor_lexico), "output", 0);
        if (r != 0) {
            return r;
        } 
    }
#line 2067 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 367 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.no) = cria_nodo("output", NULL); 
        add_child((yyval.no),(yyvsp[0].no));
        int r = verify_type_io(hash_stack, (yyvsp[0].no)->value, "output", 1);
        if (r != 0) {
            return r;
        } 
    }
#line 2080 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 378 "parser.y" /* yacc.c:1646  */
    {
        (yyval.no) = cria_nodo((yyvsp[-3].valor_lexico)->valor.s,(yyvsp[-3].valor_lexico)); 
        add_child((yyval.no),(yyvsp[-1].no)); 
        int r = verify_exp_ident(hash_stack,"function", (yyval.no)); if(r != 0) return r;
        r = ILOC_function_call(hash_stack, (yyval.no), (yyvsp[-1].no)); if (r != 0) return r;
    }
#line 2091 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 387 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = (yyvsp[0].no); }
#line 2097 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 388 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = join_nodes((yyvsp[-2].no),(yyvsp[0].no)); }
#line 2103 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 389 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = NULL; }
#line 2109 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 393 "parser.y" /* yacc.c:1646  */
    { char str[16]; sprintf(str,"%s",(yyvsp[-2].valor_lexico)->valor.s); node_t* aux = cria_nodo(str,(yyvsp[-2].valor_lexico)); 
       char str2[16]; sprintf(str2,"%d",(yyvsp[0].valor_lexico)->valor.i); node_t* aux2 = cria_nodo(str2,(yyvsp[0].valor_lexico)); 
       add_child((yyvsp[-1].no), aux); add_child((yyvsp[-1].no), aux2); (yyval.no) = (yyvsp[-1].no); 
       int r = verify_shift_size((yyvsp[0].valor_lexico)); if(r !=0) return r;}
#line 2118 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 397 "parser.y" /* yacc.c:1646  */
    { char str[16]; sprintf(str,"%s",(yyvsp[-5].valor_lexico)->valor.s); node_t* aux = cria_nodo(str,(yyvsp[-5].valor_lexico)); 
        node_t* aux2 = cria_nodo("[]",NULL); 
        add_child(aux2, aux); add_child(aux2,(yyvsp[-3].no)); 
        char str3[16]; sprintf(str3,"%d",(yyvsp[0].valor_lexico)->valor.i); node_t* aux3 = cria_nodo(str3,(yyvsp[0].valor_lexico));
        add_child((yyvsp[-1].no), aux2); add_child((yyvsp[-1].no), aux3); (yyval.no) = (yyvsp[-1].no);
        int r = verify_shift_size((yyvsp[0].valor_lexico)); if(r !=0) return r;
        }
#line 2130 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 406 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = cria_nodo("<<",NULL); }
#line 2136 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 407 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = cria_nodo(">>", NULL); }
#line 2142 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 410 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = cria_nodo("return", NULL); add_child((yyval.no),(yyvsp[0].no)); 
    int r = ILOC_function_return(hash_stack, (yyvsp[0].no), f_type, return_label, (yyval.no)); if (r != 0) { return r; } 
    }
#line 2150 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 413 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = cria_nodo("break", NULL);  }
#line 2156 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 414 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = cria_nodo("continue", NULL);  }
#line 2162 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 418 "parser.y" /* yacc.c:1646  */
    { hash_stack = put_stack(hash_stack); }
#line 2168 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 418 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.no) = cria_nodo("if", NULL);
        add_child((yyval.no), (yyvsp[-3].no));
        add_child((yyval.no), (yyvsp[-1].no));
        add_child((yyval.no), (yyvsp[0].no));
        (yyval.no)->code = ILOC_cmd_if(hash_stack, (yyvsp[-3].no), (yyvsp[-1].no), (yyvsp[0].no));
    }
#line 2180 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 425 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = (yyvsp[0].no); }
#line 2186 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 429 "parser.y" /* yacc.c:1646  */
    { hash_stack = put_stack(hash_stack); }
#line 2192 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 429 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = (yyvsp[0].no);}
#line 2198 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 430 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = NULL; }
#line 2204 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 434 "parser.y" /* yacc.c:1646  */
    { hash_stack = put_stack(hash_stack); }
#line 2210 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 434 "parser.y" /* yacc.c:1646  */
    {
        (yyval.no) = cria_nodo("for", NULL);
        add_child((yyval.no), (yyvsp[-6].no));
        add_child((yyval.no), (yyvsp[-4].no));
        add_child((yyval.no), (yyvsp[-2].no));
        add_child((yyval.no), (yyvsp[0].no));

        (yyval.no)->code = ILOC_cmd_for(hash_stack, (yyvsp[-6].no), (yyvsp[-4].no), (yyvsp[-2].no), (yyvsp[0].no));
	
    }
#line 2225 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 444 "parser.y" /* yacc.c:1646  */
    { hash_stack = put_stack(hash_stack); }
#line 2231 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 444 "parser.y" /* yacc.c:1646  */
    {
        (yyval.no) = cria_nodo("while", NULL);
        add_child((yyval.no), (yyvsp[-3].no));
        add_child((yyval.no), (yyvsp[0].no));
        (yyval.no)->code = ILOC_cmd_while(hash_stack, (yyvsp[-3].no), (yyvsp[0].no));
    }
#line 2242 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 452 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = cria_nodo("+", add_token(yylineno, CHAR_ESP, "+", OC_ID_SC)); }
#line 2248 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 453 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = cria_nodo("-", add_token(yylineno, CHAR_ESP, "-", OC_ID_SC)); }
#line 2254 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 454 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = cria_nodo("!", add_token(yylineno, CHAR_ESP, "|", OC_ID_SC)); }
#line 2260 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 455 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = cria_nodo("&", add_token(yylineno, CHAR_ESP, "&", OC_ID_SC)); }
#line 2266 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 456 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = cria_nodo("*", add_token(yylineno, CHAR_ESP, "*", OC_ID_SC)); }
#line 2272 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 457 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = cria_nodo("?", add_token(yylineno, CHAR_ESP, "?", OC_ID_SC)); }
#line 2278 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 458 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = cria_nodo("#", add_token(yylineno, CHAR_ESP, "#", OC_ID_SC)); }
#line 2284 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 462 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = cria_nodo("+", add_token(yylineno, CHAR_ESP, "+", OC_ID_SC)); }
#line 2290 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 463 "parser.y" /* yacc.c:1646  */
    {  (yyval.no) = cria_nodo("-", add_token(yylineno, CHAR_ESP, "-", OC_ID_SC)); }
#line 2296 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 464 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = cria_nodo("||",add_token(yylineno, CHAR_ESP, "||", OC_ID_SC)); }
#line 2302 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 467 "parser.y" /* yacc.c:1646  */
    {  (yyval.no) = cria_nodo("*", add_token(yylineno, CHAR_ESP, "*", OC_ID_SC)); }
#line 2308 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 468 "parser.y" /* yacc.c:1646  */
    {  (yyval.no) = cria_nodo("/", add_token(yylineno, CHAR_ESP, "/", OC_ID_SC)); }
#line 2314 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 469 "parser.y" /* yacc.c:1646  */
    {  (yyval.no) = cria_nodo("%", add_token(yylineno, CHAR_ESP, "%", OC_ID_SC)); }
#line 2320 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 470 "parser.y" /* yacc.c:1646  */
    {  (yyval.no) = cria_nodo("|", add_token(yylineno, CHAR_ESP, "|", OC_ID_SC)); }
#line 2326 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 471 "parser.y" /* yacc.c:1646  */
    {  (yyval.no) = cria_nodo("&", add_token(yylineno, CHAR_ESP, "&", OC_ID_SC)); }
#line 2332 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 472 "parser.y" /* yacc.c:1646  */
    {  (yyval.no) = cria_nodo("^", add_token(yylineno, CHAR_ESP, "^", OC_ID_SC)); }
#line 2338 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 473 "parser.y" /* yacc.c:1646  */
    {  (yyval.no) = cria_nodo("<", add_token(yylineno, CHAR_ESP, "<", OC_ID_SC)); }
#line 2344 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 474 "parser.y" /* yacc.c:1646  */
    {  (yyval.no) = cria_nodo(">", add_token(yylineno, CHAR_ESP, ">", OC_ID_SC)); }
#line 2350 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 475 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = cria_nodo("<=",add_token(yylineno, CHAR_ESP, "<=", OC_ID_SC)); }
#line 2356 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 476 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = cria_nodo(">=",add_token(yylineno, CHAR_ESP, ">=", OC_ID_SC)); }
#line 2362 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 477 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = cria_nodo("==",add_token(yylineno, CHAR_ESP, "==", OC_ID_SC)); }
#line 2368 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 478 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = cria_nodo("!=",add_token(yylineno, CHAR_ESP, "!=", OC_ID_SC)); }
#line 2374 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 479 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = cria_nodo("&&",add_token(yylineno, CHAR_ESP, "&&", OC_ID_SC)); }
#line 2380 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 483 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = (yyvsp[-1].no); }
#line 2386 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 484 "parser.y" /* yacc.c:1646  */
    { add_child((yyvsp[-1].no),(yyvsp[-2].no)); add_child((yyvsp[-1].no),(yyvsp[0].no)); (yyval.no) = (yyvsp[-1].no); int r = ILOC_binary_exp((yyval.no), (yyvsp[-2].no), (yyvsp[0].no)); if(r != 0) return r;  }
#line 2392 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 485 "parser.y" /* yacc.c:1646  */
    { add_child((yyvsp[-3].no),(yyvsp[-4].no)); add_child((yyvsp[-3].no),(yyvsp[-1].no)); (yyval.no) = (yyvsp[-3].no); int r = ILOC_binary_exp((yyval.no), (yyvsp[-4].no), (yyvsp[-1].no)); if(r != 0) return r;  }
#line 2398 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 486 "parser.y" /* yacc.c:1646  */
    {  
       
        (yyval.no) = cria_nodo("?:", add_token(yylineno, CHAR_ESP, "?:", OC_ID_SC));
        add_child((yyval.no),(yyvsp[-4].no));
        add_child((yyval.no),(yyvsp[-2].no));
        add_child((yyval.no),(yyvsp[0].no));
        
        int r = binary_type_inference((yyval.no), (yyvsp[-2].no), (yyvsp[0].no));
        if(r != 0) return r;
        (yyval.no)->code = ILOC_cmd_ternary_op(hash_stack, (yyvsp[-4].no), (yyvsp[-2].no), (yyvsp[0].no));
        
    }
#line 2415 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 498 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.no) = cria_nodo("?:", add_token(yylineno, CHAR_ESP, "?:", OC_ID_SC));
        add_child((yyval.no),(yyvsp[-6].no));
        add_child((yyval.no),(yyvsp[-4].no));
        add_child((yyval.no),(yyvsp[-1].no));
        int r = binary_type_inference((yyval.no), (yyvsp[-4].no), (yyvsp[-1].no));
        if(r != 0) return r;
        (yyval.no)->code = ILOC_cmd_ternary_op(hash_stack, (yyvsp[-6].no), (yyvsp[-4].no), (yyvsp[-1].no));
    }
#line 2429 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 507 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = (yyvsp[0].no); }
#line 2435 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 510 "parser.y" /* yacc.c:1646  */
    { add_child((yyvsp[-1].no),(yyvsp[-2].no)); add_child((yyvsp[-1].no),(yyvsp[0].no)); (yyval.no) = (yyvsp[-1].no); int r = ILOC_binary_exp((yyval.no), (yyvsp[-2].no), (yyvsp[0].no)); if(r != 0) return r;  }
#line 2441 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 511 "parser.y" /* yacc.c:1646  */
    { add_child((yyvsp[-3].no),(yyvsp[-4].no)); add_child((yyvsp[-3].no),(yyvsp[-1].no)); (yyval.no) = (yyvsp[-3].no); int r = ILOC_binary_exp((yyval.no), (yyvsp[-4].no), (yyvsp[-1].no)); if(r != 0) return r;  }
#line 2447 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 512 "parser.y" /* yacc.c:1646  */
    { add_child((yyvsp[-1].no),(yyvsp[-3].no)); add_child((yyvsp[-1].no),(yyvsp[0].no)); (yyval.no) = (yyvsp[-1].no); int r = ILOC_binary_exp((yyval.no), (yyvsp[-3].no), (yyvsp[0].no)); if(r != 0) return r;  }
#line 2453 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 513 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = (yyvsp[0].no); }
#line 2459 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 516 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = (yyvsp[0].no); }
#line 2465 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 517 "parser.y" /* yacc.c:1646  */
    { add_child((yyvsp[-1].no),(yyvsp[0].no)); (yyval.no) = (yyvsp[-1].no); int r = ILOC_unary_exp((yyval.no), (yyvsp[0].no)); if(r != 0) return r; }
#line 2471 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 518 "parser.y" /* yacc.c:1646  */
    { add_child((yyvsp[-3].no),(yyvsp[-1].no)); (yyval.no) = (yyvsp[-3].no); int r = ILOC_unary_exp((yyval.no), (yyvsp[-1].no)); if(r != 0) return r; }
#line 2477 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 521 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = ILOC_cria_nodo((yyvsp[0].valor_lexico)->valor.s,(yyvsp[0].valor_lexico), "ident", hash_stack); int r = verify_exp_ident(hash_stack,"var", (yyval.no)); if(r != 0) return r; }
#line 2483 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 522 "parser.y" /* yacc.c:1646  */
    { node_t* aux = cria_nodo((yyvsp[-3].valor_lexico)->valor.s,(yyvsp[-3].valor_lexico)); int r = verify_exp_ident(hash_stack,"vector", aux); if(r != 0) return r;
    	(yyval.no) = cria_nodo("[]",NULL); add_child((yyval.no),aux); add_child((yyval.no),(yyvsp[-1].no)); (yyval.no)->tipo = aux->tipo; }
#line 2490 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 524 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = (yyvsp[0].no); /*TODO*/ }
#line 2496 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 525 "parser.y" /* yacc.c:1646  */
    { char str[16]; sprintf(str,"%d",(yyvsp[0].valor_lexico)->valor.i); (yyval.no) = ILOC_cria_nodo(str, (yyvsp[0].valor_lexico), "lit", hash_stack); (yyval.no)->tipo = N_INT; }
#line 2502 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 526 "parser.y" /* yacc.c:1646  */
    { char str[16]; sprintf(str,"%f",(yyvsp[0].valor_lexico)->valor.f); (yyval.no) = cria_nodo(str,(yyvsp[0].valor_lexico)); (yyval.no)->tipo = N_FLOAT; }
#line 2508 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 527 "parser.y" /* yacc.c:1646  */
    { char str[16]; (yyval.no) = cria_nodo("false",(yyvsp[0].valor_lexico)); sprintf(str,"%d",0); (yyval.no) = ILOC_cria_nodo(str, (yyvsp[0].valor_lexico), "lit", hash_stack); (yyval.no)->tipo = N_BOOLEAN; }
#line 2514 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 528 "parser.y" /* yacc.c:1646  */
    { char str[16]; (yyval.no) = cria_nodo("true",(yyvsp[0].valor_lexico)); sprintf(str,"%d",1); (yyval.no) = ILOC_cria_nodo(str, (yyvsp[0].valor_lexico), "lit", hash_stack); (yyval.no)->tipo = N_BOOLEAN; }
#line 2520 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 529 "parser.y" /* yacc.c:1646  */
    { (yyval.no) = cria_nodo((yyvsp[0].valor_lexico)->valor.s,(yyvsp[0].valor_lexico)); (yyval.no)->tipo = N_STRING;  }
#line 2526 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 530 "parser.y" /* yacc.c:1646  */
    { char str[16]; sprintf(str,"%c",(yyvsp[0].valor_lexico)->valor.c); (yyval.no) = cria_nodo(str,(yyvsp[0].valor_lexico)); (yyval.no)->tipo = N_CHAR; }
#line 2532 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 2536 "parser.tab.c" /* yacc.c:1646  */
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
#line 533 "parser.y" /* yacc.c:1906  */

int yyerror(const char *str)
{
    printf("error: %s in line %d\n", str, yylineno);
    return 1;
}


