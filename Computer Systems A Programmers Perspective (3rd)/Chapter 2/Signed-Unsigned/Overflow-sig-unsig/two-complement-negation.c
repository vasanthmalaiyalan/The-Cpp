#include<stdio.h>
#include<limits.h>

// Check if x is its own negation (Tmin case)
int is_TMin(int x) {
    return x == INT_MIN;
}

int main() {

    int test[] = {
        5,
        -5,
        123,
        INT_MIN // Special case -> -2147483648
    };

    int n = sizeof(test) / sizeof(test[0]);

    printf("========= Two's Complement Negation Demo ==========\n\n");

    for (int i = 0; i < n; i++) {

        int x = test[i];
        int neg = -x;

        printf("x = %d\n", x);
        printf("-x = %d\n", neg);

        // check special case
        if (is_TMin(x)) {
            printf(" Special Case: x is INT_MIN\n"); //-2147483648
            printf(" -x == x (no positive representation)\n");
        }

        // verify property
        printf("x + (-x) = %d\n", x + neg);

        printf("---------------------------------\n");
    }
    return 0;
}