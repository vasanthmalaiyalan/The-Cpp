## `for (double x : temps)` என்றால் என்ன?

---

## `x` இங்கயே Declare ஆகுது!

```cpp
for (double x : temps)
//   ^^^^^^^^
//   இங்கயே declare + initialize ஆகுது!
```

`x` = loop variable — **for loop-ல மட்டும் உயிரோட இருக்கும்!**

---

## என்ன நடக்குது?

```cpp
for (double x : temps)
    sum += x;
```

Compiler இதை இப்படி translate பண்ணும்:

```cpp
for (int i = 0; i < temps.size(); i++) {
    double x = temps[i];  // ← ஒவ்வொரு iteration-லயும்
    sum += x;             //   temps-லிருந்து copy ஆகும்
}
```

---

## Memory-ல என்ன நடக்குது?

```
temps = [1.0, 2.0, 3.0]

Iteration 1:
  double x = 1.0  ← temps[0] copy
  sum += 1.0 → sum = 1.0
  x destroy ❌

Iteration 2:
  double x = 2.0  ← temps[1] copy
  sum += 2.0 → sum = 3.0
  x destroy ❌

Iteration 3:
  double x = 3.0  ← temps[2] copy
  sum += 3.0 → sum = 6.0
  x destroy ❌
```

---

## Syntax Breakdown

```cpp
for (double x : temps)
//   ^^^^^^  ^  ^^^^^
//   type    │  collection
//   +       │
//   var     │
//           ← "in" என்று படிக்கலாம்

// "temps-ல உள்ள ஒவ்வொரு double-உம் x-ஆ எடு"
```

---

**Simple rule:**

> `double x` = loop-ல மட்டும் உள்ள temporary variable — ஒவ்வொரு iteration-லயும் temps-லிருந்து value copy ஆகும், iteration முடிஞ்சா destroy ஆகும். எங்கயும் தனியா declare தேவையில்ல — for loop-லயே declare + initialize!