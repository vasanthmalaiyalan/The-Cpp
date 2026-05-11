/*
  Calculator with Variables

  Supports:
    + - * / %

    parentheses
    unary +/-
    variables
    declarations
    error recovery

  Example:
    
     let x = 10;
     x + 5;
*/

#include <iostream>
#include <stdexcept>
#include <vector>
#include <cmath>

// -------------------------------------------------
// Constants
// ------------------------------------------------

constexpr char number = '8';
constexpr char name = 'a';

constexpr char let = 'L';

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

      std::string name; 

      Token(char k) : kind{k}, value{0} {}
      Token(char k, double v) : kind{k}, value{v} {}
      Token(char k, std::string n) : kind{k}, value{0}, name{n} {}
};

// -----------------------------------------------
// Varaible
// -----------------------------------------------

class Variable {
  public:
     std::string name;
     double value;

     Variable(std::string n, double v) : name{n}, value{v} {}
};

// -----------------------------------------------
// Variable Table
// -----------------------------------------------

std::vector<Variable> var_table;

// ---------------------------------------------
// Token Stream 
// ----------------------------------------------

class Token_stream {

  public:
    Token get();

    void putback(Token t);

    void ignore(char c);

  private:
    bool full {false};

    Token buffer {'0'};  
};

// ----------------------------------------------
// Global Token Stream
// -----------------------------------------------

Token_stream ts;

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

bool is_declared(std::string var) {

  for (const Variable& v : var_table) {

    if (v.name == var) {
      return true;
    }
  }

  return false;
}

double define_name(std::string var, double value) {

  if (is_declared(var)) {
    throw std::runtime_error(var + " declared twice");
  }

  var_table.push_back(Variable{var, value}); // only stored in data

  return value;
}

// --------------------------------------------
// Putback
// -----------------------------------------------

void Token_stream::putback(Token t) {

  if (full) {
    throw std::runtime_error("putback() into full buffer");
  }

  buffer = t;
  full = true;
}

// ---------------------------------------------
// Ignore
// ---------------------------------------------

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

    case print:
    case quit:

    case '(':
    case ')':

    case '+':
    case '-':
    case '*':
    case '/':
    case '%':
    case '=':

      return Token{ch};

    case '.':
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
       
    if (std::isalpha(ch)) {

      std::string s;

      s += ch;

      while (std::cin.get(ch) && (std::isalpha(ch) || std::isdigit(ch))) {

        s += ch;
      }

      std::cin.putback(ch);

      if (s == "let") {
        return Token{let};
      }

      return Token{name, s};
    }

    throw std::runtime_error("Bad token");
  }
 }

 // ---------------------------------------------
 // Function Declarations
 // -----------------------------------------------

 double expression();
 double term();
 double primary();

 double statement();
 double declaration();

 void calculate();
 void clean_up_mess();

 // ------------------------------------------------
 // Primary
 // ------------------------------------------------
 
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

    case name:
      return get_value(t.name);
      
    case '-':
      return -primary();
      
    case '+':
      return primary();
      
    default:
      throw std::runtime_error("Primary expected");  
  }

 }

 // ----------------------------------------------
 // Term
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
          throw std::runtime_error("divide by zero");
        }

        left /= d;
        break;
      }  

      case '%':
      {
        double d = primary();

        if (d == 0) {
          throw std::runtime_error("%: divide by zero");
        }

        left = std::fmod(left, d);
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

 // ------------------------------------------------
 // Declaration
 // ------------------------------------------------

 double declaration() {

  Token t = ts.get();

  if (t.kind != name) {
    throw std::runtime_error("name expected");
  }

  std::string var_name = t.name;

  Token t2 = ts.get();

  if (t2.kind != '=') {
    throw std::runtime_error("= missing in declaration");
  }

  double value = expression();

  define_name(var_name, value);

  return value;
 }

 // ---------------------------------------------
 // Statement
 // ----------------------------------------------

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

 /// --------------------------------------------
 // Cleanup
 // -----------------------------------------------
 void clean_up_mess() {

     ts.ignore(print);
 }

 // ---------------------------------------------
 // Calculate
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

      std::cout << result << statement() << '\n';
    }

    catch (std::exception& e) {

      std::cerr << e.what() << '\n';

      clean_up_mess();
    }
 }

 // ------------------------------------------------
 // Main
 // -----------------------------------------------

 int main() 
 try {

  calculate();
  return 0;

 }

 catch (...) {

  std::cerr << "'Fatal error\n";
  return 2;
 }