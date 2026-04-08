#include<stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    for (size_t i = 0; i < len; i++)
         printf("%02x ", start[i]);
    printf("\n");     
}

int main() {

    short sx = -12345; // 16-bit signed
    unsigned uy = sx; // tricky conversation

    printf("sx (short) = %d\n", sx);
    printf("uy (unsigned) = %u\n\n", uy);

    printf("Memory view:\n");

    printf("sx: ");
    show_bytes((byte_pointer)&sx, sizeof(short));

    printf("uy:  ");
    show_bytes((byte_pointer)&uy, sizeof(unsigned));

    return 0;
}