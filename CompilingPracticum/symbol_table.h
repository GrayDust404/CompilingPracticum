#pragma once
#include<string>
#include<vector>
#include<memory>
#include"ast.h"

class SymbolTable;

class Symbol {
public:
	Symbol() = default;
	Symbol(std::string _id) :id(_id) {}
	Symbol(std::string _id,
		TypeStruct _type,
		bool _isConst
		) :
		id(_id), type(_type), isConst(_isConst), parameterType(std::vector<TypeStruct>()), childTable(std::shared_ptr<SymbolTable>()) {}
	Symbol(std::string _id,
		TypeStruct _type,
		std::vector<TypeStruct> _parameterType
	) :
		id(_id), type(_type), isConst(false), parameterType(_parameterType), childTable(std::shared_ptr<SymbolTable>()){}
	std::string getId() { return id; }
	void createChildTable() { childTable = std::shared_ptr<SymbolTable>(new SymbolTable()); }
	std::shared_ptr<SymbolTable> getChildTable() { return childTable; }
	std::vector<TypeStruct> getParameterType() { return parameterType; }
private:
	std::string id;
	TypeStruct type;
	bool isConst;
	std::vector<TypeStruct> parameterType;
	std::shared_ptr<SymbolTable> childTable;
};

class SymbolTable {
public:
	SymbolTable() = default;
	void insert(Symbol item)
	{
		symbolList.push_back(item);
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
		symbolList.back().createChildTable();
		return symbolList.back().getChildTable();
	}
private:
	std::vector<Symbol> symbolList;
	std::shared_ptr<SymbolTable> parentTable;
};
