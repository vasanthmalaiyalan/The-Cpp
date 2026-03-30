#include<stdio.h>
#include<stdint.h>

    // Bits print 
    void show_bits_32(uint32_t x) {
        for (int i = 31; i >= 0; i--) 
            printf("%d", (x >> i) & 1); 
    }

    // Two's Complement forward: -1 -> 0xFFFFFFF
    uint32_t twos_complement_forward(uint_t positive) {
        uint32_t flipped = ~positive; // flip all bits
        uint32_t result = flipped + 1; //add 1
        return result;
    }

    // Two''s complement reverse: oxFFFFFFFF -> 1 (magnitude)
    uint32_t twos_complement_reverse(uint32_t bits) {
        uint32_t flipped = ~bits; // flip all bits
        uint32_t result = flipped + 1; // add 1
        return result;
    }

    int main() {

        //===================================
        // STEP 1: COMPILE TIME - -1 memory execution time
        //====================================
        printf("=============================\n");
        printf("  STEP 1: COMPILE TIME        \n");
        printf("=============================\n\n");

        printf("Source code: int x = -1;\n\n");

        printf("Compiler sees '-' token -> negative number\n\n");

        // +1 binary
        uint32_t positive = 1;
        printf("Positive version (+1):\n");
        printf(" Binary: ");
        show_bits_32(positive);
        printf("\n");
        printf("  Hex:    0x%08X\n\n", positive);

        // Flip
        uint32_t flipped = ~positive;
        printf("Flip all bits: \n");
        printf("  Binary: ");
        show_bits_32(flipped);
        printf("\n");
        printf(" Hex:   0x%08x\n\n", flipped);

        // Add 1
        uint32_t stored = flipped + 1;
        printf("Add 1:\n");
        printf("  Binary:  ");
        show_bits_32(stored);
        printf("\n");
        printf("  Hex:    0x%08X\n\n", stored);

        printf("Assembly emit: mov [x], 0x%08X\n\n", stored);

        // ====================================
        // STEP 2: RUNTIME - CPU RAM Store
        // =====================================

        printf("===============================\n");
        printf("   STEP 2: RUNTIME - CPU Stores \n");
        printf("=================================\n\n");

        int x = -1; // actual variable
        uint32_t *raw = (uint32_t *)&x;

        printf("Cpu execute: mov [x], 0xFFFFFFFF\n\n");
        printf("RAM Content: \n");
        printf("   Address: 0x100  0x101  0x102  0x103\n");
        printf("  Byte:  FF  FF  FF  FF  FF\n");
        show_bits_32(*raw);
        printf("\n");
        printf("  Hex:      0x%08X\n\n",  *raw);
        printf("CPU done. No more work. Just bits in Ram.\n\n");

        // =====================================
        //  STEP 3: RUNTIME - printf call
        // ======================================
        printf("================================\n");
        printf("||  STEP 3: RUNTIME - Printf  ||\n");
        printf("================================\n\n");

        printf("printf(\"%%u %%dd\", x , x) called\n\n");

        printf("CPU: RAM-லிருந்து 0x%08X எடு\n\n", *raw);

        // %u PATH
        printf("----%%u path (unsigned) ---\n");
        printf("  Direct conversion, no flip\n");
        printf("  0xFFFFFFFF -> %u\n\n", (unsigned int)*raw);

        // %d path
        printf("----- %%d path (signed) -----\n");
        printf("  MSB Check: bit 31 = %d\n", (*raw >> 31) & 1);
        printf("  MSB = 1 -> NEGATIVE!\n");
        printf("  Reverse two's complement:\n");

        unint32_t magnitude = twos_complement_reverse(*raw);
        printf("    flip 0x%08X  -> 0x%08X\n", *raw, ~(*raw));
        printf("    +1     -> 0x%08X = %u\n", magnitude, magnitude);
        printf("   Add '-' signed -> -%u\n\n", magnitude);

        // Actual printf
        printf("----- ACTUAL OUTPUT -----\n");
        printf("printf(\"x = %%u = %%d\\n\",x,x):\n");
        printf("x = %u = %d\n\n", x , x);

        // =====================================
        // FULL PICTURE - Forward and Reverse
        // ======================================
        printf("==================================\n");
        printf("   FULL PICTURE             \n");
        printf("=================================\n\n");

        printf("FORWARD (Compailer time):\n");
        printf("  -1 -> flip+1 -> 0xFFFFFFFF -> RAM\n\n");

        printf("RUNTIME:\n");
        printf("  RAM: 0XFFFFFFFF\n");
        printf("       ↓           ↓\n");
        printf("      %%u          %%d\n");
        printf("       ↓           ↓\n");
        printf("   direct       reverse flip+1\n");
        printf("       ↓           ↓\n");
        printf("  429497295      -1\n\n");

        printf("KEY INSIGHT:\n");
        printf("  flip+1 is its own inverse!\n");
        printf("   forward:   -1 -> flip+1 -> 0xFFFFFFFF\n");
        printf("    reverse:  0xFFFFFFFF -> flip+1 -> 1 -> add '-' -> -1\n\n");

        // ==================================
        // MORE VALUES - -1, -2, -3, -128
        // ==================================

        int values[] = {-1, -2, -3, -128, -2147483648};
        int n = 5;

        printf("Value Forward(RAM)  %%u       %%d\n");
        printf("_________________________________\n");

        for (int i = 0; i < n; i++) {
            int v = value[i];
            uint32_t *bits   = (uint32_t *)&v;
            printf("%-6d 0x%08X    %-12u  %d\n",v, *bits, (unsigned)*bits, v);
        }

        printf("\n");
        printf("Pattern: larger negative -> smaller 0xFFFF....value\n");
        printf("   -1 -> 0xFFFFFFFF (all 1s)\n");
        printf("   -2 -> 0xFFFFFFFE (last bit 0)\n");
        printf("   -128 -> 0xFFFFFF80\n");

        //====================================
        // SAME OPERATION PROOF
        // ======================================
        printf("\n ===============================\n");
        printf("||    PROOF: flip+1 = its own inverse   ||");
        printf("=================================\n\n");

        uint32_t original = 1; // +1
        uint32_t forward = twos_complement_forward(original); // 0xFFFFFFFFFF
        uint32_t reverse = twos_complement_reverse(forward); // 1 again

        printf("Start:   %u (0x%08X)\n",original, original);
        printf("Forward:  0x%08X (stored in RAM)\n", forward);
        printf("Reverse:  %u (0x%08X) <- same as start!\n\n",reverse, reverse);
        printf("flip+1 applied twice = original value \n");

        return 0;

    }