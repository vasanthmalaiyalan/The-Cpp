🔥 நல்ல கேள்வி — இப்ப நீ concept almost பிடிச்சிட்டே 👍
ஆனா ஒரு **சின்ன but important correction** 👇

---

# 🧠 Rule (clear version)

```text id="r1"
signed >> n
⇒ MSB bit n times copy ஆகும்
```

👉 அதாவது:

```text id="r2"
left sideல n bits fill ஆகும்
```

---

# 🔍 Example

## Start

```text id="r3"
1000  (-8)
```

---

## Shift by 3

👉 3 bits shift பண்ணுறோம்:

```text id="r4"
1000 >> 3
```

👉 leftல 3 bits fill ஆகும்:

```text id="r5"
1111 ✔️
```

---

# 🔥 General idea

👉 negative numberனா:

```text id="r6"
MSB = 1
⇒ fill with 1
```

👉 positiveனா:

```text id="r7"
MSB = 0
⇒ fill with 0
```

---

# 💥 Important correction

👉 நீ கேட்டது:

> "negativeனா always 111 வருமா?"

👉 ❌ இல்லை

👉 correct:

```text id="r8"
shift எவ்வளவு (n)ன்னு depend ஆகும்
```

---

# 🔍 More examples

### Example 1

```text id="r9"
1000 >> 1 = 1100
```

---

### Example 2

```text id="r10"
1000 >> 2 = 1110
```

---

### Example 3

```text id="r11"
1000 >> 3 = 1111
```

---

# 🎯 Final answer

```text id="r12"
negativeனா MSB = 1 repeat ஆகும்
but count = shift amount
```

---

# 🧠 One-line memory

```text id="r13"
right shift → MSB repeats n times
```

---

🔥 இப்ப இது முழுசா settle ஆகணும் 💯
-------------

🔥 ஆமாம் — இப்ப நீ சரியான பாதையில் இருக்கே! இதை **formalா clarify** பண்ணுறேன் 👇

---

# 🧠 Two’s complement value formula

```text
value = -(MSB × 2^(w-1)) + (rest bits × powers of 2)
```

👉 அதாவது:

```text id="f1"
முதல் bit (MSB) மட்டும் negative weight  
மீதியெல்லாம் positive weight ✔️
```

---

# 🔍 Example: 1111 (4-bit)

```text id="f2"
bits: 1 1 1 1
positions: 3 2 1 0
```

👉 apply formula:

```text id="f3"
= (1 × -2^3) + (1 × 2^2) + (1 × 2^1) + (1 × 2^0)
= -8 + 4 + 2 + 1
= -1 ✔️
```

---

# 🔥 Example: 1000

```text id="f4"
= (1 × -2^3) + 0 + 0 + 0
= -8 ✔️
```

---

# 💥 Important clarity

👉 நீ சொன்னது:

> “MSB மட்டும் negative, rest positive தானே?”

👉 ✔️ **100% correct**

---

# 🧠 Why this works?

👉 two’s complement design:

```text id="f5"
MSB → negative weight (-2^(w-1))
rest → normal binary (+ powers of 2)
```

---

# 🔍 Another example

```text id="f6"
1010
```

👉 compute:

```text id="f7"
= -8 + 0 + 2 + 0
= -6 ✔️
```

---

# 🎯 Final answer

```text id="f8"
✔️ MSB மட்டும் negative
✔️ rest bits positive
```

---

# 🧠 One-line memory

```text id="f9"
two’s complement = one negative weight + rest positive
```

---

🔥 நீ இப்ப formula-level clarityக்கு வந்துட்ட 💯

வேணும்னா next:
👉 இந்த formula எப்படி derive பண்ணியது deep proof காட்டுறேன் 😏
