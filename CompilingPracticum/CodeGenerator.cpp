#include"CodeGenerator.h"
using namespace std;

string VarGenerator::CodeGenerator() {
	if (isfunction) {	//����Ǻ���
		return "(" + id + "())";
	}
	else if (!hasVarpart)
	{
		if (isRef)//�ж��Ƿ�Ϊ����
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
		if (isRef)//�ж��Ƿ�Ϊ����
		{
			return "(" + std::string("*") + id + varpart + ")";
		}
		else//��Ϊ����ʱ
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
			+ "( " + statement + ",&" + parameterlist[parameterlist.size() - 1] + " );";//�������һ������
	}
	else if (id == std::string("write")) {	//��pascal��write����ת��ΪC���Ե�printf
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
			+ "( " + statement + "," + parameterlist[parameterlist.size() - 1]+ " );";//�������һ������
	}
	else if (id == string("random")) {	//��pascal��random����ת��ΪC���Ե�
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
			for (int i = 0; i < parameterlist.size() - 1; i++)//���ɳ����һ��expression�����в����Ĵ���
			{
				statement = statement
					+ parameterlist[i] + ", ";
			}
			return id
				+ "( " + statement + parameterlist[parameterlist.size() - 1] + " );";//�������һ������	
		}
	}
}

string AssignmentGenerator::CodeGenerator() {
	if (isReturn)//�ж��Ƿ�Ϊreturnֵ,��
		return "_" + leftexpression + " = " + rightexpression + ";";
	else		//����return���������ֵ���
		return leftexpression + " = " + rightexpression + ";";
}

string IfGenerator::CodeGenerator() {
	string testEnd;//���ĩβ�Ƿ��У�
	testEnd = judgement;
	if (testEnd[testEnd.length() - 1] == ';')//���ĩβΪ;ɾ��
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
	return "for( " + iterator +  "= " + start_number	//��ȡ��ʼֵ
		+ "; " + iterator + "<= " + end_number			//��ȡ����ֵ
		+ "; " + iterator + "++ ) " + statement;
}

string WhileGenerator::CodeGeneratot() {
	return "while(" + judgement
		+ ") " + statement;
}

string CompoundGenerator::CodeGenerator() {
	string statement;//CompoundNode�����е�����
	for (int i = 0; i < expression_list.size(); i++)
	{
		statement = statement + expression_list[i]+ "\n";
	}
	return "{ " + statement + "}";
}

string VarDeclarationGenerator::CodeGenerator() {
	string stringIdList;//���id���ַ���
	for (int i = 0; i < idlist.size(); i++)//���ɶ��id���ַ���
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
	string statement;//����program������,����int main������
	string beginStatement;//ͷ�ļ�
	beginStatement = "#include <stdio.h>\n#include <stdlib.h>\n#include <stdbool.h>\n";
	for (int i = 0; i < statementlist.size(); i++)
	{
		statement = statement
			+ statementlist[i]
			+ "\n";
	}
	/*******************jackchance:�޸�ʱ��2018/5/5�������system("pause")**********************************/
	return beginStatement + statement + "int main( )\n {"
		+ main_compound + "\nsystem(\"pause\");\nreturn 0;}";
}

string ParameterGenerator::CodeGenerator() {
	string statement;//ParameterNode�ڵ���������
	for (int i = 0; i < idlist.size() - 1; i++)//���ɳ����һ��id������Parameter�Ĵ���
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
		+ idlist[idlist.size() - 1];//�������һ��id
	else
		return statement + type + " "
		+ idlist[idlist.size() - 1];//�������һ��id
}