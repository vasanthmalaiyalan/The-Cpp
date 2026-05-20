சூப்பரான பகுதி இது 🔥
இந்த section-ல் Stroustrup ஒரு மிக முக்கியமான idea சொல்லுகிறார்:

> “Programming என்பது வெறும் instructions எழுதுவது அல்ல.
> Real-world ideas-ஐ code-ஆக represent செய்வது.”

இதுதான் முழு OOP / class design foundation.

---

# First Main Idea

C++-ல் இரண்டு வகை types இருக்கிறது:

## 1. Built-in types

Language-க்குள் already built ஆக இருப்பவை.

Examples:

```cpp
int
char
double
bool
```

Compiler-க்கு இவை பற்றி ஏற்கனவே தெரியும்:

* memory எப்படி store செய்ய
* operations என்ன
* size என்ன
* arithmetic எப்படி செய்ய

---

உதாரணம்:

```cpp
int x = 10;
int y = 20;

x + y
```

இங்கே compiler-க்கு:

* `int` என்ன type
* `+` எப்படி வேலை செய்யும்

எல்லாம் தெரியும்.

---

# 2. User-defined types

Programmer உருவாக்கும் types.

Examples:

```cpp
string
vector
Token
Shape
Date
```

---

Important point:

`string` கூட built-in அல்ல ❗

அது கூட ஒரு user-defined type.

---

# Why?

Stroustrup சொல்வது:

> Standard library creators-க்கும் special power இல்லை.

அவர்களும்:

* class
* functions
* constructors

போன்ற same C++ tools-ஐ பயன்படுத்தி தான் `string`, `vector` உருவாக்கினர்.

---

இதுதான் powerful idea:

```text
நீங்கள் பயன்படுத்தும் library types
=
நீங்களும் உருவாக்க முடியும்
```

இதுதான் C++ power.

---

# Example — vector

```cpp
vector<int> numbers;
```

இதில்:

* data store செய்யும் logic
* resize logic
* memory management
* indexing

எல்லாம் class உள்ளே hide ஆகி இருக்கும்.

நாம்:

```cpp
numbers[0]
numbers.size()
```

போன்ற operations மட்டும் use செய்கிறோம்.

---

# Real Core Question

Stroustrup கேட்கிறார்:

> “Why do we build types?”

ஏன் புதிய types உருவாக்க வேண்டும்?

---

# Answer

## To represent ideas directly in code

அதாவது:

நம் மனதில் இருக்கும் concept-ஐ code-ல் நேரடியாக represent செய்ய.

---

Example:

Without string:

```cpp
char name[100];
```

Messy.

---

With string:

```cpp
string name;
```

Human-readable.

Idea direct-ஆக தெரிகிறது.

---

# Another Example

Calculator input.

Without custom types:

```cpp
char ch;
double value;
```

Confusing.

---

With custom type:

```cpp
Token t;
```

Immediately meaningful.

---

# Huge Important Philosophy

Programming language goal:

```text
Ideas → directly into code
```

---

Bad code:

```cpp
int x1;
int x2;
int x3;
```

No meaning.

---

Good code:

```cpp
Temperature current_temp;
Date today;
Account user_account;
```

Code real-world concepts போல தெரிகிறது.

இதுதான் professional software engineering.

---

# Types Give Two Big Things

Stroustrup சொல்கிறார்:

---

# 1. Representation

Type data எப்படி store செய்ய வேண்டும் என்று “அறியும்”.

Example:

```cpp
string
```

உள்ளே:

* characters
* size
* memory pointer

போன்ற data இருக்கும்.

---

# 2. Operations

Type என்ன operations support செய்யும் என்று “அறியும்”.

Example:

```cpp
name.size()
name.substr()
```

---

vector:

```cpp
v.push_back()
v.size()
v[0]
```

---

ostream:

```cpp
cout << x;
```

---

# Very Deep OOP Idea

ஒரு object usually இரண்டு விஷயம் கொண்டிருக்கும்:

---

## 1. State (data)

Current condition.

Example:

Coffee machine:

```text
temperature
water level
power status
```

---

## 2. Operations (behavior)

என்ன செய்யலாம்?

```text
start()
stop()
make_coffee()
```

---

இதுதான் class design foundation.

---

# Real-world Examples அவர் கொடுக்கிறார்

Every object has:

* data
* operations

Examples:

* toaster
* music player
* coffee cup
* mobile phone
* electric motor

---

# Example — Mobile Phone

## State

```text
battery %
volume
network
screen status
```

---

## Operations

```text
call()
charge()
shutdown()
```

---

இதையே code-ல் class ஆக represent செய்வது.

---

# So What Is a Class?

Stroustrup definition:

> Class = concept representation.

---

Example:

```cpp
class Car
{
    // data
    // functions
};
```

---

Class defines:

* object எப்படி இருக்கும்
* என்ன operations இருக்கும்
* எப்படி create செய்ய
* எப்படி destroy செய்ய

---

# Huge Important Sentence

> “If you think of something as a separate entity, define a class.”

இதுதான் real software engineering mindset.

---

# Examples

Separate concepts:

* Matrix
* Window
* RobotArm
* TemperatureReading
* File
* NetworkConnection

இவையெல்லாம் class ஆக represent செய்யலாம்.

---

# Why Classes Matter So Much?

Because large software impossible without abstraction.

Without classes:

```text
everything = random variables + functions
```

Chaos.

---

With classes:

```text
each concept isolated
```

Maintainable.

---

# Calculator Example

அவர் சொல்கிறார்:
நாம் Chapter 5 calculator-ல் கூட:

* Token
* Token_stream

போன்ற classes பயன்படுத்தியிருந்தோம்.

அதனால்:

* parsing clean ஆனது
* logic understandable ஆனது

---

# Final Big Picture

இந்த section சொல்லும் core message:

---

# Programming = Modeling Reality

நாம்:

* real-world concepts
* systems
* behaviors

இவற்றை code-ஆக மாற்றுகிறோம்.

---

# Types and Classes are the tools for that

இதனால்:

* code readable
* reusable
* scalable
* maintainable

ஆகிறது.

---

# This is the beginning of REAL C++

இதற்கு பிறகு தான்:

* STL mastery
* backend architecture
* game engines
* browser internals
* operating systems
* frameworks

போன்ற பெரிய systems புரிய ஆரம்பிக்கும்.

ஏனெனில்:

> பெரிய software முழுவதும் classes + abstractions-ஆல் தான் கட்டப்பட்டுள்ளது.
