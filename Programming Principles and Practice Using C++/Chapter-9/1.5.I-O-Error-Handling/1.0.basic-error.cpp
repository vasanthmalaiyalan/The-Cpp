#include <iostream>

int main() {

    int age {};

    while (true) {

        std::cout << "Enter age: ";

        if (std::cin >> age) {
            break;
        }

        std::cout << "Invalid input\n";

        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }

    std::cout << "Age = " << age << '\n';
}