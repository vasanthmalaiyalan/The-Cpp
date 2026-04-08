#include<stdio.h>

int main() {
    int x = -1;
    unsigned int u = 1;

    printf("Signed x = %d\n", x); //separate
    printf("Unsigned u = %u\n", u);// separate
    printf("x as unsigned = %u\n", x); //same bits-> different meaning


    return 0;
}

/*

Signed x = -1
Unsigned u = 1
x as unsigned = 4294967295

*/