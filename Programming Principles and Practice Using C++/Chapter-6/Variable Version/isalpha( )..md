🔥 Excellent question.
`isalpha()` என்பது C/C++ல் மிகவும் பழமையான மற்றும் முக்கியமான character checking function.

இதுதான் நம்ம calculatorல்:

```cpp id="’wini08"
let x = 10;
```

இதில்:

```text id="’wini09"
x
let
```

இவை variable name / keywordஆ என்பதை கண்டுபிடிக்க உதவுகிறது.

---

# 📘 `isalpha()` என்றால் என்ன?

`isalpha()` checks:

```text id="’wini10"
“இந்த character ஒரு alphabet letterஆ?”
```

---

# ✅ True ஆகும்

```text id="’wini11"
a
b
Z
X
```

---

# ❌ False ஆகும்

```text id="’wini12"
1
@
#
7
```

---

# 📘 Header

```cpp id="’wini13"
#include <cctype>
```

---

# 📘 Syntax

```cpp id="’wini14"
isalpha(character)
```

---

# 🧪 Example

```cpp id="’wini15"
#include <iostream>
#include <cctype>

int main()
{
    char ch = 'A';

    if (isalpha(ch)) {
        std::cout << "Alphabet\n";
    }
    else {
        std::cout << "Not alphabet\n";
    }
}
```

---

# ▶️ Output

```text id="’wini16"
Alphabet
```

---

# 🧠 Calculatorல் இது ஏன் தேவை?

நம்ம calculatorல் user type பண்ணுவார்:

```text id="’wini17"
let x = 10;
```

Program first character read பண்ணும்:

```cpp id="’wini18"
char ch;
std::cin >> ch;
```

Suppose:

```text id="’wini19"
l
```

---

# ❓ இப்போது எப்படி தெரியும்?

இது:

* numberஆ?
* operatorஆ?
* variable nameஆ?

---

# 💡 Solution

```cpp id="’wini20"
if (std::isalpha(ch))
```

👉 alphabet என்றால்:

```text id="’wini21"
variable / keyword start
```

---

# 📘 Calculator Code

```cpp id="’wini22"
if (std::isalpha(ch)) {

    std::string s;

    s += ch;

    while (std::cin.get(ch) &&
           (std::isalpha(ch) || std::isdigit(ch))) {

        s += ch;
    }

    std::cin.putback(ch);

    if (s == "let") {
        return Token{let};
    }

    return Token{name, s};
}
```

---

# 🧠 What happens here?

Input:

```text id="’wini23"
let
```

---

## Flow

First:

```text id="’wini24"
l
```

👉 `isalpha(l)` = true

---

Then loop builds:

```text id="’wini25"
"let"
```

---

Then checks:

```cpp id="’wini26"
if (s == "let")
```

👉 keyword token.

---

# 🟢 Other Related Functions

C/C++ has many similar functions.

---

# 🔹 `isdigit()`

Checks:

```text id="’wini27"
0-9
```

---

# 🔹 `isalnum()`

Checks:

```text id="’wini28"
alphabet OR digit
```

---

# 🔹 `isspace()`

Checks:

```text id="’wini29"
space
tab
newline
```

---

# 🔹 `islower()`

```text id="’wini30"
a-z
```

---

# 🔹 `isupper()`

```text id="’wini31"
A-Z
```

---

# 🧪 Small Demo

```cpp id="’wini32"
#include <iostream>
#include <cctype>

int main()
{
    char ch;

    std::cin >> ch;

    if (isalpha(ch)) {
        std::cout << "Alphabet\n";
    }

    if (isdigit(ch)) {
        std::cout << "Digit\n";
    }
}
```

---

# ▶️ Input

```text id="’wini33"
A
```

Output:

```text id="’wini34"
Alphabet
```

---

# ▶️ Input

```text id="’wini35"
7
```

Output:

```text id="’wini36"
Digit
```

---

# 💥 Real Importance

இந்த functions heavily use ஆகும்:

✔️ compilers
✔️ parsers
✔️ interpreters
✔️ lexers/tokenizers
✔️ input validation

---

# 🎯 Hidden Big Lesson

`isalpha()` போன்ற functions தான்:

```text id="’wini37"
raw text → meaningful tokens
```

மாற்ற உதவுகிறது.

🔥 அதுதான் programming language internals ஆரம்பம்.
