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
#include<string>
#include"parser.h"
#include"transform.h"
#include"parser.tab.h"

extern int yylex();
extern int yyparse();
extern FILE* yyin;
extern int yylineno;

void yyerror(const char* s);
std::vector<ParseTreeNode> parseTree;
void ParseError(std::string msg,int line);
void lParseError(std::string msg, YYLTYPE t);
int parseTreeRoot;

/* Line 371 of yacc.c  */
#line 90 "parser.tab.cpp"

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
     ENDTOK = 303
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 25 "parser.y"

	int ival;


/* Line 387 of yacc.c  */
#line 186 "parser.tab.cpp"
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
#line 227 "parser.tab.cpp"

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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   780

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  175
/* YYNRULES -- Number of states.  */
#define YYNSTATES  379

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   303

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
      45,    46,    47,    48
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,    11,    15,    19,    25,    31,    37,
      43,    49,    55,    59,    61,    65,    70,    71,    75,    79,
      83,    86,    92,    98,   104,   110,   116,   122,   125,   129,
     133,   137,   141,   145,   148,   151,   154,   157,   159,   162,
     165,   167,   170,   173,   175,   177,   178,   182,   186,   190,
     193,   197,   201,   205,   209,   215,   221,   227,   233,   239,
     245,   249,   250,   254,   258,   262,   266,   270,   274,   278,
     282,   288,   292,   296,   300,   303,   309,   315,   321,   327,
     333,   338,   339,   343,   347,   351,   355,   359,   361,   365,
     369,   373,   375,   377,   379,   382,   385,   389,   393,   397,
     401,   405,   409,   413,   417,   421,   425,   427,   431,   435,
     439,   440,   444,   448,   452,   456,   458,   460,   466,   472,
     478,   484,   490,   496,   505,   514,   523,   532,   541,   548,
     557,   566,   575,   584,   589,   594,   599,   604,   609,   610,
     613,   616,   618,   623,   626,   627,   631,   635,   637,   639,
     643,   647,   651,   655,   659,   663,   667,   671,   675,   677,
     681,   685,   689,   693,   697,   699,   701,   703,   705,   710,
     714,   717,   720,   722,   729,   735
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      50,     0,    -1,    51,     4,    53,    -1,     1,     4,    53,
      -1,    51,     4,     1,    -1,    51,     1,    53,    -1,    46,
       3,    42,    52,    43,    -1,    46,     3,     1,    52,    43,
      -1,    46,     3,    42,    52,     1,    -1,     1,     3,    42,
      52,    43,    -1,    46,     1,    42,    52,    43,    -1,    46,
       3,    42,     1,    43,    -1,    52,     5,     3,    -1,     3,
      -1,    52,     5,     1,    -1,    54,    57,    59,    68,    -1,
      -1,     6,    55,     4,    -1,     1,    55,     4,    -1,     6,
      55,     1,    -1,     6,     1,    -1,    55,     4,     3,    12,
      56,    -1,    55,     1,     3,    12,    56,    -1,    55,     4,
       1,    12,    56,    -1,    55,     4,     3,    12,     1,    -1,
      55,     4,     3,     1,    56,    -1,     1,     4,     3,    12,
      56,    -1,     1,     4,    -1,    55,     4,     1,    -1,     3,
      12,    56,    -1,     1,    12,    56,    -1,     3,    12,     1,
      -1,     3,     1,    56,    -1,    14,     3,    -1,    14,     1,
      -1,    15,     3,    -1,    15,     1,    -1,     3,    -1,    14,
      11,    -1,    15,    11,    -1,    11,    -1,    14,    19,    -1,
      15,    19,    -1,    19,    -1,    16,    -1,    -1,     7,    58,
       4,    -1,     1,    58,     4,    -1,     7,    58,     1,    -1,
       7,     1,    -1,    52,     8,    80,    -1,     1,     8,    80,
      -1,    52,     1,    80,    -1,    52,     8,     1,    -1,    58,
       4,    52,     8,    80,    -1,    58,     1,    52,     8,    80,
      -1,    58,     4,     1,     8,    80,    -1,    58,     4,    52,
       1,    80,    -1,    58,     4,    52,     8,     1,    -1,     1,
       4,    52,     8,    80,    -1,    58,     4,     1,    -1,    -1,
      59,    60,     4,    -1,    59,     1,     4,    -1,    59,    60,
       1,    -1,    61,     4,    67,    -1,     1,     4,    67,    -1,
      61,     4,     1,    -1,    61,     1,    67,    -1,    17,     3,
      62,    -1,    18,     3,    62,     8,     9,    -1,     1,     3,
      62,    -1,    17,     1,    62,    -1,    17,     3,     1,    -1,
      17,     1,    -1,     1,     3,    62,     8,     9,    -1,    18,
       1,    62,     8,     9,    -1,    18,     3,     1,     8,     9,
      -1,    18,     3,    62,     1,     9,    -1,    18,     3,    62,
       8,     1,    -1,    18,     3,    62,     1,    -1,    -1,    42,
      63,    43,    -1,     1,    63,    43,    -1,    42,    63,     1,
      -1,    42,     1,    43,    -1,    63,     4,    64,    -1,    64,
      -1,     1,     4,    64,    -1,    63,     1,    64,    -1,    63,
       4,     1,    -1,     1,    -1,    65,    -1,    66,    -1,     7,
      66,    -1,     7,     1,    -1,    52,     8,     9,    -1,     1,
       8,     9,    -1,    52,     1,     9,    -1,    52,     8,     1,
      -1,    54,    57,    68,    -1,    47,    69,    48,    -1,     1,
      69,    48,    -1,    47,     1,    48,    -1,    47,    69,     1,
      -1,    69,     4,    70,    -1,    70,    -1,    69,     1,    70,
      -1,     1,     4,    70,    -1,    69,     4,     1,    -1,    -1,
      73,    10,    76,    -1,     1,    10,    76,    -1,    73,     1,
      76,    -1,    73,    10,     1,    -1,    72,    -1,    68,    -1,
      27,    76,    28,    70,    71,    -1,     1,    76,    28,    70,
      71,    -1,    27,     1,    28,    70,    71,    -1,    27,    76,
       1,    70,    71,    -1,    27,    76,    28,     1,    71,    -1,
      27,    76,    28,    70,     1,    -1,    29,     3,    10,    76,
      31,    76,    32,    70,    -1,     1,     3,    10,    76,    31,
      76,    32,    70,    -1,    29,     1,    10,    76,    31,    76,
      32,    70,    -1,    29,     3,     1,    76,    31,    76,    32,
      70,    -1,    29,     3,    10,     1,    31,    76,    32,    70,
      -1,    29,     1,    31,    76,    32,    70,    -1,    29,     3,
      10,    76,     1,    76,    32,    70,    -1,    29,     3,    10,
      76,    31,     1,    32,    70,    -1,    29,     3,    10,    76,
      31,    76,     1,    70,    -1,    29,     3,    10,    76,    31,
      76,    32,     1,    -1,    36,    76,    32,    70,    -1,     1,
      76,    32,    70,    -1,    36,     1,    32,    70,    -1,    36,
      76,     1,    70,    -1,    36,    76,    32,     1,    -1,    -1,
      30,    70,    -1,    30,     1,    -1,     3,    -1,     3,    42,
      75,    43,    -1,     3,    74,    -1,    -1,    44,    75,    45,
      -1,    75,     5,    76,    -1,    76,    -1,    77,    -1,    77,
      12,    77,    -1,    77,    37,    77,    -1,    77,    38,    77,
      -1,    77,    39,    77,    -1,    77,    40,    77,    -1,    77,
      41,    77,    -1,    77,    14,    78,    -1,    77,    15,    78,
      -1,    77,    33,    78,    -1,    78,    -1,    78,    21,    79,
      -1,    78,    22,    79,    -1,    78,    23,    79,    -1,    78,
      24,    79,    -1,    78,    25,    79,    -1,    79,    -1,    19,
      -1,    11,    -1,    73,    -1,     3,    42,    75,    43,    -1,
      42,    76,    43,    -1,    26,    79,    -1,    15,    79,    -1,
       9,    -1,    20,    44,    81,    45,    34,     9,    -1,    81,
       5,    11,    35,    11,    -1,    11,    35,    11,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    44,    44,    55,    58,    61,    67,    80,    83,    86,
      89,    92,    96,   107,   116,   120,   132,   140,   150,   154,
     157,   161,   174,   177,   180,   183,   186,   189,   192,   195,
     206,   209,   212,   216,   226,   229,   239,   242,   251,   261,
     271,   280,   289,   298,   307,   317,   325,   336,   340,   343,
     347,   358,   362,   365,   368,   381,   384,   387,   390,   393,
     396,   401,   409,   420,   423,   427,   438,   441,   444,   448,
     458,   469,   472,   475,   478,   481,   484,   487,   490,   493,
     496,   500,   508,   519,   522,   525,   529,   540,   549,   552,
     555,   558,   562,   571,   580,   590,   595,   606,   609,   612,
     616,   628,   637,   640,   643,   647,   658,   667,   670,   673,
     677,   685,   696,   699,   702,   705,   714,   723,   736,   739,
     742,   745,   748,   751,   767,   770,   773,   776,   779,   782,
     785,   788,   791,   794,   804,   807,   810,   813,   817,   825,
     835,   838,   847,   859,   869,   875,   884,   895,   904,   913,
     924,   935,   946,   957,   968,   979,   990,  1001,  1012,  1021,
    1032,  1043,  1054,  1065,  1076,  1085,  1094,  1103,  1112,  1124,
    1135,  1145,  1156,  1165,  1178,  1189
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
  "rightSB", "program", "BEGINTOK", "ENDTOK", "$accept", "programstruct",
  "program_head", "idlist", "program_body", "const_declarations",
  "const_declaration", "const_value", "var_declarations",
  "var_declaration", "subprogram_declarations", "subprogram",
  "subprogram_head", "formal_parameter", "parameter_list", "parameter",
  "var_parameter", "value_parameter", "subprogram_body",
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
     295,   296,   297,   298,   299,   300,   301,   302,   303
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    50,    50,    50,    51,    51,    51,    51,
      51,    51,    52,    52,    52,    53,    54,    54,    54,    54,
      54,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    57,    57,    57,    57,    57,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    59,    59,    59,    59,    60,    60,    60,    60,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    62,    62,    62,    62,    62,    63,    63,    63,    63,
      63,    63,    64,    64,    65,    65,    66,    66,    66,    66,
      67,    68,    68,    68,    68,    69,    69,    69,    69,    69,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    71,    71,
      71,    72,    72,    73,    74,    74,    75,    75,    76,    76,
      76,    76,    76,    76,    76,    77,    77,    77,    77,    78,
      78,    78,    78,    78,    78,    79,    79,    79,    79,    79,
      79,    79,    80,    80,    81,    81
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     3,     3,     3,     5,     5,     5,     5,
       5,     5,     3,     1,     3,     4,     0,     3,     3,     3,
       2,     5,     5,     5,     5,     5,     5,     2,     3,     3,
       3,     3,     3,     2,     2,     2,     2,     1,     2,     2,
       1,     2,     2,     1,     1,     0,     3,     3,     3,     2,
       3,     3,     3,     3,     5,     5,     5,     5,     5,     5,
       3,     0,     3,     3,     3,     3,     3,     3,     3,     3,
       5,     3,     3,     3,     2,     5,     5,     5,     5,     5,
       4,     0,     3,     3,     3,     3,     3,     1,     3,     3,
       3,     1,     1,     1,     2,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     3,     3,     3,
       0,     3,     3,     3,     3,     1,     1,     5,     5,     5,
       5,     5,     5,     8,     8,     8,     8,     8,     6,     8,
       8,     8,     8,     4,     4,     4,     4,     4,     0,     2,
       2,     1,     4,     2,     0,     3,     3,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     3,
       3,     3,     3,     3,     1,     1,     1,     1,     4,     3,
       2,     2,     1,     6,     5,     3
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       0,     0,     0,     0,     0,     3,     0,     0,     0,     0,
       5,     0,     2,    13,     0,     0,     0,     0,    20,     0,
       0,     0,    61,     0,     0,     0,     0,     0,     9,    27,
       0,     0,     0,     0,     0,    19,     0,     0,     0,     0,
      49,     0,     0,    10,     7,    11,     8,     6,    14,    12,
       0,    37,    40,     0,     0,    44,    43,    30,    32,    31,
      29,     0,    28,     0,     0,     0,     0,     0,     0,     0,
      48,     0,     0,     0,     0,     0,     0,     0,    15,     0,
      34,    33,    38,    41,    36,    35,    39,    42,     0,     0,
       0,     0,     0,   172,     0,    51,    52,    53,    50,     0,
      60,     0,     0,     0,     0,     0,     0,     0,   116,     0,
     106,   115,     0,     0,     0,     0,     0,     0,   141,     0,
      64,    62,     0,     0,    26,    22,    23,    25,    24,    21,
       0,     0,     0,     0,     0,     0,   144,     0,     0,   166,
       0,   165,     0,     0,     0,     0,   148,   158,   164,     0,
       0,     0,    71,   143,     0,    66,     0,   144,   167,     0,
       0,     0,     0,     0,     0,     0,   102,     0,     0,     0,
      72,     0,    69,     0,     0,     0,   103,     0,     0,   101,
      68,     0,    65,    59,     0,     0,    55,    56,    57,    58,
      54,     0,     0,     0,   108,   112,   171,   170,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    91,     0,     0,     0,    87,
      92,    93,    91,   144,     0,     0,   147,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   107,     0,   105,   113,   114,   111,     0,     0,    80,
       0,     0,     0,     0,     0,     0,   169,   138,   134,   149,
     155,   156,   157,   150,   151,   152,   153,   154,   159,   160,
     161,   162,   163,     0,     0,    95,    94,     0,     0,     0,
       0,    83,    85,     0,    82,     0,   142,   145,    75,     0,
     100,   138,     0,   138,     0,     0,     0,     0,     0,     0,
       0,   135,   136,     0,   133,    76,    77,    78,    79,    70,
     175,     0,     0,     0,   168,     0,   118,     0,    88,    97,
      98,    99,    96,    89,    90,    86,   146,   119,   168,   120,
     121,   122,   117,     0,     0,     0,     0,     0,     0,     0,
     173,     0,     0,   139,     0,   128,     0,     0,     0,     0,
       0,   174,     0,     0,     0,     0,     0,     0,     0,     0,
     124,   125,   126,   127,   129,   130,   131,     0,   123
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,   227,    15,    16,    27,    67,    32,    49,
      52,    86,    87,   162,   228,   229,   230,   231,   165,   118,
     119,   120,   326,   121,   168,   163,   235,   155,   156,   157,
     158,   105,   195
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -160
static const yytype_int16 yypact[] =
{
       7,   302,   351,   114,   443,    63,    57,    83,     4,  -160,
      57,   241,   166,   474,   488,  -160,   130,   166,   166,   504,
    -160,   557,  -160,  -160,     5,   189,    23,   458,   189,   616,
     518,   571,  -160,   133,   201,   148,   121,   661,  -160,   176,
     712,   712,   702,   194,   339,   194,   370,   381,    26,   633,
     381,   697,   155,  -160,  -160,  -160,  -160,  -160,  -160,  -160,
     218,  -160,  -160,   473,   503,  -160,  -160,  -160,  -160,  -160,
    -160,   257,   267,    35,   166,   244,   244,   349,   166,   296,
     166,   398,   548,   736,   768,   575,   728,   762,  -160,   712,
    -160,  -160,  -160,  -160,  -160,  -160,  -160,  -160,   712,   712,
     712,   719,   759,  -160,   212,  -160,  -160,  -160,  -160,   760,
     284,   580,   454,    13,   301,   437,   769,   467,  -160,    24,
    -160,  -160,    31,   199,   215,   182,   232,   484,   524,    25,
    -160,  -160,   102,   203,  -160,  -160,  -160,  -160,  -160,  -160,
     244,   306,   244,   244,   244,   383,    12,   597,   336,  -160,
     336,  -160,   336,   336,   656,   635,   671,   732,  -160,   629,
     407,   336,   328,  -160,   110,  -160,   313,   731,  -160,    95,
     235,    97,   375,    88,   597,   602,  -160,   336,   497,   699,
    -160,   651,  -160,   358,   611,   315,  -160,   336,   115,  -160,
    -160,   428,  -160,  -160,   361,    79,  -160,  -160,  -160,  -160,
    -160,   336,   336,   514,  -160,  -160,  -160,  -160,   359,   151,
     151,   336,   336,   336,   336,   336,   336,   336,   336,   336,
     336,   336,   336,   336,   336,   683,   773,   620,   128,  -160,
    -160,  -160,   316,   181,   142,   206,  -160,   105,   410,   112,
     151,   336,   151,   191,   336,   336,   336,   527,   151,   151,
     225,  -160,   544,  -160,  -160,  -160,  -160,   452,   535,   558,
     262,   426,   435,   433,   466,   246,  -160,   552,  -160,   550,
     732,   732,   732,   550,   550,   550,   550,   550,  -160,  -160,
    -160,  -160,  -160,   744,   581,   519,  -160,   590,   371,   744,
     745,  -160,  -160,   639,  -160,   336,  -160,  -160,  -160,   612,
    -160,   552,   255,   552,   334,    14,   596,   603,   625,   659,
     245,  -160,  -160,   364,  -160,  -160,  -160,  -160,  -160,  -160,
    -160,   647,   690,   336,    93,   264,  -160,   519,  -160,  -160,
    -160,  -160,  -160,  -160,   519,  -160,  -160,  -160,  -160,  -160,
    -160,  -160,  -160,   336,   151,   336,   336,   336,   650,   696,
    -160,   682,   394,  -160,   687,  -160,   692,   693,   717,   718,
     164,  -160,   151,   151,   151,   151,   151,   151,   151,   274,
    -160,  -160,  -160,  -160,  -160,  -160,  -160,   424,  -160
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -160,  -160,  -160,    21,   599,   475,   763,   -30,   595,   747,
    -160,  -160,  -160,   549,   136,   304,  -160,   553,   193,   -51,
     695,   -35,   457,  -160,   -82,  -160,  -159,  -111,   525,   323,
    -143,   -57,  -160
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -168
static const yytype_int16 yytable[] =
{
     122,    88,   237,   122,   169,    18,   173,   206,     1,   207,
      37,    68,    70,  -141,   159,   341,  -141,   -81,  -138,   106,
     108,   -81,   201,  -144,    41,   174,   188,    76,   175,   175,
     154,    37,   177,    24,    77,    42,   100,   205,    33,    34,
      36,   178,   208,   265,   325,   154,    19,   101,    38,   236,
     236,    48,    48,     2,   202,   160,   161,   161,    13,   134,
    -141,  -141,  -138,    14,   -16,   122,   254,   256,   135,   136,
     137,   139,   176,   189,   -16,   -16,   236,   278,   279,   280,
     281,   282,   302,   193,   262,   196,   197,   198,   200,   249,
     264,   236,   122,   122,  -142,   102,   242,  -142,   246,   109,
     111,   109,   111,    13,   -16,    12,   122,   247,    14,   -16,
     295,    30,   204,   299,     9,  -104,   203,    31,   128,  -104,
     250,   154,    56,   243,   263,    17,    37,   122,   122,   289,
     236,    30,   290,   306,   307,   308,   310,    31,    37,   251,
     253,  -142,   115,   293,   116,  -104,   290,   -45,   -45,   -16,
     297,   117,   203,   251,   128,  -110,    82,   -45,   122,    85,
     122,   122,    85,  -104,    57,   368,   122,   122,   122,    23,
     154,   291,    83,    84,   267,   268,    53,   -45,   115,    60,
     116,  -110,   -13,   159,   336,   294,   -13,   117,   300,   -13,
     -81,    55,   304,    39,   128,  -110,   369,    71,    85,  -110,
     159,    40,    85,   -74,   191,   301,    37,   303,   305,    14,
     -16,   295,   351,   311,   312,   314,   181,   122,   115,   -81,
     116,  -110,   154,   241,   179,   161,   313,   117,   128,  -110,
      89,   154,   354,   184,   356,   357,   358,   360,    85,  -110,
     -81,   179,    21,   122,    54,   244,   347,    14,   -16,   296,
     -16,   295,   115,   103,   116,  -110,   141,   179,   -16,   -16,
     295,   117,   122,   318,   104,   352,   245,   128,  -110,    98,
     154,   319,    85,  -110,   179,   377,   348,   128,  -110,    99,
     122,   122,   122,   122,   122,   122,   122,   122,   -16,   324,
     353,   115,   143,   116,  -110,   154,   234,   110,   338,    23,
     117,   115,    13,   116,  -110,     5,     6,    14,   -16,   355,
     117,    85,  -110,   -47,   -47,   234,   259,   194,   -63,   -63,
     283,    85,  -110,   260,   284,   190,   192,   370,   371,   372,
     373,   374,   375,   376,   378,   112,   238,   146,  -110,   167,
      72,   240,    73,   -47,   148,   149,   -18,   149,   -16,   150,
     107,   150,     7,   151,     8,   151,   -18,   -18,   103,   292,
     152,   115,   152,   116,   325,   112,   257,   146,  -110,   104,
     117,    72,   331,    73,   148,   149,   153,   -17,   153,   150,
     332,    85,  -110,   151,   199,    74,   -18,   -17,   -17,    75,
     152,   115,   103,   116,  -137,   112,   261,   146,  -110,   110,
     117,    23,   266,   104,   148,   149,   153,   248,   232,   150,
     233,    85,  -110,   151,   226,   -46,   -46,   -17,   149,   298,
     152,   115,   150,   116,  -140,   112,   151,   146,  -110,    25,
     117,    26,   -67,   152,   148,   149,   153,   320,   166,   150,
     167,    85,  -110,   151,    10,   -46,   321,    11,   149,   153,
     152,   115,   150,   116,  -132,   112,   151,   146,   147,    43,
     117,   315,    44,   152,   148,   149,   153,   322,   172,   150,
     167,    85,  -110,   151,    90,    25,    91,    26,   149,   153,
     152,   115,   150,   116,    92,   112,   151,   146,   147,    28,
     117,    26,    93,   152,   148,   149,   153,   323,   255,   150,
     167,    85,  -110,   151,    94,    35,    95,    23,   149,   153,
     152,   115,   150,   116,    96,   112,   151,   146,  -110,    47,
     117,    23,    97,   152,   148,   149,   153,   284,   309,   150,
     167,    85,   186,   151,  -144,   270,   271,   272,   149,   153,
     152,   115,   150,   116,   316,   112,   151,   146,  -109,   112,
     117,   113,   114,   152,   148,   149,   153,    -4,    25,   150,
      26,    85,  -110,   151,   212,   213,   187,   317,   161,   153,
     152,   115,    50,   116,    23,   115,   127,   116,   128,  -110,
     117,   144,   325,   214,   117,    37,   153,   328,   145,   164,
     329,    85,  -109,   333,   335,    85,  -110,   333,   203,   330,
     128,  -110,   115,   252,   116,   128,  -110,   164,   164,    20,
      22,   117,   225,   112,    23,   128,  -110,    45,   226,   258,
      46,   287,    85,  -110,   115,    37,   116,   343,   288,   115,
     225,   116,    23,   117,    78,   344,   226,    79,   117,   115,
     327,   116,    23,   -84,    85,  -110,   226,   -84,   117,    85,
    -110,   359,   225,   167,    23,   -73,   345,   177,   226,    85,
    -110,   149,    58,   209,    59,   150,   178,   210,  -167,   151,
    -167,  -167,   180,   182,   183,   185,   152,  -167,  -167,  -167,
    -167,  -167,   349,   211,  -167,   212,   213,   283,  -167,  -167,
     346,   284,   153,  -167,  -167,  -167,  -167,  -167,    80,   350,
     232,    81,    23,    69,   214,    61,   226,   361,   215,   216,
     217,   218,   219,    62,   362,    61,    63,    64,    65,   363,
     138,    66,    61,    62,   364,   365,    63,    64,    65,   130,
      62,    66,   131,    63,    64,    65,   269,   123,    66,   124,
     273,   274,   275,   276,   277,   327,   334,    23,    23,   366,
     367,   226,   226,   220,   221,   222,   223,   224,   337,   239,
     339,   340,   342,   132,    37,    37,   133,   140,   142,   125,
     170,   126,   171,   241,   285,   161,    23,    29,    51,   286,
     129
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-160)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_uint16 yycheck[] =
{
      82,    52,   161,    85,   115,     1,   117,   150,     1,   152,
       5,    41,    42,     1,     1,     1,     4,     4,     4,    76,
      77,     8,    10,    10,     1,     1,     1,     1,     4,     4,
     112,     5,     1,    12,     8,    12,     1,   148,    17,    18,
      19,    10,   153,   202,    30,   127,    42,    12,    43,   160,
     161,    30,    31,    46,    42,    42,    44,    44,     1,    89,
      48,    48,    48,     6,     7,   147,   177,   178,    98,    99,
     100,   101,    48,    48,    17,    18,   187,   220,   221,   222,
     223,   224,   241,   140,     5,   142,   143,   144,   145,     1,
     201,   202,   174,   175,     1,    74,     1,     4,     1,    78,
      79,    80,    81,     1,    47,    42,   188,    10,     6,     7,
       5,     1,   147,     1,     0,     0,     1,     7,     3,     4,
      32,   203,     1,    28,    45,    42,     5,   209,   210,     1,
     241,     1,     4,   244,   245,   246,   247,     7,     5,   174,
     175,    48,    27,     1,    29,    30,     4,    17,    18,    47,
      45,    36,     1,   188,     3,     4,     1,    47,   240,    47,
     242,   243,    47,    48,    43,     1,   248,   249,   250,     3,
     252,    43,    17,    18,   209,   210,    43,    47,    27,     3,
      29,    30,     1,     1,   295,    43,     5,    36,   239,     8,
       8,    43,     1,     4,     3,     4,    32,     3,    47,    48,
       1,    12,    47,     4,     1,   240,     5,   242,   243,     6,
       7,     5,   323,   248,   249,   250,     1,   299,    27,     4,
      29,    30,   304,    42,    42,    44,     1,    36,     3,     4,
      12,   313,   343,     1,   345,   346,   347,   348,    47,    48,
       8,    42,     1,   325,    43,    10,     1,     6,     7,    43,
      47,     5,    27,     9,    29,    30,    44,    42,    17,    18,
       5,    36,   344,     1,    20,     1,    31,     3,     4,    12,
     352,     9,    47,    48,    42,     1,    31,     3,     4,    12,
     362,   363,   364,   365,   366,   367,   368,   369,    47,    43,
     325,    27,     8,    29,    30,   377,   160,     1,    43,     3,
      36,    27,     1,    29,    30,     3,     4,     6,     7,   344,
      36,    47,    48,    17,    18,   179,     1,    11,    17,    18,
       4,    47,    48,     8,     8,   132,   133,   362,   363,   364,
     365,   366,   367,   368,   369,     1,     8,     3,     4,     3,
       1,    28,     3,    47,    10,    11,     7,    11,    47,    15,
       1,    15,     1,    19,     3,    19,    17,    18,     9,    43,
      26,    27,    26,    29,    30,     1,     8,     3,     4,    20,
      36,     1,     1,     3,    10,    11,    42,     7,    42,    15,
       9,    47,    48,    19,     1,     4,    47,    17,    18,     8,
      26,    27,     9,    29,    30,     1,    35,     3,     4,     1,
      36,     3,    43,    20,    10,    11,    42,    32,     1,    15,
       3,    47,    48,    19,     7,    17,    18,    47,    11,     9,
      26,    27,    15,    29,    30,     1,    19,     3,     4,     1,
      36,     3,     4,    26,    10,    11,    42,    11,     1,    15,
       3,    47,    48,    19,     1,    47,    11,     4,    11,    42,
      26,    27,    15,    29,    30,     1,    19,     3,     4,     1,
      36,     9,     4,    26,    10,    11,    42,    34,     1,    15,
       3,    47,    48,    19,     1,     1,     3,     3,    11,    42,
      26,    27,    15,    29,    11,     1,    19,     3,     4,     1,
      36,     3,    19,    26,    10,    11,    42,    31,     1,    15,
       3,    47,    48,    19,     1,     1,     3,     3,    11,    42,
      26,    27,    15,    29,    11,     1,    19,     3,     4,     1,
      36,     3,    19,    26,    10,    11,    42,     8,     1,    15,
       3,    47,    48,    19,    10,   212,   213,   214,    11,    42,
      26,    27,    15,    29,     9,     1,    19,     3,     4,     1,
      36,     3,     4,    26,    10,    11,    42,     0,     1,    15,
       3,    47,    48,    19,    14,    15,    42,     9,    44,    42,
      26,    27,     1,    29,     3,    27,     1,    29,     3,     4,
      36,     1,    30,    33,    36,     5,    42,   283,     8,   114,
       9,    47,    48,   289,   290,    47,    48,   293,     1,     9,
       3,     4,    27,     1,    29,     3,     4,   132,   133,    10,
      11,    36,     1,     1,     3,     3,     4,     1,     7,     8,
       4,     1,    47,    48,    27,     5,    29,    31,     8,    27,
       1,    29,     3,    36,     1,    32,     7,     4,    36,    27,
       1,    29,     3,     4,    47,    48,     7,     8,    36,    47,
      48,     1,     1,     3,     3,     4,    31,     1,     7,    47,
      48,    11,     1,    28,     3,    15,    10,    32,    12,    19,
      14,    15,   123,   124,   125,   126,    26,    21,    22,    23,
      24,    25,    35,    12,    28,    14,    15,     4,    32,    33,
      31,     8,    42,    37,    38,    39,    40,    41,     1,     9,
       1,     4,     3,     1,    33,     3,     7,    11,    37,    38,
      39,    40,    41,    11,    32,     3,    14,    15,    16,    32,
       1,    19,     3,    11,    32,    32,    14,    15,    16,     1,
      11,    19,     4,    14,    15,    16,   211,     1,    19,     3,
     215,   216,   217,   218,   219,     1,     1,     3,     3,    32,
      32,     7,     7,    21,    22,    23,    24,    25,   301,   164,
     303,   304,   305,     1,     5,     5,     4,     8,     8,     1,
       1,     3,     3,    42,     1,    44,     3,    14,    31,   226,
      85
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    46,    50,    51,     3,     4,     1,     3,     0,
       1,     4,    42,     1,     6,    53,    54,    42,     1,    42,
      53,     1,    53,     3,    52,     1,     3,    55,     1,    55,
       1,     7,    57,    52,    52,     1,    52,     5,    43,     4,
      12,     1,    12,     1,     4,     1,     4,     1,    52,    58,
       1,    58,    59,    43,    43,    43,     1,    43,     1,     3,
       3,     3,    11,    14,    15,    16,    19,    56,    56,     1,
      56,     3,     1,     3,     4,     8,     1,     8,     1,     4,
       1,     4,     1,    17,    18,    47,    60,    61,    68,    12,
       1,     3,    11,    19,     1,     3,    11,    19,    12,    12,
       1,    12,    52,     9,    20,    80,    80,     1,    80,    52,
       1,    52,     1,     3,     4,    27,    29,    36,    68,    69,
      70,    72,    73,     1,     3,     1,     3,     1,     3,    69,
       1,     4,     1,     4,    56,    56,    56,    56,     1,    56,
       8,    44,     8,     8,     1,     8,     3,     4,    10,    11,
      15,    19,    26,    42,    73,    76,    77,    78,    79,     1,
      42,    44,    62,    74,    54,    67,     1,     3,    73,    76,
       1,     3,     1,    76,     1,     4,    48,     1,    10,    42,
      62,     1,    62,    62,     1,    62,    48,    42,     1,    48,
      67,     1,    67,    80,    11,    81,    80,    80,    80,     1,
      80,    10,    42,     1,    70,    76,    79,    79,    76,    28,
      32,    12,    14,    15,    33,    37,    38,    39,    40,    41,
      21,    22,    23,    24,    25,     1,     7,    52,    63,    64,
      65,    66,     1,     3,    63,    75,    76,    75,     8,    57,
      28,    42,     1,    28,    10,    31,     1,    10,    32,     1,
      32,    70,     1,    70,    76,     1,    76,     8,     8,     1,
       8,    35,     5,    45,    76,    75,    43,    70,    70,    77,
      78,    78,    78,    77,    77,    77,    77,    77,    79,    79,
      79,    79,    79,     4,     8,     1,    66,     1,     8,     1,
       4,    43,    43,     1,    43,     5,    43,    45,     9,     1,
      68,    70,    75,    70,     1,    70,    76,    76,    76,     1,
      76,    70,    70,     1,    70,     9,     9,     9,     1,     9,
      11,    11,    34,    31,    43,    30,    71,     1,    64,     9,
       9,     1,     9,    64,     1,    64,    76,    71,    43,    71,
      71,     1,    71,    31,    32,    31,    31,     1,    31,    35,
       9,    76,     1,    70,    76,    70,    76,    76,    76,     1,
      76,    11,    32,    32,    32,    32,    32,    32,     1,    32,
      70,    70,    70,    70,    70,    70,    70,     1,    70
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
#line 44 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("programstruct"),std::string(""),std::vector<int>{(yyvsp[(1) - (3)].ival),(yyvsp[(2) - (3)].ival),(yyvsp[(3) - (3)].ival)}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[(yyvsp[(1) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (3)].ival)].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
					}
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 55 "parser.y"
    {
					lParseError("缺少program head 或 程序头部有错误",(yylsp[(2) - (3)]));
					}
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 58 "parser.y"
    {
					lParseError("缺少program body 或 程序主体有错误",(yylsp[(2) - (3)]));
					}
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 61 "parser.y"
    {
					lParseError("程序头部后分号缺失",(yylsp[(1) - (3)]));
					}
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 68 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("program_head"),std::string(""),std::vector<int>{(yyvsp[(2) - (5)].ival),(yyvsp[(3) - (5)].ival),(yyvsp[(4) - (5)].ival),(yyvsp[(5) - (5)].ival)}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[(yyvsp[(2) - (5)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (5)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(4) - (5)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(5) - (5)].ival)].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
				   }
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 80 "parser.y"
    {
					lParseError("id前缺少左括号",(yylsp[(4) - (5)]));
					}
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 83 "parser.y"
    {
					lParseError("id后缺少右括号",(yylsp[(4) - (5)]));
					}
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 86 "parser.y"
    {
					lParseError("缺少‘program’字段",(yylsp[(2) - (5)]));
					}
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 89 "parser.y"
    {
					lParseError("左括号前缺少主程序名称",(yylsp[(3) - (5)]));
					}
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 92 "parser.y"
    {
					lParseError("缺少输入参数",(yylsp[(3) - (5)]));
					}
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 96 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("idlist"),std::string(""),std::vector<int>{(yyvsp[(1) - (3)].ival),(yyvsp[(2) - (3)].ival),(yyvsp[(3) - (3)].ival)}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[(yyvsp[(1) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (3)].ival)].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
				   }
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 107 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("idlist"),std::string(""),std::vector<int>{(yyvsp[(1) - (1)].ival)}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[(yyvsp[(1) - (1)].ival)].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 116 "parser.y"
    {
					lParseError("传入空值",(yylsp[(2) - (3)]));
					}
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 120 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("program_body"),std::string(""),std::vector<int>{(yyvsp[(1) - (4)].ival),(yyvsp[(2) - (4)].ival),(yyvsp[(3) - (4)].ival),(yyvsp[(4) - (4)].ival)}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[(yyvsp[(1) - (4)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (4)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (4)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(4) - (4)].ival)].setParent(parseTree.size() - 1);
}
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 132 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("const_declarations"),std::string(""),std::vector<int>{}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 140 "parser.y"
    {				   
				   parseTree.push_back(ParseTreeNode(std::string("const_declarations"),std::string(""),std::vector<int>{(yyvsp[(1) - (3)].ival),(yyvsp[(2) - (3)].ival)}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[(yyvsp[(1) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (3)].ival)].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
				   }
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 151 "parser.y"
    {
					lParseError("在常量声明前缺少‘const’字段",(yylsp[(2) - (3)]));
					}
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 154 "parser.y"
    {
					lParseError("常量声明结束缺少分号",(yylsp[(2) - (3)]));
					}
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 157 "parser.y"
    {
					lParseError("在const之后缺少常量声明或出现错误",(yylsp[(1) - (2)]));
					}
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 161 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("const_declaration"),std::string(""),std::vector<int>{(yyvsp[(1) - (5)].ival),(yyvsp[(2) - (5)].ival),(yyvsp[(3) - (5)].ival),(yyvsp[(4) - (5)].ival),(yyvsp[(5) - (5)].ival)}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[(yyvsp[(1) - (5)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (5)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (5)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(4) - (5)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(5) - (5)].ival)].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 174 "parser.y"
    {
					lParseError("常量声明缺少分号",(yylsp[(1) - (5)]));
					}
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 177 "parser.y"
    {
					lParseError("常量声明id缺失",(yylsp[(4) - (5)]));
					}
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 180 "parser.y"
    {
					lParseError("常量声明缺失变量值",(yylsp[(4) - (5)]));
					}
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 183 "parser.y"
    {
					lParseError("常量声明等于号缺失",(yylsp[(3) - (5)]));
					}
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 186 "parser.y"
    {
					lParseError("分号多余或常量声明缺失",(yylsp[(2) - (5)]));
					}
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 189 "parser.y"
    {
					lParseError("分号多余，const结构缺失",(yylsp[(2) - (2)]));
					}
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 192 "parser.y"
    {
					lParseError("分号多余或常量声明缺失",(yylsp[(2) - (3)]));
					}
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 195 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("const_declaration"),std::string(""),std::vector<int>{(yyvsp[(1) - (3)].ival),(yyvsp[(2) - (3)].ival),(yyvsp[(3) - (3)].ival)}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[(yyvsp[(1) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (3)].ival)].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;	
}
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 206 "parser.y"
    {
					lParseError("常量声明缺失ID",(yylsp[(2) - (3)]));
					}
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 209 "parser.y"
    {
					lParseError("常量声明缺失数值",(yylsp[(2) - (3)]));
					}
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 212 "parser.y"
    {
					lParseError("常量声明缺失等号",(yylsp[(1) - (3)]));
					}
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 216 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("const_value"),std::string(""),std::vector<int>{(yyvsp[(1) - (2)].ival),(yyvsp[(2) - (2)].ival)}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[(yyvsp[(1) - (2)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (2)].ival)].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;	
}
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 226 "parser.y"
    {
					lParseError("缺失ID或整数或小数",(yylsp[(1) - (2)]));
					}
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 229 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("const_value"),std::string(""),std::vector<int>{(yyvsp[(1) - (2)].ival),(yyvsp[(2) - (2)].ival)}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[(yyvsp[(1) - (2)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (2)].ival)].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;		
}
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 239 "parser.y"
    {
					lParseError("缺失ID或整数或小数",(yylsp[(1) - (2)]));
					}
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 242 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("const_value"),std::string(""),std::vector<int>{(yyvsp[(1) - (1)].ival)}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[(yyvsp[(1) - (1)].ival)].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;	
}
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 251 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("const_value"),std::string(""),std::vector<int>{(yyvsp[(1) - (2)].ival),(yyvsp[(2) - (2)].ival)}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[(yyvsp[(1) - (2)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (2)].ival)].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;		
}
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 261 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("const_value"),std::string(""),std::vector<int>{(yyvsp[(1) - (2)].ival),(yyvsp[(2) - (2)].ival)}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[(yyvsp[(1) - (2)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (2)].ival)].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;	
}
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 271 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("const_value"),std::string(""),std::vector<int>{(yyvsp[(1) - (1)].ival)}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[(yyvsp[(1) - (1)].ival)].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;	
}
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 280 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("const_value"),std::string(""),std::vector<int>{(yyvsp[(1) - (2)].ival)}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[(yyvsp[(1) - (2)].ival)].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 289 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("const_value"),std::string(""),std::vector<int>{(yyvsp[(1) - (2)].ival)}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[(yyvsp[(1) - (2)].ival)].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 298 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("const_value"),std::string(""),std::vector<int>{(yyvsp[(1) - (1)].ival)}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[(yyvsp[(1) - (1)].ival)].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 307 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("const_value"),std::string(""),std::vector<int>{(yyvsp[(1) - (1)].ival)}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[(yyvsp[(1) - (1)].ival)].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;	
}
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 317 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("var_declarations"),std::string(""),std::vector<int>{}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 325 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("var_declarations"),std::string(""),std::vector<int>{(yyvsp[(1) - (3)].ival),(yyvsp[(2) - (3)].ival),(yyvsp[(3) - (3)].ival)}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[(yyvsp[(1) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (3)].ival)].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;	
}
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 337 "parser.y"
    {
					lParseError("在变量声明前缺少‘var’字段",(yylsp[(2) - (3)]));
					}
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 340 "parser.y"
    {
					lParseError("Error in Variable declaration",(yylsp[(2) - (3)]));
					}
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 343 "parser.y"
    {
					lParseError("在var之后缺少变量声明或者出现错误",(yylsp[(1) - (2)]));
					}
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 347 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("var_declaration"),std::string(""),std::vector<int>{(yyvsp[(1) - (3)].ival),(yyvsp[(2) - (3)].ival),(yyvsp[(3) - (3)].ival)}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[(yyvsp[(1) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (3)].ival)].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 358 "parser.y"
    {
					lParseError("在冒号之前缺少ID",(yylsp[(2) - (3)]));

					}
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 362 "parser.y"
    {
					lParseError("在ID之后缺少冒号",(yylsp[(1) - (3)]));
					}
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 365 "parser.y"
    {
					lParseError("在冒号之后缺少变量类型",(yylsp[(2) - (3)]));
					}
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 368 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("var_declaration"),std::string(""),std::vector<int>{(yyvsp[(1) - (5)].ival),(yyvsp[(2) - (5)].ival),(yyvsp[(3) - (5)].ival),(yyvsp[(4) - (5)].ival),(yyvsp[(5) - (5)].ival)}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[(yyvsp[(1) - (5)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (5)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (5)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(4) - (5)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(5) - (5)].ival)].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 381 "parser.y"
    {
					lParseError("在变量定义之后缺失分号",(yylsp[(1) - (5)]));
					}
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 384 "parser.y"
    {
					lParseError("分号后缺少ID",(yylsp[(2) - (5)]));
					}
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 387 "parser.y"
    {
					lParseError("变量定义后缺少冒号",(yylsp[(3) - (5)]));
					}
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 390 "parser.y"
    {
					lParseError("变量定义后缺少类型声明",(yylsp[(4) - (5)]));
					}
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 393 "parser.y"
    {
					lParseError("分号冗余或缺少变量声明",(yylsp[(2) - (5)]));
					}
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 396 "parser.y"
    {
					lParseError("分号冗余或缺少变量声明",(yylsp[(2) - (3)]));
					}
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 401 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("subprogram_declarations"),std::string(""),std::vector<int>{}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;	
}
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 409 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("subprogram_declarations"),std::string(""),std::vector<int>{(yyvsp[(1) - (3)].ival),(yyvsp[(2) - (3)].ival),(yyvsp[(3) - (3)].ival)}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[(yyvsp[(1) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (3)].ival)].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 420 "parser.y"
    {
					lParseError("分号冗余或缺少子程序",(yylsp[(2) - (3)]));
					}
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 423 "parser.y"
    {
					lParseError("子程序结束缺少分号",(yylsp[(2) - (3)]));
					}
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 427 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("subprogram"),std::string(""),std::vector<int>{(yyvsp[(1) - (3)].ival),(yyvsp[(2) - (3)].ival),(yyvsp[(3) - (3)].ival)}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[(yyvsp[(1) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (3)].ival)].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;		
}
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 438 "parser.y"
    {
					lParseError("缺少子函数头部 或 子函数头部有错误",(yylsp[(2) - (3)]));
					}
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 441 "parser.y"
    {
					lParseError("缺少子函数主体 或 子函数主体有错误",(yylsp[(2) - (3)]));
					}
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 444 "parser.y"
    {
					lParseError("子函数头部后分号缺失",(yylsp[(1) - (3)]));
					}
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 448 "parser.y"
    {
					parseTree.push_back(ParseTreeNode(std::string("subprogram_head"),std::string(""),std::vector<int>{(yyvsp[(2) - (3)].ival),(yyvsp[(3) - (3)].ival)}));
					//记录指向本节点的指针
					(yyval.ival) = parseTree.size() - 1;
					//为子节点设置父节点指针
					parseTree[(yyvsp[(2) - (3)].ival)].setParent(parseTree.size() - 1);
					parseTree[(yyvsp[(3) - (3)].ival)].setParent(parseTree.size() - 1);
					//设置根节点，仅最上层规则需要 
					parseTreeRoot = parseTree.size() - 1;	
}
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 458 "parser.y"
    {
					parseTree.push_back(ParseTreeNode(std::string("subprogram_head"),std::string(""),std::vector<int>{(yyvsp[(1) - (5)].ival),(yyvsp[(2) - (5)].ival),(yyvsp[(3) - (5)].ival),(yyvsp[(4) - (5)].ival),(yyvsp[(5) - (5)].ival)}));
					//记录指向本节点的指针
					(yyval.ival) = parseTree.size() - 1;
					//为子节点设置父节点指针
				   parseTree[(yyvsp[(1) - (5)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (5)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (5)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(4) - (5)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(5) - (5)].ival)].setParent(parseTree.size() - 1);
}
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 469 "parser.y"
    {
					lParseError("缺失‘procedure’字段",(yylsp[(2) - (3)]));
					}
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 472 "parser.y"
    {
					lParseError("子过程缺失ID",(yylsp[(3) - (3)]));
					}
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 475 "parser.y"
    {
					lParseError("子过程传入参数错误",(yylsp[(2) - (3)]));
					}
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 478 "parser.y"
    {
					lParseError("子过程有错误",(yylsp[(1) - (2)]));
					}
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 481 "parser.y"
    {
					lParseError("缺失‘function’字段",(yylsp[(2) - (5)]));
					}
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 484 "parser.y"
    {
					lParseError("子函数缺失ID",(yylsp[(3) - (5)]));
					}
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 487 "parser.y"
    {
					lParseError("子函数传入参数错误",(yylsp[(2) - (5)]));
					}
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 490 "parser.y"
    {
					lParseError("子函数声明缺失冒号",(yylsp[(3) - (5)]));
					}
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 493 "parser.y"
    {
					lParseError("子函数声明缺失类型",(yylsp[(4) - (5)]));
					}
    break;

  case 80:
