சூப்பரான கேள்வி. 🔥
இங்குதான் C++ operator overloading-ன் உண்மையான magic இருக்கு.

நீங்கள் confusion ஆகுற காரணம்:

```cpp
numbers[2]
```

இது array access போல தெரிகிறது.

ஆனால் `numbers` ஒரு array இல்லை.

இது:

```cpp
My_vector numbers;
```

ஒரு object.

அப்படியிருக்க:

```cpp
numbers[2]
```

எப்படி வேலை செய்கிறது?

இதைத்தான் compiler special rule மூலம் function call-ஆக மாற்றுகிறது.

---

# முதலில் இது invalid ஆக இருக்க வேண்டும்

இந்த class-ஐ பாருங்கள்:

```cpp id="p5gckd"
class Test
{
};
```

```cpp id="7ypskb"
Test t;

t[2];
```

இது compile error.

ஏனெனில்:

```text id="0jgjcv"
இந்த object-க்கு [] எப்படி வேலை செய்ய வேண்டும்?
```

என்று compiler-க்கு தெரியாது.

---

# ஆனால் நீங்கள் இந்த function-ஐ சேர்த்துவிட்டீர்கள்

```cpp id="12f87u"
int& operator[](size_t i)
{
    return *(data + i);
}
```

இதன் அர்த்தம்:

```text id="7hlls8"
"இந்த object மீது [] பயன்படுத்தினால்
இந்த function-ஐ ஓட்டு"
```

---

# Compiler special translation செய்கிறது

நீங்கள் எழுதுவது:

```cpp id="g5q62v"
numbers[2]
```

Compiler இதைப் பார்த்தவுடன்:

```text id="m6qej0"
numbers என்பது class object
அதற்குள் operator[] உள்ளது
```

என்று கண்டுபிடிக்கிறது.

பிறகு automatic rewrite:

```cpp id="0vq4wo"
numbers.operator[](2)
```

---

# இது magic syntax rule

C++ language itself rule:

```text id="xrr65q"
obj[x]
```

↓

```text id="ft7x52"
obj.operator[](x)
```

---

# Real flow

இந்த line:

```cpp id="pl3e7g"
numbers[2]
```

உண்மையில்:

```cpp id="9m9rjn"
numbers.operator[](2)
```

---

அதாவது function call:

```cpp id="y1k7p8"
operator[](2)
```

---

# Inside function

```cpp id="wyqbqb"
return *(data + i);
```

---

Suppose:

```text id="z8u9rr"
data = 1000
i = 2
```

---

Then:

```cpp id="7yk0pr"
data + i
```

↓

```text id="br4r4f"
1000 + (2 * 4)
= 1008
```

---

பிறகு:

```cpp id="0c6w0h"
*(1008)
```

↓

```text id="4ux8mz"
30
```

---

அதனால்:

```cpp id="qmp9jr"
numbers[2]
```

↓

```cpp id="1k7oc7"
numbers.operator[](2)
```

↓

```cpp id="6ngjlwm"
*(data + 2)
```

↓

```text id="rjlwmv"
30
```

---

# இதை actual function call போல எழுதலாம்

இந்த இரண்டு same:

```cpp id="kzyl2d"
numbers[2]
```

```cpp id="i0jlwm"
numbers.operator[](2)
```

---

# Example

இந்த code try பண்ணுங்கள்:

```cpp id="wvyjlwm"
#include <iostream>

class Test
{
public:

    int operator[](int x)
    {
        std::cout
            << "operator[] called\n";

        return x * 100;
    }
};

int main()
{
    Test t;

    std::cout << t[5] << '\n';
}
```

---

Output:

```text id="y1lcbt"
operator[] called
500
```

---

இங்கே actual array ஒன்றும் இல்லை.

ஆனால்:

```cpp id="5i3rqj"
t[5]
```

வேலை செய்கிறது.

ஏன்?

ஏனெனில் compiler internally:

```cpp id="7y8vpy"
t.operator[](5)
```

ஆக மாற்றிவிட்டது.

---

# இதே மாதிரி பல operators

| நீங்கள் எழுதுவது | Compiler மாற்றுவது |
| ---------------- | ------------------ |
| `a + b`          | `a.operator+(b)`   |
| `a[2]`           | `a.operator[](2)`  |
| `a()`            | `a.operator()()`   |
| `a == b`         | `a.operator==(b)`  |

---

அதனால்:

```cpp id="pzhb2u"
numbers[2]
```

இது உண்மையில் special syntax மட்டும்.

Actual execution:

```cpp id="0vc15d"
numbers.operator[](2)
```

🔥
