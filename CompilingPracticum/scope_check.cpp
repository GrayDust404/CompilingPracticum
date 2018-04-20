#include"ast.h"

bool ASTNode::scopeCheck(std::shared_ptr<SymbolTable> parentScope)
{
	bool flag = true;
	scope = parentScope;
	for (auto i : children)
	{
		if (!(i->scopeCheck(scope)))
			flag = false;
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
		//fix me
	}
	for (auto i : children)
	{
		if (!(i->scopeCheck(scope)))
			flag = false;
	}
	return flag;
}

bool FunctionCallNode::scopeCheck(std::shared_ptr<SymbolTable> parentScope)
{
	bool flag = true;
	scope = parentScope;
	if (scope->lookUp(id).getId().empty())
	{
		flag = false;
		//fix me
	}
	for (auto i : children)
	{
		if (!(i->scopeCheck(scope)))
			flag = false;
	}
	return  flag;
}

bool ForNode::scopeCheck(std::shared_ptr<SymbolTable> parentScope)
{
	bool flag = true;
	scope = parentScope;
	scope->insert(Symbol(std::string("for")));
	scope = scope->initializationScope();
	scope->insert(iterator);
	for (auto i : children)
	{
		if (!(i->scopeCheck(scope)))
			flag = false;
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
			flag = false;
	}
	return flag;
}

bool ConstDeclarationNode::scopeCheck(std::shared_ptr<SymbolTable> parentScope)
{
	bool flag = true;
	scope = parentScope;
	if (value.find(std::string(".")) != std::string::npos)
	{
		scope->insert(Symbol(std::string(id), TypeStruct(std::string("real")), false));
	}
	else if (value.find(std::string("'")) != std::string::npos)
	{
		scope->insert(Symbol(std::string(id), TypeStruct(std::string("letter")), false));
	}
	else if ((value[0]>'a'&&value[0]<'z') || (value[0]>'A'&&value[0]<'Z'))
	{
		//fix me
		if (!(scope->lookUp(value).getId().empty()))
		{
			scope->insert(Symbol(std::string(id), TypeStruct(scope->lookUp(value).getType()), false));
		}
		flag = false;
	}
	else
	{
		scope->insert(Symbol(std::string(id), TypeStruct(std::string("digits")), false));
	}
	for (auto i : children)
	{
		if (!(i->scopeCheck(scope)))
			flag = false;
	}
	return flag;
}

bool ParameterNode::scopeCheck(std::shared_ptr<SymbolTable> parentScope)
{
	bool flag = false;
	scope = parentScope;
	//fix me
	for (auto i : idlist)
	{
		// fix me
		scope->insert(Symbol(std::string(i),TypeStruct(std::string(simpleType),isVar), false));
	}
	for (auto i : children)
	{
		if (!(i->scopeCheck(scope)))
			flag = false;
	}
	return flag;
}

bool FunctionDeclarationNode::scopeCheck(std::shared_ptr<SymbolTable> parentScope)
{
	bool flag = true;
	scope = parentScope;
	// fix me 这个地方需不需要加上categories这个属性，这个属性是为了处理函数的操作
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
			flag = false;
	}
	return flag;
}
