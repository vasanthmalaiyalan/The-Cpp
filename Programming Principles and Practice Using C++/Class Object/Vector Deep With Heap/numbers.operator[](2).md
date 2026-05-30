சூப்பரான கேள்வி. 🔥
இங்குதான் C++ operator overloading-ன் உண்மையான magic இருக்கு.

நீங்கள் confusion ஆகுற காரணம்:

```cpp
numbers[2]
```

இது array access போல தெரிகிறது.

ஆனால் `numbers` ஒரு array இல்லை.

இது:

```cpp
My_vector numbers;
```

ஒரு object.

அப்படியிருக்க:

```cpp
numbers[2]
```

எப்படி வேலை செய்கிறது?

இதைத்தான் compiler special rule மூலம் function call-ஆக மாற்றுகிறது.

---

# முதலில் இது invalid ஆக இருக்க வேண்டும்

இந்த class-ஐ பாருங்கள்:

```cpp id="p5gckd"
class Test
{
};
```

```cpp id="7ypskb"
Test t;

t[2];
```

இது compile error.

ஏனெனில்:

```text id="0jgjcv"
இந்த object-க்கு [] எப்படி வேலை செய்ய வேண்டும்?
```

என்று compiler-க்கு தெரியாது.

---

# ஆனால் நீங்கள் இந்த function-ஐ சேர்த்துவிட்டீர்கள்

```cpp id="12f87u"
int& operator[](size_t i)
{
    return *(data + i);
}
```

இதன் அர்த்தம்:

```text id="7hlls8"
"இந்த object மீது [] பயன்படுத்தினால்
இந்த function-ஐ ஓட்டு"
```

---

# Compiler special translation செய்கிறது

நீங்கள் எழுதுவது:

```cpp id="g5q62v"
numbers[2]
```

Compiler இதைப் பார்த்தவுடன்:

```text id="m6qej0"
numbers என்பது class object
அதற்குள் operator[] உள்ளது
```

என்று கண்டுபிடிக்கிறது.

பிறகு automatic rewrite:

```cpp id="0vq4wo"
numbers.operator[](2)
```

---

# இது magic syntax rule

C++ language itself rule:

```text id="xrr65q"
obj[x]
```

↓

```text id="ft7x52"
obj.operator[](x)
```

---

# Real flow

இந்த line:

```cpp id="pl3e7g"
numbers[2]
```

உண்மையில்:

```cpp id="9m9rjn"
numbers.operator[](2)
```

---

அதாவது function call:

```cpp id="y1k7p8"
operator[](2)
```

---

# Inside function

```cpp id="wyqbqb"
return *(data + i);
```

---

Suppose:

```text id="z8u9rr"
data = 1000
i = 2
```

---

Then:

```cpp id="7yk0pr"
data + i
```

↓

```text id="br4r4f"
1000 + (2 * 4)
= 1008
```

---

பிறகு:

```cpp id="0c6w0h"
*(1008)
```

↓

```text id="4ux8mz"
30
```

---

அதனால்:

```cpp id="qmp9jr"
numbers[2]
```

↓

```cpp id="1k7oc7"
numbers.operator[](2)
```

↓

```cpp id="6ngjlwm"
*(data + 2)
```

↓

```text id="rjlwmv"
30
```

---

# இதை actual function call போல எழுதலாம்

இந்த இரண்டு same:

```cpp id="kzyl2d"
numbers[2]
```

```cpp id="i0jlwm"
numbers.operator[](2)
```

---

# Example

இந்த code try பண்ணுங்கள்:

```cpp id="wvyjlwm"
#include <iostream>

class Test
{
public:

    int operator[](int x)
    {
        std::cout
            << "operator[] called\n";

        return x * 100;
    }
};

int main()
{
    Test t;

    std::cout << t[5] << '\n';
}
```

---

Output:

```text id="y1lcbt"
operator[] called
500
```

---

இங்கே actual array ஒன்றும் இல்லை.

ஆனால்:

```cpp id="5i3rqj"
t[5]
```

வேலை செய்கிறது.

ஏன்?

ஏனெனில் compiler internally:

