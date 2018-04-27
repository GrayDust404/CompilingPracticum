#include<iostream>
#include"parser.h"
#include"ast.h"
#include"transform.h"
#include"symbol_table.h"
extern std::vector<ParseTreeNode> parseTree;
extern int parseTreeRoot;

std::shared_ptr<ASTNode> transformFactor(int root)
{
	std::vector<int> children = parseTree[root].getChildren();
	for (int i = 0; i < children.size(); i++)
	{
		std::string token = parseTree[children[i]].getToken();
		if (token == std::string("num")|| token == std::string("digits"))
		{
			return std::shared_ptr<ASTNode>(new ConstNode(parseTree[children[i]].getValue(),parseTree[children[i]].getLineNum()));
		}
		else if (token == std::string("variable"))
		{
			return transformVariable(children[i]);
		}
		else if (token == std::string("id"))
		{
			std::string id = parseTree[children[i]].getValue();
			std::vector<std::shared_ptr<ASTNode>> ASTChildren = transformExpressionList(children[i + 2]);
			return std::shared_ptr<ASTNode>(new FunctionCallNode(id, ASTChildren, parseTree[children[i]].getLineNum()));
		}
		else if (token == std::string("leftB"))
		{
			return transformExpression(children[i + 1]);
		}
		else if (token == std::string("not") || token == std::string("sub"))
		{
			std::string operation = parseTree[children[i]].getValue();
			std::vector<std::shared_ptr<ASTNode>> ASTChildren;
			ASTChildren.push_back(transformFactor(children[i + 1]));
			return std::shared_ptr<ASTNode>(new ExpressionNode(operation, ASTChildren, parseTree[children[i]].getLineNum()));
		}
	}
	return std::shared_ptr<ASTNode>();
}

std::shared_ptr<ASTNode> transformTerm(int root)
{
	std::vector<int> children = parseTree[root].getChildren();
	std::vector<std::shared_ptr<ASTNode>> ASTChildren;
	std::string operation;
	for (int i = 0; i < children.size(); i++)
	{
		std::string token = parseTree[children[i]].getToken();
		if (token == std::string("factor"))
		{
			if (i == 2)
			{
				ASTChildren.push_back(transformTerm(children[i - 2]));
				ASTChildren.push_back(transformFactor(children[i]));
				operation = parseTree[children[i - 1]].getValue();
				return std::shared_ptr<ASTNode>(new ExpressionNode(operation, ASTChildren, parseTree[children[i-1]].getLineNum()));
			}
			else if (i == 0)
				return transformFactor(children[i]);
		}
	}
	return std::shared_ptr<ASTNode>();
}

std::shared_ptr<ASTNode> transformSimpleExpression(int root)
{
	std::vector<int> children = parseTree[root].getChildren();
	std::vector<std::shared_ptr<ASTNode>> ASTChildren;
	std::string operation;
	for (int i = 0; i < children.size(); i++)
	{
		std::string token = parseTree[children[i]].getToken();
		if (token == std::string("term"))
		{
			if (i == 2)
			{
				ASTChildren.push_back(transformSimpleExpression(children[i - 2]));
				ASTChildren.push_back(transformTerm(children[i]));
				operation = parseTree[children[i - 1]].getValue();
				return std::shared_ptr<ASTNode>(new ExpressionNode(operation, ASTChildren, parseTree[children[i-1]].getLineNum()));
			}
			else if (i == 0)
				return transformTerm(children[i]);
		}
	}
	return std::shared_ptr<ASTNode>();
}

std::shared_ptr<ASTNode> transformExpression(int root)
{
	std::vector<int> children = parseTree[root].getChildren();
	std::vector<std::shared_ptr<ASTNode>> ASTChildren;
	std::string operation;
	int lineNum = 0;
	for (int i = 0; i < children.size(); i++)
	{
		std::string token = parseTree[children[i]].getToken();
		if (token == std::string("simple_expression"))
		{
			ASTChildren.push_back(transformSimpleExpression(children[i]));
		}
		else
		{
			operation = parseTree[children[i]].getValue();
			lineNum = parseTree[children[i]].getLineNum();
		}
	}
	if (ASTChildren.size() < 2)
		return ASTChildren[0];
	return std::shared_ptr<ASTNode>(new ExpressionNode(operation, ASTChildren,lineNum));
}

