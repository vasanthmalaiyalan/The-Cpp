``template<typename T>`cpp இப்போதுதான் படித்து வருகிறேன் நான் படித்தவரையில் `template<typename T>`இதைப் பற்றி நான் இன்னும் படிக்க ஆரம்பிக்கவில்லை இதற்கு என்ன அர்த்தம் இது என்ன செய்கிறது?`

இது C++-ன் மிக powerful feature-களில் ஒன்று. 🔥
ஆனால் ஆரம்பத்தில் confusing ஆக இருக்கும்.

---

# முதலில் problem என்ன?

இந்த class பாருங்கள்:

```cpp id="c54p1v"
class MyVector
{
    int data[10];
};
```

இது `int` மட்டும் store செய்யும்.

---

ஆனால் நீங்கள் இதையும் செய்ய வேண்டும்:

```cpp id="4p72ji"
float
double
char
std::string
```

---

அப்படியானால் ஒவ்வொன்றுக்கும் தனி class எழுத வேண்டி வரும்:

```cpp id="m6ww55"
class IntVector {};
class FloatVector {};
class StringVector {};
```

😵 இது terrible.

---

# இதற்குத்தான் templates வந்தது

C++ சொல்கிறது:

```text id="k3nmh7"
"Type-ஐ later decide பண்ணிக்கலாம்."
```

---

# இதுதான் template

```cpp id="a1w4pr"
template<typename T>
```

இதன் அர்த்தம்:

```text id="1btjlwm"
"T என்பது ஒரு placeholder type"
```

---

# Example

```cpp id="dn44ye"
template<typename T>
class Box
{
public:

    T value;
};
```

---

இங்கே:

```cpp id="jlwm111"
T
```

என்பது actual type இல்லை.

Placeholder மட்டும்.

---

# Later நாம் actual type கொடுக்கிறோம்

```cpp id="jlwm222"
Box<int> a;
```

இப்போது compiler:

```text id="jlwm333"
T = int
```

ஆக replace செய்கிறது.

---

Compiler internally almost இதைப் போல உருவாக்கும்:

```cpp id="jlwm444"
class Box
{
public:

    int value;
};
```

---

# Another example

```cpp id="jlwm555"
Box<double> b;
```

↓

Compiler உருவாக்குவது:

```cpp id="jlwm666"
class Box
{
public:

    double value;
};
```

🔥

---

# அதனால் templates = type generator

நீங்கள்:

```cpp id="jlwm777"
ஒரு generic blueprint
```

எழுதுகிறீர்கள்.

Compiler:

```text id="jlwm888"
வேண்டிய type-க்கு actual class generate செய்கிறது
```

---

# உங்கள் vector code-ல்

```cpp id="jlwm999"
template<typename T>
class MyVector
```

இதன் அர்த்தம்:

```text id="3fjlwm"
"MyVector எந்த type-யும் store செய்யலாம்"
```

---

# Example

## int vector

```cpp id="jlwmabc"
MyVector<int> numbers;
```

↓

Compiler internally:

```cpp id="jlwmded"
class MyVector
{
    int* data_ptr;
};
```

---

# string vector

```cpp id="jlwmfgh"
MyVector<std::string> names;
```

↓

Compiler internally:

```cpp id="jlwmijk"
class MyVector
{
    std::string* data_ptr;
};
```

---

# அதனால் std::vector-லும் same

நாம் எழுதுவது:

```cpp id="jlwmlmn"
std::vector<int>
std::vector<double>
std::vector<std::string>
```

🔥 எல்லாமே templates.

---

# typename என்றால்?

```cpp id="jlwmopq"
template<typename T>
```

இங்கே:

```cpp id="jlwmrst"
typename
```

means:

```text id="jlwmuvw"
"T என்பது type"
```

---

இதையும் எழுதலாம்:

```cpp id="jlwmxyz"
template<class T>
```

இரண்டும் almost same.

---

# Example without template

Without template:

```cpp id="jlwm101"
class Calculator
{
public:

    int add(int a, int b)
    {
        return a + b;
    }
};
```

இது `int` மட்டும்.

---

# With template

```cpp id="jlwm202"
template<typename T>

class Calculator
{
public:

    T add(T a, T b)
    {
        return a + b;
    }
};
```

