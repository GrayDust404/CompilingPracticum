%locations
%{

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include"parser.h"
#include"transform.h"
#include"parser.tab.h"

extern int yylex();
extern int yyparse();
extern FILE* yyin;
extern int yylineno;

void yyerror(const char* s);
std::vector<ParseTreeNode> parseTree;
void ParseError(std::string msg,int line);
void lParseError(std::string msg, YYLTYPE t);
int parseTreeRoot;
%}


%union{
	int ival;
}

%token<ival> id semicolon comma _const _var colon simple_type assignop digits assign relop plus minus letter procedure function num _array
%token<ival> multiply divide _div _mod _and _not
%token<ival> _if _then _for _else _to _do _or _of _range _while
%token<ival> noequal GE GT LE LT leftB rightB leftSB rightSB
%token  program BEGINTOK ENDTOK 
%type<ival> programstruct program_head program_body idlist type variable const_value 
%type<ival> const_declarations var_declarations const_declaration var_declaration subprogram_declarations subprogram
%type<ival> subprogram_head subprogram_body formal_parameter parameter_list parameter var_parameter value_parameter
%type<ival> compound_statement statement_list statement expression expression_list simple_expression term factor
%type<ival> procedure_call else_part id_varpart period

%start programstruct

%%

programstruct: program_head semicolon program_body{
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
| error semicolon program_body{
					lParseError("缺少program head 或 程序头部有错误",@2);
					}
| program_head semicolon error{
					lParseError("缺少program body 或 程序主体有错误",@2);
					}
| program_head error program_body{
					lParseError("程序头部后分号缺失",@1);
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
| program id error idlist rightB{
					lParseError("id前缺少左括号",@4);
					}
| program id leftB idlist error{
					lParseError("id后缺少右括号",@4);
					}
| error id leftB idlist rightB{
					lParseError("缺少‘program’字段",@2);
					}
| program error leftB idlist rightB{
					lParseError("左括号前缺少主程序名称",@3);
					}
| program id leftB error rightB{
					lParseError("缺少输入参数",@3);
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
| idlist comma	error	{
					lParseError("传入空值",@2);
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
| error const_declaration semicolon
					{
					lParseError("在常量声明前缺少‘const’字段",@2);
					}
| _const const_declaration error{
					lParseError("常量声明结束缺少分号",@2);
					}
| _const error{
					lParseError("在const之后缺少常量声明或出现错误",@1);
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
| const_declaration error id assign const_value{
					lParseError("常量声明缺少分号",@1);
					}
| const_declaration semicolon error assign const_value{
					lParseError("常量声明id缺失",@4);
					}
| const_declaration semicolon id assign error{
					lParseError("常量声明缺失变量值",@4);
					}
| const_declaration semicolon id error const_value{
					lParseError("常量声明等于号缺失",@3);
					}
| error semicolon id assign const_value{
					lParseError("分号多余或常量声明缺失",@2);
					}
| error semicolon{
					lParseError("分号多余，const结构缺失",@2);
					}
| const_declaration semicolon error{
					lParseError("分号多余或常量声明缺失",@2);
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
| error assign const_value{
					lParseError("常量声明缺失ID",@2);
					}
| id assign error{
					lParseError("常量声明缺失数值",@2);
					}
| id error const_value{
					lParseError("常量声明缺失等号",@1);
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
| plus error{
					lParseError("缺失ID或整数或小数",@1);
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
| minus error{
					lParseError("缺失ID或整数或小数",@1);
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
| error var_declaration semicolon
					{
					lParseError("在变量声明前缺少‘var’字段",@2);
					}
| _var var_declaration error{
					lParseError("Error in Variable declaration",@2);
					}
| _var error {
					lParseError("在var之后缺少变量声明或者出现错误",@1);
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
| error colon type{
					lParseError("在冒号之前缺少ID",@2);

					}
| idlist error type{
					lParseError("在ID之后缺少冒号",@1);
					}
| idlist colon error{
					lParseError("在冒号之后缺少变量类型",@2);
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
| var_declaration error idlist colon type{
					lParseError("在变量定义之后缺失分号",@1);
					}
| var_declaration semicolon error colon type{
					lParseError("分号后缺少ID",@2);
					}
| var_declaration semicolon idlist error type{
					lParseError("变量定义后缺少冒号",@3);
					}
| var_declaration semicolon idlist colon error{
					lParseError("变量定义后缺少类型声明",@4);
					}
| error semicolon idlist colon type{
					lParseError("分号冗余或缺少变量声明",@2);
					}
| var_declaration semicolon error{
					lParseError("分号冗余或缺少变量声明",@2);
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
					lParseError("分号冗余或缺少子程序",@2);
					}
| subprogram_declarations subprogram error{
					lParseError("子程序结束缺少分号",@2);
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
					lParseError("缺少子函数头部 或 子函数头部有错误",@2);
					}
| subprogram_head semicolon error{
					lParseError("缺少子函数主体 或 子函数主体有错误",@2);
					}
| subprogram_head error subprogram_body{
					lParseError("子函数头部后分号缺失",@1);
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
| error id formal_parameter{
					lParseError("缺失‘procedure’字段",@2);
					}
| procedure error formal_parameter{
					lParseError("子过程缺失ID",@3);
					}
| procedure id error{
					lParseError("子过程传入参数错误",@2);
					}
| procedure error{
					lParseError("子过程有错误",@1);
					}
| error id formal_parameter colon simple_type{
					lParseError("缺失‘function’字段",@2);
					}
| function error formal_parameter colon simple_type{
					lParseError("子函数缺失ID",@3);
					}
| function id error colon simple_type{
					lParseError("子函数传入参数错误",@2);
					}
| function id formal_parameter error simple_type{
					lParseError("子函数声明缺失冒号",@3);
					}
| function id formal_parameter colon error{
					lParseError("子函数声明缺失类型",@4);
					}
| function id formal_parameter error{
					lParseError("子函数声明缺失返回值类型",@3);
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
| error parameter_list rightB{
					lParseError("参数传入缺失左括号",@2);
					}
| leftB parameter_list error{
					lParseError("参数传入缺失右括号",@2);
					}
| leftB error rightB{
					lParseError("传入参数缺失或语法错误",@1);
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
| parameter_list error parameter{
					lParseError("传入参数缺失分号",@1);
					}
| parameter_list semicolon error{
					lParseError("分号后传入参数语法错误",@2);
					}
| error{
					lParseError("传入参数语法错误",@$);
					}
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
| _var error{
					lParseError("引用调用语法错误",@1);
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
| error colon simple_type{
					lParseError("参数传入缺失ID",@2);
					}
| idlist error simple_type{
					lParseError("参数传入缺失冒号",@1);
					}
| idlist colon error{
					lParseError("参数传入缺失变量类型",@2);
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
| error statement_list ENDTOK{
					lParseError("缺失begin",@2);
					}
| BEGINTOK error ENDTOK{
					lParseError("缺失函数体或函数体存在语法错误",@$);
					}
| BEGINTOK statement_list error{
					lParseError("缺失end",@2);
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
| statement_list error statement{
					lParseError("语句缺失分号",@1);
					}
| error semicolon statement{
					lParseError("分号前语句存在语法错误",@2);
					}
| statement_list semicolon error{
					lParseError("分号后语句存在语法错误",@2);
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
| error assignop expression{
					lParseError("变量缺失或存在语法错误",@2);
					}
| variable error expression{
					lParseError("变量后缺失:=",@1);
					}
| variable assignop error{
					lParseError("表达式缺失或存在语法错误",@2);
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
| error expression _then statement else_part{
					lParseError("缺少if",@2);
					}
| _if error _then statement else_part{
					lParseError("if后缺少表达式或表达式存在语法错误",@1);
					}
| _if expression error statement else_part{
					lParseError("缺少then",@2);
					}
| _if expression _then error else_part{
					lParseError("then后缺少表达式或表达式存在语法错误",@3);
					}
| _if expression _then statement error{
					lParseError("else 部分表达式存在语法错误",@4);
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
| error id assignop expression _to expression _do statement{
					lParseError("缺少for",@2);
					}
| _for error assignop expression _to expression _do statement{
					lParseError("缺少ID",@1);
					}
| _for id error expression _to expression _do statement{
					lParseError("缺少=",@2);
					}
| _for id assignop error _to expression _do statement{
					lParseError("条件缺少表达式",@3);
					}
| _for error _to expression _do statement{
					lParseError("条件表达式语法错误",@1);
					}
| _for id assignop expression error expression _do statement{
					lParseError("缺少to",@4);
					}
| _for id assignop expression _to error _do statement{
					lParseError("缺少终止条件表达式",@5);
					}
| _for id assignop expression _to expression error statement{
					lParseError("缺少do",@6);
					}
| _for id assignop expression _to expression _do error{
					lParseError("缺少执行语句或执行语句存在语法错误",@7);
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
| error expression _do statement{
					lParseError("缺少while",@2);
					}
| _while error _do statement{
					lParseError("while后表达式缺失或存在错误",@1);
					}
| _while expression error statement{
					lParseError("缺少do",@2);
					}
| _while expression _do error{
					lParseError("do后表达式缺失或存在错误",@3);
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
| _else error{
					lParseError("else后表达式缺失或存在语法错误",@1);
					}
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
| error leftB expression_list rightB{
					lParseError("函数调用缺失函数名",@2);
					}
| id error expression_list rightB{
					lParseError("函数调用缺失左括号",@1);
					}
| id leftB error rightB{
					lParseError("函数调用参数格式存在语法错误",@2);
					}
| id leftB expression_list error{
					lParseError("函数调用缺失右括号",@3);
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
| id error{
					lParseError("数组语法格式错误",@1);
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
|error expression_list rightSB{
					lParseError("缺少[",@2);
					}
|leftSB error rightSB{
					lParseError("数组语法格式错误",@1);
					}
|leftSB expression_list error{
					lParseError("缺少]",@2);
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
					lParseError("逗号前数组数字非法",@2);
					}
| expression_list comma error{
					lParseError("逗号后数组数字非法",@2);
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
| error assign simple_expression{
					lParseError("=前表达式非法",@2);
					}
| simple_expression assign error{
					lParseError("=后表达式非法",@2);
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
| error noequal simple_expression{
					lParseError("<>前表达式非法",@2);
					}
| simple_expression noequal error{
					lParseError("<>后表达式非法",@2);
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
| error GE simple_expression{
					lParseError(">=前表达式非法",@2);
					}
| simple_expression GE error{
					lParseError(">=后表达式非法",@2);
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
| error GT simple_expression{
					lParseError(">前表达式非法",@2);
					}
| simple_expression GT error{
					lParseError(">后表达式非法",@2);
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
| error LE simple_expression{
					lParseError("<=前表达式非法",@2);
					}
| simple_expression LE error{
					lParseError("<=后表达式非法",@2);
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
| error LT simple_expression{
					lParseError("<前表达式非法",@2);
					}
| simple_expression LT error{
					lParseError("<后表达式非法",@2);
					}
| simple_expression error simple_expression{
					lParseError("非法符号",@1);
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
| error plus term{
					lParseError("+前表达式非法",@2);
					}
| simple_expression plus error{
					lParseError("+后表达式非法",@2);
					}
|simple_expression minus term {
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
| error minus term{
					lParseError("-前表达式非法",@2);
					}
| simple_expression minus error{
					lParseError("-后表达式非法",@2);
					}
|simple_expression _or term {
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
| error _or term{
					lParseError("or前表达式非法",@2);
					}
| simple_expression _or error{
					lParseError("or后表达式非法",@2);
					}
| simple_expression error term{
					lParseError("非法符号",@1);
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
| error multiply factor{
					lParseError("*前表达式非法",@2);
					}
| term multiply error{
					lParseError("*后表达式非法",@2);
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
| error divide factor{
					lParseError("/前表达式非法",@2);
					}
| term divide error{
					lParseError("/后表达式非法",@2);
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
| error _div factor{
					lParseError("div前表达式非法",@2);
					}
| term _div error{
					lParseError("div后表达式非法",@2);
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
| error _mod factor{
					lParseError("mod前表达式非法",@2);
					}
| term _mod error{
					lParseError("mod后表达式非法",@2);
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
| error _and factor{
					lParseError("and前表达式非法",@2);
					}
| term _and error{
					lParseError("and后表达式非法",@2);
					}
| term error factor{
					lParseError("非法符号",@1);
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
|error leftB expression_list rightB{
					lParseError("表达式中函数调用ID格式错误",@2);
					}
|id error expression_list rightB{
					lParseError("表达式中缺失左括号",@1);
					}
|id leftB error rightB{
					lParseError("表达式中函数调用存在语法错误",@2);
					}
|id leftB expression_list error{
					lParseError("表达式中函数调用缺失右括号",@3);
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
| error expression_list rightB{
					lParseError("表达式中缺失左括号",@2);
					}
| leftB error rightB{
					lParseError("表达式括号中存在语法错误",@1);
					}
| leftB expression_list error{
					lParseError("表达式中缺失右括号",@2);
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
| _not error{
					lParseError("not后缺失表达式",@1);
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
| minus error{
					lParseError("‘-’后缺失表达式",@1);
					}
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
| error leftSB period rightSB _of simple_type{
					lParseError("缺少字段‘array’",@2);
					}
| _array error period rightSB _of simple_type{
					lParseError("缺少[",@1);
					}
| _array leftSB error rightSB _of simple_type{
					lParseError("数组范围声明存在语法错误",@2);
					}
| _array leftSB period error _of simple_type{
					lParseError("缺少]",@3);
					}
| _array leftSB period rightSB error simple_type{
					lParseError("缺少of",@4);
					}
| _array leftSB period rightSB _of error{
					lParseError("缺少数组类型",@5);
					}
| _array leftSB period rightSB error{
					lParseError("缺少数组类型",@4);
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
| period error digits _range digits{
					lParseError("缺少','",@1);
					}
| period comma error _range digits{
					lParseError("缺少数字或数字格式错误",@2);
					}
| period comma digits error digits{
					lParseError("缺少‘..’",@3);
					}
| period comma digits _range error{
					lParseError("缺少数字或数字格式错误",@4);
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
| error _range digits{
					lParseError("缺少数字或数字格式错误",@2);
					}
| digits error digits{
					lParseError("缺少‘..’",@1);
					}
| digits _range error{
					lParseError("缺少数字或数字格式错误",@2);
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
	yyin = fopen("test.txt","r");
	yydebug = 0;
	yyparse();
	//test();
	return 0;
}

void yyerror(const char* s) {
	//fprintf(stderr, "Parse error: %s in line %d\n", s,yylloc.first_line);
	//exit(1);
}
