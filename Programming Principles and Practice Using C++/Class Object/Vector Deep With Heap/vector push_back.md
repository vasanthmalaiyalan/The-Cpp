`ஆனால் vector -க்கு எப்ப வேணாலும் push back செய்வோம் என்பதால் அதை எப்படி எடுத்துக் கொள்ளும்`

அதுதான் vector-ன் மிக முக்கியமான magic. 🔥
`std::vector` ஆரம்பத்தில் எல்லா memory-யும் allocate செய்யாது.

அது:

```text id="gw4t9m"
"தேவைப்பட்டால் later bigger memory allocate பண்ணிக்கலாம்"
```

என்ற strategy பயன்படுத்துகிறது.

---

# Example

```cpp id="l2v7xq"
std::vector<int> vec;
```

Suppose internally:

```text id="a8m3p1"
capacity = 2
```

---

Heap:

```text id="n5r2k8"
1000 -> empty
1004 -> empty
```

---

# Push 1

```cpp id="u6c9j4"
vec.push_back(10);
```

Memory:

```text id="q1x8v7"
1000 -> 10
1004 -> empty
```

---

# Push 2

```cpp id="r4p7m2"
vec.push_back(20);
```

Memory:

```text id="f9k1z5"
1000 -> 10
1004 -> 20
```

---

# Now vector full

```text id="j3m8w1"
size = 2
capacity = 2
```

---

# Push 3

```cpp id="x7q2n6"
vec.push_back(30);
```

🔥 Problem:

```text id="k5v9r3"
existing heap full
```

---

# Vector internal solution

Vector internally:

## Step 1 — Bigger memory allocate

Usually:

```text id="b2x6m8"
capacity *= 2
```

---

Old:

```text id="y1n4q7"
capacity = 2
```

New:

```text id="c8r3p5"
capacity = 4
```

---

Allocate new heap:

```cpp id="m7v2k1"
new int[4]
```

Suppose new address:

```text id="w9p4x6"
5000
```

---

# New memory

```text id="h3k7m2"
5000 -> empty
5004 -> empty
5008 -> empty
5012 -> empty
```

---

# Step 2 — Copy old elements

Old heap:

```text id="t6n1v9"
1000 -> 10
1004 -> 20
```

Copy:

```text id="p2m8q4"
5000 -> 10
5004 -> 20
```

---

# Step 3 — Insert new element

```text id="z5x1r7"
5008 -> 30
```

---

# Step 4 — Delete old heap

```cpp id="q4v9m2"
delete[] old_memory;
```

---

# Step 5 — Pointer update

```cpp id="r8k3n1"
data_ptr = new_memory;
```

---

# Final state

```text id="u7m2x5"
5000 -> 10
5004 -> 20
5008 -> 30
5012 -> empty
```

🔥

---

# இதுதான் dynamic resizing

Vector fixed-size array இல்லை.

அது:

```text id="a5p8m3"
dynamic heap reallocation
```

பயன்படுத்துகிறது.

---

# Why capacity doubling?

Suppose every push_back-க்கும்:

```text id="d1k7v4"
new memory allocate
copy
delete old
```

செய்தால் extremely slow.

---

அதனால் vector:

```text id="m9x2q6"
extra empty memory
```

reserve பண்ணி வைக்கும்.

இதைத்தான்:

```cpp id="n4r8p1"
capacity
```

என்பார்கள்.

---

# Difference

| Term     | Meaning                |
| -------- | ---------------------- |
| size     | actual used elements   |
| capacity | allocated memory slots |

---

# Example

```text id="t3m7x2"
size = 3
capacity = 8
```

means:

```text id="q6p1v9"
3 elements used
5 empty slots ready
```

---

# Visualize

```text id="j8n4k7"
[10][20][30][ ][ ][ ][ ][ ]
```

---

# Why vector uses heap?

ஏனெனில் heap மட்டும்:

```text id="v2x9m5"
runtime resizing
```

allow செய்கிறது.

Stack memory resize செய்ய முடியாது.

---

# Your custom vector already does this

உங்கள் code-ல்:

```cpp id="p7m1k4"
if (current_size >= current_capacity)
```

↓

```cpp id="y4v8n2"
current_capacity *= 2;
```

↓

```cpp id="z1x5r9"
new T[current_capacity]
```

🔥

இதுதான் real std::vector concept.

---

# Deep truth

`std::vector` உண்மையில்:

```text id="g6n2p8"
"smart dynamic heap array"
```

மட்டுமே.

அதன் core operations:

* allocate heap
* copy/move elements
* delete old memory
* pointer arithmetic

🔥 இவைகள்தான்.
