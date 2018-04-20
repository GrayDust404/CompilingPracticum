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
	Symbol(std::string _id, TypeStruct _type): id(_id),type(_type){}
	Symbol(std::string _id,
		TypeStruct _type,
		std::string _category,
		bool _isConst,
		std::vector<TypeStruct> _parameterType = std::vector<TypeStruct>()
	) :
		id(_id), type(_type), category(_category), isConst(_isConst), parameterType(_parameterType), childTable(std::shared_ptr<SymbolTable>()){}
	std::string getId() { return id; }
	void createChildTable() { childTable = std::shared_ptr<SymbolTable>(new SymbolTable()); }
private:
	std::string id;
	TypeStruct type;
	std::string category;//funcation variable 
	bool isConst;
	std::vector<TypeStruct> parameterType;
	std::shared_ptr<SymbolTable> childTable;
};

class SymbolTable {
public:
	SymbolTable() = default;
	void insert(Symbol item);
	Symbol lookUp(std::string id);
	std::shared_ptr<SymbolTable> initializationScope();
	void finalizeScope();
private:
	std::vector<Symbol> symbolList;
	std::shared_ptr<SymbolTable> parentTable;
};
