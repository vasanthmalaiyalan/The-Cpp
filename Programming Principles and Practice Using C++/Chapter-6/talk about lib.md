## நல்ல Question! 🎯

---

## `cout` — Trailing Zeros Remove பண்ணும்!

```cpp
double x = 3.0;
std::cout << x;  // → "3" print ஆகும், "3.0" இல்ல!

double y = 3.14;
std::cout << y;  // → "3.14" print ஆகும்

double z = 3.10;
std::cout << z;  // → "3.1" print ஆகும், "3.10" இல்ல!
```

`cout` default-ஆ **unnecessary zeros remove** பண்ணும்.

---

## ஏன் இப்படி?

`cout` internally **6 significant digits** மட்டும் print பண்ணும்:

```cpp
double x = 3.0;
// significant digits: 3 மட்டும்
// trailing zero தேவையில்ல → "3" print
```

---

## `3.0` print பண்ணணும்னா?

```cpp
#include <iomanip>

std::cout << std::fixed << std::setprecision(1) << 3.0;
// → "3.0" ✅

std::cout << std::fixed << std::setprecision(2) << 3.0;
// → "3.00" ✅
```

---

## Memory-ல இருப்பது vs Print ஆவது

```
Memory:
double x = 3.0
[0 00000000000 0000...0000]  ← IEEE 754 format, 3.0 exactly store

Print:
cout << x → "3"  ← display convenience மட்டும்
                    memory-ல 3.0-தான் இருக்கு!
```

---

**Simple rule:**

> Memory-ல `3.0` — ஆனா `cout` default-ஆ trailing zeros remove பண்ணி `3` print பண்ணும். `std::fixed << std::setprecision(1)` போட்டா `3.0` print ஆகும். Display convenience மட்டும் — actual value மாறாது!