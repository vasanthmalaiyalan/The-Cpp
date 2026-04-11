#include<stdio.h>
#include<stdint.h>

// simulate w-bit trunction
unsigned truncate(unsigned x, int w) {
    unsigned mask = (1U << w) - 1; // e.g w = 4 -> 00001111
    return x & mask;
}

int main() {

    unsigned x = 9;
    unsigned y = 5;

    printf("========== Unsigned Multiplication Demo ================\n\n");

    // full multiplication (32-bit)
    unsigned full = x * y;

    printf("Full multiplication (32-bit):\n");
    printf("%u * %u = %u\n\n", x, y, full);

    // simulate 4-bit system
    int w = 4;
    unsigned truncated = truncate(full, w);

    printf("Simulating %d-bit unsigned multiplication:\n", w);
    printf("Result = %u (after truncation)\n\n", truncated);

    // verify using mod
    unsigned mod_result = full % (1 << w);

    printf("Using formula (mod 2^%d):\n", w);
    printf("%u mod %u = %u\n\n", full, (1 << w), mod_result);

    // show equality
    if (truncated == mod_result)
          printf("truncation == mod -> concept correct!\n");
          else
            printf("mismatch\n");

    return 0;        
}

/*
சூப்பர் 🔥 — இந்த line தான் truncation (lower w bits மட்டும் எடுக்கும் trick). இதை clearஆ breakdown பண்ணலாம் 😄

🔴 Code
unsigned mask = (1U << w) - 1;   // e.g., w=4 → 00001111
return x & mask;
🔹 1. (1U << w) என்ன?

👉 1U = unsigned 1
👉 << w = left shift

🔸 Example (w = 4)
1U = 00000001
1U << 4 = 00010000  (16)

👉 so:

(1U << 4) = 16
🔹 2. (1U << w) - 1

👉

16 - 1 = 15

👉 binary:

00010000 - 1 = 00001111
🔥 Result
mask = 0b00001111

👉 meaning:

last 4 bits = 1
others = 0
🔹 3. x & mask

👉 AND operation:

1 & 1 = 1
1 & 0 = 0

👉 so:

keep only bits where mask = 1
🔥 4. Example
x = 45 = 00101101
mask =    00001111
-------------------
result =  00001101

👉

= 13 ✅
🔹 5. What is happening?

👉
higher bits remove ஆகுது

👉
lower w bits மட்டும் save ஆகுது

🔥 6. Why this works?

👉 mask:

00001111

👉 so:

only last 4 bits survive
🔹 7. General idea

👉

(1 << w) - 1 = w number of 1s
Examples
w	mask
4	00001111
8	11111111
3	00000111
🔥 8. Equivalent meaning

👉

x & mask  =  x mod 2^w
🔹 9. Simple analogy

👉 mask = filter

only last w bits pass ✅
rest blocked ❌
🔥 10. One-line takeaway

👉
“mask = last w bits only → AND → truncate”

🔥 Final clarity

👉

(1U << w) - 1 → creates mask
x & mask      → keeps lower w bits
*/