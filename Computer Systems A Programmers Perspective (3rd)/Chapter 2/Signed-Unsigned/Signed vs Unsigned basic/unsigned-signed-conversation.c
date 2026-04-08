#include<stdio.h>

int main() {
    unsigned int u = 2147483648;
    int x = (int)u;

    printf("u = %u\n", u);
    printf("After Conversation x = %d\n", x);
}