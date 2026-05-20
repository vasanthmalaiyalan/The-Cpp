இந்த chapter-லும் author என்ன சொல்ல வருகிறார் என்றால்:

> “இப்போ variables, functions பார்த்தோம்.
> இனிமேல் நாமே புதிய data types உருவாக்குவது எப்படி என்று பார்க்கலாம்.”

அதாவது:

* class
* object
* enum
* operator overloading

போன்ற **real C++ OOP foundation** இங்கே ஆரம்பமாகிறது.

---

# Chapter 8 — Simple Tamil Explanation

# §8.1 User-defined types

C++-ல் already இருக்கும் types:

* int
* double
* char

ஆனால் நாமே புதிய type உருவாக்கலாம்.

உதாரணம்:

```cpp id="f2d8xp"
Date today;
```

இங்கே `Date` என்பது நாம் உருவாக்கிய type.

இதுதான் user-defined type.

---

# §8.2 Classes and members

## Class என்றால்?

பல variables + functions ஒன்றாக group செய்வது.

```cpp id="2y9xk4"
class Person {
public:
    string name;
    int age;
};
```

---

## Object

```cpp id="i0u7m8"
Person p;
```

இப்போது:

* `p.name`
* `p.age`

பயன்படுத்தலாம்.

---

## Members

class உள்ளே இருக்கும்:

* variables
* functions

இவை members.

---

# §8.3 Interface and implementation

இந்த concept மிகவும் முக்கியம்.

---

## Interface

“Outside world பயன்படுத்த வேண்டிய பகுதி”

உதாரணம்:

```cpp id="l6l6zn"
class Car {
public:
    void start();
};
```

User:

* `start()` மட்டும் பார்க்கிறார்.

---

## Implementation

Inside actual code:

```cpp id="61ifxj"
void Car::start()
{
    // engine logic
}
```

---

இதன் benefit:

* clean design
* maintain easy
* internal logic hide செய்யலாம்

---

# §8.4 Evolving a class: Date

இந்த chapter முழுக்க `Date` class slowly improve செய்வார்கள்.

உதாரணம்:

* day
* month
* year

---

# struct and functions

ஆரம்பத்தில் simple struct:

```cpp id="5qy4v7"
struct Date {
    int day;
    int month;
    int year;
};
```

---

# Member functions

Class உள்ளே functions.

```cpp id="j4l3xa"
class Date {
public:
    void print();
};
```

---

# Constructors

object உருவாகும் போது automatic function call ஆகும்.

```cpp id="z30z6g"
Date today(20, 5, 2026);
```

இதற்கு constructor:

```cpp id="0yz2qr"
Date(int d, int m, int y)
```

---

இதன் purpose:

* object valid state-ல் உருவாக வேண்டும்.

---

# Keep details private

மிக முக்கியமான OOP concept.

```cpp id="e3i2w4"
class Bank {
private:
    int money;
};
```

Outside:

```cpp id="im7d8x"
obj.money // error
```

---

ஏன்?

யாரும் direct modify செய்யக்கூடாது.

Security + correctness.

---

# Defining member functions

```cpp id="68w24l"
void Date::print()
{
    cout << day;
}
```

`Date::`

என்பது:

> இந்த function Date class-க்கு சேர்ந்தது

என்று சொல்கிறது.

---

# Referring to current object

Inside class:

```cpp id="o4k6xq"
this
```

means:

> current object pointer

---

உதாரணம்:

```cpp id="6c6ezr"
this->day
```

---

# Reporting errors

Wrong values வந்தால்:

```cpp id="u4l0ru"
Date(40, 15, 2026)
```

invalid date.

அப்போது:

* error throw
* validation
* checking

செய்வது எப்படி என்று காட்டுவார்கள்.

---

# §8.5 Enumerations

Limited fixed values.

---

## Example

```cpp id="rqm3cf"
enum Color {
    red,
    green,
    blue
};
```

---

Usage:

```cpp id="w0m5gw"
Color c = red;
```

---

இதன் benefit:

* readable code
* invalid values avoid

---

# Plain enumerations

Old-style enum.

Modern C++-ல்:

```cpp id="0l1f2y"
enum class Color
```

அதிக safe.

---

# §8.6 Operator overloading

C++ famous feature.

நாமே operators customize செய்யலாம்.

---

உதாரணம்:

```cpp id="n7hwnu"
a + b
```

Normally numbers.

ஆனால்:

```cpp id="t63q0t"
Date d1 + d2
```

போன்ற custom meaning கொடுக்கலாம்.

---

Example:

```cpp id="d8nk4q"
class Vector {
public:
    Vector operator+(const Vector& other);
};
```

---

இதனால் code natural-ஆக இருக்கும்.

---

# §8.7 Class interfaces

Good class design rules.

---

# Argument types

எப்படி arguments pass செய்ய வேண்டும்?

```cpp id="1d8p0u"
const string&
```

போன்ற efficient techniques.

---

# Copying

Object copy ஆனால் என்ன நடக்கும்?

```cpp id="x3xbvr"
Person p2 = p1;
```

இதன் internal behavior.

---

# Default constructors

Arguments இல்லாமல் object உருவாக்க:

```cpp id="2o5ovf"
Date d;
```

இதற்கான constructor.

---

# const member functions

Object change செய்யாத function.

```cpp id="k58pnr"
void print() const
```

இதில் object modify செய்ய முடியாது.

---

# Helper functions

Class-க்கு உதவி செய்யும் outside functions.

---

# ISO standard

Official C++ rules document.

Compiler behavior standardized.

---

# இந்த chapter-ன் real importance என்ன?

இந்த chapter முடிந்த பிறகு:

* “C++ syntax தெரியும்” level இருந்து
* “Proper C++ design” level-க்கு move ஆக ஆரம்பிப்பீர்கள்.

இதுதான்:

* OOP foundation
* library design foundation
* large-scale software foundation

ஆகும்.

இந்த chapter நல்லா புரிந்தால்:

* STL
* advanced C++
* backend systems
* game engines
* browser internals

போன்ற பெரிய codebases புரிவது மிகவும் easy ஆகும்.
