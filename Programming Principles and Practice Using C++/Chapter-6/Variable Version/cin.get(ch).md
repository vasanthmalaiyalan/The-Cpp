🔥 Excellent question.
`cin.get(ch)` என்பது C++ input systemல் மிகவும் முக்கியமான low-level character reading function.

நம்ம calculator tokenizerல இதை பயன்படுத்தினோம்:

```cpp id="’winb05"
while (std::cin.get(ch) &&
       (std::isalpha(ch) || std::isdigit(ch)))
{
    s += ch;
}
```

இதுதான்:

```text id="’winb06"
let
variable123
abc99
```

போன்ற words build செய்ய உதவுகிறது.

---

# 📘 `cin.get(ch)` என்றால் என்ன?

இதன் வேலை:

```text id="’winb07"
inputலிருந்து EXACTLY ஒரு character read செய்
```

---

# 🟢 Syntax

```cpp id="’winb08"
std::cin.get(ch);
```

---

# 💡 Meaning

Keyboard/input streamலிருந்து:
👉 next character எடுத்துக்கொண்டு
👉 `ch` உள்ளே store செய்யும்.

---

# 🧪 Example

```cpp id="’winb09"
#include <iostream>

int main()
{
    char ch;

    std::cin.get(ch);

    std::cout << ch << '\n';
}
```

---

# ▶️ Input

```text id="’winb10"
A
```

---

# ▶️ Output

```text id="’winb11"
A
```

---

# 🧠 Difference Between `>>` and `.get()`

VERY IMPORTANT 🔥

---

# 🟢 `>>`

```cpp id="’winb12"
std::cin >> ch;
```

👉 skips whitespace.

Meaning:

* space skip
* newline skip
* tab skip

---

# 🟢 `.get()`

```cpp id="’winb13"
std::cin.get(ch);
```

👉 reads EVERYTHING.

Even:

* spaces
* newline
* tab

---

# 🧪 Demo

```cpp id="’winb14"
#include <iostream>

int main()
{
    char ch;

    std::cin.get(ch);

    if (ch == ' ') {
        std::cout << "SPACE\n";
    }
    else {
        std::cout << ch << '\n';
    }
}
```

---

# ▶️ Input

(space key)

---

# ▶️ Output

```text id="’winb15"
SPACE
```

🔥 `>>` இருந்தால் இது impossible.

---

# 🧠 Why Calculator Uses `.get()`

Suppose input:

```text id="’winb16"
let123
```

First:

```cpp id="’winb17"
std::cin >> ch;
```

reads:

```text id="’winb18"
'l'
```

---

Now we must continue reading:

```text id="’winb19"
e
t
1
2
3
```

one-by-one.

That is why:

```cpp id="’winb20"
std::cin.get(ch)
```

inside loop.

---

# 🟢 Flow

Input stream:

```text id="’winb21"
l e t 1 2 3
```

---

# Step 1

```cpp id="’winb22"
cin >> ch;
```

reads:

```text id="’winb23"
l
```

---

# Step 2

loop:

```cpp id="’winb24"
cin.get(ch)
```

reads:

```text id="’winb25"
e
```

append:

```text id="’winb26"
"le"
```

---

# Step 3

reads:

```text id="’winb27"
t
```

append:

```text id="’winb28"
"let"
```

---

# Step 4

reads:

```text id="’winb29"
1
```

append:

```text id="’winb30"
"let1"
```

---

🔥 character-by-character tokenizer building.

---

# 🧠 Another Important Thing

This expression:

```cpp id="’winb31"
std::cin.get(ch)
```

returns stream object itself.

That allows:

```cpp id="’winb32"
while (std::cin.get(ch))
```

---

# 💡 Meaning

Loop continues UNTIL:

* EOF
* input failure

---

# 🧪 Example

```cpp id="’winb33"
#include <iostream>

int main()
{
    char ch;

    while (std::cin.get(ch)) {

        std::cout << ch << '\n';
    }
}
```

---

# 💥 This reads entire input stream character-by-character.

---

# 🟢 Related Functions

---

# `cin.putback(ch)`

Put character BACK into stream.

---

# `cin.peek()`

Look next character WITHOUT consuming.

---

# `getline(cin, s)`

Read whole line.

---

# 🎯 Simple Tamil Summary

```cpp id="’winb34"
cin.get(ch)
```

👉 inputலிருந்து:

```text id="’winb35"
ஒரு character exactஆ read செய்கிறது
```

---

Difference:

| Function      | Space Skip? |
| ------------- | ----------- |
| `cin >> ch`   | YES         |
| `cin.get(ch)` | NO          |

---

🔥 tokenizer/parser/compiler codeல:

```text id="’winb36"
cin.get()
```

மிகவும் common.
