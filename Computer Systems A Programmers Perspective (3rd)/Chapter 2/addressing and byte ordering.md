 Book-ல இருக்கற exact examples — Figure 2.4, Figure 2.5, Figure 2.6, disassembler output, 12345 byte trace — எல்லாத்தையும் use பண்ணி explain பண்றேன்.

---

# 2.1.3 — Book-ரோட Every Example Deep-ஆ

## Example 1 — `int x` address and layout

Book சொல்றது: variable `x` of type `int` has address `0x100`.

```
int x;  // assume address &x = 0x100
        // int = 4 bytes (32-bit representation)

Memory locations used:
  0x100 → byte 0 (lowest address = address of x)
  0x101 → byte 1
  0x102 → byte 2
  0x103 → byte 3 (highest address)

Rule: address of object = smallest address of bytes used
So &x = 0x100, always.
```

---

## Example 2 — `0x01234567` little vs big endian

Book-ரோட exact example: `x = 0x01234567` at address `0x100`.

```
Value breakdown:
  0x01 = most significant byte  (MSB)
  0x23
  0x45
  0x67 = least significant byte (LSB)
```

**Little endian (Intel x86 — உன் laptop):**

```
Address:  0x100  0x101  0x102  0x103
Byte:      67     45     23     01
           ↑LSB first              ↑MSB last
```

**Big endian (Sun SPARC):**

```
Address:  0x100  0x101  0x102  0x103
Byte:      01     23     45     67
           ↑MSB first             ↑LSB last
```

---

## Example 3 — Disassembler output (book-ரோட exact line)

```
4004d3: 01 05 43 0b 20 00    add %eax, 0x200b43(%rip)
```

Book சொல்றது: last 4 bytes = `43 0b 20 00` — இது little-endian-ல store ஆன address.

```
Bytes as they appear: 43  0b  20  00
                      ↑                ↑
                    lowest addr    highest addr

Little-endian → reverse பண்ணி read:
  00  20  0b  43  = 0x00200b43

Leading zero drop: 0x200b43 ✓

Book சொல்றது: "natural way = lowest byte left, highest right"
BUT numbers normally written MSB left — இதனால reverse-ஆ தெரியும்.
```

---

## Example 4 — Figure 2.4: show_bytes code, line by line

```c
#include <stdio.h>

typedef unsigned char *byte_pointer;
// unsigned char = 1 byte, 0–255
// byte_pointer = pointer to 1 byte
// So dereferencing gives exactly 1 byte at a time
```

```c
void show_bytes(byte_pointer start, size_t len) {
    int i;
    for (i = 0; i < len; i++)
        printf("%.2x", start[i]);
    printf("\n");
}
```

**Line-by-line:**

```
byte_pointer start  → starting address (pointer to first byte)
size_t len          → how many bytes to print
                      size_t = unsigned int, word-size (portable)

start[i]            → i-th byte from start address
                      same as *(start + i)
                      pointer arithmetic + array notation = identical in C

"%.2x"              → hex format, minimum 2 digits
                      byte value 5   → "05" (not "5")
                      byte value 255 → "ff"
```

```c
void show_int(int x) {
    show_bytes(
        (byte_pointer) &x,  // line 13
        sizeof(int)          // = 4 bytes
    );
}
```

**Line 13 — cast breakdown:**

```
&x              → type: int*    (address of x)
(byte_pointer)  → cast to: unsigned char*

Cast changes: compiler's view of the pointer type
Cast does NOT change: the actual pointer value (address)

Before cast: compiler treats memory as int (4 bytes at once)
After cast:  compiler treats memory as unsigned char (1 byte at a time)

So show_bytes reads x's memory 1 byte at a time → prints each byte in hex
```

```c
void show_float(float x) {
    show_bytes((byte_pointer) &x, sizeof(float));  // line 17
}
// sizeof(float) = 4 — same as int

void show_pointer(void *x) {
    show_bytes((byte_pointer) &x, sizeof(void*));  // line 21
}
// sizeof(void*) = 4 (32-bit) or 8 (64-bit) — word size
// Note: &x — address OF the pointer variable itself, not what it points to
```

