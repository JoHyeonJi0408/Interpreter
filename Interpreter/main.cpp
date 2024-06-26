#include "lexer.h"

int main() {
	string code = "let add = fn(x, y) { x + y ; };";
	Lexer lexer(code);
}