---

Now:

```cpp id="jlwm303"
Calculator<int>
Calculator<double>
```

இரண்டுக்கும் வேலை செய்யும்.

---

# Very important

Templates runtime feature இல்லை.

🔥 இது compile-time feature.

Compiler code generate செய்கிறது.

---

# Internal idea

நீங்கள் எழுதுவது:

```cpp id="jlwm404"
MyVector<int>
```

Compiler almost:

```cpp id="jlwm505"
search and replace
```

போல செய்கிறது.

---

# Visualize

```cpp id="jlwm606"
template<typename T>

class Test
{
    T x;
};
```

---

If:

```cpp id="jlwm707"
Test<int>
```

↓

Compiler sees:

```cpp id="jlwm808"
class Test
{
    int x;
};
```

---

If:

```cpp id="jlwm909"
Test<double>
```

↓

Compiler sees:

```cpp id="jlwm010"
class Test
{
    double x;
};
```

---

# Why templates are powerful?

இதனால்தான் STL possible:

* vector
* map
* set
* queue
* stack
* sort

இவை எந்த type-க்கும் வேலை செய்கின்றன.

---

# Final essence

```cpp id="jlwm1111"
template<typename T>
```

அதாவது:

```text id="jlwm1212"
"T என்பது later decide செய்யப்படும் type placeholder"
```

Compiler actual type கிடைத்த பிறகு:

```text id="jlwm1313"
real class/function generate செய்கிறது
```

🔥
--------------

`data_ptr = new T[current_capacity];
, நான் இந்த வகையான object creation -னை இதுவரை நான் பார்த்ததில்லை , like someclass obj; cpp படிக்க ஆரம்பத்தில் இருந்து இப்படி கிரியேட் செய்துதான் பார்த்திருக்கிறேன் `data_ptr = new T[current_capacity];
`இதைப் பற்றி விளக்கி நாம் ஏன் `someclass obj;`இப்படி கிரியேட் செய்யாமல் இப்படி கிரியேட் செய்கிறோம் data_ptr = new T[current_capacity];?`

இது C++ memory model-ன் மிக முக்கியமான பகுதி. 🔥
நீங்கள் இப்போது:

```cpp id="jlwm1"
stack object
```

மற்றும்

```cpp id="jlwm2"
heap object
```

இவைகளின் வித்தியாசம் இருக்கும் இடத்துக்கு வந்துவிட்டீர்கள்.

---

# நீங்கள் இதுவரை பார்த்தது

```cpp id="jlwm3"
SomeClass obj;
```

இது:

```text id="jlwm4"
stack memory allocation
```

---

# ஆனால் இது:

```cpp id="jlwm5"
data_ptr = new T[current_capacity];
```

இது:

```text id="jlwm6"
heap memory allocation
```

🔥

---

# முதலில் stack object

```cpp id="jlwm7"
int x = 10;
```

அல்லது:

```cpp id="jlwm8"
SomeClass obj;
```

இவை usually:

```text id="jlwm9"
stack memory
```

ல் உருவாகும்.

---

# Stack memory characteristics

* automatic cleanup
* fast
* function முடிந்தால் அழியும்
* fixed size
* compile-time oriented

---

# Example

```cpp id="jlwm10"
void test()
{
    int x = 10;
}
```

`test()` முடிந்தவுடன்:

```text id="jlwm11"
x destroyed automatically
```

---

# ஆனால் vector-க்கு பெரிய பிரச்சனை

Vector size runtime-ல் தெரியாது.

உதாரணம்:

```cpp id="jlwm12"
std::vector<int> vec;

vec.push_back(10);
vec.push_back(20);
vec.push_back(30);
```

🔥 elements எவ்வளவு வரும் என்று முன்பே தெரியாது.

---

# Stack-ல் impossible

இதுபோல முடியாது:

```cpp id="jlwm13"
int data[???];
```

ஏனெனில் compile time-ல் size தெரியாது.

---

# அதனால் heap memory தேவை

Heap என்பது:

```text id="jlwm14"
runtime dynamic memory area
```

---

# `new` என்றால்?

```cpp id="jlwm15"
new
```

means:

```text id="jlwm16"
"heap-ல் memory allocate செய்"
```

