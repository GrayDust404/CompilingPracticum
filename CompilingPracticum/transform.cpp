#include"parser.h"
#include"ast.h"

extern std::vector<ParseTreeNode> parseTree;
extern int parseTreeRoot;

std::shared_ptr<ASTNode> transformStatement(int root)
{
	std::vector<int> children = parseTree[root].getChildren();
	for (int i = 0; i < children.size(); i++)
	{
		std::string token = parseTree[children[i]].getToken();
		if (token == std::string("variable"))
		{
			
		}
		else if (token == std::string("procedure_call"))
		{

		}
		else if (token == std::string("compound_statement"))
		{

		}
		else if (token == std::string("if"))
		{

		}
		else if (token == std::string("for"))
		{

		}
		else if (token == std::string("while"))
		{

		}
	}
	return std::shared_ptr<ASTNode>();
}

std::vector<std::shared_ptr<ASTNode>> transformStatementList(int root)
{
	std::vector<int> children = parseTree[root].getChildren();
	std::vector<std::shared_ptr<ASTNode>> result;
	for (int i = 0; i < children.size(); i++)
	{
		std::string token = parseTree[children[i]].getToken();
		if (token == std::string("statement_list"))
		{
			result = transformStatementList(children[i]);
		}
		else if (token == std::string("statement"))
		{
			std::shared_ptr<ASTNode> temp = transformStatement(children[i]);
			if(temp)
				result.push_back(temp);
		}
	}
	return result;
}

std::shared_ptr<ASTNode> transformCompound(int root)
{
	std::vector<int> children = parseTree[root].getChildren();
	std::vector<std::shared_ptr<ASTNode>> ASTChildren;
	for (int i = 0; i < children.size(); i++)
	{
		std::string token = parseTree[children[i]].getToken();
		if (token == std::string("statement_list"))
		{
			ASTChildren = transformStatementList(children[i]);
		}
	}
	return std::shared_ptr<ASTNode>(new CompoundNode(ASTChildren));
}

std::vector<std::shared_ptr<ASTNode>> transformSubprogramBody(int root)
{
	std::vector<int> children = parseTree[root].getChildren();
	std::vector<std::shared_ptr<ASTNode>> result;
	for (int i = 0; i < children.size(); i++)
	{
		std::string token = parseTree[children[i]].getToken();
		if (token == std::string("const_declarations"))
		{
			std::vector<std::shared_ptr<ASTNode>> temp = transformConstDeclarationS(children[i]);
			for (auto i : temp)
			{
				result.push_back(i);
			}
		}
		else if (token == std::string("var_declarations"))
		{
			std::vector<std::shared_ptr<ASTNode>> temp = transformVarDeclarationS(children[i]);
			for (auto i : temp)
			{
				result.push_back(i);
			}
		}
		else if (token == std::string("compound_statement"))
		{
			result.push_back(transformCompound(children[i]));
		}
	}
	return result;
}

ParameterNode transformValueParameter(int root)
{
	std::vector<int> children = parseTree[root].getChildren();
	std::vector<std::string> idlist;
	std::string simpleType;
	for (int i = 0; i < children.size(); i++)
	{
		std::string token = parseTree[children[i]].getToken();
		if (token == std::string("idlist"))
		{
			idlist = transformIDList(children[i]);
		}
		else if(token == std::string("simple_type"))
		{
			simpleType = parseTree[children[i]].getValue();
		}
	}
	return ParameterNode(idlist, simpleType);
}

ParameterNode transformVarParameter(int root)
{
	std::vector<int> children = parseTree[root].getChildren();
	for (int i = 0; i < children.size(); i++)
	{
		std::string token = parseTree[children[i]].getToken();
		if (token == std::string("value_parameter"))
		{
			ParameterNode result = transformValueParameter(children[i]);
			result.setIsVar();
			return result;
		}
	}
}

std::shared_ptr<ParameterNode> transformParameter(int root)
{
	std::vector<int> children = parseTree[root].getChildren();
	for (int i = 0; i < children.size(); i++)
	{
		std::string token = parseTree[children[i]].getToken();
		if (token == std::string("var_parameter"))
		{
			return std::shared_ptr<ASTNode>(new ParameterNode(transformVarParameter(children[i])));
		}
		else if (token == std::string("value_parameter"))
		{
			return std::shared_ptr<ASTNode>(new ParameterNode(transformValueParameter(children[i])));
		}
	}
	return std::shared_ptr<ASTNode>();
}

