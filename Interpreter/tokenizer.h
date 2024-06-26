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

map<string, TokenType> keywords = {
	{"fn", FUNCTION},
	{"let", LET},
	{"true", TRUE},
	{"false", FALSE},
	{"if", IF},
	{"else", ELSE},
	{"return", RETURN }
};

struct Token {
	TokenType Type;
	string Literal;

	Token() : Type(ILLEGAL), Literal("") {}
	Token(TokenType t, const string& lit) : Type(t), Literal(lit) {}

	TokenType LookupIdent(string ident) {
		if (keywords.find(ident) != keywords.end()) {
			return keywords[ident];
		}

		return IDENT;
	}
};
