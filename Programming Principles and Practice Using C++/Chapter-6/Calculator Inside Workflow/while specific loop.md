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