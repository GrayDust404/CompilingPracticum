%{

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

extern int yylex();
extern int yyparse();
extern FILE* yyin;

void yyerror(const char* s);
%}

%union{
	char* sval;
}

%token<sval> ID
%token EOL



%start idlist

%%

idlist: 
	   | idlist ID EOL { std::cout << std::string($2);}
	   | idlist EOL
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