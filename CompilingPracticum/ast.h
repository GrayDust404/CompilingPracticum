#pragma once
#include<string>
#include<vector>

class ASTNode 
{
public:
	ASTNode():child(std::vector<ASTNode*>()){}
	virtual std::string codeGenerator();
	virtual bool scopeCheck();
	virtual bool typeCheck();
	virtual std::string getID();
	virtual std::string getType();
protected:
	std::vector<ASTNode&> child;
};

class IDNode : public ASTNode 
{
public:

private:
	std::string id;
};

class VarNode : public ASTNode
{
public:

private:

};

class ConstNode : public ASTNode
{
public:

private:

};

class PeriodNode : public ASTNode
{
public:

private:

};

class FunctionCallNode : public ASTNode
{
public:

private:

};

class ExpressionNode : public ASTNode
{
public:

private:

};

class AssignmentNode : public ASTNode
{
public:

private:

};

class IfNode : public ASTNode
{
public:

private:

};

class ForNode : public ASTNode
{
public:

private:

};

class WhileNode : public ASTNode
{
public:

private:

};

class CompoundNode : public ASTNode
{
public:

private:

};

class VarDeclarationNode : public ASTNode
{
public:

private:

};

class ConstDeclarationNode : public ASTNode
{
public:

private:

};

class FunctionDeclarationNode : public ASTNode
{
public:

private:

};

class TypeNode : public ASTNode
{
public:

private:

};

class ParameterNode : public ASTNode
{
public:

private:

};

class ProgramNode : public ASTNode
{
public:

private:

};