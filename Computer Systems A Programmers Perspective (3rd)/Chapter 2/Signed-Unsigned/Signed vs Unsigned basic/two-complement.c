#include<stdio.h>
#include<string.h>
#include<math.h>

// Function to convert binary string to decimal using the formula

// Value = -(MSB x 2^(w-1)) + (sum of remaining bits x their place values)
int twos_complement_value(const char *binary, int bits) {
    int value = 0;

    // Calulate value of remaining bits (position bits-2 down to 0)
    for(int i = 1; i < bits; i++) {
        if(binary[i] == '1') {
             value += 1 << (bits - 1 - i);
        }
    }
    //Apply MSB as Negative
    if(binary[0] == '1') {
        value = -(1 << (bits - 1)) + value;
    }

    return value;
}

// Function to convert binary string to unsigned value
unsigned int unsigned_value(const char *binary, int bits) {
    unsigned int value = 0;
    for(int i = 0; i < bits; i++) {
        if(binary[i] == '1') {
           value += 1 << (bits - 1 - i);  // Same as pow(2, bits-1-i)
        }
    }
    return value;
}


int main() {
    // Your binary number
    char binary[] = "1100111111000111";
    int bits = 16;

    printf("Binary: %s (%d bits)\n", binary, bits);
    printf("==================================\n\n");

    // Method 1: Using the formula directly
    printf("Using formula: value = -(MSB x 2^(w-1)) + (remaining bits)\n\n");

    // Extract MSB and remaining bits
    char msb = binary[0];
    char remaining[17];
    strcpy(remaining, &binary[1]);

    printf("MSB = %c\n", msb);
    printf("Remaining bits = %s\n", remaining);
    printf("2^(w-1) = 2^%d = %d\n\n",bits-1, 1 << (bits-1));

    // Calculate remaining bits value
    unsigned int remaining_value = unsigned_value(remaining, bits-1);
    printf("Value of remaining bits (%s) = %u\n", remaining, remaining_value);

    //Apply formula
    int result = -(msb == '1' ? (1 << (bits-1)) : 0) + remaining_value;
    printf("\nResult = -(%d) + %u = %d\n", 1 << (bits-1), remaining_value, result);

    printf("\n===================================\n");
    printf("Final answer: %s₂ = %d\n", binary, result);

    // Verification
    printf("\n=======VERIFICATION===========\n");

    // Method 2: Using two's complement conversation
    unsigned int u = unsigned_value(binary, bits);
    printf("As unsigned: %u\n", u);

    if(binary[0] == '1') {
        int verified = u - (1 << bits);  // u - 2^bits
        printf("As signed (two's complement): %d\n", verified);
        printf("Matches formula? %s\n", verified == result ? "✓ YES" : "✗ NO");
    } else {
        printf("As signed: %d\n", result);
    }

    // Method 3: Show step-by-step calculation
    printf("\n==== STEP-BY-STEP CALCULATION ===\n");
    printf("%s = ", binary);

    // Show MSB term
    if(msb == '1') {
        printf("-(1 x 2^%d) + (", bits-1);
    } else {
        printf("(0 x 2^%d) + (", bits-1);
    }

    // Show remaining bits sum
    printf("%s", remaining);
    printf("₂)\n");
    printf("    = -%d + (", 1 << (bits-1));

    // Show expanded form of remaining bits
    for(int i = 0; i < bits-1; i++) {
        if(remaining[i] == '1') {
            printf("%d", 1 << (bits-2-i));
            // check if not the last 1
            int has_more = 0;
            for(int j = i+1; j < bits-1; j++) {
                if(remaining[j] == '1') {
                    has_more = 1;
                    break;
                }
            }
            if(has_more) printf(" + ");
        }
    }
    printf(")\n");

    printf("    = -%d + %u\n", 1 << (bits-1), remaining_value);
    printf("    = %d\n", result);

    return 0;
}

/*
ouput

Binary: 1100111111000111 (16 bits)
==================================

Using formula: value = -(MSB x 2^(w-1)) + (remaining bits)

MSB = 1
Remaining bits = 100111111000111
2^(w-1) = 2^15 = 32768

Value of remaining bits (100111111000111) = 20423

Result = -(32768) + 20423 = -12345

===================================
Final answer: 1100111111000111₂ = -12345

=======VERIFICATION===========
As unsigned: 53191
As signed (two's complement): -12345
Matches formula? ✓ YES

==== STEP-BY-STEP CALCULATION ===
1100111111000111 = -(1 x 2^15) + (100111111000111₂)
    = -32768 + (16384 + 2048 + 1024 + 512 + 256 + 128 + 64 + 4 + 2 + 1)
    = -32768 + 20423
    = -12345

*/

/*
Key Changes:
Old (with pow)	New (with bit shift)
pow(2, bits-1)	1 << (bits-1)
pow(2, bits-1-i)	1 << (bits-1-i)
pow(2, bits-2-i)	1 << (bits-2-i)
pow(2, bits)	1 << bits
*/

