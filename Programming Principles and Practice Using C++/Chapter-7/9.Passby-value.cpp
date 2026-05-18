#include <iostream>

// ==========================================
// Pass-by-value function
// ==========================================

int increase(int value) {
    std::cout << "\nInside function BEFORE change:\n";
    std::cout << "value  = " << value << '\n';

    value = value + 1;

    std::cout << "Inside function AFTER change:\n";
    std::cout << "value = " << value << '\n';

    return value;
}

// ==============================================
// Another example
// ==============================================

void multiply_by_two(int number) {

    number = number * 2;

    std::cout << "\nInside multiply _by_two():\n";

    std::cout << "number = " << number << '\n';
}

// =================================================
// Main
// ================================================

int main() {
    int x = 10;

    std::cout << "Before function call:\n";
    std::cout << "x = " << x << '\n';

    int result = increase(x);

    std::cout << "\nAfter function call:\n";

    std::cout << "x = " << x << '\n';
    std::cout << "returned result = " << result << '\n';

    multiply_by_two(x);

    std::cout << "\nAfter multiply_by_two():\n";
    std::cout << "x = " << x << '\n';
}

/*
./a.out
Before function call:
x = 10

Inside function BEFORE change:
value  = 10
Inside function AFTER change:
value = 11

After function call:
x = 10
returned result = 11

Inside multiply _by_two():
number = 20

After multiply_by_two():
x = 10

*/