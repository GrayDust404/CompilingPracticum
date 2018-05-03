#include "symbol_table.h"
using namespace std;
std::string ExpressionNode::codeGenerator()
{
	if (children.size() == 1)//只有一个子节点时
	{
		string testEnd;//检测末尾是否有；
		testEnd = children[0]->codeGenerator();
		if (testEnd[testEnd.length() - 1] == ';')//如果末尾为;删除
			testEnd.pop_back();
		return "( " + getCTypeOperation() + " "
			+ testEnd + " )";
	}
	if (children.size() == 2)//有两个子节点时
	{
		string testEnd1, testEnd2;//检测末尾是否有；
		testEnd1 = children[0]->codeGenerator();
		testEnd2 = children[1]->codeGenerator();
		if (testEnd1[testEnd1.length() - 1] == ';')//如果末尾为;删除
			testEnd1.pop_back();
		if (testEnd2[testEnd2.length() - 1] == ';')//如果末尾为;删除
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
			if (scope->lookUp(id).getType().checkRef())//判断是否为引用
			{
				return "(" + std::string("*") + id + ")";
			}
			else//不为引用时
			{
				return "(" + id + ")";
			}
		}
		else
		{
			if (scope->lookUp(id).getType().checkRef())//判断是否为引用
			{
				return "(" + std::string("*") + id + children[0]->codeGenerator() + ")";
			}
			else//不为引用时
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
	string stringIdList;//多个id的字符串
	for (int i = 0; i < idlist.size(); i++)//生成多个id的字符串
	{
		if (i != 0)
		{
			if (scope->lookUp(idlist[i]).getType().getPeroid().size() > 0)//判断是否为数组
			{
				vector<std::pair<int, int>> peroid = scope->lookUp(idlist[i]).getType().getPeroid();
				string IdPart;//数组下标
				for (int j = 0; j < scope->lookUp(idlist[i]).getType().getPeroid().size(); j++)//根据数组维数添加下标
				{
					IdPart = IdPart + "[" + to_string(peroid[j].second - peroid[j].first+1) + "]";
				}
				stringIdList = stringIdList + "," + idlist[i]+ IdPart;
			}
			else//不为数组
			{
				stringIdList = stringIdList + "," + idlist[i];
			}
		}
		else
		{
			if (scope->lookUp(idlist[i]).getType().getPeroid().size() > 0)//判断是否为数组
			{
				vector<std::pair<int, int>> peroid = scope->lookUp(idlist[i]).getType().getPeroid();
				string IdPart;//数组下标
				for (int j = 0; j < scope->lookUp(idlist[i]).getType().getPeroid().size(); j++)//根据数组维数添加下标
				{
					IdPart = IdPart + "[" + to_string(peroid[j].second - peroid[j].first + 1) + "]";
				}
				stringIdList = stringIdList + " " + idlist[i] + IdPart;
			}
			else//不为数组
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
	if (std::string("_") + children[0]->getID() == scope->getFirstSymbol().getId())//判断是否为return值,是
		return "return " + children[1]->codeGenerator() + ";";
	else		//不是return，则输出赋值语句
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
	string statement;//CompoundNode内所有的内容
	for (int i = 0; i < children.size(); i++)
	{
		statement = statement + children[i]->codeGenerator()
			+ "\n";
	}
	return "{ " + statement + "}";
}

std::string ParameterNode::codeGenerator()
{																//2018.4.25 jackchance修复pascal类型到C类型的转换
	string statement;//ParameterNode内的所有内容
	for (int i = 0; i < idlist.size() - 1; i++)//生成除最后一个id外所有Parameter的代码
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
			+ idlist[idlist.size() - 1];//加上最后一个id
	else
		return statement + getType().getCType() + " "
		+ idlist[idlist.size() - 1];//加上最后一个id
}

std::string FunctionCallNode::codeGenerator()
{
	string statement;//参数的内容
	if (getID() == std::string("read")) {		//将pascal的read函数转化为C语言的scanf
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
			+ " );";//加上最后一个参数
	}
	else if (getID() == "write") {	//将pascal的write函数转化为C语言的printf
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
			+ " );";//加上最后一个参数
	}
	else if (getID() == "random") {	//将pascal的random函数转化为C语言的
		if (children.size() != 0) {
			statement = statement + "%" + children[0]->codeGenerator();
		}
		return std::string("rand()") + statement + ";";
	}
	else {
		if (children.size() != 0)
		{
			for (int i = 0; i < children.size() - 1; i++)//生成除最后一个expression外所有参数的代码
			{
				statement = statement
					+ children[i]->codeGenerator()
					+ ", ";
			}

			return id
				+ "( " + statement + children[children.size() - 1]->codeGenerator()
				+ " );";//加上最后一个参数
		}
		else
		{
			return id + "();";
		}

	}
}

std::string FunctionDeclarationNode::codeGenerator()
{
	string parStatement;//参数内容
	
	string statement = std::string();
	if (getType().getCType().empty()) 
	{
		statement =  "void " + id + "(";//函数主体内容
	}
	else
	{
		statement = getType().getCType() + " " + id + "(";//函数主体内容
	}

	int ptr = 0;	//children数组的当前访问指针
	if (parameterNum != 0) { //判断是否有参数
		int parametercount = 0;//计数已经输出的参数
		while (parametercount < parameterNum) {	//之后的children节点还存在参数
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
	string statement;//所有program的内容,除了int main的内容
	string beginStatement;//头文件
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

/****************将TypeStruct中的pascal类型转化为对应的C类型*******************/
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

/**********将ExpressionNode中的pascal操作符转化为对应的C操作符************/
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
