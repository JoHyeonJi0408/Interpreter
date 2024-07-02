#include "ast.h"

string Program::TokenLiteral() const {
    if (!Statements.empty()) {
        return Statements[0]->TokenLiteral();
    }
    else {
        return "";
    }
}
