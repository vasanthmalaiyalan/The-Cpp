## 2 Questions — ஒவ்வொன்னா பார்ப்போம்

---

## Question 1 — ஏன் Forward Declaration வேணும்?

Compiler **main() மட்டும் பார்க்காது** — top to bottom எல்லாத்தையும் பார்க்கும்!

```
primary() உள்ளே:
  expression() call பண்றது ← கீழே define ஆகியிருக்கு!

term() உள்ளே:
  primary() call பண்றது ← மேலே இருக்கு ✅
  
expression() உள்ளே:
  term() call பண்றது ← மேலே இருக்கு ✅
```

**Circular dependency:**

```
primary() ──► expression()
   ▲               │
   └──── term() ◄──┘
```

யாரையும் முதலில் define பண்ணினாலும் மற்றதை தெரியாது — **forward declaration வேணும்!**

```cpp
double expression();  // "கீழே இருக்கு, நம்பு" — compiler-க்கு hint
double term();
double primary();
```

---

## Question 2 — ஏன் `while` — `if` இல்லையா?

```cpp
// if போட்டா:
if (t.kind == ';') {
    t = ts.get();   // ஒரே ஒரு ';' skip பண்ணும்
}

// user ";;;1+2" போட்டா:
// first ';' skip ஆகும்
// second ';' skip ஆகாது! ❌
```

```cpp
// while போட்டா:
while (t.kind == ';') {
    t = ts.get();   // எத்தனை ';' இருந்தாலும் skip பண்ணும்
}

// user ";;;1+2" போட்டா:
// ';' ';' ';' எல்லாம் skip ஆகும் ✅
// '1' வந்தா loop நிக்கும்
```

---

## Real Scenario

```
user type பண்றது:
> ;;;1+2;

while loop:
  t = ';' → skip
  t = ';' → skip  
  t = ';' → skip
  t = '1' → loop நிக்கும் ✅
  putback('1')
  expression() → 3
```

---

**Simple rule:**

> Forward declaration — circular calls இருக்கதால் கட்டாயம். `while` — user multiple `;` போட்டாலும் எல்லாத்தையும் skip பண்ண. `if` ஒரே ஒரு `;` மட்டும் skip பண்ணும்.