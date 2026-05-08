#include <iostream>
#include <stdexcept>
#include <cctype>

// -----------------------------------------------
// Token 
// -----------------------------------------------

class Token {
    public:
       char kind;
       double value;

    Token(char k) : kind{k}, value{0} {}
    Token(char k, double v) : kind{k}, value{v} {}   
};

// ------------------------------------------------
// Token Stream
// ------------------------------------------------

class Token_stream {
    public:
       Token get();
       void putback(Token t);

    private:
       bool full {false};
       Token buffer {'0'};   
};

// ============================================
// Putback
// ============================================

void Token_stream::putback(Token t) {

    if (full) {
        throw std::runtime_error("putback() into full buffer");
    }

    buffer = t;
    full = true;
}

// -----------------------------------------------
// Get Token
// ------------------------------------------------

Token Token_stream::get() {

    if (full) {
        full = false;
        return buffer;
    }

    char ch = 0;
    std::cin >> ch;

    switch (ch) {

        case ';':
        case 'q':
        case '(':
        case ')':
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
             return Token{ch};

        case '.':
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        {
            std::cin.putback(ch);

            double value = 0;
            std::cin >> value;

            return Token{'8', value};
        }    
        
        default:
             throw std::runtime_error("Bad token");
    }
}

// -----------------------------------------------
// Global Token Stream
// -----------------------------------------------

Token_stream ts;

// ------------------------------------------------
// Forward Declaration for Compailer time
// ------------------------------------------------

double expression();
double term();
double primary();

// ----------------------------------------------
// Primary
// -----------------------------------------------

double primary() {

    Token t = ts.get();

    switch (t.kind) {

        case '(':
        {
            double value = expression();

            t = ts.get();

            if (t.kind != ')') {
                throw std::runtime_error("')' expected");
            }

            return value;
        }

        case '8':
           return t.value;

        default:
           throw std::runtime_error("Primary expected");   
    }
}

// ---------------------------------------------
// Term
// ----------------------------------------------

double term() {

    double left = primary();

    while (true) {

        Token t = ts.get();

        switch (t.kind) {

            case '*':
               left *= primary();
               break;

            case '/':
            {
                double divisor = primary();

                if (divisor == 0) {
                    throw std::runtime_error("divide by zero");
                }

                left /= divisor;
                break;
            }
            
            default:
                ts.putback(t);
                return left;
        }
    }
}

// -----------------------------------------
// Expression
// -----------------------------------------

double expression()
 {
    double left = term();

    while (true) {

        Token t = ts.get();

        switch (t.kind) {

            case '+':
               left += term();
               break;

            case '-':
               left -= term();
               break;
               
            default:
                ts.putback(t);
                return left;   
        }
    }
 }

 int main() 
 try {

    std::cout << "Simple Calculator\n";
    std::cout << "Use ; to print result\n";
    std::cout << "Use q to quit\n\n";

    while (true) {

        std::cout << "> ";

        Token t = ts.get();

        while (t.kind == ';') {
              t = ts.get(); /// this one is never trust use input
        }

        if (t.kind == 'q') {
            return 0;
        }

        ts.putback(t);

        std::cout << "= " << expression() << '\n';
    }

    return 0;
 }

 catch (std::exception& e) { // exception catch all error
         
    std::cerr << "Error: " << e.what() << '\n';
    return 1;
 }

 catch (...) {

    std::cerr << "Unknown exception\n";
    return 2;
 }

 /*
 ./a.out 
Simple Calculator
Use ; to print result
Use q to quit

> (1+2)*3;
= 9
> 
 */