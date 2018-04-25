#include"symbol_table.h"

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
		printf("%d\n", children[0]->getLineNum());
		printf(children[0]->getID().c_str());
		flag = false;
	}
	for (auto i : children)
	{
		if (!(i->typeCheck()))
			flag = false;
	}
	return flag;
}

bool IfNode::typeCheck()
{
	bool flag = true;
	if (children[0]->getType() != TypeStruct(std::string("boolean")))
	{
		printf("%d\n", children[0]->getLineNum());
		printf(children[0]->getID().c_str());
		flag = false;
	}
	for (auto i : children)
	{
		if (!(i->typeCheck()))
			flag = false;
	}
	return flag;
}

bool ForNode::typeCheck()
{
	bool flag = true;
	TypeStruct temp = TypeStruct(std::string("integer"));
	if (children[0]->getType() != temp || children[1]->getType() != temp)
	{
		printf("%d\n", children[0]->getLineNum());
		printf(children[0]->getID().c_str());
		flag = false;
	}
	for (auto i : children)
	{
		if (!(i->typeCheck()))
			flag = false;
	}
	return flag;
}

bool WhileNode::typeCheck()
{
	bool flag = true;
	if (children[0]->getType() != TypeStruct(std::string("boolean")))
	{
		printf("%d\n", children[0]->getLineNum());
		printf(children[0]->getID().c_str());
		flag = false;
	}
	for (auto i : children)
	{
		if (!(i->typeCheck()))
			flag = false;
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
			printf("%d\n", i->getLineNum());
			printf(i->getID().c_str());
			flag = false;
		}
	}
	for (auto i : children)
	{
		if (!(i->typeCheck()))
			flag = false;
	}
	return flag;
}

bool ExpressionNode::typeCheck()
{
	bool flag = true;
	TypeStruct temp = children[0]->getType();
	if (temp == TypeStruct())
		flag = false;
	for (auto i : children)
	{
		if (i->getType() != temp)
		{
			printf("%d\n", i->getLineNum());
			printf(i->getID().c_str());
			flag = false;
		}
	}
	for (auto i : children)
	{
		if (!(i->typeCheck()))
			flag = false;
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
			printf("%d\n", lineNum);
			flag = false;
		}
		else
		{
			for (int i = 0; i<parameterType.size(); i++)
			{
				if (children[i]->getType() != parameterType[i])
				{
					printf("%d\n", children[i]->getLineNum());
					printf(children[i]->getID().c_str());
					flag = false;
				}
			}
		}
	}
	for (auto i : children)
	{
		if (!(i->typeCheck()))
			flag = false;
	}
	return flag;
}

TypeStruct VarNode::getType()
{
	TypeStruct originType = scope->lookUp(id).getType();
	std::vector<std::pair<int, int>> peroid = originType.getPeroid();
	if (children.size() <= peroid.size())
	{
		for (int i = children.size(); i > 0; i--)
		{
			peroid.erase(peroid.begin());
		}
		return TypeStruct(originType.getSimpleType(), peroid);
	}
	else
	{
		printf("%d\n", lineNum);
		return TypeStruct();
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

