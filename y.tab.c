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
     IDENT = 258,
     LITERAL = 259,
     COMMA = 260,
     SEMICOLON = 261,
     LBRACE = 262,
     RBRACE = 263,
     LPAR = 264,
     RPAR = 265,
     LBRACK = 266,
     RBRACK = 267,
     TYPENAME = 268,
     BREAK = 269,
     ELSE = 270,
     IF = 271,
     RETURN = 272,
     WHILE = 273,
     EQUAL = 274,
     OROR = 275,
     ANDAND = 276,
     OR = 277,
     UPARROW = 278,
     AND = 279,
     NOTEQ = 280,
     EQEQ = 281,
     GT = 282,
     GE = 283,
     LT = 284,
     LE = 285,
     RSHIFT = 286,
     LSHIFT = 287,
     MINUS = 288,
     PLUS = 289,
     PERCENT = 290,
     SLASH = 291,
     STAR = 292,
     TILDE = 293,
     EXCLAM = 294,
     MINUSMINUS = 295,
     PLUSPLUS = 296
   };
#endif
/* Tokens.  */
#define IDENT 258
#define LITERAL 259
#define COMMA 260
#define SEMICOLON 261
#define LBRACE 262
#define RBRACE 263
#define LPAR 264
#define RPAR 265
#define LBRACK 266
#define RBRACK 267
#define TYPENAME 268
#define BREAK 269
#define ELSE 270
#define IF 271
#define RETURN 272
#define WHILE 273
#define EQUAL 274
#define OROR 275
#define ANDAND 276
#define OR 277
#define UPARROW 278
#define AND 279
#define NOTEQ 280
#define EQEQ 281
#define GT 282
#define GE 283
#define LT 284
#define LE 285
#define RSHIFT 286
#define LSHIFT 287
#define MINUS 288
#define PLUS 289
#define PERCENT 290
#define SLASH 291
#define STAR 292
#define TILDE 293
#define EXCLAM 294
#define MINUSMINUS 295
#define PLUSPLUS 296




/* Copy the first part of user declarations.  */
#line 4 "parse1.y"

#include <stdio.h>
#include <stdlib.h>
#include "common.h"

#define NRES    27
#define IDSIZE  8
#define STRSIZE 2000
#define NEGL    -1

extern FILE *source;

static int c = ' ';
static int line = 1;
static int tokenline;
static char id[IDSIZE+1],declid[IDSIZE+1];
static char string[STRSIZE];
static int strtop = 0;
static int value;

static TYPE *ctype,*basetype;
extern TYPE inttype,chartype;
extern int currfunc;
extern int errcnt;

extern TYPE *newtype(),*reverse();
extern TREE *maketree();
extern IDPROP *lookup();

