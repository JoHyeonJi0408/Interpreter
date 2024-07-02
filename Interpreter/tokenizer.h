#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <string>
#include <map>
using namespace std;

enum TokenType {
	ILLEGAL,
	ENDOFFILE,
	IDENT,
	INT,
	ASSIGN,
	PLUS,
	MINUS,
	BANG,
	ASTERISK,
	SLASH,
	LT,
	GT,
	COMMA,
	SEMICOLON,
	LPAREN,
	RPAREN,
	LBRACE,
	RBRACE,
	EQ,
	NOT_EQ,

	// keywords
	FUNCTION,
	LET,
	TRUE,
	FALSE,
	IF,
	ELSE,
	RETURN
};

extern map<string, TokenType> keywords;

struct Token {
	TokenType Type;
	string Literal;

	Token();
	Token(TokenType t, const string& lit);

	TokenType LookupIdent(string ident);
};

#endif
