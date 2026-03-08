ஒவ்வொன்னா deep-ஆ பார்க்கலாம்!

---

## 1️⃣ Stack vs Heap — என்ன வித்தியாசம்?

```
RAM Layout:
┌─────────────────────────┐ High address
│      OS / Kernel        │
├─────────────────────────┤
│                         │
│   Stack  ↓ கீழே வளரும் │ ← automatic, fast
│   ┌─────────────────┐   │
│   │ function frames │   │
│   │ local variables │   │
│   │ return address  │   │
│   └─────────────────┘   │
│         (empty)         │
│   ┌─────────────────┐   │
│   │ malloc() memory │   │
│   │ dynamic data    │   │
│   └─────────────────┘   │
│   Heap   ↑ மேலே வளரும் │ ← manual, flexible
├─────────────────────────┤
│   .rodata               │ ← "Hello, World!" இங்கே
│   .data                 │ ← global variables
│   .text (code)          │ ← assembly instructions
└─────────────────────────┘ Low address
```

---

## Stack என்றால்:

```c
void main() {
    int x = 10;        // Stack-ல் போகும்
    char name[20];     // Stack-ல் போகும்
}
// function முடிந்தால் → automatic-ஆ free!
```

**யார் manage பண்றது?** CPU தானே — push/pop automatically.

**எது போகும்:**
- Local variables
- Function arguments
- Return address
- Saved registers (rbp போன்றவை)

---

## Heap என்றால்:

```c
void main() {
    int *p = malloc(100);  // Heap-ல் போகும்
    // நீயே free பண்ணணும்!
    free(p);
}
```

**யார் manage பண்றது?** Programmer — manually `malloc` / `free`.

**எது போகும்:**
- Runtime-ல் size தெரியும் data
- Big data
- Long-lived data (function முடிந்தாலும் இருக்கணும்)

---

## Stack vs Heap — Quick table:

| | Stack | Heap |
|---|---|---|
| Size | Fixed, small (~8MB) | Large, flexible |
| Speed | Very fast | Slower |
| Manage | CPU automatic | Programmer manual |
| Life | Function உள்ளே மட்டும் | நீ free பண்ணும் வரை |
| Error | Stack overflow | Memory leak |

---

## 2️⃣ `#include` binary/hex → Assembly-ல் என்ன ஆனது?

**நம்ம hello.c-ல் இருந்தது:**

```
Disk-ல் bytes:
# i  n  c  l  u  d  e     < s  t  d  i  o  .  h  >
23 69 6e 63 6c 75 64 65 20 3c 73 74 64 69 6f 2e 68 3e
```

**Assembly-ல் வந்ததா?** ❌ வரவே இல்லை!

```
#include <stdio.h>  →  Preprocessor-ல் உபயோகப்பட்டது
                    →  stdio.h contents copy ஆச்சு
                    →  hello.i-ல் declarations வந்தது
                    →  Compiler அந்த declarations படித்தது
                    →  Assembly-ல் trace இல்லை — gone!
```

---

## 3️⃣ hello.c → Assembly — எல்லாம் என்ன ஆனது?

```
┌─────────────────────────────────────────────────────────────────┐
│                    hello.c (disk-ல் bytes)                      │
├──────────────────┬──────────────────────────────────────────────┤
│ Code             │ Disk bytes (hex)                             │
├──────────────────┼──────────────────────────────────────────────┤
│ #include<stdio.h>│ 23 69 6e 63 6c 75 64 65 ...                 │
│ int main() {     │ 69 6e 74 20 6d 61 69 6e ...                 │
│ printf(          │ 70 72 69 6e 74 66 28 ...                    │
│ "Hello, World!"  │ 48 65 6c 6c 6f 2c 20 57 6f 72 6c 64 21 ... │
│ return 0;        │ 72 65 74 75 72 6e 20 30 ...                 │
│ }                │ 7d                                           │
└──────────────────┴──────────────────────────────────────────────┘
         ↓ Preprocessing
┌─────────────────────────────────────────────────────────────────┐
│                         hello.i                                 │
├──────────────────┬──────────────────────────────────────────────┤
│ #include gone!   │ stdio.h-ஓட 800 lines paste ஆச்சு           │
│ extern printf(..)│ ← இது வந்தது (declaration)                  │
│ int main()...    │ ← உன் code same                             │
└──────────────────┴──────────────────────────────────────────────┘
         ↓ Compilation (cc1)
┌─────────────────────────────────────────────────────────────────┐
│                         hello.s                                 │
├──────────────────┬──────────────────────────────────────────────┤
│ C code           │ Assembly-ல் என்ன ஆனது                       │
├──────────────────┼──────────────────────────────────────────────┤
│ #include         │ ❌ GONE — no trace                           │
│ "Hello, World!"  │ ✅ .rodata → .string "Hello, World!"        │
│ int main()       │ ✅ main: label ஆனது                         │
│ printf(...)      │ ✅ call puts@PLT ஆனது                       │
│ return 0         │ ✅ movl $0, %eax ஆனது                       │
│ { }              │ ✅ pushq/popq/ret ஆனது                      │
└──────────────────┴──────────────────────────────────────────────┘
```

