சூப்பர் 🔥 இது CSAPPல **very important concept** — நான் இதை cleanஆ, simple தமிழ்ல break பண்ணுறேன்.

---

# 🧠 1. Shift operations என்ன?

👉 Cல இரண்டு shift operators:

```c
x << k   // left shift
x >> k   // right shift
```

👉 `k` = எத்தனை bits move பண்ணணும்

---

# 🔁 2. Left Shift (`<<`)

👉 Rule:

> bits எல்லாம் **leftக்கு k இடம் நகரும்**
> right side **0 fill ஆகும்**

---

## Example

```text
x = 01100011
x << 4 = 00110000
```

👉 explanation:

```text
0110 0011
↓ shift 4
0011 0000
```

👉 left side bits drop ❌
👉 right side zeros fill ✅

---

# 🔁 3. Right Shift (`>>`) — முக்கியம் ⚠️

👉 இரண்டு type இருக்கு:

---

## 🔹 (A) Logical Right Shift

👉 left side = **0 fill**

```text
x = 10010101
x >> 4 (logical) = 00001001
```

---

## 🔹 (B) Arithmetic Right Shift

👉 left side = **MSB (sign bit) copy**

```text
x = 10010101
x >> 4 (arithmetic) = 11111001
```

👉 MSB = 1 → negative
👉 அதனால 1 fill

---

# 🧠 4. ஏன் இரண்டு type?

👉 காரணம்:

### 🔹 unsigned numbers

* sign concept இல்லை
* → always **logical shift**

---

### 🔹 signed numbers

* sign preserve பண்ணணும்
* → **arithmetic shift**

---

# 🔥 Table (book example)

| Operation           | Value1 (01100011) | Value2 (10010101) |
| ------------------- | ----------------- | ----------------- |
| x << 4              | 00110000          | 01010000          |
| x >> 4 (logical)    | 00000110          | 00001001          |
| x >> 4 (arithmetic) | 00000110          | 11111001          |

---

# 💥 முக்கிய observation

👉 எல்லா caseலுமே:

* mostly **0 fill தான்**
* except:

  * signed + MSB = 1
  * → arithmetic shift → **1 fill**

---

# ⚠️ 5. C language problem

👉 C standard சொல்லாது:

> signed right shift logicalஆ? arithmeticஆ?

👉 அதனால்:

> ❗ portable code எழுதும்போது careful

---

## 🧠 Practical reality

👉 almost எல்லா systemsல:

> signed >> = **arithmetic shift**

---

# ✅ 6. Important rule summary

| Type        | Shift              | Fill |
| ----------- | ------------------ | ---- |
| unsigned >> | logical            | 0    |
| signed >>   | usually arithmetic | MSB  |

---

# 🔥 7. Java difference (important)

👉 Java clearஆ define பண்ணுது:

```java
x >> k   // arithmetic shift
x >>> k  // logical shift
```

---

# 🎯 Final intuition

👉 Left shift:

> multiply (approx)
> 0 fill

👉 Right shift:

> divide (approx)
> unsigned → 0 fill
> signed → sign preserve

---

# 🔥 One-line summary

> `<<` → left move + 0 fill
> `>>` → right move + (0 or MSB fill)

---

நீ இப்போ 🔥 CSAPP concept முழுக்க grasp பண்ணிட்டே இருக்கே

👉 next killer topic:

**“why signed right shift exact divide இல்ல sometimes”**
(இது interview + systemsல முக்கியம்)

சொல்லு 😄
