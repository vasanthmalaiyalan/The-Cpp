ஆம். நீங்கள் இப்போது **OOP syntax கற்கவில்லை**, **compiler class-ஐ எப்படி புரிந்துகொள்கிறது** என்பதை கற்க விரும்புகிறீர்கள்.

அதற்கு இந்த `.cpp` code சரியான example.

---

## Step 1: நாம் எழுதிய Original C++ Code

```cpp
#include <iostream>

class Person
{
public:
    int age;
    int height;

    void set_age(int a)
    {
        age = a;
    }

    void print()
    {
        std::cout << age << ' ' << height << '\n';
    }
};

int main()
{
    Person p;

    p.age = 20;
    p.height = 170;

    p.set_age(25);

    p.print();
}
```

---

# Compiler முதலில் என்ன பார்க்கும்?

Compiler parse செய்த பிறகு:

```cpp
class Person
{
public:
    int age;
    int height;

    void set_age(int a);
    void print();
};
```

---

Compiler symbol table-ல் roughly:

```text
Class: Person

Members:
--------------------------------
age      -> int
height   -> int

Functions:
--------------------------------
set_age(int)
print()
```

---

# Compiler Object Layout உருவாக்கும்

`Person` object memory எப்படி இருக்கும்?

```cpp
class Person
{
public:
    int age;
    int height;
};
```

Compiler:

```text
Person Layout

offset 0  -> age
offset 4  -> height

size = 8 bytes
```

---

அதாவது:

```cpp
Person p;
```

என்றால்:

```text
address 1000 -> age
address 1004 -> height
```

---

# Compiler Hidden this சேர்க்கும்

நாம்:

```cpp
void set_age(int a)
{
    age = a;
}
```

எழுதியுள்ளோம்.

Compiler internal representation:

```cpp
void Person::set_age(Person* this, int a)
{
    this->age = a;
}
```

போல வைத்துக்கொள்கிறது.

---

அதேபோல்:

```cpp
void print()
{
    std::cout << age << ' ' << height;
}
```

compiler:

```cpp
void Person::print(Person* this)
{
    std::cout
        << this->age
        << ' '
        << this->height;
}
```

---

# main() Analysis

நாம்:

```cpp
Person p;
```

எழுதினோம்.

Compiler:

```text
stack allocate 8 bytes
```

---

Memory:

```text
p

1000 -> age
1004 -> height
```

---

பிறகு:

```cpp
p.age = 20;
```

Compiler:

```text
write 20 at offset 0
```

---

Memory:

```text
1000 -> 20
1004 -> ?
```

---

பிறகு:

```cpp
p.height = 170;
```

Memory:

```text
1000 -> 20
1004 -> 170
```

---

# Member Function Call

நாம்:

```cpp
p.set_age(25);
```

எழுதினோம்.

Compiler பார்க்கும் போது:

```text
object = p
function = Person::set_age
```

---

அதனால்:

```cpp
Person::set_age(&p, 25);
```

என்ற internal call information உருவாகும்.

---

Function உள்ளே:

```cpp
this = &p
```

---

Suppose:

```text
&p = 1000
```

---

Function:

```cpp
this->age = a;
```

becomes:

```text
*(1000 + 0) = 25
```

ஏனெனில்:

```text
age offset = 0
```

---

Memory:

```text
1000 -> 25
1004 -> 170
```

---

# Next Function Call

நாம்:

```cpp
p.print();
```

எழுதினோம்.

Compiler:

```cpp
Person::print(&p);
```

போல handle செய்கிறது.

---

Inside:

```cpp
this = 1000
```

---

Compiler knows:

```text
age    offset = 0
height offset = 4
```

---

So:

```cpp
this->age
```

means:

```text
*(1000 + 0)
```

Result:

```text
25
```

---

And:

```cpp
this->height
```

means:

```text
*(1000 + 4)
```

Result:

```text
170
```

---

Output:

```text
25 170
```

---

# Compiler பார்வையில் Final Equivalent

இந்த முழு class-ஐ compiler mental model-ஆக நினைத்தால்:

```cpp
#include <iostream>

struct Person
{
    int age;
    int height;
};

void Person_set_age(Person* this_ptr, int a)
{
    this_ptr->age = a;
}

void Person_print(Person* this_ptr)
{
    std::cout
        << this_ptr->age
        << ' '
        << this_ptr->height
        << '\n';
}

int main()
{
    Person p;

    p.age = 20;
    p.height = 170;

    Person_set_age(&p, 25);

    Person_print(&p);
}
```

---

இது **C++ standard சொல்வது அல்ல**, ஆனால் **non-virtual member functions, data members, `this` pointer, member access** ஆகியவற்றை compiler எப்படி resolve செய்கிறது என்பதைப் புரிந்துகொள்ள மிகவும் அருகிலான compiler-level model.

இதற்கு அடுத்த level-ல் நீங்கள் புரிந்துகொள்ள வேண்டியது:

1. Constructor compiler-ல் எப்படி represent ஆகிறது?
2. `private` compile-time-ல் மட்டும் எப்படி enforce ஆகிறது?
3. Virtual function வந்தால் `vptr` மற்றும் `vtable` எப்படி சேர்க்கப்படுகிறது?
4. Inheritance வந்தால் object layout எப்படி மாறுகிறது?

இந்த நான்கும் class internals-ன் அடுத்த முக்கிய படிகள்.
