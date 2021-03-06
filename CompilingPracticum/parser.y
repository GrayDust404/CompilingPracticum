%locations
%{

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<fstream>
#include<string>
#include"parser.h"
#include"transform.h"
#include"parser.tab.h"
//#include"lexer.flex.cpp"

extern int yylex();
extern int yyparse();
extern FILE* yyin;
extern int yylineno;

void yyerror(const char* s);
std::vector<ParseTreeNode> parseTree;
void ParseError(std::string msg,int line);
void lParseError(std::string msg, YYLTYPE t);
int parseTreeRoot;
int parseNum = 0;
%}


%union{
	int ival;
}

%token<ival> id semicolon comma _const _var colon simple_type assignop digits assign relop plus minus letter procedure function num _array
%token<ival> multiply divide _div _mod _and _not
%token<ival> _if _then _for _else _to _do _or _of _range _while
%token<ival> noequal GE GT LE LT leftB rightB leftSB rightSB
%token  program BEGINTOK ENDTOK fullstop
%type<ival> programstruct program_head program_body idlist type variable const_value 
%type<ival> const_declarations var_declarations const_declaration var_declaration subprogram_declarations subprogram
%type<ival> subprogram_head subprogram_body formal_parameter parameter_list parameter var_parameter value_parameter
%type<ival> compound_statement statement_list statement expression expression_list simple_expression term factor
%type<ival> procedure_call else_part id_varpart period

%start programstruct

%%