/* Line 1792 of yacc.c  */
#line 496 "parser.y"
    {
					lParseError("子函数声明缺失返回值类型",(yylsp[(3) - (4)]));
					}
    break;

  case 81:
/* Line 1792 of yacc.c  */
#line 500 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("formal_parameter"),std::string(""),std::vector<int>{}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 82:
/* Line 1792 of yacc.c  */
#line 508 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("formal_parameter"),std::string(""),std::vector<int>{(yyvsp[(1) - (3)].ival),(yyvsp[(2) - (3)].ival),(yyvsp[(3) - (3)].ival)}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[(yyvsp[(1) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (3)].ival)].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 83:
/* Line 1792 of yacc.c  */
#line 519 "parser.y"
    {
					lParseError("参数传入缺失左括号",(yylsp[(2) - (3)]));
					}
    break;

  case 84:
/* Line 1792 of yacc.c  */
#line 522 "parser.y"
    {
					lParseError("参数传入缺失右括号",(yylsp[(2) - (3)]));
					}
    break;

  case 85:
/* Line 1792 of yacc.c  */
#line 525 "parser.y"
    {
					lParseError("传入参数缺失或语法错误",(yylsp[(1) - (3)]));
					}
    break;

  case 86:
/* Line 1792 of yacc.c  */
#line 529 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("parameter_list"),std::string(""),std::vector<int>{(yyvsp[(1) - (3)].ival),(yyvsp[(2) - (3)].ival),(yyvsp[(3) - (3)].ival)}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[(yyvsp[(1) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (3)].ival)].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 87:
/* Line 1792 of yacc.c  */
#line 540 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("parameter_list"),std::string(""),std::vector<int>{(yyvsp[(1) - (1)].ival)}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[(yyvsp[(1) - (1)].ival)].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 88:
/* Line 1792 of yacc.c  */
#line 549 "parser.y"
    {
					lParseError("分号前传入参数语法错误",(yylsp[(2) - (3)]));
					}
    break;

  case 89:
