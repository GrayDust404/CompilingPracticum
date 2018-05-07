/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 2 "parser.y"


#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<fstream>
#include<string>
#include"parser.h"
#include"transform.h"
#include"parser.tab.h"

extern int yylex();
extern int yyparse();
extern FILE* yyin;
extern int yylineno;
extern int lexerror;

void yyerror(const char* s);
std::vector<ParseTreeNode> parseTree;
void ParseError(std::string msg,int line);
void lParseError(std::string msg, YYLTYPE t);
int parseTreeRoot;
int parseNum = 0;

/* Line 371 of yacc.c  */
#line 93 "parser.tab.cpp"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
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
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     id = 258,
     semicolon = 259,
     comma = 260,
     _const = 261,
     _var = 262,
     colon = 263,
     simple_type = 264,
     assignop = 265,
     digits = 266,
     assign = 267,
     relop = 268,
     plus = 269,
     minus = 270,
     letter = 271,
     procedure = 272,
     function = 273,
     num = 274,
     _array = 275,
     multiply = 276,
     divide = 277,
     _div = 278,
     _mod = 279,
     _and = 280,
     _not = 281,
     _if = 282,
     _then = 283,
     _for = 284,
     _else = 285,
     _to = 286,
     _do = 287,
     _or = 288,
     _of = 289,
     _range = 290,
     _while = 291,
     noequal = 292,
     GE = 293,
     GT = 294,
     LE = 295,
     LT = 296,
     leftB = 297,
     rightB = 298,
     leftSB = 299,
     rightSB = 300,
     program = 301,
     BEGINTOK = 302,
     ENDTOK = 303,
     fullstop = 304
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 28 "parser.y"

	int ival;


