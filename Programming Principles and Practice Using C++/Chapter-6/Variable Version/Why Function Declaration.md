`கம்பெனில compail time -ல பார்க்கும் போது get_value() இந்த மாதிரி அதற்கு கீழே எழுதப்பட்டுள்ள ஃபங்க்ஷன் எல்லாம் declare செய்யாமல் இருப்பதால் ஏன் டிக்ளர் செய்யவில்லை என்று கேட்டு எரர் வராதா`

## நல்ல Question! 🎯

---

## Code Order பாரு

```cpp
// இந்த order-ல இருக்கு:

double get_value(std::string s) { }      // line 1 — define
bool is_declared(std::string var) { }    // line 2 — define  
double define_name(std::string var) { }  // line 3 — define

// ...

double primary() {
    get_value(t.name);   // ← இங்க call பண்றோம்
}
```

`get_value()` — **primary()-க்கு மேலே define ஆகியிருக்கு!**

---

## அதனால் Forward Declaration தேவையில்ல!

```
Compiler top-to-bottom படிக்கும்:

get_value()   → define ✅ தெரியும்
is_declared() → define ✅ தெரியும்
define_name() → define ✅ தெரியும்

primary():
  get_value() call → already தெரியும் ✅ — error இல்ல!
```

---

## Forward Declaration எப்போ வேணும்?

```cpp
// Circular calls இருந்தா மட்டும்:

double primary() {
    expression();  // ← கீழே இருக்கு, தெரியாது!
}

double expression() {
    primary();     // ← மேலே இருக்கு, தெரியும்
}
```

```
அதனால்:
double expression();  // ← forward declaration வேணும்!
double term();
double primary();
```

---

**Simple rule:**

> Compiler top-to-bottom படிக்கும் — மேலே define ஆனது கீழே call பண்ணலாம், forward declaration தேவையில்ல. `get_value()`, `is_declared()`, `define_name()` எல்லாம் `primary()`-க்கு மேலே இருக்கு — compiler already தெரியும்!

---------------

``get_value(), is_declared(), define_name() எல்லாம் primary()-க்கு மேலே இருக்கு — compiler already தெரியும்!`compailer மேலே இருந்து படிக்கும்போது `get_value(), is_declared(), define_name(`இதைத்தானே முதலில் பார்க்கும் இது எங்கும் டிக்ளேர் செய்யப்படவில்லையே`

## ஆமா! ஆனா Define = Declaration!

---

## Declaration vs Definition

```cpp
// Declaration மட்டும் — body இல்ல:
double get_value(std::string s);  // ← just declaration

// Definition — body இருக்கு:
double get_value(std::string s)   // ← declaration + definition
{                                  //   இரண்டும் சேர்ந்து!
    for (const Variable& v : var_table) {
        ...
    }
}
```

---

## Key Point

```
Definition = Declaration + Body

Definition பார்த்தாலே compiler-க்கு:
  return type தெரியும் ✅
  parameters தெரியும் ✅
  body தெரியும் ✅
```

---

## Compiler என்ன பார்க்கும்?

```
line 1: double get_value(std::string s) { }
        ↑
        "get_value என்ற function இருக்கு,
         string எடுக்கும், double return பண்ணும்"
        compiler-க்கு தெரிஞ்சுவிட்டது! ✅

line 2: primary() உள்ளே get_value() call
        already தெரியும் → error இல்ல! ✅
```

---

**Simple rule:**

> Forward declaration தனியா போட தேவையில்ல — **definition-யே declaration!** Compiler function பார்த்தவுடன் "இந்த function இருக்கு" note பண்ணும். மேலே define ஆனது கீழே call பண்ணலாம் — தனியா declare தேவையில்ல!

----------
`
`இதே மாதிரி `Definition = Declaration + Body`இதுவும் இதே மாதிரி செய்யலாம் தானே `double expression();  // ← forward declaration வேணும்!
double term();
double primary();`ஏன் தனியாக டிக்ளரேசன் செய்கிறார்கள்`

`

## ஏன் தனியா Declaration வேணும்?

---

## Problem — Circular Calls!

```cpp
double primary() {
    expression();  // ← expression() கீழே இருக்கு!
}

double term() {
    primary();     // ← primary() மேலே இருக்கு ✅
}

double expression() {
    term();        // ← term() மேலே இருக்கு ✅
}
```

---

## Compiler Top-to-Bottom படிக்கும்:

```
primary() define:
  expression() call → இன்னும் பார்க்கலை! ❌ ERROR!
```

---

## யாரை மேலே போட்டாலும் Problem!

```
primary() மேலே போட்டா:
  expression() தெரியாது ❌

expression() மேலே போட்டா:
  term() தெரியாது ❌

term() மேலே போட்டா:
  primary() தெரியாது ❌
```

**எந்த order-லயும் fix ஆகாது!**

---

## அதனால் Forward Declaration!

```cpp
// முதலில் எல்லாரையும் declare பண்ணு:
double expression();   // "இருக்கு, கீழே இருக்கு"
double term();         // "இருக்கு, கீழே இருக்கு"
double primary();      // "இருக்கு, கீழே இருக்கு"

// இப்போ எந்த order-லயும் define பண்ணலாம்:
double primary() {
    expression();  // ✅ already declared!
}
```

---

## `get_value()` ஏன் தேவையில்ல?

```
get_value()  →  primary() call பண்றது இல்ல
primary()    →  get_value() call பண்றது

One-way! Circular இல்ல → forward declaration தேவையில்ல!
```

---

**Simple rule:**

> `get_value()` = one-way call, மேலே define — forward declaration தேவையில்ல. `primary/term/expression` = circular calls — யாரை மேலே போட்டாலும் மற்றது தெரியாது — forward declaration கட்டாயம்!