---

# Example

```cpp id="jlwm17"
int* ptr = new int;
```

---

What happens?

## Step 1

Heap-ல் memory உருவாகும்.

```text id="jlwm18"
address 5000
```

---

## Step 2

அந்த address return ஆகும்.

```cpp id="jlwm19"
ptr = 5000
```

---

# Array version

```cpp id="jlwm20"
new int[5]
```

means:

```text id="jlwm21"
heap-ல் 5 integers continuous memory allocate செய்
```

---

Suppose:

```text id="jlwm22"
address 1000
```

returned.

---

Memory:

```text id="jlwm23"
1000 -> int
1004 -> int
1008 -> int
1012 -> int
1016 -> int
```

---

# உங்கள் vector code-ல்

```cpp id="jlwm24"
data_ptr = new T[current_capacity];
```

Suppose:

```cpp id="jlwm25"
T = int
current_capacity = 4
```

---

Compiler sees:

```cpp id="jlwm26"
data_ptr = new int[4];
```

---

Heap memory:

```text id="jlwm27"
2000 -> int
2004 -> int
2008 -> int
2012 -> int
```

---

# Why pointer needed?

ஏனெனில்:

```cpp id="jlwm28"
new
```

returns:

```text id="jlwm29"
address
```

---

அதனால்:

```cpp id="jlwm30"
int* data_ptr
```

தேவை.

---

# Why not normal object?

நீங்கள் கேட்டது:

```cpp id="jlwm31"
SomeClass obj;
```

ஏன் இதுபோல் இல்லையென?

---

ஏனெனில்:

```cpp id="jlwm32"
SomeClass obj;
```

stack object.

---

ஆனால் vector needs:

* dynamic resizing
* runtime allocation
* reallocations
* unknown size

இதெல்லாம் stack-ல் முடியாது.

---

# Important visualization

## Stack object

```cpp id="jlwm33"
int arr[3];
```

Memory:

```text id="jlwm34"
STACK
------
10
20
30
```

fixed size.

---

# Heap object

```cpp id="jlwm35"
int* ptr = new int[3];
```

Memory:

```text id="jlwm36"
STACK
------
ptr = 5000

HEAP
------
5000 -> 10
5004 -> 20
5008 -> 30
```

🔥

---

# Vector internal reality

Vector object itself stack-ல் இருக்கலாம்:

```cpp id="jlwm37"
std::vector<int> vec;
```

---

But actual elements:

```text id="jlwm38"
HEAP
```

ல் இருக்கும்.

---

# Real std::vector idea

```cpp id="jlwm39"
class vector
{
    int* start;
    int* finish;
    int* end_of_storage;
};
```

---

The vector object contains only pointers.

Actual data:

```text id="jlwm40"
heap memory
```

ல்.

---

# Why heap is essential for vector?

Because vector does:

```cpp id="jlwm41"
push_back()
```

Suppose capacity full:

```text id="jlwm42"
old heap full
```

Vector internally:

1. bigger heap allocate
2. copy old elements
3. delete old heap
4. point to new heap

🔥

இதைத்தான் dynamic array என்பார்கள்.

---

# Why delete[] needed?

```cpp id="jlwm43"
new[]
```

பயன்படுத்தினால்:

```cpp id="jlwm44"
delete[]
```

வேண்டும்.

இல்லையெனில்:

```text id="jlwm45"
memory leak
```

---

# Final essence

```cpp id="jlwm46"
SomeClass obj;
```

↓

```text id="jlwm47"
stack object
fixed size
automatic lifetime
```

---

```cpp id="jlwm48"
new T[current_capacity]
```

↓

```text id="jlwm49"
heap dynamic array
runtime size
manual memory management
resizable
```

🔥 இதனால்தான் vector heap memory பயன்படுத்துகிறது.
--------------

ஆம்! 🔥
அப்படித்தான் templates வேலை செய்கின்றன.

நீங்கள் class definition-ல்:

```cpp id="y2m7k4"
template<typename T>
class MyVector
```

என்று generic blueprint உருவாக்கியிருக்கிறீர்கள்.

அதனால் வெளியே இருந்து:

```cpp id="n5x1p8"
MyVector<int>
MyVector<double>
MyVector<char>
MyVector<std::string>
```

