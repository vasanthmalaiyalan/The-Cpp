```cpp
import std;


// ==========================================================
// SIMPLE CLASS
// ==========================================================

class Demo
{
private:

    // ------------------------------------------
    // Stored DIRECTLY inside object
    // ------------------------------------------

    int id;

    double price;


    // ------------------------------------------
    // vector object stored inside object
    // BUT vector elements stored in HEAP
    // ------------------------------------------

    std::vector<int> numbers;


    // ------------------------------------------
    // string object stored inside object
    // string characters usually stored in HEAP
    // ------------------------------------------

    std::string name;

public:

    Demo()
    {
        id = 101;

        price = 999.99;

        name = "Vasanth";

        numbers.push_back(10);
        numbers.push_back(20);
        numbers.push_back(30);
    }


    void print_memory_layout()
    {
        std::cout
            << "\n========================================\n"
            << "OBJECT ADDRESS\n"
            << "========================================\n";

        // whole object address
        std::cout << "this (Demo object)           : "
                  << this
                  << '\n';


        std::cout
            << "\n========================================\n"
            << "STACK / OBJECT MEMORY MEMBERS\n"
            << "========================================\n";

        // member addresses
        std::cout << "&id                          : "
                  << &id
                  << '\n';

        std::cout << "&price                       : "
                  << &price
                  << '\n';

        std::cout << "&numbers (vector object)     : "
                  << &numbers
                  << '\n';

        std::cout << "&name (string object)        : "
                  << &name
                  << '\n';


        std::cout
            << "\n========================================\n"
            << "HEAP MEMORY\n"
            << "========================================\n";

        // vector heap memory
        std::cout << "numbers.data()               : "
                  << numbers.data()
                  << '\n';

        // string heap memory
        std::cout << "name.data()                  : "
                  << static_cast<const void*>(name.data())
                  << '\n';


        std::cout
            << "\n========================================\n"
            << "VECTOR ELEMENTS\n"
            << "========================================\n";

        for (size_t i = 0; i < numbers.size(); ++i)
        {
            std::cout
                << "numbers[" << i << "] value          : "
                << numbers[i]
                << '\n';

            std::cout
                << "numbers[" << i << "] address        : "
                << &numbers[i]
                << '\n';

            std::cout
                << "offset from base             : "
                << (
                        reinterpret_cast<char*>(&numbers[i])
                      - reinterpret_cast<char*>(numbers.data())
                   )
                << " bytes\n\n";
        }


        std::cout
            << "\n========================================\n"
            << "OFFSET OF MEMBERS INSIDE OBJECT\n"
            << "========================================\n";

        std::cout
            << "id offset                    : "
            << (
                    reinterpret_cast<char*>(&id)
                  - reinterpret_cast<char*>(this)
               )
            << " bytes\n";


        std::cout
            << "price offset                 : "
            << (
                    reinterpret_cast<char*>(&price)
                  - reinterpret_cast<char*>(this)
               )
            << " bytes\n";


        std::cout
            << "numbers offset               : "
            << (
                    reinterpret_cast<char*>(&numbers)
                  - reinterpret_cast<char*>(this)
               )
            << " bytes\n";


        std::cout
            << "name offset                  : "
            << (
                    reinterpret_cast<char*>(&name)
                  - reinterpret_cast<char*>(this)
               )
            << " bytes\n";
    }
};


// ==========================================================
// MAIN
// ==========================================================

int main()
{
    Demo d;

    d.print_memory_layout();
}
```

---

# இந்த code என்ன கற்றுக்கொடுக்கும்?

---

# 1. Object memory (`this`)

```cpp
this
```

முழு object address.

---

# 2. Stack/Object memory members

```cpp
&id
&price
&numbers
&name
```

இவை object உள்ளே இருக்கும் members.

---

# 3. Heap memory

```cpp
numbers.data()
name.data()
```

இவை heap address.

---

# 4. Vector elements contiguous memory

```cpp
&numbers[i]
```

ஒவ்வொரு element address-யும் print ஆகும்.

---

# 5. Offset calculation

```cpp
member_address - object_address
```

இதன் மூலம்:
member object உள்ளே எவ்வளவு offset-ல் உள்ளது தெரியும்.

---

# Important Understanding

---

# Inside Object

```text
Demo object
+----------------------+
| id                   |
| price                |
| vector object        |
| string object        |
+----------------------+
```

---

# vector object internally

```text
vector object
+----------------------+
| data pointer -------+-----> heap array
| size                |
| capacity            |
+----------------------+
```

---

# string object internally

```text
string object
+----------------------+
| char pointer -------+-----> heap chars
| size                |
| capacity            |
+----------------------+
```

---

# Final Core Understanding

| Thing           | Stored where?        |
| --------------- | -------------------- |
| int             | inside object        |
| double          | inside object        |
| vector object   | inside object        |
| vector elements | heap                 |
| string object   | inside object        |
| string chars    | usually heap         |
| `this`          | whole object address |
| `data()`        | heap address         |

---

# Most Important Insight

Modern C++ containers mostly work like this:

```text
Object
   ↓
Manager object inside
   ↓
Pointer to heap memory
```

இதுதான்:

* vector
* string
* map
* unordered_map
* deque

போன்ற STL containers-ன் core architecture.
