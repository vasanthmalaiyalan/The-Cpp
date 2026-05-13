ஆம் 🔥🔥🔥
நீ இப்போது actual OOP + STL internal architecture-ஐ சரியாக connect செய்துவிட்டாய்.

உன் statement almost completely correct.

---

# Example

```cpp id="yjlwm1"
class My_class
{
    std::vector<int> numbers;
};
```

---

# Then:

```cpp id="7jlwmy"
My_class obj;
```

இதன் meaning:

> `obj` object உள்ளே
> `numbers` என்ற இன்னொரு object இருக்கும்.

---

# Very Important

## `numbers`

ஒரு variable மட்டும் இல்லை.

Itself:

## full-fledged object.

---

# Because

```cpp id="4jlwma"
std::vector<int>
```

ஒரு class type.

---

# Internally

Conceptually:

```cpp id="qjlwmd"
class vector
{
    int* data;
    size_t size;
    size_t capacity;
};
```

---

# Therefore

`obj` memory layout:

```text id="0jlwmm"
obj
+--------------------------------+
| vector object (numbers)        |
|--------------------------------|
| data pointer ----------------+ |
| size                         | |
| capacity                     | |
+--------------------------------+
                                 |
                                 v
```

---

# Heap memory

```text id="yjlwmu"
10
20
30
```

---

# So YES

> “object inside object”

Exactly correct.

---

# Important OOP Concept

## Composition

This is called:

# Object Composition

---

# Meaning

ஒரு object:
மற்ற object-களை member-ஆக வைத்திருக்கும்.

---

# Example

```cpp id="9jlwmp"
class Engine
{
};

class Car
{
    Engine engine;
};
```

---

# Meaning

```text id="zjlwme"
Car HAS-A Engine
```

---

# Similarly

```cpp id="6jlwmg"
class My_class
{
    vector<int> numbers;
};
```

means:

```text id="mjlwmy"
My_class HAS-A vector
```

---

# Now VERY IMPORTANT

## Why heap used?

Because:
vector size compile-time-ல் தெரியாது.

---

# Example

```cpp id="8jlwma"
numbers.push_back(...)
```

runtime-ல் grow ஆகும்.

---

# Problem

Object size fixed.

Compiler compile-time-ல் object size தெரிந்திருக்க வேண்டும்.

---

# Impossible:

```cpp id="qjlwmd"
class Bad
{
    ??? unknown number of ints
};
```

---

# Solution

Inside object:
store only:

```text id="tjlwmm"
pointer
size
capacity
```

---

# Actual dynamic data

store in:

```text id="5jlwmp"
heap
```

---

# Therefore

## vector object itself

inside parent object.

BUT

## vector elements

heap.

---

# Most Important Big Understanding

---

# `obj`

contains:

```text id="1jlwme"
vector manager object
```

---

# vector manager object contains:

```text id="mjlwmg"
pointer to heap
```

---

# heap contains:

```text id="7jlwmy"
actual integers
```

---

# Visual Full Chain

```text id="4jlwma"
obj
 |
 +---- vector object
         |
         +---- data pointer
                 |
                 +---- heap array
```

---

# This is everywhere in modern C++

Almost all STL containers work like this:

| Container     | Uses heap? |
| ------------- | ---------- |
| vector        | YES        |
| string        | usually    |
| map           | YES        |
| unordered_map | YES        |
| deque         | YES        |
| list          | YES        |

---

# Therefore modern OOP objects often become

```text id="qjlwmd"
object
   ↓
contains objects
   ↓
those objects manage heap memory
```

---

# Real Software Engineering Truth

Modern large systems:

* browsers
* game engines
* databases
* operating systems

எல்லாமே:

```text id="0jlwmm"
composition + heap-managed containers
```

மேல்தான் build ஆகின்றன.

---

# Final Most Important Understanding

ஆம்:

> ஒரு class-ல் vector member இருந்தால்,
> அந்த class object உள்ளே vector object இருக்கும்.

அந்த vector object:

* heap pointer
* size
* capacity

வைத்திருக்கும்.

Actual dynamic data:
heap-ல் இருக்கும்.

இதுதான்:

# Object Composition + Dynamic Memory Management

என்ற modern C++ core architecture.
