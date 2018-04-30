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
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
					}
| error semicolon program_body{
					lParseError("ȱ��program head �� ����ͷ���д���",@2);
					}
| program_head semicolon error{
					lParseError("ȱ��program body �� ���������д���",@2);
					}
| program_head error program_body{
					lParseError("����ͷ����ֺ�ȱʧ",@1);
					}
;


program_head: program id leftB idlist rightB	
				   {
				   parseTree.push_back(ParseTreeNode(std::string("program_head"),std::string(""),std::vector<int>{$2,$3,$4,$5}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   parseTree[$4].setParent(parseTree.size() - 1);
				   parseTree[$5].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
				   }
| program id error idlist rightB{
					lParseError("idǰȱ��������",@4);
					}
| program id leftB idlist error{
					lParseError("id��ȱ��������",@4);
					}
| error id leftB idlist rightB{
					lParseError("ȱ�١�program���ֶ�",@2);
					}
| program error leftB idlist rightB{
					lParseError("������ǰȱ������������",@3);
					}
| program id leftB error rightB{
					lParseError("ȱ���������",@3);
					}
;
idlist: idlist comma id	{
				   parseTree.push_back(ParseTreeNode(std::string("idlist"),std::string(""),std::vector<int>{$1,$2,$3}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
				   }
| id {
				   parseTree.push_back(ParseTreeNode(std::string("idlist"),std::string(""),std::vector<int>{$1}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[$1].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
| idlist comma	error	{
					lParseError("�����ֵ",@2);
					}
;
program_body: const_declarations var_declarations subprogram_declarations compound_statement{
				   parseTree.push_back(ParseTreeNode(std::string("program_body"),std::string(""),std::vector<int>{$1,$2,$3,$4}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   parseTree[$4].setParent(parseTree.size() - 1);
}
;

const_declarations: {
				   parseTree.push_back(ParseTreeNode(std::string("const_declarations"),std::string(""),std::vector<int>{}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
} 
| _const const_declaration semicolon {				   
				   parseTree.push_back(ParseTreeNode(std::string("const_declarations"),std::string(""),std::vector<int>{$1,$2}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
				   } 
| error const_declaration semicolon
					{
					lParseError("�ڳ�������ǰȱ�١�const���ֶ�",@2);
					}
| _const const_declaration error{
					lParseError("������������ȱ�ٷֺ�",@2);
					}
| _const error{
					lParseError("��const֮��ȱ�ٳ�����������ִ���",@1);
					}
;
const_declaration: const_declaration semicolon id assign const_value{
				   parseTree.push_back(ParseTreeNode(std::string("const_declaration"),std::string(""),std::vector<int>{$1,$2,$3,$4,$5}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   parseTree[$4].setParent(parseTree.size() - 1);
				   parseTree[$5].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
| const_declaration error id assign const_value{
					lParseError("��������ȱ�ٷֺ�",@1);
					}
| const_declaration semicolon error assign const_value{
					lParseError("��������idȱʧ",@4);
					}
| const_declaration semicolon id assign error{
					lParseError("��������ȱʧ����ֵ",@4);
					}
| const_declaration semicolon id error const_value{
					lParseError("�����������ں�ȱʧ",@3);
					}
| error semicolon id assign const_value{
					lParseError("�ֺŶ����������ȱʧ",@2);
					}
| error semicolon{
					lParseError("�ֺŶ��࣬const�ṹȱʧ",@2);
					}
| const_declaration semicolon error{
					lParseError("�ֺŶ����������ȱʧ",@2);
					}
| id assign const_value{
				   parseTree.push_back(ParseTreeNode(std::string("const_declaration"),std::string(""),std::vector<int>{$1,$2,$3}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;	
}
| error assign const_value{
					lParseError("��������ȱʧID",@2);
					}
| id assign error{
					lParseError("��������ȱʧ��ֵ",@2);
					}
| id error const_value{
					lParseError("��������ȱʧ�Ⱥ�",@1);
					}
;
const_value : plus id{
				   parseTree.push_back(ParseTreeNode(std::string("const_value"),std::string(""),std::vector<int>{$1,$2}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;	
}
| plus error{
					lParseError("ȱʧID��������С��",@1);
					}
| minus id {
				   parseTree.push_back(ParseTreeNode(std::string("const_value"),std::string(""),std::vector<int>{$1,$2}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;		
}
| minus error{
					lParseError("ȱʧID��������С��",@1);
					}
| id {
				   parseTree.push_back(ParseTreeNode(std::string("const_value"),std::string(""),std::vector<int>{$1}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[$1].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;	
}
| plus digits {
				   parseTree.push_back(ParseTreeNode(std::string("const_value"),std::string(""),std::vector<int>{$1,$2}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;		
}
| minus digits {
				   parseTree.push_back(ParseTreeNode(std::string("const_value"),std::string(""),std::vector<int>{$1,$2}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;	
}
| digits {
				   parseTree.push_back(ParseTreeNode(std::string("const_value"),std::string(""),std::vector<int>{$1}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[$1].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;	
}
| plus num {
				   parseTree.push_back(ParseTreeNode(std::string("const_value"),std::string(""),std::vector<int>{$1}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[$1].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
| minus num {
				   parseTree.push_back(ParseTreeNode(std::string("const_value"),std::string(""),std::vector<int>{$1}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[$1].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
| num{
				   parseTree.push_back(ParseTreeNode(std::string("const_value"),std::string(""),std::vector<int>{$1}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[$1].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
| letter {
				   parseTree.push_back(ParseTreeNode(std::string("const_value"),std::string(""),std::vector<int>{$1}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[$1].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;	
};

var_declarations:{
				   parseTree.push_back(ParseTreeNode(std::string("var_declarations"),std::string(""),std::vector<int>{}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
|_var var_declaration semicolon {
				   parseTree.push_back(ParseTreeNode(std::string("var_declarations"),std::string(""),std::vector<int>{$1,$2,$3}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;	
}
| error var_declaration semicolon
					{
					lParseError("�ڱ�������ǰȱ�١�var���ֶ�",@2);
					}
| _var var_declaration error{
					lParseError("Error in Variable declaration",@2);
					}
| _var error {
					lParseError("��var֮��ȱ�ٱ����������߳��ִ���",@1);
					}
;
var_declaration: idlist colon type{
				   parseTree.push_back(ParseTreeNode(std::string("var_declaration"),std::string(""),std::vector<int>{$1,$2,$3}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
| error colon type{
					lParseError("��ð��֮ǰȱ��ID",@2);

					}
| idlist error type{
					lParseError("��ID֮��ȱ��ð��",@1);
					}
| idlist colon error{
					lParseError("��ð��֮��ȱ�ٱ�������",@2);
					}
| var_declaration semicolon idlist colon type{
				   parseTree.push_back(ParseTreeNode(std::string("var_declaration"),std::string(""),std::vector<int>{$1,$2,$3,$4,$5}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   parseTree[$4].setParent(parseTree.size() - 1);
				   parseTree[$5].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
| var_declaration error idlist colon type{
					lParseError("�ڱ�������֮��ȱʧ�ֺ�",@1);
					}
| var_declaration semicolon error colon type{
					lParseError("�ֺź�ȱ��ID",@2);
					}
| var_declaration semicolon idlist error type{
					lParseError("���������ȱ��ð��",@3);
					}
| var_declaration semicolon idlist colon error{
					lParseError("���������ȱ����������",@4);
					}
| error semicolon idlist colon type{
					lParseError("�ֺ������ȱ�ٱ�������",@2);
					}
| var_declaration semicolon error{
					lParseError("�ֺ������ȱ�ٱ�������",@2);
					}
;

subprogram_declarations:  {
				   parseTree.push_back(ParseTreeNode(std::string("subprogram_declarations"),std::string(""),std::vector<int>{}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;	
}
| subprogram_declarations subprogram semicolon{
				   parseTree.push_back(ParseTreeNode(std::string("subprogram_declarations"),std::string(""),std::vector<int>{$1,$2,$3}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
| subprogram_declarations error semicolon{
					lParseError("�ֺ������ȱ���ӳ���",@2);
					}
| subprogram_declarations subprogram error{
					lParseError("�ӳ������ȱ�ٷֺ�",@2);
					}
;
subprogram: subprogram_head semicolon subprogram_body{
				   parseTree.push_back(ParseTreeNode(std::string("subprogram"),std::string(""),std::vector<int>{$1,$2,$3}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;		
}
| error semicolon subprogram_body{
					lParseError("ȱ���Ӻ���ͷ�� �� �Ӻ���ͷ���д���",@2);
					}
| subprogram_head semicolon error{
					lParseError("ȱ���Ӻ������� �� �Ӻ��������д���",@2);
					}
| subprogram_head error subprogram_body{
					lParseError("�Ӻ���ͷ����ֺ�ȱʧ",@1);
					}
;
subprogram_head : procedure id formal_parameter {
					parseTree.push_back(ParseTreeNode(std::string("subprogram_head"),std::string(""),std::vector<int>{$2,$3}));
					//��¼ָ�򱾽ڵ��ָ��
					$$ = parseTree.size() - 1;
					//Ϊ�ӽڵ����ø��ڵ�ָ��
					parseTree[$2].setParent(parseTree.size() - 1);
					parseTree[$3].setParent(parseTree.size() - 1);
					//���ø��ڵ㣬�����ϲ������Ҫ 
					parseTreeRoot = parseTree.size() - 1;	
}
| function id formal_parameter colon simple_type{
					parseTree.push_back(ParseTreeNode(std::string("subprogram_head"),std::string(""),std::vector<int>{$1,$2,$3,$4,$5}));
					//��¼ָ�򱾽ڵ��ָ��
					$$ = parseTree.size() - 1;
					//Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   parseTree[$4].setParent(parseTree.size() - 1);
				   parseTree[$5].setParent(parseTree.size() - 1);
}
| error id formal_parameter{
					lParseError("ȱʧ��procedure���ֶ�",@2);
					}
| procedure error formal_parameter{
					lParseError("�ӹ���ȱʧID",@3);
					}
| procedure id error{
					lParseError("�ӹ��̴����������",@2);
					}
| procedure error{
					lParseError("�ӹ����д���",@1);
					}
| error id formal_parameter colon simple_type{
					lParseError("ȱʧ��function���ֶ�",@2);
					}
| function error formal_parameter colon simple_type{
					lParseError("�Ӻ���ȱʧID",@3);
					}
| function id error colon simple_type{
					lParseError("�Ӻ��������������",@2);
					}
| function id formal_parameter error simple_type{
					lParseError("�Ӻ�������ȱʧð��",@3);
					}
| function id formal_parameter colon error{
					lParseError("�Ӻ�������ȱʧ����",@4);
					}
| function id formal_parameter error{
					lParseError("�Ӻ�������ȱʧ����ֵ����",@3);
					}
;
formal_parameter : {
				   parseTree.push_back(ParseTreeNode(std::string("formal_parameter"),std::string(""),std::vector<int>{}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
| leftB parameter_list rightB{
				   parseTree.push_back(ParseTreeNode(std::string("formal_parameter"),std::string(""),std::vector<int>{$1,$2,$3}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
| error parameter_list rightB{
					lParseError("��������ȱʧ������",@2);
					}
| leftB parameter_list error{
					lParseError("��������ȱʧ������",@2);
					}
| leftB error rightB{
					lParseError("�������ȱʧ���﷨����",@1);
					}
;
parameter_list : parameter_list semicolon parameter{
				   parseTree.push_back(ParseTreeNode(std::string("parameter_list"),std::string(""),std::vector<int>{$1,$2,$3}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
| parameter {
				   parseTree.push_back(ParseTreeNode(std::string("parameter_list"),std::string(""),std::vector<int>{$1}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[$1].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
| error semicolon parameter{
					lParseError("�ֺ�ǰ��������﷨����",@2);
					}
| parameter_list error parameter{
					lParseError("�������ȱʧ�ֺ�",@1);
					}
| parameter_list semicolon error{
					lParseError("�ֺź�������﷨����",@2);
					}
| error{
					lParseError("��������﷨����",@$);
					}
;
parameter : var_parameter{
				   parseTree.push_back(ParseTreeNode(std::string("parameter"),std::string(""),std::vector<int>{$1}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[$1].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
| value_parameter {
				   parseTree.push_back(ParseTreeNode(std::string("parameter"),std::string(""),std::vector<int>{$1}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[$1].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
};
var_parameter : _var value_parameter{
				   parseTree.push_back(ParseTreeNode(std::string("var_parameter"),std::string(""),std::vector<int>{$1,$2}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;	
}
| _var error{
					lParseError("���õ����﷨����",@1);
					}

;
value_parameter : idlist colon simple_type {
				   parseTree.push_back(ParseTreeNode(std::string("value_parameter"),std::string(""),std::vector<int>{$1,$2,$3}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
| error colon simple_type{
					lParseError("��������ȱʧID",@2);
					}
| idlist error simple_type{
					lParseError("��������ȱʧð��",@1);
					}
| idlist colon error{
					lParseError("��������ȱʧ��������",@2);
					}
;
subprogram_body : const_declarations var_declarations compound_statement{
				   parseTree.push_back(ParseTreeNode(std::string("subprogram_body"),std::string(""),std::vector<int>{$1,$2,$3}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
};

compound_statement: BEGINTOK statement_list ENDTOK{
				   parseTree.push_back(ParseTreeNode(std::string("compound_statement"),std::string(""),std::vector<int>{$2}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[$2].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
| error statement_list ENDTOK{
					lParseError("ȱʧbegin",@2);
					}
| BEGINTOK error ENDTOK{
					lParseError("ȱʧ���������������﷨����",@$);
					}
| BEGINTOK statement_list error{
					lParseError("ȱʧend",@2);
					}
;
statement_list:  statement_list semicolon statement {
				   parseTree.push_back(ParseTreeNode(std::string("statement_list"),std::string(""),std::vector<int>{$1,$2,$3}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
|statement{
				   parseTree.push_back(ParseTreeNode(std::string("statement_list"),std::string(""),std::vector<int>{$1}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[$1].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
| statement_list error statement{
					lParseError("���ȱʧ�ֺ�",@1);
					}
| error semicolon statement{
					lParseError("�ֺ�ǰ�������﷨����",@2);
					}
| statement_list semicolon error{
					lParseError("�ֺź��������﷨����",@2);
					}
;
statement: {
				   parseTree.push_back(ParseTreeNode(std::string("statement"),std::string(""),std::vector<int>{}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
| variable assignop expression{
				   parseTree.push_back(ParseTreeNode(std::string("statement"),std::string(""),std::vector<int>{$1,$2,$3}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
| error assignop expression{
					lParseError("����ȱʧ������﷨����",@2);
					}
| variable error expression{
					lParseError("������ȱʧ:=",@1);
					}
| variable assignop error{
					lParseError("���ʽȱʧ������﷨����",@2);
					}
| procedure_call {
				   parseTree.push_back(ParseTreeNode(std::string("statement"),std::string(""),std::vector<int>{$1}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[$1].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
| compound_statement {
				   parseTree.push_back(ParseTreeNode(std::string("statement"),std::string(""),std::vector<int>{$1}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[$1].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
| _if expression _then statement else_part{
				   parseTree.push_back(ParseTreeNode(std::string("statement"),std::string(""),std::vector<int>{$1,$2,$3,$4,$5}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   parseTree[$4].setParent(parseTree.size() - 1);
				   parseTree[$5].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
| error expression _then statement else_part{
					lParseError("ȱ��if",@2);
					}
| _if error _then statement else_part{
					lParseError("if��ȱ�ٱ��ʽ����ʽ�����﷨����",@1);
					}
| _if expression error statement else_part{
					lParseError("ȱ��then",@2);
					}
| _if expression _then error else_part{
					lParseError("then��ȱ�ٱ��ʽ����ʽ�����﷨����",@3);
					}
| _if expression _then statement error{
					lParseError("else ���ֱ��ʽ�����﷨����",@4);
					}
| _for id assignop expression _to expression _do statement{
				   parseTree.push_back(ParseTreeNode(std::string("statement"),std::string(""),std::vector<int>{$1,$2,$3,$4,$5,$6,$7,$8}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   parseTree[$4].setParent(parseTree.size() - 1);
				   parseTree[$5].setParent(parseTree.size() - 1);
				   parseTree[$6].setParent(parseTree.size() - 1);
				   parseTree[$7].setParent(parseTree.size() - 1);
				   parseTree[$8].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
| error id assignop expression _to expression _do statement{
					lParseError("ȱ��for",@2);
					}
| _for error assignop expression _to expression _do statement{
					lParseError("ȱ��ID",@1);
					}
| _for id error expression _to expression _do statement{
					lParseError("ȱ��=",@2);
					}
| _for id assignop error _to expression _do statement{
					lParseError("����ȱ�ٱ��ʽ",@3);
					}
| _for error _to expression _do statement{
					lParseError("�������ʽ�﷨����",@1);
					}
| _for id assignop expression error expression _do statement{
					lParseError("ȱ��to",@4);
					}
| _for id assignop expression _to error _do statement{
					lParseError("ȱ����ֹ�������ʽ",@5);
					}
| _for id assignop expression _to expression error statement{
					lParseError("ȱ��do",@6);
					}
| _for id assignop expression _to expression _do error{
					lParseError("ȱ��ִ������ִ���������﷨����",@7);
					}
| _while expression _do statement{
				   parseTree.push_back(ParseTreeNode(std::string("statement"),std::string(""),std::vector<int>{$1,$2,$3,$4}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   parseTree[$4].setParent(parseTree.size() - 1);
}
| error expression _do statement{
					lParseError("ȱ��while",@2);
					}
| _while error _do statement{
					lParseError("while����ʽȱʧ����ڴ���",@1);
					}
| _while expression error statement{
					lParseError("ȱ��do",@2);
					}
| _while expression _do error{
					lParseError("do����ʽȱʧ����ڴ���",@3);
					}
;
else_part : {
				   parseTree.push_back(ParseTreeNode(std::string("else_part"),std::string(""),std::vector<int>{}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
| _else statement{
				   parseTree.push_back(ParseTreeNode(std::string("else_part"),std::string(""),std::vector<int>{$1,$2}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
};
| _else error{
					lParseError("else����ʽȱʧ������﷨����",@1);
					}
procedure_call : id{
				   parseTree.push_back(ParseTreeNode(std::string("procedure_call"),std::string(""),std::vector<int>{$1}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[$1].setParent(parseTree.size() - 1);				
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
| id leftB expression_list rightB{
				   parseTree.push_back(ParseTreeNode(std::string("procedure_call"),std::string(""),std::vector<int>{$1,$2,$3,$4}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   parseTree[$4].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
| error leftB expression_list rightB{
					lParseError("��������ȱʧ������",@2);
					}
| id error expression_list rightB{
					lParseError("��������ȱʧ������",@1);
					}
| id leftB error rightB{
					lParseError("�������ò�����ʽ�����﷨����",@2);
					}
| id leftB expression_list error{
					lParseError("��������ȱʧ������",@3);
					}
;
variable : id id_varpart{
				   parseTree.push_back(ParseTreeNode(std::string("variable"),std::string(""),std::vector<int>{$1,$2}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
| id error{
					lParseError("�����﷨��ʽ����",@1);
					}
;
id_varpart: {
				   parseTree.push_back(ParseTreeNode(std::string("id_varpart"),std::string(""),std::vector<int>{}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
}
|leftSB expression_list rightSB{
				   parseTree.push_back(ParseTreeNode(std::string("id_varpart"),std::string(""),std::vector<int>{$1,$2,$3}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
}
|error expression_list rightSB{
					lParseError("ȱ��[",@2);
					}
|leftSB error rightSB{
					lParseError("�����﷨��ʽ����",@1);
					}
|leftSB expression_list error{
					lParseError("ȱ��]",@2);
					}
;
expression_list : expression_list comma expression {
				   parseTree.push_back(ParseTreeNode(std::string("expression_list"),std::string(""),std::vector<int>{$1,$2,$3}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
| error comma expression{
					lParseError("����ǰ�������ַǷ�",@2);
					}
| expression_list comma error{
					lParseError("���ź��������ַǷ�",@2);
					}
| expression{
				   parseTree.push_back(ParseTreeNode(std::string("expression_list"),std::string(""),std::vector<int>{$1}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[$1].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
};
expression: simple_expression{
				   parseTree.push_back(ParseTreeNode(std::string("expression"),std::string(""),std::vector<int>{$1}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[$1].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
| simple_expression assign simple_expression{
				   parseTree.push_back(ParseTreeNode(std::string("expression"),std::string(""),std::vector<int>{$1,$2,$3}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;		
}
| error assign simple_expression{
					lParseError("=ǰ���ʽ�Ƿ�",@2);
					}
| simple_expression assign error{
					lParseError("=����ʽ�Ƿ�",@2);
					}
| simple_expression noequal simple_expression{
				   parseTree.push_back(ParseTreeNode(std::string("expression"),std::string(""),std::vector<int>{$1,$2,$3}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
| error noequal simple_expression{
					lParseError("<>ǰ���ʽ�Ƿ�",@2);
					}
| simple_expression noequal error{
					lParseError("<>����ʽ�Ƿ�",@2);
					}
| simple_expression GE simple_expression{
				   parseTree.push_back(ParseTreeNode(std::string("expression"),std::string(""),std::vector<int>{$1,$2,$3}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
| error GE simple_expression{
					lParseError(">=ǰ���ʽ�Ƿ�",@2);
					}
| simple_expression GE error{
					lParseError(">=����ʽ�Ƿ�",@2);
					}
| simple_expression GT simple_expression{
				   parseTree.push_back(ParseTreeNode(std::string("expression"),std::string(""),std::vector<int>{$1,$2,$3}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
| error GT simple_expression{
					lParseError(">ǰ���ʽ�Ƿ�",@2);
					}
| simple_expression GT error{
					lParseError(">����ʽ�Ƿ�",@2);
					}
| simple_expression LE simple_expression{
				   parseTree.push_back(ParseTreeNode(std::string("expression"),std::string(""),std::vector<int>{$1,$2,$3}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
| error LE simple_expression{
					lParseError("<=ǰ���ʽ�Ƿ�",@2);
					}
| simple_expression LE error{
					lParseError("<=����ʽ�Ƿ�",@2);
					}
| simple_expression LT simple_expression{
				   parseTree.push_back(ParseTreeNode(std::string("expression"),std::string(""),std::vector<int>{$1,$2,$3}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
| error LT simple_expression{
					lParseError("<ǰ���ʽ�Ƿ�",@2);
					}
| simple_expression LT error{
					lParseError("<����ʽ�Ƿ�",@2);
					}
| simple_expression error simple_expression{
					lParseError("�Ƿ�����",@1);
					}
;
simple_expression: simple_expression plus term {
				   parseTree.push_back(ParseTreeNode(std::string("simple_expression"),std::string(""),std::vector<int>{$1,$2,$3}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
| error plus term{
					lParseError("+ǰ���ʽ�Ƿ�",@2);
					}
| simple_expression plus error{
					lParseError("+����ʽ�Ƿ�",@2);
					}
|simple_expression minus term {
				   parseTree.push_back(ParseTreeNode(std::string("simple_expression"),std::string(""),std::vector<int>{$1,$2,$3}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
| error minus term{
					lParseError("-ǰ���ʽ�Ƿ�",@2);
					}
| simple_expression minus error{
					lParseError("-����ʽ�Ƿ�",@2);
					}
|simple_expression _or term {
				   parseTree.push_back(ParseTreeNode(std::string("simple_expression"),std::string(""),std::vector<int>{$1,$2,$3}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
| error _or term{
					lParseError("orǰ���ʽ�Ƿ�",@2);
					}
| simple_expression _or error{
					lParseError("or����ʽ�Ƿ�",@2);
					}
| simple_expression error term{
					lParseError("�Ƿ�����",@1);
					}
|term{
				   parseTree.push_back(ParseTreeNode(std::string("simple_expression"),std::string(""),std::vector<int>{$1}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[$1].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
;
term: term multiply factor {
				   parseTree.push_back(ParseTreeNode(std::string("term"),std::string(""),std::vector<int>{$1,$2,$3}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
| error multiply factor{
					lParseError("*ǰ���ʽ�Ƿ�",@2);
					}
| term multiply error{
					lParseError("*����ʽ�Ƿ�",@2);
					}
|term divide factor {
				   parseTree.push_back(ParseTreeNode(std::string("term"),std::string(""),std::vector<int>{$1,$2,$3}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
| error divide factor{
					lParseError("/ǰ���ʽ�Ƿ�",@2);
					}
| term divide error{
					lParseError("/����ʽ�Ƿ�",@2);
					}
|term _div factor {
				   parseTree.push_back(ParseTreeNode(std::string("term"),std::string(""),std::vector<int>{$1,$2,$3}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
| error _div factor{
					lParseError("divǰ���ʽ�Ƿ�",@2);
					}
| term _div error{
					lParseError("div����ʽ�Ƿ�",@2);
					}
|term _mod factor {
				   parseTree.push_back(ParseTreeNode(std::string("term"),std::string(""),std::vector<int>{$1,$2,$3}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
| error _mod factor{
					lParseError("modǰ���ʽ�Ƿ�",@2);
					}
| term _mod error{
					lParseError("mod����ʽ�Ƿ�",@2);
					}
|term _and factor {
				   parseTree.push_back(ParseTreeNode(std::string("term"),std::string(""),std::vector<int>{$1,$2,$3}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
| error _and factor{
					lParseError("andǰ���ʽ�Ƿ�",@2);
					}
| term _and error{
					lParseError("and����ʽ�Ƿ�",@2);
					}
| term error factor{
					lParseError("�Ƿ�����",@1);
					}
|factor{
				   parseTree.push_back(ParseTreeNode(std::string("term"),std::string(""),std::vector<int>{$1}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[$1].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
};
factor: num{
				   parseTree.push_back(ParseTreeNode(std::string("factor"),std::string(""),std::vector<int>{$1}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[$1].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
|digits {
				   parseTree.push_back(ParseTreeNode(std::string("factor"),std::string(""),std::vector<int>{$1}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[$1].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
| variable {
				   parseTree.push_back(ParseTreeNode(std::string("factor"),std::string(""),std::vector<int>{$1}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[$1].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
|id leftB expression_list rightB{
				   parseTree.push_back(ParseTreeNode(std::string("factor"),std::string(""),std::vector<int>{$1,$2,$3,$4}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   parseTree[$4].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
|error leftB expression_list rightB{
					lParseError("���ʽ�к�������ID��ʽ����",@2);
					}
|id error expression_list rightB{
					lParseError("���ʽ��ȱʧ������",@1);
					}
|id leftB error rightB{
					lParseError("���ʽ�к������ô����﷨����",@2);
					}
|id leftB expression_list error{
					lParseError("���ʽ�к�������ȱʧ������",@3);
					}
|leftB expression rightB{
				   parseTree.push_back(ParseTreeNode(std::string("factor"),std::string(""),std::vector<int>{$1,$2,$3}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
| error expression_list rightB{
					lParseError("���ʽ��ȱʧ������",@2);
					}
| leftB error rightB{
					lParseError("���ʽ�����д����﷨����",@1);
					}
| leftB expression_list error{
					lParseError("���ʽ��ȱʧ������",@2);
					}
| _not factor{
				   parseTree.push_back(ParseTreeNode(std::string("factor"),std::string(""),std::vector<int>{$1,$2}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
| _not error{
					lParseError("not��ȱʧ���ʽ",@1);
					}
| minus factor {
				   parseTree.push_back(ParseTreeNode(std::string("factor"),std::string(""),std::vector<int>{$1,$2}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;	
};
| minus error{
					lParseError("��-����ȱʧ���ʽ",@1);
					}
type : simple_type{
				   parseTree.push_back(ParseTreeNode(std::string("type"),std::string(""),std::vector<int>{$1}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[$1].setParent(parseTree.size() - 1);
				   //���ø��ڵ㣬�����ϲ������Ҫ 
				   parseTreeRoot = parseTree.size() - 1;
}
| _array leftSB period rightSB _of simple_type{
				   parseTree.push_back(ParseTreeNode(std::string("type"),std::string(""),std::vector<int>{$1,$2,$3,$4,$5,$6}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   parseTree[$4].setParent(parseTree.size() - 1);
				   parseTree[$5].setParent(parseTree.size() - 1);
				   parseTree[$6].setParent(parseTree.size() - 1);
}
| error leftSB period rightSB _of simple_type{
					lParseError("ȱ���ֶΡ�array��",@2);
					}
| _array error period rightSB _of simple_type{
					lParseError("ȱ��[",@1);
					}
| _array leftSB error rightSB _of simple_type{
					lParseError("���鷶Χ���������﷨����",@2);
					}
| _array leftSB period error _of simple_type{
					lParseError("ȱ��]",@3);
					}
| _array leftSB period rightSB error simple_type{
					lParseError("ȱ��of",@4);
					}
| _array leftSB period rightSB _of error{
					lParseError("ȱ����������",@5);
					}
| _array leftSB period rightSB error{
					lParseError("ȱ����������",@4);
;

period : period comma digits _range digits{
				   parseTree.push_back(ParseTreeNode(std::string("period"),std::string(""),std::vector<int>{$1,$2,$3,$4,$5}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
				   parseTree[$4].setParent(parseTree.size() - 1);
				   parseTree[$5].setParent(parseTree.size() - 1);
}
| period error digits _range digits{
					lParseError("ȱ��','",@1);
					}
| period comma error _range digits{
					lParseError("ȱ�����ֻ����ָ�ʽ����",@2);
					}
| period comma digits error digits{
					lParseError("ȱ�١�..��",@3);
					}
| period comma digits _range error{
					lParseError("ȱ�����ֻ����ָ�ʽ����",@4);
					}
| digits _range digits{
				   parseTree.push_back(ParseTreeNode(std::string("period"),std::string(""),std::vector<int>{$1,$2,$3}));
				   //��¼ָ�򱾽ڵ��ָ��
				   $$ = parseTree.size() - 1;
				   //Ϊ�ӽڵ����ø��ڵ�ָ��
				   parseTree[$1].setParent(parseTree.size() - 1);
				   parseTree[$2].setParent(parseTree.size() - 1);
				   parseTree[$3].setParent(parseTree.size() - 1);
}
| error _range digits{
					lParseError("ȱ�����ֻ����ָ�ʽ����",@2);
					}
| digits error digits{
					lParseError("ȱ�١�..��",@1);
					}
| digits _range error{
					lParseError("ȱ�����ֻ����ָ�ʽ����",@2);
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
