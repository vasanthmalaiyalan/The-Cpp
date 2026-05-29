#include <stdio.h>

int my_snprintf(
    char* buffer,
    int buffer_size,
    const char* format,
    int value
) {

    int temp = value;

    char digits[32];

    int digit_count = 0;

    // ------------------------------------------
    // integer -> string
    // ------------------------------------------

    do {

        digits[digit_count] = (temp % 10) + '0';

        temp /= 10;

        digit_count++;

    } while (temp > 0);

    // -----------------------------------------
    // build output
    // -----------------------------------------

    int pos = 0;

    while ( *format && pos < buffer_size - 1) {

        if (format[0] == '%' && format[1] == 'd') {
            
            int i;

            for (i = digit_count - 1; i >= 0; i--) {
                if ( pos >= buffer_size - 1) {
                    break;
                }

                buffer[pos++] = digits[i];
            }

            format += 2;
        }
    }
}