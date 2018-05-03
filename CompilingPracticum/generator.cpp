#include "symbol_table.h"
#include "CodeGenerator.h"
using namespace std;
std::string ExpressionNode::codeGenerator()
{
	if (children.size() == 1)//ֻ��һ���ӽڵ�ʱ
	{
		string testEnd;//���ĩβ�Ƿ��У�
		testEnd = children[0]->codeGenerator();
		if (testEnd[testEnd.length() - 1] == ';')//���ĩβΪ;ɾ��
			testEnd.pop_back();
		return "( " + getCTypeOperation() + " "
			+ testEnd + " )";
	}
	if (children.size() == 2)//�������ӽڵ�ʱ
	{
		string testEnd1, testEnd2;//���ĩβ�Ƿ��У�
		testEnd1 = children[0]->codeGenerator();
		testEnd2 = children[1]->codeGenerator();
		if (testEnd1[testEnd1.length() - 1] == ';')//���ĩβΪ;ɾ��
			testEnd1.pop_back();
		if (testEnd2[testEnd2.length() - 1] == ';')//���ĩβΪ;ɾ��
			testEnd2.pop_back();
		return "( " + testEnd1 + " " + getCTypeOperation()
			+ " " + testEnd2 + " )";
	}
	return std::string();
}

std::string VarNode::codeGenerator()
{
	bool isfunction;
	if (scope->lookUp(id).getChildTable() != std::shared_ptr<SymbolTable>())	//�ж��Ƿ��Ǻ���
	{
		isfunction = true;
	}
	else
		isfunction = false;

	bool isRef = scope->lookUp(id).getType().checkRef();//�ж��Ƿ�Ϊ����
	string varpart;
	bool hasVarpart;
	if (children.size() == 0) {
		varpart = "";
		hasVarpart = false;
	}
	else
	{
		varpart = children[0]->codeGenerator();
		hasVarpart = true;
	}
	VarGenerator vargentator = VarGenerator(id, isRef, varpart,hasVarpart,isfunction);
	return vargentator.CodeGenerator();
}

std::string ConstNode::codeGenerator()
{
	return value;
}

std::string VarDeclarationNode::codeGenerator()
{
	vector<string> ids;
	for (int i = 0; i < idlist.size(); i++) {

		if (scope->lookUp(idlist[i]).getType().getPeroid().size() > 0) { //������
			vector<std::pair<int, int>> peroid = scope->lookUp(idlist[i]).getType().getPeroid();
			string IdPart="";//�����±�
			for (int j = 0; j < scope->lookUp(idlist[i]).getType().getPeroid().size(); j++)//��������ά������±�
			{
				IdPart = IdPart + "[" + to_string(peroid[j].second - peroid[j].first + 1) + "]";
			}
			ids.push_back(idlist[i] + IdPart);
		}
		else {		//��������
			ids.push_back(idlist[i]);
		}
	}
	VarDeclarationGenerator generator = VarDeclarationGenerator(ids, type.getCType());
	return generator.CodeGenerator();
}

std::string ConstDeclarationNode::codeGenerator()
{
	ConstDeclarationGenerator generator = ConstDeclarationGenerator(
		scope->lookUp(id).getType().getCType(), id, value, operation);
	return generator.CodeGenerator();
}

std::string AssignmentNode::codeGenerator()
{
	bool isReturn;
	if (std::string("_") + children[0]->getID() == scope->getFirstSymbol().getId())//�ж��Ƿ�Ϊreturnֵ,��
		isReturn = true;
	else					//����return
		isReturn = false;
	string leftexpression = children[0]->codeGenerator();
	string rightexpression = children[1]->codeGenerator(); //�ұ��ʽ
	AssignmentGenerator generator = AssignmentGenerator(isReturn, leftexpression, rightexpression);
	return generator.CodeGenerator();
}

std::string ForNode::codeGenerator()
{
	string start_number = children[0]->codeGenerator();//���
	string end_number = children[1]->codeGenerator(); //�յ�
	string statement = children[2]->codeGenerator();//ѭ�������
	ForGenerator generator = ForGenerator(start_number, end_number, statement);
	return generator.CodeGenerator();
}

std::string IfNode::codeGenerator()
{
	string judgement = children[0]->codeGenerator();	//�ж�����
	string statement = children[1]->codeGenerator();	//��ת���
	vector<string> else_string;
	for (int i = 2; i < children.size(); i++) {
		else_string.push_back(children[i]->codeGenerator());
	}
	IfGenerator generator = IfGenerator(judgement, statement,else_string);
	return generator.CodeGenerator();
}

std::string WhileNode::codeGenerator()
{
	string judgement = children[0]->codeGenerator();
	string statement = children[1]->codeGenerator();
	WhileGenerator generator = WhileGenerator(judgement, statement);
	return generator.CodeGeneratot();
}

