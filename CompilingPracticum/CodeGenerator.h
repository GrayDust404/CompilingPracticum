#pragma once
#pragma once
#include<string>
#include<vector>
#include<utility>
#include<memory>
using namespace std;

class VarGenerator
{
public:
	VarGenerator(string _id, bool _isRef, string _varpart,bool _hasVarpart,bool _isfunction) {
		id = _id;
		isRef = _isRef;
		varpart = _varpart;
		hasVarpart = _hasVarpart;
		isfunction = _isfunction;
	}
	string CodeGenerator();
private:
	string id;	//变量名
	bool isRef;	//是否是引用
	string varpart; //考虑数组等的情况
	bool hasVarpart;
	bool isfunction;
};

class VarpartGenerator
{
public:
	VarpartGenerator(vector<string> _ids,vector<std::pair<int, int>> _peroid) {
		peroid = _peroid;
		ids = _ids;
	}
	string CodeGenerator();
private:
	vector<std::pair<int, int>> peroid;	//各维度数组上下界
	vector<string> ids;		//各个维度下标表达式
};

class FunctionCallGenerator
{
public:
	FunctionCallGenerator(string _id, vector<string> _parameterlist,
		vector<string> _paramentType) {
		id = _id;
		parameterlist = _parameterlist;
		parameterType = _paramentType;
	}
	string CodeGenerator();
private:
	string id;	//函数名
	vector<string> parameterlist;	//参数列表
	vector<string> parameterType;	//各个参数的类型
};

class AssignmentGenerator
{
public:
	AssignmentGenerator(bool _isReturn, string _leftexpression, string _rightexpression) {
		isReturn = _isReturn;
		leftexpression = _leftexpression;
		rightexpression = _rightexpression;
	}
	string CodeGenerator();
private:
	bool isReturn;	//是否是返回值语句
	string leftexpression;	//左表达式
	string rightexpression; //右表达式
};

class IfGenerator
{
public:
	IfGenerator(string _judgement, string _statement,vector<string> _else_statement) {
		judgement = _judgement;
		statement = _statement;
		else_statements = _else_statement;
	}
	string CodeGenerator();
private:
	string judgement;	//判断条件
	string statement;	//跳转语句
	vector<string> else_statements;	//else跳转语句

};

class ForGenerator {
public:
	ForGenerator(string _start_number,string _end_number,string _statement,string _iterator) {
		start_number = _start_number;
		end_number = _end_number;
		statement = _statement;
		iterator = _iterator;
	}
	string CodeGenerator();
private:
	string start_number;	 //起点
	string end_number;		 //终点
	string statement;//循环体语句
	string iterator; //循环变量
};

class WhileGenerator {
public:
	WhileGenerator(string _judgement,string _statement) {
		judgement = _judgement;
		statement = _statement;
	}
	string CodeGeneratot();
private:
	string judgement;
	string statement;
};

class CompoundGenerator {
public:
	CompoundGenerator(vector<string> _expression_list) {
		expression_list = _expression_list;
	}
	string CodeGenerator();
private:
	vector<string> expression_list;	//语句列表
};

class VarDeclarationGenerator {
public:
	VarDeclarationGenerator(vector<string> _idlist, string _type) {
		idlist = _idlist;
		type = _type;
	}
	string CodeGenerator();
private:
	string type;	//声明变量的类型,C类型
	vector<string> idlist;
};

class ConstDeclarationGenerator
{
public:
	ConstDeclarationGenerator(string _type, string _id, string _value, string _operation) {
		type = _type;
		id = _id;
		value = _value;
		operation = _operation;
	}
	string CodeGenerator();

private:
	string type;	//const类型
	string id;		//const名
	string operation;	//操作符
	string value;	//const值
};

class ParameterGenerator 
{
public:
	ParameterGenerator(bool _isVar,string _type, vector<string> _idlist) {
		isVar = _isVar;
		type = _type;
		idlist = _idlist;
	}
	string CodeGenerator();
private:
	bool isVar;		//是否是变量
	string type;	//类型,C类型的
	vector<string> idlist;	//参数列表
};

class ProgramGenerator {
public:
	ProgramGenerator(vector<string> _statementlist, string _main_compound) {
		statementlist = _statementlist;
		main_compound = _main_compound;
	}
	string CodeGenerator();
private:
	vector<string> statementlist;	//main函数之前的内容
	string main_compound;		//main函数种的内容
};
