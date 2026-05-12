இந்த section-ல் author சொல்வது:

> “C++-ல் programmer எந்தெந்த வகையான things create செய்ய முடியும்?”

அதாவது:
C++ program build செய்ய பயன்படுத்தும் முக்கிய building blocks.

---

# 1. Variables and Constants

## Variable

மாறக்கூடிய value.

```cpp id="vrp0lq"
int age = 20;
```

பிறகு change செய்யலாம்:

```cpp id="2m7q6i"
age = 25;
```

---

## Constant

மாற்ற முடியாத value.

```cpp id="zvhk5f"
const int max_size = 100;
```

இதற்கு பிறகு:

```cpp id="1jv8hh"
max_size = 200; // error
```

---

# Simple meaning

| Type     | Meaning            |
| -------- | ------------------ |
| Variable | value change ஆகும் |
| Constant | value fixed        |

---

# 2. Functions

Function:
ஒரு வேலை செய்யும் reusable code block.

```cpp id="4s4l7s"
int add(int a, int b)
{
    return a + b;
}
```

Use:

```cpp id="xlm4ik"
int result = add(10, 20);
```

---

# Function purpose

* code reuse
* clean structure
* modular programming

---

# 3. Namespaces

பெயர் conflict avoid செய்ய.

---

# Problem

```cpp id="8rkx2n"
int value = 10;
```

வேறு library-லும்:

```cpp id="4gtyu9"
int value = 50;
```

Conflict.

---

# Solution

```cpp id="a7xztw"
namespace A
{
    int value = 10;
}
```

Use:

```cpp id="1ek1mi"
A::value
```

---

# Real example

```cpp id="k4cbqn"
std::cout
```

`cout` என்பது `std` namespace-க்குள் உள்ளது.

---

# 4. Modules

Modern C++ feature.

பெரிய programs-ஐ:

* separate parts
* reusable units

ஆக organize செய்ய.

---

# Example

```cpp id="uz1p44"
import std;
```

இதில்:

* standard library module import ஆகிறது

---

# Why modules?

* faster compile
* cleaner code
* better dependency management

---

# 5. Types (Classes and Enumerations)

மிக முக்கியமான concept.

---

# Class

Custom type உருவாக்கலாம்.

```cpp id="zic13v"
class Car
{
public:
    std::string name;
    int speed;
};
```

Use:

```cpp id="2j5c8n"
Car c;
```

---

# Meaning

நாமே புதிய datatype உருவாக்குகிறோம்.

---

# Enumeration (enum)

Fixed set of values.

```cpp id="1m4ewk"
enum Color
{
    red,
    green,
    blue
};
```

---

# Why useful?

Invalid values avoid செய்ய.

---

# 6. Templates

Generic programming.

ஒரே code:
பல types-க்கு work செய்யும்.

---

# Without template

```cpp id="z1q4s5"
int add_int(int a, int b);
double add_double(double a, double b);
```

Repeated code.

---

# With template

```cpp id="z9m5hl"
template<typename T>
T add(T a, T b)
{
    return a + b;
}
```

Works for:

* int
* double
* float
* etc.

---

# Why templates important?

STL முழுவதும் templates.

Examples:

* vector
* map
* sort

---

# 7. Concepts

Modern C++ feature.

Template constraints.

---

# Problem

Template எந்த type-க்கும் allow செய்யும்.

Sometimes unsafe.

---

# Concept solution

```cpp id="qdzm5s"
template<typename T>
concept Number = std::integral<T>;
```

Meaning:

> “இந்த template integers மட்டும் accept செய்யும்.”

---

# Why concepts?

* cleaner errors
* safer templates
* readable generic code

---

# Overall Big Picture

இந்த section basically:

> “C++ programmer உருவாக்கும் major entities என்ன?”

என்று overview கொடுக்கிறது.

---

# Complete Summary Table

| Entity    | Purpose                 |
| --------- | ----------------------- |
| Variable  | changeable data         |
| Constant  | fixed data              |
| Function  | reusable logic          |
| Namespace | avoid name conflicts    |
| Module    | organize large programs |
| Class     | custom datatype         |
| Enum      | fixed set of values     |
| Template  | generic programming     |
| Concept   | template restrictions   |

---

# Most Important Ones for Beginners

முதலில் strong ஆக கற்றுக்கொள்ள வேண்டியது:

1. Variables
2. Functions
3. Classes
4. Namespaces

---

# Advanced Topics

பிறகு:

* Templates
* Concepts
* Modules

இவை modern advanced C++ topics.