---

## Example 5 — Figure 2.5: test_show_bytes

```c
void test_show_bytes(int val) {
    int   ival = val;           // line 2: int copy
    float fval = (float) ival;  // line 3: convert int to float
    int  *pval = &ival;         // line 4: pointer to ival

    show_int(ival);             // line 5
    show_float(fval);           // line 6
    show_pointer(pval);         // line 7
}
```

`val = 12345`:

```
12345 decimal = 0x00003039 hex

ival = 12345  → int,   4 bytes, value 0x00003039
fval = 12345.0 → float, 4 bytes, value 0x4640E400 (IEEE 754)
pval = &ival   → int*,  4 or 8 bytes, = address of ival
```

---

## Example 6 — Figure 2.6: Real output on 4 machines

**`ival = 12345 = 0x00003039`:**

```
Bytes in memory:
  MSB→LSB order: 00  00  30  39

Linux32  (little-endian): 39 30 00 00  ← LSB first ✓
Windows  (little-endian): 39 30 00 00  ← same ✓
Sun      (big-endian):    00 00 30 39  ← MSB first ✓
Linux64  (little-endian): 39 30 00 00  ← same ✓
```

**Verify Linux32:** `39 30 00 00`

```
byte[0] at lowest addr = 0x39 = 57 decimal = LSB of 12345
byte[1] = 0x30 = 48
byte[2] = 0x00
byte[3] at highest addr = 0x00 = MSB

Reconstruct: 0x00 0x00 0x30 0x39 = 0x00003039 = 12345 ✓
```

**`fval = 12345.0 = 0x4640E400`:**

```
Linux32  (little-endian): 00 e4 40 46  ← reverse of 4640E400 ✓
Sun      (big-endian):    46 40 e4 00  ← straight 4640E400 ✓

Note: int 0x00003039 ≠ float 0x4640E400
Same numeric value, completely different bit patterns
→ int and float use different encoding schemes
```

**`pval = &ival` (pointer):**

```
Linux32:  e4f9ffbf          → 4 bytes (32-bit address)
Windows:  b4cc2200          → 4 bytes (32-bit address)
Sun:      effffa0c          → 4 bytes (32-bit address)
Linux64:  b811e5ffff7f0000  → 8 bytes (64-bit address) ← word size!

Pointer values completely different per machine —
OS/compiler decides where to place variables in memory.
```

---

## Example 7 — int vs float bit pattern comparison (book-ரோட exact analysis)

```
12345 as int:   0x00003039
12345.0 as float: 0x4640E400

Binary expansion:
0x00003039:
  0000 0000 0000 0000 0011 0000 0011 1001

0x4640E400:
  0100 0110 0100 0000 1110 0100 0000 0000

Align and compare:
int:   00000000000000000011000000111001
float: 01000110010000001110010000000000
                      *************
                      13 matching bits!
```

Book: "This is not coincidental." — Float encoding-ல mantissa bits-ல 12345-ரோட binary pattern appear ஆகும். Floating point chapter-ல இதை explain பண்ணும்.

---

## Example 8 — typedef usage (book-ரோட exact examples)

```c
// Book-ரோட example:
typedef int *int_pointer;
int_pointer ip;
// equivalent to:
int *ip;

// byte_pointer similarly:
typedef unsigned char *byte_pointer;
byte_pointer bp;
// equivalent to:
unsigned char *bp;

// Syntax rule:
// typedef [type] [new_name];
// Same as variable declaration — just use type name instead of variable name
```

---

## Example 9 — `&` operator and cast (lines 13, 17, 21)

```c
// Line 13: show_int
int x = 12345;
&x              // creates int* pointing to x
(byte_pointer)&x // cast: same address, now treated as unsigned char*

// What changes:
// Before: compiler accesses 4 bytes at once (int)
// After:  compiler accesses 1 byte at a time (unsigned char)
// Memory: unchanged, bits unchanged, address unchanged

// Line 21: show_pointer
void *x = pval;  // x is a pointer
&x               // address OF the pointer variable — not what it points to!
sizeof(void*)    // size of pointer itself = 4 or 8 bytes
```

