`data_ptr = new int[4];, இதில் நாம் மெமரி எந்த டேட்டா டைப்பில் allocate ஆக வேண்டும் என்று சொல்லனுமா? `int`? எவ்வளவு சைஸில் ஆக வேண்டும் என்பதையும் சொல்லனுமா?`

ஆம்! 🔥
`new int[4]`-ல் நீங்கள் compiler-க்கு இரண்டு விஷயங்களை சொல்கிறீர்கள்:

---

# 1. எந்த type memory வேண்டும்?

```cpp id="y7k8l1"
int
```

---

# 2. எத்தனை elements வேண்டும்?

```cpp id="f3m2n9"
4
```

---

அதனால்:

```cpp id="p8v4q6"
new int[4]
```

அர்த்தம்:

```text id="t1z5x7"
"Heap-ல் 4 integers வைக்கத் தகுந்த
continuous memory allocate செய்"
```

---

# Internal calculation

Compiler already knows:

```cpp id="c6r8u2"
sizeof(int)
```

usually:

```text id="j9w3e4"
4 bytes
```

---

அதனால்:

```cpp id="m2k7d5"
new int[4]
```

↓

internal required bytes:

```text id="v4n8p1"
4 * sizeof(int)
```

↓

```text id="z6q1r3"
4 * 4
```

↓

```text id="b7x2c9"
16 bytes
```

🔥

---

# Heap allocation visualization

```cpp id="d5m1s8"
int* ptr = new int[4];
```

Suppose heap address:

```text id="r2y9k4"
1000
```

returned.

---

Memory:

```text id="u8e3w6"
1000 -> int
1004 -> int
1008 -> int
1012 -> int
```

---

# Pointer stores only first address

```cpp id="q4h7v2"
ptr = 1000
```

---

# Pointer arithmetic later handles rest

```cpp id="n6j1b5"
ptr[2]
```

↓

```cpp id="a3c8f7"
*(ptr + 2)
```

↓

```text id="l5p2x9"
1000 + (2 * sizeof(int))
```

↓

```text id="g7r4m1"
1008
```

🔥

---

# Important

நீங்கள் bytes directly சொல்லவில்லை.

நீங்கள்:

```cpp id="k1u6z3"
int
```

மற்றும்

```cpp id="w9n5e8"
4
```

மட்டும் சொல்கிறீர்கள்.

Compiler தான் internally:

```cpp id="h2d7q4"
4 * sizeof(int)
```

calculate செய்கிறது.

---

# Another example

```cpp id="x5m8r1"
new double[4]
```

Suppose:

```cpp id="t7p3v9"
sizeof(double) == 8
```

---

Internal allocation:

```text id="e4k1c6"
4 * 8
= 32 bytes
```

---

# Another example

```cpp id="o9j2l5"
new char[100]
```

`char` size:

```cpp id="u3y7n1"
1 byte
```

---

Internal:

```text id="m6r4x8"
100 * 1
= 100 bytes
```

---

# Template version

உங்கள் vector code-ல்:

```cpp id="v1b5k9"
new T[current_capacity]
```

Suppose:

```cpp id="r8c2m4"
T = int
```

Compiler sees:

```cpp id="n7x1p6"
new int[current_capacity]
```

---

Suppose:

```cpp id="c5q9z2"
T = double
```

Compiler sees:

```cpp id="s4m8r7"
new double[current_capacity]
```

🔥

---

# Why type is important?

ஏனெனில் compiler தெரிந்துகொள்ள வேண்டும்:

* element size
* alignment
* constructor call
* destructor call
* pointer arithmetic

---

# Example with class

```cpp id="d8v3k1"
class Person
{
};
```

---

```cpp id="q2m7x5"
new Person[3]
```

means:

```text id="n9r4c6"
3 Person objects allocate செய்
constructors call செய்
```

---

# Important deep truth

```cpp id="b6p1z8"
new int[4]
```

இது raw bytes மட்டும் allocate செய்யாது.

அது:

```text id="k4x7m2"
typed memory allocation
```

🔥

அதாவது:

* int memory
* int alignment
* int arithmetic
* int semantics

எல்லாம் attach ஆகும்.

---

# Final essence

```cpp id="t3v8r1"
new int[4]
```

means:

```text id="m7q2x9"
Heap-ல்
4 integers continuous-ஆ
வைக்கத் தகுந்த memory allocate செய்
```

Compiler internally:

```cpp id="p5k1n4"
4 * sizeof(int)
```

bytes allocate செய்கிறது.
