`ஏன் இந்த அட்ரஸ் மட்டும் டிஃபரண்ட் உள்ளது `vector heap data address      ``

ஏனெனில் 🔥

```cpp
std::vector
```

ஒரு dynamic container.

அதன் actual elements:

## object உள்ளே store ஆகாது.

அவை:

## heap memory-ல் store ஆகும்.

அதனால்:

```text
vector object address
```

மற்றும்

```text
vector heap data address
```

வேறுபடும்.

---

# Very Important Understanding

இந்த line:

```cpp
std::vector<int> values;
```

இதன் meaning:

> values object உள்ளே actual integers இருக்காது.

Instead:

* pointer
* size
* capacity

மட்டும் இருக்கும்.

---

# Real internal structure (simplified)

Conceptually vector roughly:

```cpp
class vector
{
    int* data;
    size_t size;
    size_t capacity;
};
```

---

# So object memory

```text
store object
+---------------------------+
| values.data pointer ------+----+
| values.size               |    |
| values.capacity           |    |
+---------------------------+    |
                                 |
                                 v
                         heap memory
                         +----+----+----+
                         | 10 | 20 | 30 |
                         +----+----+----+
```

---

# Therefore addresses differ

---

# Example

Suppose:

## Object address

```text
0x1000
```

Inside object:

```text
pointer = 0x9000
```

Heap elements:

```text
0x9000 -> 10
0x9004 -> 20
0x9008 -> 30
```

---

# So:

| Thing         | Address       |
| ------------- | ------------- |
| object        | 0x1000        |
| vector member | inside object |
| heap data     | 0x9000        |

Different memory regions.

---

# Why vector does this?

Because vector size dynamic.

---

# Imagine

```cpp
values.push_back(...)
```

பல தடவை add செய்யலாம்.

---

# Problem if inside object memory only

Object fixed size.

Compiler compile-time-ல் object size தெரிந்திருக்க வேண்டும்.

---

# Impossible:

```cpp
class X
{
    ??? unknown amount of ints
};
```

---

# Solution

Object stores:

```text
pointer
```

Actual data:

```text
heap
```

---

# Why heap?

Heap allows:

* dynamic growth
* resize
* runtime allocation

---

# Important distinction

---

# Normal array inside object

```cpp
class X
{
    int arr[3];
};
```

இதில்:

```text
object
+----+----+----+
| 10 | 20 | 30 |
+----+----+----+
```

Everything inside object.

Addresses close.

---

# Vector

```cpp
class X
{
    vector<int> arr;
};
```

இதில்:

```text
object
+----------------+
| pointer -------+-----> heap
| size           |
| capacity       |
+----------------+
```

---

# This is why vector powerful

Can:

* grow dynamically
* resize
* move memory
* allocate huge data

---

# Very Important

When vector grows:

```cpp
values.push_back(...)
```

Sometimes:

* old heap memory freed
* new larger heap memory allocated
* elements copied

---

# Therefore:

```cpp
values.data()
```

address கூட change ஆகலாம்.

---

# Example

Initially:

```text
0x9000
```

After resize:

```text
0xA000
```

---

# But object address same

```text
store = still 0x1000
```

---

# This is core modern container design

Almost all dynamic containers:

* vector
* string
* deque
* hashmap

Internally:

```text
object metadata + heap allocation
```

architecture use செய்கின்றன.

---

# Final Core Understanding

| Thing           | Stored where?        |
| --------------- | -------------------- |
| vector object   | inside parent object |
| vector elements | heap                 |
| object address  | stack/object memory  |
| data() address  | heap memory          |
| Different?      | YES                  |

---

# One-line summary

> vector object actual data-ஐ store செய்யாது;
> அந்த data இருக்கும் heap memory-க்கான pointer-ஐ மட்டும் store செய்கிறது.