std::string CompoundNode::codeGenerator()
{
	vector<string> expression_list;	//����б�
	for (int i = 0; i < children.size(); i++)
	{
		expression_list.push_back(children[i]->codeGenerator());
	}
	CompoundGenerator generator = CompoundGenerator(expression_list);
	return generator.CodeGenerator();
}

std::string ParameterNode::codeGenerator()
{	
	//��û����
	ParameterGenerator generator = ParameterGenerator(isVar, getType().getCType(), idlist);
	return generator.CodeGenerator();
	/*
	string statement;//ParameterNode�ڵ���������
	for (int i = 0; i < idlist.size() - 1; i++)//���ɳ����һ��id������Parameter�Ĵ���
	{
		if(isVar)
			statement = statement + getType().getCType() + " *"
			+ idlist[i] + ", ";
		else
			statement = statement + getType().getCType() + " "
				+ idlist[i] + ", ";
	}
	if(isVar)
		return statement + getType().getCType() + " *"
			+ idlist[idlist.size() - 1];//�������һ��id
	else
		return statement + getType().getCType() + " "
		+ idlist[idlist.size() - 1];//�������һ��id
	*/
}

std::string FunctionCallNode::codeGenerator()
{
	vector<string> parameterlist;
	vector<string> parameterType;
	for (int i = 0; i < children.size(); i++) {
		parameterType.push_back(children[i]->getType().getSimpleType());
		parameterlist.push_back(children[i]->codeGenerator());
	}
	FunctionCallGenerator generator = FunctionCallGenerator(getID(), parameterlist, parameterType);
	return generator.CodeGenerator();
}

std::string FunctionDeclarationNode::codeGenerator()
{
	string parStatement;//��������
	
	string statement = std::string();
	if (getType().getCType().empty()) 
	{
		statement =  "void " + id + "(";//������������
	}
	else
	{
		statement = getType().getCType() + " " + id + "(";//������������
	}

	int ptr = 0;	//children����ĵ�ǰ����ָ��
	if (parameterNum != 0) { //�ж��Ƿ��в���
		int parametercount = 0;//�����Ѿ�����Ĳ���
		while (parametercount < parameterNum) {	//֮���children�ڵ㻹���ڲ���
			if (parametercount == 0)
				statement = statement + children[ptr]->codeGenerator();
			else
				statement = statement + ","+ children[ptr]->codeGenerator();
			parametercount += children[ptr]->getIdNum();
			ptr++;
		}
	}
	statement += "){";
	for (int i = ptr; i < children.size(); i++) {
		statement += children[i]->codeGenerator();
	}
	statement += "}";
	return statement;
}

std::string ProgramNode::codeGenerator()
{
	vector<string> statementlist;
	for (int i = 0; i < children.size() - 1; i++){
		statementlist.push_back(children[i]->codeGenerator());
	}
	string main_compound = children[children.size() - 1]->codeGenerator();
	ProgramGenerator generator = ProgramGenerator(statementlist, main_compound);
	return generator.CodeGenerator();

	/*
	string statement;//����program������,����int main������
	string beginStatement;//ͷ�ļ�
	beginStatement = "#include <stdio.h> \n #include <stdlib.h>\n ";
	for (int i = 0; i < children.size() - 1; i++)
	{
		statement = statement
			+ children[i]->codeGenerator()
			+ "\n";
	}
	return beginStatement + statement + "int main( ) \n"
		+ children[children.size() - 1]->codeGenerator();
	*/
}

std::string VarpartNode::codeGenerator() {
	
	string statement;
	vector<std::pair<int, int>> peroid = scope->lookUp(id).getType().getPeroid();
	vector<string> ids;
	for (int i = 0; i < children.size(); i++) {
		ids.push_back(children[i]->codeGenerator());
	}
	VarpartGenerator generator = VarpartGenerator(ids, peroid);
	return generator.CodeGenerator();

	/*
	string statement;
	vector<std::pair<int, int>> peroid = scope->lookUp(id).getType().getPeroid();

	for (int i = 0; i < children.size(); i++) {
		statement += "[" + children[i]->codeGenerator() + "-" + to_string(peroid[i].first) + "]";
	}
	return statement;
	*/
}

/****************��TypeStruct�е�pascal����ת��Ϊ��Ӧ��C����*******************/
std::string TypeStruct::getCType() {
	if (simpleType == "integer") {
		return "int";
	}
	else if (simpleType == "boolean") {
		return "bool";
	}
	else if (simpleType == "real") {
		return "float";
	}
	return simpleType;
}

/**********��ExpressionNode�е�pascal������ת��Ϊ��Ӧ��C������************/
std::string ExpressionNode::getCTypeOperation() {
	if (operation == "and") {
		return "&&";
	}
	else if (operation == "or") {
		return "||";
	}
	else if (operation == "not") {
		return "!";
	}
	else if (operation == "div") {
		return "/";
	}
	else if (operation == "mod") {
		return "%";
	}
	else if (operation == "<>") {
		return "!=";
	}
	else
		return operation;
}
