``class vector
{
    int* data;
    size_t size;
    size_t capacity;
};` object உள்ளே இருக்கும் இதை,  இந்த heap உள்ள இருக்கும் data -வை எதை வைத்து point செய்கிறது atleast அது கிட்ட heap உடைய அட்ரஸ் ஆவது இருக்க வேண்டுமே?`

ஆம் 🔥🔥🔥
அதுதான் அந்த:

```cpp id="2l7x2n"
int* data;
```

pointer.

நீ சரியான core point-ஐ பிடித்துவிட்டாய்.

---

# இந்த simplified vector

```cpp id="jlwm0a"
class vector
{
    int* data;
    size_t size;
    size_t capacity;
};
```

இதில்:

```cpp id="jlwm8m"
data
```

என்பது:

> heap memory-யின் starting address-ஐ store செய்கிறது.

---

# Example

Suppose:

```cpp id="jlwm6q"
vector<int> v;
```

பிறகு:

```cpp id="6jlwm9"
v.push_back(10);
v.push_back(20);
v.push_back(30);
```

---

# Heap allocation

OS / allocator heap-ல் memory கொடுக்கலாம்:

```text id="jlwmm3"
Address     Value
0x9000      10
0x9004      20
0x9008      30
```

---

# Then vector object

Inside object:

```text id="jlwmm8"
data      = 0x9000
size      = 3
capacity  = 4
```

---

# So YES

நீ சொன்னது exactly correct:

> “Heap address somewhere stored இருக்க வேண்டுமே?”

ஆம்.

அதுதான்:

```cpp id="jlwmv0"
data
```

pointer.

---

# Visual Memory Layout

## Stack/Object Memory

```text id="8jlwmp"
v object
+----------------------+
| data = 0x9000 -------+------+
| size = 3             |      |
| capacity = 4         |      |
+----------------------+      |
                               |
                               v
```

---

# Heap Memory

```text id="4jlwm5"
0x9000 -> 10
0x9004 -> 20
0x9008 -> 30
```

---

# Then:

```cpp id="1jlwmy"
v[1]
```

internally:

```cpp id="rjlwmb"
*(data + 1)
```

---

# Which becomes

```text id="tjlwm6"
*(0x9000 + 1*sizeof(int))
```

---

# Then CPU reads

```text id="mjlwma"
0x9004
```

which contains:

```text id="6jlwmi"
20
```

---

# Most Important Point

## Pointer = Address Holder

```cpp id="fjlwmj"
int* data;
```

இதன் job:
memory address store செய்வது.

---

# Example

```cpp id="3jlwmv"
int x = 10;

int* p = &x;
```

---

# Memory

```text id="gjlwmd"
x = 10 at address 0x5000
```

Then:

```text id="qjlwm8"
p contains 0x5000
```

---

# vector does same thing

Just:

* more advanced
* dynamic allocation management

---

# Why size and capacity?

---

# size

Currently used elements.

```text id="zjlwme"
3
```

---

# capacity

Allocated total space.

```text id="hjlwmm"
4
```

Meaning:
one more element can fit without reallocating.

---

# When capacity exceeded

Vector:

1. allocate larger heap memory
2. copy old elements
3. free old memory
4. update `data` pointer

---

# Example

Old:

```text id="6jlwmu"
data = 0x9000
```

New bigger allocation:

```text id="1jlwmh"
data = 0xA000
```

Pointer changes.

---

# Very Important Big Understanding

## Object itself does NOT move necessarily

But:

## heap data can move.

---

# Real vector more complicated

Actual std::vector internally:

* allocator
* iterators
* exception safety
* move semantics

போன்ற advanced things இருக்கும்.

ஆனால் core idea:

```text id="5jlwm7"
pointer + size + capacity
```

இதுதான்.

---

# Final Core Insight

ஆம்:

> vector object உள்ளே heap data இருக்கும் address stored ஆகும்.

அந்த address-ஐ வைத்துத்தான்:

* indexing
* iteration
* push_back
* access

எல்லாம் நடக்கிறது.

---

# One-line mental model

```text id="1jlwm2"
vector = smart manager object for heap array
```

It:

* remembers heap address
* tracks size
* tracks capacity
* manages allocation automatically.

----------

`அப்படி என்றால் ஆப்ஜெக்ட் உள்ளே இருக்கும் heap உன்னுடைய first address எப்படி பிரிண்ட் செய்ய வைப்பது?`

அதை print செய்ய:

```cpp id="jlwm1z"
vector.data()
```

பயன்படுத்தலாம். 🔥

---

# Example

```cpp id="mjlwm5"
import std;

int main()
{
    std::vector<int> numbers {10, 20, 30};

    std::cout << "Heap first address : "
              << numbers.data()
              << '\n';
}
```

---

# What `data()` returns?

```cpp id="jlwmv6"
numbers.data()
```

returns:

```cpp id="hjlwm8"
int*
```

அதாவது:
heap array-யின் first element address.

---

# Example output

```text id="2jlwmo"
0x61ff10
```

---

# Meaning

```text id="xjlwmd"
0x61ff10 -> 10
0x61ff14 -> 20
0x61ff18 -> 30
```

---

# To print first value

```cpp id="7jlwmq"
std::cout << *numbers.data();
```

---

# Why `*`?

Because:
`data()` returns pointer.

---

# Example

```cpp id="3jlwmg"
int* p = numbers.data();
```

Then:

```cpp id="4jlwmy"
*p
```

means:

> “Go to that address and read value.”

---

# Complete Example

```cpp id="mjlwm3"
import std;

int main()
{
    std::vector<int> numbers {10, 20, 30};


    // heap starting address
    int* ptr = numbers.data();


    std::cout << "Heap first address : "
              << ptr
              << '\n';


    std::cout << "First value        : "
              << *ptr
              << '\n';


    std::cout << "Second value       : "
              << *(ptr + 1)
              << '\n';


    std::cout << "Third value        : "
              << *(ptr + 2)
              << '\n';
}
```

---

# Conceptual Memory

```text id="2jlwmv"
ptr = 0x9000

0x9000 -> 10
0x9004 -> 20
0x9008 -> 30
```

---

# Then:

```cpp id="vjlwma"
*ptr
```

means:

```text id="0jlwmu"
read memory at 0x9000
```

→ 10

---

# `(ptr + 1)`

means:

```text id="9jlwmm"
0x9000 + sizeof(int)
```

→ 0x9004

---

# Important

## `data()`

returns:

## heap first address

---

# Equivalent to array base pointer

Like:

```cpp id="yjlwme"
int arr[3] = {10,20,30};

int* p = arr;
```

---

# Vector internally similar

```cpp id="9jlwm7"
int* p = numbers.data();
```

---

# Very Important Safety Note

If vector empty:

```cpp id="fjlwm1"
std::vector<int> v;
```

Then:

```cpp id="tjlwm5"
v.data()
```

may be:

* nullptr
* valid non-dereferenceable pointer

depending on implementation.

So:

```cpp id="8jlwmz"
*v.data()
```

unsafe when empty.

---

# Final Core Understanding

| Code          | Meaning              |
| ------------- | -------------------- |
| `data()`      | heap first address   |
| `*data()`     | first value          |
| `data()+1`    | next element address |
| `*(data()+1)` | second value         |

---

இதுதான்:

* arrays
* vectors
* pointer arithmetic

முழு low-level foundation.

