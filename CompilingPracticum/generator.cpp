#include "symbol_table.h"
#include "CodeGenerator.h"
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
	bool isfunction;
	if (scope->lookUp(id).getChildTable() != std::shared_ptr<SymbolTable>())	//判断是否是函数
	{
		isfunction = true;
	}
	else
		isfunction = false;

	bool isRef = scope->lookUp(id).getType().checkRef();//判断是否为引用
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

		if (scope->lookUp(idlist[i]).getType().getPeroid().size() > 0) { //是数组
			vector<std::pair<int, int>> peroid = scope->lookUp(idlist[i]).getType().getPeroid();
			string IdPart="";//数组下标
			for (int j = 0; j < scope->lookUp(idlist[i]).getType().getPeroid().size(); j++)//根据数组维数添加下标
			{
				IdPart = IdPart + "[" + to_string(peroid[j].second - peroid[j].first + 1) + "]";
			}
			ids.push_back(idlist[i] + IdPart);
		}
		else {		//不是数组
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
	if (std::string("_") + children[0]->getID() == scope->getFirstSymbol().getId())//判断是否为return值,是
		isReturn = true;
	else					//不是return
		isReturn = false;
	string leftexpression = children[0]->codeGenerator();
	string rightexpression = children[1]->codeGenerator(); //右表达式
	AssignmentGenerator generator = AssignmentGenerator(isReturn, leftexpression, rightexpression);
	return generator.CodeGenerator();
}

std::string ForNode::codeGenerator()
{
	string start_number = children[0]->codeGenerator();//起点
	string end_number = children[1]->codeGenerator(); //终点
	string statement = children[2]->codeGenerator();//循环体语句
	ForGenerator generator = ForGenerator(start_number, end_number, statement);
	return generator.CodeGenerator();
}

std::string IfNode::codeGenerator()
{
	string judgement = children[0]->codeGenerator();	//判断条件
	string statement = children[1]->codeGenerator();	//跳转语句
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
	vector<string> expression_list;	//语句列表
	for (int i = 0; i < children.size(); i++)
	{
		expression_list.push_back(children[i]->codeGenerator());
	}
	CompoundGenerator generator = CompoundGenerator(expression_list);
	return generator.CodeGenerator();
}

std::string ParameterNode::codeGenerator()
{	
	//还没改完
	ParameterGenerator generator = ParameterGenerator(isVar, getType().getCType(), idlist);
	return generator.CodeGenerator();
	/*
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
	vector<string> statementlist;
	for (int i = 0; i < children.size() - 1; i++){
		statementlist.push_back(children[i]->codeGenerator());
	}
	string main_compound = children[children.size() - 1]->codeGenerator();
	ProgramGenerator generator = ProgramGenerator(statementlist, main_compound);
	return generator.CodeGenerator();

	/*
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
