/*
   Simple Claculator

   This program implements a basic expression calculator.

   Input:
     cin

   Output:
     cout
     
   Commands:
      ; print result
      q quit calculator
      
    Grammer:
    
    Statement:
        Expression
        Print
        Quit

    Print:
      ";"
      
    Quit:
       "q"
       
    Expression:
       Term
       Expression "+" Term
       Expression "-" Term
       
    Term:
       Primary
       Term "*" Primary
       Term "/" Primary
       Term "%" Primary
       
    Primary:
       Number
       "(" Expression ")"
       "-" Primary
       "+" Primary
       
    Number:
       floating-point literal   
*/

#include <iostream>
#include <stdexcept>
#include <cmath>

// -------------------------------------------------
// Symbolic Constant
// -------------------------------------------------

constexpr char number = '8';

constexpr char quit = 'q';
constexpr char print = ';';

constexpr const char* prompt = "> ";
constexpr const char* result = "= ";

// -------------------------------------------------
// Token
// Represent one input unit:
//     number
//     operator
//     parenthesis
// ------------------------------------------------
class Token {
    public:
      char kind;
      double value;

      Token(char k) : kind{k}, value{0} {}
      Token(char k, double v) : kind{k}, value{v} {}
};

// ------------------------------------------------
// Token Stream
//
// Handles token input and buffering
// ------------------------------------------------

class Token_stream {
    public:
      Token get();
      void putback(Token t);

    private:
       bool full {false};
       Token buffer {'0'};  
};

// ------------------------------------------------
// Global Token Stream
// ------------------------------------------------

Token_stream ts;

// ------------------------------------------------
// Put Token Back Into Stream
// -------------------------------------------------

void  Token_stream::putback(Token t) {

    if (full) {

        throw std::runtime_error("putback() into full buffer");
    }

    buffer = t;
    full = true;
}

// ------------------------------------------------
// Read Characters And Built Tokens
// ------------------------------------------------

Token Token_stream::get() {

    // Check if Token alraedy exits in buffer

    if (full) {

        full = false;
        return buffer;
    }

    char ch = 0;

    // operator >> skips whitespace automatically

    std::cin >> ch;

    switch (ch) {
        // commands

        case quit:
        case print:

        // Parentheses

        case '(':
        case ')':

        // operator
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':

          return Token{ch};

       // floating-point literal
       
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

        return Token{number, value};
       }  

       default:
          throw std::runtime_error("Bad token");
    }
}

// ----------------------------------------------
// Function Declarations
// ---------------------------------------------

double expression();
double term();
double primary();

void calculate();

// --------------------------------------------
// Primary
// 
// Handles:
//    numbers
//    parentheses
//    unary minus
//    unary plus
// --------------------------------------------

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

        case number:
           return t.value;

        case '-':
            return -primary();
            
        case '+':
           return primary();
           
        default:
           throw std::runtime_error("Primary expected");   
    }
}

// ---------------------------------------------
// term
// 
// Handles:
//     multiplication
//     division
//      remainder
// ---------------------------------------------

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

             case '%':
             {
                double divisor = primary();

                if (divisor == 0) {
                    throw std::runtime_error("%: divide by zero");
                }

                left = std::fmod(left, divisor);
                break;
             }

             default:
                ts.putback(t);
                return left;
        }
    }
}

// ------------------------------------------
// Expression
// 
// Handles:
//    addition
//    subtraction
// ------------------------------------------

double expression() {

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

// --------------------------------------------
// Calculator Execution Loop
// ---------------------------------------------

void calculate() {

    while (true) {

        std::cout << prompt;

        Token t = ts.get();

        // discard repeated print commands

        while (t.kind == print) {
            t = ts.get();
        }

        if (t.kind == quit) {
            return;
        }

        ts.putback(t);

        std::cout << result << expression() << '\n';
    }
}

// ---------------------------------------------
// Main
// 
// Handles:
//    starting
//    shutdown
//    fatal errors
// ---------------------------------------------

int main() 
try {

    calculate();

    return 0;
}

// ---------------------------------------------
// Error Handling
// ---------------------------------------------

catch (std::runtime_error& e) {

    std::cerr << e.what() << '\n';
    return 1;
}

catch (...) {

    std::cerr << "Unkown exception\n";
    return 2;
}