/* Line 1792 of yacc.c  */
#line 552 "parser.y"
    {
					lParseError("传入参数缺失分号",(yylsp[(1) - (3)]));
					}
    break;

  case 90:
/* Line 1792 of yacc.c  */
#line 555 "parser.y"
    {
					lParseError("分号后传入参数语法错误",(yylsp[(2) - (3)]));
					}
    break;

  case 91:
/* Line 1792 of yacc.c  */
#line 558 "parser.y"
    {
					lParseError("传入参数语法错误",(yyloc));
					}
    break;

  case 92:
/* Line 1792 of yacc.c  */
#line 562 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("parameter"),std::string(""),std::vector<int>{(yyvsp[(1) - (1)].ival)}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[(yyvsp[(1) - (1)].ival)].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 93:
/* Line 1792 of yacc.c  */
#line 571 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("parameter"),std::string(""),std::vector<int>{(yyvsp[(1) - (1)].ival)}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[(yyvsp[(1) - (1)].ival)].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 94:
/* Line 1792 of yacc.c  */
#line 580 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("var_parameter"),std::string(""),std::vector<int>{(yyvsp[(1) - (2)].ival),(yyvsp[(2) - (2)].ival)}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[(yyvsp[(1) - (2)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (2)].ival)].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;	
}
    break;

  case 95:
