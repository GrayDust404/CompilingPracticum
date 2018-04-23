#include"symbol_table.h"

bool ASTNode::scopeCheck(std::shared_ptr<SymbolTable> parentScope)
{
	bool flag = true;
	scope = parentScope;
	for (auto i : children)
	{
		if (!(i->scopeCheck(scope)))
		{
			flag = false;
			printf("%dAST",i->getLineNum());
			printf(i->getID().c_str());
			
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
		printf(id.c_str());
		//fix me
	}
	for (auto i : children)
	{
		if (!(i->scopeCheck(scope)))
		{
			printf("%d", i->getLineNum());
			printf(i->getID().c_str());
			flag = false;
		}
			
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
		printf(id.c_str());
		//fix me
	}
	for (auto i : children)
	{
		if (!(i->scopeCheck(scope)))
		{
			printf("%d", i->getLineNum());
			printf(i->getID().c_str());
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
	scope->insert(iterator);
	for (auto i : children)
	{
		if (!(i->scopeCheck(scope)))
		{
			printf("%d", i->getLineNum());
			printf(i->getID().c_str());
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
			printf("%d", i->getLineNum());
			printf(i->getID().c_str());
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
			printf(value.c_str());
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
			printf("%d", i->getLineNum());
			printf(i->getID().c_str());
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
			printf("%dPara", i->getLineNum());
			printf(i->getID().c_str());
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
			printf("4%dFunc", i->getLineNum());
			printf(i->getID().c_str());
			flag = false;
		}
	}
	return flag;
}
