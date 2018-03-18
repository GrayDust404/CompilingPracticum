#pragma once
#include<vector>
#include<string>
class ParseTreeNode 
{
public:
	ParseTreeNode(std::string t, std::string v, std::vector<int> c = std::vector<int>()) :token(t), value(v), childen(c) {}
private:
	std::string token;
	std::string value;
	std::vector<int> childen;
};