/* Line 1792 of yacc.c  */
#line 590 "parser.y"
    {
					lParseError("引用调用语法错误",(yylsp[(1) - (2)]));
					}
    break;

  case 96:
/* Line 1792 of yacc.c  */
#line 595 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("value_parameter"),std::string(""),std::vector<int>{(yyvsp[(1) - (3)].ival),(yyvsp[(2) - (3)].ival),(yyvsp[(3) - (3)].ival)}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[(yyvsp[(1) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (3)].ival)].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 97:
/* Line 1792 of yacc.c  */
#line 606 "parser.y"
    {
					lParseError("参数传入缺失ID",(yylsp[(2) - (3)]));
					}
    break;

  case 98:
/* Line 1792 of yacc.c  */
#line 609 "parser.y"
    {
					lParseError("参数传入缺失冒号",(yylsp[(1) - (3)]));
					}
    break;

  case 99:
/* Line 1792 of yacc.c  */
#line 612 "parser.y"
    {
					lParseError("参数传入缺失变量类型",(yylsp[(2) - (3)]));
					}
    break;

  case 100:
/* Line 1792 of yacc.c  */
#line 616 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("subprogram_body"),std::string(""),std::vector<int>{(yyvsp[(1) - (3)].ival),(yyvsp[(2) - (3)].ival),(yyvsp[(3) - (3)].ival)}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[(yyvsp[(1) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (3)].ival)].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 101:
/* Line 1792 of yacc.c  */
#line 628 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("compound_statement"),std::string(""),std::vector<int>{(yyvsp[(2) - (3)].ival)}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[(yyvsp[(2) - (3)].ival)].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 102:
/* Line 1792 of yacc.c  */
#line 637 "parser.y"
    {
					lParseError("缺失begin",(yylsp[(2) - (3)]));
					}
    break;

  case 103:
