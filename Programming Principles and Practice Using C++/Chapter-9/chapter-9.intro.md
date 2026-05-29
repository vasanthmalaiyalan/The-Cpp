இந்த **Chapter 9: Input and Output Streams** என்பது C++-ல் மிகவும் முக்கியமான chapter-களில் ஒன்று.

எளிமையாக சொன்னால்:

> **"Program-க்கு data எப்படி உள்ளே வருகிறது, வெளியே எப்படி செல்கிறது?"**

என்பதை முழுமையாக கற்றுக்கொடுக்கும் chapter.

---

# §9.1 Input and Output

அடிப்படை Input / Output

Input:

```cpp
int age;
cin >> age;
```

Output:

```cpp
cout << age;
```

உதாரணம்:

```text
Input : 25
Output: 25
```

---

# §9.2 The I/O Stream Model

C++-ல் data ஒரு **stream** போல ஓடுகிறது.

```text
Keyboard
   ↓
  cin
   ↓
Program
   ↓
 cout
   ↓
Screen
```

Stream = Data flow.

அதனால்தான் பெயர்:

```cpp
iostream
```

(Input Output Stream)

---

# §9.3 Files

File handling.

---

## Opening a file

```cpp
ifstream fin("input.txt");
```

File open செய்யும்.

---

## Reading a file

```cpp
int x;
fin >> x;
```

File-லிருந்து value படிக்கும்.

---

## Writing a file

```cpp
ofstream fout("result.txt");

fout << 100;
```

File-க்கு எழுதும்.

---

உதாரணம்:

```text
input.txt
---------
25
```

Program:

```cpp
ifstream fin("input.txt");

int age;
fin >> age;
```

age = 25

---

# §9.4 I/O Error Handling

File கிடைக்கவில்லை என்றால்?

```cpp
ifstream fin("data.txt");
```

ஆனால் file இல்லையென்றால்?

```cpp
if (!fin)
{
    cout << "File open failed";
}
```

இதுதான் error handling.

---

# §9.5 Reading a Single Value

User input வாங்கும்போது validation செய்வது.

---

Bad:

```cpp
cin >> age;
```

User:

```text
hello
```

என்றால் error.

---

Better:

```cpp
int age;

if(cin >> age)
{
    // valid
}
else
{
    // invalid
}
```

---

## Breaking the problem into manageable parts

பெரிய வேலைகளை சிறு functions-ஆக பிரி.

```cpp
read_age();
read_name();
read_salary();
```

---

## Separating dialog from function

Bad:

```cpp
cout << "Enter age:";
```

எல்லா இடத்திலும் எழுதுவது.

Good:

Input logic-ஐ தனியாக வைத்துக்கொள்.

---

# §9.6 User-defined Output Operators

நம்முடைய class-ஐ `cout` மூலம் print செய்வது.

---

உதாரணம்:

```cpp
class Person
{
public:
    string name;
    int age;
};
```

இப்போது:

```cpp
Person p;
cout << p;
```

சாதாரணமாக வேலை செய்யாது.

---

Operator overload:

```cpp
ostream& operator<<(ostream& os,
                    const Person& p)
{
    return os << p.name
              << " "
              << p.age;
}
```

இப்போது:

```cpp
cout << p;
```

வேலை செய்யும்.

---

# §9.7 User-defined Input Operators

`cin` மூலம் class object படிப்பது.

```cpp
Person p;

cin >> p;
```

இதற்கு:

```cpp
istream& operator>>(istream& is,
                    Person& p)
{
    return is >> p.name >> p.age;
}
```

எழுத வேண்டும்.

---

# §9.8 A Standard Input Loop

மிகவும் முக்கியமான pattern.

```cpp
int x;

while (cin >> x)
{
    cout << x << '\n';
}
```

Input valid இருக்கும் வரை loop ஓடும்.

---

உதாரணம்:

```text
10
20
30
abc
```

Output:

```text
10
20
30
```

`abc` வந்தவுடன் loop stop.

---

# §9.9 Reading a Structured File

Simple file:

```text
10
20
30
```

Structured file:

```text
Vasanth 24
Arun    22
Kumar   25
```

---

## In-memory representation

File data memory-ல் எப்படி store ஆகும்?

```cpp
struct Person
{
    string name;
    int age;
};
```

---

## Reading structured values

```cpp
Person p;

fin >> p.name >> p.age;
```

---

## Changing representations

File format மாறினாலும் program structure maintain செய்வது.

---

# §9.10 Formatting

Output அழகாக காட்டுவது.

---

## Integer formatting

```cpp
cout << hex << 255;
```

Output:

```text
ff
```

---

## Floating-point formatting

```cpp
cout << fixed << setprecision(2);
```

```cpp
cout << 3.14159;
```

Output:

```text
3.14
```

---

## String formatting

```cpp
cout << setw(10) << "Hi";
```

Alignment.

---

## Character I/O

```cpp
char ch;

cin >> ch;
```

ஒரு character மட்டும் படிக்கும்.

---

# format()

Modern C++ formatting.

```cpp
cout << format("Age = {}", age);
```

Python f-string போல.

---

# §9.11 String Streams

மிகவும் பயனுள்ள topic.

String-ஐ stream போல நடத்தலாம்.

---

```cpp
#include <sstream>

string s = "100 200";

istringstream iss(s);

int a,b;

iss >> a >> b;
```

Result:

```cpp
a = 100
b = 200
```

---

# Chapter 9 முடிந்தபின் என்ன தெரியும்?

✅ `cin`

✅ `cout`

✅ File Reading

✅ File Writing

✅ Error Handling

✅ Operator Overloading (`<<`, `>>`)

✅ Parsing Text Files

✅ Formatting Output

✅ String Streams

இவை எல்லாம் **Software Engineering**, **Security Tools**, **Log Parsing**, **Bug Bounty Automation Tools**, **CLI Applications** போன்றவற்றில் தினசரி பயன்படுத்தப்படும் C++ அடிப்படைகள். Chapter 9-ஐ நன்றாகப் புரிந்துகொண்டால், text files, logs, CSV files, configuration files போன்றவற்றை கையாளும் திறன் கிடைக்கும்.