std::vector<std::shared_ptr<ParameterNode>> transformParameterList(int root)
{
	std::vector<int> children = parseTree[root].getChildren();
	std::vector<std::shared_ptr<ASTNode>> parameterList;
	for (int i = 0; i < children.size(); i++)
	{
		std::string token = parseTree[children[i]].getToken();
		if (token == std::string("parameter_list"))
		{
			parameterList = transformParameterList(children[i]);
		}
		else if (token == std::string("parameter"))
		{
			parameterList.push_back(transformParameter(children[i]));
		}
	}
	return parameterList;
}

std::vector<std::shared_ptr<ParameterNode>> transformFormalParameter(int root)
{
	std::vector<int> children = parseTree[root].getChildren();
	std::vector<std::shared_ptr<ASTNode>> parameterList;
	for (int i = 0; i < children.size(); i++)
	{
		std::string token = parseTree[children[i]].getToken();
		if (token == std::string("parameter_list"))
		{
			parameterList = transformParameterList(children[i]);
		}
	}
	return parameterList;
}

std::shared_ptr<ASTNode> transformSubprogramHead(int root)
{
	std::vector<int> children = parseTree[root].getChildren();
	std::vector<std::shared_ptr<ParameterNode>> formalParameter;
	std::string id;
	std::string simpleType;
	for (int i = 0; i < children.size(); i++)
	{
		std::string token = parseTree[children[i]].getToken();
		if (token == std::string("id"))
		{
			id = parseTree[children[i]].getValue();
		}
		else if (token == std::string("formal_parameter"))
		{
			formalParameter = transformFormalParameter(children[i]);
		}
		else if (token == std::string("simple_type"))
		{
			simpleType = parseTree[children[i]].getValue();
		}
	}
	return std::shared_ptr<ASTNode>(new FunctionDeclarationNode(id, simpleType, formalParameter));
}

std::shared_ptr<ASTNode> transformSubprogram(int root)
{
	std::vector<int> children = parseTree[root].getChildren();
	std::vector<std::shared_ptr<ASTNode>> body;
	std::shared_ptr<ASTNode> subprogram;
	for (int i = 0; i < children.size(); i++)
	{
		std::string token = parseTree[children[i]].getToken();
		if (token == std::string("subprogram_head"))
		{
			subprogram = transformSubprogramHead(children[i]);
		}
		else if (token == std::string("subprogram_body"))
		{
			body = transformSubprogramBody(children[i]);
			subprogram->addChildren(body);
		}
	}
	return subprogram;
}

std::vector<std::shared_ptr<ASTNode>> transformSubprogramDeclarationS(int root)
{
	std::vector<int> children = parseTree[root].getChildren();
	std::vector<std::shared_ptr<ASTNode>> result;
	for (int i = 0; i < children.size(); i++)
	{
		std::string token = parseTree[children[i]].getToken();
		if (token == std::string("subprogram_declarations"))
		{
			result = transformSubprogramDeclarationS(children[i]);
		}
		else if (token == std::string("subprogram"))
		{
			result.push_back(transformSubprogram(children[i]));
			return result;
		}
	}
	return result;
}

std::vector<std::pair<int, int>> transformPeriod(int root)
{
	std::vector<int> children = parseTree[root].getChildren();
	std::vector<std::pair<int, int>> result;
	for (int i = 0; i < children.size(); i++)
	{
		std::string token = parseTree[children[i]].getToken();
		if (token == std::string("digits"))
		{
			result.push_back(std::pair<int, int>(std::stoi(parseTree[children[i]].getValue()), std::stoi(parseTree[children[i + 3]].getValue())));
			return result;
		}
		else if (token == std::string("period"))
		{
			result = transformPeriod(children[i]);
		}
	}
	return result;
}

TypeStruct transformType(int root) 
{
	std::vector<int> children = parseTree[root].getChildren();
	std::string simpleType;
	std::vector<std::pair<int, int>> period;
	for (int i = 0; i < children.size(); i++)
	{
		std::string token = parseTree[children[i]].getToken();
		if (token == std::string("simple_type"))
		{
			simpleType = parseTree[children[i]].getValue();
		}
		else if (token == std::string("period"))
		{
			period = transformPeriod(children[i]);
		}
	}
	return TypeStruct(simpleType,period);
}

