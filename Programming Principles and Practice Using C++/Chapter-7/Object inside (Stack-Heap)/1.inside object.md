```cpp
import std;


// ==========================================================
// CLASS
// ==========================================================

class Number_store
{
private:

    // member variable inside object
    std::vector<int> values;

public:

    // member function
    void add(int value)
    {
        values.push_back(value);
    }

    void print_debug()
    {
        std::cout << "\n========== OBJECT INFO ==========\n";

        // ------------------------------------------
        // OBJECT ADDRESS
        // ------------------------------------------

        std::cout << "this (object address)          : "
                  << this
                  << '\n';


        // ------------------------------------------
        // MEMBER VARIABLE ADDRESS
        // ------------------------------------------

        std::cout << "values member address          : "
                  << &values
                  << '\n';


        // ------------------------------------------
        // VECTOR INTERNAL DATA POINTER
        // ------------------------------------------

        std::cout << "vector heap data address       : "
                  << values.data()
                  << '\n';


        // ------------------------------------------
        // VECTOR ELEMENTS
        // ------------------------------------------

        std::cout << "\n========== VECTOR ELEMENTS ==========\n";

        for (size_t i = 0; i < values.size(); ++i)
        {
            std::cout
                << "Index [" << i << "]\n"

                << "  value                         : "
                << values[i] << '\n'

                << "  element address               : "
                << &values[i] << '\n'

                << "  calculated offset from base   : "
                << (
                        reinterpret_cast<char*>(&values[i])
                      - reinterpret_cast<char*>(values.data())
                   )
                << " bytes\n\n";
        }
    }
};


// ==========================================================
// MAIN
// ==========================================================

int main()
{
    Number_store store;

    store.add(10);
    store.add(20);
    store.add(30);

    store.print_debug();
}
```

---

# இந்த code என்ன காட்டுகிறது?

---

# 1. Object address (`this`)

```cpp id="jlwmq1"
std::cout << this;
```

இதில்:

* object memory address print ஆகும்.

Example:

```text id="9jlwms"
0x61ff00
```

---

# 2. Member variable address

```cpp id="5jlwm4"
&values
```

இதில்:

* `values` member object எங்கு இருக்கிறது என்பதை காட்டும்.

இது object-ன் உள்ளே இருக்கும்.

---

# 3. Vector heap pointer

```cpp id="4jlwmk"
values.data()
```

இதில்:

* actual vector elements இருக்கும் heap memory address கிடைக்கும்.

---

# Example memory picture

```text id="3jlwmu"
store object
+----------------------+
| vector metadata      |
| data ptr ----------+-------> heap array
| size                |
| capacity            |
+----------------------+
```

---

# 4. Element addresses

```cpp id="1jlwm0"
&values[i]
```

ஒவ்வொரு element address-யும் print ஆகும்.

---

# Example output conceptually

```text id="0jlwm7"
Index [0]
address = 1000

Index [1]
address = 1004

Index [2]
address = 1008
```

---

# 5. Offset calculation

மிக முக்கியமான பகுதி:

```cpp id="8jlwmg"
reinterpret_cast<char*>(&values[i])
-
reinterpret_cast<char*>(values.data())
```

இதில்:

* base address-லிருந்து
* element எத்தனை bytes தள்ளி உள்ளது

கணக்கிடப்படுகிறது.

---

# Example result

```text id="7jlwm8"
Index 0 -> 0 bytes
Index 1 -> 4 bytes
Index 2 -> 8 bytes
```

---

# Meaning

## Formula

\text{element address} = \text{base address} + (index \times sizeof(type))

---

# What this proves

## 1. Object has memory address

```text id="1jlwm2"
this
```

---

## 2. Member variable lives inside object

```text id="6jlwmd"
values
```

---

## 3. vector stores heap pointer

```text id="zjlwm1"
values.data()
```

---

## 4. Vector elements contiguous memory

```text id="yjlwmf"
1000
1004
1008
```

---

## 5. Indexing uses offset arithmetic

```text id="djlwml"
base + offset
```

---

# Most Important Insight

இந்த code basically modern C++ internals-ஐ காட்டுகிறது:

```text id="mjlwm9"
Object
   ↓
Member offset
   ↓
Vector metadata
   ↓
Heap pointer
   ↓
Offset arithmetic
   ↓
Actual element access
```

---

# This is the foundation of

* arrays
* vectors
* objects
* structs
* pointer arithmetic
* cache locality
* low-level optimization
* compiler internals

எல்லாவற்றிற்கும்.
