இரண்டு நல்ல கேள்விகள்! ஒவ்வொன்னா பார்க்கலாம்.

---

## கேள்வி 1: ஏன் `.c` பயன்படுத்துகிறோம், `.i` பயன்படுத்தலாமே?

**நீங்கள் சொன்னது 100% சரி!** `.i` பயன்படுத்தலாம்:

```bash
gcc -S hello.c -o hello.s    # இதுவும் work ஆகும்
gcc -S hello.i -o hello.s    # இதுவும் same result!
```

**GCC internally என்ன செய்யும்:**
```
gcc -S hello.c கொடுத்தால்:
    hello.c → [preprocessing] → hello.i → [compilation] → hello.s
                ↑
            Automatically இதை செய்துவிடும்!

gcc -S hello.i கொடுத்தால்:
    hello.i → [compilation] → hello.s
              ↑
          Preprocessing skip! Direct போகும்
```

நாம் தனியா `-E` run பண்ணியது **படிக்கவும் புரியவும்** — real world-ல் நேரடியாக `gcc hello.c` என்று ஒரே command போதும்!

---

## கேள்வி 2: நம்ம `.c` code exact-ஆ இந்த assembly-ஆக மாறுமா?**ஆமா — exact-ஆ இதுதான்!** இப்போதுதான் run பண்ணினேன். இரண்டையும் compare பண்ணலாம்:

---

## நம்ம hello.c → Assembly mapping:

```c
// hello.c                    // hello.s
#include <stdio.h>        →   .section .rodata
                              .LC0: .string "Hello, World!"
                              ↑ string எங்கே store ஆகும்

int main() {              →   main:
                              endbr64        ; function start

    printf("Hello!\n");   →   leaq .LC0(%rip), %rax  ; string address load
                              movq %rax, %rdi          ; argument ready
                              call puts@PLT            ; printf → puts call

    return 0;             →   movl $0, %eax           ; return value = 0
}                         →   popq %rbp
                              ret                      ; function end
```

---

## Extra lines என்ன? — நீங்கள் கவலைப்படலாம்

Document-ல் காட்டியதை விட extra lines இருக்கு:

```asm
.cfi_startproc
.cfi_def_cfa_offset 16
.cfi_offset 6, -16
.LFB0:
.LFE0:
```

இவை எல்லாம் **debug information** — crash ஆனால் எங்கே ஆனது என்று கண்டுபிடிக்க. CPU execute செய்வதில்லை — ignore செய்யலாம்.

---

## ஒரு முக்கியமான விஷயம் — `printf` → `puts` ஆனது ஏன்?

```c
// நாம் எழுதியது:
printf("Hello, World!\n");

// Assembly-ல் வந்தது:
call puts@PLT              // printf இல்ல, puts!
```

**GCC smart-ஆக optimize பண்ணியது!**

```
printf("Hello!\n")  →  format specifier இல்ல (%d, %s இல்ல)
                    →  simple string மட்டுமே
                    →  puts() போதும்! (faster, simpler)
                    →  GCC automatically மாற்றியது
```

நாம் `printf` எழுதினோம், GCC `puts`-ஆக மாற்றியது — **compiler நம்மை விட smart!**

---

## Summary

```
.c → .i → .s என்பது:

hello.c (human language)
    "printf Hello World, return 0"
         ↓ GCC cc1 compiler
hello.s (CPU near language)  
    "string இங்கே வை, address load பண்ணு,
     puts call பண்ணு, 0 return பண்ணு"
         ↓
இன்னும் text — ஆனால் CPU instructions ready!
Binary இல்லை — அது step 4-ல்!
```

Step 3 clear-ஆ புரிஞ்சதா? 🎯