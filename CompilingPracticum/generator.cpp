#include"ast.h"
using namespace std;
std::string ExpressionNode::codeGenerator()
{
	if (ExpressionNode::children.size == 1)//ֻ��һ���ӽڵ�ʱ
	{
		string testEnd;//���ĩβ�Ƿ��У�
		testEnd = ExpressionNode::children[0]->codeGenerator();
		if (testEnd[testEnd.length() - 1] == ';')//���ĩβΪ;ɾ��
			testEnd.pop_back();
		return "( " + ExpressionNode::operation + " "
			+ testEnd + " )";
	}
	if (ExpressionNode::children.size == 2)//�������ӽڵ�ʱ
	{
		string testEnd1, testEnd2;//���ĩβ�Ƿ��У�
		testEnd1 = ExpressionNode::children[0]->codeGenerator();
		testEnd2 = ExpressionNode::children[1]->codeGenerator();
		if (testEnd1[testEnd1.length() - 1] == ';')//���ĩβΪ;ɾ��
			testEnd1.pop_back();
		if (testEnd2[testEnd2.length() - 1] == ';')//���ĩβΪ;ɾ��
			testEnd2.pop_back();
		return "( " + testEnd1 + " "+ ExpressionNode::operation 
			+ " " + testEnd2 +" )";
	}
}

std::string AssignmentNode::codeGenerator()
{

}

std::string VarNode::codeGenerator()
{
	if (VarNode::scope->lookUp(id).getType().checkRef())//�ж��Ƿ�Ϊ����
	{
		return '(' +"*"+id + ')';
	}
	else//��Ϊ����ʱ
	{
		return '('+id+')';
	}
}

std::string ConstNode::codeGenerator()
{
	return value;
}

std::string VarDeclarationNode::codeGenerator()
{
	string stringIdList;//���id���ַ���
	for (int i = 0; i < VarDeclarationNode::idlist.size; i++)//���ɶ��id���ַ���
		stringIdList = stringIdList +" " + VarDeclarationNode::idlist[i];
	return VarDeclarationNode::type.getSimpleType() + stringIdList + ";";
}

std::string ConstDeclarationNode::codeGenerator()
{
	return "const " +
		ConstDeclarationNode::scope->lookUp(id).getType().getSimpleType()
		+ " " + ConstDeclarationNode::id + " = "
		+ ConstDeclarationNode::value +";";
}

std::string AssignmentNode::codeGenerator()
{
	if (AssignmentNode::children[0]->getID())//�ж��Ƿ�Ϊreturnֵ
		return;
	else
		return
}

std::string ForNode::codeGenerator()
{
	return "for(int i = " + ForNode::children[0]->codeGenerator()
		+ "; i<= " + ForNode::children[1]->codeGenerator()
		+ "; i++ ) "+ ForNode::children[2]->codeGenerator();
}

std::string IfNode::codeGenerator()
{
	return "if(" + IfNode::children[0]->codeGenerator()
		+ ") " +IfNode::children[1]->codeGenerator();
}

std::string WhileNode::codeGenerator()
{
	return "while("+WhileNode::children[0]->codeGenerator()
		+") "+ WhileNode::children[1]->codeGenerator();
}

std::string CompoundNode::codeGenerator()
{
	string statement;//CompoundNode�����е�����
	for (int i = 0; i < CompoundNode::children.size; i++)
	{
		statement = statement + CompoundNode::children[i]->codeGenerator()
			+ "\n";
	}
	return "{ " + statement + "}";
}

std::string ParameterNode::codeGenerator()
{
	string statement;//ParameterNode�ڵ���������
	for (int i = 0; i < ParameterNode::idlist.size-1; i++)//���ɳ����һ��id������Parameter�Ĵ���
	{
		statement = statement + ParameterNode::simpleType + " "
			+ ParameterNode::idlist[i] + ", ";
	}
	return statement+ ParameterNode::simpleType + " "
		+ ParameterNode::idlist[ParameterNode::idlist.size - 1];//�������һ��id
}

std::string FunctionCallNode::codeGenerator()
{
	string statement;//����������
	for (int i = 0; i < FunctionCallNode::children.size - 1; i++)//���ɳ����һ��expression�����в����Ĵ���
	{
		statement = statement
			+ FunctionCallNode::children[i]->codeGenerator()
			+ ", ";
	}
	return FunctionCallNode::id 
		+ "( " + statement + FunctionCallNode:: children[FunctionCallNode::children.size - 1]->codeGenerator()
		+ " );";//�������һ������
}

std::string FunctionDeclarationNode::codeGenerator()
{
	string parStatement;//��������
	string statement;//������������
	for(int i=0;i< )
}

std::string ProgramNode::codeGenerator()
{
	string statement;//����program������,����int main������
	string beginStatement;//ͷ�ļ�
	beginStatement = "#include <stdio.h> \n";
	for (int i = 0; i < ProgramNode::children.size-1; i++)
	{
		statement = statement
			+ ProgramNode::children[i]->codeGenerator()
			+ "\n";
	}
	return beginStatement + statement + "int main( ) \n"
		+ ProgramNode::children[ProgramNode::children.size - 1]->codeGenerator();
}
