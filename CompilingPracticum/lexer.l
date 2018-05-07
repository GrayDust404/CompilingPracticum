%option noyywrap
%option yylineno

%{
#include<stdio.h>
#include<iostream>
#include<string>
#include"parser.h"

#define YY_DECL int yylex()
int yycolumn = 1;
int lexerror = 0;
#define YY_USER_ACTION yylloc.first_line = yylloc.last_line = yylineno;\
	yylloc.first_column = yycolumn;yylloc.last_column = yycolumn+yyleng-1;\
	yycolumn += yyleng;
	
#include "parser.tab.h"
extern std::vector<ParseTreeNode> parseTree;
void lexerError(std::string msg,std::string s,int line);
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
"if"					{
						parseTree.push_back(ParseTreeNode(std::string("if"),std::string(yytext),yylineno));
						yylval.ival = parseTree.size() - 1;
						return _if;
						}
"then"					{
						parseTree.push_back(ParseTreeNode(std::string("then"),std::string(yytext),yylineno));
						yylval.ival = parseTree.size() - 1;
						return _then;						
						}
"for"					{
						parseTree.push_back(ParseTreeNode(std::string("for"),std::string(yytext),yylineno));
						yylval.ival = parseTree.size() - 1;
						return _for;						
						}
"while"					{
						parseTree.push_back(ParseTreeNode(std::string("while"),std::string(yytext),yylineno));
						yylval.ival = parseTree.size() - 1;
						return _while;
						}
"else"					{
						parseTree.push_back(ParseTreeNode(std::string("else"),std::string(yytext),yylineno));
						yylval.ival = parseTree.size() - 1;
						return _else;	
						}
"of"					{
						parseTree.push_back(ParseTreeNode(std::string("of"),std::string(yytext),yylineno));
						yylval.ival = parseTree.size() - 1;
						return _of;
						}
"to"					{
						parseTree.push_back(ParseTreeNode(std::string("to"),std::string(yytext),yylineno));
						yylval.ival = parseTree.size() - 1;
						return _to;						
						}
"do"					{
						parseTree.push_back(ParseTreeNode(std::string("do"),std::string(yytext),yylineno));
						yylval.ival = parseTree.size() - 1;
						return _do;	
						}
"or"					{
						parseTree.push_back(ParseTreeNode(std::string("or"),std::string(yytext),yylineno));
						yylval.ival = parseTree.size() - 1;
						return _or;
						}
"array"					{
						parseTree.push_back(ParseTreeNode(std::string("array"),std::string(yytext),yylineno));
						yylval.ival = parseTree.size() - 1;
						return _array;
						}
"const"					{
						parseTree.push_back(ParseTreeNode(std::string("const"),std::string(yytext),yylineno));
						yylval.ival = parseTree.size() - 1;
						return _const;
						}
"procedure"				{
						parseTree.push_back(ParseTreeNode(std::string("procedure"),std::string(yytext),yylineno));
						yylval.ival = parseTree.size() - 1;
						return procedure;
						}
"function"				{
						parseTree.push_back(ParseTreeNode(std::string("function"),std::string(yytext),yylineno));
						yylval.ival = parseTree.size() - 1;
						return function;
						}
"integer"|"boolean"|"char"|"real" {
						parseTree.push_back(ParseTreeNode(std::string("simple_type"),std::string(yytext),yylineno));
						yylval.ival = parseTree.size() - 1;
						return simple_type;						
						}
"not"					{
						parseTree.push_back(ParseTreeNode(std::string("not"),std::string(yytext),yylineno));
						yylval.ival = parseTree.size() - 1;
						return _not;	
						}
"div"					{
						parseTree.push_back(ParseTreeNode(std::string("div"),std::string(yytext),yylineno));
						yylval.ival = parseTree.size() - 1;
						return _div;
						}
"mod"					{
						parseTree.push_back(ParseTreeNode(std::string("mod"),std::string(yytext),yylineno));
						yylval.ival = parseTree.size() - 1;
						return _mod;
						}
"and"					{
						parseTree.push_back(ParseTreeNode(std::string("and"),std::string(yytext),yylineno));
						yylval.ival = parseTree.size() - 1;
						return _and;
						}

"begin"					{ return BEGINTOK;}
"end"					{ return ENDTOK;}
\'[a-zA-Z]\'			{
						parseTree.push_back(ParseTreeNode(std::string("letter"),std::string(yytext),yylineno));
						yylval.ival = parseTree.size() - 1;
						return letter;
						}
\'[a-zA-Z]             {
						lexerError("Lack of single quotes",yytext,yylineno);
						parseTree.push_back(ParseTreeNode(std::string("letter"),std::string(yytext),yylineno));
						yylval.ival = parseTree.size() - 1;
						return letter;
						}
\'[a-zA-Z][a-zA-Z]+\'	{
						lexerError("Do not support string",yytext,yylineno);
						parseTree.push_back(ParseTreeNode(std::string("letter"),std::string(yytext),yylineno));
						yylval.ival = parseTree.size() - 1;
						return letter;
						}
\'[a-zA-Z][a-zA-Z]+		{
						lexerError("Illegal alphabet format",yytext,yylineno);
						parseTree.push_back(ParseTreeNode(std::string("letter"),std::string(yytext),yylineno));
						yylval.ival = parseTree.size() - 1;
						return letter;
						}