```cpp id="7y8vpy"
t.operator[](5)
```

ஆக மாற்றிவிட்டது.

---

# இதே மாதிரி பல operators

| நீங்கள் எழுதுவது | Compiler மாற்றுவது |
| ---------------- | ------------------ |
| `a + b`          | `a.operator+(b)`   |
| `a[2]`           | `a.operator[](2)`  |
| `a()`            | `a.operator()()`   |
| `a == b`         | `a.operator==(b)`  |

---

அதனால்:

```cpp id="pzhb2u"
numbers[2]
```

இது உண்மையில் special syntax மட்டும்.

Actual execution:

```cpp id="0vc15d"
numbers.operator[](2)
```

🔥
----------------

``இதே மாதிரி பல operators
நீங்கள் எழுதுவது
Compiler மாற்றுவது
a + b
a.operator+(b)
a[2]
a.operator[](2)
a()
a.operator()()
a == b
a.operator==(b)|இப்படி உருவாக்கப்பட்டது நோக்கம் என்ன?`

இதன் பின்னால் இருக்கும் நோக்கம் C++-ன் மிகப் பெரிய design philosophy-யில் ஒன்று. 🔥

அது:

```text
"User-defined types should behave like built-in types."
```

அதாவது:

> நீங்கள் உருவாக்கும் class/object-களும்
> `int`, `double`, array போன்ற built-in types போலவே பயன்படுத்தப்பட வேண்டும்.

---

# Problem before operator overloading

நாம் ஒரு `Vector` class உருவாக்கினோம் என்று வைத்துக்கொள்ளுங்கள்.

Without operator overloading:

```cpp id="pp9k4j"
Vector a;
Vector b;

a.add(b);
```

இது வேலை செய்யும்.

ஆனால் mathematically awkward.

---

# With operator overloading

```cpp id="i7r2xg"
Vector c = a + b;
```

இப்போது:

```text
math போல தெரிகிறது
natural ஆக தெரிகிறது
readability அதிகரிக்கிறது
```

---

# Same for indexing

Without `operator[]`:

```cpp id="lty8kt"
numbers.get(2);
```

---

With operator overloading:

```cpp id="h2nzz8"
numbers[2];
```

இது array போலவே feel தருகிறது.

---

# C++ creators என்ன நினைத்தார்கள்?

C++ உருவாக்கிய Bjarne Stroustrup முக்கிய idea:

```text
High-level abstraction
+
Low-level power
```

அதாவது:

* custom types உருவாக்கு
* ஆனால் usage natural ஆக இருக்கட்டும்

---

# Real-world examples

## std::string

நாம் எழுதுவது:

```cpp id="bfk0hn"
std::string a = "Hello ";
std::string b = "World";

std::string c = a + b;
```

`+` எப்படி string-க்கு வேலை செய்கிறது?

ஏனெனில்:

```cpp id="jlwm3e"
operator+
```

overload செய்யப்பட்டிருக்கிறது.

---

# std::vector

```cpp id="d0x3wf"
vec[3]
```

↓

```cpp id="6mjlwm"
vec.operator[](3)
```

---

# Smart pointers

```cpp id="3jht0q"
ptr->name
```

↓

```cpp id="dq1sro"
ptr.operator->()
```

---

# Goal = Natural syntax

C++ சொல்லுவது:

```text
"Object-oriented code ugly ஆக இருக்கக்கூடாது."
```

அதனால்:

```cpp id="s6v0go"
matrix.multiply(other_matrix)
```

பதிலாக:

```cpp id="x0jlwm"
matrix * other_matrix
```

எழுத அனுமதி.

---

# Why compiler rewrite செய்கிறது?

ஏனெனில் CPU-க்கு:

```cpp id="0pwjlwm"
a + b
```

என்ற syntax புரியாது.

Compiler translate செய்ய வேண்டும்.

Built-in types என்றால்:

```cpp id="lsjlwm"
int + int
```

direct machine instruction.

ஆனால் custom object என்றால்:

```cpp id="6hjlwm"
Vector + Vector
```

எப்படி add செய்வது?

அதை programmer define செய்கிறார்:

```cpp id="njlwm4"
operator+
```

மூலம்.

---

# Example

```cpp id="3gtjlwm"
class Number
{
public:

