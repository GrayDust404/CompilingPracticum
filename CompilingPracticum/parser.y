%{

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include"parser.h"

extern int yylex();
extern int yyparse();
extern FILE* yyin;

void yyerror(const char* s);
std::vector<ParseTreeNode> parseTree;
int parseTreeRoot;
%}

%union{
	int ival;
}

%token<ival> ID
%type<ival> idlist



%start idlist

%%

idlist: 
	   | idlist ID {
				   parseTree.push_back(ParseTreeNode(std::string("idlist"),std::string(""),std::vector<int>{$1,$2}));
				   $$ = parseTree.size() - 1;
				   parseTreeRoot = parseTree.size() - 1; //仅最上层规则需要 
				   }
;

%%

int main(int argc, char* argv[]) 
{
	yyin = stdin;
	do { 
		yyparse();
	} while(!feof(yyin));

	return 0;
}

void yyerror(const char* s) {
	fprintf(stderr, "Parse error: %s\n", s);
	exit(1);
}