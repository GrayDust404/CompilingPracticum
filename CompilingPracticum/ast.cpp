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
		scope->insert(Symbol(std::string(id), type, std::string(), false));
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
		scope->insert(Symbol(std::string(id), TypeStruct(std::string("real")), std::string(), false));
	}
	else if (value.find(std::string("'")) != std::string::npos)
	{
		scope->insert(Symbol(std::string(id), TypeStruct(std::string("letter")), std::string(), false));
	}
	else if (!(scope->lookUp(value).getId().empty()))
	{
		//fix me
		scope->insert(Symbol(std::string(id), TypeStruct(std::string()), std::string(), false));
	}
	else
	{
		scope->insert(Symbol(std::string(id), TypeStruct(std::string("digits")), std::string(), false));
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
		scope->insert(Symbol(std::string(i),TypeStruct(std::string(simpleType),isVar),std::string(),false));
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
	// fix me ����ط��費��Ҫ����categories������ԣ����������Ϊ�˴������Ĳ���
	scope->insert(Symbol(std::string(id),std::string(simpleType)));
	scope = scope->initializationScope();
	for (auto i : children)
	{
		if (!(i->scopeCheck(scope)))
			flag = false;
	}
	return flag;
}