/* Line 387 of yacc.c  */
#line 190 "parser.tab.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;
extern YYLTYPE yylloc;
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

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 231 "parser.tab.cpp"

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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

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
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   371

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  127
/* YYNRULES -- Number of states.  */
#define YYNSTATES  274

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   304

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
      45,    46,    47,    48,    49
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     8,    14,    19,    24,    29,    35,    41,
      47,    53,    57,    59,    63,    68,    69,    73,    77,    82,
      88,    94,    98,   101,   104,   106,   109,   112,   114,   117,
     120,   122,   124,   125,   129,   133,   138,   142,   148,   154,
     155,   159,   163,   167,   171,   175,   181,   182,   186,   190,
     195,   199,   201,   205,   207,   209,   212,   216,   220,   224,
     228,   233,   237,   239,   243,   248,   249,   253,   255,   257,
     263,   269,   278,   285,   294,   303,   308,   313,   314,   317,
     319,   324,   329,   332,   333,   337,   341,   346,   350,   354,
     358,   360,   362,   366,   370,   374,   378,   382,   386,   390,
     394,   398,   400,   404,   408,   412,   416,   420,   422,   424,
     426,   428,   433,   437,   443,   448,   454,   459,   463,   467,
     472,   475,   478,   480,   487,   494,   500,   506
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      51,     0,    -1,    52,     4,    54,    49,    -1,    52,     1,
       4,    54,    49,    -1,     1,     4,    54,    49,    -1,    52,
       4,     1,    49,    -1,    52,     4,    54,     1,    -1,    46,
       3,    42,    53,    43,    -1,    46,     1,    42,    53,    43,
      -1,    46,     3,    42,     1,    43,    -1,    46,     3,    42,
      53,     1,    -1,    53,     5,     3,    -1,     3,    -1,    53,
       5,     1,    -1,    55,    58,    60,    69,    -1,    -1,     6,
      56,     4,    -1,     6,     1,     4,    -1,     6,    56,     1,
       4,    -1,    56,     4,     3,    12,    57,    -1,     1,     4,
       3,    12,    57,    -1,     3,    12,    57,    -1,    14,     3,
      -1,    15,     3,    -1,     3,    -1,    14,    11,    -1,    15,
      11,    -1,    11,    -1,    14,    19,    -1,    15,    19,    -1,
      19,    -1,    16,    -1,    -1,     7,    59,     4,    -1,     7,
       1,     4,    -1,     7,    59,     1,     4,    -1,    53,     8,
      81,    -1,    59,     4,    53,     8,    81,    -1,     1,     4,
      53,     8,    81,    -1,    -1,    60,    61,     4,    -1,    60,
       1,     4,    -1,    62,     4,    68,    -1,     1,     4,    68,
      -1,    17,     3,    63,    -1,    18,     3,    63,     8,     9,
      -1,    -1,    42,    64,    43,    -1,    42,     1,    43,    -1,
      42,    64,     1,    43,    -1,    64,     4,    65,    -1,    65,
      -1,     1,     4,    65,    -1,    66,    -1,    67,    -1,     7,
      67,    -1,    53,     8,     9,    -1,    55,    58,    69,    -1,
      47,    70,    48,    -1,    47,     1,    48,    -1,    47,    70,
       1,    48,    -1,    70,     4,    71,    -1,    71,    -1,     1,
       4,    71,    -1,    70,     1,     4,    71,    -1,    -1,    74,
      10,    77,    -1,    73,    -1,    69,    -1,    27,    77,    28,
      71,    72,    -1,    27,     1,    28,    71,    72,    -1,    29,
       3,    10,    77,    31,    77,    32,    71,    -1,    29,     1,
      31,    77,    32,    71,    -1,    29,     3,    10,    77,    31,
       1,    32,    71,    -1,    29,     3,    10,    77,    31,    77,
      32,     1,    -1,    36,    77,    32,    71,    -1,    36,     1,
      32,    71,    -1,    -1,    30,    71,    -1,     3,    -1,     3,
      42,    76,    43,    -1,     3,    42,     1,    43,    -1,     3,
      75,    -1,    -1,    44,    76,    45,    -1,    44,     1,    45,
      -1,    44,    76,     1,    45,    -1,    44,    76,     1,    -1,
      76,     5,    77,    -1,     1,     5,    77,    -1,    77,    -1,
      78,    -1,    78,    12,    78,    -1,    78,    37,    78,    -1,
      78,    38,    78,    -1,    78,    39,    78,    -1,    78,    40,
      78,    -1,    78,    41,    78,    -1,    78,    14,    79,    -1,
      78,    15,    79,    -1,    78,    33,    79,    -1,    79,    -1,
      79,    21,    80,    -1,    79,    22,    80,    -1,    79,    23,
      80,    -1,    79,    24,    80,    -1,    79,    25,    80,    -1,
      80,    -1,    19,    -1,    11,    -1,    74,    -1,     3,    42,
      76,    43,    -1,     3,    42,    43,    -1,     3,     1,    42,
      76,    43,    -1,     3,    42,     1,    43,    -1,     3,    42,
      76,     1,    43,    -1,     3,    42,    76,     1,    -1,    42,
      77,    43,    -1,    42,     1,    43,    -1,    42,    77,     1,
      43,    -1,    26,    80,    -1,    15,    80,    -1,     9,    -1,
      20,    44,    82,    45,    34,     9,    -1,    20,    44,     1,
      45,    34,     9,    -1,    82,     5,    11,    35,    11,    -1,
       1,     5,    11,    35,    11,    -1,    11,    35,    11,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    47,    47,    58,    61,    64,    67,    73,    86,    89,
      92,    96,   107,   116,   120,   132,   140,   150,   153,   157,
     170,   173,   186,   197,   208,   217,   227,   237,   246,   255,
     264,   273,   283,   291,   302,   305,   309,   320,   334,   339,
     347,   358,   362,   373,   377,   387,   399,   407,   418,   421,
     425,   436,   445,   455,   464,   473,   484,   496,   508,   517,
     520,   524,   535,   544,   547,   551,   559,   570,   579,   588,
     601,   604,   620,   623,   626,   629,   639,   643,   651,   661,
     670,   682,   687,   698,   704,   714,   717,   720,   724,   735,
     738,   747,   756,   767,   778,   789,   800,   811,   823,   834,
     845,   856,   867,   878,   889,   900,   911,   922,   931,   940,
     949,   958,   970,   973,   976,   979,   982,   985,   996,   999,
    1002,  1012,  1022,  1031,  1044,  1049,  1060,  1064
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "id", "semicolon", "comma", "_const",
  "_var", "colon", "simple_type", "assignop", "digits", "assign", "relop",
  "plus", "minus", "letter", "procedure", "function", "num", "_array",
  "multiply", "divide", "_div", "_mod", "_and", "_not", "_if", "_then",
  "_for", "_else", "_to", "_do", "_or", "_of", "_range", "_while",
  "noequal", "GE", "GT", "LE", "LT", "leftB", "rightB", "leftSB",
  "rightSB", "program", "BEGINTOK", "ENDTOK", "fullstop", "$accept",
  "programstruct", "program_head", "idlist", "program_body",
  "const_declarations", "const_declaration", "const_value",
  "var_declarations", "var_declaration", "subprogram_declarations",
  "subprogram", "subprogram_head", "formal_parameter", "parameter_list",
  "parameter", "var_parameter", "value_parameter", "subprogram_body",
  "compound_statement", "statement_list", "statement", "else_part",
  "procedure_call", "variable", "id_varpart", "expression_list",
  "expression", "simple_expression", "term", "factor", "type", "period", YY_NULL
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    50,    51,    51,    51,    51,    51,    52,    52,    52,
      52,    53,    53,    53,    54,    55,    55,    55,    55,    56,
      56,    56,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    58,    58,    58,    58,    59,    59,    59,    60,
      60,    60,    61,    61,    62,    62,    63,    63,    63,    63,
      64,    64,    64,    65,    65,    66,    67,    68,    69,    69,
      69,    70,    70,    70,    70,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    72,    72,    73,
      73,    73,    74,    75,    75,    75,    75,    75,    76,    76,
      76,    77,    77,    77,    77,    77,    77,    77,    78,    78,
      78,    78,    79,    79,    79,    79,    79,    79,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    81,    81,    81,    82,    82,    82
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     5,     4,     4,     4,     5,     5,     5,
       5,     3,     1,     3,     4,     0,     3,     3,     4,     5,
       5,     3,     2,     2,     1,     2,     2,     1,     2,     2,
       1,     1,     0,     3,     3,     4,     3,     5,     5,     0,
       3,     3,     3,     3,     3,     5,     0,     3,     3,     4,
       3,     1,     3,     1,     1,     2,     3,     3,     3,     3,
       4,     3,     1,     3,     4,     0,     3,     1,     1,     5,
       5,     8,     6,     8,     8,     4,     4,     0,     2,     1,
       4,     4,     2,     0,     3,     3,     4,     3,     3,     3,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     3,     3,     3,     3,     3,     1,     1,     1,
       1,     4,     3,     5,     4,     5,     4,     3,     3,     4,
       2,     2,     1,     6,     6,     5,     5,     3
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,    15,     0,     0,     1,     0,
       0,     0,     0,    32,     0,     0,    15,     0,     0,     0,
       0,     0,     4,     0,    39,    12,     0,     0,     0,     0,
       5,     6,     2,    17,     0,     0,    16,     0,     0,     0,
       0,     0,     8,     9,    10,     7,     3,     0,    24,    27,
       0,     0,    31,    30,    21,    18,     0,    34,     0,     0,
      33,     0,     0,     0,     0,     0,     0,    14,    13,    11,
       0,    22,    25,    28,    23,    26,    29,     0,     0,   122,
       0,    36,    35,     0,    41,    46,    46,     0,    79,     0,
       0,     0,    68,     0,    62,    67,     0,    40,    15,    20,
      19,     0,     0,     0,    32,    43,     0,    44,     0,    65,
      59,     0,     0,    82,     0,     0,   109,     0,   108,     0,
       0,   110,     0,    91,   101,   107,     0,     0,     0,     0,
       0,    65,    58,     0,    42,    38,     0,     0,     0,    37,
       0,     0,     0,     0,     0,    51,    53,    54,     0,    63,
       0,     0,    90,     0,     0,    65,     0,     0,   121,   120,
       0,     0,    65,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    65,
      65,    65,    60,    61,    66,     0,     0,     0,     0,     0,
      57,     0,    48,    55,     0,     0,     0,    47,    45,     0,
      81,     0,    80,    85,    87,    84,    77,     0,     0,   112,
       0,   118,     0,   117,    77,    92,    98,    99,   100,    93,
      94,    95,    96,    97,   102,   103,   104,   105,   106,     0,
       0,    76,    75,    64,     0,     0,   127,     0,     0,    52,
      56,    49,    50,    89,    88,    86,    65,    70,     0,     0,
     114,   116,   111,   119,    69,    65,     0,     0,   124,     0,
     123,    78,   113,   115,    72,     0,     0,   126,   125,    65,
       0,    73,    74,    71
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,   143,    12,    13,    21,    54,    24,    39,
      40,    65,    66,   107,   144,   145,   146,   147,   105,    92,
      93,    94,   247,    95,   121,   113,   151,   152,   123,   124,
     125,    81,   138
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -114
static const yytype_int16 yypact[] =
{
      12,    37,   256,    85,    27,   126,   -26,    70,  -114,   129,
      75,   260,    99,   161,   181,   264,   126,   140,     2,   170,
     178,   141,  -114,   292,  -114,  -114,   100,   158,    14,   175,
    -114,  -114,  -114,   232,   287,   225,   237,   240,   150,   210,
      31,   316,  -114,  -114,  -114,  -114,  -114,   224,  -114,  -114,
     125,   154,  -114,  -114,  -114,  -114,   229,   181,    -2,   241,
     181,   250,   269,   270,    39,   280,   288,  -114,  -114,  -114,
     287,  -114,  -114,  -114,  -114,  -114,  -114,   287,   226,  -114,
     252,  -114,  -114,   272,    83,   234,   234,    22,   171,   201,
     332,   206,  -114,    16,  -114,  -114,   289,  -114,   126,  -114,
    -114,    -2,    23,    -2,   161,  -114,   128,  -114,   296,    77,
    -114,   207,   227,  -114,   281,   155,  -114,   268,  -114,   268,
     236,  -114,   290,   274,   304,  -114,   306,   295,   276,   307,
      26,    77,  -114,   268,  -114,  -114,    24,   265,    94,  -114,
     291,    10,   181,   277,   106,  -114,  -114,  -114,   331,  -114,
     103,   109,  -114,    96,    20,    77,   299,   108,  -114,  -114,
     300,    45,    77,   268,   268,   268,   268,   268,   268,   268,
     268,   268,   268,   268,   268,   268,   268,   268,   268,    77,
      77,    77,  -114,  -114,  -114,   333,   308,   334,   335,   313,
    -114,   216,  -114,  -114,   339,   309,   216,  -114,  -114,   268,
    -114,   268,  -114,  -114,   305,  -114,   319,   249,   120,  -114,
      78,  -114,   310,  -114,   319,   139,   304,   304,   304,   139,
     139,   139,   139,   139,  -114,  -114,  -114,  -114,  -114,   322,
     320,  -114,  -114,  -114,   321,   346,  -114,   323,   348,  -114,
    -114,  -114,  -114,  -114,  -114,  -114,    77,  -114,   354,   121,
    -114,   317,  -114,  -114,  -114,    77,   255,   350,  -114,   351,
    -114,  -114,  -114,  -114,  -114,   336,   337,  -114,  -114,    77,
       8,  -114,  -114,  -114
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -114,  -114,  -114,    80,    17,   -62,  -114,     7,   259,  -114,
    -114,  -114,  -114,   278,  -114,   -25,  -114,   223,   273,   -38,
    -114,  -108,   152,  -114,   -64,  -114,  -107,   -81,   153,   166,
    -113,   233,  -114
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -84
static const yytype_int16 yytable[] =
{
      96,   149,    67,    31,   158,   154,   159,    79,   122,   272,
     129,    88,   -65,     1,   191,    44,    14,   130,    80,    41,
     131,   204,   104,   183,   136,   201,   109,    18,     9,   185,
     181,    10,    61,    29,   137,    89,   104,    90,   -65,   161,
      87,     5,    88,   -65,    91,    96,   212,   206,    62,    63,
     210,    32,   184,   192,   214,    64,   -65,    45,     2,   224,
     225,   226,   227,   228,   132,   205,    89,    96,    90,   186,
     110,   231,   232,   233,   182,    91,    17,    99,    64,   251,
      88,    11,   -15,   201,   100,     8,    64,   -65,   213,    11,
     -15,    96,   -15,   -15,    26,    28,   229,   230,    96,   188,
     249,   199,   190,    38,    89,    41,    90,   195,   199,   208,
     196,   115,    15,    91,   201,    96,    96,    96,   243,   116,
     244,   252,   -15,   117,    64,   199,   201,   118,    71,   141,
     -15,    25,    11,    16,   119,   142,    72,    78,   261,   189,
      83,   203,    35,    42,    73,    36,   200,   264,    22,   197,
     120,   209,   202,   164,   165,    41,   156,    74,    58,   -83,
     -83,   271,   273,   250,   262,    75,   239,   -83,    23,   -83,
     -83,   242,   166,    76,    33,   266,   -83,   -83,   -83,   -83,
     -83,   -83,    96,   -83,    25,   -83,   -83,   -83,   -83,    30,
      34,    96,   -83,   -83,   -83,   -83,   -83,   157,   -83,   112,
     -83,    43,   114,   -83,   115,    96,    96,   128,   150,   115,
     115,    59,   116,   111,    60,   112,   117,   116,   116,    25,
     118,   117,   117,   142,    46,   118,   118,   119,   153,    55,
     115,    41,   119,   119,   101,    47,    70,   160,   116,   115,
      56,    77,   117,   120,    57,    82,   118,   116,   120,   120,
     248,   117,   115,   119,    84,   118,   265,     6,   115,     7,
     116,    19,   119,    20,   117,    27,   116,    25,   118,   120,
     117,   115,    85,    86,   118,   119,   106,    41,   120,   116,
     103,   119,    41,   117,    97,   194,   163,   118,   164,   165,
      48,   120,    98,    37,   119,    25,   102,   120,    49,   133,
     187,    50,    51,    52,   148,   178,    53,   166,   179,   155,
     120,   167,   168,   169,   170,   171,   215,    68,   162,    69,
     219,   220,   221,   222,   223,   172,   173,   174,   175,   176,
     216,   217,   218,   126,   135,   127,   139,   177,    64,   180,
     198,   207,   235,   211,   234,   236,   237,   238,   240,   246,
     245,   256,   241,   253,   255,   258,   257,   260,   259,   199,
     263,   267,   268,   140,   108,   193,   254,     0,   269,   270,
       0,   134
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-114)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      64,   109,    40,     1,   117,   112,   119,     9,    89,     1,
      91,     3,     4,     1,     4,     1,    42,     1,    20,     5,
       4,     1,    84,   131,     1,     5,     4,    10,     1,     5,
       4,     4,     1,    16,    11,    27,    98,    29,    30,   120,
       1,     4,     3,     4,    36,   109,     1,   155,    17,    18,
     157,    49,   133,    43,   162,    47,    48,    43,    46,   172,
     173,   174,   175,   176,    48,    45,    27,   131,    29,    45,
      48,   179,   180,   181,    48,    36,     1,    70,    47,     1,
       3,     6,     7,     5,    77,     0,    47,    48,    43,     6,
       7,   155,    17,    18,    14,    15,   177,   178,   162,     5,
     207,     5,   140,    23,    27,     5,    29,     1,     5,     1,
       4,     3,    42,    36,     5,   179,   180,   181,   199,    11,
     201,    43,    47,    15,    47,     5,     5,    19,     3,     1,
      47,     3,     6,     4,    26,     7,    11,    57,   246,    45,
      60,    45,     1,    43,    19,     4,    43,   255,    49,    43,
      42,    43,    43,    14,    15,     5,     1,     3,     8,     4,
       5,   269,   270,    43,    43,    11,   191,    12,     7,    14,
      15,   196,    33,    19,     4,   256,    21,    22,    23,    24,
      25,    10,   246,    28,     3,    30,    31,    32,    33,    49,
      12,   255,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    43,     1,    48,     3,   269,   270,     1,     1,     3,
       3,     1,    11,    42,     4,    44,    15,    11,    11,     3,
      19,    15,    15,     7,    49,    19,    19,    26,     1,     4,
       3,     5,    26,    26,     8,     3,    12,     1,    11,     3,
       3,    12,    15,    42,     4,     4,    19,    11,    42,    42,
       1,    15,     3,    26,     4,    19,     1,     1,     3,     3,
      11,     1,    26,     3,    15,     1,    11,     3,    19,    42,
      15,     3,     3,     3,    19,    26,    42,     5,    42,    11,
       8,    26,     5,    15,     4,     8,    12,    19,    14,    15,
       3,    42,     4,     1,    26,     3,    44,    42,    11,    10,
      35,    14,    15,    16,     8,    10,    19,    33,    32,    28,
      42,    37,    38,    39,    40,    41,   163,     1,    28,     3,
     167,   168,   169,   170,   171,    21,    22,    23,    24,    25,
     164,   165,   166,     1,   101,     3,   103,    31,    47,    32,
       9,    42,    34,    43,    11,    11,    11,    34,     9,    30,
      45,    31,    43,    43,    32,     9,    35,     9,    35,     5,
      43,    11,    11,   104,    86,   142,   214,    -1,    32,    32,
      -1,    98
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    46,    51,    52,     4,     1,     3,     0,     1,
       4,     6,    54,    55,    42,    42,     4,     1,    54,     1,
       3,    56,    49,     7,    58,     3,    53,     1,    53,    54,
      49,     1,    49,     4,    12,     1,     4,     1,    53,    59,
      60,     5,    43,    43,     1,    43,    49,     3,     3,    11,
      14,    15,    16,    19,    57,     4,     3,     4,     8,     1,
       4,     1,    17,    18,    47,    61,    62,    69,     1,     3,
      12,     3,    11,    19,     3,    11,    19,    12,    53,     9,
      20,    81,     4,    53,     4,     3,     3,     1,     3,    27,
      29,    36,    69,    70,    71,    73,    74,     4,     4,    57,
      57,     8,    44,     8,    55,    68,    42,    63,    63,     4,
      48,    42,    44,    75,     1,     3,    11,    15,    19,    26,
      42,    74,    77,    78,    79,    80,     1,     3,     1,    77,
       1,     4,    48,    10,    68,    81,     1,    11,    82,    81,
      58,     1,     7,    53,    64,    65,    66,    67,     8,    71,
       1,    76,    77,     1,    76,    28,     1,    42,    80,    80,
       1,    77,    28,    12,    14,    15,    33,    37,    38,    39,
      40,    41,    21,    22,    23,    24,    25,    31,    10,    32,
      32,     4,    48,    71,    77,     5,    45,    35,     5,    45,
      69,     4,    43,    67,     8,     1,     4,    43,     9,     5,
      43,     5,    43,    45,     1,    45,    71,    42,     1,    43,
      76,    43,     1,    43,    71,    78,    79,    79,    79,    78,
      78,    78,    78,    78,    80,    80,    80,    80,    80,    77,
      77,    71,    71,    71,    11,    34,    11,    11,    34,    65,
       9,    43,    65,    77,    77,    45,    30,    72,     1,    76,
      43,     1,    43,    43,    72,    32,    31,    35,     9,    35,
       9,    71,    43,    43,    71,     1,    77,    11,    11,    32,
      32,    71,     1,    71
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (YYID (N))                                                     \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (YYID (0))
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

__attribute__((__unused__))
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
#else
static unsigned
yy_location_print_ (yyo, yylocp)
    FILE *yyo;
    YYLTYPE const * const yylocp;
#endif
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += fprintf (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += fprintf (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += fprintf (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += fprintf (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += fprintf (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

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
		  Type, Value, Location); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
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

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;


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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.
       `yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
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
	YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
/* Line 1792 of yacc.c  */
#line 47 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("programstruct"),std::string(""),std::vector<int>{(yyvsp[(1) - (4)].ival),(yyvsp[(2) - (4)].ival),(yyvsp[(3) - (4)].ival)}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[(yyvsp[(1) - (4)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (4)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (4)].ival)].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
					}
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 58 "parser.y"
    {
					lParseError("����ͷ�������﷨����",(yylsp[(2) - (5)]));
					}
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 61 "parser.y"
    {
					lParseError("����ͷ�������﷨����",(yylsp[(2) - (4)]));
					}
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 64 "parser.y"
    {
					lParseError("����������﷨����",(yylsp[(2) - (4)]));
					}
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 67 "parser.y"
    {
					lParseError("�����β�����﷨����",(yylsp[(2) - (4)]));
					}
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 74 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("program_head"),std::string(""),std::vector<int>{(yyvsp[(2) - (5)].ival),(yyvsp[(3) - (5)].ival),(yyvsp[(4) - (5)].ival),(yyvsp[(5) - (5)].ival)}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[(yyvsp[(2) - (5)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (5)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(4) - (5)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(5) - (5)].ival)].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
				   }
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 86 "parser.y"
    {
					lParseError("������ǰȱ������������",(yylsp[(3) - (5)]));
					}
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 89 "parser.y"
    {
					lParseError("ȱ�������������������������﷨����",(yylsp[(3) - (5)]));
					}
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 92 "parser.y"
    {
					lParseError("������ȱ��������",(yylsp[(3) - (5)]));
					}
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 96 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("idlist"),std::string(""),std::vector<int>{(yyvsp[(1) - (3)].ival),(yyvsp[(2) - (3)].ival),(yyvsp[(3) - (3)].ival)}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[(yyvsp[(1) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (3)].ival)].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
				   }
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 107 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("idlist"),std::string(""),std::vector<int>{(yyvsp[(1) - (1)].ival)}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[(yyvsp[(1) - (1)].ival)].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 116 "parser.y"
    {
					lParseError("������������﷨����",(yylsp[(2) - (3)]));
					}
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 120 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("program_body"),std::string(""),std::vector<int>{(yyvsp[(1) - (4)].ival),(yyvsp[(2) - (4)].ival),(yyvsp[(3) - (4)].ival),(yyvsp[(4) - (4)].ival)}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[(yyvsp[(1) - (4)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (4)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (4)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(4) - (4)].ival)].setParent(parseTree.size() - 1);
}
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 132 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("const_declarations"),std::string(""),std::vector<int>{}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 140 "parser.y"
    {				   
				   parseTree.push_back(ParseTreeNode(std::string("const_declarations"),std::string(""),std::vector<int>{(yyvsp[(1) - (3)].ival),(yyvsp[(2) - (3)].ival)}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[(yyvsp[(1) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (3)].ival)].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
				   }
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 150 "parser.y"
    {
					lParseError("�������������﷨����",(yylsp[(3) - (3)]));
					}
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 153 "parser.y"
    {
					lParseError("�������������﷨����",(yylsp[(3) - (4)]));
					}
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 157 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("const_declaration"),std::string(""),std::vector<int>{(yyvsp[(1) - (5)].ival),(yyvsp[(2) - (5)].ival),(yyvsp[(3) - (5)].ival),(yyvsp[(4) - (5)].ival),(yyvsp[(5) - (5)].ival)}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[(yyvsp[(1) - (5)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (5)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (5)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(4) - (5)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(5) - (5)].ival)].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 170 "parser.y"
    {
					lParseError("�������������﷨����",(yylsp[(2) - (5)]));
					}
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 173 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("const_declaration"),std::string(""),std::vector<int>{(yyvsp[(1) - (3)].ival),(yyvsp[(2) - (3)].ival),(yyvsp[(3) - (3)].ival)}));
				   //��¼ָ�򱾽ڵ��ָ�� 
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[(yyvsp[(1) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (3)].ival)].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;	
}
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 186 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("const_value"),std::string(""),std::vector<int>{(yyvsp[(1) - (2)].ival),(yyvsp[(2) - (2)].ival)}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[(yyvsp[(1) - (2)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (2)].ival)].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;	
}
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 197 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("const_value"),std::string(""),std::vector<int>{(yyvsp[(1) - (2)].ival),(yyvsp[(2) - (2)].ival)}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[(yyvsp[(1) - (2)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (2)].ival)].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;		
}
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 208 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("const_value"),std::string(""),std::vector<int>{(yyvsp[(1) - (1)].ival)}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[(yyvsp[(1) - (1)].ival)].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;	
}
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 217 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("const_value"),std::string(""),std::vector<int>{(yyvsp[(1) - (2)].ival),(yyvsp[(2) - (2)].ival)}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[(yyvsp[(1) - (2)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (2)].ival)].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;		
}
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 227 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("const_value"),std::string(""),std::vector<int>{(yyvsp[(1) - (2)].ival),(yyvsp[(2) - (2)].ival)}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[(yyvsp[(1) - (2)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (2)].ival)].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;	
}
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 237 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("const_value"),std::string(""),std::vector<int>{(yyvsp[(1) - (1)].ival)}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[(yyvsp[(1) - (1)].ival)].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;	
}
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 246 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("const_value"),std::string(""),std::vector<int>{(yyvsp[(1) - (2)].ival)}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[(yyvsp[(1) - (2)].ival)].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 255 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("const_value"),std::string(""),std::vector<int>{(yyvsp[(1) - (2)].ival)}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[(yyvsp[(1) - (2)].ival)].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 264 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("const_value"),std::string(""),std::vector<int>{(yyvsp[(1) - (1)].ival)}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[(yyvsp[(1) - (1)].ival)].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 273 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("const_value"),std::string(""),std::vector<int>{(yyvsp[(1) - (1)].ival)}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[(yyvsp[(1) - (1)].ival)].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;	
}
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 283 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("var_declarations"),std::string(""),std::vector<int>{}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 291 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("var_declarations"),std::string(""),std::vector<int>{(yyvsp[(1) - (3)].ival),(yyvsp[(2) - (3)].ival),(yyvsp[(3) - (3)].ival)}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[(yyvsp[(1) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (3)].ival)].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;	
}
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 302 "parser.y"
    {
					lParseError("�������������﷨����",(yylsp[(3) - (3)]));
					}
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 305 "parser.y"
    {
					lParseError("�������������﷨����",(yylsp[(3) - (4)]));
					}
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 309 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("var_declaration"),std::string(""),std::vector<int>{(yyvsp[(1) - (3)].ival),(yyvsp[(2) - (3)].ival),(yyvsp[(3) - (3)].ival)}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[(yyvsp[(1) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (3)].ival)].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 320 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("var_declaration"),std::string(""),std::vector<int>{(yyvsp[(1) - (5)].ival),(yyvsp[(2) - (5)].ival),(yyvsp[(3) - (5)].ival),(yyvsp[(4) - (5)].ival),(yyvsp[(5) - (5)].ival)}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[(yyvsp[(1) - (5)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (5)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (5)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(4) - (5)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(5) - (5)].ival)].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 334 "parser.y"
    {
					lParseError("�������������﷨����",(yylsp[(2) - (5)]));
					}
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 339 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("subprogram_declarations"),std::string(""),std::vector<int>{}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;	
}
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 347 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("subprogram_declarations"),std::string(""),std::vector<int>{(yyvsp[(1) - (3)].ival),(yyvsp[(2) - (3)].ival),(yyvsp[(3) - (3)].ival)}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[(yyvsp[(1) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (3)].ival)].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 358 "parser.y"
    {
					lParseError("�ӳ�����Ӻ����﷨����",(yylsp[(3) - (3)]));
					}
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 362 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("subprogram"),std::string(""),std::vector<int>{(yyvsp[(1) - (3)].ival),(yyvsp[(2) - (3)].ival),(yyvsp[(3) - (3)].ival)}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[(yyvsp[(1) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (3)].ival)].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;		
}
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 373 "parser.y"
    {
					lParseError("�Ӻ���ͷ�������﷨����",(yylsp[(2) - (3)]));
					}
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 377 "parser.y"
    {
					parseTree.push_back(ParseTreeNode(std::string("subprogram_head"),std::string(""),std::vector<int>{(yyvsp[(2) - (3)].ival),(yyvsp[(3) - (3)].ival)}));
					//��¼ָ�򱾽ڵ��ָ��
					(yyval.ival) = parseTree.size() - 1;
					//Ϊ�ӽڵ����ø��ڵ�ָ��
					parseTree[(yyvsp[(2) - (3)].ival)].setParent(parseTree.size() - 1);
					parseTree[(yyvsp[(3) - (3)].ival)].setParent(parseTree.size() - 1);
					//���ø��ڵ㣬�����ϲ������Ҫ 
					parseTreeRoot = parseTree.size() - 1;	
}
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 387 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("subprogram_head"),std::string(""),std::vector<int>{(yyvsp[(1) - (5)].ival),(yyvsp[(2) - (5)].ival),(yyvsp[(3) - (5)].ival),(yyvsp[(4) - (5)].ival),(yyvsp[(5) - (5)].ival)}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[(yyvsp[(1) - (5)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (5)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (5)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(4) - (5)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(5) - (5)].ival)].setParent(parseTree.size() - 1);
}
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 399 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("formal_parameter"),std::string(""),std::vector<int>{}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 407 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("formal_parameter"),std::string(""),std::vector<int>{(yyvsp[(1) - (3)].ival),(yyvsp[(2) - (3)].ival),(yyvsp[(3) - (3)].ival)}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[(yyvsp[(1) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (3)].ival)].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 418 "parser.y"
    {
					lParseError("�������ȱʧ���﷨����",(yylsp[(1) - (3)]));
					}
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 421 "parser.y"
    {
					lParseError("�������ȱʧ���﷨����",(yylsp[(2) - (4)]));
					}
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 425 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("parameter_list"),std::string(""),std::vector<int>{(yyvsp[(1) - (3)].ival),(yyvsp[(2) - (3)].ival),(yyvsp[(3) - (3)].ival)}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[(yyvsp[(1) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (3)].ival)].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 436 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("parameter_list"),std::string(""),std::vector<int>{(yyvsp[(1) - (1)].ival)}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[(yyvsp[(1) - (1)].ival)].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 445 "parser.y"
    {
					lParseError("�ֺ�ǰ��������﷨����",(yylsp[(2) - (3)]));
					}
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 455 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("parameter"),std::string(""),std::vector<int>{(yyvsp[(1) - (1)].ival)}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[(yyvsp[(1) - (1)].ival)].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 464 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("parameter"),std::string(""),std::vector<int>{(yyvsp[(1) - (1)].ival)}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[(yyvsp[(1) - (1)].ival)].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 473 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("var_parameter"),std::string(""),std::vector<int>{(yyvsp[(1) - (2)].ival),(yyvsp[(2) - (2)].ival)}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[(yyvsp[(1) - (2)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (2)].ival)].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;	
}
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 484 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("value_parameter"),std::string(""),std::vector<int>{(yyvsp[(1) - (3)].ival),(yyvsp[(2) - (3)].ival),(yyvsp[(3) - (3)].ival)}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[(yyvsp[(1) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (3)].ival)].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 496 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("subprogram_body"),std::string(""),std::vector<int>{(yyvsp[(1) - (3)].ival),(yyvsp[(2) - (3)].ival),(yyvsp[(3) - (3)].ival)}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[(yyvsp[(1) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (3)].ival)].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 508 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("compound_statement"),std::string(""),std::vector<int>{(yyvsp[(2) - (3)].ival)}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[(yyvsp[(2) - (3)].ival)].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 517 "parser.y"
    {
					lParseError("ȱʧ���������������﷨����",(yyloc));
					}
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 520 "parser.y"
    {
					lParseError("ȱʧ���������������﷨����",(yyloc));
					}
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 524 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("statement_list"),std::string(""),std::vector<int>{(yyvsp[(1) - (3)].ival),(yyvsp[(2) - (3)].ival),(yyvsp[(3) - (3)].ival)}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[(yyvsp[(1) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (3)].ival)].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 535 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("statement_list"),std::string(""),std::vector<int>{(yyvsp[(1) - (1)].ival)}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[(yyvsp[(1) - (1)].ival)].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 544 "parser.y"
    {
					lParseError("�ֺ�ǰ�������﷨����",(yylsp[(2) - (3)]));
					}
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 547 "parser.y"
    {
					lParseError("�ֺ�ǰ�������﷨����",(yylsp[(3) - (4)]));
					}
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 551 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("statement"),std::string(""),std::vector<int>{}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 559 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("statement"),std::string(""),std::vector<int>{(yyvsp[(1) - (3)].ival),(yyvsp[(2) - (3)].ival),(yyvsp[(3) - (3)].ival)}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[(yyvsp[(1) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (3)].ival)].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 570 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("statement"),std::string(""),std::vector<int>{(yyvsp[(1) - (1)].ival)}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[(yyvsp[(1) - (1)].ival)].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 579 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("statement"),std::string(""),std::vector<int>{(yyvsp[(1) - (1)].ival)}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[(yyvsp[(1) - (1)].ival)].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 588 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("statement"),std::string(""),std::vector<int>{(yyvsp[(1) - (5)].ival),(yyvsp[(2) - (5)].ival),(yyvsp[(3) - (5)].ival),(yyvsp[(4) - (5)].ival),(yyvsp[(5) - (5)].ival)}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[(yyvsp[(1) - (5)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (5)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (5)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(4) - (5)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(5) - (5)].ival)].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 601 "parser.y"
    {
					lParseError("if��ȱ�ٱ��ʽ����ʽ�����﷨����",(yylsp[(1) - (5)]));
					}
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 604 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("statement"),std::string(""),std::vector<int>{(yyvsp[(1) - (8)].ival),(yyvsp[(2) - (8)].ival),(yyvsp[(3) - (8)].ival),(yyvsp[(4) - (8)].ival),(yyvsp[(5) - (8)].ival),(yyvsp[(6) - (8)].ival),(yyvsp[(7) - (8)].ival),(yyvsp[(8) - (8)].ival)}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[(yyvsp[(1) - (8)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (8)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (8)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(4) - (8)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(5) - (8)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(6) - (8)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(7) - (8)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(8) - (8)].ival)].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 620 "parser.y"
    {
					lParseError("forѭ���������ʽ�﷨����",(yylsp[(1) - (6)]));
					}
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 623 "parser.y"
    {
					lParseError("forѭ��ȱ����ֹ�������ʽ",(yylsp[(5) - (8)]));
					}
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 626 "parser.y"
    {
					lParseError("forѭ���������﷨����",(yylsp[(7) - (8)]));
					}
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 629 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("statement"),std::string(""),std::vector<int>{(yyvsp[(1) - (4)].ival),(yyvsp[(2) - (4)].ival),(yyvsp[(3) - (4)].ival),(yyvsp[(4) - (4)].ival)}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[(yyvsp[(1) - (4)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (4)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (4)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(4) - (4)].ival)].setParent(parseTree.size() - 1);
}
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 639 "parser.y"
    {
					lParseError("while����ʽȱʧ����ڴ���",(yylsp[(1) - (4)]));
					}
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 643 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("else_part"),std::string(""),std::vector<int>{}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 651 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("else_part"),std::string(""),std::vector<int>{(yyvsp[(1) - (2)].ival),(yyvsp[(2) - (2)].ival)}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[(yyvsp[(1) - (2)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (2)].ival)].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 661 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("procedure_call"),std::string(""),std::vector<int>{(yyvsp[(1) - (1)].ival)}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[(yyvsp[(1) - (1)].ival)].setParent(parseTree.size() - 1);				
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 80:
/* Line 1792 of yacc.c  */
#line 670 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("procedure_call"),std::string(""),std::vector<int>{(yyvsp[(1) - (4)].ival),(yyvsp[(2) - (4)].ival),(yyvsp[(3) - (4)].ival),(yyvsp[(4) - (4)].ival)}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[(yyvsp[(1) - (4)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (4)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (4)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(4) - (4)].ival)].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 81:
/* Line 1792 of yacc.c  */
#line 682 "parser.y"
    {
					lParseError("�������ò�����ʽ�����﷨����",(yylsp[(2) - (4)]));
					}
    break;

  case 82:
/* Line 1792 of yacc.c  */
#line 687 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("variable"),std::string(""),std::vector<int>{(yyvsp[(1) - (2)].ival),(yyvsp[(2) - (2)].ival)}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[(yyvsp[(1) - (2)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (2)].ival)].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 83:
/* Line 1792 of yacc.c  */
#line 698 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("id_varpart"),std::string(""),std::vector<int>{}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
}
    break;

  case 84:
/* Line 1792 of yacc.c  */
#line 704 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("id_varpart"),std::string(""),std::vector<int>{(yyvsp[(1) - (3)].ival),(yyvsp[(2) - (3)].ival),(yyvsp[(3) - (3)].ival)}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[(yyvsp[(1) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (3)].ival)].setParent(parseTree.size() - 1);
}
    break;

  case 85:
/* Line 1792 of yacc.c  */
#line 714 "parser.y"
    {
					lParseError("�����﷨��ʽ����",(yylsp[(1) - (3)]));
					}
    break;

  case 86:
/* Line 1792 of yacc.c  */
#line 717 "parser.y"
    {
					lParseError("�����﷨��ʽ����",(yylsp[(1) - (4)]));
					}
    break;

  case 87:
/* Line 1792 of yacc.c  */
#line 720 "parser.y"
    {
					lParseError("�����﷨��ʽ����",(yylsp[(1) - (3)]));
					}
    break;

  case 88:
/* Line 1792 of yacc.c  */
#line 724 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("expression_list"),std::string(""),std::vector<int>{(yyvsp[(1) - (3)].ival),(yyvsp[(2) - (3)].ival),(yyvsp[(3) - (3)].ival)}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[(yyvsp[(1) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (3)].ival)].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 89:
/* Line 1792 of yacc.c  */
#line 735 "parser.y"
    {
					lParseError("����ǰ���ݴ����﷨����",(yylsp[(2) - (3)]));
					}
    break;

  case 90:
/* Line 1792 of yacc.c  */
#line 738 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("expression_list"),std::string(""),std::vector<int>{(yyvsp[(1) - (1)].ival)}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[(yyvsp[(1) - (1)].ival)].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 91:
/* Line 1792 of yacc.c  */
#line 747 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("expression"),std::string(""),std::vector<int>{(yyvsp[(1) - (1)].ival)}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[(yyvsp[(1) - (1)].ival)].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 92:
/* Line 1792 of yacc.c  */
#line 756 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("expression"),std::string(""),std::vector<int>{(yyvsp[(1) - (3)].ival),(yyvsp[(2) - (3)].ival),(yyvsp[(3) - (3)].ival)}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[(yyvsp[(1) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (3)].ival)].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;		
}
    break;

  case 93:
/* Line 1792 of yacc.c  */
#line 767 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("expression"),std::string(""),std::vector<int>{(yyvsp[(1) - (3)].ival),(yyvsp[(2) - (3)].ival),(yyvsp[(3) - (3)].ival)}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[(yyvsp[(1) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (3)].ival)].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 94:
/* Line 1792 of yacc.c  */
#line 778 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("expression"),std::string(""),std::vector<int>{(yyvsp[(1) - (3)].ival),(yyvsp[(2) - (3)].ival),(yyvsp[(3) - (3)].ival)}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[(yyvsp[(1) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (3)].ival)].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 95:
/* Line 1792 of yacc.c  */
#line 789 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("expression"),std::string(""),std::vector<int>{(yyvsp[(1) - (3)].ival),(yyvsp[(2) - (3)].ival),(yyvsp[(3) - (3)].ival)}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[(yyvsp[(1) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (3)].ival)].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 96:
/* Line 1792 of yacc.c  */
#line 800 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("expression"),std::string(""),std::vector<int>{(yyvsp[(1) - (3)].ival),(yyvsp[(2) - (3)].ival),(yyvsp[(3) - (3)].ival)}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[(yyvsp[(1) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (3)].ival)].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 97:
/* Line 1792 of yacc.c  */
#line 811 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("expression"),std::string(""),std::vector<int>{(yyvsp[(1) - (3)].ival),(yyvsp[(2) - (3)].ival),(yyvsp[(3) - (3)].ival)}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[(yyvsp[(1) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (3)].ival)].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 98:
/* Line 1792 of yacc.c  */
#line 823 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("simple_expression"),std::string(""),std::vector<int>{(yyvsp[(1) - (3)].ival),(yyvsp[(2) - (3)].ival),(yyvsp[(3) - (3)].ival)}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[(yyvsp[(1) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (3)].ival)].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 99:
/* Line 1792 of yacc.c  */
#line 834 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("simple_expression"),std::string(""),std::vector<int>{(yyvsp[(1) - (3)].ival),(yyvsp[(2) - (3)].ival),(yyvsp[(3) - (3)].ival)}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[(yyvsp[(1) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (3)].ival)].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 100:
/* Line 1792 of yacc.c  */
#line 845 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("simple_expression"),std::string(""),std::vector<int>{(yyvsp[(1) - (3)].ival),(yyvsp[(2) - (3)].ival),(yyvsp[(3) - (3)].ival)}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[(yyvsp[(1) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (3)].ival)].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 101:
/* Line 1792 of yacc.c  */
#line 856 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("simple_expression"),std::string(""),std::vector<int>{(yyvsp[(1) - (1)].ival)}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[(yyvsp[(1) - (1)].ival)].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 102:
/* Line 1792 of yacc.c  */
#line 867 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("term"),std::string(""),std::vector<int>{(yyvsp[(1) - (3)].ival),(yyvsp[(2) - (3)].ival),(yyvsp[(3) - (3)].ival)}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[(yyvsp[(1) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (3)].ival)].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 103:
/* Line 1792 of yacc.c  */
#line 878 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("term"),std::string(""),std::vector<int>{(yyvsp[(1) - (3)].ival),(yyvsp[(2) - (3)].ival),(yyvsp[(3) - (3)].ival)}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[(yyvsp[(1) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (3)].ival)].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 104:
/* Line 1792 of yacc.c  */
#line 889 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("term"),std::string(""),std::vector<int>{(yyvsp[(1) - (3)].ival),(yyvsp[(2) - (3)].ival),(yyvsp[(3) - (3)].ival)}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[(yyvsp[(1) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (3)].ival)].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 105:
/* Line 1792 of yacc.c  */
#line 900 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("term"),std::string(""),std::vector<int>{(yyvsp[(1) - (3)].ival),(yyvsp[(2) - (3)].ival),(yyvsp[(3) - (3)].ival)}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[(yyvsp[(1) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (3)].ival)].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 106:
/* Line 1792 of yacc.c  */
#line 911 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("term"),std::string(""),std::vector<int>{(yyvsp[(1) - (3)].ival),(yyvsp[(2) - (3)].ival),(yyvsp[(3) - (3)].ival)}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[(yyvsp[(1) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (3)].ival)].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 107:
/* Line 1792 of yacc.c  */
#line 922 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("term"),std::string(""),std::vector<int>{(yyvsp[(1) - (1)].ival)}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[(yyvsp[(1) - (1)].ival)].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 108:
/* Line 1792 of yacc.c  */
#line 931 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("factor"),std::string(""),std::vector<int>{(yyvsp[(1) - (1)].ival)}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[(yyvsp[(1) - (1)].ival)].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 109:
/* Line 1792 of yacc.c  */
#line 940 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("factor"),std::string(""),std::vector<int>{(yyvsp[(1) - (1)].ival)}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[(yyvsp[(1) - (1)].ival)].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 110:
/* Line 1792 of yacc.c  */
#line 949 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("factor"),std::string(""),std::vector<int>{(yyvsp[(1) - (1)].ival)}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[(yyvsp[(1) - (1)].ival)].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 111:
/* Line 1792 of yacc.c  */
#line 958 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("factor"),std::string(""),std::vector<int>{(yyvsp[(1) - (4)].ival),(yyvsp[(2) - (4)].ival),(yyvsp[(3) - (4)].ival),(yyvsp[(4) - (4)].ival)}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[(yyvsp[(1) - (4)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (4)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (4)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(4) - (4)].ival)].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 112:
/* Line 1792 of yacc.c  */
#line 970 "parser.y"
    {
					
					}
    break;

  case 113:
/* Line 1792 of yacc.c  */
#line 973 "parser.y"
    {
					lParseError("���ʽ�к�������ID��ʽ����",(yylsp[(2) - (5)]));
					}
    break;

  case 114:
/* Line 1792 of yacc.c  */
#line 976 "parser.y"
    {
					lParseError("���ʽ�к������ô����﷨����",(yylsp[(2) - (4)]));
					}
    break;

  case 115:
/* Line 1792 of yacc.c  */
#line 979 "parser.y"
    {
					lParseError("���ʽ�к������ô����﷨����",(yylsp[(3) - (5)]));
					}
    break;

  case 116:
/* Line 1792 of yacc.c  */
#line 982 "parser.y"
    {
					lParseError("���ʽ�к�������ȱ��������",(yylsp[(3) - (4)]));
					}
    break;

  case 117:
/* Line 1792 of yacc.c  */
#line 985 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("factor"),std::string(""),std::vector<int>{(yyvsp[(1) - (3)].ival),(yyvsp[(2) - (3)].ival),(yyvsp[(3) - (3)].ival)}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[(yyvsp[(1) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (3)].ival)].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 118:
/* Line 1792 of yacc.c  */
#line 996 "parser.y"
    {
					lParseError("���ʽ�����д����﷨����",(yylsp[(1) - (3)]));
					}
    break;

  case 119:
/* Line 1792 of yacc.c  */
#line 999 "parser.y"
    {
					lParseError("���ʽ�����д����﷨����",(yylsp[(2) - (4)]));
					}
    break;

  case 120:
/* Line 1792 of yacc.c  */
#line 1002 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("factor"),std::string(""),std::vector<int>{(yyvsp[(1) - (2)].ival),(yyvsp[(2) - (2)].ival)}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[(yyvsp[(1) - (2)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (2)].ival)].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 121:
/* Line 1792 of yacc.c  */
#line 1012 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("factor"),std::string(""),std::vector<int>{(yyvsp[(1) - (2)].ival),(yyvsp[(2) - (2)].ival)}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[(yyvsp[(1) - (2)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (2)].ival)].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;	
}
    break;

  case 122:
/* Line 1792 of yacc.c  */
#line 1022 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("type"),std::string(""),std::vector<int>{(yyvsp[(1) - (1)].ival)}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[(yyvsp[(1) - (1)].ival)].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 123:
/* Line 1792 of yacc.c  */
#line 1031 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("type"),std::string(""),std::vector<int>{(yyvsp[(1) - (6)].ival),(yyvsp[(2) - (6)].ival),(yyvsp[(3) - (6)].ival),(yyvsp[(4) - (6)].ival),(yyvsp[(5) - (6)].ival),(yyvsp[(6) - (6)].ival)}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[(yyvsp[(1) - (6)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (6)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (6)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(4) - (6)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(5) - (6)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(6) - (6)].ival)].setParent(parseTree.size() - 1);
}
    break;

  case 124:
/* Line 1792 of yacc.c  */
#line 1044 "parser.y"
    {
					lParseError("������������﷨����",(yylsp[(2) - (6)]));
					}
    break;

  case 125:
/* Line 1792 of yacc.c  */
#line 1049 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("period"),std::string(""),std::vector<int>{(yyvsp[(1) - (5)].ival),(yyvsp[(2) - (5)].ival),(yyvsp[(3) - (5)].ival),(yyvsp[(4) - (5)].ival),(yyvsp[(5) - (5)].ival)}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[(yyvsp[(1) - (5)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (5)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (5)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(4) - (5)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(5) - (5)].ival)].setParent(parseTree.size() - 1);
}
    break;

  case 126:
/* Line 1792 of yacc.c  */
#line 1060 "parser.y"
    {
					lParseError("������������﷨����",(yylsp[(2) - (5)]));
					}
    break;

  case 127:
/* Line 1792 of yacc.c  */
#line 1064 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("period"),std::string(""),std::vector<int>{(yyvsp[(1) - (3)].ival),(yyvsp[(2) - (3)].ival),(yyvsp[(3) - (3)].ival)}));
				   //��¼ָ�򱾽ڵ��ָ��
				   (yyval.ival) = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[(yyvsp[(1) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (3)].ival)].setParent(parseTree.size() - 1);
}
    break;


/* Line 1792 of yacc.c  */
#line 3413 "parser.tab.cpp"
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
  *++yylsp = yyloc;

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

  yyerror_range[1] = yylloc;

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
		      yytoken, &yylval, &yylloc);
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

  yyerror_range[1] = yylsp[1-yylen];
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
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


/* Line 2055 of yacc.c  */
#line 1076 "parser.y"

void ParseError(std::string msg,int line)
{
	std::cout<< "Parse errors ("<<msg<<") : "<< " in line "<< line <<std::endl;
}

void lParseError(std::string msg,YYLTYPE t)
{
	std::cout<< "Parse errors ("<<msg<<") : "<< " in line"<< t.first_line <<" - line"<<t.last_line;
	std::cout<< " and column"<<t.first_column<<" -column"<<t.last_column<<std::endl;
}

int main(int argc, char* argv[]) 
{
	std::fstream f1,f2;
	if(argc > 1)
	{
		f1.open(argv[1],std::fstream::in);
		std::string filename = std::string(argv[1]);
		std::string filenameCopy = filename + "Copy";
		f2.open(filenameCopy.c_str(),std::fstream::out);
		char ch;
		while(f1.get(ch))
		{
			if(ch >= 'A' && ch <= 'Z')
			{
				ch += 32;
			}
			f2.put(ch);
		}
		f1.close();
		f2.close();
		yyin = fopen(filenameCopy.c_str(),"r");
		yyparse();
		if(parseNum==0&&lexerror==0)
			deal(filename);
		else
		{
			if(lexerror != 0)
				std::cout<<"����"<<lexerror<<"���ʷ�����"<<std::endl;
			if(parseNum != 0)
				std::cout<<"����"<<parseNum<<"���﷨����"<<std::endl;
		}
			
	}
	else
	{
		std::cout<<"error:δ�ṩ�����ļ�"<<std::endl;
	}
	return 0;
}

void yyerror(const char* s) {
	parseNum++;
	//fprintf(stderr, "Parse error: %s in line %d\n", s,yylloc.first_line);
	//exit(1);
}
