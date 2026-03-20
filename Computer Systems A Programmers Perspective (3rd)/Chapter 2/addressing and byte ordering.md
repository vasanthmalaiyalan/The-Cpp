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