typedef TREE *T;


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
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
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 220 "y.tab.c"

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
# if YYENABLE_NLS
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
#define YYLAST   417

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  88
/* YYNRULES -- Number of states.  */
#define YYNSTATES  150

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,    10,    11,    13,    15,    18,
      19,    20,    31,    34,    35,    39,    43,    45,    46,    49,
      51,    55,    58,    63,    65,    66,    70,    72,    74,    77,
      78,    80,    81,    85,    89,    90,    91,    92,   102,   103,
     104,   112,   115,   119,   122,   125,   126,   128,   130,   132,
     134,   135,   137,   139,   143,   148,   153,   155,   157,   158,
     162,   164,   167,   170,   173,   176,   179,   182,   185,   188,
     191,   195,   199,   203,   207,   211,   215,   219,   223,   227,
     231,   235,   239,   243,   247,   251,   255,   259,   263
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      43,     0,    -1,    -1,    44,    45,    -1,    45,    46,    -1,
      -1,    51,    -1,    47,    -1,     1,     6,    -1,    -1,    -1,
       3,    48,     9,    56,    10,    49,     7,    50,    59,     8,
      -1,    50,    51,    -1,    -1,    13,    52,     6,    -1,    52,
       5,    53,    -1,    53,    -1,    -1,    54,    55,    -1,     3,
      -1,     9,    55,    10,    -1,    37,    55,    -1,    55,    11,
      69,    12,    -1,    57,    -1,    -1,    57,     5,    58,    -1,
      58,    -1,     3,    -1,    59,    60,    -1,    -1,     6,    -1,
      -1,    61,    68,     6,    -1,     7,    59,     8,    -1,    -1,
      -1,    -1,    16,    62,     9,    68,    10,    63,    60,    64,
      67,    -1,    -1,    -1,    18,    65,     9,    68,    10,    66,
      60,    -1,    14,     6,    -1,    17,    69,     6,    -1,     1,
       6,    -1,    15,    60,    -1,    -1,    70,    -1,    74,    -1,
      75,    -1,    68,    -1,    -1,     3,    -1,     4,    -1,     9,
      68,    10,    -1,    71,     9,    72,    10,    -1,    70,    11,
      68,    12,    -1,     3,    -1,    73,    -1,    -1,    73,     5,
      68,    -1,    68,    -1,    37,    68,    -1,    24,    70,    -1,
      33,    68,    -1,    39,    68,    -1,    38,    68,    -1,    41,
      70,    -1,    40,    70,    -1,    70,    41,    -1,    70,    40,
      -1,    68,    37,    68,    -1,    68,    36,    68,    -1,    68,
      35,    68,    -1,    68,    34,    68,    -1,    68,    33,    68,
      -1,    68,    32,    68,    -1,    68,    31,    68,    -1,    68,
      29,    68,    -1,    68,    27,    68,    -1,    68,    30,    68,
      -1,    68,    28,    68,    -1,    68,    26,    68,    -1,    68,
      25,    68,    -1,    68,    24,    68,    -1,    68,    23,    68,
      -1,    68,    22,    68,    -1,    68,    21,    68,    -1,    68,
      20,    68,    -1,    68,    19,    68,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    72,    72,    72,    78,    79,    83,    84,    85,    90,
      92,    89,    98,    99,   103,   107,   108,   112,   112,   118,
     120,   121,   123,   128,   129,   133,   134,   138,   145,   146,
     150,   151,   151,   154,   156,   158,   160,   155,   164,   166,
     163,   169,   171,   173,   177,   178,   184,   185,   186,   190,
     192,   196,   198,   200,   202,   204,   211,   216,   218,   222,
     224,   230,   232,   234,   236,   238,   240,   242,   244,   246,
     252,   254,   256,   258,   260,   262,   264,   266,   268,   270,
     272,   274,   276,   278,   280,   282,   284,   286,   288
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENT", "LITERAL", "COMMA", "SEMICOLON",
  "LBRACE", "RBRACE", "LPAR", "RPAR", "LBRACK", "RBRACK", "TYPENAME",
  "BREAK", "ELSE", "IF", "RETURN", "WHILE", "EQUAL", "OROR", "ANDAND",
  "OR", "UPARROW", "AND", "NOTEQ", "EQEQ", "GT", "GE", "LT", "LE",
  "RSHIFT", "LSHIFT", "MINUS", "PLUS", "PERCENT", "SLASH", "STAR", "TILDE",
  "EXCLAM", "MINUSMINUS", "PLUSPLUS", "$accept", "program", "@1",
  "ext_def_list", "external_def", "function", "@2", "@3",
  "local_decl_list", "var_decl", "declarator_list", "declaration", "@4",
  "declarator", "formal_params", "formal_list", "formal", "statement_list",
  "statement", "@5", "@6", "@7", "@8", "@9", "@10", "if_tail",
  "expression", "opt_expression", "primary", "func_name", "actual_params",
  "expr_list", "unary_expr", "binary_expr", 0
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
     295,   296
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    44,    43,    45,    45,    46,    46,    46,    48,
      49,    47,    50,    50,    51,    52,    52,    54,    53,    55,
      55,    55,    55,    56,    56,    57,    57,    58,    59,    59,
      60,    61,    60,    60,    62,    63,    64,    60,    65,    66,
      60,    60,    60,    60,    67,    67,    68,    68,    68,    69,
      69,    70,    70,    70,    70,    70,    71,    72,    72,    73,
      73,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     0,     1,     1,     2,     0,
       0,    10,     2,     0,     3,     3,     1,     0,     2,     1,
       3,     2,     4,     1,     0,     3,     1,     1,     2,     0,
       1,     0,     3,     3,     0,     0,     0,     9,     0,     0,
       7,     2,     3,     2,     2,     0,     1,     1,     1,     1,
       0,     1,     1,     3,     4,     4,     1,     1,     0,     3,
       1,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     5,     1,     0,     0,     9,    17,     4,     7,
       6,     8,     0,     0,    16,     0,    24,    17,    14,    19,
       0,     0,    18,    27,     0,    23,    26,    15,     0,    21,
      50,    10,     0,    20,    51,    52,     0,     0,     0,     0,
       0,     0,     0,     0,    49,     0,    46,     0,    47,    48,
       0,    25,     0,    62,    63,    61,    65,    64,    67,    66,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    22,
       0,    69,    68,    58,    13,    53,    88,    87,    86,    85,
      84,    83,    82,    81,    78,    80,    77,    79,    76,    75,
      74,    73,    72,    71,    70,     0,    60,     0,    57,    29,
      55,    54,     0,    12,     0,    59,     0,    30,    29,    11,
       0,    34,    50,    38,    28,     0,    43,     0,    41,     0,
       0,     0,     0,    33,     0,    42,     0,    32,     0,     0,
      35,    39,     0,     0,    36,    40,    45,     0,    37,    44
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     4,     8,     9,    12,    50,   109,    10,
      13,    14,    15,    22,    24,    25,    26,   114,   124,   125,
     129,   142,   146,   131,   143,   148,    44,    45,    46,    47,
     107,   108,    48,    49
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -37
static const yytype_int16 yypact[] =
{
     -37,     1,   -37,   -37,    54,    81,   -37,   -37,   -37,   -37,
     -37,   -37,    83,    56,   -37,    60,    96,   -37,   -37,   -37,
      60,    60,    91,   -37,    99,   101,   -37,   -37,    67,    91,
     146,   -37,    96,   -37,   109,   -37,   146,    61,   146,   146,
     146,   146,    61,    61,   298,    98,    12,   110,   -37,   -37,
     114,   -37,   197,   111,    49,   -37,   -37,   -37,   111,   111,
     146,   146,   146,   146,   146,   146,   146,   146,   146,   146,
     146,   146,   146,   146,   146,   146,   146,   146,   146,   -37,
     146,   -37,   -37,   146,   -37,   -37,   298,   -15,   314,   329,
     343,   356,   369,   369,   380,   380,   380,   380,    80,    80,
      49,    49,   -37,   -37,   -37,   279,   298,   113,   125,   120,
     -37,   -37,   146,   -37,    42,   298,   130,   -37,   -37,   -37,
     132,   -37,   146,   -37,   -37,   146,   -37,    87,   -37,   131,
     133,   134,   169,   -37,   146,   -37,   146,   -37,   225,   253,
     -37,   -37,   128,   128,   -37,   -37,   126,   128,   -37,   -37
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -37,   -37,   -37,   -37,   -37,   -37,   -37,   -37,   -37,    38,
     -37,   136,   -37,    51,   -37,   -37,   116,    33,   -35,   -37,
     -37,   -37,   -37,   -37,   -37,   -37,   -36,    32,    31,   -37,
     -37,   -37,   -37,   -37
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -57
static const yytype_int16 yytable[] =
{
      52,     3,    54,    55,    56,    57,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    80,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   116,   105,   -31,   -31,   106,   117,   118,
     119,   -31,    81,    82,    -3,     5,   120,     6,   121,   122,
     123,    17,    18,    19,    34,    35,   -31,     7,    53,    20,
      36,    28,    29,    58,    59,   -31,   115,    33,    30,   -31,
     -31,   -31,   -31,   -31,    76,    77,    78,    11,   116,   132,
     -31,   -31,    16,   117,   118,   133,   -31,    21,   138,    23,
     139,   120,    30,   121,   122,   123,    32,   144,   145,    31,
      79,   -31,   149,    74,    75,    76,    77,    78,   -56,    83,
     -31,    84,    80,   111,   -31,   -31,   -31,   -31,   -31,   116,
     112,   -31,   -31,     7,   117,   118,   126,   -31,   128,   135,
     134,   147,   120,   136,   121,   122,   123,   113,    51,    34,
      35,   127,   -31,    27,   130,    36,     0,     0,     0,     0,
       0,   -31,     0,     0,     0,   -31,   -31,   -31,   -31,   -31,
      37,     0,     0,     0,     0,   137,     0,     0,     0,    38,
       0,     0,     0,    39,    40,    41,    42,    43,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    85,     0,     0,
       0,     0,     0,     0,     0,     0,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,   140,     0,     0,     0,     0,
       0,     0,     0,     0,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,   141,     0,     0,     0,     0,     0,     0,
       0,     0,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,   110,     0,     0,     0,     0,     0,     0,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,   -57,   -57,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,   -57,   -57,   -57,
     -57,    72,    73,    74,    75,    76,    77,    78
};

static const yytype_int16 yycheck[] =
{
      36,     0,    38,    39,    40,    41,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    11,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,     1,    80,     3,     4,    83,     6,     7,
       8,     9,    40,    41,     0,     1,    14,     3,    16,    17,
      18,     5,     6,     3,     3,     4,    24,    13,    37,     9,
       9,    20,    21,    42,    43,    33,   112,    10,    11,    37,
      38,    39,    40,    41,    35,    36,    37,     6,     1,   125,
       3,     4,     9,     6,     7,     8,     9,    37,   134,     3,
     136,    14,    11,    16,    17,    18,     5,   142,   143,    10,
      12,    24,   147,    33,    34,    35,    36,    37,     9,     9,
      33,     7,    11,    10,    37,    38,    39,    40,    41,     1,
       5,     3,     4,    13,     6,     7,     6,     9,     6,     6,
       9,    15,    14,     9,    16,    17,    18,   109,    32,     3,
       4,   118,    24,    17,   122,     9,    -1,    -1,    -1,    -1,
      -1,    33,    -1,    -1,    -1,    37,    38,    39,    40,    41,
      24,    -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,    33,
      -1,    -1,    -1,    37,    38,    39,    40,    41,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    12,    -1,    -1,    -1,    -1,    -1,    -1,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    43,    44,     0,    45,     1,     3,    13,    46,    47,
      51,     6,    48,    52,    53,    54,     9,     5,     6,     3,
       9,    37,    55,     3,    56,    57,    58,    53,    55,    55,
      11,    10,     5,    10,     3,     4,     9,    24,    33,    37,
      38,    39,    40,    41,    68,    69,    70,    71,    74,    75,
      49,    58,    68,    70,    68,    68,    68,    68,    70,    70,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    12,
      11,    40,    41,     9,     7,    10,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    72,    73,    50,
      12,    10,     5,    51,    59,    68,     1,     6,     7,     8,
      14,    16,    17,    18,    60,    61,     6,    59,     6,    62,
      69,    65,    68,     8,     9,     6,     9,     6,    68,    68,
      10,    10,    63,    66,    60,    60,    64,    15,    67,    60
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
# if YYLTYPE_IS_TRIVIAL
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
        case 2:
#line 72 "parse1.y"
    { initcode(); }
    break;

  case 3:
#line 74 "parse1.y"
    { checkfunc(); }
    break;

  case 9:
#line 90 "parse1.y"
    { enterfunc(id); }
    break;

  case 10:
#line 92 "parse1.y"
    { endparam(); }
    break;

  case 11:
#line 94 "parse1.y"
    { endfunc(); }
    break;

  case 17:
#line 112 "parse1.y"
    { ctype=NIL; cleartree(); }
    break;

  case 18:
#line 114 "parse1.y"
    { enter(declid,reverse(ctype,basetype)); }
    break;

  case 19:
#line 119 "parse1.y"
    { copystr(declid,id); }
    break;

  case 21:
#line 122 "parse1.y"
    { ctype=newtype('*',0,ctype); }
    break;

  case 22:
#line 124 "parse1.y"
    { ctype=newtype('[',eval((T)(yyvsp[(3) - (4)])),ctype); }
    break;

  case 27:
#line 139 "parse1.y"
    { enter(id,&inttype); }
    break;

  case 31:
#line 151 "parse1.y"
    { cleartree(); }
    break;

  case 32:
#line 153 "parse1.y"
    { compile((T)(yyvsp[(2) - (3)]),POPUP); }
    break;

  case 34:
#line 156 "parse1.y"
    { cleartree(); }
    break;

  case 35:
#line 158 "parse1.y"
    { if1(compile((T)(yyvsp[(4) - (5)]),FJUMP));}
    break;

  case 36:
#line 160 "parse1.y"
    { if2(); }
    break;

  case 37:
#line 162 "parse1.y"
    { if3(); }
    break;

  case 38:
#line 164 "parse1.y"
    { while1(); cleartree(); }
    break;

  case 39:
#line 166 "parse1.y"
    { while2(compile((T)(yyvsp[(4) - (5)]),FJUMP)); }
    break;

  case 40:
#line 168 "parse1.y"
    { while3(); }
    break;

  case 41:
#line 170 "parse1.y"
    { break1(); }
    break;

  case 42:
#line 172 "parse1.y"
    { compile((T)(yyvsp[(2) - (3)]),LOAD); emit(FUNCRET,currfunc,0); }
    break;

  case 50:
#line 192 "parse1.y"
    { (yyval)=(int)maketree(T_LIT,0,NIL); }
    break;

  case 51:
#line 197 "parse1.y"
    { (yyval)=(int)maketree(T_ID,(T)lookup(id),NIL); }
    break;

  case 52:
#line 199 "parse1.y"
    { (yyval)=(int)maketree(T_LIT,value,NIL); }
    break;

  case 53:
#line 201 "parse1.y"
    { (yyval)=(yyvsp[(2) - (3)]); }
    break;

  case 54:
#line 203 "parse1.y"
    { (yyval)=(int)maketree(CALL,(T)(yyvsp[(1) - (4)]),(T)(yyvsp[(3) - (4)])); }
    break;

  case 55:
#line 205 "parse1.y"
    { (yyval)=(int)maketree(DEREF,
			                   maketree(ADD,(T)(yyvsp[(1) - (4)]),(T)(yyvsp[(3) - (4)])),
			                   NIL); }
    break;

  case 56:
#line 212 "parse1.y"
    { (yyval)=reffunc(id); }
    break;

  case 58:
#line 218 "parse1.y"
    { (yyval)=NIL; }
    break;

  case 59:
#line 223 "parse1.y"
    { (yyval)=(int)maketree(ARGLINK,(T)(yyvsp[(3) - (3)]),(T)(yyvsp[(1) - (3)])); }
    break;

  case 60:
#line 225 "parse1.y"
    { (yyval)=(int)maketree(ARGLINK,(T)(yyvsp[(1) - (1)]),NIL); }
    break;

  case 61:
#line 231 "parse1.y"
    { (yyval)=(int)maketree(DEREF,(T)(yyvsp[(2) - (2)]),NIL); }
    break;

  case 62:
#line 233 "parse1.y"
    { (yyval)=(int)maketree(ADRS,(T)(yyvsp[(2) - (2)]),NIL); }
    break;

  case 63:
#line 235 "parse1.y"
    { (yyval)=(int)maketree(INVSIGN,(T)(yyvsp[(2) - (2)]),NIL); }
    break;

  case 64:
#line 237 "parse1.y"
    { (yyval)=(int)maketree(NOT,(T)(yyvsp[(2) - (2)]),NIL); }
    break;

  case 65:
#line 239 "parse1.y"
    { (yyval)=(int)maketree(ONECMPL,(T)(yyvsp[(2) - (2)]),NIL); }
    break;

  case 66:
#line 241 "parse1.y"
    { (yyval)=(int)maketree(PREINCR,(T)(yyvsp[(2) - (2)]),NIL); }
    break;

  case 67:
#line 243 "parse1.y"
    { (yyval)=(int)maketree(PREDECR,(T)(yyvsp[(2) - (2)]),NIL); }
    break;

  case 68:
#line 245 "parse1.y"
    { (yyval)=(int)maketree(PSTINCR,(T)(yyvsp[(1) - (2)]),NIL); }
    break;

  case 69:
#line 247 "parse1.y"
    { (yyval)=(int)maketree(PSTDECR,(T)(yyvsp[(1) - (2)]),NIL); }
    break;

  case 70:
#line 253 "parse1.y"
    { (yyval)=(int)maketree(MULT,(T)(yyvsp[(1) - (3)]),(T)(yyvsp[(3) - (3)])); }
    break;

  case 71:
#line 255 "parse1.y"
    { (yyval)=(int)maketree(DIV,(T)(yyvsp[(1) - (3)]),(T)(yyvsp[(3) - (3)])); }
    break;

  case 72:
#line 257 "parse1.y"
    { (yyval)=(int)maketree(MOD,(T)(yyvsp[(1) - (3)]),(T)(yyvsp[(3) - (3)])); }
    break;

  case 73:
#line 259 "parse1.y"
    { (yyval)=(int)maketree(ADD,(T)(yyvsp[(1) - (3)]),(T)(yyvsp[(3) - (3)])); }
    break;

  case 74:
#line 261 "parse1.y"
    { (yyval)=(int)maketree(SUB,(T)(yyvsp[(1) - (3)]),(T)(yyvsp[(3) - (3)])); }
    break;

  case 75:
#line 263 "parse1.y"
    { (yyval)=(int)maketree(LSFTOP,(T)(yyvsp[(1) - (3)]),(T)(yyvsp[(3) - (3)])); }
    break;

  case 76:
#line 265 "parse1.y"
    { (yyval)=(int)maketree(RSFTOP,(T)(yyvsp[(1) - (3)]),(T)(yyvsp[(3) - (3)])); }
    break;

  case 77:
#line 267 "parse1.y"
    { (yyval)=(int)maketree(LTOP,(T)(yyvsp[(1) - (3)]),(T)(yyvsp[(3) - (3)])); }
    break;

  case 78:
#line 269 "parse1.y"
    { (yyval)=(int)maketree(LTOP,(T)(yyvsp[(3) - (3)]),(T)(yyvsp[(1) - (3)])); }
    break;

  case 79:
#line 271 "parse1.y"
    { (yyval)=(int)maketree(LEOP,(T)(yyvsp[(1) - (3)]),(T)(yyvsp[(3) - (3)])); }
    break;

  case 80:
#line 273 "parse1.y"
    { (yyval)=(int)maketree(LEOP,(T)(yyvsp[(3) - (3)]),(T)(yyvsp[(1) - (3)])); }
    break;

  case 81:
#line 275 "parse1.y"
    { (yyval)=(int)maketree(EQOP,(T)(yyvsp[(1) - (3)]),(T)(yyvsp[(3) - (3)])); }
    break;

  case 82:
#line 277 "parse1.y"
    { (yyval)=(int)maketree(NEOP,(T)(yyvsp[(1) - (3)]),(T)(yyvsp[(3) - (3)])); }
    break;

  case 83:
#line 279 "parse1.y"
    { (yyval)=(int)maketree(ANDOP,(T)(yyvsp[(1) - (3)]),(T)(yyvsp[(3) - (3)])); }
    break;

  case 84:
#line 281 "parse1.y"
    { (yyval)=(int)maketree(XOROP,(T)(yyvsp[(1) - (3)]),(T)(yyvsp[(3) - (3)])); }
    break;

  case 85:
#line 283 "parse1.y"
    { (yyval)=(int)maketree(OROP,(T)(yyvsp[(1) - (3)]),(T)(yyvsp[(3) - (3)])); }
    break;

  case 86:
#line 285 "parse1.y"
    { (yyval)=(int)maketree(LANDOP,(T)(yyvsp[(1) - (3)]),(T)(yyvsp[(3) - (3)])); }
    break;

  case 87:
#line 287 "parse1.y"
    { (yyval)=(int)maketree(LOROP,(T)(yyvsp[(1) - (3)]),(T)(yyvsp[(3) - (3)])); }
    break;

  case 88:
#line 289 "parse1.y"
    { (yyval)=(int)maketree(ASSIGN,(T)(yyvsp[(1) - (3)]),(T)(yyvsp[(3) - (3)])); }
    break;


/* Line 1267 of yacc.c.  */
#line 1907 "y.tab.c"
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


#line 298 "parse1.y"

 
static struct { char *s; int v; }
	keywords[NRES] =  { "auto",     NEGL,
	                    "break",    BREAK,
	                    "case",     NEGL,
	                    "char",     TYPENAME,
	                    "continue", NEGL,
	                    "default",  NEGL,
	                    "do",       NEGL,
	                    "double",   NEGL,
	                    "else",     ELSE,
	                    "extern",   NEGL,
	                    "float",    NEGL,
	                    "for",      NEGL,
	                    "goto",     NEGL,
	                    "if",       IF,
	                    "int",      TYPENAME,
	                    "long",     TYPENAME,
	                    "register", NEGL,
	                    "return",   RETURN,
	                    "short",    TYPENAME,
	                    "sizeof",   NEGL,
	                    "static",   NEGL,
	                    "struct",   NEGL,
	                    "switch",   NEGL,
	                    "typedef",  NEGL,
	                    "union",    NEGL,
	                    "unsigned", NEGL,
	                    "while",    WHILE };

//static int yylex()
int yylex()
{	int l,h,p,x,base;
 
    rescan:
	while (c==' ' || c=='\t' || c=='\n')
		cget();
	tokenline=line;         /* accurately refer to error position */
	if (c==EOF)
		return(EOF);
	if (c>='a' && c<='z' || c>='A' && c<='Z' || c=='_') {
		l=0;
		while (c>='a' && c<='z' || c>='A' && c<='Z' ||
		       c=='_' || c>='0' && c<='9') {
			if (l<IDSIZE)
				id[l++]=c;
			cget();
		}
		id[l]=0;
		l=0;
		h=NRES-1;
		while (l<=h) {
			p=(l+h)/2;
			x=strcompare(id,keywords[p].s);
			if (x==0) {
				if (keywords[p].v==NEGL) {
					yyerror("unsupported keyword");
					goto rescan;
				}
				if (keywords[p].v==TYPENAME) {
					if (strcompare(id,"char")==0)
						basetype=(&chartype);
					else
						basetype=(&inttype);
				}
				return(keywords[p].v);
			}
			if (x<0)
				h=p-1;
			else
				l=p+1;
		}
		return(IDENT);
	}
	else if (c>='0' && c<='9') {
		if (c=='0')
			base=8;
		else
			base=10;
		value=0;
		while (c>='0' && c<='9') {
			if (base==8 && (c=='8' || c=='9'))
				yyerror("8 or 9 in octal number");
			value=value*base+(c-'0');
			cget();
		}
		return(LITERAL);
	}
	else if (c=='\'') {
		cget();
		if (c=='\'') 
			yyerror("null character literal");
		else
			value=charval();
		if (c=='\'')
			cget();
		else
			yyerror("character literal invalid format");
		return(LITERAL);
	}
	else if (c=='\"') {
		value=(int)(&string[strtop]);
		cget();
		while (c!='\"' && c!='\n') 
			enterstr(charval());
		if (c=='\"')
			cget();
		else
			yyerror("string literal invalid format");
		enterstr(0);
		return(LITERAL);
	}
	switch (c) {
	case ',':
		cget();
		return(COMMA);
	case ';':
		cget();
		return(SEMICOLON);
	case '{':
		cget();
		return(LBRACE);
	case '}':
		cget();
		return(RBRACE);
	case '(':
		cget();
		return(LPAR);
	case ')':
		cget();
		return(RPAR);
	case '[':
		cget();
		return(LBRACK);
	case ']':
		cget();
		return(RBRACK);
	case '*':
		cget();
		return(STAR);
	case '&':
		cget();
		if (c=='&') {
			cget();
			return(ANDAND);
		}
		return(AND);
	case '|':
		cget();
		if (c=='|') {
			cget();
			return(OROR);
		}
		return(OR);
	case '+':
		cget();
		if (c=='+') {
			cget();
			return(PLUSPLUS);
		}
		return(PLUS);
	case '-':
		cget();
		if (c=='-') {
			cget();
			return(MINUSMINUS);
		}
		return(MINUS);
	case '/':
		cget();
		if (c=='*') {
			cget();
			do {
				while (c!='*' && c!=EOF)
					cget();
				cget();
			} while (c!='/' && c!=EOF);
			if (c==EOF) {
				yyerror("comment not terminated");
				return(EOF);
			}
			cget();
			goto rescan;
		}
		return(SLASH);
	case '!':
		cget();
		if (c=='=') {
			cget();
			return(NOTEQ);
		}
		return(EXCLAM);
	case '~':
		cget();
		return(TILDE);
	case '%':
		cget();
		return(PERCENT);
	case '<':
		cget();
		if (c=='<') {
			cget();
			return(LSHIFT);
		}
		else if (c=='=') {
			cget();
			return(LE);
		}
		return(LT);
	case '>':
		cget();
		if (c=='>') {
			cget();
			return(RSHIFT);
		}
		else if (c=='=') {
			cget();
			return(GE);
		}
		return(GT);
	case '=':
		cget();
		if (c=='=') {
			cget();
			return(EQEQ);
		}
		return(EQUAL);
	case '^':
		cget();
		return(UPARROW);
	default:
		yyerror("invalid character");
		cget();
		goto rescan;
	}
}

enterstr(v)
int v;
{
	if (strtop>=STRSIZE)
		fatal("string table overflow");
	string[strtop++]=v;
}

int charval()
{	int v,l;

	if (c<040 || c>=0177) {
		yyerror("control character in string");
		cget();
		return(0);
	}
	if (c!='\\') {
		v=c;
		cget();
		return(v);
	}
	cget();
	if (c>='0' && c<='7') {
		v=0;
		l=0;
		while (l<3 && c>='0' && c<='7') {
			v=(v<<3)+(c-'0');
			l++;
			cget();
		}
		return(v);
	}
	switch (c) {
	case 'n':
		v='\n';
		break;
	case 't':
		v='\t';
		break;
	case 'b':
		v='\b';
		break;
	case 'r':
		v='\r';
		break;
	case 'f':
		v='\f';
		break;
	default:
		v=c;
	}
	cget();
	return(v);
}

int cget()
{
	c=getc(source);
	if (c=='\n')
		line++;
}

int copystr(a,b)
char *a,*b;
{
	while (*a++=(*b++))
		;
}

yyerror(s)
char *s;
{
	printf("%4d: %s\n",tokenline,s);
	errcnt++;
}

fatal(s)
char *s;
{
	yyerror(s);
	exit(1);
}

