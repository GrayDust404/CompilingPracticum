#include"symbol_table.h"
#include<iostream>

bool ASTNode::scopeCheck(std::shared_ptr<SymbolTable> parentScope)
{
	bool flag = true;
	scope = parentScope;
	for (auto i : children)
	{
		if (!(i->scopeCheck(scope)))
		{
			flag = false;
		}
	}
	return flag;
}

bool VarNode::scopeCheck(std::shared_ptr<SymbolTable> parentScope)
{
	bool flag = true;
	scope = parentScope;
	if (scope->lookUp(id).getId().empty() || (scope->lookUp(id).getChildTable() != std::shared_ptr<SymbolTable>() && scope->lookUp(id).getChildTable() != scope))
	{
		flag = false;
		std::cout << "第" << lineNum << "行: 变量" << id <<"未定义"<< std::endl;
	}
	for (auto i : children)
	{
		if (!(i->scopeCheck(scope)))
		{
			flag = false;
		}
	}
	return flag;
}

bool FunctionCallNode::scopeCheck(std::shared_ptr<SymbolTable> parentScope)
{
	bool flag = true;
	scope = parentScope;
	if (scope->lookUp(id).getId().empty() || scope->lookUp(id).getChildTable() == std::shared_ptr<SymbolTable>())
	{
		std::cout << "第" << lineNum << "行: 函数" << id << "未定义" << std::endl;
		flag = false;
	}
	for (auto i : children)
	{
		if (!(i->scopeCheck(scope)))
		{
			flag = false;
		}
	}
	return  flag;
}

bool ForNode::scopeCheck(std::shared_ptr<SymbolTable> parentScope)
{
	bool flag = true;
	scope = parentScope;
	if (scope->lookUp(iterator).getId().empty() || (scope->lookUp(iterator).getChildTable() != std::shared_ptr<SymbolTable>() && scope->lookUp(iterator).getChildTable() != scope))
	{
		std::cout << "第" << lineNum << "行: 变量" << iterator << "未定义" << std::endl;
		flag = false;
	}
	for (auto i : children)
	{
		if (!(i->scopeCheck(scope)))
		{
			flag = false;
		}
	}
	return flag;
}

bool VarDeclarationNode::scopeCheck(std::shared_ptr<SymbolTable> parentScope)
{
	bool flag = true;
	scope = parentScope;
	for (auto id : idlist)
	{
		if(scope->localLookUp(id).getId().empty() && scope->lookUp(id).getChildTable() == std::shared_ptr<SymbolTable>())
			scope->insert(Symbol(std::string(id), type, false));
		else
		{
			std::cout << "第" << lineNum << "行: 变量" << id << "重定义" << std::endl;
			flag = false;
		}
	}
	for (auto i : children)
	{
		if (!(i->scopeCheck(scope)))
		{
			flag = false;
		}
	}
	return flag;
}

bool ConstDeclarationNode::scopeCheck(std::shared_ptr<SymbolTable> parentScope)
{
	bool flag = true;
	scope = parentScope;
	if (scope->localLookUp(id).getId().empty() && scope->lookUp(id).getChildTable() == std::shared_ptr<SymbolTable>())
	{
		if (value.find(std::string(".")) != std::string::npos)
		{
			scope->insert(Symbol(std::string(id), TypeStruct(std::string("real")), true));
		}
		else if (value.find(std::string("'")) != std::string::npos)
		{
			scope->insert(Symbol(std::string(id), TypeStruct(std::string("char")), true));
		}
		else if ((value[0]>'a'&&value[0]<'z') || (value[0]>'A'&&value[0]<'Z'))
		{
			if (!(scope->lookUp(value).getId().empty()))
			{
				scope->insert(Symbol(std::string(id), TypeStruct(scope->lookUp(value).getType()), true));
			}
			else
			{
				std::cout << "第" << lineNum << "行: 变量" << value << "未定义" << std::endl;
				flag = false;
			}
		}
		else
		{
			scope->insert(Symbol(std::string(id), TypeStruct(std::string("integer")), true));
		}
	}
	else
	{
		std::cout << "第" << lineNum << "行: 常量" << id << "重定义" << std::endl;
		flag = false;
	}
	for (auto i : children)
	{
		if (!(i->scopeCheck(scope)))
		{
			flag = false;
		}
	}
	return flag;
}

bool ParameterNode::scopeCheck(std::shared_ptr<SymbolTable> parentScope)
{
	bool flag = true;
	scope = parentScope;
	for (auto id : idlist)
	{
		if (scope->localLookUp(id).getId().empty() && scope->lookUp(id).getChildTable() == std::shared_ptr<SymbolTable>())
			scope->insert(Symbol(std::string(id),TypeStruct(std::string(simpleType),isVar)));
		else
		{
			std::cout << "第" << lineNum << "行: 参数" << id << "重定义" << std::endl;
			flag = false;
		}
	}
	for (auto i : children)
	{
		if (!(i->scopeCheck(scope)))
		{
			flag = false;
		}
	}
	return flag;
}

bool FunctionDeclarationNode::scopeCheck(std::shared_ptr<SymbolTable> parentScope)
{
	
	bool flag = true;
	scope = parentScope;
	if (scope->lookUp(id).getId().empty())
	{
		std::vector<TypeStruct> parameterType;
		int count = 0;
		for (int i = 0;; i++)
		{
			if (count >= parameterNum) break;
			TypeStruct tempType = children[i]->getType();
			for (int j = 0; j < children[i]->getIdNum(); j++)
			{
				parameterType.push_back(tempType);
				count++;
			}
		}
		scope->insert(Symbol(std::string(id), TypeStruct(simpleType), parameterType));
		scope = scope->initializationScope();
		for (auto i : children)
		{
			if (!(i->scopeCheck(scope)))
			{
				flag = false;
			}
		}
		return flag;
	}
	else
	{
		std::cout << "第" << lineNum << "行: 函数" << id << "重定义" << std::endl;
		flag = false;
	}
	return flag;
}

bool ProgramNode::scopeCheck(std::shared_ptr<SymbolTable> parentScope)
{
	bool flag = true;
	scope = parentScope;
	std::vector<TypeStruct> randomParameter;
	randomParameter.push_back(TypeStruct(std::string("integer")));
	scope->insert(Symbol(std::string("random"), TypeStruct(std::string("integer")),randomParameter));
	scope->initializationScope();
	scope->insert(Symbol(std::string("read"), TypeStruct()));
	scope->initializationScope();
	scope->insert(Symbol(std::string("write"), TypeStruct()));
	scope->initializationScope();
	scope->insert(Symbol(std::string("program")));
	scope = scope->initializationScope();
	for (auto i : children)
	{
		if (!(i->scopeCheck(scope)))
		{
			flag = false;
		}
	}
	return flag;
}