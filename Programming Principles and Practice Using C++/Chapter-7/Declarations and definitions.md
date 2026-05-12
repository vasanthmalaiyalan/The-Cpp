இந்த section C++-ல் மிகவும் fundamental concept ஒன்றை explain செய்கிறது:

# Declaration vs Definition

இந்த இரண்டு concepts புரிந்தால்:

* compiler எப்படி think செய்கிறது
* large programs எப்படி build ஆகிறது
* headers ஏன் இருக்கிறது
* linking என்ன

எல்லாம் slowly புரிய ஆரம்பிக்கும்.

---

# முதலில் simple definition

| Concept     | Meaning                                                     |
| ----------- | ----------------------------------------------------------- |
| Declaration | “இப்படி ஒரு thing இருக்கிறது” என்று compiler-க்கு சொல்லுவது |
| Definition  | அந்த thing-ஐ உண்மையாக உருவாக்குவது                          |

---

# Author சொல்வது:

## A declaration introduces a name

அதாவது:

ஒரு name:

* variable
* function
* class

எதுவாக இருந்தாலும் முதலில் compiler-க்கு அறிமுகப்படுத்த வேண்டும்.

---

# Example 1

```cpp
int a = 7;
```

இதில்:

* `a` என்ற variable உருவாக்கப்படுகிறது
* type = int
* value = 7

இது declaration + definition இரண்டும்.

ஏனெனில்:

* compiler-க்கு சொல்லுகிறது
* memory-யும் allocate செய்கிறது

---

# Example 2

```cpp
const double cd = 8.7;
```

இதில்:

* `cd` → constant
* double type
* 8.7 value

இதும் declaration + definition.

---

# Example 3

```cpp
double sqrt(double);
```

இது important.

இதில்:

* sqrt என்ற function இருக்கிறது
* input = double
* output = double

என்று மட்டும் சொல்லப்படுகிறது.

ஆனால்:
function body இல்லை.

அதனால் இது declaration மட்டும்.

---

# Example 4

```cpp
vector<Token> v;
```

இதில்:

* `v` என்ற vector variable உருவாகிறது

இதும் definition.

ஏனெனில் memory allocate ஆகிறது.

---

# Before using name → must declare

மிக முக்கியமான C++ rule:

> Use செய்வதற்கு முன் declare செய்ய வேண்டும்.

---

# Example

```cpp
int main()
{
    std::cout << f(i);
}
```

Compiler errors:

* std தெரியாது
* cout தெரியாது
* f தெரியாது
* i தெரியாது

ஏன்?

அவை declare செய்யப்படவில்லை.

---

# import std;

```cpp
import std;
```

இதனால்:

* std namespace declarations வரும்
* cout declaration கிடைக்கும்

---

# Important concept

நாம் `cout` எப்படி internally build செய்தார்கள் என்று தெரிய வேண்டிய அவசியம் இல்லை.

நமக்கு தெரிந்தால் போதும்:

```cpp
cout << "hello";
```

எப்படி use செய்வது என்று.

இதுதான் interface concept.

---

# Interface vs Implementation

மிக முக்கியமான software engineering concept.

| Part           | Meaning                     |
| -------------- | --------------------------- |
| Interface      | எப்படி use செய்வது          |
| Implementation | உள்ளே எப்படி வேலை செய்கிறது |

---

# Example

## Declaration

```cpp
double sqrt(double);
```

இது interface.

அதாவது:

> “இந்த function இப்படிப் பயன்படுத்தலாம்”

---

## Definition

```cpp
double sqrt(double d)
{
    return d * d;
}
```

இது implementation.

---

# Another example

```cpp
int f(int);
```

இதில்:

* function body இல்லை
* declaration மட்டும்

---

# Then:

```cpp
int i = 7;
```

இதில்:

* i variable உருவாக்கப்பட்டது

definition.

---

# Compile vs Link

இந்த part மிகவும் important.

இந்த code compile ஆகும்:

```cpp
int f(int);

int main()
{
    int i = 7;
    cout << f(i);
}
```

ஏன் compile ஆகிறது?

