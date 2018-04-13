#pragma once
#include"parser.h"
#include"ast.h"
std::shared_ptr<ASTNode> transformFactor(int root);
std::shared_ptr<ASTNode> transformTerm(int root);
std::shared_ptr<ASTNode> transformSimpleExpression(int root);
std::shared_ptr<ASTNode> transformExpression(int root);
std::vector<std::shared_ptr<ASTNode>> transformExpressionList(int root);
std::shared_ptr<ASTNode> transformVarPart(int root);
std::shared_ptr<ASTNode> transformVariable(int root);
std::shared_ptr<ASTNode> transformFunctionCall(int root);
std::shared_ptr<ASTNode> transformElsePart(int root);
std::shared_ptr<ASTNode> transformStatement(int root);
std::vector<std::shared_ptr<ASTNode>> transformStatementList(int root);
std::shared_ptr<ASTNode> transformCompound(int root);
std::vector<std::shared_ptr<ASTNode>> transformSubprogramBody(int root);
ParameterNode transformValueParameter(int root);
ParameterNode transformVarParameter(int root);
std::shared_ptr<ParameterNode> transformParameter(int root);
std::vector<std::shared_ptr<ParameterNode>> transformParameterList(int root);
std::vector<std::shared_ptr<ParameterNode>> transformFormalParameter(int root);
std::shared_ptr<ASTNode> transformSubprogramHead(int root);
std::shared_ptr<ASTNode> transformSubprogram(int root);
std::vector<std::shared_ptr<ASTNode>> transformSubprogramDeclarationS(int root);
std::vector<std::pair<int, int>> transformPeriod(int root);
TypeStruct transformType(int root);
std::vector<std::string> transformIDList(int root);
std::vector<std::shared_ptr<ASTNode>> transformVarDeclaration(int root);
std::vector<std::shared_ptr<ASTNode>> transformVarDeclarationS(int root);
std::vector<std::shared_ptr<ASTNode>> transformConstDeclaration(int root);
std::vector<std::shared_ptr<ASTNode>> transformConstDeclarationS(int root);
std::vector<std::shared_ptr<ASTNode>> transformProgramBody(int root);
std::shared_ptr<ASTNode> transformProgramStruct(int root);