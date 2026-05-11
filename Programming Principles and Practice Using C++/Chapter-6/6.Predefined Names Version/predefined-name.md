🔥 Excellent — now the calculator gets another REAL language feature:

# 📘 §6.8.3 Predefined Names

This section teaches:

```text id="jlwm106"
Languages can start with built-in variables/constants
```

🔥 EXACTLY like real programming languages.

The uploaded section explains how predefined constants like `pi` and `e` are added before the calculator starts running. 

---

# 🧠 Core Idea

Instead of forcing user to write:

```text id="’wini107"
let pi = 3.1415926535;
```

every time,

the calculator automatically knows:

```text id="’wini108"
pi
e
```

---

# 🟢 Real Languages Also Do This

Examples:

| Language    | Built-in          |
| ----------- | ----------------- |
| Python      | `True`, `False`   |
| JavaScript  | `Math.PI`         |
| C++         | library constants |
| calculators | `pi`, `e`         |

---

# 🟢 Where Should We Define Them?

Book asks:

```text id="’wini109"
main() ?
or
calculate() ?
```

---

# 💡 Correct Answer

Inside:

```cpp id="’wini110"
main()
```

---

# 🧠 Why?

Because:

```text id="’wini111"
pi and e are global setup,
NOT part of one calculation
```

🔥 VERY good architecture thinking.

---

# 🟢 Predefined Constants

Book adds:

```cpp id="’wini112"
define_name("pi", 3.1415926535);
define_name("e",  2.7182818284);
```

---

# 💡 Meaning

Before calculator loop starts:

```text id="’wini113"
var_table already contains:
("pi", 3.1415926535)
("e",  2.7182818284)
```

---

# 🟢 Result

Now user can directly type:

```text id="’wini114"
pi * 2;
```

🔥 works immediately.

---

# 📘 FULL UPDATED `.cpp` CODE (Predefined Names Version)

Only `main()` changes.

---

# 📘 Updated `main()`

```cpp id="’wini115"
// -----------------------------------------------------------------------------
// Main
// -----------------------------------------------------------------------------

int main()
try
{
    // predefined constants

    define_name("pi", 3.1415926535);

    define_name("e", 2.7182818284);

    calculate();

    return 0;
}

catch (std::exception& e)
{
    std::cerr << "Fatal error: "
              << e.what()
              << '\n';

    return 1;
}

catch (...)
{
    std::cerr << "Unknown fatal error\n";

    return 2;
}
```

---

# 🧪 Example

```text id="’wini116"
> pi;
= 3.14159

> e;
= 2.71828

> pi * 2;
= 6.28319

> e * 10;
= 27.1828

> let radius = 5;
= 5

> pi * radius * radius;
= 78.5398
```

---

# 💥 HUGE SOFTWARE ENGINEERING LESSON

This section teaches:

```text id="’wini117"
Programs often need initialization/setup phase
```

🔥 VERY important architecture concept.

---

# 🟢 Real Program Analogy

Before application starts:

Programs often:

* load configs
* initialize database
* preload constants
* allocate memory
* setup environment

Exactly same idea 😄

---

# 🎯 Final Professional Insight

Your calculator is now becoming:

```text id="’wini118"
a tiny interpreter
```

Because it now has:
✔️ lexer
✔️ parser
✔️ symbol table
✔️ variables
✔️ predefined names
✔️ grammar
✔️ runtime evaluation
✔️ error recovery

🔥 These are CORE compiler/interpreter concepts.
