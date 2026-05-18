#include <iostream>
#include <vector>

// =======================================
// Pass-by-value
// =======================================

int increase(int value) {
    value++;

    return value;
}

// ========================================
// Pass-by-const-reference
// =======================================

void print_vector(const std::vector<int>& values) {

    std::cout << "{ ";

    for (int value : values) {

        std::cout << value << ' ';
    }

    std::cout << "}\n";

    // ERROR:
    //
    // values[0] = 100;
}

// ===========================================
// Pass-by-reference
// ===========================================

void initialize(std::vector<int>& values) {

    for (size_t i = 0; i < values.size(); ++i) {

        values[i] = i * 10;
    }
}

// ========================================
// Swap using reference
// ========================================

void swap_values(int& a, int& b) {

    int temp = a;

    a = b;

    b = temp;
}

// =========================================
// Main
// =========================================

int main() {

    // --------------------------------------
    // Pass-by-value
    // ---------------------------------------

    int x = 5;

    int result = increase(x);

    std::cout << "x after increase() : " << x << '\n';
    std::cout << "returned result    : " << result << '\n';

    // ------------------------------------
    // Pass-by-const-reference
    // -------------------------------------

    std::vector<int> numbers(5);

    initialize(numbers);

    std::cout << "\nVector contents:\n";

    print_vector(numbers);

    // ---------------------------------------
    // Pass-by-reference
    // ---------------------------------------

    int a = 10;
    
    int b = 20;

    std::cout << '\nBefore swap"\n';
    std::cout << "a = " << a << " b = " << b << '\n';

    swap_values(a, b);

    std::cout << "\nAfter swap:\n";
    std::cout << "a = " << a << " b = " << b << '\n';

}