---

## Example 10 — pointer + array duality (show_bytes-ல)

```c
void show_bytes(byte_pointer start, size_t len) {
    for (i = 0; i < len; i++)
        printf("%.2x", start[i]);  // array notation on pointer!
}

// start[i]  ==  *(start + i)  // C-ல identical

// start = 0x7fff1000 (address of ival)
// start[0] = *(0x7fff1000) = first byte  = 0x39
// start[1] = *(0x7fff1001) = second byte = 0x30
// start[2] = *(0x7fff1002) = third byte  = 0x00
// start[3] = *(0x7fff1003) = fourth byte = 0x00
// → prints: 39300000
```

---

Book-ல இருக்கற every example, every figure, every code line — எல்லாத்தையும் cover பண்ணாச்சு. அடுத்து 2.1.4 (Representing Strings) paste பண்ணு!

----

ஆமாம் 🔥 நீ சரியான example try பண்ணிருக்க — errorயும் perfect learning point தான்.

---

# ❌ Problem என்ன?

```text
undefined reference to `main`
```

👉 இதன் அர்த்தம்:

```text
Programல main() function இல்ல ❌
```

---

# 🧠 WHY?

👉 C program run ஆகணும் என்றால்:

```text
Execution always starts from → main()
```

---

👉 நீ இப்போ எழுதிருக்குற code:

```c
void show_bytes(...)
```

👉 இது ஒரு function மட்டும்
👉 but entry point இல்லை ❌

---

# ✅ FIX (Add main function)

👉 book example full working version 👇

```c
#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    int i;
    for (i = 0; i < len; i++)
        printf("%.2x ", start[i]);
    printf("\n");
}

void show_int(int x) {
    show_bytes((byte_pointer)&x, sizeof(int));
}

int main() {
    int x = 12345;
    show_int(x);
    return 0;
}
```

---

# 🔥 Compile & Run

```bash
gcc bycode_pointer.c -o test
./test
```

---

# 🧠 Expected Output (on your laptop)

👉 (Intel = little endian)

```text
39 30 00 00
```

---

# 💥 Why this output?

👉 x = 12345

```text
decimal → hex = 0x00003039
```

---

👉 memory (little endian):

```text
39 30 00 00
```

---

# 🔥 Try MORE (important)

👉 change value:

```c
int x = 0x01234567;
```

---

👉 output:

```text
67 45 23 01
```

---

👉 boom 💥

👉 now you are seeing:

```text
Little endian in real life 😎
```

---

# 💣 FINAL INSIGHT

```text
Code compile error → because no entry point
main() is mandatory in C
```

---

# ⚡ ONE LINE

```text
"No main → no program execution"
```

---

🔥 next level try பண்ணலாமா?

👉 show_float() add பண்ணு
👉 pointer print பண்ணு
👉 gdbல memory dump பாரு

நான் guide பண்ணுறேன் 😎
----------

சூப்பர் 🔥 இப்போ நீ எழுதின code-ஐ **line by line deepஆ explain பண்ணுறேன்** — book example-ோட exact meaning 👇

---

# 🧠 🔥 0. Overall என்ன code இது?

```text
இந்த code → memoryல data எப்படி byte-by-byte store ஆகுது என்பதை காட்டுகிறது
```

👉 முக்கியமாக:

```text
int value → raw bytes ஆக print பண்ணுறோம்
```

---

# ⚙️ 1. Header

```c
#include <stdio.h>
```

👉 இது:

```text
printf() use பண்ணணும் → அதனால include
```

---

# 🧠 2. typedef

```c
typedef unsigned char *byte_pointer;
```

👉 breakdown:

* `unsigned char` → 1 byte (0–255)
* `*` → pointer

---

👉 meaning:

```text
byte_pointer = pointer to raw bytes
```

👉 இதன் purpose:

```text
memory-யை byte-by-byte read பண்ண
```

---

# 🔥 3. show_bytes function

```c
void show_bytes(byte_pointer start, size_t len)
```

