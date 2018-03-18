%option noyywrap

%{
#include<stdio.h>
#include"parser.h"

#define YY_DECL int yylex()

#include "parser.tab.h"
extern std::vector<ParseTreeNode> parseTree;
%}

%%

[a-zA-Z][0-9a-zA-Z]* 	{
						parseTree.push_back(ParseTreeNode(std::string("ID"),std::string(yytext)));
						yylval.ival = parseTree.size() - 1;
						return ID;
						}

%%