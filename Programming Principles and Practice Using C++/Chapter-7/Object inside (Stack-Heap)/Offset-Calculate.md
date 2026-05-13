`offset எப்படி கால்குலேட் ஆகிறது? `

மிக முக்கியமான question 🔥
இப்போது நீ actual compiler memory layout logic-ஐ பார்க்கிறாய்.

உன் output:

```text id="hjlwm1"
id offset        : 0 bytes
price offset     : 8 bytes
numbers offset   : 16 bytes
name offset      : 40 bytes
```

இதெல்லாம் எப்படி calculate ஆகிறது?

---

# Core Idea

## Offset means:

> object start address-லிருந்து
> member எவ்வளவு bytes தள்ளி இருக்கிறது?

---

# Formula

\text{offset} = \text{member address} - \text{object base address}

---

# Your code

நீ இதை பயன்படுத்தினாய்:

```cpp id="zjlwme"
reinterpret_cast<char*>(&price)
-
reinterpret_cast<char*>(this)
```

---

# Why `char*`?

Because:

```text id="6jlwmg"
char = 1 byte
```

அதனால் subtraction:

## exact byte difference.

---

# Example Memory Layout

Suppose:

```cpp id="mjlwmy"
class Demo
{
    int id;
    double price;
    vector<int> numbers;
    string name;
};
```

---

# Suppose object starts at:

```text id="8jlwma"
this = 1000
```

---

# Step-by-step Layout

---

# 1. `int id`

```text id="qjlwmd"
sizeof(int) = 4
```

Placed at:

```text id="0jlwmm"
1000
```

---

# But next member is double

---

# 2. `double price`

```text id="yjlwmu"
sizeof(double) = 8
```

double usually:

## 8-byte aligned.

---

# So compiler inserts padding.

---

# Layout becomes

```text id="9jlwmp"
1000 -> id (4 bytes)
1004 -> padding (4 bytes)
1008 -> price
```

---

# Therefore:

```text id="zjlwme"
price offset = 8
```

---

# 3. vector<int> numbers

Suppose vector object size:

```text id="6jlwmg"
24 bytes
```

---

# price occupies:

```text id="mjlwmy"
1008 - 1015
```

---

# Next available:

```text id="8jlwma"
1016
```

---

# Therefore:

```text id="qjlwmd"
numbers offset = 16
```

---

# 4. string name

Suppose vector occupies:

```text id="0jlwmm"
24 bytes
```

Then:

```text id="yjlwmu"
1016 + 24 = 1040
```

---

# Therefore:

```text id="9jlwmp"
name offset = 40
```

---

# So offsets come from:

## previous members + alignment/padding.

---

# VERY IMPORTANT CONCEPT

# Alignment

CPU certain data types aligned addresses-ல் இருந்தால் faster.

---

# Example

double often wants:

```text id="zjlwme"
address divisible by 8
```

---

# So compiler adds padding.

---

# Without padding

```text id="6jlwmg"
1004 -> double
```

slow/misaligned.

---

# Therefore compiler does:

```text id="mjlwmy"
1004-1007 padding
1008 double
```

---

# This is why offsets not always continuous.

---

# Your Output Explained

---

# id offset = 0

Because:
first member.

---

# price offset = 8

Because:
padding added after int.

---

# numbers offset = 16

After double.

---

# name offset = 40

After vector object.

---

# Your Code Logic

This line:

```cpp id="8jlwma"
reinterpret_cast<char*>(&price)
-
reinterpret_cast<char*>(this)
```

Suppose:

```text id="qjlwmd"
&price = 1008
this    = 1000
```

Then:

1008 - 1000 = 8

---

# That's the offset.

---

# Important

Offsets are:

## compile-time calculated.

Compiler already knows:

* member sizes
* alignments
* layout rules

---

# CPU access internally

When you write:

```cpp id="0jlwmm"
obj.price
```

Compiler roughly generates:

```text id="yjlwmu"
object_base + 8
```

---

# This is why objects fast

No searching.

Direct offset access.

---

# Visual Full Layout

```text id="9jlwmp"
Object Base = 1000

1000 -> id        (4 bytes)
1004 -> padding   (4 bytes)
1008 -> price     (8 bytes)
1016 -> numbers   (24 bytes)
1040 -> name
```

---

# Final Most Important Understanding

## Offset means:

```text id="zjlwme"
distance from object base address
```

---

# Calculated using:

```text id="6jlwmg"
member address - object address
```

---

# Compiler decides offsets based on:

* member size
* alignment rules
* padding

---

# One-line summary

> Offset என்பது object starting address-லிருந்து member எவ்வளவு bytes தள்ளி இருக்கிறது என்பதைக் காட்டும் value.
