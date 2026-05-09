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