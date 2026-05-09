/*
    Simple Calculator

    Features:
      + - * / %
      parentheses
      unary plus/minus
      error recovery
      symbolic constants
      clean code layout
*/

#include <iostream>
#include <stdexcept>
#include <cmath>

// -------------------------------------------------
// Symbolic Constants
// -------------------------------------------------

constexpr char number = '8';

constexpr char quit = 'q';
constexpr char print = ';';

constexpr const char* prompt = "> ";
constexpr const char* result = "= ";

// ------------------------------------------------
// Token
// -----------------------------------------------

class Token {
    public:
       char kind;
       double value;

       Token(char k) : kind{k}, value{0} {}
       Token(char k , double v) : kind{k}, value{v} {}
};

// ------------------------------------------------
// Token Stream
// ------------------------------------------------

class Token_stream {
    public:
       Token get();
       
       void putback(Token t);

       void ignore(char c);

     private:
       bool full {false};

       Token buffer {'0'};
};

// -----------------------------------------------
// Global Token Stream
// -----------------------------------------------

Token_stream ts;

// -----------------------------------------------
// Putback
// -----------------------------------------------

void Token_stream::putback(Token t) {

    if (full) {
        throw std::runtime_error("putback() into full buffer");
    }

    buffer = t;
    full = true;
}

// -----------------------------------------------
// Ignore Characters Until c
// -----------------------------------------------

void Token_stream::ignore(char c) {

    // check buffer first

    if (full && buffer.kind == c) {

       full = false;
       return;
    }

    full = false;

    // discard characters

    char ch = 0;

    while (std::cin >> ch) {

      if (ch == c) {
        return;
      }
    }
}

// ------------------------------------------------
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

    case quit:
    case print:

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

      return Token{number, value};
    }

    default:
      throw std::runtime_error("Bad token");
  }
}

// -----------------------------------------------
// Function Declarations
// -----------------------------------------------

double expression();
double term();
double primary();

void calculate();
void clean_up_mess();

// -----------------------------------------------
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

    case number:
       return t.value;

    case '-':
       return -primary();
       
    case '+':
      return primary();
      
    default:
       throw std::runtime_error("primary expected");  
  }
}

// -------------------------------------------
// Term
// -------------------------------------------

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

// ---------------------------------------------
// Expression
// ---------------------------------------------

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

// -----------------------------------------------
// Cleanup
// -----------------------------------------------

void clean_up_mess() {

  ts.ignore(print);
}

// ----------------------------------------------
// Calculator Loop
// ----------------------------------------------

void calculate() {
  
  while (std::cin) 
  try {

    std::cout << prompt;

    Token t = ts.get();

    while (t.kind == print) {
      t = ts.get();
    }

    if (t.kind == quit) {
      return;
    }

    ts.putback(t);

    std::cout << result << expression() << '\n';
  }

  catch (std::exception& e) {

    std::cerr << e.what() << '\n';

    clean_up_mess();
  }
}

// -----------------------------------------------
// Main
// ------------------------------------------------

int main() 
try {

  calculate();

  return 0;
}

catch (...) {

  std::cerr << "Fatal error\n";
  return 2;
}

