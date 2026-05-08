`அதாவது கம்பைளர் `Forward Declaration வேணும்?
Compiler main() மட்டும் பார்க்காது — top to bottom எல்லாத்தையும் பார்க்கும்!
primary() உள்ளே:
  expression() call பண்றது ← கீழே define ஆகியிருக்கு!

term() உள்ளே:
  primary() call பண்றது ← மேலே இருக்கு ✅
  
expression() உள்ளே:
  term() call பண்றது ← மேலே இருக்கு ✅
Circular dependency:
primary() ──► expression()
   ▲               │
   └──── term() ◄──┘
யாரையும் முதலில் define பண்ணினாலும் மற்றதை தெரியாது — forward declaration வேணும்!
double expression();  // "கீழே இருக்கு, நம்பு" — compiler-க்கு hint
double term();
double primary();` compail time-la மேல இருந்ததா பார்க்க ஆரம்பிக்கும் அதனால் மேலே நாம் declaration செய்து சொல்ல வேண்டும் கம்பைலருக்கு அப்படித்தானே அதே மாதிரி  runtime la தான் main மட்டும் கம்பைளர் பார்க்கும்?`

## ஆமா! Exactly சரிதான்! 🎯

---

## 2 Phases — தெளிவாக பாரு

### Phase 1 — Compile Time (Top to Bottom)

```
Compiler source code-ஐ மேலிருந்து கீழே படிக்கும்:

line 1: class Token { }          → Token type தெரியும் ✅
line 2: class Token_stream { }   → Token_stream தெரியும் ✅
line 3: double expression();     → "இருக்கு, கீழே இருக்கு" ✅
line 4: double term();           → "இருக்கு, கீழே இருக்கு" ✅
line 5: double primary();        → "இருக்கு, கீழே இருக்கு" ✅
line 6: primary() define         → expression() call — தெரியும் ✅
line 7: term() define            → primary() call — தெரியும் ✅
line 8: expression() define      → term() call — தெரியும் ✅
line 9: main() define            → எல்லாம் தெரியும் ✅
```

**Compile time = source code check மட்டும் — execute ஆகாது!**

---

### Phase 2 — Runtime (main() மட்டும்)

```
Program execute ஆகும்போது:

main() start ஆகும்          ← entry point
  expression() call
    term() call
      primary() call
```

**Runtime = main()-லிருந்து மட்டும் execute ஆகும்!**

---

## Simple Summary

```
Compile time:
  Compiler   → source code top to bottom படிக்கும்
  Forward declaration → "இந்த function கீழே இருக்கு" hint

Runtime:
  CPU        → main()-லிருந்து மட்டும் execute ஆகும்
  Functions  → call ஆகும்போது மட்டும் run ஆகும்
```

---

**Simple rule:**

> Compile time = compiler source code-ஐ top to bottom check பண்ணும் — forward declaration அதற்காக. Runtime = main()-லிருந்து மட்டும் execute ஆகும் — functions call ஆகும்போது மட்டும் run ஆகும். இரண்டும் different phases!