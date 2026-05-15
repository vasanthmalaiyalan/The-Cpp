``int& operator[](size_t i) ` நான் கேட்க வருவது இதற்கும் அப்புறம் `int operator[](size_t i) `இதற்கும் என்ன வித்தியாசம்`


இதுதான் C++-ல் மிக முக்கியமான difference-களில் ஒன்று. 🔥
இந்த ஒரு `&` காரணமாக behavior முழுவதும் மாறிவிடும்.

---

# Version 1

```cpp id="m7k2x5"
int& operator[](size_t i)
```

இதன் அர்த்தம்:

```text id="u4m8p1"
"actual original int-ஐ reference ஆக return செய்"
```

---

# Version 2

```cpp id="q1k7v4"
int operator[](size_t i)
```

இதன் அர்த்தம்:

```text id="r9m3x6"
"int value copy return செய்"
```

🔥

---

# Example memory

Suppose heap:

```text id="t5k1m8"
0x22b0 -> 10
0x22b4 -> 20
0x22b8 -> 30
```

---

# CASE 1 — Reference return

```cpp id="v2m9x4"
int& operator[](size_t i)
{
    return *(data + i);
}
```

---

Now:

```cpp id="c7k3p1"
numbers[2]
```

↓

```text id="n4m8v5"
actual int object at 0x22b8
```

(reference/alias)

---

# Therefore

## Modify works

```cpp id="u1k7x9"
numbers[2] = 999;
```

🔥 heap memory directly changes.

---

## Address works

```cpp id="q5m2v8"
&numbers[2]
```

↓

```text id="x8k1p4"
0x22b8
```

---

# CASE 2 — Value copy return

```cpp id="r2m7v5"
int operator[](size_t i)
{
    return *(data + i);
}
```

---

Now:

```cpp id="t4k8x1"
numbers[2]
```

↓

```text id="u7m3p9"
copy of value 30
```

🔥

---

# Important

இதில் original heap memory return ஆகவில்லை.

ஒரு temporary copy மட்டும்.

---

# Therefore

## Read works

```cpp id="p1k9v6"
int x = numbers[2];
```

✅ works.

Because copy enough.

---

# But modify fails

```cpp id="n5m4x8"
numbers[2] = 999;
```

❌ error / meaningless.

ஏனெனில்:

```text id="q3k7v1"
temporary copy-க்கு assign செய்கிறீர்கள்
```

---

# Address also problematic

```cpp id="r8m1v4"
&numbers[2]
```

❌ invalid/dangerous.

ஏனெனில்:

```text id="u6k2x9"
temporary value address
```

---

# Visualize difference

# Reference version

```cpp id="c4m9p5"
numbers[2]
```

↓

```text id="v1k7m3"
actual heap int
```

---

# Value version

```cpp id="f8m2x6"
numbers[2]
```

↓

```text id="y5k1v9"
copy of heap int
```

🔥

---

# Real-world analogy

## Reference (`int&`)

```text id="u3m8k4"
Original house key
```

You directly access real house.

---

## Value (`int`)

```text id="q7k2v5"
Photocopy/photo of house
```

You can see it.

But changing photo won't change real house.

🔥

---

# Demo

## Reference version

```cpp id="r1m9x7"
int& get()
{
    static int x = 10;

    return x;
}
```

---

```cpp id="t5k3m1"
get() = 999;
```

✅ real x changes.

---

# Value version

```cpp id="n8m2v4"
int get()
{
    static int x = 10;

    return x;
}
```

---

```cpp id="u4k7x6"
get() = 999;
```

❌ impossible.

Because returned thing:

```text id="p9m1v5"
temporary copied value
```

---

# Why std::vector uses int&

Because vector indexing must behave like real arrays.

Real arrays allow:

```cpp id="q2k8m7"
arr[2] = 999;
```

and:

```cpp id="r6m3v1"
&arr[2]
```

🔥

அதனால் vector also returns reference.

---

# Deep truth

இந்த:

```cpp id="t9k1x4"
arr[i]
```

C/C++-ல் actual memory object-ஐ represent செய்கிறது.

அதனால்தான்:

```cpp id="u5m7v2"
vector::operator[]
```

must return:

```cpp id="n1k8x5"
T&
```

not:

```cpp id="q4m2v9"
T
```

---

# Final essence

| Return type | Meaning                   |
| ----------- | ------------------------- |
| `int&`      | original memory reference |
| `int`       | copied value              |

---

அதனால்:

## `int&`

```cpp id="r7k3m6"
numbers[2] = 999;
&numbers[2];
```

✅ works.

---

## `int`

```cpp id="t2m9x1"
numbers[2] = 999;
&numbers[2];
```

❌ works properly இல்லை.

🔥 `&` ஒரு character மட்டும் அல்ல —
அது:

```text id="u8k4v5"
copy semantics
vs
real memory semantics
```

என்ற பெரிய difference.
