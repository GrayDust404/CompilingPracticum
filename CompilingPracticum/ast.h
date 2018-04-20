#pragma once
#include<string>
#include<vector>
#include<utility>
#include<memory>
#include"symbol_table.h"

class TypeStruct {
public:
	TypeStruct() = default;
	TypeStruct(std::string _simpleType, bool _isRef = false) :simpleType(_simpleType), isRef(_isRef), period(std::vector<std::pair<int, int>>()) {}
	TypeStruct(std::string _simpleType, std::vector<std::pair<int, int>> _peroid) :simpleType(_simpleType), isRef(false), period(_peroid) {}
	std::string getSimpleType() { return simpleType; }
	std::vector<std::pair<int, int>> getPeroid() { return period; }
	bool checkRef() { return isRef; }
private:
	std::string simpleType;
	std::vector<std::pair<int, int>> period;
	bool isRef; //符号表中记录是否引用
};

class ASTNode 
{
public:
	ASTNode() = default;
	ASTNode(std::vector<std::shared_ptr<ASTNode>> _children, int _lineNum) :children(_children), lineNum(_lineNum) {}
	void addChildren(std::vector<std::shared_ptr<ASTNode>> newChildren)
	{
		for (auto i : newChildren)
		{
			children.push_back(i);
		}
	}
	virtual std::string codeGenerator() = 0;
	virtual bool scopeCheck(std::shared_ptr<SymbolTable> parentScope);
	virtual bool typeCheck() = 0;
	virtual std::string getID() { return std::string(); }
	virtual TypeStruct getType() { return TypeStruct(); }
	int getLineNum() { return lineNum; }
protected:
	std::vector<std::shared_ptr<ASTNode>> children;
	int lineNum;
	std::shared_ptr<SymbolTable> scope;
};

class VarNode : public ASTNode
{
public:
	VarNode(std::string _id, std::vector<std::shared_ptr<ASTNode>> _children, int _lineNum) :ASTNode(_children,_lineNum) { id = _id; }
	std::string codeGenerator() override { return std::string(); }
	bool scopeCheck(std::shared_ptr<SymbolTable> parentScope) override;
	bool typeCheck() override { return false; }
	std::string getID() override { return std::string(); }
	TypeStruct getType() override { return TypeStruct(); }
private:
	std::string id;
};

class VarpartNode : public ASTNode
{
public:
	VarpartNode(std::vector<std::shared_ptr<ASTNode>> _children, int _lineNum) :ASTNode(_children,_lineNum) {}
	std::string codeGenerator() override { return std::string(); }
	bool typeCheck() override { return false; }
	std::string getID() override { return std::string(); }
	TypeStruct getType() override { return TypeStruct(); }
private:

};

class ConstNode : public ASTNode
{
public:
	ConstNode(std::string _value,int _lineNum) :ASTNode(std::vector<std::shared_ptr<ASTNode>>(), _lineNum)
	{
		value = _value;
	}
	std::string codeGenerator() override { return std::string(); }
	bool typeCheck() override { return false; }
	TypeStruct getType() override { return TypeStruct();}
private:
	std::string value;
};

class FunctionCallNode : public ASTNode
{
public:
	FunctionCallNode(std::string _id, std::vector<std::shared_ptr<ASTNode>> _children, int _lineNum) :ASTNode(_children, _lineNum)
	{
		id = _id;
	}
	std::string codeGenerator() override { return std::string(); }
	bool scopeCheck(std::shared_ptr<SymbolTable> parentScope) override;
	bool typeCheck() override { return false; }
	std::string getID() override { return std::string(); }
	TypeStruct getType() override { return TypeStruct(); }
private:
	std::string id;
};

class ExpressionNode : public ASTNode
{
public:
	ExpressionNode(std::string _operation, std::vector<std::shared_ptr<ASTNode>> _children, int _lineNum) :ASTNode(_children,_lineNum)
	{
		operation = _operation;
	}
	std::string codeGenerator() override { return std::string();}
	bool typeCheck() override { return false; }
	TypeStruct getType() override { return TypeStruct(); }
private:
	std::string operation;
};

class AssignmentNode : public ASTNode
{
public:
	AssignmentNode(std::vector<std::shared_ptr<ASTNode>> _children, int _lineNum) :ASTNode(_children,_lineNum) {}
	std::string codeGenerator() override { return std::string(); }
	bool typeCheck() override { return false; }
private:

};

