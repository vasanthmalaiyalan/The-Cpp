`Person* person = (Person*)memory  , நான் இதை பார்க்கும் போது முதலில் என்ன நினைத்தேன் என்றால் array மாதிரி நினைத்தேன் like `Person*`இந்த கிளாஸ் உள்ளே இருக்கும் 1 first variable address -சை கொண்டிருக்கும் என்று like if that first variable int so you call Person* is int*? இது தவறு தானே`

## ஆமா! அது தவறு — ஆனால் நல்ல thinking!

---

## நீங்கள் நினைத்தது:

```cpp
class Person {
    int age;      // ← Person* இந்த int-ன் address என்று நினைத்தீர்கள்
    double salary;
};

Person* p = (Person*)memory;
// நீங்கள்: "p = int* மாதிரி" என்று நினைத்தீர்கள்
```

---

## உண்மை என்னவென்றால்:

```cpp
Person* p = (Person*)memory;
// p = Person object-ன் starting address
//     உள்ளே என்ன இருக்கு என்று பார்க்காது!
```

```
Memory:
┌──────────┬──────────┬──────────┬──────────┐
│ age(4B)  │ pad(4B)  │ salary(8B)          │
└──────────┴──────────┴──────────┴──────────┘
↑
p points here → இது Person object start
                int start அல்ல!
                Person* = "இந்த முழு block-உம் Person"
```

---

## உங்கள் Confusion ஏன் வந்தது?

```cpp
Person* p;
int*    q;

// இரண்டும் same address point பண்ணலாம்:
// ஆனால் interpret வேறு!

int*    q = (int*)memory;
// q[0] → age மட்டும் படிக்கும் (4 bytes)
// q[1] → padding படிக்கும்  (4 bytes) ← wrong!

Person* p = (Person*)memory;
// p[0] → முழு Person படிக்கும் (16 bytes) ← correct!
```

---

## Key Difference:

```
int* என்றால்:
┌────┬────┬────┬────┐
│    4B   │    4B   │  ← 4 byte씩 jump
└────┴────┴────┴────┘

Person* என்றால்:
┌───────────────────┐
│      16B          │  ← 16 byte씩 jump (whole object)
└───────────────────┘
```

---

## Simple Rule:

```
Person* = "Person object-ன் address"
          ≠ "first variable-ன் address"

though technically same location,
interpretation முற்றிலும் வேறு!
```

> **One line:** `Person*` = முழு Person object-ஐ point பண்ணும் — உள்ளே first variable என்னவாக இருந்தாலும் சம்பந்தமில்லை. Type label = object type, not member type.

----------------

## Template-ஆல் T = Person எப்படி Identify ஆகும்?

---

## Call Site பார்க்கலாம்:

```cpp
Person* people = (Person*)std::malloc(sizeof(Person) * 3);

fake_delete_array(people, 3);
```

Compiler இந்த line பார்க்கும்போது:

```
fake_delete_array(people, 3)
                  ^^^^^^
                  இதன் type என்ன? → Person*
```

---

## Template Matching — Step by Step:

```cpp
template<typename T>
void fake_delete_array(T* ptr, size_t count)
//                     ^^
//                     T* என்று declare பண்ணியுள்ளோம்
```

Compiler பண்ணுவது:

```
Pass பண்ணியது  →  Person*
Template expect →  T*
─────────────────────────
Pattern match:
    T*  =  Person*
    T   =  Person       ← T கண்டுபிடிக்கப்பட்டது!
```

---

## Visual — Compiler-ன் சிந்தனை:

```
Step 1: Function call பார்க்கும்
        fake_delete_array(people, 3)

Step 2: Argument type பார்க்கும்
        people → declared as Person*

Step 3: Template parameter match பண்ணும்
        T* ←→ Person*
        ∴ T = Person

Step 4: Function instantiate பண்ணும்
        void fake_delete_array(Person* ptr, size_t count)
        {
            ptr[i].~Person();  // T = Person
        }
```

---

## Memory-ல் என்ன இருக்கு என்று பார்க்கவே மாட்டாது:

```cpp
// Compiler இதை பார்க்கும்:
Person* people = ...    // ← type label: Person*

// Compiler இதை பார்க்காது:
// memory-ல் என்ன bytes உள்ளன என்று
```

```
❌ Compiler நினைப்பது இல்லை:
   "memory-ல் என்ன இருக்கிறது? → T = அது"

✅ Compiler நினைப்பது:
   "pointer-ன் declared type என்ன? → T = அது"
```

---

## Proof — Different Types Pass பண்ணினால்:

```cpp
int*    a = ...;
double* b = ...;
Person* c = ...;

fake_delete_array(a, 3);  // T = int
fake_delete_array(b, 3);  // T = double
fake_delete_array(c, 3);  // T = Person
```

**Same function, same template — argument type மாறினால் T மாறும்.**

---

## One Line Answer:

> Compiler, `people`-ன் **declared type** `Person*` -ஐ பார்த்து, `T*` pattern-உடன் match பண்ணி, **`T = Person`** என்று compile time-லேயே decide பண்ணும். Runtime-ல் எதுவும் நடக்காது — இது pure compile-time deduction.