இந்த section முழுக்க ஒரு மிக முக்கியமான concept பற்றி:

# Scope

Simple-ஆக:

> “ஒரு name எங்கு visible இருக்கும்?”

---

# Definition

Author சொல்வது:

> Scope என்பது program text-ன் ஒரு region.

அதாவது:
ஒரு variable/function/class
எந்த area-க்குள் பயன்படுத்தலாம் என்பதைக் scope தீர்மானிக்கும்.

---

# Important Rule

## Name declared after only usable

---

# Example

```cpp id="u6gjcg"
void f()
{
    g();
}
```

Error.

ஏன்?

`g()` இன்னும் declare செய்யப்படவில்லை.

---

# But this works

```cpp id="uozgjw"
void f()
{
}

void g()
{
    f();
}
```

ஏன்?

`g()` define ஆகும் போது:
`f()` already declared.

---

# Variable Example

```cpp id="0quk0e"
int x = y;
int y = x;
```

---

# Problem

முதல் line-ல்:
`y` இன்னும் exist ஆகவில்லை.

அதனால் error.

---

# Second line okay

ஏனெனில்:
`x` already declared.

---

# Key Rule

## Scope starts from declaration point

NOT before declaration.

---

# Nested Scope

மிக important concept.

---

# Example

```cpp id="c5uqjp"
int x = 10;

{
    std::cout << x;
}
```

Inner block:
outer scope variables பார்க்க முடியும்.

---

# But reverse impossible

```cpp id="9xnmkg"
{
    int y = 5;
}

std::cout << y;
```

Error.

---

# Why?

Inner scope variables:
outside visible இல்லை.

---

# Types of Scopes

Author several scopes list செய்கிறார்.

---

# 1. Global Scope

Everything outside functions/classes.

```cpp id="q3l6qf"
int x = 10;
```

Global variable.

---

# Visible everywhere

இதனால் dangerous கூட.

---

# 2. Module Scope

Inside module.

Modern C++ feature.

---

# 3. Namespace Scope

```cpp id="8suwbo"
namespace A
{
    int x = 5;
}
```

`x` exists inside namespace A.

Use:

```cpp id="jlwmr7"
A::x
```

---

# 4. Class Scope

```cpp id="7h3uyd"
class Car
{
    int speed;
};
```

`speed` exists inside class.

---

# 5. Local Scope

Inside function/block.

```cpp id="l07fzh"
void f()
{
    int x = 5;
}
```

x local variable.

---

# 6. Statement Scope

Example:

```cpp id="54v5ut"
for (int i = 0; i < 10; ++i)
{
}
```

`i` only exists inside loop.

---

# Main Purpose of Scope

மிக முக்கியமான line:

> “Keep names local.”

---

# Why?

Large programs:

* thousands of variables
* thousands of functions

Everything global என்றால்:
huge chaos.

---

# Example

```cpp id="p01n14"
int max(int a, int b)
{
    int m;
}
```

---

# Scope analysis

| Name | Scope  |
| ---- | ------ |
| max  | global |
| a    | local  |
| b    | local  |
| m    | local  |

---

# Another function

```cpp id="ztpw7z"
int abs(int a)
{
}
```

இந்த `a`
வேறு variable.

No conflict.

---

# Why no clash?

Different scopes.

---

# Clash meaning

Same scope-ல்:
same incompatible names.

---

# Conditional Operator `?:`

```cpp id="d1pqlw"
(a >= 0) ? a : -a
```

Meaning:

If:

```text id="0n0y2f"
a >= 0
```

then:

```text id="2s2uvc"
a
```

else:

```text id="h47t8i"
-a
```

---

# Equivalent long version

```cpp id="xocjlwm"
if (a >= 0)
{
    return a;
}
else
{
    return -a;
}
```

---

# Author advice

Keep scopes local.

---

# Why global variables dangerous?

மிக முக்கியமான software engineering point.

---

# Example

```cpp id="qod0lv"
int x = 0;
```

Suppose:
100 functions modify x.

Debugging nightmare.

---

# Questions become impossible

* யார் x change செய்தது?
* எப்போது?
* ஏன்?
* எந்த file?

---

# Real-world rule

Good programs:
very few global variables.

---

# Hiding / Shadowing

மிக important.

---

# Example

```cpp id="v4x5u5"
int x = 0;

void f()
{
    int x = 7;
}
```