std::vector<std::shared_ptr<ASTNode>> transformExpressionList(int root)
{
	std::vector<int> children = parseTree[root].getChildren();
	std::vector<std::shared_ptr<ASTNode>> result;
	for (int i = 0; i < children.size(); i++)
	{
		std::string token = parseTree[children[i]].getToken();
		if (token == std::string("expression_list"))
		{
			result = transformExpressionList(children[i]);
		}
		else if (token == std::string("expression"))
		{
			result.push_back(transformExpression(children[i]));
			return result;
		}
	}
	return result;
}

std::shared_ptr<ASTNode> transformVarPart(int root, std::string id)
{
	std::vector<int> children = parseTree[root].getChildren();
	int lineNum = 0;
	for (int i = 0; i < children.size(); i++)
	{
		std::string token = parseTree[children[i]].getToken();
		if (token == std::string("expression_list"))
		{
			return std::shared_ptr<ASTNode>(new VarpartNode(id,transformExpressionList(children[i]),lineNum));
		}
		if (token == std::string("leftSB"))
		{
			lineNum = parseTree[children[i]].getLineNum();
		}
	}
	return std::shared_ptr<ASTNode>();
}

std::shared_ptr<ASTNode> transformVariable(int root)
{
	std::vector<int> children = parseTree[root].getChildren();
	for (int i = 0; i < children.size(); i++)
	{
		std::string token = parseTree[children[i]].getToken();
		if (token == std::string("id"))
		{
			std::vector<std::shared_ptr<ASTNode>> ASTChildren;
			std::shared_ptr<ASTNode> temp = transformVarPart(children[i + 1], parseTree[children[i]].getValue());
			if(temp)
				ASTChildren.push_back(temp);
			return std::shared_ptr<ASTNode>(new VarNode(parseTree[children[i]].getValue(),ASTChildren, parseTree[children[i]].getLineNum()));
		}
	}
	return std::shared_ptr<ASTNode>();
}

std::shared_ptr<ASTNode> transformFunctionCall(int root)
{
	std::vector<int> children = parseTree[root].getChildren();
	std::string id;
	std::vector<std::shared_ptr<ASTNode>> ASTChildren;
	int lineNum = 0;
	for (int i = 0; i < children.size(); i++)
	{
		std::string token = parseTree[children[i]].getToken();
		if (token == std::string("id"))
		{
			id = parseTree[children[i]].getValue();
			lineNum = parseTree[children[i]].getLineNum();
		}
		else if (token == std::string("expression_list"))
		{
			ASTChildren = transformExpressionList(children[i]);
		}
	}
	return std::shared_ptr<ASTNode>(new FunctionCallNode(id, ASTChildren,lineNum));
}

std::shared_ptr<ASTNode> transformElsePart(int root)
{
	std::vector<int> children = parseTree[root].getChildren();
	for (int i = 0; i < children.size(); i++)
	{
		std::string token = parseTree[children[i]].getToken();
		if (token == std::string("statement"))
		{
			return transformStatement(children[i]);
		}
	}
	return std::shared_ptr<ASTNode>();
}

