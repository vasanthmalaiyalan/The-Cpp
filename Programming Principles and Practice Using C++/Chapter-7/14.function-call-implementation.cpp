#include <iostream>
#include <string>

class Token {

    public:
      char kind;

      Token(char ch) : kind(ch) {}
};

class Token_stream {
    public:
       Token get() {
        return Token('+');
       }
};

// ==============================================
// Forward declarations
// ==============================================

double expression(Token_stream& ts);
double term(Token_stream& ts);
double primary(Token_stream& ts);

// ===============================================
// expression()
// ==============================================

double expression(Token_stream& ts) {

    double left = term(ts);

    Token t = ts.get();

    std::cout << "expression() called";

    return left;
}

// ===========================================
// term()
// ============================================

double term(Token_stream& ts) {

    double left = primary(ts);

    Token t = ts.get();

    double d = 0;

    std::cout << "term() called\n";

    return left;
}

// ===========================================
// Primary()
// ===========================================

double primary(Token_stream& ts) {

    Token t = ts.get();

    std::cout << "primary() called\n";

    return 1;
}

// ============================================
// main()
// ============================================

int main() {

    Token_stream ts;

    double result = expression(ts);

    std::cout << "result = " << result << '\n';
}