/* Line 1792 of yacc.c  */
#line 640 "parser.y"
    {
					lParseError("缺失函数体或函数体存在语法错误",(yyloc));
					}
    break;

  case 104:
/* Line 1792 of yacc.c  */
#line 643 "parser.y"
    {
					lParseError("缺失end",(yylsp[(2) - (3)]));
					}
    break;

  case 105:
/* Line 1792 of yacc.c  */
#line 647 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("statement_list"),std::string(""),std::vector<int>{(yyvsp[(1) - (3)].ival),(yyvsp[(2) - (3)].ival),(yyvsp[(3) - (3)].ival)}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[(yyvsp[(1) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (3)].ival)].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 106:
/* Line 1792 of yacc.c  */
#line 658 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("statement_list"),std::string(""),std::vector<int>{(yyvsp[(1) - (1)].ival)}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[(yyvsp[(1) - (1)].ival)].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 107:
/* Line 1792 of yacc.c  */
#line 667 "parser.y"
    {
					lParseError("语句缺失分号",(yylsp[(1) - (3)]));
					}
    break;

  case 108:
/* Line 1792 of yacc.c  */
#line 670 "parser.y"
    {
					lParseError("分号前语句存在语法错误",(yylsp[(2) - (3)]));
					}
    break;

  case 109:
