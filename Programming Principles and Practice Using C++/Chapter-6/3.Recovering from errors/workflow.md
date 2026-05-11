## Full Code — என்ன நடக்குது?

---

## New Features — Previous Version-ஓட வித்தியாசம்

---

### 1. `constexpr` Symbolic Constants

```cpp
constexpr char number = '8';
constexpr char quit   = 'q';
constexpr char print  = ';';
constexpr const char* prompt = "> ";
constexpr const char* result = "= ";
```

Compile time-லயே fix ஆகும் — magic numbers இல்ல, readable code!

---

### 2. `ignore()` — New Function!

```cpp
void Token_stream::ignore(char c)
{
    // buffer-ல இருக்கா check:
    if (full && buffer.kind == c) {
        full = false;
        return;
    }

    full = false;

    // cin-லிருந்து ';' வரும் வரை எல்லாத்தையும் discard:
    char ch = 0;
    while (std::cin >> ch) {
        if (ch == c) return;
    }
}
```

**Error வந்தா** — bad input-ஐ `;` வரும் வரை skip பண்ணும்!

---

### 3. `calculate()` — Separate Function

```cpp
void calculate()
{
    while (std::cin)
    try {
        // expression evaluate
    }
    catch (std::exception& e) {
        std::cerr << e.what() << '\n';
        clean_up_mess();   // ← error recovery!
    }
}
```

Error வந்தாலும் **program continue** பண்ணும் — previous version-ல crash ஆகும்!

---

## Input Examples — என்ன நடக்கும்?

### Case 1 — Normal: `1+2;`
```
> 1+2;
= 3
>         ← மீண்டும் input கேக்கும்
```

### Case 2 — Error Recovery: `1+@;`
```
> 1+@;
Bad token    ← error print
             ← ignore() ';' வரும் வரை skip
>            ← program continue! ✅ crash இல்ல!
```

### Case 3 — Multiple: `1+2; 3*4;`
```
> 1+2; 3*4;
= 3
>
= 12
```

### Case 4 — Quit: `q`
```
> q
            ← program end
```

---

## Previous vs இந்த Version

| Feature | Previous | இந்த Version |
|---|---|---|
| Error வந்தா | crash, exit | recover, continue ✅ |
| Error cleanup | இல்ல | `ignore()` ✅ |
| Loop | main-ல | `calculate()`-ல ✅ |
| Constants | `'q'`, `';'` hardcoded | `constexpr` ✅ |

---

## `clean_up_mess()` — Key Feature

```
Error: "1+@;"

ignore(';') call:
  '@' discard
  ';' வந்தா stop

Next iteration:
  fresh start! ✅
```

---

**Simple rule:**

> இந்த version-ல error வந்தாலும் program die ஆகாது — `catch` பிடிக்கும், `ignore()` bad input clear பண்ணும், loop continue ஆகும். Real-world calculator மாதிரி robust!

-------------

ஆம் 🔥
அந்த `return;` முழுமையாக வேலை செய்யும்.

இது எந்த function உள்ளே இருக்கிறது?

```cpp id="09bjlwm"
void Token_stream::ignore(char c)
```

👉 இந்த function-இலிருந்து வெளியே return ஆகும்.

---

# 🧠 `void` function என்றால்?

```cpp id="10bjlwm"
void
```

அதாவது:

```text id="11bjlwm"
“இந்த function value எதையும் return செய்யாது”
```

---

# அதனால்:

```cpp id="12bjlwm"
return;
```

என்றால்:

```text id="13bjlwm"
“function-ஐ இங்கேயே நிறுத்தி வெளியே போ”
```

---

# 🧪 Example Flow

Input:

```text id="14bjlwm"
1+*2; 4+5;
```

---

# Error வந்தது:

```text id="15bjlwm"
primary expected
```

---

# Then:

```cpp id="16bjlwm"
clean_up_mess();
```

calls:

```cpp id="17bjlwm"
ts.ignore(print);
```

---

# So now:

```cpp id="18bjlwm"
ignore(';')
```

---

# Inside ignore()

---

## Step 1

```cpp id="19bjlwm"
while (std::cin >> ch)
```

reads characters one-by-one:

---

# Reads:

```text id="20bjlwm"
*
```

---

# Check:

```cpp id="21bjlwm"
if (ch == c)
```

👉 `* == ';'` ❌

continue loop.

---

# Next read:

```text id="22bjlwm"
2
```

---

Again:

```cpp id="23bjlwm"
2 == ';'
```

❌

---

# Next read:

```text id="24bjlwm"
;
```

---

Now:

```cpp id="25bjlwm"
if (ch == c)
```

✔️ TRUE

---

# Then:

```cpp id="26bjlwm"
return;
```

---

# 🔥 What happens now?

Function immediately exits:

```text id="27bjlwm"
Token_stream::ignore()
END
```

---

# Control returns to caller

அதாவது:

```cpp id="28bjlwm"
clean_up_mess()
```

க்கு திரும்பும்.

---

# Then:

```cpp id="29bjlwm"
calculate()
```

loop continue ஆகும்.

---

# 🧠 Important Concept

`return;`

👉 current function execution stop பண்ணும்.

---

# 💡 Equivalent Meaning

```cpp id="30bjlwm"
return;
```

means:

```text id="31bjlwm"
“I'm done. Go back to whoever called me.”
```

---

# 🧪 Another Small Example

```cpp id="32bjlwm"
void hello()
{
    std::cout << "A\n";

    return;

    std::cout << "B\n";
}
```

---

# Output

```text id="33bjlwm"
A
```

---

# Why `B` not printed?

Because:

```cpp id="34bjlwm"
return;
```

function execution immediately stop பண்ணிவிட்டது.

---

# 🟢 In Your `ignore()` Function

இந்த line:

```cpp id="35bjlwm"
return;
```

means:

```text id="36bjlwm"
“Found the ';'
cleanup finished
go back”
```

---

# 🔥 Very Important Understanding

`return` does NOT:

* stop whole program ❌
* stop calculate() ❌
* stop main() ❌

It ONLY exits:

```cpp id="37bjlwm"
ignore()
```

function மட்டும்.

---

# 🧠 Full Call Stack

```text id="38bjlwm"
calculate()
    ↓
clean_up_mess()
    ↓
ignore()
        ↓
        return;
    ↑
clean_up_mess() finished
↑
calculate() continues
```

🔥 இது தான் actual execution flow.
