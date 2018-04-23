#pragma once
#include"ast.h"

class SymbolTable;


class Symbol {
public:
	Symbol() = default;
	Symbol(std::string _id) :id(_id),isConst(false){}
	Symbol(std::string _id,TypeStruct _type,bool _isConst = false) 
	{
		id = _id;
		type = _type;
		isConst = _isConst;
	}
	Symbol(std::string _id,TypeStruct _type,std::vector<TypeStruct> _parameterType)
	{
		id = _id;
		type = _type;
		parameterType = _parameterType;
		isConst = false;
	}
	std::string getId() { return id; }
	TypeStruct getType() { return type; }
	bool checkConst() { return isConst; }
	std::shared_ptr<SymbolTable> getChildTable() { return childTable; }
	std::vector<TypeStruct> getParameterType() { return parameterType; }
	void setChildTable(std::shared_ptr<SymbolTable> _childTable)
	{ 
		childTable = _childTable;
	}
private:
	std::string id;
	TypeStruct type;
	bool isConst;
	std::vector<TypeStruct> parameterType;
	std::shared_ptr<SymbolTable> childTable;
};

class SymbolTable {
public:
	SymbolTable(SymbolTable *_parentTable) :parentTable(_parentTable) {}
	void insert(Symbol item)
	{
		symbolList.push_back(item);
	}
	Symbol getFirstSymbol()
	{
		if (symbolList.empty())
			return Symbol();
		else
			return symbolList[0];
	}
	Symbol lookUp(std::string id)
	{
		for (auto i : symbolList)
		{
			if (i.getId() == id)
				return i;
		}
		if (parentTable)
			return parentTable->lookUp(id);
		return Symbol();
	}
	std::shared_ptr<SymbolTable> initializationScope()
	{
		//std::shared_ptr<SymbolTable> cTable = std::shared_ptr<SymbolTable>(new SymbolTable(this));
		symbolList.back().setChildTable(std::shared_ptr<SymbolTable>(new SymbolTable(this)));
		symbolList.back().getChildTable()->insert(Symbol(std::string("_")+symbolList.back().getId(), symbolList.back().getType()));
		return symbolList.back().getChildTable();
	}
	
private:
	std::vector<Symbol> symbolList;
	SymbolTable *parentTable;
};
