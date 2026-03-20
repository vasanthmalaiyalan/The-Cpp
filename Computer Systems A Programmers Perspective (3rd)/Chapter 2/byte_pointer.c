#include<stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    int i;
    for (i = 0; i < len; i++) 
        printf("%.2x ",start[i]);
        printf("%p",&start[i]);
     printf("\n");   
}

void show_int(int x) {
    show_bytes((byte_pointer) &x, sizeof(int));
}

int main() {
    int x = 12345;
    show_int(x);
    return 0; 
}