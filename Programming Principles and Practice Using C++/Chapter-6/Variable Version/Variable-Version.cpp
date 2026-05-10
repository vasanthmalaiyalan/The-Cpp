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

     
}