    int value;

    Number(int v)
    {
        value = v;
    }

    Number operator+(const Number& other)
    {
        return Number(value + other.value);
    }
};
```

---

Now:

```cpp id="jlwm12"
Number a(10);
Number b(20);

Number c = a + b;
```

Compiler internally:

```cpp id="jlwm55"
Number c = a.operator+(b);
```

---

# Important philosophy

C++ tries to blur the line between:

```text
built-in types
and
user-defined types
```

அதனால்:

```cpp id="jlwm90"
vec[2]
str1 + str2
smart_ptr->x
```

எல்லாமே natural syntax போல தெரிகிறது.

---

# Another deeper reason

C language already had operators:

```cpp id="jlwm44"
+
-
[]
*
==
```

C++ creators நினைத்தார்கள்:

```text
"இந்த syntax already programmers-க்கு familiar.
அதை custom types-க்கும் reuse பண்ணலாம்."
```

இதனால் learning easier.

---

# ஆனால் danger-மும் இருக்கு

Overloading தவறாக பயன்படுத்தினால் confusing code வரும்.

உதாரணம்:

```cpp id="0njlwm"
obj + obj
```

உண்மையில் addition செய்யாமல்:

```text
delete file
```

செய்தால் horrible design.

அதனால் operator overloading powerful ஆனாலும் carefully பயன்படுத்த வேண்டும்.

---

# Final essence

Operator overloading purpose:

* custom types natural ஆக பயன்படுத்த
* mathematical syntax support செய்ய
* readability improve செய்ய
* built-in types போல behavior கொடுக்க
* abstraction powerful ஆக்க

அதனால்:

```cpp id="jlwmzz"
numbers[2]
```

போன்ற syntax possible ஆனது.
---------------

``இதே மாதிரி பல operators
நீங்கள் எழுதுவது
Compiler மாற்றுவது
a + b
a.operator+(b)
a[2]
a.operator[](2)
a()
a.operator()()
a == b
a.operator==(b)`இதை உள்ளே vector internal-லில் பயன்படுத்தப்பட்டுள்ளதா? `


ஆம்! 🔥
`std::vector` internal implementation-ல் இவை உண்மையாகவே பயன்படுத்தப்படுகின்றன.

நீங்கள் எழுதுவது:

```cpp id="m6l7dq"
std::vector<int> vec;

vec[2];
```

ஆனால் vector class உள்ளே actual-ஆக இருக்கும் function:

```cpp id="c8i94j"
reference operator[](size_type pos);
```

---

# Actual std::vector internal idea

Simplified version:

```cpp id="ol8i7w"
template<typename T>
class vector
{
private:

    T* data;

public:

    T& operator[](size_t i)
    {
        return *(data + i);
    }
};
```

---

அதனால்:

```cpp id="43vwwj"
vec[2]
```

↓

compiler converts:

```cpp id="3m9mzw"
vec.operator[](2)
```

↓

inside:

```cpp id="xjuxqn"
return *(data + 2);
```

↓

pointer arithmetic.

---

# std::vector actual implementation concept

உள்ளே roughly:

```cpp id="9e89k7"
class vector
{
    T* start;
    T* finish;
    T* end_of_storage;
};
```

---

Memory:

```text id="ry6uv8"
start -----------> heap array
finish -----------> last used element
end_of_storage ---> capacity end
```

---

# operator[] actual logic

Simplified:

```cpp id="qq5qjw"
T& operator[](size_t n)
{
    return start[n];
}
```

ஆனால்:

```cpp id="bnjjlwm"
start[n]
```

இதுவும் internally:

```cpp id="jlwm123"
*(start + n)
```

🔥

---

# அதனால் chain இப்படிச் செல்கிறது

```cpp id="6jlwmx"
vec[2]
```

↓

```cpp id="jlwmab"
vec.operator[](2)
```

↓

```cpp id="jlwmcd"
start[2]
```

↓

```cpp id="jlwmef"
*(start + 2)
```

↓

real memory access.

---

# std::string-லும் same

```cpp id="jlwmgh"
str[1]
```

↓

```cpp id="jlwmij"
str.operator[](1)
```

---

# smart pointer-லும்

```cpp id="jlwmkl"
ptr->x
```

↓

```cpp id="jlwmmn"
ptr.operator->()->x
```

---

# function object

```cpp id="jlwmop"
obj()
```

↓

```cpp id="jlwmqr"
obj.operator()()
```

இதைத்தான்:

* lambda
* functor
* comparator objects

உள்ளே use செய்கின்றன.

---

# Example — sort comparator

```cpp id="jlwmst"
class Compare
{
public:

