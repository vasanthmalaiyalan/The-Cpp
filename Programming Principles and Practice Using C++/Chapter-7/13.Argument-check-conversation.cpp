#include <iostream>
#include <vector>

// =====================================
// Function taking double
// =====================================

void print_double(double value) {

    std::cout << "double value = " << value << '\n';
}

// ======================================
// Implicit conversation examples
// ======================================

void implicit_conversion_demo() {
    int i = 7;

    double d = i;

    std::cout << "\nImplicit int -> double:\n";
    std::cout << "i = " << i << '\n';
    std::cout << "d = " << d << '\n';

    print_double(i);
}

// =============================================
// Narrowing conversation
// ==============================================

void narrowing_demo() {

    double pi = 3.14159;

    int x = pi;

    std::cout << "\nNarrowing conversation:\n";
    std::cout << "pi = " << pi << '\n';
    std::cout << "x = " << x << '\n';
}

// ==============================================
// Interger division trap
// ===============================================

void division_demo() {

    int a = 5;

    int b = 2;

    double wrong = a / b;

    double correct = double(a) / b;

    std::cout << "\nDivision demo:\n";
    std::cout << "wrong = " << wrong << '\n';
    std::cout << "correct = " << correct << '\n';
}

// ===========================================
// Character conversation
// ===========================================

void char_demo() {

    char c = 'x';

    int ascii = c;

    std::cout << "\nCharacter conversation:\n";
    std::cout << "char = " << c << '\n';
    std::cout << "ascii = " << ascii << '\n';
}

// ===========================================
// Main
// ===========================================

int main() {

    implicit_conversion_demo();

    narrowing_demo();

    division_demo();

    char_demo();
}

/*
 ./a.out

Implicit int -> double:
i = 7
d = 7
double value = 7

Narrowing conversation:
pi = 3.14159
x = 3

Division demo:
wrong = 2
correct = 2.5

Character conversation:
char = x
ascii = 120
*/