/* Line 1792 of yacc.c  */
#line 673 "parser.y"
    {
					lParseError("分号后语句存在语法错误",(yylsp[(2) - (3)]));
					}
    break;

  case 110:
/* Line 1792 of yacc.c  */
#line 677 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("statement"),std::string(""),std::vector<int>{}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 111:
/* Line 1792 of yacc.c  */
#line 685 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("statement"),std::string(""),std::vector<int>{(yyvsp[(1) - (3)].ival),(yyvsp[(2) - (3)].ival),(yyvsp[(3) - (3)].ival)}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[(yyvsp[(1) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (3)].ival)].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 112:
/* Line 1792 of yacc.c  */
#line 696 "parser.y"
    {
					lParseError("变量缺失或存在语法错误",(yylsp[(2) - (3)]));
					}
    break;

  case 113:
/* Line 1792 of yacc.c  */
#line 699 "parser.y"
    {
					lParseError("变量后缺失:=",(yylsp[(1) - (3)]));
					}
    break;

  case 114:
/* Line 1792 of yacc.c  */
#line 702 "parser.y"
    {
					lParseError("表达式缺失或存在语法错误",(yylsp[(2) - (3)]));
					}
    break;

  case 115:
/* Line 1792 of yacc.c  */
#line 705 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("statement"),std::string(""),std::vector<int>{(yyvsp[(1) - (1)].ival)}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[(yyvsp[(1) - (1)].ival)].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 116:
/* Line 1792 of yacc.c  */
#line 714 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("statement"),std::string(""),std::vector<int>{(yyvsp[(1) - (1)].ival)}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[(yyvsp[(1) - (1)].ival)].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 117:
/* Line 1792 of yacc.c  */
#line 723 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("statement"),std::string(""),std::vector<int>{(yyvsp[(1) - (5)].ival),(yyvsp[(2) - (5)].ival),(yyvsp[(3) - (5)].ival),(yyvsp[(4) - (5)].ival),(yyvsp[(5) - (5)].ival)}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[(yyvsp[(1) - (5)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (5)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (5)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(4) - (5)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(5) - (5)].ival)].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 118:
/* Line 1792 of yacc.c  */
#line 736 "parser.y"
    {
					lParseError("缺少if",(yylsp[(2) - (5)]));
					}
    break;

  case 119:
