#include"symbol_table.h"
#include<iostream>

bool operator==(const TypeStruct &lhs, const TypeStruct &rhs)
{
	if (lhs.simpleType == rhs.simpleType && lhs.period.size() == rhs.period.size())
		return true;
	else
		return false;
}
bool operator!=(const TypeStruct &lhs, const TypeStruct &rhs)
{
	if (lhs.simpleType == rhs.simpleType && lhs.period.size() == rhs.period.size())
		return false;
	else
		return true;
}

bool ASTNode::typeCheck()
{
	bool flag = true;
	for (auto i : children)
	{
		if (!(i->typeCheck()))
			flag = false;
	}
	return flag;
}

bool AssignmentNode::typeCheck()
{
	bool flag = true;
	if (children[0]->getType() != children[1]->getType())
	{
		std::cout << "��" << lineNum << "�У���ֵ������Ͳ�ƥ��" << std::endl;
		auto temp1 = children[1]->getType();
		auto temp0 = children[0]->getType();
		flag = false;
	}
	for (auto i : children)
	{
		if (!(i->typeCheck()))
		{
			flag = false;
		}
	}
	return flag;
}

bool IfNode::typeCheck()
{
	bool flag = true;
	if (children[0]->getType() != TypeStruct(std::string("boolean")))
	{
		std::cout << "��" << lineNum << "��: �������ʽ���ͱ���Ϊboolean"<< std::endl;
		flag = false;
	}
	for (auto i : children)
	{
		if (!(i->typeCheck()))
		{
			flag = false;
		}
	}
	return flag;
}

bool ForNode::typeCheck()
{
	bool flag = true;
	TypeStruct temp = TypeStruct(std::string("integer"));
	if (scope->lookUp(iterator).getType() != temp)
	{
		std::cout << "��" << lineNum << "��: ѭ���������ͱ���Ϊinteger" << std::endl;
		flag = false;
	}
	if (children[0]->getType() != temp || children[1]->getType() != temp)
	{
		std::cout << "��" << lineNum << "��: ѭ���������½���ʽ���ͱ���Ϊinteger"<< std::endl;
		flag = false;
	}
	for (auto i : children)
	{
		if (!(i->typeCheck()))
		{
			flag = false;
		}
	}
	return flag;
}

bool WhileNode::typeCheck()
{
	bool flag = true;
	if (children[0]->getType() != TypeStruct(std::string("boolean")))
	{
		std::cout << "��" << lineNum << "��: ���ʹ����������ʽ���ͱ���Ϊboolean" << std::endl;
		flag = false;
	}
	for (auto i : children)
	{
		if (!(i->typeCheck()))
		{
			flag = false;
		}
	}
	return flag;
}

bool VarpartNode::typeCheck()
{
	bool flag = true;
	TypeStruct temp = TypeStruct(std::string("integer"));
	for (auto i : children)
	{
		if (i->getType() != temp)
		{
			std::cout << "��" << lineNum << "��: �����±��еı��ʽ���ͱ���Ϊinteger" << std::endl;
			flag = false;
		}
	}
	for (auto i : children)
	{
		if (!(i->typeCheck()))
		{
			flag = false;
		}
	}
	return flag;
}

bool ExpressionNode::typeCheck()
{
	bool flag = true;
	TypeStruct temp = children[0]->getType(); 
	if (temp == TypeStruct())
		flag = false;
	if (operation == std::string("not") || operation == std::string("and") || operation == std::string("or"))
	{
		temp = TypeStruct(std::string("boolean"));
		for (auto i : children)
		{
			if (i->getType() != temp)
			{
				std::cout << "��" << lineNum << "��: �����\"" << operation << "\"�������ͱ���Ϊboolean" << std::endl;
				flag = false;
			}
		}
	}
	else
	{
		for (auto i : children)
		{
			if (i->getType() != temp)
			{
				std::cout << "��" << lineNum << "��: �����\"" << operation << "\"�������Ͳ�ƥ��" << std::endl;
				flag = false;
			}
		}
	}
	for (auto i : children)
	{
		if (!(i->typeCheck()))
		{
			flag = false;
		}
	}
	return flag;
}

bool FunctionCallNode::typeCheck()
{
	bool flag = true;
	std::vector<TypeStruct> parameterType = scope->lookUp(id).getParameterType();
	if (id != std::string("read") && id != std::string("write"))
	{
		if (parameterType.size() != children.size())
		{
			std::cout << "��" << lineNum << "��: �������õĲ���������ƥ��" << std::endl;
			flag = false;
		}
		else
		{
			for (int i = 0; i<parameterType.size(); i++)
			{
				if (children[i]->getType() != parameterType[i])
				{
					std::cout << "��" << lineNum << "��: ����\"" << id << "\"�ĵ�"<< i+1 <<"���������Ͳ�ƥ��"<< std::endl;
					flag = false;
				}
				if (!children[i]->isVarNode() && parameterType[i].checkRef())
				{
					std::cout << "��" << lineNum << "��: ����\"" << id << "\"�ĵ�" << i + 1 << "������Ϊ���ã�������ʹ�÷Ǳ����Ĳ���" << std::endl;
					flag = false;
				}
			}
		}
	}
	else
	{
		for (auto i : children)
		{
			if (!i->getType().getPeroid().empty())
			{
				std::cout << "��" << lineNum << "��: ����\"" << id << "\"�Ĳ�������Ϊ����" << std::endl;
				flag = false;
			}
			if (i->getType().getSimpleType() == std::string("boolean"))
			{
				std::cout << "��" << lineNum << "��: ����\"" << id << "\"�Ĳ�������Ϊboolean" << std::endl;
				flag = false;
			}
		}
	}
	for (auto i : children)
	{
		if (!(i->typeCheck()))
		{
			flag = false;
		}
	}
	return flag;
}

TypeStruct VarNode::getType()
{
	TypeStruct originType = scope->lookUp(id).getType();
	std::vector<std::pair<int, int>> peroid = originType.getPeroid();
	if (children.size() == 0)
		return originType;
	else
	{
		if (children[0]->getChildrenNum() <= peroid.size())
		{
			for (int i = children[0]->getChildrenNum(); i > 0; i--)
			{
				peroid.erase(peroid.begin());
			}
			return TypeStruct(originType.getSimpleType(), peroid);
		}
		else
		{
			std::cout << "��" << lineNum << "��: �������\"" << id <<"\"���õ��±������������ȶ����ά��" << std::endl;
			return TypeStruct();
		}
	}
}
TypeStruct ConstNode::getType()
{
	if (value.find(std::string(".")) != std::string::npos)
		return TypeStruct(std::string("real"));
	else if (value.find(std::string("'")) != std::string::npos)
		return TypeStruct(std::string("char"));
	else
		return TypeStruct(std::string("integer"));
}
TypeStruct FunctionCallNode::getType()
{
	return scope->lookUp(id).getType();
}
TypeStruct ExpressionNode::getType()
{
	if (operation == std::string("not")
		|| operation == std::string("and")
		|| operation == std::string("or")
		|| operation == std::string(">")
		|| operation == std::string("<")
		|| operation == std::string("=")
		|| operation == std::string(">=")
		|| operation == std::string("<=")
		|| operation == std::string("<>"))
		return TypeStruct(std::string("boolean"));
	return children[0]->getType();
}

