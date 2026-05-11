🔥 மிக நல்ல கேள்வி.
இப்போது நீ syntax levelல இல்லாமல்:

```text id="jlwm75"
“இந்த architecture ஏன்?”
```

என்ற levelல் யோசிக்க ஆரம்பித்துவிட்டாய். அதுதான் real programming 🔥

---

# 📘 இந்த Calculator Program என்ன செய்கிறது?

இது ஒரு:

```text id="jlwm76"
Expression Evaluator / Mini Interpreter
```

---

# 💡 Meaning

User type செய்யும் mathematical expressionஐ:

```text id="jlwm77"
parse
analyze
evaluate
```

செய்து answer கொடுக்கிறது.

---

# 🧪 Example

Input:

```text id="’wini78"
(10 + 5) * 2
```

Program internally:

```text id="’wini79"
Tokenize
↓
Parse grammar
↓
Evaluate precedence
↓
Return result
```

Output:

```text id="’wini80"
30
```

---

# 🔥 இந்த Program எந்த Problem Solve செய்கிறது?

Book ஆரம்பத்தில் சொன்ன original problem:

```text id="’wini81"
“Get computer to do arithmetic expressions”
```

---

# 💡 Real Meaning

இந்த program solve செய்வது:

✔️ operator precedence
✔️ parentheses
✔️ variables
✔️ expression parsing
✔️ error handling
✔️ tokenization

---

# 🧠 இது சாதாரண Calculator இல்ல

இது actually:

```text id="’wini82"
mini programming language engine
```

---

# 💥 இந்த Programல நீ சேர்த்த Extra Changes என்ன?

நாம் Chapter 5 → 6 வரை gradually add பண்ணினோம்.

---

# 🟢 1. Token System

---

## Before

```cpp id="’wini83"
cin >> a >> op >> b;
```

👉 only simple:

```text id="’wini84"
1+2
```

---

## After

```cpp id="’wini85"
Token
Token_stream
```

---

# 💡 What it solves?

Complex expressions:

```text id="’wini86"
(1+2)*3-5%2
```

---

# 🟢 2. Grammar-Based Parser

Functions:

```cpp id="’wini87"
expression()
term()
primary()
```

---

# 💡 Solves

Operator precedence:

```text id="’wini88"
1 + 2 * 3
```

correctly becomes:

```text id="’wini89"
1 + (2 * 3)
```

NOT:

```text id="’wini90"
(1 + 2) * 3
```

---

# 🟢 3. Parentheses Support

Added:

```text id="’wini91"
( )
```

---

# 💡 Solves

Nested calculations:

```text id="’wini92"
(2+3)*(4+5)
```

---

# 🟢 4. Unary Minus / Plus

Added:

```text id="’wini93"
-5
+10
```

---

# 💡 Solves

Negative number support.

---

# 🟢 5. `%` Operator

Added:

```text id="’wini94"
10 % 3
```

---

# 💡 Solves

Remainder calculations.

---

# 🟢 6. Error Handling

Added:

```cpp id="’wini95"
try
catch
```

---

# 💡 Solves

Program crash prevention.

Example:

```text id="’wini96"
1++
```

Now:
✔️ error message
✔️ continue running

---

# 🟢 7. Error Recovery

Added:

```cpp id="’wini97"
ignore()
clean_up_mess()
```

---

# 💡 Solves

Bad input cleanup.

---

# 🟢 8. Symbolic Constants

Added:

```cpp id="’wini98"
constexpr char number = '8';
```

---

# 💡 Solves

Magic constant confusion.

---

# 🟢 9. Variables 🔥

Added:

```text id="’wini99"
let x = 10;
x + 5;
```

---

# 💡 Solves

Reusable calculations.

Without variables:

```text id="’wina00"
(123*55+77)/(44-2)
```

again and again எழுதணும் 😵

---

# 🟢 10. Symbol Table

Added:

```cpp id="’wini01"
vector<Variable> var_table;
```

---

# 💡 Solves

Store memory/state.

---

# 🟢 11. Statement System

Added:

```cpp id="’wini02"
statement()
declaration()
```

---

# 💡 Solves

Program can now distinguish:

```text id="’wini03"
let x = 5;
```

vs

```text id="’wini04"
x + 2;
```

---

# 🟢 12. Clean Architecture

Separated:

```text id="’wini05"
main()
calculate()
expression()
term()
primary()
```

---

# 💡 Solves

Maintainability + readability.

---

# 💥 Hidden Big Picture

This calculator is secretly teaching:

---

# 🔥 Compiler Basics

* tokenization
* parsing
* grammar
* syntax analysis

---

# 🔥 Interpreter Basics

* evaluation
* symbol table
* runtime state

---

# 🔥 Software Engineering

* architecture
* clean code
* error handling
* maintainability

---

# 🎯 Real Industry Insight

இந்த architecture concepts use ஆகும்:

✔️ compilers
✔️ interpreters
✔️ SQL parsers
✔️ JavaScript engines
✔️ config parsers
✔️ scripting languages

---

# 💬 Simple Tamil Summary

இந்த program:

```text id="’wini06"
math expression language
```

உருவாக்குகிறது.

இது solve செய்வது:

✔️ arithmetic parsing
✔️ precedence handling
✔️ variables
✔️ runtime evaluation
✔️ safe error handling

---

# 🚀 Final Hidden Truth

🔥 Book actually calculator teach பண்ணவில்லை 😄

It is secretly teaching:

```text id="’wini07"
“How programming languages work internally”
```
