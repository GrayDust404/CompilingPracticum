%option noyywrap

%{
#include <stdio.h>

#define YY_DECL int yylex()

#include "parser.tab.h"

%}

%%

[a-zA-Z][0-9a-zA-Z]* 	{yylval.sval = yytext;return ID;}
\n		{return EOL;}

%%