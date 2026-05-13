`ஜாவாவில் இதுபோல அட்ரசை print செய்ய வைக்க முடியுமா`

Short answer:

# Direct-ஆக முடியாது ❌

C++ போல:

* real memory address
* pointer arithmetic
* raw pointer access

Java intentionally allow செய்யாது.

---

# Why?

Java design goal:

```text
memory safety
```

---

# Java hides:

* actual addresses
* pointers
* manual memory management

from programmer.

---

# In C++

You can do:

```cpp
std::cout << &x;
```

Real memory address கிடைக்கும்.

---

# In Java

இப்படி இல்லை:

```java
System.out.println(&x);
```

❌ invalid.

---

# Why Java hides addresses?

Because:
Java wants:

* safer programming
* garbage collection
* no pointer corruption
* no arbitrary memory access

---

# Java Internally Still Uses Addresses

மிக முக்கியமான point:

> JVM internally pointers/address பயன்படுத்தும்.

BUT:

## programmer-க்கு expose செய்யாது.

---

# Example

```java
String s = new String("hello");
```

Internally:

* heap object உருவாகும்
* JVM references maintain செய்யும்

But:

* actual address hidden.

---

# Java Reference ≠ C++ Pointer

Java:

```java
MyClass obj;
```

இதில்:

* reference variable
* object reference handle

---

# But:

* pointer arithmetic இல்லை
* raw dereference இல்லை

---

# What Java prints?

Example:

```java
class Test
{
    int x = 10;
}

public class Main
{
    public static void main(String[] args)
    {
        Test t = new Test();

        System.out.println(t);
    }
}
```

Output:

```text
Test@2f92e0f4
```

---

# Is this real address?

Usually:

## NO.

It's typically:

```text
class_name + hashcode
```

---

# Not raw memory address.

---

# Can Java approximate addresses?

Technically:

## advanced unsafe tricks possible.

Using:

* Unsafe API
* JVM internals
* JNI

But:

* unsafe
* non-portable
* discouraged

---

# Example Unsafe Trick (Advanced)

```java
System.identityHashCode(obj)
```

But:

## not actual memory address.

---

# Why Java different from C++?

---

# C++

Gives:

* low-level control
* raw memory access
* pointers
* manual allocation

---

# Java

Gives:

* abstraction
* safety
* managed runtime
* GC

---

# Memory Model Comparison

| Feature               | C++      | Java     |
| --------------------- | -------- | -------- |
| Real pointers         | ✅        | ❌ hidden |
| Address printing      | ✅        | ❌        |
| Pointer arithmetic    | ✅        | ❌        |
| Manual memory control | ✅        | ❌        |
| Garbage collector     | optional | ✅        |
| Raw memory access     | ✅        | mostly ❌ |

---

# Important

Even Java internally:

* objects have addresses
* heap exists
* stack exists

BUT:
programmer cannot directly manipulate them.

---

# Example

Java internally conceptually:

```text
reference ---> heap object
```

Similar idea exists.

But JVM hides:

* actual addresses
* offsets
* pointer math

---

# Interesting Truth

Languages like:

* Java
* Python
* C#
* JavaScript

internally:

## still use pointers and addresses.

But runtime/VM manages them.

---

# Final Most Important Understanding

## C++

```text
Programmer controls memory directly
```

---

## Java

```text
JVM controls memory
```

and gives only:

```text
safe references
```

to programmer.

---

# One-line summary

> Java internally addresses பயன்படுத்தினாலும்,
> C++ போல actual memory address-ஐ programmer-க்கு direct-ஆக print செய்ய அல்லது manipulate செய்ய allow செய்யாது.
