இந்த chapter-ல author என்ன சொல்ல வருகிறார் என்றால்:

> “இப்போ வரை programming எப்படி செய்ய வேண்டும் என்று பார்த்தோம்.
> இனிமேல் C++ language உள்ளே எப்படி வேலை செய்கிறது என்பதை கொஞ்சம் technical-ஆக பார்க்கலாம்.”

அதாவது இது:

* புதிய பெரிய concepts கற்பிப்பதற்காக இல்லை
* C++ language-ஐ சரியாக புரிந்து கொள்ள
* functions, variables, scope போன்ற internal rules-ஐ புரிய வைக்க

---

# Chapter 7 — Simple Tamil Explanation

## §7.1 Technicalities

இது “language technical details” பகுதி.

உதாரணம்:

* variable எப்படி உருவாகிறது
* function எப்படி call ஆகிறது
* compiler என்ன செய்கிறது
* memory எப்படி பயன்படுத்துகிறது

போன்ற low-level understanding.

---

# §7.2 Declarations and Definitions

## Declaration என்றால்?

“இப்படி ஒரு thing இருக்கிறது” என்று compiler-க்கு சொல்லுவது.

```cpp
int add(int, int);
```

இது:

> add என்ற function இருக்கிறது

என்று மட்டும் சொல்கிறது.

---

## Definition என்றால்?

உண்மையான implementation.

```cpp
int add(int a, int b)
{
    return a + b;
}
```

இப்போது function body இருக்கிறது.

---

## Variable declaration

```cpp
int age = 20;
```

* `int` → datatype
* `age` → variable name
* `20` → value

---

## Constant

மாற்ற முடியாத value.

```cpp
const int x = 10;
```

பிறகு:

```cpp
x = 20; // error
```

---

## Default Initialization

value கொடுக்காமல் விட்டால் என்ன ஆகும்?

```cpp
int x;
```

சில நேரங்களில் garbage value வரும்.

---

# §7.3 Scope

ஒரு variable எங்கு visible ஆக இருக்கும்?

```cpp
{
    int x = 5;
}
```

இந்த block வெளியே:

```cpp
x // error
```

ஏனெனில் x-ன் scope முடிந்துவிட்டது.

---

# §7.4 Function call and return

இந்த பகுதி மிகவும் முக்கியம்.

---

## Function declaration

```cpp
int add(int a, int b);
```

---

## Returning value

```cpp
return a + b;
```

function output கொடுக்கிறது.

---

# Pass by value

```cpp
void f(int x)
```

copy அனுப்பப்படும்.

Original variable change ஆகாது.

---

# Pass by reference

```cpp
void f(int& x)
```

real variable itself அனுப்பப்படும்.

அதனால் original change ஆகும்.

---

# Pass by const reference

```cpp
void f(const string& s)
```

இதில்:

* copy ஆகாது → fast
* modify செய்ய முடியாது → safe

இதுதான் real-world C++-ல் அதிகம் பயன்படுத்தப்படும்.

---

# Pass-by-value vs reference

| Type            | Speed       | Original Change? |
| --------------- | ----------- | ---------------- |
| value           | slow (copy) | இல்லை            |
| reference       | fast        | change ஆகும்     |
| const reference | fast        | change ஆகாது     |

---

# Function call implementation

function call செய்யும்போது:

* arguments stack-ல் போகும்
* CPU jump செய்யும்
* return address save ஆகும்

போன்ற internal விஷயங்கள்.

இதுதான் low-level understanding.

---

# Compile-time computation

program run ஆகும் முன்பே compiler சில calculation செய்வது.

```cpp
constexpr int x = 5 * 10;
```

இதில் runtime calculation தேவையில்லை.

---

# §7.5 Order of evaluation

எந்த expression முதலில் execute ஆகும்?

```cpp
f() + g()
```

முதலில்:

* `f()`?
* அல்லது `g()`?

சில cases-ல் guaranteed order இருக்காது.

இதனால் bugs வரலாம்.

---

# Global initialization

global variables program start ஆகும் முன் initialize ஆகும்.

---

# §7.6 Namespaces

ஒரே பெயர் conflict avoid செய்ய.

```cpp
namespace A {
    int x = 5;
}
```

பயன்பாடு:

```cpp
A::x
```

---

## using

```cpp
using namespace std;
```

அப்புறம்:

```cpp
cout
```

என்று நேரடியாக பயன்படுத்தலாம்.

இல்லையெனில்:

```cpp
std::cout
```

எழுத வேண்டும்.

---

# §7.7 Modules and headers

பெரிய program-ஐ பல files-ஆக பிரிப்பது.

---

## Header files

```cpp
#include <iostream>
```

இதில் declarations இருக்கும்.

---

## Modules

Modern C++ way.

இது:

* faster compile
* cleaner dependency management

கொடுக்கிறது.

---

# இந்த chapter-ன் main goal என்ன?

இந்த chapter:

* “Programming logic” அல்ல
* “C++ language mechanics”

கற்பிக்கிறது.

இதைக் கற்றால்:

* compiler எப்படி think செய்கிறது
* memory எப்படி வேலை செய்கிறது
* functions internally என்ன செய்கிறது
* large-scale C++ எப்படி build ஆகிறது

புரிய ஆரம்பிக்கும்.

இது intermediate → advanced C++ foundation chapter.
