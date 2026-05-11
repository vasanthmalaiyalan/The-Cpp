## ஆமா! ஆனா ஒரு Important Point!

---

## `t` என்ன இருக்கு?

```cpp
while (true) {
    Token t = ts.get();  // ← loop-ல ஒவ்வொரு iteration-லயும் NEW token படிக்கும்!
```

---

## `1+2` Trace

### First iteration:
```
t = ts.get() → '+' படிக்கும்

case '+':
  left += term()  → '2' படிக்கும், left = 3
  break           → switch exit, loop மீண்டும்!
```

### Second iteration:
```
t = ts.get() → '\n' skip... wait ⏳
```

---

## உன் Question — `t` உள்ளே `+` இருக்கா?

**இல்ல!** — Second iteration-ல `t` new token படிக்கும்:

```
First iteration:  t = '+'  ← case '+' handle
break             ← switch exit

Second iteration: t = ts.get() ← AGAIN படிக்கும்!
                  t = '\n' skip → wait ⏳
```

`+` போயிடுது — `t` overwrite ஆகுது!

---

## `;` போட்டா:

```
First iteration:
  t = '+' → case '+' → left = 3 → break

Second iteration:
  t = ts.get() → ';' ✅
  default:
    ts.putback(';')  ← ';' buffer-ல
    return 3         ← print! ✅
```

---

**Simple rule:**

> `break` = switch exit, loop மீண்டும் ஓடும். Next iteration-ல `t = ts.get()` மீண்டும் படிக்கும் — `+` போயிடுது, new token வருது. `\n` வந்தா skip+wait, `;` வந்தா default hit → return!