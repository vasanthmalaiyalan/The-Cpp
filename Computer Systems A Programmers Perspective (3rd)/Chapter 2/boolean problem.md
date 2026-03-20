சூப்பர் 🔥 இப்போ நீ கொடுத்தது **Boolean Algebra practical problems** —
நாம இதை **step-by-step, book flow + clear reasoning**ல solve பண்ணலாம்.

---

# 🔥 ✅ Practice Problem 2.8

## GIVEN

```text
a = 01001110
b = 11100001
```

---

# 🧠 RULE REMINDER

| Operation | Meaning   |
| --------- | --------- |
| ~         | flip bits |
| &         | both 1    |
| |         | any 1     |
| ^         | different |

---

## 🟢 1. ~a

```text
a  = 01001110
~a = 10110001
```

---

## 🔵 2. ~b

```text
b  = 11100001
~b = 00011110
```

---

## 🟡 3. a & b

```text
  01001110
& 11100001
----------
  01000000
```

---

## 🔴 4. a | b

```text
  01001110
| 11100001
----------
  11101111
```

---

## ⚡ 5. a ^ b

```text
  01001110
^ 11100001
----------
  10101111
```

---

# 💥 FINAL ANSWER (2.8)

```text
~a   = 10110001
~b   = 00011110
a&b  = 01000000
a|b  = 11101111
a^b  = 10101111
```

---

# 💣 KEY INSIGHT

```text
bit-by-bit apply தான் எல்லாமே
```

---

# 🔥 BONUS (book important concept)

```text
a ^ a = 0
```

👉 XOR trick 🔥

---

---

# 🔥 ✅ Practice Problem 2.9 (Colors)

👉 mapping:

```text
R G B
```

---

## 🎨 Colors table

| Color   | RGB |
| ------- | --- |
| Black   | 000 |
| Blue    | 001 |
| Green   | 010 |
| Cyan    | 011 |
| Red     | 100 |
| Magenta | 101 |
| Yellow  | 110 |
| White   | 111 |

---

# 🧠 A. Complement (~)

👉 rule:

```text
0 → 1
1 → 0
```

---

| Color   | RGB | ~   | Result  |
| ------- | --- | --- | ------- |
| Black   | 000 | 111 | White   |
| Blue    | 001 | 110 | Yellow  |
| Green   | 010 | 101 | Magenta |
| Cyan    | 011 | 100 | Red     |
| Red     | 100 | 011 | Cyan    |
| Magenta | 101 | 010 | Green   |
| Yellow  | 110 | 001 | Blue    |
| White   | 111 | 000 | Black   |

---

# 🔥 B. Operations

---

## 🟢 1. Blue | Green

```text
Blue  = 001
Green = 010

OR → 011
```

👉 result:

```text
Cyan
```

---

## 🔵 2. Yellow & Cyan

```text
Yellow = 110
Cyan   = 011

AND → 010
```

👉 result:

```text
Green
```

---

## 🔴 3. Red ^ Magenta

```text
Red     = 100
Magenta = 101

XOR → 001
```

👉 result:

```text
Blue
```

---

# 💥 FINAL ANSWER (2.9)

```text
A:
Black ↔ White
Blue ↔ Yellow
Green ↔ Magenta
Cyan ↔ Red

B:
Blue | Green = Cyan
Yellow & Cyan = Green
Red ^ Magenta = Blue
```

---

# 🧠 DEEP INSIGHT

```text
Bit vectors → sets represent பண்ணலாம்
```

---

👉 example:

```text
a = 01101001 → set {0,3,5,6}
```

---

👉 operations:

| Bit op | Set meaning  |
| ------ | ------------ |
| &      | intersection |
| |      | union        |
| ~      | complement   |

---

# 🔥 FINAL SUMMARY

```text
Boolean algebra:
→ logic
→ bit operations
→ sets
→ colors
→ real systems
```

---

# 💣 FINAL ONE-LINE

```text
"Boolean operations = bit manipulation + set logic + real-world systems"
```

---

🔥 நீ இப்போ:

👉 bit-level thinking strong
👉 XOR concept புரிஞ்சு
👉 set mapping புரிஞ்சு

---

👉 next (🔥 killer topics):

* XOR swap trick 😈
* bit masking (set/clear bits)
* real OS signal masks

சொல்லு 😎
