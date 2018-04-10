#pragma once
#include<string>
#include<vector>
#include<utility>
#include<memory>

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
	ASTNode() :children(std::vector<std::shared_ptr<ASTNode>>()) {}
	ASTNode(std::vector<std::shared_ptr<ASTNode>> _children):children(_children){}
	void addChildren(std::vector<std::shared_ptr<ASTNode>> newChildren);
	virtual std::string codeGenerator() = 0;
	virtual bool scopeCheck() = 0;
	virtual bool typeCheck() = 0;
	virtual std::string getID() { return std::string(); }
	virtual TypeStruct getType() { return TypeStruct(); }
protected:
	std::vector<std::shared_ptr<ASTNode>> children;
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
private:

};

class IfNode : public ASTNode
{
public:
	std::string codeGenerator() override;
	bool scopeCheck() override;
	bool typeCheck() override;
private:

};

class ForNode : public ASTNode
{
public:
	std::string codeGenerator() override;
	bool scopeCheck() override;
	bool typeCheck() override;
private:
	std::string iterator;
};

class WhileNode : public ASTNode
{
public:
	std::string codeGenerator() override;
	bool scopeCheck() override;
	bool typeCheck() override;
private:

};

class CompoundNode : public ASTNode
{
public:
	CompoundNode(std::vector<std::shared_ptr<ASTNode>> _children) :ASTNode(_children) {}
	std::string codeGenerator() override;
	bool scopeCheck() override;
	bool typeCheck() override;
private:

};

class VarDeclarationNode : public ASTNode
{
public:
	VarDeclarationNode(std::vector<std::string> _idlist, TypeStruct _type) :idlist(_idlist), type(_type) {}
	std::string codeGenerator() override;
	bool scopeCheck() override;
	bool typeCheck() override;
private:
	std::vector<std::string> idlist;
	TypeStruct type;
};

class ConstDeclarationNode : public ASTNode
{
public:
	ConstDeclarationNode(std::string _id,std::string _value):id(_id),value(_value){}
	std::string codeGenerator() override;
	bool scopeCheck() override;
	bool typeCheck() override;
private:
	std::string id;
	std::string value;
};

class FunctionDeclarationNode : public ASTNode
{
public:
	FunctionDeclarationNode(std::string _id, std::string _simpleType, std::vector<std::shared_ptr<ParameterNode>> _parameter)
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
	}
	std::string codeGenerator() override;
	bool scopeCheck() override;
	bool typeCheck() override;
private:
	std::string id;
	std::string simpleType;
	int parameterNum;
};

class ParameterNode : public ASTNode
{
public:
	ParameterNode(std::vector<std::string> _idlist, std::string _simpleType) :idlist(_idlist), simpleType(_simpleType), isVar(false) {}
	std::string codeGenerator() override;
	bool scopeCheck() override;
	bool typeCheck() override;
	TypeStruct getType() override;
	int getIdNum() { return idlist.size(); }
	void setIsVar() { isVar = true; }
private:
	std::vector<std::string> idlist;
	std::string simpleType;
	bool isVar;
};

class ProgramNode : public ASTNode
{
public:
	ProgramNode(std::vector<std::shared_ptr<ASTNode>> _children):ASTNode(_children){}
	std::string codeGenerator() override;
	bool scopeCheck() override;
	bool typeCheck() override;
	std::string getID() override;
	TypeStruct getType() override;
private:

};