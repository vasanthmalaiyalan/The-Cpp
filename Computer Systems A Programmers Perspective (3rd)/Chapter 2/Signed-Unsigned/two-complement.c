#include<stdio.h>

// B2T: binary -> two's complement (signed)
int B2T(unsigned char bits, int w) {
    int result =0;

    // MSB (signed bit)
    int sign = (bits >> (w - 1)) & 1;
    if (sign == 1) {
        result -= (1 << (w - 1)); // -2^(w-1)
    }

    //remaining bits
    for (int i = 0; i < w - 1; i++) {
        int xi = (bits >> i) & 1;
        result += xi * (1 << i); //-8+1+2 = -5
    }
    return result;
}

//show function (book style)
void show_B2T(unsigned char bits, int w) {
    printf("[");

    //print bits
    for (int i = w - 1; i >= 0; i--) {
        printf("%d",(bits >> i)) & 1;
    }
    printf("] = ");

    // MSB part
    int sign = (bits >> (w -1)) & 1;
    printf("%dx(-2^%d)",sign,w - 1);

    // rest bits
    for (int i = w - 2; i >= 0; i--) {
        int xi = (bits >> i) & 1;
        printf(" + %dx2^%d", xi,i);
    }
    printf(" = %d\n", B2T(bits, w));
}
int main() {
    printf("======= CSAPP B2T Examples (w = 4) ====\n\n");

    show_B2T(0b0001, 4); //1
    show_B2T(0b0101, 4); //5
    show_B2T(0b1011, 4); //-5
    show_B2T(0b1111, 4); //-1
    
    return 0;
}