`ஏன் இதற்கு `if (t.kind != ')') {
            throw std::runtime_error("')' expected");` இந்த வகையான error பயன்படுத்தி உள்ளோம் `runtime_error` இதை பயன்படுத்தலாமே `catch (std::exception& e)
{
    std::cerr << "Error: " << e.what() << '\n';
    return 1;` cerr, மொத்தம் எத்தனை error-கள் உள்ளது ஒவ்வொன்றுக்கும் என்ன வித்தியாசம் எதை எப்போது பயன்படுத்துவது போன்ற விவரங்களை தெள்ளத் தெளிவாக கொடு`

 ## C++ Exception Hierarchy — Full Picture

---

## எத்தனை Types இருக்கு?

```
std::exception                    ← parent (base)
    │
    ├── std::logic_error           ← code logic தப்பு
    │       ├── std::invalid_argument
    │       ├── std::out_of_range
    │       ├── std::length_error
    │       └── std::domain_error
    │
    ├── std::runtime_error         ← runtime-ல தப்பு
    │       ├── std::overflow_error
    │       ├── std::underflow_error
    │       └── std::range_error
    │
    ├── std::bad_alloc             ← memory fail
    ├── std::bad_cast              ← type cast fail
    └── std::bad_exception         ← unknown exception
```

---

## ஒவ்வொன்னும் என்ன?

### `logic_error` — Code-ல தப்பு (programmer mistake)
```cpp
// Program run ஆகும் முன்னாடியே தெரியும் தப்பு

std::invalid_argument  // wrong argument போட்டா
std::out_of_range      // array boundary தாண்டினா
std::length_error      // string too long
std::domain_error      // math domain தப்பு (sqrt(-1))
```

### `runtime_error` — Runtime-ல தப்பு (unexpected)
```cpp
// Program run ஆகும்போது தெரியும் தப்பு

std::overflow_error    // number too large
std::underflow_error   // number too small
std::range_error       // result out of range
```

---

## Calculator-ல ஏன் `runtime_error`?

```cpp
// User input-ல தப்பு — compile time-ல தெரியாது!
// Runtime-லதான் தெரியும்!

throw std::runtime_error("')' expected");
throw std::runtime_error("divide by zero");
throw std::runtime_error("Bad token");
```

```
')' missing   → user type பண்ணும்போது தெரியும் ← runtime ✅
divide by zero → calculation time-ல தெரியும்    ← runtime ✅
Bad token      → user wrong char போட்டா தெரியும் ← runtime ✅
```

---

## எதை எப்போது Use பண்றது?

```cpp
// invalid_argument — function-க்கு wrong value போட்டா
void setAge(int age) {
    if (age < 0)
        throw std::invalid_argument("Age cannot be negative");
}

// out_of_range — boundary தாண்டினா
void getElement(int index) {
    if (index >= size)
        throw std::out_of_range("Index out of range");
}

// runtime_error — user input, file, network தப்பு
Token Token_stream::get() {
    if (bad_input)
        throw std::runtime_error("Bad token");
}

// bad_alloc — memory fail (auto throw, நீ throw பண்ண வேண்டாம்)
int* p = new int[999999999];  // auto throws bad_alloc
```

---

## catch எப்படி போடுவது?

```cpp
// Specific catch — ஒரே type மட்டும்
catch (std::invalid_argument& e) { }
catch (std::out_of_range& e) { }

// General catch — எல்லா std exceptions
catch (std::exception& e) {
    std::cerr << e.what() << '\n';  // ← எல்லாரும் what() இருக்கு
}

// Everything catch — non-std exceptions-உம்
catch (...) { }
```

---

## உன் Code-ல Pattern

```cpp
// throw specific type:
throw std::runtime_error("Bad token");

// catch parent type:
catch (std::exception& e) {    // runtime_error parent = exception
    std::cerr << e.what();     // "Bad token" print ஆகும்
}
```

`runtime_error` → `exception`-ஓட child — parent catch பண்ணும் ✅

---

## Quick Reference Table

| Exception | எப்போது | Example |
|---|---|---|
| `invalid_argument` | Wrong parameter | age < 0 |
| `out_of_range` | Boundary cross | index >= size |
| `runtime_error` | User input/file error | Bad token |
| `overflow_error` | Number too big | int overflow |
| `bad_alloc` | Memory fail | new fail |
| `logic_error` | Code logic தப்பு | algorithm bug |

---

**Simple rule:**

> User input தப்பு → `runtime_error`. Code logic தப்பு → `logic_error` or specific child. Boundary தாண்டினா → `out_of_range`. எல்லாத்தையும் catch பண்ண → `std::exception&`. Calculator-ல user input handle பண்றோம் → `runtime_error` correct choice!   