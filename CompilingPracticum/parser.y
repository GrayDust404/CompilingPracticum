
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

%token<ival> id semicolon comma _const _var colon simple_type assignop num 
%token program leftB rightB BEGINTOK ENDTOK
%type<ival> programstruct program_head program_body idlist type variable 
%type<ival> const_declarations var_declarations const_declaration var_declaration subprogram_declarations subprogram
%type<ival> compound_statement statement_list statement expression simple_expression term factor

%start programstruct

%%


programstruct: program_head semicolon program_body

program_head: program id leftB idlist rightB	
				   {
				   parseTree.push_back(ParseTreeNode(std::string("program_head"),std::string(""),std::vector<int>{$2,$4}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$4].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
				   }
;
idlist: {		   parseTree.push_back(ParseTreeNode(std::string("idlist"),std::string(""),std::vector<int>{}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTreeRoot = parseTree.size() - 1;
				   }
|idlist comma id	{
				   parseTree.push_back(ParseTreeNode(std::string("idlist"),std::string(""),std::vector<int>{$1,$2,$3}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
				   }
| id {
				   parseTree.push_back(ParseTreeNode(std::string("idlist"),std::string(""),std::vector<int>{$1}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
};
program_body: const_declarations var_declarations subprogram_declarations compound_statement;

const_declarations: {
				   parseTree.push_back(ParseTreeNode(std::string("const_declarations"),std::string(""),std::vector<int>{}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
} 
|_const const_declaration {				   
				   parseTree.push_back(ParseTreeNode(std::string("const_declarations"),std::string(""),std::vector<int>{$1,$2}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
				   } 
;
const_declaration: {};
var_declarations:{
				   parseTree.push_back(ParseTreeNode(std::string("var_declarations"),std::string(""),std::vector<int>{}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
};
|_var var_declaration {
				   parseTree.push_back(ParseTreeNode(std::string("var_declarations"),std::string(""),std::vector<int>{$1,$2}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;	
};
var_declaration: idlist colon type semicolon{
				   parseTree.push_back(ParseTreeNode(std::string("var_declaration"),std::string(""),std::vector<int>{$1,$2,$3}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
};
subprogram_declarations:  {
				   parseTree.push_back(ParseTreeNode(std::string("subprogram_declarations"),std::string(""),std::vector<int>{}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;	
}
|subprogram_declarations subprogram{
				   parseTree.push_back(ParseTreeNode(std::string("subprogram_declarations"),std::string(""),std::vector<int>{$1,$2}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
};
subprogram: {};

compound_statement: BEGINTOK statement_list ENDTOK{
				   parseTree.push_back(ParseTreeNode(std::string("compound_statement"),std::string(""),std::vector<int>{$2}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$2].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
};
statement_list:  statement_list semicolon statement {
				   parseTree.push_back(ParseTreeNode(std::string("statement_list"),std::string(""),std::vector<int>{$1,$2,$3}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
|statement{
				   parseTree.push_back(ParseTreeNode(std::string("statement_list"),std::string(""),std::vector<int>{$1}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
};
statement: variable assignop expression semicolon{
				   parseTree.push_back(ParseTreeNode(std::string("statement_list"),std::string(""),std::vector<int>{$1,$2,$3}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
};
variable : id{
				   parseTree.push_back(ParseTreeNode(std::string("variable"),std::string(""),std::vector<int>{$1}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
};
expression: simple_expression{
				   parseTree.push_back(ParseTreeNode(std::string("expression"),std::string(""),std::vector<int>{$1}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
};
simple_expression: term{
				   parseTree.push_back(ParseTreeNode(std::string("simple_expression"),std::string(""),std::vector<int>{$1}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
};
term: factor{
				   parseTree.push_back(ParseTreeNode(std::string("term"),std::string(""),std::vector<int>{$1}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
};
factor: num {
				   parseTree.push_back(ParseTreeNode(std::string("num"),std::string(""),std::vector<int>{$1}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
};

type : simple_type{
				   parseTree.push_back(ParseTreeNode(std::string("type"),std::string(""),std::vector<int>{$1}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
};


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