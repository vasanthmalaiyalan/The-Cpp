#include<stdio.h>

int main() {
    int x = -1;
    unsigned int u = (unsigned int)x;// conversation

    printf("x = %d\n", x);
    printf("After conversation u = %u\n", u);
}

/*

x = -1
After conversation u = 4294967295

*/