`இது என்ன புதுசா `bool full {false};
    Token buffer {'0'};` அதாவது நான் இதுவரை இப்படித்தான் பார்த்துள்ள `bool full = false`இப்படி அசைன் செய்து தான் பார்த்து உள்ளேன்?`

 ## இரண்டும் Same — வேற Syntax மட்டும்!

---

## 3 Ways to Initialize

```cpp
// Way 1 — Assignment (உனக்கு familiar)
bool full = false;
Token buffer = Token{'0'};

// Way 2 — Brace initialization (new style)
bool full {false};
Token buffer {'0'};

// Way 3 — Parenthesis
bool full(false);
Token buffer('0');
```

**மூன்றும் same result** — compiler-க்கு வித்தியாசமே இல்ல!

---

## ஏன் `{}` Modern C++?

```cpp
// = இல்ல ஒரு trap இருக்கு:
int x = 3.14;   // ✅ compile ஆகும் — 3 ஆகிடும்! data loss ❌

// {} போட்டா compiler catch பண்ணும்:
int x {3.14};   // ❌ error! — narrowing conversion not allowed
```

`{}` = **type-safe** — wrong type போட்டா compiler error தரும்.

---

## Class-ல போடும்போது

```cpp
class Token_stream {
    bool full {false};    // member initialization
    Token buffer {'0'};   // object create ஆகும்போதே initialize
};
```

இது **constructor இல்லாமலும்** default values போட முடியும்:

```cpp
// Constructor இல்லன்னா:
Token_stream ts;
// full = false  ✅ (garbage இல்ல!)
// buffer = '0'  ✅
```

---

**Simple rule:**

> `bool full = false` = `bool full {false}` — same result. `{}` modern C++ style — type-safe, narrowing conversion catch பண்ணும். Class members-ல `{}` போட்டா constructor இல்லாமலும் safe default values கிடைக்கும்.   