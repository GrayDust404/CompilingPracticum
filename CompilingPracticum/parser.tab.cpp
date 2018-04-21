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
#include"parser.h"
#include"transform.h"

extern int yylex();
extern int yyparse();
extern FILE* yyin;

void yyerror(const char* s);
std::vector<ParseTreeNode> parseTree;
int parseTreeRoot;

/* Line 371 of yacc.c  */
#line 85 "parser.tab.cpp"

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
# define YYERROR_VERBOSE 1
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
#line 21 "parser.y"

	int ival;


/* Line 387 of yacc.c  */
#line 181 "parser.tab.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

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
#line 209 "parser.tab.cpp"

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   160

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNRULES -- Number of states.  */
#define YYNSTATES  173

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
       0,     0,     3,     7,    13,    17,    19,    24,    25,    28,
      34,    38,    41,    44,    46,    49,    52,    54,    56,    57,
      61,    65,    71,    72,    76,    80,    84,    90,    91,    95,
      99,   101,   103,   105,   108,   112,   116,   120,   124,   126,
     127,   131,   133,   135,   141,   150,   155,   156,   159,   161,
     166,   169,   170,   174,   178,   180,   182,   186,   190,   194,
     198,   202,   206,   210,   214,   218,   220,   224,   228,   232,
     236,   240,   242,   244,   246,   251,   255,   258,   261,   263,
     270,   276
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      50,     0,    -1,    51,     4,    53,    -1,    46,     3,    42,
      52,    43,    -1,    52,     5,     3,    -1,     3,    -1,    54,
      57,    59,    68,    -1,    -1,     6,    55,    -1,    55,     4,
       3,    12,    56,    -1,     3,    12,    56,    -1,    14,     3,
      -1,    15,     3,    -1,     3,    -1,    14,    11,    -1,    15,
      11,    -1,    11,    -1,    16,    -1,    -1,     7,    58,     4,
      -1,    52,     8,    80,    -1,    58,     4,    52,     8,    80,
      -1,    -1,    59,    60,     4,    -1,    61,     4,    67,    -1,
      17,     3,    62,    -1,    18,     3,    62,     8,     9,    -1,
      -1,    42,    63,    43,    -1,    63,     4,    64,    -1,    64,
      -1,    65,    -1,    66,    -1,     7,    66,    -1,    52,     8,
       9,    -1,    54,    57,    68,    -1,    47,    69,    48,    -1,
      69,     4,    70,    -1,    70,    -1,    -1,    73,    10,    76,
      -1,    72,    -1,    68,    -1,    27,    76,    28,    70,    71,
      -1,    29,     3,    10,    76,    31,    76,    32,    70,    -1,
      36,    76,    32,    70,    -1,    -1,    30,    70,    -1,     3,
      -1,     3,    42,    75,    43,    -1,     3,    74,    -1,    -1,
      44,    75,    45,    -1,    75,     5,    76,    -1,    76,    -1,
      77,    -1,    77,    12,    77,    -1,    77,    37,    77,    -1,
      77,    38,    77,    -1,    77,    39,    77,    -1,    77,    40,
      77,    -1,    77,    41,    77,    -1,    77,    14,    78,    -1,
      77,    15,    78,    -1,    77,    33,    78,    -1,    78,    -1,
      78,    21,    79,    -1,    78,    22,    79,    -1,    78,    23,
      79,    -1,    78,    24,    79,    -1,    78,    25,    79,    -1,
      79,    -1,    11,    -1,    73,    -1,     3,    42,    75,    43,
      -1,    42,    76,    43,    -1,    26,    79,    -1,    15,    79,
      -1,     9,    -1,    20,    44,    81,    45,    34,     9,    -1,
      81,     5,    11,    35,    11,    -1,    11,    35,    11,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    40,    40,    53,    67,    78,    87,    98,   106,   117,
     130,   141,   151,   161,   170,   180,   190,   199,   209,   217,
     228,   239,   253,   261,   272,   283,   293,   304,   312,   323,
     334,   343,   352,   361,   371,   382,   394,   403,   414,   423,
     431,   442,   451,   460,   473,   489,   499,   507,   518,   527,
     539,   549,   555,   564,   575,   584,   593,   604,   615,   626,
     637,   648,   659,   670,   681,   692,   701,   712,   723,   734,
     745,   756,   765,   774,   783,   795,   806,   816,   827,   836,
     849,   860
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
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
       0,    49,    50,    51,    52,    52,    53,    54,    54,    55,
      55,    56,    56,    56,    56,    56,    56,    56,    57,    57,
      58,    58,    59,    59,    60,    61,    61,    62,    62,    63,
      63,    64,    64,    65,    66,    67,    68,    69,    69,    70,
      70,    70,    70,    70,    70,    70,    71,    71,    72,    72,
      73,    74,    74,    75,    75,    76,    76,    76,    76,    76,
      76,    76,    77,    77,    77,    77,    78,    78,    78,    78,
      78,    78,    79,    79,    79,    79,    79,    79,    80,    80,
      81,    81
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     5,     3,     1,     4,     0,     2,     5,
       3,     2,     2,     1,     2,     2,     1,     1,     0,     3,
       3,     5,     0,     3,     3,     3,     5,     0,     3,     3,
       1,     1,     1,     2,     3,     3,     3,     3,     1,     0,
       3,     1,     1,     5,     8,     4,     0,     2,     1,     4,
       2,     0,     3,     3,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     3,     3,     3,     3,
       3,     1,     1,     1,     4,     3,     2,     2,     1,     6,
       5,     3
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     1,     7,     0,     0,     2,
      18,     5,     0,     0,     8,     0,    22,     0,     3,     0,
       0,     0,     0,     0,     4,    13,    16,     0,     0,    17,
      10,     0,     0,    19,     0,     0,    39,     0,     0,     6,
      11,    14,    12,    15,     0,    78,     0,    20,     0,    27,
      27,    48,     0,     0,     0,    42,     0,    38,    41,     0,
      23,     7,     9,     0,     0,     0,    25,     0,     0,     0,
      50,    51,    72,     0,     0,     0,    73,     0,    55,    65,
      71,     0,     0,    39,    36,     0,    18,    24,     0,     0,
      21,     0,     0,     0,    30,    31,    32,     0,     0,    54,
       0,     0,    77,    76,     0,    39,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    39,    37,    40,     0,     0,     0,     0,    33,     0,
       0,    28,    26,     0,    49,    52,     0,    75,    46,    56,
      62,    63,    64,    57,    58,    59,    60,    61,    66,    67,
      68,    69,    70,     0,    45,    35,    81,     0,     0,    34,
      29,    53,    74,    39,    43,     0,     0,    79,    47,     0,
      80,    39,    44
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    92,     9,    10,    14,    30,    16,    22,
      23,    37,    38,    66,    93,    94,    95,    96,    87,    55,
      56,    57,   164,    58,    76,    70,    98,    99,    78,    79,
      80,    47,    89
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -78
static const yytype_int16 yypact[] =
{
     -35,    24,    40,    58,   -19,   -78,    62,    77,    79,   -78,
      82,   -78,    14,    91,   100,    77,   -78,    92,   -78,    61,
     116,    73,   117,    20,   -78,   -78,   -78,    28,    76,   -78,
     -78,   108,     4,    77,   119,   120,     7,   121,   122,   -78,
     -78,   -78,   -78,   -78,    61,   -78,    80,   -78,    83,    86,
      86,    19,     6,   126,     6,   -78,     8,   -78,   -78,   123,
     -78,    62,   -78,   125,     4,    23,   -78,   124,     6,     6,
     -78,   -26,   -78,     6,     6,     6,   -78,   102,    59,    89,
     -78,   127,    99,     7,   -78,     6,    82,   -78,   103,     0,
     -78,    77,    85,    -1,   -78,   -78,   -78,   130,    15,   -78,
      10,     6,   -78,   -78,    97,     7,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     7,   -78,   -78,    87,   131,   132,   107,   -78,   135,
      23,   -78,   -78,     6,   -78,   -78,    17,   -78,   115,    51,
      89,    89,    89,    51,    51,    51,    51,    51,   -78,   -78,
     -78,   -78,   -78,   118,   -78,   -78,   -78,   111,   138,   -78,
     -78,   -78,   -78,     7,   -78,     6,   137,   -78,   -78,   128,
     -78,     7,   -78
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -78,   -78,   -78,    26,   -78,    90,   -78,   106,    66,   -78,
     -78,   -78,   -78,   104,   -78,    25,   -78,    65,   -78,   -22,
     -78,   -77,   -78,   -78,   -36,   -78,   -55,   -50,    -5,     9,
     -66,    93,   -78
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -52
static const yytype_int16 yytable[] =
{
      59,    39,    77,   130,    82,   126,   122,   102,   103,    71,
      51,     1,    83,    45,   100,   133,   101,    72,    69,    17,
     133,    73,   133,     7,    46,   104,    11,     4,   138,   -51,
      91,    40,    74,    12,    52,   123,    53,    34,    35,    41,
       5,    21,   131,    54,   154,   127,   136,    59,    75,   148,
     149,   150,   151,   152,    36,   135,    84,    18,   134,    48,
     162,    68,     6,    69,    25,   107,   108,    36,     8,    59,
     153,   106,    26,   107,   108,    27,    28,    29,    17,    42,
      11,    32,    13,   161,   109,    59,   168,    43,    17,    15,
      17,    64,   109,   129,   172,    24,   110,   111,   112,   113,
     114,   139,   155,    19,    20,   143,   144,   145,   146,   147,
     115,   116,   117,   118,   119,   169,   140,   141,   142,    31,
      44,    33,    49,    50,    63,    60,    61,    59,    65,    81,
     105,   121,    97,    85,    36,    59,    88,   120,   125,   132,
     137,   158,   156,   157,   159,   163,   166,   167,   170,   165,
      62,    86,   124,     0,    67,   160,   128,    90,     0,     0,
     171
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-78)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      36,    23,    52,     4,    54,     5,    83,    73,    74,     3,
       3,    46,     4,     9,    69,     5,    42,    11,    44,     5,
       5,    15,     5,    42,    20,    75,     3,     3,   105,    10,
       7,     3,    26,     7,    27,    85,    29,    17,    18,    11,
       0,    15,    43,    36,   121,    45,   101,    83,    42,   115,
     116,   117,   118,   119,    47,    45,    48,    43,    43,    33,
      43,    42,     4,    44,     3,    14,    15,    47,     6,   105,
     120,    12,    11,    14,    15,    14,    15,    16,     5,     3,
       3,     8,     3,   133,    33,   121,   163,    11,     5,     7,
       5,     8,    33,     8,   171,     3,    37,    38,    39,    40,
      41,   106,   124,    12,     4,   110,   111,   112,   113,   114,
      21,    22,    23,    24,    25,   165,   107,   108,   109,     3,
      12,     4,     3,     3,    44,     4,     4,   163,    42,     3,
      28,    32,     8,    10,    47,   171,    11,    10,    35,     9,
      43,    34,    11,    11,     9,    30,    35,     9,    11,    31,
      44,    61,    86,    -1,    50,   130,    91,    64,    -1,    -1,
      32
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    46,    50,    51,     3,     0,     4,    42,     6,    53,
      54,     3,    52,     3,    55,     7,    57,     5,    43,    12,
       4,    52,    58,    59,     3,     3,    11,    14,    15,    16,
      56,     3,     8,     4,    17,    18,    47,    60,    61,    68,
       3,    11,     3,    11,    12,     9,    20,    80,    52,     3,
       3,     3,    27,    29,    36,    68,    69,    70,    72,    73,
       4,     4,    56,    44,     8,    42,    62,    62,    42,    44,
      74,     3,    11,    15,    26,    42,    73,    76,    77,    78,
      79,     3,    76,     4,    48,    10,    54,    67,    11,    81,
      80,     7,    52,    63,    64,    65,    66,     8,    75,    76,
      75,    42,    79,    79,    76,    28,    12,    14,    15,    33,
      37,    38,    39,    40,    41,    21,    22,    23,    24,    25,
      10,    32,    70,    76,    57,    35,     5,    45,    66,     8,
       4,    43,     9,     5,    43,    45,    75,    43,    70,    77,
      78,    78,    78,    77,    77,    77,    77,    77,    79,    79,
      79,    79,    79,    76,    70,    68,    11,    11,    34,     9,
      64,    76,    43,    30,    71,    31,    35,     9,    70,    76,
      11,    32,    70
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


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
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
  FILE *yyo = yyoutput;
  YYUSE (yyo);
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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
/* Line 1792 of yacc.c  */
#line 40 "parser.y"
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
#line 54 "parser.y"
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

  case 4:
/* Line 1792 of yacc.c  */
#line 67 "parser.y"
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

  case 5:
/* Line 1792 of yacc.c  */
#line 78 "parser.y"
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

  case 6:
/* Line 1792 of yacc.c  */
#line 87 "parser.y"
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

  case 7:
/* Line 1792 of yacc.c  */
#line 98 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("const_declarations"),std::string(""),std::vector<int>{}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 106 "parser.y"
    {				   
				   parseTree.push_back(ParseTreeNode(std::string("const_declarations"),std::string(""),std::vector<int>{(yyvsp[(1) - (2)].ival),(yyvsp[(2) - (2)].ival)}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[(yyvsp[(1) - (2)].ival)].setParent(parseTree.size() - 1);
				   parseTree[(yyvsp[(2) - (2)].ival)].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
				   }
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 117 "parser.y"
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

  case 10:
/* Line 1792 of yacc.c  */
#line 130 "parser.y"
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

  case 11:
/* Line 1792 of yacc.c  */
#line 141 "parser.y"
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

  case 12:
/* Line 1792 of yacc.c  */
#line 151 "parser.y"
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

  case 13:
/* Line 1792 of yacc.c  */
#line 161 "parser.y"
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

  case 14:
/* Line 1792 of yacc.c  */
#line 170 "parser.y"
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

  case 15:
/* Line 1792 of yacc.c  */
#line 180 "parser.y"
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

  case 16:
/* Line 1792 of yacc.c  */
#line 190 "parser.y"
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

  case 17:
/* Line 1792 of yacc.c  */
#line 199 "parser.y"
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

  case 18:
/* Line 1792 of yacc.c  */
#line 209 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("var_declarations"),std::string(""),std::vector<int>{}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 217 "parser.y"
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

  case 20:
/* Line 1792 of yacc.c  */
#line 228 "parser.y"
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

  case 21:
/* Line 1792 of yacc.c  */
#line 239 "parser.y"
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

  case 22:
/* Line 1792 of yacc.c  */
#line 253 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("subprogram_declarations"),std::string(""),std::vector<int>{}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;	
}
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 261 "parser.y"
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

  case 24:
/* Line 1792 of yacc.c  */
#line 272 "parser.y"
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

  case 25:
/* Line 1792 of yacc.c  */
#line 283 "parser.y"
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

  case 26:
/* Line 1792 of yacc.c  */
#line 293 "parser.y"
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

  case 27:
/* Line 1792 of yacc.c  */
#line 304 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("formal_parameter"),std::string(""),std::vector<int>{}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 312 "parser.y"
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

  case 29:
/* Line 1792 of yacc.c  */
#line 323 "parser.y"
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

  case 30:
/* Line 1792 of yacc.c  */
#line 334 "parser.y"
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

  case 31:
/* Line 1792 of yacc.c  */
#line 343 "parser.y"
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

  case 32:
/* Line 1792 of yacc.c  */
#line 352 "parser.y"
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

  case 33:
/* Line 1792 of yacc.c  */
#line 361 "parser.y"
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

  case 34:
/* Line 1792 of yacc.c  */
#line 371 "parser.y"
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

  case 35:
/* Line 1792 of yacc.c  */
#line 382 "parser.y"
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

  case 36:
/* Line 1792 of yacc.c  */
#line 394 "parser.y"
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

  case 37:
/* Line 1792 of yacc.c  */
#line 403 "parser.y"
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

  case 38:
/* Line 1792 of yacc.c  */
#line 414 "parser.y"
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

  case 39:
/* Line 1792 of yacc.c  */
#line 423 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("statement"),std::string(""),std::vector<int>{}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 431 "parser.y"
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

  case 41:
/* Line 1792 of yacc.c  */
#line 442 "parser.y"
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

  case 42:
/* Line 1792 of yacc.c  */
#line 451 "parser.y"
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

  case 43:
/* Line 1792 of yacc.c  */
#line 460 "parser.y"
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

  case 44:
/* Line 1792 of yacc.c  */
#line 473 "parser.y"
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

  case 45:
/* Line 1792 of yacc.c  */
#line 489 "parser.y"
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

  case 46:
/* Line 1792 of yacc.c  */
#line 499 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("else_part"),std::string(""),std::vector<int>{}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 507 "parser.y"
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

  case 48:
/* Line 1792 of yacc.c  */
#line 518 "parser.y"
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

  case 49:
/* Line 1792 of yacc.c  */
#line 527 "parser.y"
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

  case 50:
/* Line 1792 of yacc.c  */
#line 539 "parser.y"
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

  case 51:
/* Line 1792 of yacc.c  */
#line 549 "parser.y"
    {
				   parseTree.push_back(ParseTreeNode(std::string("id_varpart"),std::string(""),std::vector<int>{}));
				   //记录指向本节点的指针
				   (yyval.ival) = parseTree.size() - 1;
				   //为子节点设置父节点指针
}
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 555 "parser.y"
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

  case 53:
/* Line 1792 of yacc.c  */
#line 564 "parser.y"
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

  case 54:
/* Line 1792 of yacc.c  */
#line 575 "parser.y"
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

  case 55:
/* Line 1792 of yacc.c  */
#line 584 "parser.y"
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

  case 56:
/* Line 1792 of yacc.c  */
#line 593 "parser.y"
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

  case 57:
/* Line 1792 of yacc.c  */
#line 604 "parser.y"
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

  case 58:
/* Line 1792 of yacc.c  */
#line 615 "parser.y"
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

  case 59:
/* Line 1792 of yacc.c  */
#line 626 "parser.y"
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

  case 60:
/* Line 1792 of yacc.c  */
#line 637 "parser.y"
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

  case 61:
/* Line 1792 of yacc.c  */
#line 648 "parser.y"
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

  case 62:
/* Line 1792 of yacc.c  */
#line 659 "parser.y"
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

  case 63:
/* Line 1792 of yacc.c  */
#line 670 "parser.y"
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

  case 64:
/* Line 1792 of yacc.c  */
#line 681 "parser.y"
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

  case 65:
/* Line 1792 of yacc.c  */
#line 692 "parser.y"
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

  case 66:
/* Line 1792 of yacc.c  */
#line 701 "parser.y"
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

  case 67:
/* Line 1792 of yacc.c  */
#line 712 "parser.y"
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

  case 68:
/* Line 1792 of yacc.c  */
#line 723 "parser.y"
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

  case 69:
/* Line 1792 of yacc.c  */
#line 734 "parser.y"
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

  case 70:
/* Line 1792 of yacc.c  */
#line 745 "parser.y"
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

  case 71:
/* Line 1792 of yacc.c  */
#line 756 "parser.y"
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

  case 72:
/* Line 1792 of yacc.c  */
#line 765 "parser.y"
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

  case 73:
/* Line 1792 of yacc.c  */
#line 774 "parser.y"
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

  case 74:
/* Line 1792 of yacc.c  */
#line 783 "parser.y"
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

  case 75:
/* Line 1792 of yacc.c  */
#line 795 "parser.y"
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

  case 76:
/* Line 1792 of yacc.c  */
#line 806 "parser.y"
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

  case 77:
/* Line 1792 of yacc.c  */
#line 816 "parser.y"
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

  case 78:
/* Line 1792 of yacc.c  */
#line 827 "parser.y"
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

  case 79:
/* Line 1792 of yacc.c  */
#line 836 "parser.y"
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

  case 80:
/* Line 1792 of yacc.c  */
#line 849 "parser.y"
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

  case 81:
/* Line 1792 of yacc.c  */
#line 860 "parser.y"
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
#line 2771 "parser.tab.cpp"
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


/* Line 2055 of yacc.c  */
#line 871 "parser.y"


int main(int argc, char* argv[]) 
{
	yyin = fopen("test.txt","r");
	yyparse();
	test();
	return 0;
}

void yyerror(const char* s) {
	fprintf(stderr, "Parse error: %s\n", s);
	exit(1);
}