இந்த **Chapter 8 – Alternatives to Ten**-ல் author ஒரு பெரிய idea explain செய்கிறார்.
அது மிகவும் simple:

> **Numbers base-10 (decimal) மட்டும் இல்லை.
> வேறு base-களிலும் numbers இருக்கலாம்.**

இது computer-க்கு important because **binary (base-2)**.

நாம் step-by-step பார்ப்போம்.

---

# 1️⃣ Decimal system (base-10)

நாம் பயன்படுத்தும் system:

```
0 1 2 3 4 5 6 7 8 9
```

இதில்:

```
10 = next number
```

ஏன்?

```
10 fingers
```

அதனால் humans:

```
base-10 counting
```

---

# 2️⃣ Base-8 (Octal)

Author cartoon characters example கொடுக்கிறார்.

Cartoon characters:

```
4 fingers per hand
```

Total:

```
8 fingers
```

அதனால் அவர்கள்:

```
base-8 system
```

Counting:

```
0 1 2 3 4 5 6 7
10
11
12
```

Important point:

```
8 (decimal) = 10 (octal)
```

Example conversions:

| Decimal | Octal |
| ------- | ----- |
| 8       | 10    |
| 9       | 11    |
| 10      | 12    |
| 16      | 20    |
| 64      | 100   |

---

# 3️⃣ Positional system same தான்

Decimal:

```
4825
= 4×10³ + 8×10² + 2×10¹ + 5×10⁰
```

Octal example:

```
3725₈
```

Meaning:

```
3×8³ + 7×8² + 2×8¹ + 5×8⁰
```

---

# 4️⃣ Base-4 (Quaternary)

Author lobster example கொடுக்கிறார்.

Lobster claws:

```
2
```

அதனால்:

```
base-4
```

Digits:

```
0 1 2 3
```

Counting:

```
0
1
2
3
10
11
12
13
20
```

Example:

```
31232₄
```

---

# 5️⃣ Base-2 (Binary)

இப்போது author முக்கியமான system introduce செய்கிறார்.

Binary:

```
0
1
```

Only **two digits**.

Counting:

```
0
1
10
11
100
101
110
111
1000
```

---

# 6️⃣ Binary → Decimal

Binary example:

```
1011₂
```

Meaning:

```
1×2³ + 0×2² + 1×2¹ + 1×2⁰
```

```
8 + 0 + 2 + 1 = 11
```

So:

```
1011₂ = 11₁₀
```

---

# 7️⃣ Example from book

```
101101011010₂
```

Breakdown:

```
1×2048
0×1024
1×512
1×256
0×128
1×64
0×32
1×16
1×8
0×4
1×2
0×1
```

Result:

```
2906₁₀
```

---

# 8️⃣ Binary addition

Binary addition table:

```
0 + 0 = 0
0 + 1 = 1
1 + 0 = 1
1 + 1 = 10
```

Example:

```
 1011
+0110
------
10001
```

---

# 9️⃣ Binary multiplication

```
0 × anything = 0
1 × anything = same
```

Table:

```
0×0=0
0×1=0
1×0=0
1×1=1
```

---

# 🔟 Binary pattern

Example first numbers:

| Binary | Decimal |
| ------ | ------- |
| 0000   | 0       |
| 0001   | 1       |
| 0010   | 2       |
| 0011   | 3       |
| 0100   | 4       |
| 0101   | 5       |
| 0110   | 6       |
| 0111   | 7       |
| 1000   | 8       |

Pattern:

```
rightmost digit
0 1 0 1 0 1
```

Next digit:

```
00 11 00 11
```

Next:

```
0000 1111
```

---

# 1️⃣1️⃣ Binary ↔ electricity

இது தான் chapter-ன் biggest point.

Binary numbers:

```
0 / 1
```

Electrical devices:

| Device | 0          | 1         |
| ------ | ---------- | --------- |
| wire   | no current | current   |
| switch | open       | closed    |
| bulb   | off        | on        |
| relay  | rest       | activated |

அதாவது:

```
electricity = binary
```

---

# 1️⃣2️⃣ BIT

Binary digit → short name:

```
BIT
```

Coined by:

```
John Tukey (1948)
```

Meaning:

```
bit = binary digit
```

---

# 🎯 Chapter main idea

Author சொல்ல வருவது:

```
Decimal numbers special இல்லை
```

Many systems exist:

```
base-10
base-8
base-4
base-2
```

But computers use:

```
binary
```

Because:

```
electric circuits
= ON / OFF
= 1 / 0
```

---

# ⚡ One-line summary

```
Binary numbers connect mathematics with electricity.
```

---

நீ விரும்பினால் நான் next concept explain பண்ணலாம்:

**இந்த binary numbers எப்படி computer memory-ஆக மாறுகிறது (bits → bytes → characters)**

அது தான் இந்த book-லே அடுத்த பெரிய jump.