/* Line 1792 of yacc.c  */
#line 739 "parser.y"
    {
					lParseError("if后缺少表达式或表达式存在语法错误",(yylsp[(1) - (5)]));
					}
    break;

  case 120:
/* Line 1792 of yacc.c  */
#line 742 "parser.y"
    {
					lParseError("缺少then",(yylsp[(2) - (5)]));
					}
    break;

  case 121:
/* Line 1792 of yacc.c  */
#line 745 "parser.y"
    {
					lParseError("then后缺少表达式或表达式存在语法错误",(yylsp[(3) - (5)]));
					}
    break;

  case 122:
/* Line 1792 of yacc.c  */
#line 748 "parser.y"
    {
					lParseError("else 部分表达式存在语法错误",(yylsp[(4) - (5)]));
					}
    break;

  case 123:
/* Line 1792 of yacc.c  */
#line 751 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("statement"),std::string(""),std::vector<int>{(yyvsp[(1) - (8)].ival),(yyvsp[(2) - (8)].ival),(yyvsp[(3) - (8)].ival),(yyvsp[(4) - (8)].ival),(yyvsp[(5) - (8)].ival),(yyvsp[(6) - (8)].ival),(yyvsp[(7) - (8)].ival),(yyvsp[(8) - (8)].ival)}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[(yyvsp[(1) - (8)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (8)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (8)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(4) - (8)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(5) - (8)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(6) - (8)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(7) - (8)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(8) - (8)].ival)].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 124:
/* Line 1792 of yacc.c  */
#line 767 "parser.y"
    {
					lParseError("缺少for",(yylsp[(2) - (8)]));
					}
    break;

  case 125:
/* Line 1792 of yacc.c  */
#line 770 "parser.y"
    {
					lParseError("缺少ID",(yylsp[(1) - (8)]));
					}
    break;

  case 126:
/* Line 1792 of yacc.c  */
#line 773 "parser.y"
    {
					lParseError("缺少=",(yylsp[(2) - (8)]));
					}
    break;

  case 127:
/* Line 1792 of yacc.c  */
#line 776 "parser.y"
    {
					lParseError("条件缺少表达式",(yylsp[(3) - (8)]));
					}
    break;

  case 128:
/* Line 1792 of yacc.c  */
#line 779 "parser.y"
    {
					lParseError("条件表达式语法错误",(yylsp[(1) - (6)]));
					}
    break;

  case 129:
/* Line 1792 of yacc.c  */
#line 782 "parser.y"
    {
					lParseError("缺少to",(yylsp[(4) - (8)]));
					}
    break;

  case 130:
/* Line 1792 of yacc.c  */
#line 785 "parser.y"
    {
					lParseError("缺少终止条件表达式",(yylsp[(5) - (8)]));
					}
    break;

  case 131:
/* Line 1792 of yacc.c  */
#line 788 "parser.y"
    {
					lParseError("缺少do",(yylsp[(6) - (8)]));
					}
    break;

  case 132:
/* Line 1792 of yacc.c  */
#line 791 "parser.y"
    {
					lParseError("缺少执行语句或执行语句存在语法错误",(yylsp[(7) - (8)]));
					}
    break;

  case 133:
/* Line 1792 of yacc.c  */
#line 794 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("statement"),std::string(""),std::vector<int>{(yyvsp[(1) - (4)].ival),(yyvsp[(2) - (4)].ival),(yyvsp[(3) - (4)].ival),(yyvsp[(4) - (4)].ival)}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[(yyvsp[(1) - (4)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (4)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (4)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(4) - (4)].ival)].setParent(parseTree.size() - 1);
}
    break;

  case 134:
/* Line 1792 of yacc.c  */
#line 804 "parser.y"
    {
					lParseError("缺少while",(yylsp[(2) - (4)]));
					}
    break;

  case 135:
/* Line 1792 of yacc.c  */
#line 807 "parser.y"
    {
					lParseError("while后表达式缺失或存在错误",(yylsp[(1) - (4)]));
					}
    break;

  case 136:
/* Line 1792 of yacc.c  */
#line 810 "parser.y"
    {
					lParseError("缺少do",(yylsp[(2) - (4)]));
					}
    break;

  case 137:
/* Line 1792 of yacc.c  */
#line 813 "parser.y"
    {
					lParseError("do后表达式缺失或存在错误",(yylsp[(3) - (4)]));
					}
    break;

  case 138:
/* Line 1792 of yacc.c  */
#line 817 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("else_part"),std::string(""),std::vector<int>{}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 139:
/* Line 1792 of yacc.c  */
#line 825 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("else_part"),std::string(""),std::vector<int>{(yyvsp[(1) - (2)].ival),(yyvsp[(2) - (2)].ival)}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[(yyvsp[(1) - (2)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (2)].ival)].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 140:
/* Line 1792 of yacc.c  */
#line 835 "parser.y"
    {
					lParseError("else后表达式缺失或存在语法错误",(yylsp[(1) - (2)]));
					}
    break;

  case 141:
/* Line 1792 of yacc.c  */
#line 838 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("procedure_call"),std::string(""),std::vector<int>{(yyvsp[(1) - (1)].ival)}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[(yyvsp[(1) - (1)].ival)].setParent(parseTree.size() - 1);				
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 142:
/* Line 1792 of yacc.c  */
#line 847 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("procedure_call"),std::string(""),std::vector<int>{(yyvsp[(1) - (4)].ival),(yyvsp[(2) - (4)].ival),(yyvsp[(3) - (4)].ival),(yyvsp[(4) - (4)].ival)}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[(yyvsp[(1) - (4)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (4)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (4)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(4) - (4)].ival)].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 143:
/* Line 1792 of yacc.c  */
#line 859 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("variable"),std::string(""),std::vector<int>{(yyvsp[(1) - (2)].ival),(yyvsp[(2) - (2)].ival)}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[(yyvsp[(1) - (2)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (2)].ival)].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 144:
/* Line 1792 of yacc.c  */
#line 869 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("id_varpart"),std::string(""),std::vector<int>{}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
}
    break;

  case 145:
/* Line 1792 of yacc.c  */
#line 875 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("id_varpart"),std::string(""),std::vector<int>{(yyvsp[(1) - (3)].ival),(yyvsp[(2) - (3)].ival),(yyvsp[(3) - (3)].ival)}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[(yyvsp[(1) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (3)].ival)].setParent(parseTree.size() - 1);
}
    break;

  case 146:
