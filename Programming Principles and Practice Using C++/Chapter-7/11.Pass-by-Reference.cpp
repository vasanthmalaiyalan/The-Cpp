#include <iostream>
#include <vector>

// =============================================
// Pass-by-reference modifies original
// =============================================

void initialize(std::vector<double>& values) {
    for (int i = 0; i < values.size(); ++i) {
        values[i] = i * 10;
    }
}

// ==============================================
// Reference as alias
// ==============================================

void reference_demo() {

    int x = 7;

    int& r = x;

    std::cout << "\nBefore modification:\n";

    std::cout << "x = " << x << '\n';
    std::cout << "r = " << r << '\n';

    r = 100;

    std::cout << "\nAfter modifying r :\n";

    std::cout << "x = " << x << '\n';
    std::cout << "r = " << r << '\n';
}

// =============================================
// Swap using references
// =============================================

void swap_values(double& a, double& b) {

    double temp = a;

    a = b;

    b = temp;
}

// ===============================================
// Main
// ==============================================

int main() {

    // -----------------------------------------
    // Vector modification
    // -------------------------------------------

    std::vector<double> numbers(5);

    initialize(numbers);

    std::cout << "Initialized vector:\n";

    for (double value : numbers) {

        std::cout << value << ' ';
    }

    std::cout << '\n';

    // -----------------------------------
    // Reference alias demo
    // -------------------------------------

    reference_demo();

    // -------------------------------------
    // Swap demo
    // --------------------------------------

    double x = 1.5;
    double y = 9.5;

    std::cout << "\nBefore swap:\n";
    std::cout << "x = " << x << " y = " << y << '\n';

    swap_values(x, y);

    std::cout << "\nAfter swap:\n";
    std::cout << "x = " << x << " y = " << y << '\n';

}