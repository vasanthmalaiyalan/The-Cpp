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