Because compiler knows:

* f exists
* how to call it

---

ஆனால் link error வரும்.

ஏன்?

Because actual definition இல்லை.

Compiler:

> “சரி function இருக்கிறது.”

Linker:

> “ஆனா அது எங்கே?”

---

# Definition fully specifies entity

Definition:

* memory allocate செய்யும்
* function body கொடுக்கும்

---

# Examples

```cpp
int a = 7;
```

Memory allocated.

---

```cpp
vector<double> v;
```

Memory allocated.

---

```cpp
double sqrt(double d)
{
}
```

Function body exists.

---

# Declaration that is NOT definition

```cpp
double sqrt(double);
```

No body.

---

```cpp
extern int a;
```

இதன் meaning:

> “a somewhere else இருக்கிறது.”

Memory allocate ஆகாது.

---

# extern meaning

```cpp
extern int x;
```

இதில்:

* x exists elsewhere
* this file only references it

Mostly global variables-க்கு use செய்வார்கள்.

---

# Cannot define twice

மிக important.

```cpp
int a;
int a;
```

Error.

ஏன்?

ஒரே variable-க்கு:

* இரண்டு memory allocations possible இல்லை.

---

# Same for functions

```cpp
double sqrt(double d)
{
}

double sqrt(double d)
{
}
```

Error.

ஏனெனில்:
same function two implementations impossible.

---

# But declarations many times allowed

```cpp
double sqrt(double);
double sqrt(double);
double sqrt(double);
```

Allowed.

ஏன்?

அவை interface மட்டும்.

Memory allocate ஆகவில்லை.

---

# Inconsistent declarations

```cpp
double sqrt(double);
int sqrt(double);
```

Error.

ஏன்?

Compiler confusion:

ஒரே input type:

* output double?
* output int?

எது correct?

---

# Key idea

## Definition = actual object/function

## Declaration = promise/interface

---

# Why C++ separates declaration and definition?

மிக முக்கியமான software architecture reason.

---

# Large program problem

Imagine:

* Chrome browser
* Linux kernel
* Unreal Engine

Millions of lines.

ஒவ்வொரு file-க்கும்:

* மற்ற எல்லா file implementations-யும் தெரிந்தால்
* compile impossible slow ஆகும்.

---

# Solution

Only declaration share செய்வோம்.

Implementation separate files-ல் இருக்கும்.

இதுதான்:

* header files
* modules
* APIs

foundation.

---

# Important line

> Declaration tells HOW to use.

> Definition tells HOW it works.

---

# Function bodies consume memory

Interesting point.

Variable:

```cpp
int x;
```

Memory consume செய்கிறது.

---

Function:

```cpp
void f()
{
}
```

இதுவும் machine code memory occupy செய்கிறது.

---

# Forward declaration

மிக முக்கியமான concept.

---

# Problem

```cpp
double primary()
{
    expression();
}
```

Compiler:

> expression என்ன?

அது கீழே define செய்யப்பட்டிருக்கலாம்.

---

# Solution

```cpp
double expression();
```

முன்னாடி declare செய்யலாம்.

இதுதான் forward declaration.

---

# Why needed?

Functions ஒருவரை ஒருவர் call செய்யலாம்.

```text
expression -> term -> primary -> expression
```

Circular calls.

---

# Why declare before use?

Author gives textbook analogy.

ஒரு textbook-ல்:

* first define term
* then use term

இல்லையெனில் confusion.

Same in programming.

---

# Final core ideas of this section

## 1. Declaration

Compiler-க்கு:

> “இப்படி ஒரு thing இருக்கிறது”

---

## 2. Definition

Actually:

* memory allocate
* function body create

---

## 3. Declaration can repeat

Allowed.

---

## 4. Definition only once

Otherwise ambiguity.

---

## 5. Interface vs Implementation

மிக முக்கியமான software engineering principle.

---

## 6. Forward declarations

Circular calls handle செய்ய உதவும்.

---

## 7. Large systems depend on this

Headers, modules, libraries, APIs
எல்லாம் இந்த declaration/definition concept மேல் build ஆனவை.
