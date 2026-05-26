#include <iostream>

enum Month {
    jan = 1,
    feb = 2
};

enum Day {
    monday = 1,
    tuesday = 2
};

int main() {

    Month m = jan;

    if (m == monday) {
        std::cout << "Compiler allowed nonsense\n";
    }
}