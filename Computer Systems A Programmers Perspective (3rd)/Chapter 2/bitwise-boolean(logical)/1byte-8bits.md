அட 🔥 இந்த doubt வந்துட்டா நீ **range concept almost master பண்ணிட்டே** 😄
நான் crystal clearஆ சொல்லுறேன் 👇

---

# 🎯 Question

> **2⁸ = 256 என்றால் ஏன் max = 255?**

---

# 🧠 Key idea

> ❗ 256 என்பது **count (எத்தனை values)**
> ❗ 255 என்பது **maximum value**

---

# 🔍 Step-by-step

## 🔹 8 bits → total combinations

```text
2^8 = 256 values
```

👉 அதாவது:

```text
00000000
to
11111111
```

👉 total = 256 numbers

---

## 🔹 values start from?

👉 unsigned:

```text
start = 0
```

---

## 🔹 end எங்கு?

👉 count = 256 numbers

```text
0, 1, 2, 3, ..., 255
```

👉 last value:

```text
255 ✅
```

---

# 🔥 Simple math

```text
total values = 256
start = 0
```

👉 last value:

```text
256 - 1 = 255
```

---

# 🧠 Example (small case)

## 2 bits:

```text
2^2 = 4 values
```

👉 numbers:

```text
00 = 0
01 = 1
10 = 2
11 = 3
```

👉 max:

```text
3 = 4 - 1
```

---

## 3 bits:

```text
2^3 = 8 values
```

👉 numbers:

```text
0 → 7
```

👉 max:

```text
7 = 8 - 1
```

---

# 🔥 Binary proof

```text
11111111
```

👉 value:

```text
128 + 64 + 32 + 16 + 8 + 4 + 2 + 1 = 255
```

---

# 🎯 Final clarity

| Concept      | Value |
| ------------ | ----- |
| total values | 256   |
| start        | 0     |
| max          | 255   |

---

# 🔥 One-line takeaway

> 2ⁿ = total values
> max = 2ⁿ - 1

---

# 💥 Super intuition

> count 256 numbers இருந்தாலும்
> 👉 0 இருந்து start ஆகுறதால்
> 👉 last = 255 தான்

---

நீ இப்போ 🔥 perfect binary understanding stageல இருக்கே

👉 next:

**“why signed max = 127 (not 128)”** 😏
👉 இது இன்னும் interesting concept
