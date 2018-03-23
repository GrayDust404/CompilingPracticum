
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

%token<ival> id
%type<ival> idlist



%start idlist

%%

idlist: 
	   | idlist id {
				   parseTree.push_back(ParseTreeNode(std::string("idlist"),std::string(""),std::vector<int>{$1,$2}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
				   }
;

%%

int main(int argc, char* argv[]) 
{
	yyin = fopen("test.txt","r");
	yyparse();

	return 0;
}

void yyerror(const char* s) {
	fprintf(stderr, "Parse error: %s\n", s);
	exit(1);
}