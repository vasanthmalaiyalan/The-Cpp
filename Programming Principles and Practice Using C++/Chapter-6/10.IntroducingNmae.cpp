/*
    Full Calculator
    Chapter 6.8.2 - Introducing Names

    Features:
        + - * / %
        parentheses
        unary plus/minus
        variables
        let declarations
        error recovery
        symbolic constants
        clean structure

    Example:
        let x = 10;
        let y = 5;
        
        x + y *2;
        ( x + y ) % 3

        */

#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include <cmath>

// ----------------------------------------------
// Symbolic Constants
// ----------------------------------------------

constexpr char number = '8'; // numeric literal token
constexpr char name = 'a';  // identifier token
constexpr char let = 'L'; // declaration token

constexpr char quit = 'q'; // quit command
constexpr char print = ';'; // print command

constexpr const char* declkey = "let";

constexpr const char* prompt = "> ";
constexpr const char* result = "= ";

// -------------------------------------------------
// Token
// -------------------------------------------------

class Token {

    public:
        
         char kind;
         double value;
         std::string name;

         // default constructor

         Token() : kind{0}, value{0} {}

         // operator token

         Token(char ch) : kind{ch}, value{0} {}

         // number token

         Token(char ch, double val) : kind{ch}, value{val} {}

         // name token

         Token(char ch, std::string n) : kind{ch}, value{0}, name{n} {}
};

// ---------------------------------------------
// Variable
// ---------------------------------------------

class Variable {
    public:
       std::string name;
       double value;

       Variable(std::string n, double v) : name{n}, value{v} {}
};

// ---------------------------------------------
// Variable Table
// ----------------------------------------------

std::vector<Variable> var_table;

// ----------------------------------------------
// Token Stream
// ----------------------------------------------

class Token_stream {
     public:
        
        Token get();

        void putback(Token t);

        void ignore(char c);

    private:
       
        bool full {false};

        Token buffer;
};

// -----------------------------------------------
// Global Token Stream
// -----------------------------------------------

Token_stream ts;

// -----------------------------------------------
// Put Token Back
// -----------------------------------------------

void Token_stream::putback(Token t) {

    if (full) {
        throw std::runtime_error("putback() into full buffer");
    }

    buffer = t;
    full = true;
}

// ----------------------------------------------
// Ignore Input Until Character c
// ----------------------------------------------

void Token_stream::ignore(char c) {
    if (full && buffer.kind == c) {

        full = false;
        return;
    }

    full = false;

    char ch = 0;

    while (std::cin >> ch) {

        if (ch == c) {
            return;
        }
    }
}

// --------------------------------------------
// Get Token
// --------------------------------------------

Token Token_stream::get() {

    // use buffer token if available

    if (full) {

        full = false;
        return buffer;
    }

    char ch = 0;

    std::cin >> ch;

    switch (ch) {

        // commands

        case print:
        case quit:

        // parentheses

        case '(':
        case ')':

        // operator

        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
        case '=':

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
            // identifier or keyword

            if (std::isalpha(ch)) {

                std::string s;

                s += ch;

                while (std::cin.get(ch) && (std::isalpha(ch) || std::isdigit(ch))) {

                    s += ch;
                }

                std::cin.putback(ch);

                if (s == declkey) {
                    return Token{let};
                }

                return Token{name, s}; //string calling like (x + 10);
            }

            throw std::runtime_error("Bad token");
    }
}

// ----------------------------------------------
// Variable Function
// -----------------------------------------------

double get_value(std::string s) {

    for (const Variable& v : var_table) {

        if (v.name == s) {
            return v.value;
        }
    }

    throw std::runtime_error("undefined variable: " + s);
}

// -----------------------------------------------

void set_value(std::string s, double d) { // this is future not current program

    for (Variable& v : var_table) {

        if (v.name == s) {

            v.value = d;
            return;
        }
    }

    throw std::runtime_error("'Undefined variable: " + s);
}

// -----------------------------------------------

bool is_declared(std::string var) {

    for (const Variable& v : var_table) {

        if (v.name == var) {
            return true;
        }
    }

    return false;
}

// -----------------------------------------------------

double define_name(std::string var, double value) {

    if (is_declared(var)) {
        throw std::runtime_error(var + " declared twice");
    }

    var_table.push_back(Variable{var, value});

    return value;
}

// ---------------------------------------------
// Function Declaration
// ---------------------------------------------

double expression(); 
double term();
double primary();

double statement();
double declaration();

void calculate();
void clean_up_mess();

// -------------------------------------------------
// Primary
//
// Handles:
//    numbers
//    variables
//    parentheses
//    unary minus
//    unary plus
// -------------------------------------------------

double primary() {
     
    Token t = ts.get();  // get(&ts)

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

        case name:
           return get_value(t.name);

        case '-':
           return -primary();
           
        case '+':
           return primary();
           
        default:
           throw std::runtime_error("primary expected");   

    }

}

// --------------------------------------------------
// Term
// Handles:
//     multiplication
//     division
//     remainder
// -------------------------------------------------

double term() {

    double left = primary();

    while (true) {

        Token t = ts.get();

        switch (t.kind) {

            case '*':
                left *= primary();
                break;

            case '/': {

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

// ----------------------------------------------
 // Expression
 //
 // Handles:
 //    addition
 //    subtraction
 // -----------------------------------------------

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

 // ----------------------------------------------------
 // Declaration
 // 
 // Grammar:
 //        let name = expression
 // ----------------------------------------------------

 double declaration() {
      
      Token t = ts.get();

      if (t.kind != name) {
         throw std::runtime_error("name expected in declaration");
      }

      std::string var = t.name;

      Token t2 = ts.get();

      if (t2.kind != '=') {
          throw std::runtime_error("= missing in declaration");
      }

      double value = expression();

      define_name(var, value);

      return value;
 }

 // ------------------------------------------------
 // Statement
 // 
 // Handles:
 //     declarations
 //     expressions
 // ---------------------------------------------------

 double statement() {
     
      Token t = ts.get();

      switch (t.kind) {

        case let:
           return declaration();

         default:
            ts.putback(t);
            return expression();  
      }
 }

 // -------------------------------------------------
 // Clean After Error
 // -------------------------------------------------

 void clean_up_mess() {
     
    ts.ignore(print);
 }

 // --------------------------------------------------
 // Calulate loop
 // --------------------------------------------------

 void calculate() {
      
      while (std::cin)
      try {

          std::cout << prompt;

          Token t = ts.get();

          // discard repeated ';'

          while (t.kind == print) {
             t = ts.get();
          }

          // quit command

          if (t.kind == quit) {
            return;
          }

          ts.putback(t);

          std::cout << result << statement() << '\n';
     }

     catch (std::exception& e) {

          std::cerr << e.what() << '\n';

          clean_up_mess();
     }
 }

 // ---------------------------------------------
 // Main
 // ----------------------------------------------

 int main() 
 try {

    calculate();

    return 0;
 }

 catch (std::exception& e) {

    std::cerr << "Fatal error: " << e.what() << '\n';
    return 1;
 }

 catch (...) {

    std::cerr << "Unknown fatal error\n";
    return 2;
 }

 /*
 > let x = 10;
= 10

> let y = 5;
= 5

> x + y * 2;
= 20

> (x+y)%4;
= 3

> -x + 2;
= -8

> q
 */