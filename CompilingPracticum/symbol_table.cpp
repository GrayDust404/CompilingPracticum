#include "symbol_table.h"

void SymbolTable::insert(Symbol item)
{
	symbolList.push_back(item);
}

Symbol SymbolTable::lookUp(std::string id)
{
	for (auto i : symbolList)
	{
		if (i.getId() == id)
			return i;
	}
	return Symbol();
}