/* Line 1792 of yacc.c  */
#line 884 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("expression_list"),std::string(""),std::vector<int>{(yyvsp[(1) - (3)].ival),(yyvsp[(2) - (3)].ival),(yyvsp[(3) - (3)].ival)}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[(yyvsp[(1) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (3)].ival)].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 147:
/* Line 1792 of yacc.c  */
#line 895 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("expression_list"),std::string(""),std::vector<int>{(yyvsp[(1) - (1)].ival)}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[(yyvsp[(1) - (1)].ival)].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 148:
/* Line 1792 of yacc.c  */
#line 904 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("expression"),std::string(""),std::vector<int>{(yyvsp[(1) - (1)].ival)}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[(yyvsp[(1) - (1)].ival)].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 149:
/* Line 1792 of yacc.c  */
#line 913 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("expression"),std::string(""),std::vector<int>{(yyvsp[(1) - (3)].ival),(yyvsp[(2) - (3)].ival),(yyvsp[(3) - (3)].ival)}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[(yyvsp[(1) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (3)].ival)].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;		
}
    break;

  case 150:
/* Line 1792 of yacc.c  */
#line 924 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("expression"),std::string(""),std::vector<int>{(yyvsp[(1) - (3)].ival),(yyvsp[(2) - (3)].ival),(yyvsp[(3) - (3)].ival)}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[(yyvsp[(1) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (3)].ival)].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 151:
/* Line 1792 of yacc.c  */
#line 935 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("expression"),std::string(""),std::vector<int>{(yyvsp[(1) - (3)].ival),(yyvsp[(2) - (3)].ival),(yyvsp[(3) - (3)].ival)}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[(yyvsp[(1) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (3)].ival)].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 152:
/* Line 1792 of yacc.c  */
#line 946 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("expression"),std::string(""),std::vector<int>{(yyvsp[(1) - (3)].ival),(yyvsp[(2) - (3)].ival),(yyvsp[(3) - (3)].ival)}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[(yyvsp[(1) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (3)].ival)].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 153:
/* Line 1792 of yacc.c  */
#line 957 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("expression"),std::string(""),std::vector<int>{(yyvsp[(1) - (3)].ival),(yyvsp[(2) - (3)].ival),(yyvsp[(3) - (3)].ival)}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[(yyvsp[(1) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (3)].ival)].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 154:
/* Line 1792 of yacc.c  */
#line 968 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("expression"),std::string(""),std::vector<int>{(yyvsp[(1) - (3)].ival),(yyvsp[(2) - (3)].ival),(yyvsp[(3) - (3)].ival)}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[(yyvsp[(1) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (3)].ival)].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 155:
/* Line 1792 of yacc.c  */
#line 979 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("simple_expression"),std::string(""),std::vector<int>{(yyvsp[(1) - (3)].ival),(yyvsp[(2) - (3)].ival),(yyvsp[(3) - (3)].ival)}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[(yyvsp[(1) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (3)].ival)].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 156:
/* Line 1792 of yacc.c  */
#line 990 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("simple_expression"),std::string(""),std::vector<int>{(yyvsp[(1) - (3)].ival),(yyvsp[(2) - (3)].ival),(yyvsp[(3) - (3)].ival)}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[(yyvsp[(1) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (3)].ival)].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 157:
/* Line 1792 of yacc.c  */
#line 1001 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("simple_expression"),std::string(""),std::vector<int>{(yyvsp[(1) - (3)].ival),(yyvsp[(2) - (3)].ival),(yyvsp[(3) - (3)].ival)}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[(yyvsp[(1) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (3)].ival)].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 158:
/* Line 1792 of yacc.c  */
#line 1012 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("simple_expression"),std::string(""),std::vector<int>{(yyvsp[(1) - (1)].ival)}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[(yyvsp[(1) - (1)].ival)].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 159:
/* Line 1792 of yacc.c  */
#line 1021 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("term"),std::string(""),std::vector<int>{(yyvsp[(1) - (3)].ival),(yyvsp[(2) - (3)].ival),(yyvsp[(3) - (3)].ival)}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[(yyvsp[(1) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (3)].ival)].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 160:
/* Line 1792 of yacc.c  */
#line 1032 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("term"),std::string(""),std::vector<int>{(yyvsp[(1) - (3)].ival),(yyvsp[(2) - (3)].ival),(yyvsp[(3) - (3)].ival)}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[(yyvsp[(1) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (3)].ival)].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 161:
/* Line 1792 of yacc.c  */
#line 1043 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("term"),std::string(""),std::vector<int>{(yyvsp[(1) - (3)].ival),(yyvsp[(2) - (3)].ival),(yyvsp[(3) - (3)].ival)}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[(yyvsp[(1) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (3)].ival)].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 162:
/* Line 1792 of yacc.c  */
#line 1054 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("term"),std::string(""),std::vector<int>{(yyvsp[(1) - (3)].ival),(yyvsp[(2) - (3)].ival),(yyvsp[(3) - (3)].ival)}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[(yyvsp[(1) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (3)].ival)].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 163:
/* Line 1792 of yacc.c  */
#line 1065 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("term"),std::string(""),std::vector<int>{(yyvsp[(1) - (3)].ival),(yyvsp[(2) - (3)].ival),(yyvsp[(3) - (3)].ival)}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[(yyvsp[(1) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (3)].ival)].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 164:
/* Line 1792 of yacc.c  */
#line 1076 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("term"),std::string(""),std::vector<int>{(yyvsp[(1) - (1)].ival)}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[(yyvsp[(1) - (1)].ival)].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 165:
/* Line 1792 of yacc.c  */
#line 1085 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("factor"),std::string(""),std::vector<int>{(yyvsp[(1) - (1)].ival)}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[(yyvsp[(1) - (1)].ival)].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 166:
/* Line 1792 of yacc.c  */
#line 1094 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("factor"),std::string(""),std::vector<int>{(yyvsp[(1) - (1)].ival)}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[(yyvsp[(1) - (1)].ival)].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 167:
/* Line 1792 of yacc.c  */
#line 1103 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("factor"),std::string(""),std::vector<int>{(yyvsp[(1) - (1)].ival)}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[(yyvsp[(1) - (1)].ival)].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 168:
/* Line 1792 of yacc.c  */
#line 1112 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("factor"),std::string(""),std::vector<int>{(yyvsp[(1) - (4)].ival),(yyvsp[(2) - (4)].ival),(yyvsp[(3) - (4)].ival),(yyvsp[(4) - (4)].ival)}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[(yyvsp[(1) - (4)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (4)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (4)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(4) - (4)].ival)].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 169:
/* Line 1792 of yacc.c  */
#line 1124 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("factor"),std::string(""),std::vector<int>{(yyvsp[(1) - (3)].ival),(yyvsp[(2) - (3)].ival),(yyvsp[(3) - (3)].ival)}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[(yyvsp[(1) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (3)].ival)].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 170:
/* Line 1792 of yacc.c  */
#line 1135 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("factor"),std::string(""),std::vector<int>{(yyvsp[(1) - (2)].ival),(yyvsp[(2) - (2)].ival)}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[(yyvsp[(1) - (2)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (2)].ival)].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 171:
/* Line 1792 of yacc.c  */
#line 1145 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("factor"),std::string(""),std::vector<int>{(yyvsp[(1) - (2)].ival),(yyvsp[(2) - (2)].ival)}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[(yyvsp[(1) - (2)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (2)].ival)].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;	
}
    break;

  case 172:
/* Line 1792 of yacc.c  */
#line 1156 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("type"),std::string(""),std::vector<int>{(yyvsp[(1) - (1)].ival)}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[(yyvsp[(1) - (1)].ival)].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 173:
/* Line 1792 of yacc.c  */
#line 1165 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("type"),std::string(""),std::vector<int>{(yyvsp[(1) - (6)].ival),(yyvsp[(2) - (6)].ival),(yyvsp[(3) - (6)].ival),(yyvsp[(4) - (6)].ival),(yyvsp[(5) - (6)].ival),(yyvsp[(6) - (6)].ival)}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[(yyvsp[(1) - (6)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (6)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (6)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(4) - (6)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(5) - (6)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(6) - (6)].ival)].setParent(parseTree.size() - 1);
}
    break;

  case 174:
/* Line 1792 of yacc.c  */
#line 1178 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("period"),std::string(""),std::vector<int>{(yyvsp[(1) - (5)].ival),(yyvsp[(2) - (5)].ival),(yyvsp[(3) - (5)].ival),(yyvsp[(4) - (5)].ival),(yyvsp[(5) - (5)].ival)}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[(yyvsp[(1) - (5)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (5)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (5)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(4) - (5)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(5) - (5)].ival)].setParent(parseTree.size() - 1);
}
    break;

  case 175:
/* Line 1792 of yacc.c  */
#line 1189 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("period"),std::string(""),std::vector<int>{(yyvsp[(1) - (3)].ival),(yyvsp[(2) - (3)].ival),(yyvsp[(3) - (3)].ival)}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[(yyvsp[(1) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (3)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(3) - (3)].ival)].setParent(parseTree.size() - 1);
}
    break;


/* Line 1792 of yacc.c  */
#line 3949 "parser.tab.cpp"
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
#line 1200 "parser.y"

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
	yyin = fopen("test.txt","r");
	yydebug = 0;
	yyparse();
	//test();
	return 0;
}

void yyerror(const char* s) {
	//fprintf(stderr, "Parse error: %s in line %d\n", s,yylloc.first_line);
	//exit(1);
}