std::shared_ptr<ASTNode> transformStatement(int root)
{
	std::vector<int> children = parseTree[root].getChildren();
	for (int i = 0; i < children.size(); i++)
	{
		std::string token = parseTree[children[i]].getToken();
		if (token == std::string("variable"))
		{
			std::vector<std::shared_ptr<ASTNode>> ASTChildren;
			ASTChildren.push_back(transformVariable(children[i]));
			ASTChildren.push_back(transformExpression(children[i+2]));
			return std::shared_ptr<ASTNode>(new AssignmentNode(ASTChildren,parseTree[children[i+1]].getLineNum()));
		}
		else if (token == std::string("procedure_call"))
		{
			return transformFunctionCall(children[i]);
		}
		else if (token == std::string("compound_statement"))
		{
			return transformCompound(children[i]);
		}
		else if (token == std::string("if"))
		{
			std::shared_ptr<ASTNode> condition = transformExpression(children[i + 1]);
			std::shared_ptr<ASTNode> thenPart = transformStatement(children[i + 3]);
			std::shared_ptr<ASTNode> elsePart = transformElsePart(children[i + 4]);
			std::vector<std::shared_ptr<ASTNode>> ASTChildren;
			ASTChildren.push_back(condition);
			if (thenPart)
				ASTChildren.push_back(thenPart);
			if (elsePart) 
				ASTChildren.push_back(elsePart);
			return std::shared_ptr<ASTNode>(new IfNode(ASTChildren, parseTree[children[i]].getLineNum()));
		}
		else if (token == std::string("for"))
		{
			std::string iterator = parseTree[children[i + 1]].getValue();
			std::shared_ptr<ASTNode> low = transformExpression(children[i + 3]);
			std::shared_ptr<ASTNode> heigh = transformExpression(children[i + 5]);
			std::shared_ptr<ASTNode> forBody = transformStatement(children[i + 7]);
			std::vector<std::shared_ptr<ASTNode>> ASTChildren;
			ASTChildren.push_back(low);
			ASTChildren.push_back(heigh);
			if (forBody)
				ASTChildren.push_back(forBody);
			return std::shared_ptr<ASTNode>(new ForNode(iterator, ASTChildren, parseTree[children[i]].getLineNum()));
		}
		else if (token == std::string("while"))
		{
			std::shared_ptr<ASTNode> condition = transformExpression(children[i + 1]);
			std::shared_ptr<ASTNode> whileBody = transformStatement(children[i + 3]);
			std::vector<std::shared_ptr<ASTNode>> ASTChildren;
			ASTChildren.push_back(condition);
			if (whileBody)
				ASTChildren.push_back(whileBody);
			return std::shared_ptr<ASTNode>(new WhileNode(ASTChildren, parseTree[children[i]].getLineNum()));
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
	return std::shared_ptr<ASTNode>(new CompoundNode(ASTChildren,ASTChildren[0]->getLineNum()));
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
	int lineNum = 0;
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
			lineNum = parseTree[children[i]].getLineNum();
		}
	}
	return ParameterNode(idlist, simpleType,lineNum);
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
	return ParameterNode();
}

std::shared_ptr<ParameterNode> transformParameter(int root)
{
	std::vector<int> children = parseTree[root].getChildren();
	for (int i = 0; i < children.size(); i++)
	{
		std::string token = parseTree[children[i]].getToken();
		if (token == std::string("var_parameter"))
		{
			return std::shared_ptr<ParameterNode>(new ParameterNode(transformVarParameter(children[i])));
		}
		else if (token == std::string("value_parameter"))
		{
			return std::shared_ptr<ParameterNode>(new ParameterNode(transformValueParameter(children[i])));
		}
	}
	return std::shared_ptr<ParameterNode>();
}

std::vector<std::shared_ptr<ParameterNode>> transformParameterList(int root)
{
	std::vector<int> children = parseTree[root].getChildren();
	std::vector<std::shared_ptr<ParameterNode>> parameterList;
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
	std::vector<std::shared_ptr<ParameterNode>> parameterList;
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
	int lineNum = 0;
	for (int i = 0; i < children.size(); i++)
	{
		std::string token = parseTree[children[i]].getToken();
		if (token == std::string("id"))
		{
			id = parseTree[children[i]].getValue();
			lineNum = parseTree[children[i]].getLineNum();
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
	return std::shared_ptr<ASTNode>(new FunctionDeclarationNode(id, simpleType, formalParameter,lineNum));
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
			result.push_back(std::pair<int, int>(std::stoi(parseTree[children[i]].getValue()), std::stoi(parseTree[children[i + 2]].getValue())));
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
			int lineNum = parseTree[parseTree[children[i + 2]].getChildren()[0]].getLineNum();
			result.push_back(std::shared_ptr<ASTNode>(new VarDeclarationNode(transformIDList(children[i]),transformType(children[i+2]),lineNum)));
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
			result.push_back(std::shared_ptr<ASTNode>(new ConstDeclarationNode(parseTree[children[i]].getValue(), parseTree[children[i+2]].getValue(), parseTree[children[i]].getLineNum())));
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
	return std::shared_ptr<ASTNode>(new ProgramNode(ASTChildren,ASTChildren[0]->getLineNum()));
}

void test()
{
	std::shared_ptr<ASTNode> tree = transformProgramStruct(parseTreeRoot);
	std::shared_ptr<SymbolTable> symbolTable = std::shared_ptr<SymbolTable>(new SymbolTable(nullptr));
	if (tree->scopeCheck(symbolTable))
	{
		if (tree->typeCheck())
			std::cout << tree->codeGenerator();
	}
	system("pause");
	return;
} 