#include <iostream>

// =================================
/// Declarations
// =================================

// Function declarations
int add(int a, int b);    // declaration
void print_result(const std::string& label, int value); //declaration

// global variable declaration (extern means declaration only)
extern int global_value; // declaration only


// =========================================
// Definitions
// =========================================

// global variable definition
int global_value = 100;

// function definition
int add(int a, int b) {

    return a + b;
}

// function definition
void print_result(const std::string& label, int value) {

    std::cout << label << " : " << value << '\n';
}

// ===========================================
// Main
// ============================================

int main() {

    // variable definition
    int x = 10;

    // variable definition
    int y = 20;

    // function call
    int result = add(x, y);

    // function call
    print_result("sum", result);

    // using global variable
    std::cout << "Global value: "
              << global_value
              << '\n';
}

/*
```cpp
import std;

// ===============================
// DECLARATIONS
// ===============================

// function declarations
int add(int a, int b);
void print_result(const std::string& label, int value);

// global variable declaration
extern int global_value;


// ===============================
// DEFINITIONS
// ===============================

// global variable definition
int global_value = 100;


// function definition
int add(int a, int b)
{
    return a + b;
}


// function definition
void print_result(const std::string& label, int value)
{
    std::cout << label << " : " << value << '\n';
}


// ===============================
// MAIN
// ===============================

int main()
{
    // variable definition
    int x = 10;

    // variable definition
    int y = 20;

    // function call
    int result = add(x, y);

    // function call
    print_result("Sum", result);

    // using global variable
    std::cout << "Global value : "
              << global_value
              << '\n';
}
```

இதில் என்ன என்ன உள்ளது:

| Code                        | Type                |
| --------------------------- | ------------------- |
| `int add(int a, int b);`    | Declaration         |
| `void print_result(...);`   | Declaration         |
| `extern int global_value;`  | Declaration only    |
| `int global_value = 100;`   | Definition          |
| `int add(...) {}`           | Definition          |
| `void print_result(...) {}` | Definition          |
| `int x = 10;`               | Variable definition |

---

# Important Understanding

## Declaration

```cpp
int add(int a, int b);
```

இதில்:

* function body இல்லை
* compiler-க்கு interface மட்டும் தெரியும்

---

## Definition

```cpp
int add(int a, int b)
{
    return a + b;
}
```

இதில்:

* actual implementation உள்ளது
* executable code உருவாகும்

---

## extern

```cpp
extern int global_value;
```

Meaning:

> “இந்த variable somewhere else define செய்யப்பட்டுள்ளது.”

Memory allocate ஆகாது.

---

## Real-world usage

Large projects-ல்:

### header file (`math.hpp`)

```cpp
int add(int a, int b);
```

### source file (`math.cpp`)

```cpp
int add(int a, int b)
{
    return a + b;
}
```

இது தான் real C++ architecture foundation.

*/
