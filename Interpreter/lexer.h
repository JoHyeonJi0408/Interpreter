#ifndef LEXER_H
#define LEXER_H

#include "tokenizer.h"

bool isLetter(unsigned char ch);
bool isDigit(unsigned char ch);
string EnumToString(TokenType type);

struct Lexer{
    string input;
    int position;
    int readPosition;
    unsigned char ch;

    Lexer(string inputStr);

    void ReadChar();
    unsigned char PeekChar();
    string ReadIdentifier();
    string ReadNumber();
    void SkipWhitespace();
    Token NextToken();
};

#endif
