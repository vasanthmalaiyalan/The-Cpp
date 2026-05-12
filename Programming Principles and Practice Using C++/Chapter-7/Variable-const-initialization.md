இந்த section முழுக்க author ஒரு very important habit கற்பிக்கிறார்:

> “Variables-ஐ always initialize செய்.”

இது beginner topic போல தோன்றினாலும்,
real-world C++-ல் மிகவும் பெரிய bugs avoid செய்யும் habit.

---

# Variable Declaration

Variable declaration:

* name
* type
* optional value

கொடுக்கிறது.

---

# Example 1

```cpp id="8vgfrt"
int a;
```

இதில்:

* type = int
* name = a
* value இல்லை

இதுதான் dangerous.

---

# Why dangerous?

`a` memory allocate ஆகும்.

ஆனால்:
அதற்குள் random garbage value இருக்கும்.

---

# Example

```cpp id="0uvn6j"
int a;

std::cout << a;
```

Possible outputs:

```text id="ghj95n"
-9283
728282
0
9182
```

Unpredictable.

---

# Example 2

```cpp id="zj2ys8"
double d = 7;
```

இதில்:

* declaration
* initialization

இரண்டும் உள்ளது.

---

# `=` syntax

இதனை copy initialization என்பார்கள்.

```cpp id="7jjyxg"
int x = 10;
```

Simple values-க்கு commonly use செய்வார்கள்.

---

# Example 3

```cpp id="5yoe4s"
vector<int> vi(10);
```

இதில்:

* vector உருவாகிறது
* size = 10

இந்த `( )` syntax constructor call.

---

# Meaning

```cpp id="8hrx7j"
vector<int> vi(10);
```

Creates:

```text id="yzj9jw"
[0,0,0,0,0,0,0,0,0,0]
```

---

# Example 4

```cpp id="x2z05v"
vector<int> vi2 {1,2,3,4};
```

இதில் `{ }` initializer list syntax.

Creates:

```text id="1ukr8w"
[1,2,3,4]
```

---

# Three initialization styles

| Syntax | Example               | Meaning          |
| ------ | --------------------- | ---------------- |
| `=`    | `int x = 5;`          | simple copy      |
| `( )`  | `vector<int> v(10);`  | constructor      |
| `{ }`  | `vector<int> v{1,2};` | initializer list |

---

# Constants

## const

```cpp id="9i6p28"
const int x = 7;
```

இதன் meaning:

> x change ஆகாது.

---

# Another syntax

```cpp id="ml6z5l"
const int x2 {9};
```

Modern preferred style.

---

# Error example

```cpp id="6c2p1s"
const int y;
```

Error.

---

# Why?

Author asks:

> “Value இல்லாமல் எப்படி constant இருக்கும்?”

Correct.

Constant என்றால்:
fixed value இருக்க வேண்டும்.

---

# Important Habit

Author strongly recommends:

## Always initialize variables.

---

# Dangerous example

```cpp id="u0s1rq"
void f(int z)
{
    int x;

    if (z > x)
    {
    }

    x = 7;
}
```

---

# Problem

`x` uninitialized.

அதனால்:

```cpp id="8gw0a6"
z > x
```

undefined behavior.

---

# Undefined behavior meaning

மிக முக்கியமான C++ concept.

Meaning:

> Program result predictable இல்லை.

Possible:

* different outputs
* crashes
* strange bugs
* random behavior

---

# Why this happens?

Memory already contains old bits.

Example:

```text id="klcfsf"
100101001010
```

Compiler:

> “நீ value assign செய்யவில்லை.
> நான் என்ன இருக்கிறதோ அதையே use செய்கிறேன்.”

---

# Why bugs become dangerous?

Because:
sometimes program works.

Sometimes fails.

இதுதான் worst kind of bug.

---

# Example

Today:

```text id="xj78pf"
z > x = true
```

Tomorrow:

```text id="1r6vtt"
z > x = false
```

Same code.

Different machine.

Different result.

---

# Compilers warn but cannot fully protect

Compiler warnings helpful.

But:
complex programs-ல் எல்லா bugs-யும் detect செய்ய முடியாது.

---

# Important real-world point

பல old programmers:

* variables initialize செய்ய மாட்டார்கள்.

Reasons:

* old languages habit
* performance obsession
* older C style

---

# Author advice

> “Please don’t continue that bad habit.”

Very important advice.

---

# `=` vs `{}` preference

Author preference:

---

# Use `=` for simple values

```cpp id="3b5b9j"
int x = 5;
double d = 3.14;
```

---

# Use `{}` for complex construction

```cpp id="3tspwu"
vector<int> v {1,2,3};
```

---

# Why `{}` important in modern C++?

Safer.

Example:

```cpp id="27s7cv"
int x {3.7};
```

Error.

Because:
data loss possible.

But:

```cpp id="5vzk1q"
int x = 3.7;
```

Allowed silently.

---

# BEST PRACTICE .CPP EXAMPLE

```cpp
import std;

int main()
{
    // =====================================
    // Uninitialized variable (BAD)
    // =====================================

    int garbage_value;

    std::cout << "Uninitialized value (dangerous): "
              << garbage_value
              << '\n';


    // =====================================
    // Initialized variables (GOOD)
    // =====================================

    int age = 21;

    double price = 199.99;

    std::string name {"Vasanth"};


    // =====================================
    // Constant declarations
    // =====================================

    const double pi = 3.1415926535;

    const int max_users {100};


    // =====================================
    // Vector initialization
    // =====================================

    std::vector<int> numbers(5);

    std::vector<int> scores {95, 88, 76, 100};


    // =====================================
    // Output
    // =====================================

    std::cout << "\nInitialized variables:\n";

    std::cout << "Age        : "
              << age
              << '\n';

    std::cout << "Price      : "
              << price
              << '\n';

    std::cout << "Name       : "
              << name
              << '\n';


    std::cout << "\nConstants:\n";

    std::cout << "Pi         : "
              << pi
              << '\n';

    std::cout << "Max users  : "
              << max_users
              << '\n';


    std::cout << "\nVector with size constructor:\n";

    for (int value : numbers)
    {
        std::cout << value << ' ';
    }

    std::cout << "\n\nVector with initializer list:\n";

    for (int value : scores)
    {
        std::cout << value << ' ';
    }

    std::cout << '\n';
}
```

---

# What this code teaches

| Concept                  | Example                      |
| ------------------------ | ---------------------------- |
| Uninitialized variable   | `int garbage_value;`         |
| `=` initialization       | `int age = 21;`              |
| `{}` initialization      | `string name {"Vasanth"};`   |
| const variable           | `const double pi`            |
| `( )` constructor syntax | `vector<int> numbers(5)`     |
| `{}` initializer list    | `vector<int> scores {95,88}` |

---

# Most Important Lesson of This Section

## NEVER DO THIS

```cpp id="t8o20u"
int x;
```

---

## Prefer THIS

```cpp id="g0um1v"
int x = 0;
```

or

```cpp id="x6r4mw"
int x {0};
```

---

# Real Professional C++ Habit

Professional C++ developers:

* initialize everything
* avoid undefined behavior
* prefer predictable code

இதுவே stable systems build செய்ய foundation.