std::vector<std::string> transformIDList(int root)
{
	std::vector<int> children = parseTree[root].getChildren();
	std::vector<std::string> result;
	for (int i = 0; i < children.size(); i++)
	{
		std::string token = parseTree[children[i]].getToken();
		if (token == std::string("id"))
		{
			result.push_back(parseTree[children[i]].getValue());
			return result;
		}
		else if (token == std::string("idlist"))
		{
			result = transformIDList(children[i]);
		}
	}
	return result;
}

std::vector<std::shared_ptr<ASTNode>> transformVarDeclaration(int root)
{
	std::vector<int> children = parseTree[root].getChildren();
	std::vector<std::shared_ptr<ASTNode>> result;
	for (int i = 0; i < children.size(); i++)
	{
		std::string token = parseTree[children[i]].getToken();
		if (token == std::string("idlist"))
		{
			result.push_back(std::shared_ptr<ASTNode>(new VarDeclarationNode(transformIDList(children[i]),transformType(children[i+2]))));
			return result;
		}
		else if (token == std::string("var_declaration"))
		{
			result = transformVarDeclaration(children[i]);
		}
	}
	return result;
}

std::vector<std::shared_ptr<ASTNode>> transformVarDeclarationS(int root)
{
	std::vector<int> children = parseTree[root].getChildren();
	for (int i = 0; i < children.size(); i++)
	{
		std::string token = parseTree[children[i]].getToken();
		if (token == std::string("var_declaration"))
		{
			return transformVarDeclaration(children[i]);
		}
	}
	return std::vector<std::shared_ptr<ASTNode>>();
}

std::vector<std::shared_ptr<ASTNode>> transformConstDeclaration(int root)
{
	std::vector<int> children = parseTree[root].getChildren();
	std::vector<std::shared_ptr<ASTNode>> result;
	for (int i = 0; i < children.size(); i++)
	{
		std::string token = parseTree[children[i]].getToken();
		if (token == std::string("id"))
		{
			result.push_back(std::shared_ptr<ASTNode>(new ConstDeclarationNode(parseTree[children[i]].getValue(), parseTree[children[i+2]].getValue())));
			return result;
		}
		else if (token == std::string("const_declaration"))
		{
			result = transformConstDeclaration(children[i]);
		}
	}
	return result;
}

std::vector<std::shared_ptr<ASTNode>> transformConstDeclarationS(int root)
{
	std::vector<int> children = parseTree[root].getChildren();
	for (int i = 0; i < children.size(); i++)
	{
		std::string token = parseTree[children[i]].getToken();
		if (token == std::string("const_declaration"))
		{
			return transformConstDeclaration(children[i]);
		}
	}
	return std::vector<std::shared_ptr<ASTNode>>();
}

std::vector<std::shared_ptr<ASTNode>> transformProgramBody(int root)
{
	std::vector<int> children = parseTree[root].getChildren();
	std::vector<std::shared_ptr<ASTNode>> result;
	for (int i = 0; i < children.size(); i++)
	{
		std::string token = parseTree[children[i]].getToken();
		if (token == std::string("const_declarations"))
		{
			std::vector<std::shared_ptr<ASTNode>> temp = transformConstDeclarationS(children[i]);
			for (auto i : temp)
			{
				result.push_back(i);
			}
		}
		else if (token == std::string("var_declarations"))
		{
			std::vector<std::shared_ptr<ASTNode>> temp = transformVarDeclarationS(children[i]);
			for (auto i : temp)
			{
				result.push_back(i);
			}
		}
		else if (token == std::string("subprogram_declarations"))
		{
			std::vector<std::shared_ptr<ASTNode>> temp = transformSubprogramDeclarationS(children[i]);
			for (auto i : temp)
			{
				result.push_back(i);
			}
		}
		else if (token == std::string("compound_statement"))
		{
			result.push_back(transformCompound(children[i]));
		}
	}
	return result;
}

std::shared_ptr<ASTNode> transformProgramStruct(int root)
{
	std::vector<int> children = parseTree[root].getChildren();
	std::vector<std::shared_ptr<ASTNode>> ASTChildren;
	for (int i = 0; i < children.size(); i++)
	{
		std::string token = parseTree[children[i]].getToken();
		if (token == std::string("program_body"))
		{
			ASTChildren = transformProgramBody(children[i]);
		}
	}
	return std::shared_ptr<ASTNode>(new ProgramNode(ASTChildren));
}