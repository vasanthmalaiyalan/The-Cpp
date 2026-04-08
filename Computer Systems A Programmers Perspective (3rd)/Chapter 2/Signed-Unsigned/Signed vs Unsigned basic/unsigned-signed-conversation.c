#include<stdio.h>

int main() {
    unsigned int u = 2147483648;//already in memory 2^31=2147483648, so 1000..etc
    int x = (int)u; //just MSB added 

    printf("u = %u\n", u);
    printf("After Conversation x = %d\n", x);
}

/*
u = 2147483648
After Conversation x = -2147483648
*/