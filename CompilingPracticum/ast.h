#pragma once
#include<string>
#include<vector>
#include<utility>

class TypeStruct {
public:
	TypeStruct(std::string t){}
private:
	std::string simpleType;
	std::vector<std::pair<int, int>> period;
};

class ASTNode 
{
public:
	ASTNode():child(std::vector<ASTNode&>()){}
	virtual std::string codeGenerator() = 0;
	virtual bool scopeCheck() = 0;
	virtual bool typeCheck() = 0;
	virtual std::string getID() = 0;
	virtual TypeStruct getType() = 0;
protected:
	std::vector<ASTNode&> child;
};

class VarNode : public ASTNode
{
public:
	std::string codeGenerator() override;
	bool scopeCheck() override;
	bool typeCheck() override;
	std::string getID() override;
	TypeStruct getType() override;
private:
	std::string id;
	std::vector<int> subscript;
};

class ConstNode : public ASTNode
{
public:
	std::string codeGenerator() override;
	bool scopeCheck() override;
	bool typeCheck() override;
	std::string getID() override;
	TypeStruct getType() override;
private:
	std::string value;
	std::string simpleType;
};

class FunctionCallNode : public ASTNode
{
public:
	std::string codeGenerator() override;
	bool scopeCheck() override;
	bool typeCheck() override;
	std::string getID() override;
	TypeStruct getType() override;
private:
	std::string id;
	std::string simpleType;
};

class ExpressionNode : public ASTNode
{
public:
	std::string codeGenerator() override;
	bool scopeCheck() override;
	bool typeCheck() override;
	std::string getID() override;
	TypeStruct getType() override;
private:
	std::string operation;
};

class AssignmentNode : public ASTNode
{
public:
	std::string codeGenerator() override;
	bool scopeCheck() override;
	bool typeCheck() override;
	std::string getID() override;
	TypeStruct getType() override;
private:

};

class IfNode : public ASTNode
{
public:
	std::string codeGenerator() override;
	bool scopeCheck() override;
	bool typeCheck() override;
	std::string getID() override;
	TypeStruct getType() override;
private:

};

class ForNode : public ASTNode
{
public:
	std::string codeGenerator() override;
	bool scopeCheck() override;
	bool typeCheck() override;
	std::string getID() override;
	TypeStruct getType() override;
private:

};

class WhileNode : public ASTNode
{
public:
	std::string codeGenerator() override;
	bool scopeCheck() override;
	bool typeCheck() override;
	std::string getID() override;
	TypeStruct getType() override;
private:

};

class CompoundNode : public ASTNode
{
public:
	std::string codeGenerator() override;
	bool scopeCheck() override;
	bool typeCheck() override;
	std::string getID() override;
	TypeStruct getType() override;
private:

};

class VarDeclarationNode : public ASTNode
{
public:
	std::string codeGenerator() override;
	bool scopeCheck() override;
	bool typeCheck() override;
	std::string getID() override;
	TypeStruct getType() override;
private:
	std::vector<std::string> idlist;
	TypeStruct type;
};

class ConstDeclarationNode : public ASTNode
{
public:
	std::string codeGenerator() override;
	bool scopeCheck() override;
	bool typeCheck() override;
	std::string getID() override;
	TypeStruct getType() override;
private:
	std::string id;
	std::string value;
};

class FunctionDeclarationNode : public ASTNode
{
public:
	std::string codeGenerator() override;
	bool scopeCheck() override;
	bool typeCheck() override;
	std::string getID() override;
	TypeStruct getType() override;
private:
	std::string id;
	std::string simpleType;
};

class ParameterNode : public ASTNode
{
public:
	std::string codeGenerator() override;
	bool scopeCheck() override;
	bool typeCheck() override;
	std::string getID() override;
	TypeStruct getType() override;
private:
	bool isVar;
	std::string simpleType;
	std::vector<std::string> idlist;
};

class ProgramNode : public ASTNode
{
public:
	std::string codeGenerator() override;
	bool scopeCheck() override;
	bool typeCheck() override;
	std::string getID() override;
	TypeStruct getType() override;
private:

};