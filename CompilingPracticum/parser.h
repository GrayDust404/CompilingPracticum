#pragma once
#include<vector>
#include<string>
class ParseTreeNode 
{
public:
	ParseTreeNode(std::string t, std::string v, std::vector<int> c) :lineNum(0),token(t), value(v), childen(c) {}
	ParseTreeNode(std::string t, std::string v, int l) :lineNum(l), token(t), value(v), childen(std::vector<int>()) {}
private:
	int lineNum;
	std::string token;
	std::string value;
	std::vector<int> childen;
};