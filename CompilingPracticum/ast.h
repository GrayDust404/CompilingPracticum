#pragma once
#include<string>
#include<vector>
#include<utility>
#include<memory>

class SymbolTable;

class TypeStruct {
public:
	TypeStruct() :simpleType(std::string()), period(std::vector<std::pair<int, int>>()), isRef(false){}
	TypeStruct(std::string _simpleType, bool _isRef = false) :simpleType(_simpleType), isRef(_isRef), period(std::vector<std::pair<int, int>>()) {}
	TypeStruct(std::string _simpleType, std::vector<std::pair<int, int>> _peroid) :simpleType(_simpleType), isRef(false), period(_peroid) {}
	std::string getSimpleType() { return simpleType; }
	std::string getCType();
	std::vector<std::pair<int, int>> getPeroid() { return period; }
	bool checkRef() { return isRef; }
	friend bool operator==(const TypeStruct &lhs, const TypeStruct &rhs);
	friend bool operator!=(const TypeStruct &lhs, const TypeStruct &rhs);
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
	virtual bool typeCheck();
	virtual std::string getID() { return std::string(); }
	virtual TypeStruct getType() { return TypeStruct(); }
	virtual int getIdNum() { return -1; }
	int getLineNum() { return lineNum; }
	int getChildrenNum() { return children.size(); }
protected:
	std::vector<std::shared_ptr<ASTNode>> children;
	int lineNum;
	std::shared_ptr<SymbolTable> scope;
};

class VarNode : public ASTNode
{
public:
	VarNode(std::string _id, std::vector<std::shared_ptr<ASTNode>> _children, int _lineNum) :ASTNode(_children,_lineNum) { id = _id; }
	std::string codeGenerator() override;
	bool scopeCheck(std::shared_ptr<SymbolTable> parentScope) override;
	std::string getID() override { return id; }
	TypeStruct getType() override;
private:
	std::string id;
};

class VarpartNode : public ASTNode
{
public:
	VarpartNode(std::string _id,std::vector<std::shared_ptr<ASTNode>> _children, int _lineNum) :ASTNode(_children,_lineNum) 
	{
		id = _id;
	}
	std::string codeGenerator() override;
	bool typeCheck() override;
private:
	std::string id;
};

class ConstNode : public ASTNode
{
public:
	ConstNode(std::string _value,int _lineNum) :ASTNode(std::vector<std::shared_ptr<ASTNode>>(), _lineNum)
	{
		value = _value;
	}
	std::string codeGenerator() override;
	TypeStruct getType() override;
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
	std::string codeGenerator() override;
	bool scopeCheck(std::shared_ptr<SymbolTable> parentScope) override;
	bool typeCheck() override;
	std::string getID() override { return id; }
	TypeStruct getType() override;
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
	std::string codeGenerator() override;
	bool typeCheck() override;
	TypeStruct getType() override;
private:
	std::string operation;
	std::string getCTypeOperation();
};

class AssignmentNode : public ASTNode
{
public:
	AssignmentNode(std::vector<std::shared_ptr<ASTNode>> _children, int _lineNum) :ASTNode(_children,_lineNum) {}
	std::string codeGenerator() override;
	bool typeCheck() override;
private:

};

class IfNode : public ASTNode
{
public:
	IfNode(std::vector<std::shared_ptr<ASTNode>> _children, int _lineNum) :ASTNode(_children, _lineNum) {}
	std::string codeGenerator() override;
	bool typeCheck() override;
private:

};

class ForNode : public ASTNode
{
public:
	ForNode(std::string _iterator, std::vector<std::shared_ptr<ASTNode>> _children, int _lineNum) :ASTNode(_children, _lineNum)
	{
		iterator = _iterator;
	}
	std::string codeGenerator() override;
	bool scopeCheck(std::shared_ptr<SymbolTable> parentScope) override;
	bool typeCheck() override;
private:
	std::string iterator;
};

class WhileNode : public ASTNode
{
public:
	WhileNode(std::vector<std::shared_ptr<ASTNode>> _children, int _lineNum) :ASTNode(_children, _lineNum) {}
	std::string codeGenerator() override;
	bool typeCheck() override;
private:

};

class CompoundNode : public ASTNode
{
public:
	CompoundNode(std::vector<std::shared_ptr<ASTNode>> _children, int _lineNum) :ASTNode(_children, _lineNum) {}
	std::string codeGenerator() override;
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
	std::string codeGenerator() override;
	bool scopeCheck(std::shared_ptr<SymbolTable> parentScope) override;
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
	std::string codeGenerator() override;
	bool scopeCheck(std::shared_ptr<SymbolTable> parentScope) override;
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
	std::string codeGenerator() override;
	bool scopeCheck(std::shared_ptr<SymbolTable> parentScope) override;
	TypeStruct getType() override { return TypeStruct(simpleType); }
	int getIdNum() override { return idlist.size(); }
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
	std::string codeGenerator() override;
	bool scopeCheck(std::shared_ptr<SymbolTable> parentScope) override;
private:
	std::string id;
	std::string simpleType;
	int parameterNum;
};

class ProgramNode : public ASTNode
{
public:
	ProgramNode(std::vector<std::shared_ptr<ASTNode>> _children, int _lineNum):ASTNode(_children,_lineNum){}
	bool scopeCheck(std::shared_ptr<SymbolTable> parentScope) override;
	std::string codeGenerator() override;
private:

};
