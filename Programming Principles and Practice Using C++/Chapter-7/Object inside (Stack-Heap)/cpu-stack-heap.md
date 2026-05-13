`இதில் நாம் கூறும் stack,heap என்பது cpu உள்ளே இருப்பதை குறிக்குமா`

இல்லை ❌
`stack` மற்றும் `heap` என்பது CPU உள்ளே இருக்கும் memory இல்லை.

அவை:

# RAM (Main Memory)

உள்ள பகுதிகள்.

---

# Very Important Distinction

| Thing | Meaning                        |
| ----- | ------------------------------ |
| CPU   | instructions execute செய்கிறது |
| RAM   | data store செய்கிறது           |
| Stack | RAM-ல் ஒரு region              |
| Heap  | RAM-ல் ஒரு region              |

---

# Simple Picture

```text id="6r1sya"
+----------------------+
|        CPU           |
|----------------------|
| Registers            |
| ALU                  |
| Cache                |
+----------------------+

          ||
          || accesses
          \/

+----------------------------------+
|              RAM                 |
|----------------------------------|
| Stack                            |
| Heap                             |
| Global/Data Segment              |
| Code/Text Segment                |
+----------------------------------+
```

---

# CPU உள்ளே என்ன இருக்கும்?

CPU உள்ளே:

* registers
* cache
* execution units

இருக்கும்.

---

# Example

## Registers

Very tiny ultra-fast memory.

Example:

```text id="rjlwm5"
RAX
RBX
RSP
RBP
```

---

# Cache

CPU-க்குள் இருக்கும் fast memory.

* L1 cache
* L2 cache
* L3 cache

---

# But stack/heap?

Usually:

## RAM-ல் இருக்கும்.

---

# Stack என்ன?

RAM-ல்:
function calls/local variables store செய்யும் region.

---

# Example

```cpp id="jlwm1u"
void f()
{
    int x = 10;
}
```

`x`
typically stack memory.

---

# Heap என்ன?

RAM-ல்:
dynamic allocation region.

---

# Example

```cpp id="7jlwmy"
std::vector<int> v;
```

vector elements usually heap.

---

# OS Process Memory Layout

ஒரு program run ஆகும்போது:

```text id="4jlwma"
Process Virtual Memory

+----------------------+
| Code/Text Segment    |
+----------------------+
| Global/Data Segment  |
+----------------------+
| Heap  ---> grows up  |
|                      |
|                      |
|                      |
| Stack ---> grows down|
+----------------------+
```

---

# Important

இந்த memory:

## virtual memory.

OS manage செய்கிறது.

---

# CPU எப்படி access செய்கிறது?

CPU:

* addresses generate செய்கிறது
* RAM-லிருந்து data read/write செய்கிறது

---

# Example

```cpp id="qjlwmd"
int x = 10;
```

Suppose:

```text id="0jlwmm"
x address = 0x1000
```

CPU instruction:

```text id="yjlwmu"
read memory at 0x1000
```

---

# Cache Important

Although stack/heap RAM-ல் இருக்கும்:

Frequently used data:

## CPU cache-ல் temporarily வரும்.

---

# Example

vector traversal:

```cpp id="9jlwmp"
for (int i = 0; i < n; ++i)
```

CPU often loads nearby values into cache.

இதனால்:
vector fast.

---

# Why contiguous memory fast?

Because:
CPU cache optimized for sequential memory.

---

# Stack often faster than heap because

* simple allocation
* contiguous
* cache friendly
* automatic lifetime

---

# Heap slower because

* allocator overhead
* fragmentation
* indirect access

---

# Very Important Big Understanding

---

# CPU

Computes.

---

# RAM

Stores.

---

# Stack / Heap

RAM organization concepts.

---

# Registers

Inside CPU.

Ultra-fast.

---

# Cache

Inside/near CPU.

Fast temporary copies.

---

# Final Mental Model

```text id="zjlwme"
CPU
 |
 +-- Registers
 |
 +-- Cache
 |
 +-- accesses RAM
        |
        +-- Stack
        +-- Heap
        +-- Globals
        +-- Code
```

---

# One-line summary

> Stack மற்றும் heap என்பது CPU உள்ளே இல்லை.
> அவை RAM-ல் இருக்கும் memory regions; CPU அவற்றை address மூலம் access செய்கிறது.
