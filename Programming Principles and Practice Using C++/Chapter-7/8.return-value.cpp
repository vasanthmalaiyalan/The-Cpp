#include <iostream>

// ========================================
// Function returning int
// ========================================

int add(int a, int b) {
    return a + b;
}

// ==========================================
// Function returning double
// ==========================================

double average(int a, int b) {
    return (a + b) / 2.0;
}

// =========================================
// Function with early return
// =========================================

int absolute_value(int x) {

    if (x < 0) {
        return -x;
    }

    return x;
}

// ===========================================
// void function
// ==========================================

void print_until(std::vector<std::string> words, std::string quit) {
    for (std::string word : words) {
        if (word == quit) {
            return;
        }

        std::cout << word << '\n';
    }
}

// ===========================================
// Main
// ===========================================

int main() {
    int sum = add(10, 20);

    std::cout << "Sum : " << sum << '\n';

    double avg = average(10, 20);

    std::cout << "Average : " << avg << '\n';

    int abs_value = absolute_value(-99);

    std::cout << "Absolute value : " << abs_value << '\n';

    std::vector<std::string> words {
        "apple",
        "banana",
        "stop",
        "orange"
    };

    std::cout << "\nPrinting until stop:\n";

    print_until(words, "stop");
}