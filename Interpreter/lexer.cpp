#include "lexer.h"
#include <iostream>
#include <stdio.h>

bool isLetter(unsigned char ch) {
    return 'a' <= ch && ch <= 'z' || 'A' <= ch && ch <= 'Z' || ch == '_';
}

bool isDigit(unsigned char ch) {
    return '0' <= ch && ch <= '9';
}

string EnumToString(TokenType type) {
    switch (type) {
    case ENDOFFILE:
        return "EOF";
    case IDENT:
        return "IDENT";
    case INT:
        return "INT";
    case ASSIGN:
        return "ASSIGN";
    case PLUS:
        return "PLUS";
    case MINUS:
        return "MINUS";
    case BANG:
        return "BANG";
    case ASTERISK:
        return "ASTERISK";
    case SLASH:
        return "SLASH";
    case LT:
        return "LT";
    case GT:
        return "GT";
    case COMMA:
        return "COMMA";
    case SEMICOLON:
        return "SEMICOLON";
    case LPAREN:
        return "LPAREN";
    case RPAREN:
        return "RPAREN";
    case LBRACE:
        return "LBRACE";
    case RBRACE:
        return "RBRACE";
    case EQ:
        return "EQ";
    case NOT_EQ:
        return "NOT_EQ";
    case FUNCTION:
        return "FUNCTION";
    case LET:
        return "LET";
    case TRUE:
        return "TRUE";
    case FALSE:
        return "FALSE";
    case IF:
        return "IF";
    case ELSE:
        return "ELSE";
    case RETURN:
        return "RETURN";
    case ILLEGAL:
        return "ILLEGAL";
    default:
        return "UNKNOWN";
    }
}

Lexer::Lexer(string inputStr) : input(inputStr), position(0), readPosition(1) {
    ch = input[0];
    for (Token token = NextToken(); token.Type != ENDOFFILE; token = NextToken()) {
        string typeStr = EnumToString(token.Type);
        cout << "{ Type: " << typeStr << ", Literal: " << token.Literal << " }\n";
    }
}

void Lexer::ReadChar() {
    if (readPosition >= input.length()) {
        ch = 0;
    }
    else {
        ch = input[readPosition];
    }
    position = readPosition;
    readPosition += 1;
}

unsigned char Lexer::PeekChar() {
    if (readPosition >= input.length()) {
        return 0;
    }
    else {
        return input[readPosition];
    }
}

string Lexer::ReadIdentifier() {
    string identifier;
    while (isLetter(ch)) {
        identifier += ch;
        ReadChar();
    }
    return identifier;
}

string Lexer::ReadNumber() {
    string number;
    while (isDigit(ch)) {
        number += ch;
        ReadChar();
    }
    return number;
}

void Lexer::SkipWhitespace() {
    while (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r') {
        ReadChar();
    }
}

Token Lexer::NextToken() {
    Token token;

    SkipWhitespace();

    switch (ch) {
    case '=':
        if (PeekChar() == '=') {
            ReadChar();
            token = Token(EQ, "==");
        }
        else {
            token = Token(ASSIGN, string(1, ch));
        }
        break;
    case '+':
        token = Token(PLUS, string(1, ch));
        break;
    case '-':
        token = Token(MINUS, string(1, ch));
        break;
    case '!':
        if (PeekChar() == '=') {
            ReadChar();
            token = Token(NOT_EQ, "!=");
        }
        else {
            token = Token(BANG, string(1, ch));
        }
        break;
    case '/':
        token = Token(SLASH, string(1, ch));
        break;
    case '*':
        token = Token(ASTERISK, string(1, ch));
        break;
    case '<':
        token = Token(LT, string(1, ch));
        break;
    case '>':
        token = Token(GT, string(1, ch));
        break;
    case ';':
        token = Token(SEMICOLON, string(1, ch));
        break;
    case ',':
        token = Token(COMMA, string(1, ch));
        break;
    case '(':
        token = Token(LPAREN, string(1, ch));
        break;
    case ')':
        token = Token(RPAREN, string(1, ch));
        break;
    case '{':
        token = Token(LBRACE, string(1, ch));
        break;
    case '}':
        token = Token(RBRACE, string(1, ch));
        break;
    case 0:
        token.Literal = "";
        token.Type = ENDOFFILE;
        return token;
    default:
        if (isLetter(ch)) {
            token.Literal = ReadIdentifier();
            token.Type = token.LookupIdent(token.Literal);
            return token;
        }
        else if (isDigit(ch)) {
            token.Type = INT;
            token.Literal = ReadNumber();
            return token;
        }
        else {
            token = Token(ILLEGAL, string(1, ch));
        }
        break;
    }

    ReadChar();
    return token;
}
