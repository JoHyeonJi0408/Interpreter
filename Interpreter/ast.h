#ifndef AST_H
#define AST_H

#include "lexer.h"
#include <vector>

class Node {
public:
	virtual ~Node() = default;
	virtual string TokenLiteral() const = 0;
};

class Statement : public Node {
public :
	virtual ~Statement() = default;
	virtual void StatementNode() const = 0;
};

class Expression : public Node {
public :
	virtual ~Expression() = default;
	virtual void ExpressionNode() const = 0;
};

class Program : public Node {
public :
	vector<Statement*> Statements;

	string TokenLiteral() const override;
};

#endif