---

## 4️⃣ "Hello, World!" string — எங்கே போனது?

**இது most important!** String-ஓட journey:

```
hello.c disk-ல்:
"Hello, World!\n"
48 65 6c 6c 6f 2c 20 57 6f 72 6c 64 21 0a 00
H  e  l  l  o  ,     W  o  r  l  d  !  \n \0

         ↓ Compiler பார்க்கும்

hello.s-ல்:
.section .rodata        ← read-only data section-ல் வை
.LC0:
    .string "Hello, World!"  ← same string, label கொடு

         ↓ Assembler (step 4)

hello.o binary-ல்:
.rodata section-ல் exact bytes:
48 65 6c 6c 6f 2c 20 57 6f 72 6c 64 21 0a 00
↑ இதுவே disk-ல் இருந்த same bytes — RAM-ல் load ஆகும்!
```

---

## 5️⃣ Complete Journey — ஒரே diagram:

```
┌────────────────────────────────────────────────────────┐
│  hello.c (Text file — disk)                            │
│  '#','i','n','c'... = ASCII bytes                      │
│  'H','e','l','l','o'... = ASCII bytes                  │
└───────────────┬────────────────────────────────────────┘
                │ gcc -E (Preprocessor)
                ▼
┌────────────────────────────────────────────────────────┐
│  hello.i (Text file — disk)                            │
│  #include → GONE                                       │
│  stdio.h contents → PASTED (800 lines)                 │
│  printf declaration → இருக்கு                          │
│  உன் code → same                                       │
└───────────────┬────────────────────────────────────────┘
                │ gcc -S (Compiler cc1)
                ▼
┌────────────────────────────────────────────────────────┐
│  hello.s (Text file — disk)                            │
│  C syntax → GONE                                       │
│  "Hello,World!" → .rodata section-ல்                  │
│  main() → main: label                                  │
│  printf() → call puts@PLT                              │
│  return 0 → movl $0,%eax                               │
│  இன்னும் TEXT — binary இல்லை!                         │
└───────────────┬────────────────────────────────────────┘
                │ as (Assembler) — Step 4
                ▼
┌────────────────────────────────────────────────────────┐
│  hello.o (Binary file — disk)                          │
│  .text:   f3 0f 1e fa 55 48 89 e5 ...  ← opcodes      │
│  .rodata: 48 65 6c 6c 6f 2c 20 57 ...  ← string bytes │
│  இப்போது BINARY — human படிக்க முடியாது!              │
└───────────────┬────────────────────────────────────────┘
                │ ld (Linker) — Step 5
                ▼
┌────────────────────────────────────────────────────────┐
│  hello (Executable — disk)                             │
│  puts@PLT → libc.so connected                         │
│  addresses → resolved                                  │
└───────────────┬────────────────────────────────────────┘
                │ ./hello (Run)
                ▼
┌────────────────────────────────────────────────────────┐
│  RAM (Memory)                                          │
│  Stack:  main() frame, return address                  │
│  Heap:   (நம்ம program use பண்றதில்லை)                │
│  .text:  f3 0f 1e fa ... ← CPU execute பண்றது         │
│  .rodata: "Hello, World!" bytes ← CPU படிக்கும்        │
└───────────────┬────────────────────────────────────────┘
                │
                ▼
        Terminal: Hello, World! ✅
```

இப்போது `#include` முதல் terminal வரை எல்லாம் clear-ஆ புரிஞ்சதா? 🎯

----------

இதோ — ஒரே diagram-ல் full flow!

