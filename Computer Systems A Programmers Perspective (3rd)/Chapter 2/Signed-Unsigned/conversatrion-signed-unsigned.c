#include<stdio.h>
#include<stdint.h>

int main() {
    // =========================================
    // Book Example 1: Short int -> unsigned Short
    // v = -12345 -> uv = 53191
    // =========================================
    printf("=== BOOK EXAMPLE 1 ===\n\n");

    short int v = -12345;
    unsigned short uv = (unsigned short)v;
    printf("v = %d, uv = %d",v, uv);
    //Output: v = -12345, uv = 53191

    printf("\nBit representation (same for both!):\n");

    //Show bits of v
    printf("v bits: ");
    for (int i = 15; i >= 0; i--) {
        printf("%d", (v >> i) &1);
    printf(" = -12345 (signed)\n");
    }

    // Show bits uv
    printf("uv bits: ");
    for (int i = 15; i >= 0; i--) {
        printf("%d", (uv >> i) &1);
    printf(" = 53191 (unsigned)\n\n");
    }

    //Why -12345 to 53191?
    printf("Transformation -12345 to 53191 (signed to unsigned conversation internally)");
    printf(" -1234 as 16 bits because we use (short) as two's complement:\n");
    printf("step 1 method start with -12345 transfer to binary easy way below the comment out explain clearly and then first you use decimal to hex and then hex to binary is easy");
    printf(" 12345 = 0x3039\n");
    printf(" OR: next method is -12345 + 65536 why beacuse short bit is 16 so we add that signed why we add (+)=>(-12345 + 65536) beacuse signed to unsigned");
    printf(" Two method available one is two complement method another is this method like(65536 = 2^16, add 2^w like (65536 -12345 = 53191)to negative = unsigned)\n\n");

    // ==================================
    // BOOK EXAMPLE 2: unsigned -> int
    // u = 4294967295 (UMax32) -> tu = -1
    // =================================
    printf("===BOOK EXAMPLE 2 ===\n\n");

    unsigned u = 4294967295u; // UMax32 = 0xFFFFFFFF
    int tu = (int) u;// two complement
    printf("u = %u, tu = %d", u, tu);
    //Output: u = 4294967295, tu = -1

    printf("\nBit representation (same for both):\n");
    printf("u bits: 11111111111111111111111111111111\n");
    printf("tu bits: 00000000000000000000000000000001\n");

    printf("WHY -1?\n");
    printf("Unsigned Value is 4294967295 & Signed value is -1 , How?");
    printf("unsigned int 4bytes = bit is 32 bits(2^31)=4294967295\n");
    printf("Easy method of conversation unsigned byte is represent positive like 4294967295 and signed represent MSB=1(negative) so unsigned - signed = conversation like (4294967295-4294967296=-1)\n");
    printf("Same as previous conversation like 16 bit ,signed to unsigned conversation (-12345+65536=53191)\n");
    printf("Another Two complement method is actual method of compailer view");

    //Eamples
    printf("T2U16(-12345) = -12345 + 65536 = %d \n",-12345 + 65536);
    printf("T2U(-1) = -1 + 4294967296 = %u ✓\n",(unsigned)(-1));
    printf("T2U32(-2)     = -2 + 4294967296 = %u\n", (unsigned)(-2));

    printf("\nT2U8 eamples (8-bit):\n");
    for (int x = -4; x <= 4; x++) {
        unsigned char ux = (unsigned char)x;
        printf(" T2U(%3d) = %3d bits: ",x, ux);
        for (int i = 7; i >=0; i--) {
            printf("%d", (ux >> i) &1);
        }
        printf("\n");
    }

    // ====================================
    // U2T: unsigned -> signed formula
    // =======================================
    printf("\n=== U2T FORMULA ===\n");
    printf("U2Tw(u) = u      (if u <= TMax)\n");
    printf("U2Tw(u) = u - 2^w  (if u > TMax)\n\n");

    printf("U2T32(4294967295) = 4294967295 - 429467296 = -1\n");
    printf("U2T32(2147483648) = 2147483648 - 4294967296 = %d\n",(int)2147483648u);  // -2147483648 = TMin

    printf("\n U2T8 examples (8-bit):\n");
    printf("TMax8 = 127\n\n");
    unsigned char vals[] ={0, 127, 128, 200, 255};
    for (int i = 0; i < 5; i++) {
        unsigned char u8 = vals[i];
        signed char s8 = (signed char)u8;
        printf(" U2T(%3u) = %4d %s\n", u8, s8, u8 > 127 ?"(> TMax -> subtract 256)" : "(< TMax -> same)");
    }

    // =======================================
    // FULL 16-BITS MAPPING - Signed vs Unsigned
    // =============================================
    printf("\n==== KEY VALUES - 16-bits ====\n\n");
    printf("Signed   Unsigned    Bits\n");
    printf("_________________________________\n");

    short show_vals[] = {-32768, -12345, -1, 0, 1, 12345, 32767};
    for (int i = 0; i < 7; i++) {
        short s = show_vals[i];
        unsigned short u2 = (unsigned short) s;
        printf("%7d  %7d    ", s, u2);
        for (int j = 15; j >= 0; j--)
            printf("%d", (s >> j) & 1);   
        printf("\n"); 
    }
     return 0;




}

