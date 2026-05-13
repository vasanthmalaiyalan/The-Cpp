```cpp
import std;


// ==========================================================
// 1. STACK-ONLY OBJECT
// ==========================================================

class Stack_only_data
{
private:

    // --------------------------------------------------
    // ALL THESE LIVE DIRECTLY INSIDE OBJECT MEMORY
    // --------------------------------------------------

    int id;

    double price;

    char grade;

    std::array<int, 3> values;

public:

    Stack_only_data()
    {
        id = 101;

        price = 999.99;

        grade = 'A';

        values = {10, 20, 30};
    }


    void print_memory_layout()
    {
        std::cout
            << "\n====================================================\n"
            << "STACK-ONLY OBJECT\n"
            << "====================================================\n";


        // whole object address
        std::cout << "this object address           : "
                  << this
                  << '\n';


        std::cout
            << "\n---------------- MEMBERS ----------------\n";


        std::cout << "&id                           : "
                  << &id
                  << '\n';


        std::cout << "&price                        : "
                  << &price
                  << '\n';


        std::cout << "&grade                        : "
                  << static_cast<void*>(&grade)
                  << '\n';


        std::cout << "&values                       : "
                  << &values
                  << '\n';


        std::cout
            << "\n---------------- ARRAY ELEMENTS ----------------\n";


        for (size_t i = 0; i < values.size(); ++i)
        {
            std::cout
                << "values[" << i << "] address          : "
                << &values[i]
                << '\n';
        }


        std::cout
            << "\n---------------- OFFSETS ----------------\n";


        std::cout << "id offset                     : "
                  << (
                        reinterpret_cast<char*>(&id)
                      - reinterpret_cast<char*>(this)
                     )
                  << " bytes\n";


        std::cout << "price offset                  : "
                  << (
                        reinterpret_cast<char*>(&price)
                      - reinterpret_cast<char*>(this)
                     )
                  << " bytes\n";


        std::cout << "grade offset                  : "
                  << (
                        reinterpret_cast<char*>(&grade)
                      - reinterpret_cast<char*>(this)
                     )
                  << " bytes\n";


        std::cout << "values offset                 : "
                  << (
                        reinterpret_cast<char*>(&values)
                      - reinterpret_cast<char*>(this)
                     )
                  << " bytes\n";
    }
};



// ==========================================================
// 2. STACK + HEAP OBJECT
// ==========================================================

class Heap_based_data
{
private:

    // --------------------------------------------------
    // THESE OBJECTS LIVE INSIDE OBJECT MEMORY
    // BUT THEIR ACTUAL DATA USES HEAP
    // --------------------------------------------------

    std::vector<int> numbers;

    std::string name;

    std::map<int, std::string> students;

public:

    Heap_based_data()
    {
        numbers.push_back(10);
        numbers.push_back(20);
        numbers.push_back(30);

        name = "Vasanth";

        students[1] = "Kumar";
        students[2] = "Arun";
    }


    void print_memory_layout()
    {
        std::cout
            << "\n====================================================\n"
            << "STACK + HEAP OBJECT\n"
            << "====================================================\n";


        // whole object address
        std::cout << "this object address           : "
                  << this
                  << '\n';


        std::cout
            << "\n---------------- OBJECT MEMBERS ----------------\n";


        std::cout << "&numbers                      : "
                  << &numbers
                  << '\n';


        std::cout << "&name                         : "
                  << &name
                  << '\n';


        std::cout << "&students                     : "
                  << &students
                  << '\n';


        std::cout
            << "\n---------------- HEAP DATA ----------------\n";


        // vector heap address
        std::cout << "numbers.data()                : "
                  << numbers.data()
                  << '\n';


        // string heap address
        std::cout << "name.data()                   : "
                  << static_cast<const void*>(name.data())
                  << '\n';


        std::cout
            << "\n---------------- VECTOR ELEMENTS ----------------\n";


        for (size_t i = 0; i < numbers.size(); ++i)
        {
            std::cout
                << "numbers[" << i << "] value            : "
                << numbers[i]
                << '\n';

            std::cout
                << "numbers[" << i << "] address          : "
                << &numbers[i]
                << '\n';

            std::cout
                << "offset from heap base         : "
                << (
                        reinterpret_cast<char*>(&numbers[i])
                      - reinterpret_cast<char*>(numbers.data())
                     )
                << " bytes\n\n";
        }


        std::cout
            << "\n---------------- MAP DATA ----------------\n";


        for (const auto& [id, student_name] : students)
        {
            std::cout
                << "key = "
                << id
                << " | value = "
                << student_name
                << '\n';
        }


        std::cout
            << "\n---------------- OFFSETS ----------------\n";


        std::cout << "numbers offset                : "
                  << (
                        reinterpret_cast<char*>(&numbers)
                      - reinterpret_cast<char*>(this)
                     )
                  << " bytes\n";


        std::cout << "name offset                   : "
                  << (
                        reinterpret_cast<char*>(&name)
                      - reinterpret_cast<char*>(this)
                     )
                  << " bytes\n";


        std::cout << "students offset               : "
                  << (
                        reinterpret_cast<char*>(&students)
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
    Stack_only_data stack_object;

    stack_object.print_memory_layout();


    Heap_based_data heap_object;

    heap_object.print_memory_layout();
}
```

---

# இந்த program என்ன காட்டுகிறது?

---

# PART 1 — STACK ONLY OBJECT

இந்த class:

```cpp
class Stack_only_data
```

உள்ளே இருக்கும்:

* int
* double
* char
* std::array

எல்லாம்:

## object memory உள்ளேதான் இருக்கும்.

---

# Memory Picture

```text
Stack_only_data object
+----------------------+
| id                   |
| price                |
| grade                |
| values[0]            |
| values[1]            |
| values[2]            |
+----------------------+
```

Heap allocation இல்லை.

---

# PART 2 — STACK + HEAP OBJECT

இந்த class:

```cpp
class Heap_based_data
```

உள்ளே இருக்கும்:

* vector
* string
* map

இவை:
object உள்ளே metadata மட்டும் வைத்திருக்கும்.

Actual data:

## heap-ல் இருக்கும்.

---

# Memory Picture

```text
Heap_based_data object
+--------------------------------+
| vector object                  |
| string object                  |
| map object                     |
+--------------------------------+
```

---

# vector internally

```text
vector object
+----------------------+
| pointer ------------+-------> heap array
| size                |
| capacity            |
+----------------------+
```

---

# string internally

```text
string object
+----------------------+
| char pointer -------+-------> heap chars
| size                |
| capacity            |
+----------------------+
```

---

# map internally

```text
map object
+----------------------+
| tree metadata -------+-------> heap tree nodes
+----------------------+
```

---

# Most Important Concepts This Code Demonstrates

| Concept             | Example                |
| ------------------- | ---------------------- |
| `this` pointer      | whole object address   |
| member offsets      | object layout          |
| stack/object memory | fixed members          |
| heap memory         | vector/string/map data |
| contiguous heap     | vector                 |
| tree heap nodes     | map                    |
| offset arithmetic   | address calculations   |

---

# Final Big Understanding

## Stack-only objects

* fixed size
* no heap
* fast
* contiguous

---

## Heap-based STL containers

* dynamic size
* heap allocation
* pointers internally
* flexible

---

# Modern C++ Reality

Most advanced STL containers are actually:

```text
small manager object
        +
dynamic heap memory
```

architecture பயன்படுத்துகின்றன.
