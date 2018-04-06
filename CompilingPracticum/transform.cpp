#include"parser.h"
#include"ast.h"

extern std::vector<ParseTreeNode> parseTree;
extern int parseTreeRoot;

std::vector<std::shared_ptr<ASTNode>> transformProgramStruct(int root)
{
	std::vector<int> children = parseTree[root].getChildren();
	for (int i = 0; i < children.size(); i++)
	{
		std::string token = parseTree[children[i]].getToken();
		if(token == std::string(""))
	}
}