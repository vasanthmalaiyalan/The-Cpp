## `cin` ஏன் `\n` Skip பண்ணும்?

---

## `cin >>` Design-யே இப்படி!

`cin >>` operator = **formatted input** — இது whitespace-ஐ separator-ஆ treat பண்ணும்:

```
whitespace = space ' '
           = tab '\t'
           = newline '\n'
```

எல்லாமே **"இடைவெளி"** — data இல்ல, separator மட்டும்.

---

## ஏன் இப்படி Design பண்ணார்கள்?

```
User type பண்றது:
"1    +    2"   ← spaces
"1\t+\t2"      ← tabs
"1\n+\n2"      ← newlines

எல்லாமே same meaning:
1 + 2 = 3
```

Programmer-க்கு convenient-ஆ இருக்கணும் — spaces/newlines எத்தனை போட்டாலும் work ஆகணும்!

---

## அதனால் என்ன ஆகுது?

```cpp
char ch;
std::cin >> ch;
```

```
cin buffer: [\n][\n][ ][+]

cin >> ch:
  '\n' → skip!
  '\n' → skip!
  ' '  → skip!
  '+' → ✅ ch = '+'
```

**Valid character வரும் வரை skip பண்ணும் — block ஆகும்!**

---

## `1+2` enter போட்டா:

```
cin buffer: [1][+][2][\n]

get() → '1' ✅ (valid)
get() → '+' ✅ (valid)
get() → '2' ✅ (valid)
get() → '\n' → SKIP! next valid char வரும் வரை wait ⏳
```

`\n` = data இல்ல — cin-க்கு "இன்னும் input வரும்" என்று தெரியும்!

---

## `;` போட்டா:

```
cin buffer: [1][+][2][;][\n]

get() → ';' ✅ (valid — whitespace இல்ல!)
default hit → return 3 → print ✅
```

`;` = valid character — skip ஆகாது, உடனே read ஆகும்!

---

**Simple rule:**

> `cin >>` = whitespace (`\n`, space, tab) separator-ஆ treat பண்ணும் — "இன்னும் data வரும்" என்று wait பண்ணும். `;` whitespace இல்ல — valid token, உடனே read ஆகும். அதனால் `;` இல்லன்னா `cin` next valid input வரும் வரை block ஆகும்!