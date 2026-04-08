#include<stdio.h>

int main() {
    int x = -1;

    printf("Using %%d: %d\n", x);
    printf("Using %%u: %u\n", x);

    return 0;
}

/*
Using %d: -1
Using %u: 4294967295
*/