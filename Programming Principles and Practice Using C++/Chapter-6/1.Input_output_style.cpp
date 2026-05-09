// chapter 6.2 - input and output style calculator loop

#include <iostream>
#include <cctype>

// --------------------------------------------------
// Token
// --------------------------------------------------

class Token {
    public:
       char kind;
       double value;

       Token(char k) : kind{k}, value{0} {}

       Token(char k, double v) : kind{k}, value{v} {}
};

// -------------------------------------------
// Token_stream
// -------------------------------------------

class Token_stream {
    public:
      
      Token_stream() : full{false}, buffer{'0'} {}

      Token get();
      void putback(Token t);

    private:
      bool full;
      Token buffer;  
};
// ---------------------------------------------
// putback
// ---------------------------------------------

void Token_stream::putback(Token t) {

    if (full) {
        std::cerr << "putback() into a full buffer\n";
        return;
    }

    buffer = t;
    full = true;
}

// -------------------------------------------------
// get
// -------------------------------------------------

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
        case '+':
        case '-':
        case '*':
        case '/':
        case '(':
        case ')':
            return Token{ch};

        default:
            
            if (std::isdigit(ch) || ch == '.') {

                std::cin.putback(ch);

                double value = 0;
                std::cin >> value;

                return Token{'8', value};
            }

            std::cerr << "Bad token\n";
            return Token{'q'};
    }
}

// -----------------------------------------------
// Global Token Stream
// -----------------------------------------------

Token_stream ts;

double expression();

// ------------------------------------------------
// primary
// ------------------------------------------------

double primary() {

    Token t = ts.get();

    switch (t.kind) {

        case '(':
        {
            double value = expression();

            t = ts.get();

            if (t.kind != ')') {
                std::cerr << "')' expected\n";
            }

            return value;
        }

        case '8':
           return t.value;

        default:
            std::cerr << "Primary excepted\n";
            return 0;
    }
}

// ----------------------------------------------
// term
// -----------------------------------------------

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
                double d = primary();

                if (d == 0) {
                    std::cerr << "Division by zero\n";
                    return 0;
                }

                left /= d;
                break;
            }   

            default:
               ts.putback(t);
               return left;
        }
    }
}

// ----------------------------------------------
// expression
// ---------------------------------------------

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

 // ----------------------------------------------
 // Main
 // -----------------------------------------------

 int main() {

    std::cout << "Simple Calculator\n";
    std::cout << "Use ; to print result\n";
    std::cout << "Use q to quit\n\n";

    while (std::cin) {

        try {

            std::cout << "> ";

            Token t = ts.get();

            while (t.kind == ';') {
                t = ts.get();
            }

            if (t.kind == 'q') {
                break;
            }

            ts.putback(t);

            double val = expression();

            std::cout << "= " << val << '\n';
        }

        catch (...) {
            std::cerr << "Error occurred\n";
            return 1;
        }
    }

    return 0;
 }