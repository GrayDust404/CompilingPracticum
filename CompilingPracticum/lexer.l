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

"program"				{
						parseTree.push_back(ParseTreeNode(std::string("program"),std::string(yytext),yylineno));
						yylval.ival = parseTree.size() - 1;
						return program;
						}

"var"					{
						parseTree.push_back(ParseTreeNode(std::string("var"),std::string(yytext),yylineno));
						yylval.ival = parseTree.size() - 1;
						return _var;
						}

"const"					{
						parseTree.push_back(ParseTreeNode(std::string("const"),std::string(yytext),yylineno));
						yylval.ival = parseTree.size() - 1;
						return _const;
						}
"integer"|"boolean"|"char"|"real" {
						parseTree.push_back(ParseTreeNode(std::string("simple_type"),std::string(yytext),yylineno));
						yylval.ival = parseTree.size() - 1;
						return simple_type;						
						}

"begin"					{ return BEGINTOK;}
"end"					{ return ENDTOK;}

[a-zA-Z][0-9a-zA-Z]* 	{
						parseTree.push_back(ParseTreeNode(std::string("id"),std::string(yytext),yylineno));
						yylval.ival = parseTree.size() - 1;
						return id;
						}
[0-9]+					{
						parseTree.push_back(ParseTreeNode(std::string("num"),std::string(yytext),yylineno));
						yylval.ival = parseTree.size() - 1;
						return num;
						}
","						{
						parseTree.push_back(ParseTreeNode(std::string("comma"),std::string(yytext),yylineno));
						yylval.ival = parseTree.size() - 1;
						return comma;
						}
";"						{
						parseTree.push_back(ParseTreeNode(std::string("semicolon"),std::string(yytext),yylineno));
						yylval.ival = parseTree.size() - 1;
						return semicolon;
						}
":="					{
						parseTree.push_back(ParseTreeNode(std::string("assginop"),std::string(yytext),yylineno));
						yylval.ival = parseTree.size() - 1;
						return assignop;
						}
":"						{
						parseTree.push_back(ParseTreeNode(std::string("colon"),std::string(yytext),yylineno));
						yylval.ival = parseTree.size() - 1;
						return colon;
						}	
"("						{return leftB;}
")"						{return rightB;}
\n						{}
[ \t]					{}
%%