    bool operator()(int a, int b)
    {
        return a < b;
    }
};
```

---

Now:

```cpp id="jlwmuv"
Compare comp;

comp(10,20);
```

↓

compiler:

```cpp id="jlwmwx"
comp.operator()(10,20);
```

🔥

இதைத்தான் STL algorithms heavily use செய்கின்றன.

---

# std::vector internal-ல் heavily used operators

| Operator     | Usage               |
| ------------ | ------------------- |
| `operator[]` | indexing            |
| `operator=`  | copy assignment     |
| `operator==` | comparison          |
| `operator!=` | comparison          |
| `operator*`  | iterators           |
| `operator++` | iterators           |
| `operator->` | iterators/smart ptr |
| `operator+`  | iterator arithmetic |

---

# Example iterator

```cpp id="jlwmyz"
auto it = vec.begin();

++it;
```

இதுவும் actual:

```cpp id="jlwm01"
it.operator++();
```

---

```cpp id="jlwm23"
*it
```

↓

```cpp id="jlwm45"
it.operator*();
```

🔥 STL முழுக்க operator overloading மீது கட்டப்பட்டுள்ளது.

---

# மிகவும் deep truth

C++ STL containers:

* vector
* string
* iterator
* smart pointers
* algorithms

இவை எல்லாம்:

```text id="a30gm4"
operator overloading
+
templates
+
pointer arithmetic
```

இந்த 3 pillars மேல் நிற்கின்றன.

---

# அதனால் நீங்கள் இப்போது பார்க்கும்:

```cpp id="jlwm67"
vec[2]
```

இது simple syntax போல தோன்றினாலும் உள்ளே:

* function call
* pointer arithmetic
* reference return
* heap memory access

எல்லாம் நடக்கிறது. 🔥

-----------------

``இதே மாதிரி பல operators
நீங்கள் எழுதுவது
Compiler மாற்றுவது
a + b
a.operator+(b)
a[2]
a.operator[](2)
a()
a.operator()()
a == b
a.operator==(b)|இப்படி உருவாக்கப்பட்டது நோக்கம் என்ன?`

இதன் பின்னால் இருக்கும் நோக்கம் C++-ன் மிகப் பெரிய design philosophy-யில் ஒன்று. 🔥

அது:

```text
"User-defined types should behave like built-in types."
```

அதாவது:

> நீங்கள் உருவாக்கும் class/object-களும்
> `int`, `double`, array போன்ற built-in types போலவே பயன்படுத்தப்பட வேண்டும்.

---

# Problem before operator overloading

நாம் ஒரு `Vector` class உருவாக்கினோம் என்று வைத்துக்கொள்ளுங்கள்.

Without operator overloading:

```cpp id="pp9k4j"
Vector a;
Vector b;

a.add(b);
```

இது வேலை செய்யும்.

ஆனால் mathematically awkward.

---

# With operator overloading

```cpp id="i7r2xg"
Vector c = a + b;
```

இப்போது:

```text
math போல தெரிகிறது
natural ஆக தெரிகிறது
readability அதிகரிக்கிறது
```

---

# Same for indexing

Without `operator[]`:

```cpp id="lty8kt"
numbers.get(2);
```

---

With operator overloading:

```cpp id="h2nzz8"
numbers[2];
```

இது array போலவே feel தருகிறது.

---

# C++ creators என்ன நினைத்தார்கள்?

C++ உருவாக்கிய Bjarne Stroustrup முக்கிய idea:

```text
High-level abstraction
+
Low-level power
```