/*
Two's complement method first convert binary -12345 (Signed to unsigned conversation)

=============================================

-12345 to binary conversation 1st method is 
🧠 Method 1: Division by 2 (Most basic & important)

👉 எடுத்துக்கோ: 12345

🔁 Step-by-step divide by 2
12345 ÷ 2 = 6172  remainder 1
6172  ÷ 2 = 3086  remainder 0
3086  ÷ 2 = 1543  remainder 0
1543  ÷ 2 = 771   remainder 1
771   ÷ 2 = 385   remainder 1
385   ÷ 2 = 192   remainder 1
192   ÷ 2 = 96    remainder 0
96    ÷ 2 = 48    remainder 0
48    ÷ 2 = 24    remainder 0
24    ÷ 2 = 12    remainder 0
12    ÷ 2 = 6     remainder 0
6     ÷ 2 = 3     remainder 0
3     ÷ 2 = 1     remainder 1
1     ÷ 2 = 0     remainder 1
📌 Important:

👉 remainders bottom → top படிக்கணும்

= 11000000111001
✅ Final Answer
12345 (decimal) = 11000000111001 (binary)
👉 16-bit formatல:

0011 0000 0011 1001

==============================================

-12345 to binary 2nd method is 
🧠 Method: Divide by 16 (hex base)

👉 hex base = 16
👉 அதனால் 2 இல்ல, 16-ஆ divide பண்ணணும்

🔁 Step-by-step (12345)
12345 ÷ 16 = 771   remainder 9
771   ÷ 16 = 48    remainder 3
48    ÷ 16 = 3     remainder 0
3     ÷ 16 = 0     remainder 3
📌 Important rule

👉 remainders bottom → top படிக்கணும்

3   0   3   9
✅ Final Answer
12345 = 0x3039

🧠 எப்படி check பண்ணுவது?

👉 hex → decimal convert பண்ணி verify பண்ணலாம்:

0x3039 =
3 × 16^3 +
0 × 16^2 +
3 × 16^1 +
9 × 16^0
= 3×4096 + 0 + 3×16 + 9
= 12288 + 48 + 9
= 12345 ✅

⚡ Hex digits reminder
Decimal	Hex
10	A
11	B
12	C
13	D
14	E
15	F

🎯 Final Summary

👉 decimal → hex:

divide by 16
remainders collect
reverse

👉 or:

👉 powers of 16 use பண்ணி build பண்ணலாம்
================================================

we use 2nd method decimal to hex to binary is easy one and this is Actual Two complement method

🧠 Step 1: Positive value convert பண்ணு

முதல்ல 12345 (positive) binary-ஆ மாற்றணும்

12345 (decimal) = 0011 0000 0011 1001  (16-bit)

👉 hex-ஆ நினைச்சுக்கலாம்:

12345 = 0x3039

🧠 Step 2: 1’s complement (flip bits)
0011 0000 0011 1001
↓ flip
1100 1111 1100 0110
🧠 Step 3: +1 add பண்ணு (2’s complement)
1100 1111 1100 0110
+                   1
----------------------
1100 1111 1100 0111
✅ Final Answer:
-12345 (16-bit) = 1100 1111 1100 0111
💥 Quick Shortcut (important 🔥)

👉 Negative number binary:

-x = (2^w - x)

👉 here:

2^16 = 65536
65536 - 12345 = 53191

👉 so:

-12345 = same bits as 53191 (unsigned)
🧠 Check (verification)
1100 1111 1100 0111
= 0xCFC7
= 53191 (unsigned)
= -12345 (signed)
🎯 Final Summary

👉 Steps:

positive number → binary
flip bits
+1

👉 OR shortcut:

- x = 2^w - x

*/

//============================================

/*
Unsigned to signed Conversation (4294967295 to -1)

🧠 Step 1: bits பார்க்கணும் (most important)
4294967295 (unsigned) =
11111111111111111111111111111111   (32 bits)

👉 இதுதான் முக்கியம் — value இல்ல, bits தான் matter

🧠 Step 2: signed ஆக interpret பண்ணு

அதே bits:

11111111111111111111111111111111

👉 signed (two’s complement) rules apply பண்ணணும்

🔥 Rule: MSB (first bit)
1 → negative number

👉 so இது negative

🧠 Step 3: value கண்டுபிடிக்க
Method (flip + 1)
1️⃣ flip bits
11111111111111111111111111111111
↓
00000000000000000000000000000000
2️⃣ +1
00000000000000000000000000000001

👉 result = 1

🎯 Final:
= -1
⚡ இன்னும் easy shortcut

👉 formula:

signed = unsigned - 2^32

👉 apply பண்ணு:

4294967295 - 4294967296 = -1
🧠 Intuition (நல்லா புரிய)

👉 unsigned range:

0 → 4294967295

👉 signed range:

-2147483648 → 2147483647

👉 same bits:

11111111111111111111111111111111
unsigned → max value
signed → last negative (-1)
💥 Wrap-around concept
0
↓ (minus 1)
-1

👉 ஆனால் unsigned worldல:

0 - 1 = 4294967295
🎯 FINAL SIMPLE IDEA

👉 இது தான் answer:

4294967295 (unsigned)
= same bits
= signed-ஆ பார்த்தா
= -1
🧠 One line memory trick
ALL 1 bits → always -1 (signed)

*/
