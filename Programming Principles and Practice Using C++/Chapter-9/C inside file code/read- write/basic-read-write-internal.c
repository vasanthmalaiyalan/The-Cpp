#include <stdio.h>

int main() {

    char fake_file[100];

    const char* text = "Tony Stark";

    int len = 0;

    while (text[len] != '\0') {

        len++;
    }

    printf("strlen = %d\n", len);

    for (int i = 0; i < len; i++) {

        fake_file[i] = text[i];
    }

    fake_file[len] = '\0';

    printf("file contains: %s\n", fake_file);

    char buffer[100];

    int bytes = 0;

    while (fake_file[bytes] != '\0') {

        buffer[bytes] = fake_file[bytes];

        bytes++;
    }

    buffer[bytes] = '\0';

    printf("read result: %s\n", buffer);
}

/*
 ./a.out
strlen = 10
file contains: Tony Stark
read result: Tony Stark
*/