அதாவது:

* custom types உருவாக்கு
* ஆனால் usage natural ஆக இருக்கட்டும்

---

# Real-world examples

## std::string

நாம் எழுதுவது:

```cpp id="bfk0hn"
std::string a = "Hello ";
std::string b = "World";

std::string c = a + b;
```

`+` எப்படி string-க்கு வேலை செய்கிறது?

ஏனெனில்:

```cpp id="jlwm3e"
operator+
```

overload செய்யப்பட்டிருக்கிறது.

---

# std::vector

```cpp id="d0x3wf"
vec[3]
```

↓

```cpp id="6mjlwm"
vec.operator[](3)
```

---

# Smart pointers

```cpp id="3jht0q"
ptr->name
```

↓

```cpp id="dq1sro"
ptr.operator->()
```

---

# Goal = Natural syntax

C++ சொல்லுவது:

```text
"Object-oriented code ugly ஆக இருக்கக்கூடாது."
```

அதனால்:

```cpp id="s6v0go"
matrix.multiply(other_matrix)
```

பதிலாக:

```cpp id="x0jlwm"
matrix * other_matrix
```

எழுத அனுமதி.

---

# Why compiler rewrite செய்கிறது?

ஏனெனில் CPU-க்கு:

```cpp id="0pwjlwm"
a + b
```

என்ற syntax புரியாது.

Compiler translate செய்ய வேண்டும்.

Built-in types என்றால்:

```cpp id="lsjlwm"
int + int
```

direct machine instruction.

ஆனால் custom object என்றால்:

```cpp id="6hjlwm"
Vector + Vector
```

எப்படி add செய்வது?

அதை programmer define செய்கிறார்:

```cpp id="njlwm4"
operator+
```

மூலம்.

---

# Example

```cpp id="3gtjlwm"
class Number
{
public:

    int value;

    Number(int v)
    {
        value = v;
    }

    Number operator+(const Number& other)
    {
        return Number(value + other.value);
    }
};
```

---

Now:

```cpp id="jlwm12"
Number a(10);
Number b(20);

Number c = a + b;
```

Compiler internally:

```cpp id="jlwm55"
Number c = a.operator+(b);
```

---

# Important philosophy

C++ tries to blur the line between:

```text
built-in types
and
user-defined types
```

அதனால்:

```cpp id="jlwm90"
vec[2]
str1 + str2
smart_ptr->x
```

எல்லாமே natural syntax போல தெரிகிறது.

---

# Another deeper reason

C language already had operators:

```cpp id="jlwm44"
+
-
[]
*
==
```

C++ creators நினைத்தார்கள்:

```text
"இந்த syntax already programmers-க்கு familiar.
அதை custom types-க்கும் reuse பண்ணலாம்."
```

இதனால் learning easier.

---

# ஆனால் danger-மும் இருக்கு

Overloading தவறாக பயன்படுத்தினால் confusing code வரும்.

உதாரணம்:

```cpp id="0njlwm"
obj + obj
```

உண்மையில் addition செய்யாமல்:

```text
delete file
```

செய்தால் horrible design.

அதனால் operator overloading powerful ஆனாலும் carefully பயன்படுத்த வேண்டும்.

---

# Final essence

Operator overloading purpose:

* custom types natural ஆக பயன்படுத்த
* mathematical syntax support செய்ய
* readability improve செய்ய
* built-in types போல behavior கொடுக்க
* abstraction powerful ஆக்க

அதனால்:

```cpp id="jlwmzz"
numbers[2]
```

போன்ற syntax possible ஆனது.
-----------------

``இதே மாதிரி பல operators
நீங்கள் எழுதுவது
Compiler மாற்றுவது
a + b
a.operator+(b)
a[2]
a.operator[](2)
a()
a.operator()()
a == b
a.operator==(b)`இதை உள்ளே vector internal-லில் பயன்படுத்தப்பட்டுள்ளதா? `


ஆம்! 🔥
`std::vector` internal implementation-ல் இவை உண்மையாகவே பயன்படுத்தப்படுகின்றன.

நீங்கள் எழுதுவது:

```cpp id="m6l7dq"
std::vector<int> vec;

vec[2];
```

ஆனால் vector class உள்ளே actual-ஆக இருக்கும் function:

```cpp id="c8i94j"
reference operator[](size_type pos);
```

---

# Actual std::vector internal idea

Simplified version:

```cpp id="ol8i7w"
template<typename T>
class vector
{
private:

    T* data;

public:

    T& operator[](size_t i)
    {
        return *(data + i);
    }
};
```

---

அதனால்:

```cpp id="43vwwj"
vec[2]
```

↓

compiler converts:

```cpp id="3m9mzw"
vec.operator[](2)
```

↓

inside:

```cpp id="xjuxqn"
return *(data + 2);
```

↓

pointer arithmetic.

---

# std::vector actual implementation concept

உள்ளே roughly:

```cpp id="9e89k7"
class vector
{
    T* start;
    T* finish;
    T* end_of_storage;
};
```

---

Memory:

```text id="ry6uv8"
start -----------> heap array
finish -----------> last used element
end_of_storage ---> capacity end
```

---

# operator[] actual logic

Simplified:

```cpp id="qq5qjw"
T& operator[](size_t n)
{
    return start[n];
}
```

ஆனால்:

```cpp id="bnjjlwm"
start[n]
```

இதுவும் internally:

```cpp id="jlwm123"
*(start + n)
```

🔥

---

# அதனால் chain இப்படிச் செல்கிறது

```cpp id="6jlwmx"
vec[2]
```

↓

```cpp id="jlwmab"
vec.operator[](2)
```

↓

```cpp id="jlwmcd"
start[2]
```

↓

```cpp id="jlwmef"
*(start + 2)
```

↓

real memory access.

---

# std::string-லும் same

```cpp id="jlwmgh"
str[1]
```

↓

```cpp id="jlwmij"
str.operator[](1)
```

---

# smart pointer-லும்

```cpp id="jlwmkl"
ptr->x
```

↓

```cpp id="jlwmmn"
ptr.operator->()->x
```

---

# function object

```cpp id="jlwmop"
obj()
```

↓

```cpp id="jlwmqr"
obj.operator()()
```

இதைத்தான்:

* lambda
* functor
* comparator objects

உள்ளே use செய்கின்றன.

---

# Example — sort comparator

```cpp id="jlwmst"
class Compare
{
public:

    bool operator()(int a, int b)
    {
        return a < b;
    }
};
```

---

Now:

```cpp id="jlwmuv"
Compare comp;

comp(10,20);
```

↓

compiler:

```cpp id="jlwmwx"
comp.operator()(10,20);
```

🔥

இதைத்தான் STL algorithms heavily use செய்கின்றன.

---

# std::vector internal-ல் heavily used operators

| Operator     | Usage               |
| ------------ | ------------------- |
| `operator[]` | indexing            |
| `operator=`  | copy assignment     |
| `operator==` | comparison          |
| `operator!=` | comparison          |
| `operator*`  | iterators           |
| `operator++` | iterators           |
| `operator->` | iterators/smart ptr |
| `operator+`  | iterator arithmetic |

---

# Example iterator

```cpp id="jlwmyz"
auto it = vec.begin();

++it;
```

இதுவும் actual:

```cpp id="jlwm01"
it.operator++();
```

---

```cpp id="jlwm23"
*it
```

↓

```cpp id="jlwm45"
it.operator*();
```

🔥 STL முழுக்க operator overloading மீது கட்டப்பட்டுள்ளது.

---

# மிகவும் deep truth

C++ STL containers:

* vector
* string
* iterator
* smart pointers
* algorithms

இவை எல்லாம்:

```text id="a30gm4"
operator overloading
+
templates
+
pointer arithmetic
```

இந்த 3 pillars மேல் நிற்கின்றன.

---

# அதனால் நீங்கள் இப்போது பார்க்கும்:

```cpp id="jlwm67"
vec[2]
```

இது simple syntax போல தோன்றினாலும் உள்ளே:

* function call
* pointer arithmetic
* reference return
* heap memory access

எல்லாம் நடக்கிறது. 🔥
