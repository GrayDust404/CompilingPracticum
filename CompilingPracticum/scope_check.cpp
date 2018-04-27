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
			std::cout << "第" << i->getLineNum() << "行：作用域错误 错误内容为" << i->getID() << std::endl;
		}
	}
	return flag;
}

bool VarNode::scopeCheck(std::shared_ptr<SymbolTable> parentScope)
{
	bool flag = true;
	scope = parentScope;
	if (scope->lookUp(id).getId().empty())
	{
		flag = false;
		std::cout << "第" << lineNum << "行，作用域错误 错误内容为变量" << id <<"未定义"<< std::endl;
		//fix me
	}
	for (auto i : children)
	{
		if (!(i->scopeCheck(scope)))
		{
			std::cout << "第" << i->getLineNum() << "行，作用域错误 错误内容为" << i->getID() << std::endl;
			flag = false;
		}
			
	}
	return flag;
}

bool FunctionCallNode::scopeCheck(std::shared_ptr<SymbolTable> parentScope)
{
	bool flag = true;
	scope = parentScope;
	if (scope->lookUp(id).getId().empty() && id != std::string("read") && id != std::string("write"))
	{
		flag = false;
		std::cout << "第" << lineNum << "行，作用域错误 错误内容为函数" << id << "未定义" << std::endl;
	}
	for (auto i : children)
	{
		if (!(i->scopeCheck(scope)))
		{
			std::cout << "第" << i->getLineNum() << "行，作用域错误 错误内容为" << i->getID() << std::endl;
			flag = false;
		}

	}
	return  flag;
}

bool ForNode::scopeCheck(std::shared_ptr<SymbolTable> parentScope)
{
	bool flag = true;
	scope = parentScope;
	scope->insert(Symbol(std::string("for")));
	scope = scope->initializationScope();
	scope->insert(Symbol(iterator, TypeStruct(std::string("integer"))));
	for (auto i : children)
	{
		if (!(i->scopeCheck(scope)))
		{
			std::cout << "第" << i->getLineNum() << "行，作用域错误 错误内容为" << i->getID() << std::endl;
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
		scope->insert(Symbol(std::string(id), type, false));
	}
	for (auto i : children)
	{
		if (!(i->scopeCheck(scope)))
		{
			std::cout << "第" << i->getLineNum() << "行，作用域错误 错误内容为" << i->getID() << std::endl;
			flag = false;
		}
	}
	return flag;
}

bool ConstDeclarationNode::scopeCheck(std::shared_ptr<SymbolTable> parentScope)
{
	bool flag = true;
	scope = parentScope;
	if (value.find(std::string(".")) != std::string::npos)
	{
		scope->insert(Symbol(std::string(id), TypeStruct(std::string("real")),true));
	}
	else if (value.find(std::string("'")) != std::string::npos)
	{
		scope->insert(Symbol(std::string(id), TypeStruct(std::string("char")),true));
	}
	else if ((value[0]>'a'&&value[0]<'z') || (value[0]>'A'&&value[0]<'Z'))
	{
		if (!(scope->lookUp(value).getId().empty()))
		{
			scope->insert(Symbol(std::string(id), TypeStruct(scope->lookUp(value).getType()),true));
		}
		else
		{
			std::cout << "第" << lineNum << "行，作用域错误 错误内容为变量" << value << "未定义" << std::endl;
			flag = false;
		}
	}
	else
	{
		scope->insert(Symbol(std::string(id), TypeStruct(std::string("digits")),true));
	}
	for (auto i : children)
	{
		if (!(i->scopeCheck(scope)))
		{
			std::cout << "第" << i->getLineNum() << "行，作用域错误 错误内容为" << i->getID() << std::endl;
			flag = false;
		}
	}
	return flag;
}

bool ParameterNode::scopeCheck(std::shared_ptr<SymbolTable> parentScope)
{
	bool flag = true;
	scope = parentScope;
	for (auto i : idlist)
	{
		scope->insert(Symbol(std::string(i),TypeStruct(std::string(simpleType),isVar)));
	}
	for (auto i : children)
	{
		if (!(i->scopeCheck(scope)))
		{
			std::cout << "第" << i->getLineNum() << "行，作用域错误 错误内容为" << i->getID() << std::endl;
			flag = false;
		}
	}
	return flag;
}

bool FunctionDeclarationNode::scopeCheck(std::shared_ptr<SymbolTable> parentScope)
{
	
	bool flag = true;
	scope = parentScope;
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
	scope->insert(Symbol(std::string(id),TypeStruct(simpleType),parameterType));
	scope = scope->initializationScope();
	for (auto i : children)
	{
		if (!(i->scopeCheck(scope)))
		{
			std::cout << "第" << i->getLineNum() << "行，作用域错误 错误内容为" << i->getID() << std::endl;
			flag = false;
		}
	}
	return flag;
}

bool ProgramNode::scopeCheck(std::shared_ptr<SymbolTable> parentScope)
{
	bool flag = true;
	scope = parentScope;
	scope->insert(Symbol(std::string("program")));
	std::vector<TypeStruct> randomParameter;
	randomParameter.push_back(TypeStruct(std::string("integer")));
	scope->insert(Symbol(std::string("random"), TypeStruct(std::string("integer")),randomParameter));
	scope = scope->initializationScope();
	for (auto i : children)
	{
		if (!(i->scopeCheck(scope)))
		{
			flag = false;
			std::cout << "第" << i->getLineNum() << "行，作用域错误 错误内容为" << i->getID() << std::endl;
		}
	}
	return flag;
}