```
═══════════════════════════════════════════════════════════════
              RAM - Full Picture (Program run ஆகும்போது)
═══════════════════════════════════════════════════════════════

High Address
┌─────────────────────────────────────────────────────────┐
│                    OS / Kernel                          │
├─────────────────────────────────────────────────────────┤
│                                                         │
│  STACK (↓ கீழே வளரும்)                                 │
│  ┌───────────────────────────────────────────────┐      │
│  │          [1] Program START                    │      │
│  │  ┌─────────────────────────────┐              │      │
│  │  │       OS frame              │              │      │
│  │  │  rbp ──────────────────→ [OS frame base]  │      │
│  │  │  return address (to OS)     │              │      │
│  │  └─────────────────────────────┘              │      │
│  │                ↓ main() call                  │      │
│  │                                               │      │
│  │          [2] pushq %rbp                       │      │
│  │  ┌─────────────────────────────┐              │      │
│  │  │  [old rbp - OS frame addr] │ ← rsp        │      │
│  │  ├─────────────────────────────┤              │      │
│  │  │       OS frame              │              │      │
│  │  └─────────────────────────────┘              │      │
│  │       OS-ஓட rbp value save ஆச்சு!             │      │
│  │                                               │      │
│  │          [3] movq %rsp,%rbp                   │      │
│  │  ┌─────────────────────────────┐              │      │
│  │  │  [old rbp]      ← rsp,rbp  │ main() frame │      │
│  │  ├─────────────────────────────┤  ready!      │      │
│  │  │       OS frame              │              │      │
│  │  └─────────────────────────────┘              │      │
│  │                                               │      │
│  │          [4] leaq + movq (registers)          │      │
│  │                                               │      │
│  │  CPU Registers:                               │      │
│  │  ┌──────┬──────────────────────────────────┐  │      │
│  │  │ rax  │ = 0x2004 ("Hello,World!" address)│  │      │
│  │  │ rdi  │ = 0x2004 (puts()-க்கு argument)  │  │      │
│  │  │ rbp  │ = main() frame base              │  │      │
│  │  │ rsp  │ = stack current top              │  │      │
│  │  │ rip  │ = இப்போது execute ஆகும் address  │  │      │
│  │  └──────┴──────────────────────────────────┘  │      │
│  │                                               │      │
│  │          [5] call puts@PLT                    │      │
│  │  ┌─────────────────────────────┐              │      │
│  │  │     puts() frame            │ ← rsp        │      │
│  │  │  (internal puts variables)  │              │      │
│  │  ├─────────────────────────────┤              │      │
│  │  │  return address             │              │      │
│  │  │  (puts முடிந்தவுடன் இங்கே) │              │      │
│  │  ├─────────────────────────────┤              │      │
│  │  │  [old rbp]       ← rbp     │ main() frame │      │
│  │  ├─────────────────────────────┤              │      │
│  │  │       OS frame              │              │      │
│  │  └─────────────────────────────┘              │      │
│  │     puts() running...                         │      │
│  │     rdi → 0x2004 → "Hello,World!" படிக்கும்  │      │
│  │     write() syscall → kernel → terminal print │      │
│  │                                               │      │
│  │          [6] puts() returns                   │      │
│  │  ┌─────────────────────────────┐              │      │
│  │  │  [old rbp]       ← rsp,rbp │ ← rsp        │      │
│  │  ├─────────────────────────────┤              │      │
│  │  │       OS frame              │              │      │
│  │  └─────────────────────────────┘              │      │
│  │     puts() frame GONE!                        │      │
│  │                                               │      │
│  │          [7] movl $0,%eax                     │      │
│  │  ┌──────┬──────────────────────────────────┐  │      │
│  │  │ eax  │ = 0  (return 0 ready)            │  │      │
│  │  └──────┴──────────────────────────────────┘  │      │
│  │                                               │      │
│  │          [8] popq %rbp                        │      │
│  │  ┌─────────────────────────────┐              │      │
│  │  │       OS frame   ← rsp     │              │      │
│  │  │  rbp → OS frame base again │              │      │
│  │  └─────────────────────────────┘              │      │
│  │     main() frame GONE!                        │      │
│  │                                               │      │
│  │          [9] ret                              │      │
│  │     return address எடு → OS-க்கு jump        │      │
│  │     OS → eax=0 பார்க்கும் → SUCCESS!         │      │
│  │     Process terminate!                        │      │
│  └───────────────────────────────────────────────┘      │
│                                                         │
│  HEAP (↑ மேலே வளரும்)                                  │
│  ┌───────────────────────────────────────────────┐      │
│  │  (நம்ம program malloc பண்றதில்லை — EMPTY)    │      │
│  └───────────────────────────────────────────────┘      │
│                                                         │
├─────────────────────────────────────────────────────────┤
│  .rodata  (Read Only)                                   │
│  ┌───────────────────────────────────────────────┐      │
│  │  0x2004: 48 65 6c 6c 6f 2c 20 57 6f 72 6c    │      │
│  │          H  e  l  l  o  ,     W  o  r  l     │      │
│  │          64 21 0a 00                          │      │
│  │          d  !  \n \0                          │      │
│  │          ↑                                    │      │
│  │         .LC0 label → "Hello, World!"          │      │
│  └───────────────────────────────────────────────┘      │
│                                                         │
├─────────────────────────────────────────────────────────┤
│  .text  (Code — Execute ஆகும் instructions)             │
│  ┌───────────────────────────────────────────────┐      │
│  │  f3 0f 1e fa → endbr64                        │      │
│  │  55          → pushq %rbp                     │      │
│  │  48 89 e5    → movq %rsp,%rbp                 │      │
│  │  48 8d 05 .. → leaq .LC0(%rip),%rax           │      │
│  │  48 89 c7    → movq %rax,%rdi                 │      │
│  │  e8 .. .. .. → call puts@PLT                  │      │
│  │  b8 00 00 00 → movl $0,%eax                   │      │
│  │  5d          → popq %rbp                      │      │
│  │  c3          → ret                            │      │
│  └───────────────────────────────────────────────┘      │
│                                                         │
Low Address                                               │
└─────────────────────────────────────────────────────────┘

Terminal Output:
┌─────────────────┐
│ Hello, World!   │  ✅
└─────────────────┘
═══════════════════════════════════════════════════════════════
```

**Key Takeaway:**

```
Stack  → functions, frames, registers — temporary, auto cleanup
Heap   → malloc data — manual, நம்ம program use பண்றதில்லை
.rodata → "Hello,World!" string — permanent, read only
.text  → opcodes — CPU இதை மட்டுமே execute பண்ணும்!
```

இப்போது ஒரே பார்வையில் எல்லாமே புரிஞ்சதா? 🎯