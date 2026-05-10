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

std::vector::<Variable> var_table;

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
    
  }
}