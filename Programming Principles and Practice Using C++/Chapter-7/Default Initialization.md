இந்த section மிகவும் important C++ behavior பற்றி பேசுகிறது:

# Default Initialization

அதாவது:

> “நாம் value கொடுக்கவில்லை என்றாலும் சில types automatic-ஆக safe value பெறும்.”

---

# First confusion

முன்னாடி author சொன்னார்:

> “Variables initialize செய்யாமல் விடக்கூடாது.”

ஆனால் இப்போது:

```cpp id="rdd1ak"
vector<string> v;
string s;
```

இதில் value இல்லை.

அப்படியானால் bug இல்லையா?

---

# Answer

இல்லை.

ஏனெனில்:

* `string`
* `vector`

போன்ற class types
automatic-ஆக default value பெறும்.

---

# Example

```cpp id="u6ghux"
string s;
```

இதன் actual value:

```text id="w9phc5"
""
```

(empty string)

---

# Another example

```cpp id="k01ldd"
vector<int> v;
```

இதன் value:

```text id="56ff1i"
empty vector
```

size = 0

---

# Why this happens?

Because:
`string` and `vector`
special functions கொண்ட class types.

அவை object உருவாகும்போது:
automatic initialization செய்கின்றன.

---

# Default Constructor

Author mentions:

> “The mechanism is called a default constructor.”

---

# Constructor meaning

Object உருவாகும் போது automatically run ஆகும் function.

---

# Example conceptually

```cpp id="v11fij"
string s;
```

Internally something like:

```cpp id="dbclfy"
s.string();
```

run ஆகும்.

---

# That constructor initializes safely

For string:

```text id="qq4j44"
""
```

For vector:

```text id="5c39sv"
empty container
```

---

# Important Difference

## Built-in types

```cpp id="d5h4g7"
int x;
double d;
char c;
```

Safe default இல்லை.

Garbage values possible.

---

# Class types

```cpp id="6q1z0d"
string s;
vector<int> v;
```

Safe defaults.

---

# Why built-in types unsafe?

Because:
C++ originally designed for:

* speed
* low-level control

Compiler:

> “நீ value கொடுக்கவில்லை.
> நான் initialize செய்ய மாட்டேன்.”

---

# Example

```cpp id="k4a6w0"
int x;

std::cout << x;
```

Undefined / garbage.

---

# But:

```cpp id="ol4x9k"
string s;

std::cout << s;
```

Safe.

Outputs empty string.

---

# Real Example from Book

```cpp id="4f4u7d"
vector<string> v;
string s;

while (cin >> s)
{
    v.push_back(s);
}
```

---

# What happens here?

Initially:

```text id="r5w6h0"
v = empty vector
s = ""
```

Then:

* user inputs words
* words stored in vector

---

# Why no problem?

Because:
both objects default initialized safely.

---

# Core Guidelines Warning

Author strongly warns:

> Uninitialized variables are major bug source.

---

# C++ Core Guidelines

Professional C++ rules say:

> Never leave variables uninitialized.

---

# BAD

```cpp id="y2tw9v"
int x;
```

---

# GOOD

```cpp id="dmd7j4"
int x = 0;
```

or

```cpp id="dzpc7d"
int x {0};
```

---

# Important Mental Model

| Type   | Default safe? |
| ------ | ------------- |
| int    | ❌ No          |
| double | ❌ No          |
| char   | ❌ No          |
| string | ✅ Yes         |
| vector | ✅ Yes         |

---

# Why modern C++ prefers classes

One big reason:
classes can guarantee safety.

Built-in raw types cannot.

---

# BEST .CPP EXAMPLE

```cpp id="88ksv0"
import std;

int main()
{
    // =====================================
    // Built-in types (dangerous)
    // =====================================

    int x;

    double d;

    std::cout << "Uninitialized int x      : "
              << x
              << '\n';

    std::cout << "Uninitialized double d   : "
              << d
              << '\n';


    // =====================================
    // Class types with default initialization
    // =====================================

    std::string name;

    std::vector<int> numbers;


    std::cout << "\nDefault initialized string:\n";

    std::cout << "name = ["
              << name
              << "]\n";


    std::cout << "\nDefault initialized vector:\n";

    std::cout << "numbers.size() = "
              << numbers.size()
              << '\n';


    // =====================================
    // Adding values
    // =====================================

    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);

    name = "Vasanth";


    std::cout << "\nAfter assigning values:\n";

    std::cout << "name = "
              << name
              << '\n';


    std::cout << "numbers = ";

    for (int value : numbers)
    {
        std::cout << value << ' ';
    }

    std::cout << '\n';
}
```

---

# What this code demonstrates

| Part                   | Meaning           |
| ---------------------- | ----------------- |
| `int x;`               | dangerous garbage |
| `string name;`         | safe empty string |
| `vector<int> numbers;` | safe empty vector |
| `push_back()`          | add elements      |
| `size()`               | vector size       |

---

# Most Important Lesson

## Built-in types

Need manual initialization.

---

## Class types

Can initialize themselves safely using constructors.

---

# Real-world Modern C++ Rule

Professional modern C++ code tries to:

* avoid raw uninitialized variables
* use safe abstractions
* prefer initialized objects

இதுதான்:

* safer systems
* fewer crashes
* predictable behavior

கிடைக்க காரணம்.
