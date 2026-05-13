`static_cast<void*>(&grade), இதற்கு என்ன அர்த்தம் ?`


## `static_cast<void*>(&grade)` — breakdown

```cpp
char grade = 'A';
static_cast<void*>(&grade)
```

இதை இப்படி படிக்கணும்:

---

### Step by step

**`&grade`** → `grade` variable-ஓட memory address. Type: `char*`

**`static_cast<void*>(...)`** → அந்த `char*` pointer-ஐ `void*` pointer-ஆ **type மாத்து** — address value மாறாது, type மட்டும் மாறும்.

---

### `static_cast` என்றால் என்ன?

C++ compile-time cast. Compiler-கிட்ட சொல்றோம்:

> *"இந்த value-ஐ நான் சொல்ற type-ஆ treat செய்"*

```cpp
char*  →  void*   ✓  // allowed, safe
void*  →  char*   ✓  // allowed
int*   →  char*   ✓  // allowed  
int*   →  float*  ✗  // static_cast refuse செய்யும் (unsafe)
```

`void*` என்பது **"type இல்லாத raw pointer"** — எந்த pointer-ஐயும் `void*`-ஆ மாத்தலாம், safe.

---

### C-style cast vs static_cast

```cpp
(void*)&grade        // C-style — works, but blunt
static_cast<void*>(&grade)  // C++ style — same result, but compiler checks பண்ணும்
```

இரண்டும் same output. ஆனா `static_cast` preferred in C++ because:
- Unsafe cast-ஐ compiler reject செய்யும்
- Code-ல் தெளிவா தெரியும் — "intentional cast இது"

---

### Memory-ல் என்ன நடக்குது?

```
&grade        =  0x7ffee410   (char*  — cout இதை string-ஆ படிக்கும்)
(void*)&grade =  0x7ffee410   (void*  — cout இதை address-ஆ print செய்யும்)
```

**Address மாறல — type label மட்டும் மாறுது.**