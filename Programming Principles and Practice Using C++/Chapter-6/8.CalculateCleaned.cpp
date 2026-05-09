// calculator.cpp
// chapter - Function -Oriented Clean Version

#include <iostream>
#include <stdexcept>
#include <cmath>

// ------------------------------------------------
// Symbolic Constant
// -------------------------------------------------

constexpr char number = '8';
constexpr char quit = 'q';
constexpr char print = ';';

constexpr const char* prompt = "> ";
constexpr const char* result = "= ";

// -------------------------------------------------
// Token 
// -------------------------------------------------

class Token {
    public:
       char kind;
       double value;

       Token(char k) : kind{k}, value{0} {}
       Token(char k, double v) : kind{k}, value{v} {}
};

// ------------------------------------------------
// Token stream
// -------------------------------------------------

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

 // -----------------------------------------------
 // Putback
 // -----------------------------------------------

 void Token_stream::putback(Token t) {
       
    if (full) {
        throw std::runtime_error("putback() in to full buffer");
    }

    buffer = t;
    full = true;
 }

 // ----------------------------------------------
 // Get Token
 // ----------------------------------------------

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

 // ----------------------------------------------
 // Function Declarations
 // ----------------------------------------------

 double expression();
 double term();
 double primary();

 void calculator();

 // --------------------------------------------
 // Primary
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
          throw std::runtime_error("primary expected");   
    }
 }

 // --------------------------------------------
 // Term
 // --------------------------------------------

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

                left  /= divisor;
                break;
             } 

             case '%':
             {
                double divisor = primary();

                if (divisor == 0) {
                    throw std::runtime_error("divide by zero");
                }

                left = std::fmod(left , divisor);
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
 // ----------------------------------------------

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

 // ------------------------------------------
 // calculate
 // ==========================================

 void calculate() {

    while (true) {

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
 }

 // ------------------------------------------
 // MAIN
 // --------------------------------------------

 int main()
 try {

    calculate();

    return 0;
 }

 // -------------------------------------------
 // Error Handling
 // -------------------------------------------

 catch (std::runtime_error& e) {

    std::cerr << e.what() << '\n';
    return 1;
 }

 catch (...) {

    std::cerr << "Unknown exception\n";
    return 2;
 }


 /*
 🔥 Excellent — this is one of the MOST IMPORTANT clean-code lessons in the whole calculator project.

# 📘 §6.6.2 Use of Functions

This section teaches:

```text id="zjlwmx"
One function = one logical responsibility
```

🔥 That is REAL software engineering.

---

# 🧠 Core Problem

Old `main()` did TWO jobs:

---

# ❌ Job 1

```text id="7r4q0g"
program startup/shutdown
error handling
```

---

# ❌ Job 2

```text id="whqjrt"
calculator loop
```

---

👉 Mixing both:
❌ harder to read
❌ structure unclear

---

# 💡 Book Philosophy

> A function should perform ONE logical action.

🔥 VERY important design principle.

---

# 🟢 Solution → Separate Function

Book creates:

```cpp id="5b5g1d"
void calculate()
```

---

# 🧠 Meaning

Now:

```text id="d53qoh"
main() → program management
calculate() → calculator logic
```

🔥 clean separation.

---

# 💥 Why This is Better

Now structure becomes obvious:

```text id="jlwmjy"
main()
   ↓
calculate()
   ↓
expression()
   ↓
term()
   ↓
primary()
```

👉 beautiful hierarchy ✔️

---

# 📘 FULL CLEANED `.cpp` CODE (Function-Oriented Version)

```cpp id="ldc63i"
// calculator.cpp
// Chapter 6.6.2 - Function-Oriented Clean Version

#include <iostream>
#include <stdexcept>
#include <cmath>

// -----------------------------------------------------------------------------
// Symbolic Constants
// -----------------------------------------------------------------------------

constexpr char number = '8';
constexpr char quit   = 'q';
constexpr char print  = ';';

constexpr const char* prompt = "> ";
constexpr const char* result = "= ";

// -----------------------------------------------------------------------------
// Token
// -----------------------------------------------------------------------------

class Token {
public:

    char kind;
    double value;

    Token(char k)
        : kind{k}, value{0}
    {
    }

    Token(char k, double v)
        : kind{k}, value{v}
    {
    }
};

// -----------------------------------------------------------------------------
// Token Stream
// -----------------------------------------------------------------------------

class Token_stream {
public:

    Token get();
    void putback(Token t);

private:

    bool full {false};
    Token buffer {'0'};
};

// -----------------------------------------------------------------------------
// Global Token Stream
// -----------------------------------------------------------------------------

Token_stream ts;

// -----------------------------------------------------------------------------
// Putback
// -----------------------------------------------------------------------------

void Token_stream::putback(Token t)
{
    if (full) {
        throw std::runtime_error("putback() into full buffer");
    }

    buffer = t;
    full = true;
}

// -----------------------------------------------------------------------------
// Get Token
// -----------------------------------------------------------------------------

Token Token_stream::get()
{
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

// -----------------------------------------------------------------------------
// Function Declarations
// -----------------------------------------------------------------------------

double expression();
double term();
double primary();

void calculate();

// -----------------------------------------------------------------------------
// Primary
// -----------------------------------------------------------------------------

double primary()
{
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

// -----------------------------------------------------------------------------
// Term
// -----------------------------------------------------------------------------

double term()
{
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

// -----------------------------------------------------------------------------
// Expression
// -----------------------------------------------------------------------------

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

// -----------------------------------------------------------------------------
// Calculate
//
// Handles the calculator loop
// -----------------------------------------------------------------------------

void calculate()
{
    while (std::cin) {

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
}

// -----------------------------------------------------------------------------
// Main
//
// Handles:
//   startup
//   shutdown
//   fatal errors
// -----------------------------------------------------------------------------

int main()
try
{
    calculate();

    return 0;
}

// -----------------------------------------------------------------------------
// Error Handling
// -----------------------------------------------------------------------------

catch (std::runtime_error& e)
{
    std::cerr << e.what() << '\n';
    return 1;
}

catch (...)
{
    std::cerr << "Unknown exception\n";
    return 2;
}
```

---

# ⚙️ Compile

```bash id="7b4qvi"
g++ -std=c++17 -Wall -Wextra -Werror -pedantic calculator.cpp -o calculator
```

---

# ▶️ Run

```bash id="fxqjlwm"
./calculator
```

---

# 🧪 Example

```text id="2m7a41"
> 1+2*3;
= 7

> (1+2)*3;
= 9

> -5+10;
= 5

> 10%3;
= 1

> q
```

---

# 💥 BIG CLEAN-CODE LESSON

This section teaches:

```text id="fjlwm0"
Function names should describe program structure
```

🔥 VERY professional principle.

---

# 🎯 Real Developer Insight

Good programs read like:

```text id="jlwm11"
high-level story
```

Example:

```text id="jlwm12"
main()
  → calculate()
      → expression()
          → term()
              → primary()
```

👉 You can UNDERSTAND architecture just by reading function names 🔥

 */
