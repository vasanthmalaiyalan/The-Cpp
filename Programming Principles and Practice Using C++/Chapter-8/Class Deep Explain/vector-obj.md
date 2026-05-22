ஆம். நீ இப்போது புரிந்து கொள்ள வேண்டியது:

1. `vector<FieldInfo>` heap-ல் objects எப்படி store செய்கிறது?
2. `for(auto& field : fields)` எப்படி next object-க்கு செல்கிறது?
3. `++ptr` எப்படி `sizeof(FieldInfo)` bytes jump செய்கிறது?

இதை காட்டும் ஒரு சிறந்த `.cpp` code:

```cpp
#include <iostream>
#include <vector>
#include <string>

struct FieldInfo
{
    std::string name;
    size_t size;
    size_t alignment;
    size_t offset;
};

int main()
{
    std::vector<FieldInfo> fields;

    fields.push_back(
    {
        "age",
        sizeof(int),
        alignof(int),
        0
    });

    fields.push_back(
    {
        "salary",
        sizeof(double),
        alignof(double),
        8
    });

    fields.push_back(
    {
        "grade",
        sizeof(char),
        alignof(char),
        16
    });

    std::cout
        << "sizeof(FieldInfo) = "
        << sizeof(FieldInfo)
        << "\n\n";

    FieldInfo* begin = fields.data();
    FieldInfo* end   = begin + fields.size();

    std::cout
        << "begin = "
        << begin
        << '\n';

    std::cout
        << "end   = "
        << end
        << "\n\n";

    while(begin != end)
    {
        std::cout
            << "Object Address : "
            << begin
            << '\n';

        std::cout
            << "name       = "
            << begin->name
            << '\n';

        std::cout
            << "size       = "
            << begin->size
            << '\n';

        std::cout
            << "alignment  = "
            << begin->alignment
            << '\n';

        std::cout
            << "offset     = "
            << begin->offset
            << '\n';

        std::cout
            << "-------------------------\n";

        ++begin;
    }
}
```

---

### Example Output

(Addresses machine-க்கு machine மாறும்)

```text
sizeof(FieldInfo) = 56

begin = 0x5000
end   = 0x50A8

Object Address : 0x5000
name       = age
size       = 4
alignment  = 4
offset     = 0
-------------------------

Object Address : 0x5038
name       = salary
size       = 8
alignment  = 8
offset     = 8
-------------------------

Object Address : 0x5070
name       = grade
size       = 1
alignment  = 1
offset     = 16
-------------------------
```

---

இப்போது முக்கியமான பகுதி:

```cpp
++begin;
```

இதன் அர்த்தம்:

```cpp
begin = begin + 1;
```

ஆனால் `begin` type என்ன?

```cpp
FieldInfo*
```

---

Compiler-க்கு தெரியும்:

```cpp
sizeof(FieldInfo)
```

உதாரணம்:

```text
56 bytes
```

---

அதனால்:

```cpp
begin + 1
```

என்பது:

```cpp
(char*)begin + 56
```

என்ற மாதிரி address calculation ஆகிறது.

---

உதாரணம்:

```text
begin = 0x5000
```

---

முதல் increment:

```text
0x5000 + 56
=
0x5038
```

---

இரண்டாவது increment:

```text
0x5038 + 56
=
0x5070
```

---

அதனால்:

```cpp
for(auto& field : fields)
```

என்பது compiler பார்வையில் கிட்டத்தட்ட:

```cpp
FieldInfo* ptr = fields.data();

while(ptr != fields.data() + fields.size())
{
    FieldInfo& field = *ptr;

    std::cout << field.name << '\n';

    ++ptr;
}
```

இதுதான் range-for loop-ன் actual underlying idea.

இந்த code-ஐ run செய்து address values-ஐ பார்த்தால் contiguous memory, pointer arithmetic, `sizeof(FieldInfo)` jump ஆகிய மூன்றும் ஒரே நேரத்தில் தெளிவாக புரியும்.

---------------

`first இது ரன் ஆகி முடித்ததும் `begin = 0x5000
end   = 0x50A8

Object Address : 0x5000
name       = age
size       = 4
alignment  = 4
offset     = 0`Loop நின்றுவிடும் தானே?`

இல்லை. Loop நின்றுவிடாது. 🔥

நீங்க ஒரு முக்கியமான விஷயத்தை miss பண்ணுறீங்க:

```cpp
while(begin != end)
{
    std::cout << begin->name << '\n';

    ++begin;
}
```

ஒவ்வொரு iteration முடிவிலும்:

```cpp
++begin;
```

execute ஆகிறது.

---

முதலில்:

```text
begin = 0x5000
end   = 0x50A8
```

---

### Iteration 1

Condition:

```cpp
begin != end
```

↓

```text
0x5000 != 0x50A8
```

↓

```text
true
```

Loop உள்ளே செல்கிறது.

---

Print:

```text
Object Address : 0x5000
name           : age
```

---

பிறகு:

```cpp
++begin;
```

---

`begin` type:

```cpp
FieldInfo*
```

Compiler:

```cpp
begin = begin + 1;
```

---

Suppose:

```text
sizeof(FieldInfo)=56
```

---

அதனால்:

```text
0x5000 + 56
```

↓

```text
0x5038
```

---

இப்போது:

```text
begin = 0x5038
```

---

### Iteration 2

Condition:

```text
0x5038 != 0x50A8
```

↓

```text
true
```

---

Print:

```text
Object Address : 0x5038
name           : salary
```

---

பிறகு:

```cpp
++begin;
```

↓

```text
0x5038 + 56
```

↓

```text
0x5070
```

---

### Iteration 3

Condition:

```text
0x5070 != 0x50A8
```

↓

```text
true
```

---

Print:

```text
Object Address : 0x5070
name           : grade
```

---

பிறகு:

```cpp
++begin;
```

↓

```text
0x5070 + 56
```

↓

```text
0x50A8
```

---

### Iteration 4

Condition:

```text
0x50A8 != 0x50A8
```

↓

```text
false
```

Loop stop.

---

Visual:

```text
Heap

0x5000  age
0x5038  salary
0x5070  grade
0x50A8  end marker (one-past-last)
```

Pointer movement:

```text
begin

0x5000
   ↓ ++
0x5038
   ↓ ++
0x5070
   ↓ ++
0x50A8
```

இங்கே முக்கியமான concept:

```cpp
FieldInfo* end = begin + fields.size();
```

`end` என்பது **கடைசி object address அல்ல**.

அது:

```text
last object-க்கு அடுத்த address
```

அதாவது:

```text
age      -> 0x5000
salary   -> 0x5038
grade    -> 0x5070

end      -> 0x50A8
```

`end` object இல்லை. அது **loop நிறுத்த வேண்டிய boundary** மட்டும்.

அதனால்தான் STL iterators-ல்:

```cpp
begin()  -> first element
end()    -> one-past-last element
```

என்ற rule பயன்படுத்தப்படுகிறது. இதே rule `vector`, `string`, `array`, `map` எல்லாவற்றிலும் இருக்கும்.

----------------------

`அப்படி என்றால் இதன் size 56 `FieldInfo* end   = begin + fields.size();
`56 ? `

