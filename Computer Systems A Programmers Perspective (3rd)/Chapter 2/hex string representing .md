# 2.1.4 Representing Strings

## C String = byte array + null terminator

```c
// "12345" in C:
char s[] = "12345";
// Memory: ['1']['2']['3']['4']['5']['\0']
//          6 bytes total — null terminator include பண்ணணும்
```

---

## Book-ரோட exact example — `show_bytes("12345", 6)`

Book சொல்றது: result = `31 32 33 34 35 00`

ஏன் இப்படி வருது:

```
Character:  '1'   '2'   '3'   '4'   '5'   '\0'
ASCII hex:  0x31  0x32  0x33  0x34  0x35  0x00

show_bytes output: 31 32 33 34 35 00
```

**Book-ரோட exact observation:**

> "The ASCII code for decimal digit x happens to be 0x3x"

```
Digit '0' → 0x30
Digit '1' → 0x31
Digit '2' → 0x32
Digit '3' → 0x33
Digit '4' → 0x34
Digit '5' → 0x35
Digit '6' → 0x36
Digit '7' → 0x37
Digit '8' → 0x38
Digit '9' → 0x39
```

Pattern: digit `x` → ASCII `0x3x`. Neat!

**Null terminator:**

```
'\0' = 0x00 = all zeros byte
String end mark — C-ல string length determine பண்ண இதை use பண்றது
```

---

## Platform independence — key insight

Book-ரோட exact point:

> "This same result would be obtained on any system using ASCII as its character code, independent of the byte ordering and word size conventions."

ஏன்? Integer `0x12345678`-ல byte ordering matter ஆகுது — ஏன்னா அது **one multi-byte value**.

String `"12345"`-ல ஒவ்வொரு character-உம் **independent 1-byte value**:

```
Integer 0x12345678:
  Little endian: 78 56 34 12  ← order changes!
  Big endian:    12 34 56 78

String "12345":
  Little endian: 31 32 33 34 35 00  ← same!
  Big endian:    31 32 33 34 35 00  ← same!

Each char = 1 byte → no multi-byte ordering issue
```

**Consequence — book சொல்றது:**

> "Text data are more platform independent than binary data."

```
Binary data (int, float, pointer):
  Machine A → Machine B அனுப்பும்போது
  Byte order conversion தேவை (htonl, ntohl)

Text data (ASCII strings):
  Any machine-க்கும் அனுப்பலாம்
  Same bytes → same characters → same meaning

இதனால HTTP, SMTP, FTP protocols — text-based!
Network-ல communicate பண்ண easy.
```

---

## ASCII table — quick reference

```
man ascii  ← terminal-ல இந்த command run பண்ணு, full table பாக்கலாம்

Key values:
  '0'–'9' : 0x30–0x39
  'A'–'Z' : 0x41–0x5A
  'a'–'z' : 0x61–0x7A
  ' '     : 0x20
  '\n'    : 0x0A
  '\0'    : 0x00
```

அடுத்து 2.1.5 (Representing Code) போகலாமா?

----------

சூப்பர் 🔥 இப்போ இந்த section (**2.1.4 Representing Strings**) — book என்ன சொல்ல வருது என்பதைக் **deepஆ + example use பண்ணி** clear பண்ணுறேன்.

---

# 🧠 🔥 ONE LINE (core idea)

```text
C string = characters array + lastல null (0x00)
```

---

# ⚙️ 1. Example (book)

```c
show_bytes("12345", 6);
```

👉 ஏன் 6?

```text
"12345" = 5 characters
+ 1 null terminator ('\0')
= total 6 bytes
```

---

# 🔥 2. Memoryல actual என்ன store ஆகுது?

👉 string:

```text
"12345"
```

---

👉 ஒவ்வொரு character-க்கும் ASCII code இருக்கும்:

| Character | ASCII (hex) |
| --------- | ----------- |
| '1'       | 0x31        |
| '2'       | 0x32        |
| '3'       | 0x33        |
| '4'       | 0x34        |
| '5'       | 0x35        |

---

👉 plus:

```text
'\0' = 0x00
```

---

# 💥 FINAL MEMORY

```text
31 32 33 34 35 00
```

---

# 🧠 3. show_bytes output

```text
313233343500
```

👉 இது:

```text
31 32 33 34 35 00 (space இல்லாமல் print)
```

---

# ⚡ 4. முக்கிய observation (book சொல்றது)

```text
ASCII digit 'x' → 0x3x
```

---

👉 example:

| Digit | Hex  |
| ----- | ---- |
| '1'   | 0x31 |
| '2'   | 0x32 |
| '9'   | 0x39 |

---

👉 pattern:

```text
'0' → 0x30
'1' → 0x31
...
'9' → 0x39
```

---

# 🔥 5. NULL terminator (VERY IMPORTANT)

```text
'\0' = 0x00
```

👉 இது:

```text
string end marker
```

---

👉 C internally:

```text
"12345" → end எங்கேன்னு தெரிஞ்சுக்கிறது இதால்தான்
```

---

# 💣 6. Why endian doesn't matter here?

👉 number exampleல:

```text
39 30 00 00 → endian affect
```

---

👉 stringல:

```text
31 32 33 34 35 00
```

👉 each character = 1 byte

👉 so:

```text
order same
```

---

# 🧠 7. Why platform independent?

👉 because:

```text
ASCII standard fixed
```

---

👉 so:

```text
Linux / Windows / Mac → same bytes
```

---

# ⚡ 8. Visual memory

```text
Address     Value
-----------------------
0x100       31 ('1')
0x101       32 ('2')
0x102       33 ('3')
0x103       34 ('4')
0x104       35 ('5')
0x105       00 ('\0')
```

---

# 💥 9. BIG INSIGHT

```text
String = array of bytes (characters)
```

👉 difference:

| Type   | Storage                        |
| ------ | ------------------------------ |
| int    | multi-byte (endian matters)    |
| string | byte-by-byte (no endian issue) |

---

# 🔥 FINAL SUMMARY

```text
"12345"
→ ASCII convert
→ 31 32 33 34 35
→ + 00 (end)
```

---

# 💣 FINAL ONE-LINE

```text
"C string = characters bytes + 0x00 end marker"
```

---

🔥 இப்போ நீ புரிஞ்சுட்ட:

👉 ASCII encoding
👉 null terminator importance
👉 why strings portable

---

👉 next (🔥 powerful):

* char vs int difference memoryல
* why string length தெரியாது (strlen எப்படி work)
* buffer overflow 😈

சொல்லு 😎
