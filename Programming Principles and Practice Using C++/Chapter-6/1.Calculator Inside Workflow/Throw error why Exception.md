`throw ஆகக்கூடிய runtime_error-ரை `catch (std::exception& e)` runtime வைத்துதானே catch செய்ய முடியும் எதற்காக `exception|?`

## ஏன் `exception&` — `runtime_error&` இல்லையா?

---

## இரண்டும் Work ஆகும்!

```cpp
// Specific catch:
catch (std::runtime_error& e) {  // runtime_error மட்டும் catch
    std::cerr << e.what() << '\n';
}

// General catch:
catch (std::exception& e) {      // எல்லாவற்றையும் catch ✅
    std::cerr << e.what() << '\n';
}
```

---

## ஏன் `exception&` Better?

Calculator-ல different errors throw ஆகலாம்:

```cpp
throw std::runtime_error("Bad token");     // user input தப்பு
throw std::runtime_error("divide by zero"); // math தப்பு

int* p = new int[999999];  // bad_alloc auto throw ஆகலாம்!
```

```
runtime_error catch போட்டா:
  runtime_error ✅ catch ஆகும்
  bad_alloc     ❌ catch ஆகாது! — program crash!

exception catch போட்டா:
  runtime_error ✅ catch ஆகும்
  bad_alloc     ✅ catch ஆகும்
  எல்லாமே       ✅ catch ஆகும்!
```

---

## Parent-Child Relationship

```
std::exception          ← parent
    ├── runtime_error   ← child
    ├── logic_error     ← child
    └── bad_alloc       ← child
```

Parent reference = எல்லா children-உம் catch ஆகும்:

```cpp
catch (std::exception& e)
// runtime_error  → exception-ஓட child ✅
// bad_alloc      → exception-ஓட child ✅
// logic_error    → exception-ஓட child ✅
```

---

## Real-world Code

```cpp
try {
    // multiple different errors possible
}
catch (std::runtime_error& e) {
    // runtime errors மட்டும்
}
catch (std::bad_alloc& e) {
    // memory errors மட்டும்
}
// இப்படி ஒவ்வொன்னா போடலாம் — ஆனா verbose!

// OR — simple-ஆ:
catch (std::exception& e) {
    // எல்லாமே ஒரே இடத்துல! ✅
}
```

---

**Simple rule:**

> `runtime_error&` catch போட்டா அந்த type மட்டும் பிடிக்கும். `exception&` போட்டா **எல்லா standard errors-உம்** பிடிக்கும் — ஏன்னா எல்லாமே `exception`-ஓட children. One catch, all covered!