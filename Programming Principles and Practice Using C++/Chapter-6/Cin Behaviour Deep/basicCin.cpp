#include <iostream>

int main() {
    std::cout << "Type something and press Enter:\n";

    while (true) {

        char ch;
        std::cin >> ch; // \n skip 

        std::cout << "I got: '" << ch << "'\n";

        if (ch == ';') {
            std::cout << "DONE!\n";
            break;
        }
    }
}