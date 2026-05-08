``while (t.kind == ';') {
    t = ts.get(); `இப்படி வந்துட்டாலே program முடிந்துவிட்டது தானே? அப்புறம் எதற்காக மீண்டும் buffer la ஏதேனும் இருக்கிறதா என்று பார்க்க `t = ts.get(); செல்கிறது? அப்புறம் இதில் போடப்பட்டது போல் `if (t.kind == 'q') {
            return 0;
        }` return 0 என்றதும் லூப் நின்று விடுமா?`

 ## 2 Questions — ஒவ்வொன்னா பார்ப்போம்

---

## Question 1 — ஏன் `t = ts.get()` மீண்டும் போகுது?

`;` வந்தா program முடியாது — **next expression கேக்கும்!**

```cpp
while (std::cin) {        // ← loop தொடரும்!

    Token t = ts.get();

    while (t.kind == ';') {
        t = ts.get();     // ← next token கேக்கும்
    }
```

User multiple expressions போடலாம்:

```
> 1+2;        ← first expression
= 3
> 4*5;        ← second expression
= 20
> q           ← quit
```

`;` = "இந்த expression முடிஞ்சது, next பாரு" — program end இல்ல!

---

## `;` loop என்ன பண்ணும்?

```
user ";;;1+2" போட்டா:

t = ';' → while: t = ts.get()
t = ';' → while: t = ts.get()
t = ';' → while: t = ts.get()
t = '1' → while நிக்கும்!
putback('1')
expression() → 3
```

---

## Question 2 — `return 0` loop நிக்குமா?

**ஆமா — loop மட்டும் இல்ல, entire function exit!**

```cpp
if (t.kind == 'q') {
    return 0;    // main() function-யே exit!
}
```

```
return 0 = main() exit
         = program end
         = எல்லா loops-உம் போயிடும் ✅
```

`break` vs `return 0` வித்தியாசம்:

```cpp
break;      // while loop மட்டும் exit
            // main() தொடரும்

return 0;   // main() function-யே exit
            // program முடியும்
```

---

**Simple rule:**

> `;` = expression separator — program end இல்ல, next expression கேக்கும். `return 0` = main() exit = program end — loop, function எல்லாம் போயிடும்.  

---

`என்னதான் `loop என்ன பண்ணும்?
user ";;;1+2" போட்டா:

t = ';' → while: t = ts.get()
t = ';' → while: t = ts.get()
t = ';' → while: t = ts.get()
t = '1' → while நிக்கும்!
putback('1')
expression() → 3` while உள்ளே இருக்கும் obj t- க்கு value assign ஆனாலும் அது மேல இருக்கும் இதற்கும் சேர்த்து பொருந்துகிறது `Token t = ts.get();` அதனால்தான் இது வேலை செய்கிறது `putback('1')`?`

## ஆமா! Exactly சரிதான்! 🎯

---

## Same `t` object — while உள்ளேயும் வெளியேயும்!

```cpp
Token t = ts.get();          // ← இந்த t

while (t.kind == ';') {
    t = ts.get();            // ← same t-ஐ update பண்றோம்!
}

// while முடிஞ்சவுடன் t = '1' (last value)

ts.putback(t);               // ← '1' putback பண்றோம் ✅
```

`t` ஒரே object — while உள்ளே update ஆகுது, வெளியேயும் same `t`!

---

## Memory-ல என்ன நடக்குது?

```
Token t = ts.get() → t.kind = ';'

Stack:
┌─────────────┐
│ t.kind = ';'│ ← first value
└─────────────┘

while loop:
t = ts.get() → t.kind = ';'
┌─────────────┐
│ t.kind = ';'│ ← overwrite
└─────────────┘

t = ts.get() → t.kind = ';'
┌─────────────┐
│ t.kind = ';'│ ← overwrite
└─────────────┘

t = ts.get() → t.kind = '1'
┌─────────────┐
│ t.kind = '1'│ ← overwrite
└─────────────┘

while நிக்கும் — t.kind = '1' ✅
```

---

## அதனால் `putback(t)` சரியா வேலை செய்யும்

```cpp
ts.putback(t);   // t.kind = '1' — சரியான value! ✅
expression();    // '1' buffer-லிருந்து படிக்கும் ✅
```

---

**Simple rule:**

> `t` same object — while உள்ளே `t = ts.get()` போட்டா same `t`-ஐ overwrite பண்ணும். Loop முடிஞ்சவுடன் `t`-ல last read value இருக்கும் — அதை `putback` பண்றோம். அதனால் `expression()` correct token படிக்கும்!