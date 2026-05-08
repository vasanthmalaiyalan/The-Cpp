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

`int கூட நாம் return type ஆக போட முடியாது காரணம் char கலந்துள்ளது அதனால் class உருவாக்கி அத உள்ளே என்ன டேட்டா டைப்பை போடுகிறோமோ அது நிறைய கலந்து கூட இருக்கலாம் அதனால் அந்த கிளாஸ் உடைய பெயர் ஆகிய like Token அந்தப் பெயரை போடுவதன் மூலம் அதில் கலந்துள்ள அத்தனை டேட்டா டைப்பிலும் support செய்கிறது என்று அர்த்தம்? அப்புறம் இதற்கு காரணம் `Token t = ts.get() எழுத` எந்த டோக்கன் ரிட்டர்ன் டைப்பை call செய்கிறோமோ `Token t` அதை ரிட்டன் செய்வதற்கு `ts.get()` அந்த டோக்கன் ரிட்டன் டைப் பால் உருவாக்கப்பட்ட funct வேணும் அல்லவா?`

## ஆமா! 100% சரிதான்! 🎯

---

## உன் First Point — Class = Multiple Types Bundle

```cpp
class Token {
    char kind;    // 1 byte
    double value; // 8 bytes
};
```

```
int    → ஒரே type, single value மட்டும்
char   → ஒரே type, single value மட்டும்

Token  → char + double = இரண்டும் சேர்ந்து ஒரு unit! ✅
```

`Token` return type போட்டா — `kind` + `value` **இரண்டும் சேர்ந்து** return ஆகும்!

---

## உன் Second Point — Type Match வேணும்

```cpp
Token t = ts.get();
```

இதை இப்படி படிக்கலாம்:

```
Token t       ← "Token type variable வேணும்"
=
ts.get()      ← "Token return பண்ற function வேணும்"
```

```
return type match:
Token get() → Token return ✅ → Token t-க்கு assign ✅

int get()   → int return ❌ → Token t-க்கு assign முடியாது!
void get()  → nothing ❌   → assign பண்ணவே முடியாது!
```

---

## Simple Visual

```
get() உள்ளே:
┌─────────────────────┐
│ Token{'8', 3.14}    │ → return
│  kind  = '8'        │
│  value = 3.14       │
└─────────────────────┘
         ↓
Token t = ts.get()
┌─────────────────────┐
│ t.kind  = '8'       │ ← இரண்டும் வந்துவிட்டன! ✅
│ t.value = 3.14      │
└─────────────────────┘
```

---

**Simple rule:**

> Class = multiple types-ஐ ஒரே unit-ஆ bundle பண்றது. அந்த class-ஐ return type-ஆ போட்டா உள்ளே இருக்கற எல்லா data-உம் சேர்ந்து return ஆகும். `Token t = ts.get()` — left side type, right side return type **match ஆகணும்** — அதனால் `Token` return type கட்டாயம்!