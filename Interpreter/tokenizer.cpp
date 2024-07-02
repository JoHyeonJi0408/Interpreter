#include "tokenizer.h"

map<string, TokenType> keywords = {
    {"fn", FUNCTION},
    {"let", LET},
    {"true", TRUE},
    {"false", FALSE},
    {"if", IF},
    {"else", ELSE},
    {"return", RETURN }
};

Token::Token() : Type(ILLEGAL), Literal("") {}
Token::Token(TokenType t, const string& lit) : Type(t), Literal(lit) {}

TokenType Token::LookupIdent(string ident) {
    if (keywords.find(ident) != keywords.end()) {
        return keywords[ident];
    }
    return IDENT;
}