class IfNode : public ASTNode
{
public:
	IfNode(std::vector<std::shared_ptr<ASTNode>> _children, int _lineNum) :ASTNode(_children, _lineNum) {}
	std::string codeGenerator() override { return std::string(); }
	bool typeCheck() override { return false; }
private:

};

class ForNode : public ASTNode
{
public:
	ForNode(std::string _iterator, std::vector<std::shared_ptr<ASTNode>> _children, int _lineNum) :ASTNode(_children, _lineNum)
	{
		iterator = _iterator;
	}
	std::string codeGenerator() override { return std::string(); }
	bool scopeCheck(std::shared_ptr<SymbolTable> parentScope) override;
	bool typeCheck() override { return false; }
private:
	std::string iterator;
};

class WhileNode : public ASTNode
{
public:
	WhileNode(std::vector<std::shared_ptr<ASTNode>> _children, int _lineNum) :ASTNode(_children, _lineNum) {}
	std::string codeGenerator() override { return std::string();}
	bool typeCheck() override { return false; }
private:

};

class CompoundNode : public ASTNode
{
public:
	CompoundNode(std::vector<std::shared_ptr<ASTNode>> _children, int _lineNum) :ASTNode(_children, _lineNum) {}
	std::string codeGenerator() override { return std::string(); }
	bool typeCheck() override { return false; }
private:

};

class VarDeclarationNode : public ASTNode
{
public:
	VarDeclarationNode(std::vector<std::string> _idlist, TypeStruct _type, int _lineNum) :ASTNode(std::vector<std::shared_ptr<ASTNode>>(), _lineNum)
	{
		idlist = _idlist;
		type = _type;
	}
	std::string codeGenerator() override { return std::string(); }
	bool scopeCheck(std::shared_ptr<SymbolTable> parentScope) override;
	bool typeCheck() override { return false; }
private:
	std::vector<std::string> idlist;
	TypeStruct type;
};

class ConstDeclarationNode : public ASTNode
{
public:
	ConstDeclarationNode(std::string _id,std::string _value, int _lineNum) :ASTNode(std::vector<std::shared_ptr<ASTNode>>(),_lineNum)
	{
		id = _id;
		value = _value;
	}
	std::string codeGenerator() override { return std::string(); }
	bool scopeCheck(std::shared_ptr<SymbolTable> parentScope) override;
	bool typeCheck() override { return false; }
private:
	std::string id;
	std::string value;
};

class ParameterNode : public ASTNode
{
public:
	ParameterNode() = default;
	ParameterNode(std::vector<std::string> _idlist, std::string _simpleType, int _lineNum) :ASTNode(std::vector<std::shared_ptr<ASTNode>>(), _lineNum)
	{
		idlist = _idlist;
		simpleType = _simpleType;
		isVar = false;
	}
	std::string codeGenerator() override { return std::string(); }
	bool scopeCheck(std::shared_ptr<SymbolTable> parentScope) override;
	bool typeCheck() override { return false; }
	TypeStruct getType() override { return TypeStruct(); }
	int getIdNum() { return idlist.size(); }
	void setIsVar() { isVar = true; }
private:
	std::vector<std::string> idlist;
	std::string simpleType;
	bool isVar;
};

class FunctionDeclarationNode : public ASTNode
{
public:
	FunctionDeclarationNode(std::string _id, std::string _simpleType, std::vector<std::shared_ptr<ParameterNode>> _parameter, int _lineNum)
	{
		id = _id;
		simpleType = _simpleType;
		int num = 0;
		for (auto i : _parameter)
		{
			num += i->getIdNum();
			children.push_back(i);
		}
		parameterNum = num;
		lineNum = _lineNum;
	}
	std::string codeGenerator() override { return std::string(); }
	bool scopeCheck(std::shared_ptr<SymbolTable> parentScope) override;
	bool typeCheck() override { return false; }
private:
	std::string id;
	std::string simpleType;
	int parameterNum;
};

class ProgramNode : public ASTNode
{
public:
	ProgramNode(std::vector<std::shared_ptr<ASTNode>> _children, int _lineNum):ASTNode(_children,_lineNum){}
	std::string codeGenerator() override { return std::string();}
	bool typeCheck() override { return false; }
private:

};