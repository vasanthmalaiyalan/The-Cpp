#include <iostream>

int main() {

    char text[] = "ABC";

    char* p = text;

    std::cout << "=== for loop: p fixed, i change ====\n";

    for (int i = 0; i < 3; i++) {

        std::cout << "p address : " << (void*)p << '\n';
        std::cout << "i         : " << i << '\n';
        std::cout << "p[i]      : " << p[i] << "\n\n";
    }

    std::cout << "=== p++: i fixed, p changes ===\n";

    p = text;

    for (int i = 0; i < 3; i++) {

        std::cout << "p address : " << (void*)p << '\n';
        std::cout << "i         : " << 0 << '\n';
        std::cout << "p[0]      : " << p[0] << "\n\n";
        p++;
    }

    return 0;
}