👉 parameters:

* `start` → memory starting address
* `len` → எத்தனை bytes print பண்ணணும்

---

## inside:

```c
for (i = 0; i < len; i++)
    printf("%.2x ", start[i]);
```

---

👉 முக்கியம்:

```text
start[i] → i-th byte read
```

👉 `%.2x`:

```text
2-digit hexadecimal print
```

---

👉 finally:

```c
printf("\n");
```

---

# 💥 4. show_int function

```c
void show_int(int x)
```

---

## inside:

```c
show_bytes((byte_pointer)&x, sizeof(int));
```

---

👉 breakdown:

### 🔹 `&x`

```text
x-ன் memory address
```

---

### 🔹 cast:

```c
(byte_pointer)&x
```

👉 meaning:

```text
"இந்த int-ஐ byte array மாதிரி treat பண்ணு"
```

---

### 🔹 sizeof(int)

```text
4 bytes (usually)
```

---

👉 overall:

```text
x-ஐ raw memory bytes ஆக print பண்ணு
```

---

# 🧠 5. main function

```c
int main()
```

---

## inside:

```c
int x = 12345;
```

👉 value:

```text
12345 = 0x00003039
```

---

```c
show_int(x);
```

👉 calls:

```text
show_bytes(&x, 4)
```

---

# 🔥 6. Real output (your laptop)

👉 little endian:

```text
39 30 00 00
```

---

# 💥 Why?

👉 memory:

```text
0x00003039
→ bytes: 00 00 30 39
```

---

👉 little endian store:

```text
39 30 00 00
```

---

# 🧠 7. Most important concept

```text
இந்த code → type system bypass பண்ணுது
```

---

👉 normally:

```c
int x;
```

👉 but here:

```text
we treat x as bytes
```

---

# 💣 8. What you actually learned

---

## 🔥 Concept 1

```text
Memory = bytes
```

---

## 🔥 Concept 2

```text
Data type = interpretation
```

---

## 🔥 Concept 3

```text
Pointer → address
```

---

## 🔥 Concept 4

```text
Endianness visible
```

---

# ⚡ 9. Simple analogy

👉 imagine:

```text
x = 12345
```

---

👉 normally:

```text
நீ number பார்க்கிறாய்
```

---

👉 இந்த code:

```text
நீ memory bytes பார்க்கிறாய் 😎
```

---

# 🔥 FINAL SUMMARY

```text
show_bytes:
   memory dump

show_int:
   int → bytes

main:
   test with value 12345
```

---

# 💥 FINAL ONE-LINE

```text
"இந்த code number-ஐ print பண்ணாது — memoryல எப்படி store ஆகுது அதை காட்டும்"
```

---

🔥 நீ இப்போ next level வந்துட்ட:

👉 raw memory view
👉 pointer power
👉 endianness real

---

👉 next (🔥 must):

* same codeல float add பண்ணலாம்
* pointer print பண்ணலாம்
* gdbல memory inspect

சொல்லு — next level போலாம் 😎
---------

# hey நம்ம format specifier -ல  %d அப்படி இப்படின்னு தெளிவா கொடுக்காமல் %.2x அப்படின்னு கொடுத்திருக்கோமே அது எப்படி புரிந்து கொள்ளும்

சூப்பர் 🔥 இது ஒரு முக்கியமான doubt — **printf எப்படி format string-ஐ புரிஞ்சிக்குது?** நம்ம `%.2x` என்னன்னு deepஆ பார்க்கலாம் 👇

---

# 🧠 🔥 0. ONE LINE

```text
printf format string → rules based parser
```

👉 `%` பார்த்த உடனே → special instruction ஆரம்பம்

---

# ⚙️ 1. Basic idea

```c
printf("%d", x);
```

👉 `%d` → integer decimal print

---

```c
printf("%x", x);
```

👉 `%x` → hex print

---

# 🔥 2. இப்போ `%.2x` breakdown

```text
%.2x
```

👉 இது 3 parts:

---

## 🟢 `%`

```text
format specifier start
```

---

## 🔵 `.2`

