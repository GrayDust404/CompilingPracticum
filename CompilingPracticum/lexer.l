%option noyywrap
%option yylineno

%{
#include<stdio.h>
#include<iostream>
#include"parser.h"

#define YY_DECL int yylex()

#include "parser.tab.h"
extern std::vector<ParseTreeNode> parseTree;
%}

%%

"program"				{return program;}

[a-zA-Z][0-9a-zA-Z]* 	{
						parseTree.push_back(ParseTreeNode(std::string("id"),std::string(yytext),yylineno));
						yylval.ival = parseTree.size() - 1;
						return id;
						}
"("						{return leftB;}
")"						{return rightB;}
\n						{}
[ \t]					{}
%%