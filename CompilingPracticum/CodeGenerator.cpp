#include"CodeGenerator.h"
using namespace std;

string VarGenerator::CodeGenerator() {
	if (isfunction) {	//如果是函数
		return "(" + id + "())";
	}
	else if (!hasVarpart)
	{
		if (isRef)//判断是否为引用
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
		if (isRef)//判断是否为引用
		{
			return "(" + std::string("*") + id + varpart + ")";
		}
		else//不为引用时
		{
			return "(" + id + varpart + ")";
		}
	}
}

string VarpartGenerator::CodeGenerator() {
	string statement;
	for (int i = 0; i < peroid.size(); i++) {
		statement += "[" + ids[i] + "-" + to_string(peroid[i].first) + "]";
	}
	return statement;
}

string FunctionCallGenerator::CodeGenerator() {
	string statement;
	if (id == std::string("read")) {
		statement = statement + "\"";
		for (int i = 0; i < parameterlist.size(); i++) {
			if (i != 0) {
				statement = statement + " ";
			}
			if (parameterType[i] == std::string("integer")) {
				statement = statement + "%d";
			}
			else if (parameterType[i] == std::string("real")) {
				statement = statement + "%f";
			}
			else if (parameterType[i] == std::string("boolean")) {
				statement = statement + "%d";
			}
			else if (parameterType[i] == std::string("char")) {
				statement = statement + "%c";
			}
		}
		statement = statement + "\"";
		for (int i = 0; i < parameterlist.size() - 1; i++) {
			statement = statement
				+ ",&" + parameterlist[i];
		}
		return std::string("scanf")
			+ "( " + statement + ",&" + parameterlist[parameterlist.size() - 1] + " );";//加上最后一个参数
	}
	else if (id == std::string("write")) {	//将pascal的write函数转化为C语言的printf
		statement = statement + "\"";
		for (int i = 0; i < parameterlist.size(); i++) {
			if (i != 0) {
				statement = statement + " ";
			}
			if (parameterType[i] == std::string("integer")) {
				statement = statement + "%d";
			}
			else if (parameterType[i] == std::string("real")) {
				statement = statement + "%f";
			}
			else if (parameterType[i] == std::string("boolean")) {
				statement = statement + "%d";
			}
			else if (parameterType[i] == std::string("char")) {
				statement = statement + "%c";
			}
		}
		statement = statement + "\"";
		for (int i = 0; i < parameterlist.size() - 1; i++) {
			statement = statement
				+ "," + parameterlist[i];
		}
		return std::string("printf")
			+ "( " + statement + "," + parameterlist[parameterlist.size() - 1]+ " );";//加上最后一个参数
	}
	else if (id == string("random")) {	//将pascal的random函数转化为C语言的
		if (parameterlist.size() != 0) {
			statement = statement + "%" + parameterlist[0];
		}
		return std::string("rand()") + statement + ";";
	}
	else {
		if(parameterlist.size() == 0)
			return id + "();";
		else
		{
			for (int i = 0; i < parameterlist.size() - 1; i++)//生成除最后一个expression外所有参数的代码
			{
				statement = statement
					+ parameterlist[i] + ", ";
			}
			return id
				+ "( " + statement + parameterlist[parameterlist.size() - 1] + " );";//加上最后一个参数	
		}
	}
}

string AssignmentGenerator::CodeGenerator() {
	if (isReturn)//判断是否为return值,是
		return "_" + leftexpression + " = " + rightexpression + ";";
	else		//不是return，则输出赋值语句
		return leftexpression + " = " + rightexpression + ";";
}

string IfGenerator::CodeGenerator() {
	string testEnd;//检测末尾是否有；
	testEnd = judgement;
	if (testEnd[testEnd.length() - 1] == ';')//如果末尾为;删除
		testEnd.pop_back();
	string result = "if(" + testEnd
		+ ") " + statement;

	if (else_statements.size() == 0)
		return result;
	else {
		for (int i = 0; i < else_statements.size(); i++) {
			result = result + "\nelse " + else_statements[i];
		}
		return result;
	}
}

string ForGenerator::CodeGenerator() {
	return "for( " + iterator +  "= " + start_number	//提取初始值
		+ "; " + iterator + "<= " + end_number			//提取界限值
		+ "; " + iterator + "++ ) " + statement;
}

string WhileGenerator::CodeGeneratot() {
	return "while(" + judgement
		+ ") " + statement;
}

string CompoundGenerator::CodeGenerator() {
	string statement;//CompoundNode内所有的内容
	for (int i = 0; i < expression_list.size(); i++)
	{
		statement = statement + expression_list[i]+ "\n";
	}
	return "{ " + statement + "}";
}

string VarDeclarationGenerator::CodeGenerator() {
	string stringIdList;//多个id的字符串
	for (int i = 0; i < idlist.size(); i++)//生成多个id的字符串
	{
		if (i != 0)
			stringIdList = stringIdList + "," + idlist[i];
		else
			stringIdList = stringIdList + " " + idlist[i];
	}
	return type + stringIdList + ";";
}

string ConstDeclarationGenerator::CodeGenerator() {
	return "const " + type
		+ " " + id + " = "
		+ operation
		+ value + ";";
}

string ProgramGenerator::CodeGenerator() {
	string statement;//所有program的内容,除了int main的内容
	string beginStatement;//头文件
	beginStatement = "#include <stdio.h>\n#include <stdlib.h>\n#include <stdbool.h>\n";
	for (int i = 0; i < statementlist.size(); i++)
	{
		statement = statement
			+ statementlist[i]
			+ "\n";
	}
	/*******************jackchance:修改时间2018/5/5，添加了system("pause")**********************************/
	return beginStatement + statement + "int main( )\n {"
		+ main_compound + "\nsystem(\"pause\");\nreturn 0;}";
}

string ParameterGenerator::CodeGenerator() {
	string statement;//ParameterNode内的所有内容
	for (int i = 0; i < idlist.size() - 1; i++)//生成除最后一个id外所有Parameter的代码
	{
		if (isVar)
			statement = statement + type + " *"
			+ idlist[i] + ", ";
		else
			statement = statement + type + " "
			+ idlist[i] + ", ";
	}
	if (isVar)
		return statement + type + " *"
		+ idlist[idlist.size() - 1];//加上最后一个id
	else
		return statement + type + " "
		+ idlist[idlist.size() - 1];//加上最后一个id
}