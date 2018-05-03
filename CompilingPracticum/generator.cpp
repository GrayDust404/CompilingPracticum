#include "symbol_table.h"
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
	if (scope->lookUp(id).getChildTable() != std::shared_ptr<SymbolTable>())
	{
		return "(" + id + "())";
	}
	else
	{
		if (children.size() == 0)
		{
			if (scope->lookUp(id).getType().checkRef())//�ж��Ƿ�Ϊ����
			{
				return "(" + std::string("*") + id + ")";
			}
			else//��Ϊ����ʱ
			{
				return "(" + id + ")";
			}
		}
		else
		{
			if (scope->lookUp(id).getType().checkRef())//�ж��Ƿ�Ϊ����
			{
				return "(" + std::string("*") + id + children[0]->codeGenerator() + ")";
			}
			else//��Ϊ����ʱ
			{
				return "(" + id + children[0]->codeGenerator() + ")";
			}
		}
	}
}

std::string ConstNode::codeGenerator()
{
	return value;
}

std::string VarDeclarationNode::codeGenerator()
{
	string stringIdList;//���id���ַ���
	for (int i = 0; i < idlist.size(); i++)//���ɶ��id���ַ���
	{
		if (i != 0)
		{
			if (scope->lookUp(idlist[i]).getType().getPeroid().size() > 0)//�ж��Ƿ�Ϊ����
			{
				vector<std::pair<int, int>> peroid = scope->lookUp(idlist[i]).getType().getPeroid();
				string IdPart;//�����±�
				for (int j = 0; j < scope->lookUp(idlist[i]).getType().getPeroid().size(); j++)//��������ά������±�
				{
					IdPart = IdPart + "[" + to_string(peroid[j].second - peroid[j].first+1) + "]";
				}
				stringIdList = stringIdList + "," + idlist[i]+ IdPart;
			}
			else//��Ϊ����
			{
				stringIdList = stringIdList + "," + idlist[i];
			}
		}
		else
		{
			if (scope->lookUp(idlist[i]).getType().getPeroid().size() > 0)//�ж��Ƿ�Ϊ����
			{
				vector<std::pair<int, int>> peroid = scope->lookUp(idlist[i]).getType().getPeroid();
				string IdPart;//�����±�
				for (int j = 0; j < scope->lookUp(idlist[i]).getType().getPeroid().size(); j++)//��������ά������±�
				{
					IdPart = IdPart + "[" + to_string(peroid[j].second - peroid[j].first + 1) + "]";
				}
				stringIdList = stringIdList + " " + idlist[i] + IdPart;
			}
			else//��Ϊ����
			{
				stringIdList = stringIdList + " " + idlist[i];
			}
		}
	}
	return type.getCType() + stringIdList + ";";
}

std::string ConstDeclarationNode::codeGenerator()
{
	return "const " +
		scope->lookUp(id).getType().getCType()
		+ " " + id + " = " 
		+ operation
		+ value + ";";
}

std::string AssignmentNode::codeGenerator()
{
	if (std::string("_") + children[0]->getID() == scope->getFirstSymbol().getId())//�ж��Ƿ�Ϊreturnֵ,��
		return "return " + children[1]->codeGenerator() + ";";
	else		//����return���������ֵ���
		return children[0]->codeGenerator() + " = " + children[1]->codeGenerator() + ";";
}

std::string ForNode::codeGenerator()
{
	return "for("+ iterator + " = " + children[0]->codeGenerator()
		+ "; " + iterator + " <= " + children[1]->codeGenerator()
		+ "; " + iterator + "++ ) " + children[2]->codeGenerator();
}

std::string IfNode::codeGenerator()
{
	return "if(" + children[0]->codeGenerator()
		+ ") " + children[1]->codeGenerator();
}

std::string WhileNode::codeGenerator()
{
	return "while(" + children[0]->codeGenerator()
		+ ") " + children[1]->codeGenerator();
}

std::string CompoundNode::codeGenerator()
{
	string statement;//CompoundNode�����е�����
	for (int i = 0; i < children.size(); i++)
	{
		statement = statement + children[i]->codeGenerator()
			+ "\n";
	}
	return "{ " + statement + "}";
}

std::string ParameterNode::codeGenerator()
{																//2018.4.25 jackchance�޸�pascal���͵�C���͵�ת��
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
}

std::string FunctionCallNode::codeGenerator()
{
	string statement;//����������
	if (getID() == std::string("read")) {		//��pascal��read����ת��ΪC���Ե�scanf
		statement = statement + "\"";
		for (int i = 0; i < children.size(); i++) {
			if (i != 0) {
				statement = statement + " ";
			}
			if (children[i]->getType().getSimpleType() == std::string("integer")) {
				statement = statement + "%d";
			}
			else if (children[i]->getType().getSimpleType() == std::string("real")) {
				statement = statement + "%f";
			}
			else if (children[i]->getType().getSimpleType() == std::string("char")) {
				statement = statement + "%c";
			}
		}
		statement = statement + "\"";
		for (int i = 0; i < children.size() - 1; i++) {
			statement = statement
				+ ",&" + children[i]->codeGenerator();
		}
		return std::string("scanf")
			+ "( " + statement + ",&" + children[children.size() - 1]->codeGenerator()
			+ " );";//�������һ������
	}
	else if (getID() == "write") {	//��pascal��write����ת��ΪC���Ե�printf
		statement = statement + "\"";
		for (int i = 0; i < children.size(); i++) {
			if (i != 0) {
				statement = statement + " ";
			}
			if (children[i]->getType().getSimpleType() == std::string("integer")) {
				statement = statement + "%d";
			}
			else if (children[i]->getType().getSimpleType() == std::string("real")) {
				statement = statement + "%f";
			}
			else if (children[i]->getType().getSimpleType() == std::string("boolean")) {
				statement = statement + "%d";
			}
			else if (children[i]->getType().getSimpleType() == std::string("char")) {
				statement = statement + "%c";
			}
		}
		statement = statement + "\"";
		for (int i = 0; i < children.size() - 1; i++) {
			statement = statement
				+ "," + children[i]->codeGenerator();
		}
		return std::string("printf")
			+ "( " + statement + "," + children[children.size() - 1]->codeGenerator()
			+ " );";//�������һ������
	}
	else if (getID() == "random") {	//��pascal��random����ת��ΪC���Ե�
		if (children.size() != 0) {
			statement = statement + "%" + children[0]->codeGenerator();
		}
		return std::string("rand()") + statement + ";";
	}
	else {
		if (children.size() != 0)
		{
			for (int i = 0; i < children.size() - 1; i++)//���ɳ����һ��expression�����в����Ĵ���
			{
				statement = statement
					+ children[i]->codeGenerator()
					+ ", ";
			}

			return id
				+ "( " + statement + children[children.size() - 1]->codeGenerator()
				+ " );";//�������һ������
		}
		else
		{
			return id + "();";
		}

	}
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
}

std::string VarpartNode::codeGenerator() {
	string statement;
	vector<std::pair<int, int>> peroid = scope->lookUp(id).getType().getPeroid();

	for (int i = 0; i < children.size(); i++) {
		statement += "[" + children[i]->codeGenerator() + "-" + to_string(peroid[i].first) + "]";
	}
	return statement;
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
