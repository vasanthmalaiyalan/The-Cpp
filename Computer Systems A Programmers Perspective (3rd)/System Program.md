
# 🖥️ A Tour of Computer Systems

---

## 1️⃣ இந்த Chapter என்ன சொல்லுகிறது

```
Computer system-ஐ ஒரு tour போல introduce செய்கிறது
Computer system முழுவதும் எப்படி வேலை செய்கிறது என்று overview
```

---

## 2️⃣ Computer System என்றால் என்ன

**Hardware — Physical parts:**
```
CPU
RAM
Disk
Keyboard
Monitor
```

**System Software — Hardware-ஐ control செய்து programs run செய்ய உதவும்:**
```
Operating system
Compiler
Linker
Loader
Shell
```

✔ இந்த இரண்டும் சேர்ந்து தான் → application programs run செய்ய முடியும்

---

## 3️⃣ Implementation Change ஆகும், Concepts Change ஆகாது

**Computer technology காலத்துடன் மாறுகிறது:**
```
CPU architecture change
OS versions change
hardware speed increase
```

**ஆனால்:**
```
basic concepts same தான் இருக்கும்
```

**எல்லா computers-லும்:**
```
CPU
Memory
Storage
OS
```

✔ இவை இருக்கும் — அதனால் concepts கற்றுக்கொண்டால் எந்த future system-ஐயும் புரிந்துகொள்ள முடியும்

---

## 4️⃣ இந்த புத்தகம் யாருக்காக

```
இந்த புத்தகம் → programmers காக எழுதப்பட்டது
```

**Goal:**
```
computer system எப்படி வேலை செய்கிறது
அது program correctness மற்றும் performance-ஐ எப்படி பாதிக்கிறது
```

---

## 5️⃣ "Power Programmer" என்ற Idea

**இந்த புத்தகம் படித்தால் → Power Programmer ஆக முடியும்**

```
system internals தெரியும்
performance optimize செய்ய தெரியும்
bugs root cause கண்டுபிடிக்க தெரியும்
```

```
ordinary programmer → system-aware programmer
```

---

## 6️⃣ இந்த புத்தகம் கற்றுக்கொடுக்கும் Practical Skills

---

### (1) Strange Numerical Errors Avoid செய்ய

```
Computers numbers-ஐ special format-ல் represent செய்கிறது
Example: floating-point representation

இதனால் unexpected errors வரும்
Example: 0.1 + 0.2 ≠ 0.3
```

---

### (2) C Code Optimization

**Modern processors:**
```
pipelines
cache
branch prediction
out-of-order execution
```

✔ இந்த hardware design பயன்படுத்தி C programs fast ஆக எழுதலாம்

---

### (3) Procedure Calls Compiler எப்படி Implement செய்கிறது

```c
foo();
```

**Compile ஆன பிறகு compiler பயன்படுத்துவது:**
```
stack
registers
memory
```

---

### (4) Buffer Overflow Security Problems

```c
char buf[10];
gets(buf);
```

```
Buffer overflow → network software-ல் common vulnerability
attackers exploit செய்ய முடியும்
```

✔ எப்படி வருகிறது + எப்படி avoid செய்வது — explain செய்யும்

---

### (5) Linking Errors

**Compile செய்த பிறகு → Linking stage**

**Common errors:**
```
undefined reference
multiple definition
```

✔ Average programmers confuse ஆகிவிடுவார்கள் — இந்த புத்தகம் linking process explain செய்யும்

---

### (6) Real Systems Programs எழுத கற்றுக்கொடுக்கும்

**Projects:**
```
Unix shell
dynamic memory allocator
Web server
```

✔ அதாவது OS level programs

---

### (7) Concurrency

**Modern CPUs:**
```
4 core
8 core
16 core
→ programs parallel run செய்யலாம்
```

✔ benefits + dangers (race conditions) இரண்டையும் explain செய்யும்

---

## 7️⃣ Hello Program Example

```c
#include <stdio.h>

int main()
{
    printf("hello, world\n");
    return 0;
}
```

**Output:**
```
hello, world
```

---

## 8️⃣ Hello Program Simple தான் ஆனால் System முழுவதும் வேலை செய்ய வேண்டும்

**Run ஆக இவை எல்லாம் வேலை செய்ய வேண்டும்:**
```
editor
compiler
linker
OS
CPU
memory
terminal
```

---

## 9️⃣ இந்த புத்தகத்தின் Goal

```
Hello program run ஆகும்போது
computer system-ல் என்ன நடக்கிறது என்று explain செய்வது
```

---

## 🔟 Hello Program Lifetime

```
1️⃣ Programmer code எழுதுகிறார்
2️⃣ Source file save செய்கிறார்
3️⃣ Compiler compile செய்கிறது
4️⃣ Linker libraries இணைக்கிறது
5️⃣ OS program load செய்கிறது
6️⃣ CPU instructions execute செய்கிறது
7️⃣ Output screen-ல் print ஆகிறது
```

---

## 1️⃣1️⃣ Computer Information எப்படி Store செய்கிறது

```
Computer text-ஐ நேரடியாக store செய்யாது
அது store செய்வது → bits

bit = 0 or 1

எல்லா information-மும் bits ஆக தான் இருக்கும்
```

---

## 1️⃣2️⃣ ASCII Representation

**Text characters → numbers ஆக represent செய்யப்படும்:**
```
h = 104
e = 101
l = 108
o = 111
```

**`hello` store ஆகும்:**
```
104  101  108  108  111
```

✔ இதற்கு → ASCII encoding

---

## 1️⃣3️⃣ hello.c File எப்படி Memory-ல் இருக்கும்

**`#include <stdio.h>` → ASCII numbers:**
```
# = 35
i = 105
n = 110
c = 99
```

✔ source code → numbers

---

## 1️⃣4️⃣ Information = Bits + Context

**இந்த chapter-ல் வரும் powerful concept:**

```
Information = Bits + Context
```

**Example:**
```
01000001

Context இல்லாமல் → meaningless

ASCII context   → 'A'
Integer context → 65
```

✔ Context meaning decide செய்கிறது

---

## 1️⃣5️⃣ இந்த Chapter என்ன செய்யும்

**Hello program example மூலம் introduce செய்வது:**
```
machine code
memory
linking
OS
networking
```

---

## 📌 Final Summary

```
Computer system = hardware + system software

Programmers system internals புரிந்துகொள்ள வேண்டும்

Simple Hello program run ஆக → system முழுவதும் work செய்கிறது

Computer information → bits ஆக store செய்யப்படுகிறது

Meaning = bits + context
```

---

## 💡 Core Journey of This Book

```
C code
  ↓
compiler
  ↓
assembly
  ↓
machine code
  ↓
CPU
  ↓
memory
  ↓
OS
  ↓
terminal output
```