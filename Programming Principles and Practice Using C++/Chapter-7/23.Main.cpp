#include <iostream>

#include "23.Tokenstream.h"

int main() {

    Token_stream ts;

    Token t = ts.get();

    std::cout << t.kind << '\n';
}
