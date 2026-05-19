#include "23.Tokenstream.h"

Token::Token(char k) : kind{k}, values{0.0} {}
Token::Token(char k, double v) : kind{k}, values{v} {}

void Token_stream::putback(Token t) {

    buffer = t;

    full = true;
}

Token Token_stream::get() {

    return Token {'+'};
}