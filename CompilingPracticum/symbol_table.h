#pragma once
#include<string>
#include<vector>
#include<memory>
#include"ast.h"

class SymbolTable;

class Symbol {
public:
	Symbol(std::string _id,
		TypeStruct _type,
		std::string _category,
		bool _isConst,
		std::vector<TypeStruct> _parameterType = std::vector<TypeStruct>()
	) :
		id(_id), type(_type), category(_category), isConst(_isConst), parameterType(_parameterType), childTable(std::shared_ptr<SymbolTable>()){}
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
	void lookUp(std::string id);
	void initializationScope();
	void finalizeScope();
private:
	std::vector<Symbol> symbolList;
	std::shared_ptr<SymbolTable> parentTable;
};
