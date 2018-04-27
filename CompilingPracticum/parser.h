#pragma once
#include<vector>
#include<string>
class ParseTreeNode;
extern std::vector<ParseTreeNode> parseTree;
class ParseTreeNode 
{
public:
	ParseTreeNode(std::string t, std::string v, std::vector<int> c)
	{
		if (c.size() == 0)
			lineNum = 0;
		else
			lineNum = parseTree[c[0]].getLineNum();
		token = t;
		value = v;
		children = c;
		parent = -1;
	}
	ParseTreeNode(std::string t, std::string v, int l) :lineNum(l), token(t), value(v), children(std::vector<int>()),parent(-1) {}
	int getLineNum() { return lineNum; }
	std::string getToken() { return token; }
	std::string getValue() { return value; }
	std::vector<int> getChildren() { return children; }
	int getParent() { return parent; }
	void setParent(int p) { parent = p; }
private:
	int lineNum;
	std::string token;
	std::string value;
	std::vector<int> children;
	int parent;
};