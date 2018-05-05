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
	string id;	//������
	bool isRef;	//�Ƿ�������
	string varpart; //��������ȵ����
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
	vector<std::pair<int, int>> peroid;	//��ά���������½�
	vector<string> ids;		//����ά���±���ʽ
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
	string id;	//������
	vector<string> parameterlist;	//�����б�
	vector<string> parameterType;	//��������������
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
	bool isReturn;	//�Ƿ��Ƿ���ֵ���
	string leftexpression;	//����ʽ
	string rightexpression; //�ұ��ʽ
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
	string judgement;	//�ж�����
	string statement;	//��ת���
	vector<string> else_statements;	//else��ת���

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
	string start_number;	 //���
	string end_number;		 //�յ�
	string statement;//ѭ�������
	string iterator; //ѭ������
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
	vector<string> expression_list;	//����б�
};

class VarDeclarationGenerator {
public:
	VarDeclarationGenerator(vector<string> _idlist, string _type) {
		idlist = _idlist;
		type = _type;
	}
	string CodeGenerator();
private:
	string type;	//��������������,C����
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
	string type;	//const����
	string id;		//const��
	string operation;	//������
	string value;	//constֵ
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
	bool isVar;		//�Ƿ��Ǳ���
	string type;	//����,C���͵�
	vector<string> idlist;	//�����б�
};

class ProgramGenerator {
public:
	ProgramGenerator(vector<string> _statementlist, string _main_compound) {
		statementlist = _statementlist;
		main_compound = _main_compound;
	}
	string CodeGenerator();
private:
	vector<string> statementlist;	//main����֮ǰ������
	string main_compound;		//main�����ֵ�����
};
