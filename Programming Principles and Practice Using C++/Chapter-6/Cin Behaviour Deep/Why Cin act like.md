## ஏன் `\n` Skip பண்ண Design பண்ணார்கள்?

---

## Real-world Use Case பாரு

```cpp
int a, b, c;
std::cin >> a >> b >> c;
```

User எப்படி போட்டாலும் work ஆகணும்:

```
// One line:
10 20 30

// Multiple lines:
10
20
30

// Mixed:
10 20
30
```

**எல்லாமே same result** — `a=10, b=20, c=30`

---

## `\n` Skip இல்லன்னா?

```cpp
// \n skip இல்லன்னா:
std::cin >> a;  // 10 படிக்கும்
std::cin >> b;  // \n படிக்கும்! b = ???  ❌
std::cin >> c;  // 20 படிக்கும்
```

Programmer-க்கு nightmare — ஒவ்வொரு `\n`-ஐயும் manually handle பண்ணணும்!

---

## Historical Reason

```
1970s — Unix terminals:
  Enter = newline = "line complete"
  ஆனா data separator இல்ல!

cin Design:
  "whitespace = separator, not data"
  programmer-க்கு easy ஆகணும்!
```

---

## அதனால் 2 Types of Input இருக்கு

```cpp
// Formatted input — whitespace skip:
std::cin >> ch;    // \n, space, tab skip

// Unformatted input — every byte படிக்கும்:
std::cin.get(ch);  // \n-உம் படிக்கும்!
```

---

## Calculator-ல `cin.get()` போட்டா?

```cpp
// \n-ஐயும் படிக்கும்:
std::cin.get(ch);

// 1+2 enter:
get() → '1' ✅
get() → '+' ✅
get() → '2' ✅
get() → '\n' ✅ → default hit → return 3 → print! ✅
// ';' தேவையில்ல!
```

ஆனா **problem:**

```
"1  +  2" → spaces-ஐயும் படிக்கும்
' ' → default → Bad token error! ❌
```

---

**Simple rule:**

> `cin >>` = programmer convenience-க்காக whitespace skip — 1970s Unix design. Data-ஐ space/newline வச்சு separate பண்றது natural. `;` அதனால் வேணும் — valid token-ஆ "end" சொல்ல. `cin.get()` use பண்ணினா `\n` படிக்கும் — ஆனா spaces handle பண்ண வேற logic வேணும்!

`அதாவது இப்படி போட்டாள் `'\n'` white space - ஆக எடுத்துக் கொள்கிறது`

## ஆமா! Exactly!

---

## `cin` Design Rule

```
whitespace characters:
  ' '  → space
  '\t' → tab  
  '\n' → newline   ← enter போட்டா இது வருது
```

**எல்லாமே cin-க்கு "இடைவெளி" மட்டும் — data இல்ல!**

---

## அதனால் என்ன ஆகுது?

```
User: 1+2 [Enter]

cin பார்க்கும்:
[1] → data ✅ படிக்கும்
[+] → data ✅ படிக்கும்
[2] → data ✅ படிக்கும்
[\n] → whitespace! ❌ skip, wait...
```

---

## Simple-ஆ சொன்னா

```
cin >> ch போட்டா:

"data வா" என்று காத்திருக்கும்
whitespace வந்தா → "இது data இல்ல, skip" → காத்திருக்கும்
valid char வந்தா → "இது data!" → படிக்கும்
```

---

**One line:**

> `'\n'` = Enter key = whitespace = cin-க்கு "இடைவெளி" மட்டும் — data இல்ல. அதனால் skip பண்ணி next valid character வரும் வரை wait பண்ணும். `;` போட்டாதான் valid token — உடனே படிக்கும்!