🔥 Excellent — now the calculator becomes a REAL mini programming language.

# 📘 §6.8 Variables

This is a HUGE upgrade.

Until now calculator only handled:

```text id="jlwm57"
1+2*3
```

Now it can store values:

```text id="jlwm58"
let x = 10;
x + 5;
```

🔥 That is the beginning of:

* interpreters
* scripting languages
* compilers

The uploaded text explains how variables, declarations, symbol tables, and grammar extensions are added to the calculator. 

---

# 🧠 Core Idea

We need:

```text id="’wini59"
(name, value)
```

pairs.

Example:

```text id="’wini60"
("x", 10)
("pi", 3.14159)
```

---

# 🟢 Variable Class

Book creates:

```cpp id="’wini61"
class Variable {
public:
    std::string name;
    double value;
};
```

---

# 💡 Meaning

Each variable stores:

| Field   | Meaning       |
| ------- | ------------- |
| `name`  | variable name |
| `value` | numeric value |

---

# 🟢 Variable Table

Book stores variables inside:

```cpp id="’wini62"
std::vector<Variable> var_table;
```

---

# 💡 Meaning

This becomes the calculator’s:

```text id="’wini63"
memory
```

🔥 Real interpreters also use symbol tables.

---

# 🟢 Why Vector?

Because we need:
✔️ many variables
✔️ searchable storage

---

# 🟢 `get_value()`

Book function:

```cpp id="’wini64"
double get_value(std::string s)
```

---

# 💡 Purpose

Find variable value by name.

Example:

```text id="’wini65"
x → 10
```

---

# 🟢 `set_value()`

Changes existing variable value.

---

# 🟢 Declaration Syntax

Book chooses:

```text id="’wini66"
let x = 5;
```

instead of:

```text id="’wini67"
double x = 5;
```

Because calculator only uses `double`.

---

# 🟢 New Grammar

Book extends grammar:

```text id="’wini68"
Statement:
    Declaration
    Expression

Declaration:
    "let" Name "=" Expression
```

🔥 HUGE parser evolution.

---

# 🟢 New Function → `statement()`

Now calculator handles BOTH:

* expressions
* declarations

---

# 💡 Flow

```text id="’wini69"
statement()
    ↓
if let
    declaration()
else
    expression()
```

---

# 🟢 Symbol Table Functions

Book adds:

---

# ✔️ `is_declared()`

Checks duplicate variable names.

---

# ✔️ `define_name()`

Adds new variable into table.

---

# ⚠️ Why Duplicate Check?

Because:

```text id="’wini70"
let x = 5;
let x = 10;
```

usually typo/error.

---

# 📘 FULL VARIABLES VERSION (`calculator.cpp`)

```cpp id="’wini71"
/*
    Calculator with Variables

    Supports:
        +  -  *  /  %
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

// -----------------------------------------------------------------------------
// Constants
// -----------------------------------------------------------------------------

constexpr char number = '8';
constexpr char name   = 'a';

constexpr char let    = 'L';

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

    std::string name;

    Token(char k)
        : kind{k}, value{0}
    {
    }

    Token(char k, double v)
        : kind{k}, value{v}
    {
    }

    Token(char k, std::string n)
        : kind{k}, value{0}, name{n}
    {
    }
};

// -----------------------------------------------------------------------------
// Variable
// -----------------------------------------------------------------------------

class Variable {
public:

    std::string name;
    double value;

    Variable(std::string n, double v)
        : name{n}, value{v}
    {
    }
};

// -----------------------------------------------------------------------------
// Variable Table
// -----------------------------------------------------------------------------

std::vector<Variable> var_table;

// -----------------------------------------------------------------------------
// Token Stream
// -----------------------------------------------------------------------------

class Token_stream {
public:

    Token get();

    void putback(Token t);

    void ignore(char c);

private:

    bool full {false};

    Token buffer {'0'};
};

// -----------------------------------------------------------------------------
// Global Token Stream
// -----------------------------------------------------------------------------

Token_stream ts;

// -----------------------------------------------------------------------------
// Variable Functions
// -----------------------------------------------------------------------------

double get_value(std::string s)
{
    for (const Variable& v : var_table) {

        if (v.name == s) {
            return v.value;
        }
    }

    throw std::runtime_error("undefined variable: " + s);
}

bool is_declared(std::string var)
{
    for (const Variable& v : var_table) {

        if (v.name == var) {
            return true;
        }
    }

    return false;
}

double define_name(std::string var, double value)
{
    if (is_declared(var)) {
        throw std::runtime_error(var + " declared twice");
    }

    var_table.push_back(Variable{var, value});

    return value;
}

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
// Ignore
// -----------------------------------------------------------------------------

void Token_stream::ignore(char c)
{
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
    case '=':

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

        if (std::isalpha(ch)) {

            std::string s;

            s += ch;

            while (std::cin.get(ch) &&
                   (std::isalpha(ch) || std::isdigit(ch))) {

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

// -----------------------------------------------------------------------------
// Function Declarations
// -----------------------------------------------------------------------------

double expression();
double term();
double primary();

double statement();
double declaration();

void calculate();
void clean_up_mess();

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
// Declaration
// -----------------------------------------------------------------------------

double declaration()
{
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

// -----------------------------------------------------------------------------
// Statement
// -----------------------------------------------------------------------------

double statement()
{
    Token t = ts.get();

    switch (t.kind) {

    case let:
        return declaration();

    default:
        ts.putback(t);
        return expression();
    }
}

// -----------------------------------------------------------------------------
// Cleanup
// -----------------------------------------------------------------------------

void clean_up_mess()
{
    ts.ignore(print);
}

// -----------------------------------------------------------------------------
// Calculate
// -----------------------------------------------------------------------------

void calculate()
{
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

// -----------------------------------------------------------------------------
// Main
// -----------------------------------------------------------------------------

int main()
try
{
    calculate();

    return 0;
}

catch (...)
{
    std::cerr << "Fatal error\n";
    return 2;
}
```

---

# ⚙️ Compile

```bash id="’wini72"
g++ -std=c++17 -Wall -Wextra -Werror -pedantic calculator.cpp -o calculator
```

---

# 🧪 Example

```text id="’wini73"
> let x = 10;
= 10

> x + 5;
= 15

> let y = (x * 2) + 1;
= 21

> y;
= 21

> q
```

---

# 💥 BIGGEST LESSON OF THIS SECTION

```text id="’wini74"
Variables require:
- grammar changes
- tokenizer changes
- parser changes
- runtime storage
```

🔥 This is REAL interpreter/compiler architecture thinking.
