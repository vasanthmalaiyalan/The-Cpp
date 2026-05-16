``class Person
{
public:

    std::string name;

    Person()
    {
        name = "Tony";
    }
};` class என்று ஒன்று எழுதினாலே அதற்கு constructor எழுதியே ஆக வேண்டுமா? `

இல்லை. 🔥
நீங்கள் constructor எழுதவேண்டிய அவசியம் இல்லை.

---

# Example

```cpp id="m7k2x5"
class Person
{
public:

    std::string name;
};
```

🔥 இது perfectly valid class.

---

# Then

```cpp id="u4m8p1"
Person p;
```

வேலை செய்யும்.

---

# But wait 😄

நீங்கள் constructor எழுதவில்லை என்றாலும்:

```text id="q1k7v4"
compiler usually default constructor உருவாக்கும்
```

🔥

---

# Compiler-generated constructor

Internally almost:

```cpp id="r9m3x6"
Person()
{
}
```

போன்ற ஒன்று உருவாகும்.

---

# Important

இந்த default constructor:

```text id="t5k1m8"
member objects-ன் constructors-ஐ call செய்யும்
```

🔥

---

# Example

```cpp id="v2m9x4"
std::string name;
```

இதற்கு:

```cpp id="c7k3p1"
std::string constructor
```

automatic-ஆக call ஆகும்.

---

# So this works safely

```cpp id="n4m8v5"
Person p;
```

↓

```text id="u1k7x9"
name becomes valid empty string
```

🔥

---

# Important distinction

## No constructor written

```cpp id="q5m2v8"
class Person
{
public:

    std::string name;
};
```

↓

compiler auto-generates one.

---

# Manual constructor written

```cpp id="x8k1p4"
class Person
{
public:

    std::string name;

    Person()
    {
        name = "Tony";
    }
};
```

↓

your constructor used.

---

# Why write constructor then?

To:

* initialize values
* allocate resources
* open files
* setup invariants

🔥

---

# Example

```cpp id="r2m7v5"
Person()
{
    name = "Tony";
}
```

means:

```text id="t4k8x1"
every new Person starts with Tony
```

---

# Without constructor

```cpp id="u7m3p9"
Person p;
```

↓

```text id="p1k9v6"
name = empty string
```

(default std::string behavior)

---

# Very important

If class contains primitive types:

```cpp id="n5m4x8"
class Test
{
public:

    int x;
};
```

---

Then:

```cpp id="q3k7v1"
Test t;
```

↓

```text id="r8m1v4"
x may contain garbage value
```

🔥

Because primitive ints not auto-initialized.

---

# But std::string safe

Because:

```cpp id="u6k2x9"
std::string
```

itself has constructor.

---

# Another deep truth

Every object construction ALWAYS involves constructor somehow.

Either:

| Type                   | Constructor source  |
| ---------------------- | ------------------- |
| user-written           | your constructor    |
| no constructor written | compiler-generated  |
| primitive type         | no real constructor |

🔥

---

# Example

```cpp id="c4m9p5"
Person p;
```

Even if you wrote nothing:

compiler internally almost:

```cpp id="v1k7m3"
Person::Person()
{
    name.std::string::string();
}
```

🔥

---

# Final essence

இல்லை — class எழுதினாலே constructor எழுத வேண்டிய அவசியம் இல்லை.

```cpp id="f8m2x6"
class Person
{
public:
    std::string name;
};
```

இது valid.

🔥

ஆனால் constructor எழுதவில்லை என்றால்:

```text id="y5k1v9"
compiler default constructor உருவாக்கும்
```

மேலும் member objects (`std::string`) constructors automatic-ஆக run ஆகும்.
