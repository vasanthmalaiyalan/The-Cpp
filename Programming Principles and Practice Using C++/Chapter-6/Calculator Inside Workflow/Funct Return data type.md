`எதற்காக நாம் `Token get();` இந்த get() funct -னுக்கு return data type Token -னை கொடுத்தோம் void பயன்படுத்திருக்கலாமே`

## ஏன் `Token` Return Type வேணும்?

---

## `void` போட்டா என்ன ஆகும்?

```cpp
void get();  // ← nothing return பண்ணாது

// caller-ல:
Token t = ts.get();  // ❌ void-ஐ assign பண்ண முடியாது!
```

---

## `Token` Return Type ஏன் வேணும்?

`get()` call பண்ணும் இடத்தை பாரு:

```cpp
// primary()-ல:
Token t = ts.get();   // ← Token வேணும்!

// term()-ல:
Token t = ts.get();   // ← Token வேணும்!

// expression()-ல:
Token t = ts.get();   // ← Token வேணும்!

// main()-ல:
Token t = ts.get();   // ← Token வேணும்!
```

எல்லா இடத்திலும் `get()`-ஓட result-ஐ `Token t`-க்கு assign பண்றோம்!

---

## `get()` என்ன பண்றது?

```cpp
Token Token_stream::get()
{
    // cin-லிருந்து படிக்கும்
    // Token object create பண்ணும்
    return Token{ch};        // ← Token return பண்றது!
    return Token{'8', val};  // ← Token return பண்றது!
}
```

---

## Simple Analogy

```
void get()    = "போய் வா" — கையில் எதுவும் இல்லாம வருவான்
Token get()   = "போய் token எடுத்து வா" — token கொண்டு வருவான்
```

---

**Simple rule:**

> `get()` = cin-லிருந்து படிச்சு Token create பண்ணி **caller-க்கு கொடுக்கணும்**. `void` போட்டா return பண்ண முடியாது — caller `Token t = ts.get()` எழுத முடியாது. Function என்ன return பண்றதோ அதுவே return type!