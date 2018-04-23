#include"ast.h"
using namespace std;
std::string ExpressionNode::codeGenerator()
{
	if (ExpressionNode::children.size == 1)//只有一个子节点时
	{
		string testEnd;//检测末尾是否有；
		testEnd = ExpressionNode::children[0]->codeGenerator();
		if (testEnd[testEnd.length() - 1] == ';')//如果末尾为;删除
			testEnd.pop_back();
		return "( " + ExpressionNode::operation + " "
			+ testEnd + " )";
	}
	if (ExpressionNode::children.size == 2)//有两个子节点时
	{
		string testEnd1, testEnd2;//检测末尾是否有；
		testEnd1 = ExpressionNode::children[0]->codeGenerator();
		testEnd2 = ExpressionNode::children[1]->codeGenerator();
		if (testEnd1[testEnd1.length() - 1] == ';')//如果末尾为;删除
			testEnd1.pop_back();
		if (testEnd2[testEnd2.length() - 1] == ';')//如果末尾为;删除
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
	if (VarNode::scope->lookUp(id).getType().checkRef())//判断是否为引用
	{
		return '(' +"*"+id + ')';
	}
	else//不为引用时
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
	string stringIdList;//多个id的字符串
	for (int i = 0; i < VarDeclarationNode::idlist.size; i++)//生成多个id的字符串
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
	if (AssignmentNode::children[0]->getID())//判断是否为return值
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
	string statement;//CompoundNode内所有的内容
	for (int i = 0; i < CompoundNode::children.size; i++)
	{
		statement = statement + CompoundNode::children[i]->codeGenerator()
			+ "\n";
	}
	return "{ " + statement + "}";
}

std::string ParameterNode::codeGenerator()
{
	string statement;//ParameterNode内的所有内容
	for (int i = 0; i < ParameterNode::idlist.size-1; i++)//生成除最后一个id外所有Parameter的代码
	{
		statement = statement + ParameterNode::simpleType + " "
			+ ParameterNode::idlist[i] + ", ";
	}
	return statement+ ParameterNode::simpleType + " "
		+ ParameterNode::idlist[ParameterNode::idlist.size - 1];//加上最后一个id
}

std::string FunctionCallNode::codeGenerator()
{
	string statement;//参数的内容
	for (int i = 0; i < FunctionCallNode::children.size - 1; i++)//生成除最后一个expression外所有参数的代码
	{
		statement = statement
			+ FunctionCallNode::children[i]->codeGenerator()
			+ ", ";
	}
	return FunctionCallNode::id 
		+ "( " + statement + FunctionCallNode:: children[FunctionCallNode::children.size - 1]->codeGenerator()
		+ " );";//加上最后一个参数
}

std::string FunctionDeclarationNode::codeGenerator()
{
	string parStatement;//参数内容
	string statement;//函数主体内容
	for(int i=0;i< )
}

std::string ProgramNode::codeGenerator()
{
	string statement;//所有program的内容,除了int main的内容
	string beginStatement;//头文件
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