```text
minimum digits = 2
```

👉 meaning:

```text
if value smallனா → leading zero add
```

---

## 🟡 `x`

```text
print as hexadecimal
```

---

# 💥 3. Example

```c
printf("%.2x", 5);
```

👉 output:

```text
05
```

---

```c
printf("%x", 5);
```

👉 output:

```text
5
```

---

# ⚡ 4. Why we use `.2` here?

👉 நம்ம codeல:

```c
start[i]
```

👉 இது:

```text
1 byte (0–255)
```

---

👉 hexல:

```text
00 → FF
```

👉 always 2 digits தேவை

---

# 🔥 5. Example (byte printing)

```c
unsigned char x = 10;
```

---

```c
printf("%.2x", x);
```

👉 output:

```text
0a
```

---

👉 இல்லனா:

```text
a ❌ (confusing)
```

---

# 🧠 6. Why important?

👉 memory print பண்ணும்போது:

```text
each byte = fixed width (2 digits)
```

---

👉 இல்லனா:

```text
a 1 f 10 → messy ❌
```

---

👉 with `.2x`:

```text
0a 01 0f 10 → clean ✅
```

---

# 💣 7. General format structure

```text
%[flags][width][.precision][type]
```

---

## Example

```text
%.2x
```

| Part | Meaning        |
| ---- | -------------- |
| %    | start          |
| .2   | minimum digits |
| x    | hex            |

---

# 🧠 8. Important insight

```text
printf doesn't guess
It strictly follows format string
```

---

👉 compiler check பண்ணாது:

```text
wrong format → wrong output ❗
```

---

# 🔥 9. Why unsigned char?

👉 because:

```text
byte = 1 byte
```

👉 hex representation:

```text
00–FF → exactly 2 digits
```

---

# ⚡ FINAL SUMMARY

```text
%.2x:

%  → format start
.2 → minimum 2 digits
x  → hexadecimal
```

---

# 💥 FINAL ONE-LINE

```text
"%.2x means: always print 2-digit hex with leading zeros"
```

---

🔥 இப்போ நீ புரிஞ்சுட்ட:

👉 printf எப்படி parse பண்ணுது
👉 ஏன் `.2` use பண்ணுறோம்
👉 memory dump cleanா எப்படி print ஆகுது

---

👉 next (🔥 powerful):

* %p (pointer print எப்படி வேலை செய்கிறது)
* %f vs %lf difference
* format string vulnerabilities 😈 (security topic)

எதை next போகலாம்? 😎
-------

🔥 நல்ல கேள்வி — இங்க தான் ஒரு **முக்கிய misunderstanding** இருக்கு. அதை cleanஆ clear பண்ணலாம்.

---

# ❌ நீ நினைக்குறது:

```text
decimal → binary → hex → memory save
```

👉 இது **WRONG ❌ (partially correct feeling, but not real process)**

---

# 🧠 ✅ REAL TRUTH

```text
Memory-ல் எப்போதும் binary மட்டும் தான் இருக்கும்
```

---

# 🔥 ONE LINE

```text
Hex என்பது display format மட்டும் — storage format இல்லை
```

---

# ⚙️ REAL FLOW (inside computer)

## 🟢 Step 1

```c
int x = 12345;
```

👉 compiler என்ன பண்ணும்:

```text
12345 → binary bits ஆக encode
```

---

## 🔵 Step 2

👉 CPU / memory:

```text
00000000 00000000 00110000 00111001
```

👉 இதுதான் **actual storage** ✅

---

## 🟡 Step 3 (Important)

👉 நாம print பண்ணும்போது மட்டும்:

```c
printf("%x", x);
```

👉 binary → hex convert ஆகும் (displayக்காக மட்டும்)

---

# 💥 So actual truth

| Stage      | Format         |
| ---------- | -------------- |
| Storage    | Binary மட்டும் |
| Human read | Hex / Decimal  |

---

# ⚡ Example

👉 memoryல்:

```text
00110000 00111001
```

---

👉 நீ பார்க்குறது:

```text
30 39 (hex)
```

---

