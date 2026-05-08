`இந்த class `class Token {
public:
    char kind;
    double value;

    Token(char k)
        : kind{k}, value{0}
    {
    }

    Token(char k, double v)
        : kind{k}, value{v}
    {
    }
};| obj create ஆகும்போது 16 byte என்பது இருக்கும் என்பது தெளிவாக தெரிந்து கொள்ள முடிகிறது அதே மாதிரி இதை obj கிரியேட் பண்ணும் போது `class Token_stream {
public:

    Token get();
    void putback(Token t);

private:

    bool full {false};
    Token buffer {'0'};
};` இந்த function size`Token get();
    void putback(Token t);` caluate ஆகுமா?`

    ## நல்ல Question! 🎯

---

## Functions — Size Calculate ஆகாது!

```cpp
class Token_stream {
    Token get();           // ← size இல்ல!
    void putback(Token t); // ← size இல்ல!

    bool full {false};     // ← size இருக்கு
    Token buffer {'0'};    // ← size இருக்கு
};
```

**Functions = code segment-ல இருக்கும் — object size-ல count ஆகாது!**

---

## ஏன் Functions Size-ல இல்ல?

```
Object Memory:
┌─────────────────────┐
│ Data members மட்டும்│ ← RAM-ல store ஆகும்
└─────────────────────┘

Code Segment (separate):
┌─────────────────────┐
│ get() code          │ ← எல்லா objects-உம் share பண்ணும்!
│ putback() code      │
└─────────────────────┘
```

```cpp
Token_stream ts1;
Token_stream ts2;
Token_stream ts3;
// மூன்னும் same get(), putback() code share பண்ணும்
// 3 copies இல்ல — 1 copy மட்டும்! ✅
```

---

## `Token_stream` Size என்ன?

```cpp
class Token_stream {
    bool full {false};   // 1 byte
    Token buffer {'0'};  // 16 bytes (char=1 + padding=7 + double=8)
};
```

```
Padding காரணம்:
┌──────────────────────────┐
│ full     = 1 byte        │
│ padding  = 7 bytes       │ ← double alignment
│ buffer   = 16 bytes      │
└──────────────────────────┘
Total = 24 bytes
```

---

## Verify பண்ணலாம்

```cpp
std::cout << sizeof(Token_stream) << '\n'; // 24
std::cout << sizeof(Token) << '\n';        // 16
```

---

**Simple rule:**

> Object size = **data members மட்டும்**. Functions = code segment-ல separate-ஆ இருக்கும், எல்லா objects-உம் share பண்ணும் — object size-ல count ஆகாது!