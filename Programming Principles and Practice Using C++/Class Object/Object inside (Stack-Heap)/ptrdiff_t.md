`ptrdiff_t, இதற்கு என்ன அர்த்தம்`

`ptrdiff_t` என்பது C/C++-ல் ஒரு special integer type.
இதன் purpose:

> இரண்டு pointers-க்குள் இருக்கும் distance (difference) store செய்ய.

---

# Example

```cpp id="jlwm1p"
int arr[5] = {10,20,30,40,50};

int* p1 = &arr[1];
int* p2 = &arr[4];
```

---

# Pointer difference

```cpp id="9jlwmd"
ptrdiff_t diff = p2 - p1;
```

இதன் value:

```text id="qjlwmm"
3
```

ஏன்?

```text id="yjlwmu"
arr[4] - arr[1]
```

மூன்று int elements distance.

---

# Important

இது:

## bytes difference அல்ல.

Elements difference.

---

# Example Memory

Suppose:

```text id="tjlwmp"
arr[1] = address 1004
arr[4] = address 1016
```

Difference:

```text id="5jlwme"
1016 - 1004 = 12 bytes
```

But:

```cpp id="1jlwmg"
p2 - p1
```

returns:

```text id="8jlwmy"
3
```

Because:
compiler divides by:

```text id="mjlwma"
sizeof(int) = 4
```

---

# Why special type needed?

Pointer difference:

* may be positive
* may be negative

---

# Example

```cpp id="rjlwmd"
p1 - p2
```

Result:

```text id="0jlwmm"
-3
```

---

# Therefore:

Need signed integer type.

That type is:

```cpp id="yjlwmu"
ptrdiff_t
```

---

# Where defined?

Usually:

```cpp id="9jlwmp"
<cstddef>
```

---

# Important Meaning

## ptrdiff_t

means:

```text id="zjlwme"
pointer difference type
```

---

# In your previous code

```cpp id="6jlwmg"
ptrdiff_t offset =
    reinterpret_cast<char*>(&price)
    -
    reinterpret_cast<char*>(this);
```

---

# Why `char*`?

Because:
`char = 1 byte`

So subtraction becomes:

```text id="mjlwmy"
byte difference
```

---

# Example

Suppose:

```text id="8jlwma"
this     = 1000
&price   = 1008
```

Then:

```cpp id="qjlwmd"
reinterpret_cast<char*>(&price)
-
reinterpret_cast<char*>(this)
```

returns:

```text id="tjlwmm"
8
```

stored in:

```cpp id="5jlwmp"
ptrdiff_t
```

---

# Why not just use int?

Because:

* pointers may be 64-bit
* large memory spaces
* portability issues

`ptrdiff_t`
guaranteed correct for pointer differences.

---

# Real type internally

Usually:

| System | ptrdiff_t        |
| ------ | ---------------- |
| 32-bit | int              |
| 64-bit | long long / long |

depends on compiler/platform.

---

# Important Distinction

| Type      | Purpose                      |
| --------- | ---------------------------- |
| size_t    | sizes/counts (unsigned)      |
| ptrdiff_t | pointer differences (signed) |

---

# Example

```cpp id="1jlwme"
size_t size = 10;
```

Always:

```text id="mjlwmg"
>= 0
```

---

# But:

```cpp id="7jlwmy"
ptrdiff_t diff = p1 - p2;
```

Can be:

```text id="4jlwma"
negative
```

---

# BEST SIMPLE .CPP EXAMPLE

```cpp id="qjlwmd"
import std;

int main()
{
    int numbers[5] = {10,20,30,40,50};

    int* start = &numbers[1];

    int* end = &numbers[4];


    std::cout << "start address : "
              << start
              << '\n';

    std::cout << "end address   : "
              << end
              << '\n';


    // element difference
    ptrdiff_t element_diff = end - start;

    std::cout << "\nElement difference : "
              << element_diff
              << '\n';


    // byte difference
    ptrdiff_t byte_diff =
        reinterpret_cast<char*>(end)
      - reinterpret_cast<char*>(start);

    std::cout << "Byte difference    : "
              << byte_diff
              << '\n';
}
```

---

# Possible Output

```text id="0jlwmm"
Element difference : 3
Byte difference    : 12
```

---

# Meaning

## Normal pointer subtraction

```cpp id="yjlwmu"
end - start
```

→ element count.

---

# Byte-level subtraction

```cpp id="9jlwmp"
reinterpret_cast<char*>(...)
```

→ actual bytes.

---

# Final Core Understanding

## ptrdiff_t

Special signed integer type used for:

```text id="zjlwme"
pointer distance calculations
```

---

# Used heavily in:

* STL
* iterators
* memory allocators
* containers
* compilers
* operating systems

போன்ற low-level systems code.