programstruct: program_head semicolon program_body fullstop{
				   parseTree.push_back(ParseTreeNode(std::string("programstruct"),std::string(""),std::vector<int>{$1,$2,$3}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
					}
| program_head error semicolon program_body fullstop{
					lParseError("程序头部存在语法错误",@2);
					}
| error semicolon program_body fullstop{
					lParseError("程序头部存在语法错误",@2);
					}
| program_head semicolon error fullstop{
					lParseError("程序体存在语法错误",@2);
					}
| program_head semicolon program_body error{
					lParseError("程序结尾存在语法错误",@2);
					}
;


program_head: program id leftB idlist rightB	
				   {
				   parseTree.push_back(ParseTreeNode(std::string("program_head"),std::string(""),std::vector<int>{$2,$3,$4,$5}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   parseTree[$4].setParent(parseTree.size() - 1);
				   parseTree[$5].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
				   }
| program error leftB idlist rightB{
					lParseError("左括号前缺少主程序名称",@3);
					}
| program id leftB error rightB{
					lParseError("缺少输入参数，或输入参数存在语法错误",@3);
					}
| program id leftB idlist error{
					lParseError("主程序缺少右括号",@3);
					}
;
idlist: idlist comma id	{
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
}
| idlist comma error{
					lParseError("传入参数存在语法错误",@2);
					}
;
program_body: const_declarations var_declarations subprogram_declarations compound_statement{
				   parseTree.push_back(ParseTreeNode(std::string("program_body"),std::string(""),std::vector<int>{$1,$2,$3,$4}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   parseTree[$4].setParent(parseTree.size() - 1);
}
;

const_declarations: {
				   parseTree.push_back(ParseTreeNode(std::string("const_declarations"),std::string(""),std::vector<int>{}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
} 
| _const const_declaration semicolon {				   
				   parseTree.push_back(ParseTreeNode(std::string("const_declarations"),std::string(""),std::vector<int>{$1,$2}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
				   } 
| _const error semicolon{
					lParseError("常量声明存在语法错误",@3);
					}
| _const const_declaration error semicolon{
					lParseError("常量声明存在语法错误",@3);
					}
;
const_declaration: const_declaration semicolon id assign const_value{
				   parseTree.push_back(ParseTreeNode(std::string("const_declaration"),std::string(""),std::vector<int>{$1,$2,$3,$4,$5}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   parseTree[$4].setParent(parseTree.size() - 1);
				   parseTree[$5].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
| error semicolon id assign const_value{
					lParseError("常量声明存在语法错误",@2);
					}
| id assign const_value{
				   parseTree.push_back(ParseTreeNode(std::string("const_declaration"),std::string(""),std::vector<int>{$1,$2,$3}));
				   //记录指向本节点的指针 
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;	
}

;
const_value : plus id{
				   parseTree.push_back(ParseTreeNode(std::string("const_value"),std::string(""),std::vector<int>{$1,$2}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;	
}

| minus id {
				   parseTree.push_back(ParseTreeNode(std::string("const_value"),std::string(""),std::vector<int>{$1,$2}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;		
}

| id {
				   parseTree.push_back(ParseTreeNode(std::string("const_value"),std::string(""),std::vector<int>{$1}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;	
}
| plus digits {
				   parseTree.push_back(ParseTreeNode(std::string("const_value"),std::string(""),std::vector<int>{$1,$2}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;		
}
| minus digits {
				   parseTree.push_back(ParseTreeNode(std::string("const_value"),std::string(""),std::vector<int>{$1,$2}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;	
}
| digits {
				   parseTree.push_back(ParseTreeNode(std::string("const_value"),std::string(""),std::vector<int>{$1}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;	
}
| plus num {
				   parseTree.push_back(ParseTreeNode(std::string("const_value"),std::string(""),std::vector<int>{$1}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
| minus num {
				   parseTree.push_back(ParseTreeNode(std::string("const_value"),std::string(""),std::vector<int>{$1}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
| num{
				   parseTree.push_back(ParseTreeNode(std::string("const_value"),std::string(""),std::vector<int>{$1}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
| letter {
				   parseTree.push_back(ParseTreeNode(std::string("const_value"),std::string(""),std::vector<int>{$1}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;	
};

var_declarations:{
				   parseTree.push_back(ParseTreeNode(std::string("var_declarations"),std::string(""),std::vector<int>{}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
|_var var_declaration semicolon {
				   parseTree.push_back(ParseTreeNode(std::string("var_declarations"),std::string(""),std::vector<int>{$1,$2,$3}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;	
}
| _var error semicolon{
					lParseError("变量声明存在语法错误",@3);
					}
| _var var_declaration error semicolon{
					lParseError("变量声明存在语法错误",@3);
					}
;
var_declaration: idlist colon type{
				   parseTree.push_back(ParseTreeNode(std::string("var_declaration"),std::string(""),std::vector<int>{$1,$2,$3}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
| var_declaration semicolon idlist colon type{
				   parseTree.push_back(ParseTreeNode(std::string("var_declaration"),std::string(""),std::vector<int>{$1,$2,$3,$4,$5}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   parseTree[$4].setParent(parseTree.size() - 1);
				   parseTree[$5].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}

| error semicolon idlist colon type{
					lParseError("变量声明存在语法错误",@2);
					}
;

subprogram_declarations:  {
				   parseTree.push_back(ParseTreeNode(std::string("subprogram_declarations"),std::string(""),std::vector<int>{}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;	
}
| subprogram_declarations subprogram semicolon{
				   parseTree.push_back(ParseTreeNode(std::string("subprogram_declarations"),std::string(""),std::vector<int>{$1,$2,$3}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
| subprogram_declarations error semicolon{
					lParseError("子程序或子函数语法错误",@3);
					}
;
subprogram: subprogram_head semicolon subprogram_body{
				   parseTree.push_back(ParseTreeNode(std::string("subprogram"),std::string(""),std::vector<int>{$1,$2,$3}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;		
}
| error semicolon subprogram_body{
					lParseError("子函数头部存在语法错误",@2);
					}
;
subprogram_head : procedure id formal_parameter {
					parseTree.push_back(ParseTreeNode(std::string("subprogram_head"),std::string(""),std::vector<int>{$2,$3}));
					//记录指向本节点的指针
					$$ = parseTree.size() - 1;
					//为子节点设置父节点指针
					parseTree[$2].setParent(parseTree.size() - 1);
					parseTree[$3].setParent(parseTree.size() - 1);
					//设置根节点，仅最上层规则需要 
					parseTreeRoot = parseTree.size() - 1;	
}
| function id formal_parameter colon simple_type{
				   parseTree.push_back(ParseTreeNode(std::string("subprogram_head"),std::string(""),std::vector<int>{$1,$2,$3,$4,$5}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   parseTree[$4].setParent(parseTree.size() - 1);
				   parseTree[$5].setParent(parseTree.size() - 1);
}
;
formal_parameter : {
				   parseTree.push_back(ParseTreeNode(std::string("formal_parameter"),std::string(""),std::vector<int>{}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
| leftB parameter_list rightB{
				   parseTree.push_back(ParseTreeNode(std::string("formal_parameter"),std::string(""),std::vector<int>{$1,$2,$3}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
| leftB error rightB{
					lParseError("传入参数缺失或语法错误",@1);
					}
| leftB parameter_list error rightB{
					lParseError("传入参数缺失或语法错误",@2);
					}
;
parameter_list : parameter_list semicolon parameter{
				   parseTree.push_back(ParseTreeNode(std::string("parameter_list"),std::string(""),std::vector<int>{$1,$2,$3}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
| parameter {
				   parseTree.push_back(ParseTreeNode(std::string("parameter_list"),std::string(""),std::vector<int>{$1}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
| error semicolon parameter{
					lParseError("分号前传入参数语法错误",@2);
					}
/*| parameter_list semicolon error{
					lParseError("分号后传入参数语法错误",@2);
					}
| error semicolon error{
					lParseError("传入参数缺失或语法错误",@2);
					}*/
;
parameter : var_parameter{
				   parseTree.push_back(ParseTreeNode(std::string("parameter"),std::string(""),std::vector<int>{$1}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
| value_parameter {
				   parseTree.push_back(ParseTreeNode(std::string("parameter"),std::string(""),std::vector<int>{$1}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
};
var_parameter : _var value_parameter{
				   parseTree.push_back(ParseTreeNode(std::string("var_parameter"),std::string(""),std::vector<int>{$1,$2}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;	
}
;
value_parameter : idlist colon simple_type {
				   parseTree.push_back(ParseTreeNode(std::string("value_parameter"),std::string(""),std::vector<int>{$1,$2,$3}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
;
subprogram_body : const_declarations var_declarations compound_statement{
				   parseTree.push_back(ParseTreeNode(std::string("subprogram_body"),std::string(""),std::vector<int>{$1,$2,$3}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
};

compound_statement: BEGINTOK statement_list ENDTOK{
				   parseTree.push_back(ParseTreeNode(std::string("compound_statement"),std::string(""),std::vector<int>{$2}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$2].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
| BEGINTOK error ENDTOK{
					lParseError("缺失函数体或函数体存在语法错误",@$);
					}
| BEGINTOK statement_list error ENDTOK{
					lParseError("缺失函数体或函数体存在语法错误",@$);
					}
;
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
}
| error semicolon statement{
					lParseError("分号前语句存在语法错误",@2);
					}
| statement_list error semicolon statement{
					lParseError("分号前语句存在语法错误",@3);
					}
;
statement: {
				   parseTree.push_back(ParseTreeNode(std::string("statement"),std::string(""),std::vector<int>{}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
| variable assignop expression{
				   parseTree.push_back(ParseTreeNode(std::string("statement"),std::string(""),std::vector<int>{$1,$2,$3}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
| procedure_call {
				   parseTree.push_back(ParseTreeNode(std::string("statement"),std::string(""),std::vector<int>{$1}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
| compound_statement {
				   parseTree.push_back(ParseTreeNode(std::string("statement"),std::string(""),std::vector<int>{$1}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
| _if expression _then statement else_part{
				   parseTree.push_back(ParseTreeNode(std::string("statement"),std::string(""),std::vector<int>{$1,$2,$3,$4,$5}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   parseTree[$4].setParent(parseTree.size() - 1);
				   parseTree[$5].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
| _if error _then statement else_part{
					lParseError("if后缺少表达式或表达式存在语法错误",@1);
					}
| _for id assignop expression _to expression _do statement{
				   parseTree.push_back(ParseTreeNode(std::string("statement"),std::string(""),std::vector<int>{$1,$2,$3,$4,$5,$6,$7,$8}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   parseTree[$4].setParent(parseTree.size() - 1);
				   parseTree[$5].setParent(parseTree.size() - 1);
				   parseTree[$6].setParent(parseTree.size() - 1);
				   parseTree[$7].setParent(parseTree.size() - 1);
				   parseTree[$8].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
| _for error _to expression _do statement{
					lParseError("for循环条件表达式语法错误",@1);
					}
| _for id assignop expression _to error _do statement{
					lParseError("for循环缺少终止条件表达式",@5);
					}
| _for id assignop expression _to expression _do error{
					lParseError("for循环语句存在语法错误",@7);
					}
| _while expression _do statement{
				   parseTree.push_back(ParseTreeNode(std::string("statement"),std::string(""),std::vector<int>{$1,$2,$3,$4}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   parseTree[$4].setParent(parseTree.size() - 1);
}
| _while error _do statement{
					lParseError("while后表达式缺失或存在错误",@1);
					}
;
else_part : {
				   parseTree.push_back(ParseTreeNode(std::string("else_part"),std::string(""),std::vector<int>{}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
| _else statement{
				   parseTree.push_back(ParseTreeNode(std::string("else_part"),std::string(""),std::vector<int>{$1,$2}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
};
procedure_call : id{
				   parseTree.push_back(ParseTreeNode(std::string("procedure_call"),std::string(""),std::vector<int>{$1}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);				
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
| id leftB expression_list rightB{
				   parseTree.push_back(ParseTreeNode(std::string("procedure_call"),std::string(""),std::vector<int>{$1,$2,$3,$4}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   parseTree[$4].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
| id leftB error rightB{
					lParseError("函数调用参数格式存在语法错误",@2);
					}

;
variable : id id_varpart{
				   parseTree.push_back(ParseTreeNode(std::string("variable"),std::string(""),std::vector<int>{$1,$2}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
;
id_varpart: {
				   parseTree.push_back(ParseTreeNode(std::string("id_varpart"),std::string(""),std::vector<int>{}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
}
|leftSB expression_list rightSB{
				   parseTree.push_back(ParseTreeNode(std::string("id_varpart"),std::string(""),std::vector<int>{$1,$2,$3}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
}

| leftSB error rightSB{
					lParseError("数组语法格式错误",@1);
					}
| leftSB expression_list error rightSB{
					lParseError("数组语法格式错误",@1);
					}
| leftSB expression_list error{
					lParseError("数组语法格式错误",@1);
					}
;
expression_list : expression_list comma expression {
				   parseTree.push_back(ParseTreeNode(std::string("expression_list"),std::string(""),std::vector<int>{$1,$2,$3}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
| error comma expression{
					lParseError("逗号前内容存在语法错误",@2);
					}
| expression{
				   parseTree.push_back(ParseTreeNode(std::string("expression_list"),std::string(""),std::vector<int>{$1}));
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
}
| simple_expression assign simple_expression{
				   parseTree.push_back(ParseTreeNode(std::string("expression"),std::string(""),std::vector<int>{$1,$2,$3}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;		
}
| simple_expression noequal simple_expression{
				   parseTree.push_back(ParseTreeNode(std::string("expression"),std::string(""),std::vector<int>{$1,$2,$3}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
| simple_expression GE simple_expression{
				   parseTree.push_back(ParseTreeNode(std::string("expression"),std::string(""),std::vector<int>{$1,$2,$3}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
| simple_expression GT simple_expression{
				   parseTree.push_back(ParseTreeNode(std::string("expression"),std::string(""),std::vector<int>{$1,$2,$3}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
| simple_expression LE simple_expression{
				   parseTree.push_back(ParseTreeNode(std::string("expression"),std::string(""),std::vector<int>{$1,$2,$3}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
| simple_expression LT simple_expression{
				   parseTree.push_back(ParseTreeNode(std::string("expression"),std::string(""),std::vector<int>{$1,$2,$3}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
;
simple_expression: simple_expression plus term {
				   parseTree.push_back(ParseTreeNode(std::string("simple_expression"),std::string(""),std::vector<int>{$1,$2,$3}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
| simple_expression minus term {
				   parseTree.push_back(ParseTreeNode(std::string("simple_expression"),std::string(""),std::vector<int>{$1,$2,$3}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
| simple_expression _or term {
				   parseTree.push_back(ParseTreeNode(std::string("simple_expression"),std::string(""),std::vector<int>{$1,$2,$3}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
|term{
				   parseTree.push_back(ParseTreeNode(std::string("simple_expression"),std::string(""),std::vector<int>{$1}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
//| simple_expression error 
;
term: term multiply factor {
				   parseTree.push_back(ParseTreeNode(std::string("term"),std::string(""),std::vector<int>{$1,$2,$3}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
|term divide factor {
				   parseTree.push_back(ParseTreeNode(std::string("term"),std::string(""),std::vector<int>{$1,$2,$3}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
|term _div factor {
				   parseTree.push_back(ParseTreeNode(std::string("term"),std::string(""),std::vector<int>{$1,$2,$3}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
|term _mod factor {
				   parseTree.push_back(ParseTreeNode(std::string("term"),std::string(""),std::vector<int>{$1,$2,$3}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
|term _and factor {
				   parseTree.push_back(ParseTreeNode(std::string("term"),std::string(""),std::vector<int>{$1,$2,$3}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
|factor{
				   parseTree.push_back(ParseTreeNode(std::string("term"),std::string(""),std::vector<int>{$1}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
};
factor: num{
				   parseTree.push_back(ParseTreeNode(std::string("factor"),std::string(""),std::vector<int>{$1}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
|digits {
				   parseTree.push_back(ParseTreeNode(std::string("factor"),std::string(""),std::vector<int>{$1}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
| variable {
				   parseTree.push_back(ParseTreeNode(std::string("factor"),std::string(""),std::vector<int>{$1}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
|id leftB expression_list rightB{
				   parseTree.push_back(ParseTreeNode(std::string("factor"),std::string(""),std::vector<int>{$1,$2,$3,$4}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   parseTree[$4].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
| id leftB rightB{
					
					}
|id error leftB expression_list rightB{
					lParseError("表达式中函数调用ID格式错误",@2);
					}
|id leftB error rightB{
					lParseError("表达式中函数调用存在语法错误",@2);
					}
| id leftB expression_list error rightB{
					lParseError("表达式中函数调用存在语法错误",@3);
					}
| id leftB expression_list error {
					lParseError("表达式中函数调用缺少右括号",@3);
					}
|leftB expression rightB{
				   parseTree.push_back(ParseTreeNode(std::string("factor"),std::string(""),std::vector<int>{$1,$2,$3}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
| leftB error rightB{
					lParseError("表达式括号中存在语法错误",@1);
					}
| leftB expression error rightB{
					lParseError("表达式括号中存在语法错误",@2);
					}
| _not factor{
				   parseTree.push_back(ParseTreeNode(std::string("factor"),std::string(""),std::vector<int>{$1,$2}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   //设置根节点，仅最上层规则需要 
				   parseTreeRoot = parseTree.size() - 1;
}
| minus factor {
				   parseTree.push_back(ParseTreeNode(std::string("factor"),std::string(""),std::vector<int>{$1,$2}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
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
}
| _array leftSB period rightSB _of simple_type{
				   parseTree.push_back(ParseTreeNode(std::string("type"),std::string(""),std::vector<int>{$1,$2,$3,$4,$5,$6}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   parseTree[$4].setParent(parseTree.size() - 1);
				   parseTree[$5].setParent(parseTree.size() - 1);
				   parseTree[$6].setParent(parseTree.size() - 1);
}

| _array leftSB error rightSB _of simple_type{
					lParseError("数组参数存在语法错误",@2);
					}
;

period : period comma digits _range digits{
				   parseTree.push_back(ParseTreeNode(std::string("period"),std::string(""),std::vector<int>{$1,$2,$3,$4,$5}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   parseTree[$4].setParent(parseTree.size() - 1);
				   parseTree[$5].setParent(parseTree.size() - 1);
}
| error comma digits _range digits{
					lParseError("数组参数存在语法错误",@2);
					}

| digits _range digits{
				   parseTree.push_back(ParseTreeNode(std::string("period"),std::string(""),std::vector<int>{$1,$2,$3}));
				   //记录指向本节点的指针
				   $$ = parseTree.size() - 1;
				   //为子节点设置父节点指针
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
}
;


%%
void ParseError(std::string msg,int line)
{
	std::cout<< "Parse errors ("<<msg<<") : "<< " in line "<< line <<std::endl;
}

void lParseError(std::string msg,YYLTYPE t)
{
	std::cout<< "Parse errors ("<<msg<<") : "<< " in line"<< t.first_line <<" - line"<<t.last_line;
	std::cout<< " and column"<<t.first_column<<" -column"<<t.last_column<<std::endl;
}

int main(int argc, char* argv[]) 
{
	std::fstream f1,f2;
	if(argc > 1)
	{
		f1.open(argv[1],std::fstream::in);
		std::string filename = std::string(argv[1]);
		std::string filenameCopy = filename + "Copy";
		f2.open(filenameCopy.c_str(),std::fstream::out);
		char ch;
		while(f1.get(ch))
		{
			if(ch >= 'A' && ch <= 'Z')
			{
				ch += 32;
			}
			f2.put(ch);
		}
		f1.close();
		f2.close();
		yyin = fopen(filenameCopy.c_str(),"r");
		yyparse();
		if(parseNum==0)
			deal(filename);
		else
			std::cout<<"存在"<<parseNum<<"个语法错误。"<<std::endl;
	}
	else
	{
		std::cout<<"error:未提供输入文件"<<std::endl;
	}
	return 0;
}

void yyerror(const char* s) {
	parseNum++;
	fprintf(stderr, "Parse error: %s in line %d\n", s,yylloc.first_line);
	//exit(1);
}