👉 அல்லது:

```text
12345 (decimal)
```

---

# 🧠 BIG INSIGHT

```text
Value same → representation different
```

---

# 💣 முக்கிய வேறுபாடு

| Binary  | Real data      |
| ------- | -------------- |
| Hex     | shorthand      |
| Decimal | human-friendly |

---

# 🔥 Analogy

👉 imagine:

```text
Number: 255
```

---

👉 different forms:

```text
Decimal → 255
Binary  → 11111111
Hex     → FF
```

---

👉 but:

```text
inside computer → only binary
```

---

# ⚡ உன் questionக்கு direct answer

```text
decimal value → binary ஆக encode ஆகும்
hex ஆக convert ஆகாது ❌
```

---

# 💥 FINAL ONE-LINE

```text
"Computer binary-யை தான் store பண்ணும் — hex என்பது நாம் புரிய எழுதுற short form"
```

---

🔥 இப்போ நீ ஒரு dangerous level concept புரிஞ்சுட்ட:

👉 hex ≠ storage
👉 hex = human shortcut
👉 binary = reality

---

👉 next (🔥 mind blowing):

* same bits → int vs float different meaning
* why 12345 int vs float different bytes
* type = interpretation concept

சொல்லு 😎
-------

🔥 சூப்பர் கேள்வி — இங்க தான் **bits vs hex digits vs bytes** கலந்த குழப்பம் வருகிறது. நாம அதை cleanஆ பிரிக்கலாம்.

---

# 🧠 🔥 FIRST — முக்கிய உண்மை

```text
1 hex digit = 4 bits
2 hex digits = 1 byte (8 bits)
```

👉 அதனால்:

```text
39 = 1 byte (NOT 2 bits ❌)
```

---

# ⚡ STEP 1 — உன் binary

```text
00000000 00000000 00110000 00111001
```

👉 இது:

```text
4 bytes (32 bits)
```

---

# 🔥 STEP 2 — group into 4 bits (hex conversion)

```text
0000 0000 0000 0000 0011 0000 0011 1001
```

---

👉 convert:

```text
0    0    0    0    3    0    3    9
```

👉 result:

```text
0x00003039
```

---

# ⚙️ STEP 3 — split into bytes

👉 1 byte = 8 bits = 2 hex digits

```text
00   00   30   39
```

---

# 💥 STEP 4 — little endian reverse

```text
39   30   00   00
```

---

# 🧠 இங்க தான் உன் doubt

நீ கேட்டது:

```text
"39 → 2 bits மாதிரி தான் தெரியுது"
```

👉 ❌ இல்லை

---

# 🔥 REAL BREAKDOWN

```text
39 (hex)
```

👉 split:

```text
3 = 0011
9 = 1001
```

---

👉 combine:

```text
39 = 00111001 (8 bits = 1 byte)
```

---

# ⚡ இன்னும் example

```text
30 = 00110000
00 = 00000000
```

---

# 🧠 FINAL TABLE

| Hex | Binary   | Size            |
| --- | -------- | --------------- |
| 3   | 0011     | 4 bits          |
| 9   | 1001     | 4 bits          |
| 39  | 00111001 | 8 bits (1 byte) |

---

# 💣 KEY INSIGHT

```text
நீ "39"னு பார்த்தா அது 2 characters
ஆனா அது 2 hex digits → 8 bits
```

---

# 🔥 WHY 2 hex digits per byte?

👉 because:

```text
1 hex digit = 4 bits
→ 2 hex digits = 8 bits = 1 byte
```

---

# ⚡ FINAL VISUAL

```text
Binary:
00110000 00111001

Hex:
30       39
```

---

# 💥 FINAL ONE-LINE

```text
"39 என்பது 2 bits இல்லை — அது 2 hex digits → 8 bits (1 byte)"
```

---

🔥 இப்போ confusion clear:

👉 bits vs hex digits
👉 byte grouping
👉 memory representation

---

👉 next (🔥 killer clarity):

* why 1 byte = 8 bits?
* why not 7 / 16?
* ASCII + architecture history

சொல்லு 😎