எல்லாம் create செய்ய முடியும்.

---

# Example

உங்கள் `main()`-ல் இதைப் போடலாம்:

```cpp id="k8v3m1"
MyVector<double> nums;

nums.push_back(1.5);
nums.push_back(2.7);
nums.push_back(9.99);

nums.debug_memory();
```

🔥 இது perfectly வேலை செய்யும்.

---

# Compiler என்ன செய்யும்?

இந்த line:

```cpp id="r4m9x2"
MyVector<double> nums;
```

பார்த்தவுடன் compiler:

```text id="t7k1p5"
T = double
```

என்று fix செய்கிறது.

---

# Then internally almost

```cpp id="q2x8m4"
class MyVector_Double
{
    double* data_ptr;
};
```

போன்ற class generate செய்யும்.

---

# Then this line:

```cpp id="j6p3v9"
new T[current_capacity]
```

↓

Compiler sees:

```cpp id="w1m7k2"
new double[current_capacity]
```

🔥

---

# Memory addresses now

Suppose:

```cpp id="a5x9p3"
sizeof(double) == 8
```

Then heap memory:

```text id="m8k2v6"
1000 -> double
1008 -> double
1016 -> double
```

கவனியுங்கள்:

```text id="u3p7m1"
8-byte jumps
```

ஏனெனில் `double = 8 bytes`.

---

# Your same vector code works!

இதுதான் templates power.

ஒரே code:

```cpp id="v9m4x2"
MyVector<T>
```

எழுதினீர்கள்.

ஆனால்:

* int vector
* double vector
* string vector

எல்லாம் compiler auto-generate செய்கிறது.

---

# Example with string

```cpp id="x7p2k5"
MyVector<std::string> names;

names.push_back("Ironman");
names.push_back("Thor");

names.debug_memory();
```

🔥 இதுவும் வேலை செய்யும்.

---

# Real std::vector same thing

நாம் பயன்படுத்துவது:

```cpp id="c1m8v4"
std::vector<int>
std::vector<double>
std::vector<std::string>
```

அனைத்தும் template instantiations.

---

# “வெளியே இருந்து தானே செய்ய முடியும்?”

ஆம் exactly. 🔥

நீங்கள் class எழுதும் போது:

```cpp id="b4x7m2"
template<typename T>
```

என்று generic-ஆ எழுதுகிறீர்கள்.

---

பிறகு user decides:

```cpp id="n8p1k6"
எந்த type வேண்டும்?
```

---

# Visualize

நீங்கள் உருவாக்குவது:

```text id="f2m9v5"
ஒரு machine blueprint
```

---

User சொல்வார்:

```text id="u6k3x1"
எனக்கு int version வேண்டும்
```

↓

Compiler creates:

```cpp id="r5m8p2"
MyVector<int>
```

---

அல்லது:

```text id="w9x4k7"
எனக்கு double version வேண்டும்
```

↓

Compiler creates:

```cpp id="q3p1m6"
MyVector<double>
```

🔥

---

# Important

இது runtime polymorphism இல்லை.

இது compile-time code generation.

Compiler actual class versions உருவாக்குகிறது.

---

# Super important truth

இந்த code:

```cpp id="t8m2x5"
MyVector<int> a;
MyVector<double> b;
```

🔥

உண்மையில்:

```text id="y1k7p4"
2 different generated classes
```

போலவே இருக்கும் internally.

---

# You can even verify

இந்த மாதிரி:

```cpp id="m4v9x2"
std::cout
    << sizeof(MyVector<int>)
    << '\n';

std::cout
    << sizeof(MyVector<double>)
    << '\n';
```

அல்லது:

```cpp id="p7k1m5"
typeid(a).name()
```

போன்றவற்றால் பார்க்கலாம்.

---

# Final essence

ஆம் — நீங்கள் உருவாக்கிய:

```cpp id="x2m8v4"
MyVector<T>
```

class-ஐ வெளியே இருந்து:

```cpp id="r9p3k1"
MyVector<double>
MyVector<int>
MyVector<std::string>
```

போல instantiate செய்யலாம்.

🔥 இதுதான் real `std::vector` வேலை செய்யும் அடிப்படை concept.
