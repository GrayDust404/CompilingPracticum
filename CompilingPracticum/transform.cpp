#include"parser.h"
#include"ast.h"

extern std::vector<ParseTreeNode> parseTree;
extern int parseTreeRoot;

std::vector<std::shared_ptr<ASTNode>> transform(int root)
{
	std::string token = parseTree[root].getToken();
	if (token == std::string("programstruct"))
	{
		std::vector<std::shared_ptr<ASTNode>> ASTChildren;
		std::vector<int> children = parseTree[root].getChildren();
		for (int i = 0; i < children.size(); i++)
		{
			std::vector<std::shared_ptr<ASTNode>> tempChildren = transform(children[i]);
			if (tempChildren.size())
			{
				for (auto j : tempChildren)
				{
					ASTChildren.push_back(j);
				}
			}
		}
		std::vector<std::shared_ptr<ASTNode>> result;
		result.push_back(std::shared_ptr<ASTNode>(new ProgramNode(ASTChildren)));
		return result;
	}
	else if (token == std::string("program_head"))
	{
		return std::vector<std::shared_ptr<ASTNode>>();
	}
	else if (token == std::string("id"))
	{
		
	}
	else if (token == std::string("idlist"))
	{

	}
	else if (token == std::string("program_body"))
	{

	}
	else if (token == std::string("compound_statement"))
	{

	}
	else if (token == std::string("statement_list"))
	{

	}
	else if (token == std::string("statement"))
	{

	}
	else if (token == std::string("variable"))
	{

	}
	else if (token == std::string("assignop"))
	{

	}
	else if (token == std::string("expression"))
	{

	}
	else if (token == std::string("simple_expression"))
	{

	}
	else if (token == std::string("term"))
	{

	}
	else if (token == std::string("factor"))
	{

	}
	else
	{

	}

}