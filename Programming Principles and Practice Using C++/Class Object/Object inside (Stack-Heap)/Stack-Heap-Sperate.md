மிக முக்கியமான கேள்வி 🔥
நீ இப்போது STL containers + memory architecture எப்படி design செய்யப்பட்டுள்ளது என்பதை புரிந்து கொள்ள முயற்சிக்கிறாய்.

C++-ல் broadly இரண்டு category:

---

# 1. Mostly STACK/Object-only storage

Data object உள்ளேதான் இருக்கும்.

Heap allocation இல்லை (normally).

---

# 2. STACK/Object + HEAP storage

Object உள்ளே:

* metadata
* pointers

Actual data:

* heap-ல் இருக்கும்.

`vector` இந்த category.

---

# First Big Table

| Type                         | Stack/Object மட்டும்? | Heap பயன்படுத்துமா? |
| ---------------------------- | --------------------- | ------------------- |
| int                          | ✅                     | ❌                   |
| double                       | ✅                     | ❌                   |
| char                         | ✅                     | ❌                   |
| bool                         | ✅                     | ❌                   |
| struct/class (fixed members) | ✅                     | ❌                   |
| std::array                   | ✅                     | ❌                   |
| C array                      | ✅                     | ❌                   |
| vector                       | ❌                     | ✅                   |
| string                       | ❌ (usually)           | ✅                   |
| deque                        | ❌                     | ✅                   |
| list                         | ❌                     | ✅                   |
| map                          | ❌                     | ✅                   |
| unordered_map                | ❌                     | ✅                   |
| set                          | ❌                     | ✅                   |
| queue                        | ❌                     | ✅                   |
| stack                        | ❌                     | ✅                   |
| unique_ptr                   | pointer மட்டும்       | actual object heap  |
| shared_ptr                   | pointer மட்டும்       | actual object heap  |

---

# CATEGORY 1 — STACK / OBJECT ONLY

---

# Example Types

* int
* double
* char
* bool
* struct
* std::array
* raw arrays

---

# BEST STACK-ONLY EXAMPLE

```cpp
import std;

struct Stack_only
{
    int id;

    double price;

    char grade;

    std::array<int, 3> values;
};


int main()
{
    Stack_only s
    {
        101,
        999.99,
        'A',
        {10, 20, 30}
    };


    std::cout
        << "\n========== OBJECT ADDRESS ==========\n";

    std::cout << "&s                : "
              << &s
              << '\n';


    std::cout
        << "\n========== MEMBERS ==========\n";

    std::cout << "&s.id             : "
              << &s.id
              << '\n';

    std::cout << "&s.price          : "
              << &s.price
              << '\n';

    std::cout << "&s.grade          : "
              << static_cast<void*>(&s.grade)
              << '\n';

    std::cout << "&s.values         : "
              << &s.values
              << '\n';


    std::cout
        << "\n========== ARRAY ELEMENTS ==========\n";

    for (size_t i = 0; i < s.values.size(); ++i)
    {
        std::cout
            << "values[" << i << "] address : "
            << &s.values[i]
            << '\n';
    }
}
```

---

# What happens here?

Everything inside object itself:

```text
Stack_only object
+------------------+
| id               |
| price            |
| grade            |
| values[0]        |
| values[1]        |
| values[2]        |
+------------------+
```

NO heap.

---

# std::array Important

```cpp
std::array<int, 3>
```

Unlike vector:

* fixed size
* no heap allocation
* elements inside object directly

---

# CATEGORY 2 — STACK + HEAP

Now important STL containers.

---

# 1. vector

```cpp
std::vector<int>
```

---

# Internal model

```text
vector object
+----------------------+
| pointer ------------+-----> heap array
| size                |
| capacity            |
+----------------------+
```

---

# 2. string

```cpp
std::string
```

Usually:

```text
string object
+----------------------+
| char pointer -------+-----> heap chars
| size                |
| capacity            |
+----------------------+
```

(Note: small string optimization sometimes)

---

# 3. deque

```cpp
std::deque<int>
```

Uses:

* multiple heap blocks
* more complex structure

---

# 4. list

```cpp
std::list<int>
```

Doubly linked list.

---

# Internal

```text
node <-> node <-> node
```

Each node separately heap allocated.

---

# 5. map

```cpp
std::map<int, string>
```

Usually:

* Red-Black Tree
* heap nodes

---

# 6. unordered_map

```cpp
std::unordered_map<int, string>
```

Usually:

* hash table
* buckets in heap

---

# 7. set

Tree/hash based.

Heap.

---

# 8. stack / queue

Adapters.
Usually internally:

* deque
  or
* vector

So heap used.

---

# BEST HEAP-CONTAINER EXAMPLE

```cpp
import std;

int main()
{
    std::vector<int> vec {10,20,30};

    std::string str = "Vasanth";

    std::list<int> lst {1,2,3};

    std::map<int, std::string> mp
    {
        {1, "one"},
        {2, "two"}
    };


    std::cout
        << "\n========== VECTOR ==========\n";

    std::cout << "&vec             : "
              << &vec
              << '\n';

    std::cout << "vec.data()       : "
              << vec.data()
              << '\n';


    std::cout
        << "\n========== STRING ==========\n";

    std::cout << "&str             : "
              << &str
              << '\n';

    std::cout << "str.data()       : "
              << static_cast<const void*>(str.data())
              << '\n';


    std::cout
        << "\n========== LIST ==========\n";

    std::cout << "&lst             : "
              << &lst
              << '\n';

    std::cout << "First node value : "
              << *lst.begin()
              << '\n';


    std::cout
        << "\n========== MAP ==========\n";

    std::cout << "&mp              : "
              << &mp
              << '\n';

    std::cout << "mp[1]            : "
              << mp[1]
              << '\n';
}
```

---

# Important Understanding

---

# STACK ONLY TYPES

Fast:

* cache friendly
* fixed size
* no allocation overhead

BUT:

* cannot resize dynamically

---

# HEAP CONTAINERS

Flexible:

* dynamic growth
* runtime sizing

BUT:

* allocation overhead
* pointer indirection
* cache misses possible

---

# Most Important STL Containers

| Container     | Internal Idea      |
| ------------- | ------------------ |
| vector        | dynamic array      |
| string        | dynamic char array |
| deque         | segmented array    |
| list          | linked list        |
| map           | balanced tree      |
| unordered_map | hash table         |
| set           | tree/hash          |
| queue         | adapter            |
| stack         | adapter            |

---

# Professional C++ Reality

Modern high-performance C++ often prefers:

```cpp
std::vector
```

because:

* contiguous heap memory
* cache friendly
* extremely optimized

---

# Final Big Mental Model

## STACK / OBJECT MEMORY

```text
small fixed metadata
```

---

## HEAP MEMORY

```text
large dynamic actual data
```

---

# Modern STL architecture

Almost everything works like:

```text
object
   ↓
pointer/metadata
   ↓
heap-managed data
```

---

இதுதான் modern C++ STL memory model foundation.