\'[ ]*\'				{
						lexerError("Empty alphabet format",yytext,yylineno);
						parseTree.push_back(ParseTreeNode(std::string("letter"),std::string(yytext),yylineno));
						yylval.ival = parseTree.size() - 1;
						return letter;
						}
[a-zA-Z][0-9a-zA-Z]* 	{
						parseTree.push_back(ParseTreeNode(std::string("id"),std::string(yytext),yylineno));
						yylval.ival = parseTree.size() - 1;
						if(strlen(yytext)>=30)
						lexerError("id over length limit",yytext,yylineno);
						return id;
						}
[0-9]+\.[0-9]+			{
						parseTree.push_back(ParseTreeNode(std::string("num"),std::string(yytext),yylineno));
						yylval.ival = parseTree.size() - 1;
						return num;
						}
[0-9]+\.$		    {
						lexerError("Illegal number form ",yytext,yylineno);
						parseTree.push_back(ParseTreeNode(std::string("num"),std::string(yytext),yylineno));
						yylval.ival = parseTree.size() - 1;
						return num;
						}
[0-9]+\.[a-zA-Z]+		{
						lexerError("Illegal number form ",yytext,yylineno);
						parseTree.push_back(ParseTreeNode(std::string("num"),std::string(yytext),yylineno));
						yylval.ival = parseTree.size() - 1;
						return num;
                         }
[0-9]+					{
						parseTree.push_back(ParseTreeNode(std::string("digits"),std::string(yytext),yylineno));
						yylval.ival = parseTree.size() - 1;
						return digits;
						}
"["						{
						parseTree.push_back(ParseTreeNode(std::string("left square bracket"),std::string(yytext),yylineno));
						yylval.ival = parseTree.size() - 1;
						return leftSB;
						}
"]"						{
						parseTree.push_back(ParseTreeNode(std::string("right square bracket"),std::string(yytext),yylineno));
						yylval.ival = parseTree.size() - 1;						
						return rightSB;
						}
","						{
						parseTree.push_back(ParseTreeNode(std::string("comma"),std::string(yytext),yylineno));
						yylval.ival = parseTree.size() - 1;
						return comma;
						}
\.\.					{
						parseTree.push_back(ParseTreeNode(std::string("range"),std::string(yytext),yylineno));
						yylval.ival = parseTree.size() - 1;
						return _range;						
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
"="						{
						parseTree.push_back(ParseTreeNode(std::string("assgin"),std::string(yytext),yylineno));
						yylval.ival = parseTree.size() - 1;
						return assign;
						}
"<>"					{
						parseTree.push_back(ParseTreeNode(std::string("noequal"),std::string(yytext),yylineno));
						yylval.ival = parseTree.size() - 1;
						return noequal;						
						}
">="					{
						parseTree.push_back(ParseTreeNode(std::string("greatequal"),std::string(yytext),yylineno));
						yylval.ival = parseTree.size() - 1;
						return GE;	
						}
">"						{
						parseTree.push_back(ParseTreeNode(std::string("greatthan"),std::string(yytext),yylineno));
						yylval.ival = parseTree.size() - 1;
						return GT;	
						}
"<="					{
						parseTree.push_back(ParseTreeNode(std::string("lessequal"),std::string(yytext),yylineno));
						yylval.ival = parseTree.size() - 1;
						return LE;	
						}
"<"						{
						parseTree.push_back(ParseTreeNode(std::string("lessthan"),std::string(yytext),yylineno));
						yylval.ival = parseTree.size() - 1;
						return LT;	
						}
"+"						{
						parseTree.push_back(ParseTreeNode(std::string("plus"),std::string(yytext),yylineno));
						yylval.ival = parseTree.size() - 1;
						return plus;						
						}
"-"						{
						parseTree.push_back(ParseTreeNode(std::string("minus"),std::string(yytext),yylineno));
						yylval.ival = parseTree.size() - 1;
						return minus;
						}
"*"						{
						parseTree.push_back(ParseTreeNode(std::string("multiply"),std::string(yytext),yylineno));
						yylval.ival = parseTree.size() - 1;
						return multiply;						
						}
"{"[^}]*"}"		{}
"/*"(([^\*]*(\*[^\/])?)*)"*/"  {}
"//".*\n			{}
"/"						{
						parseTree.push_back(ParseTreeNode(std::string("divide"),std::string(yytext),yylineno));
						yylval.ival = parseTree.size() - 1;
						return divide;
						}

"("						{	
						parseTree.push_back(ParseTreeNode(std::string("left bracket"),std::string(yytext),yylineno));
						yylval.ival = parseTree.size() - 1;
						return leftB;
						}
")"						{
						parseTree.push_back(ParseTreeNode(std::string("right bracket"),std::string(yytext),yylineno));
						yylval.ival = parseTree.size() - 1;
						return rightB;
						}
\.						{
						return fullstop;
						}
\n						{yycolumn = 1;}
[ \t]					{}
[^\s|\.]                {
						lexerError("Illegal characters",yytext,yylineno);
						}
%%

void lexerError(std::string msg,std::string s,int line) {
	lexerror++;
	std::cout << "Lexical errors ("<<msg<<") : "<< s << " in line "<< line <<"\n";
}