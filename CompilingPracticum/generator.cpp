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
		return "( " + operation + " "
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
		return "( " + testEnd1 + " "+ operation 
			+ " " + testEnd2 +" )";
	}
	return std::string();
}

std::string VarNode::codeGenerator()
{
	if (children.size() == 0)
	{
		if (scope->lookUp(id).getType().checkRef())//�ж��Ƿ�Ϊ����
		{
			return '(' + "*" + id + ')';
		}
		else//��Ϊ����ʱ
		{
			return '(' + id + ')';
		}
	}
	else
	{
		if (scope->lookUp(id).getType().checkRef())//�ж��Ƿ�Ϊ����
		{
			return '(' + "*" + id + children[0]->codeGenerator() + ')';
		}
		else//��Ϊ����ʱ
		{
			return '(' + id + children[0]->codeGenerator() + ')';
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
		if(i != 0)
			stringIdList = stringIdList + "," + idlist[i];
		else
			stringIdList = stringIdList + " " + idlist[i];
	}
	return type.getSimpleType() + stringIdList + ";";
}

std::string ConstDeclarationNode::codeGenerator()
{
	return "const " +
		scope->lookUp(id).getType().getSimpleType()
		+ " " + id + " = "
		+ value +";";
}

std::string AssignmentNode::codeGenerator()
{
	if (std::string("_") + children[0]->getID() == scope->getFirstSymbol().getId())//�ж��Ƿ�Ϊreturnֵ,��
		return "return "+ children[1]->codeGenerator() + ";";
	else		//����return���������ֵ���
		return children[0]->codeGenerator() + " = " + children[1]->codeGenerator() + ";";
}

std::string ForNode::codeGenerator()
{
	return "for(int i = " + children[0]->codeGenerator()
		+ "; i<= " + children[1]->codeGenerator()
		+ "; i++ ) "+ children[2]->codeGenerator();
}

std::string IfNode::codeGenerator()
{
	return "if(" + children[0]->codeGenerator()
		+ ") " + children[1]->codeGenerator();
}

std::string WhileNode::codeGenerator()
{
	return "while("+children[0]->codeGenerator()
		+") "+ children[1]->codeGenerator();
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
{
	string statement;//ParameterNode�ڵ���������
	for (int i = 0; i < idlist.size()-1; i++)//���ɳ����һ��id������Parameter�Ĵ���
	{
		statement = statement + simpleType + " "
			+ idlist[i] + ", ";
	}
	return statement+ simpleType + " "
		+ idlist[idlist.size() - 1];//�������һ��id
}

std::string FunctionCallNode::codeGenerator()
{
	string statement;//����������
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

std::string FunctionDeclarationNode::codeGenerator()
{
	string parStatement;//��������
	string statement= simpleType + " " + id + "(";//������������

	int ptr=0;	//children����ĵ�ǰ����ָ��
	if (parameterNum != 0) { //�ж��Ƿ��в���
		int parametercount = 0;//�����Ѿ�����Ĳ���
		while (parametercount < parameterNum) {	//֮���children�ڵ㻹���ڲ���
			if (parametercount == 0) 
				statement = statement + children[ptr]->codeGenerator();
			else
				statement = "," + statement + children[ptr]->codeGenerator();
			parametercount += children[ptr]->getIdNum();
			ptr++;
		}
	}
	statement +=  "){";
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
	beginStatement = "#include <stdio.h> \n";
	for (int i = 0; i < children.size()-1; i++)
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