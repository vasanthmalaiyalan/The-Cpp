## `cout` vs `cerr` வித்தியாசம்

---

## இரண்டும் Output பண்ணும் — ஆனா Different Stream!

```cpp
std::cout << "Hello\n";         // standard output
std::cerr << "Error!\n";        // standard error
```

---

## 3 Standard Streams இருக்கு

```
stdin  (0) → input  ← cin படிக்கும்
stdout (1) → output ← cout எழுதும்
stderr (2) → error  ← cerr எழுதும்
```

---

## Key Differences

| | `cout` | `cerr` |
|---|---|---|
| Stream | stdout | stderr |
| Buffer | ✅ Buffered | ❌ Unbuffered |
| Use | Normal output | Error messages |
| Redirect | போகலாம் | போகாது (default) |

---

## Unbuffered என்றால் என்ன?

```cpp
// cout — buffer-ல சேர்க்கும், பிறகு print
std::cout << "Result = " << val;
// program crash ஆனா print ஆகாம போகலாம்! ❌

// cerr — உடனே print பண்ணும்
std::cerr << "Error!\n";
// crash ஆனாலும் print ஆகும் ✅
```

---

## Redirect வித்தியாசம்

```bash
./calculator > output.txt
# cout → output.txt-ல போகும்
# cerr → terminal-லயே தெரியும்! ← errors miss ஆகாது
```

---

## Real-world Use

```cpp
// Normal result → cout
std::cout << "= " << val << '\n';

// Error → cerr
std::cerr << "putback() into a full buffer\n";
std::cerr << "Division by zero\n";
std::cerr << "Bad token\n";
```

---

**Simple rule:**

> `cout` = normal output — buffered, redirect ஆகும். `cerr` = error output — unbuffered, உடனே print ஆகும், redirect ஆகாது. Error messages-க்கு எப்போதும் `cerr` use பண்ணு — crash ஆனாலும் error தெரியும்!