Inside f():
local x hides global x.

---

# Another nested example

```cpp id="4p95nx"
void f()
{
    int x = 7;

    {
        int x = 10;
    }
}
```

Inner x:
outer x-ஐ hide செய்கிறது.

---

# Author warns

Too much nesting + hiding:
confusing.

---

# Large Example Analysis

---

# Class Scope Example

```cpp id="ryoq7o"
class My_vector
{
    vector<int> v;
};
```

`v`
only inside class.

---

# Function Local Variable

```cpp id="rxr8ep"
int r = 0;
```

local to largest().

---

# Loop Scope

```cpp id="pxa0a4"
for (int i = 0; ...)
```

`i`
only inside loop.

---

# After loop

```cpp id="nqarfj"
i
```

Error.

---

# Important Real-world Advice

## Larger scope → better name needed

---

# BAD global names

```cpp id="fy91ei"
x
y
f
```

Terrible names globally.

---

# Better

```cpp id="j3h58k"
total_users
database_connection
calculate_salary
```

---

# Nested Constructs

C++ supports nesting.

---

# Function inside class

```cpp id="21m6uc"
class C
{
public:
    void g()
    {
    }
};
```

Very common.

---

# Class inside class

```cpp id="s19br2"
class Outer
{
    class Inner
    {
    };
};
```

Advanced use.

---

# Class inside function

```cpp id="p2zjlwm"
void f()
{
    class L
    {
    };
}
```

Rare.

Usually code smell.

---

# Function inside function

```cpp id="5f7e0s"
void f()
{
    void g()
    {
    }
}
```

NOT allowed in C++.

---

# Alternative

Use lambda.

---

# Nested Blocks

```cpp id="tlq63w"
if (x > y)
{
}
else
{
    {
    }
}
```

Normal.

But too much nesting dangerous.

---

# Important Human Factor

Author says:

> Complicated nesting hides bugs.

Absolutely true.

---

# Indentation Importance

Very important practical advice.

---

# BAD CODE

Ugly indentation:

* unreadable
* bug-prone
* impossible debugging

---

# Professional Rule

Readable code = maintainable code.

---

# BEST .CPP EXAMPLE

```cpp id="xjlwmh"
import std;


// =====================================
// Global scope
// =====================================

int global_value = 100;


// =====================================
// Function in global scope
// =====================================

int max_value(int a, int b)
{
    // local scope
    int result;

    if (a >= b)
    {
        result = a;
    }
    else
    {
        result = b;
    }

    return result;
}


// =====================================
// Class scope
// =====================================

class Number_store
{
private:
    std::vector<int> values;

public:

    void add(int value)
    {
        values.push_back(value);
    }

    int largest()
    {
        int biggest = 0;

        // statement scope
        for (int i = 0; i < values.size(); ++i)
        {
            biggest = max(biggest, values[i]);
        }

        // i no longer exists here

        return biggest;
    }
};


// =====================================
// Function demonstrating shadowing
// =====================================

void scope_demo()
{
    int x = 10;

    std::cout << "Outer x : "
              << x
              << '\n';

    {
        int x = 20;

        std::cout << "Inner x : "
                  << x
                  << '\n';
    }

    std::cout << "Outer x again : "
              << x
              << '\n';
}


// =====================================
// Main
// =====================================

int main()
{
    Number_store store;

    store.add(5);
    store.add(40);
    store.add(12);

    std::cout << "Largest value : "
              << store.largest()
              << '\n';


    scope_demo();


    std::cout << "Global value : "
              << global_value
              << '\n';
}
```

---

# What this code teaches

| Concept         | Example              |
| --------------- | -------------------- |
| Global scope    | `global_value`       |
| Function scope  | `max_value()`        |
| Local variable  | `result`             |
| Class scope     | `values`             |
| Statement scope | `for(int i...)`      |
| Shadowing       | inner `x`            |
| Nested block    | `{}` inside function |

---

# Most Important Lessons of Scope

## 1. Keep names local

---

## 2. Avoid globals

---

## 3. Avoid deep nesting

---

## 4. Avoid variable hiding

---

## 5. Good indentation matters

---

# Real-world Software Engineering Truth

Large systems survive because:

* scopes control complexity
* local names prevent conflicts
* readable structure reduces bugs

இதுதான் modern software maintainability foundation.
