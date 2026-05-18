#include <iostream>
#include <vector>

// ============================================
// Pass-by-value (copies vector)
// ============================================

void print_by_value(std::vector<int> numbers) {
    
    std::cout << "\nInside print_by_value():\n";

    numbers[0] = 999;

    for (int value : numbers) {
        std::cout << value << ' ';
    }

    std::cout << '\n';
}

// ===========================================
// Pass-by-const-reference
// ===========================================

void print_by_const_reference(const std::vector<int>& numbers) {
    std::cout << "\nInside print_by_by_const_reference():\n";

    for (int value : numbers) {
        std::cout << value << ' '; 
    }

    std::cout << '\n';

    // ERROR if uncommented:
    //
    // numbers[0] = 500;
}

// ============================================
// String example
// ===========================================

bool constains_word(const std::string& text, const std::string& word) {

    return text.find(word) != std::string::npos;
}

// ==========================================
// Main
// ===========================================

int main() {

    std::vector<int> values {
        10,
        20,
        30
    };

    std::cout << "Original vector:\n";

    for (int value : values) {

        std::cout << value << ' ';
    }

    std::cout << '\n';

    // pas-by-value
    print_by_value(values);

    std::cout << "\nAfter print_by_value():\n";

    for (int value : values) {

        std::cout << value << ' ';
    }

    std::cout << '\n';

    // pass-by-const-reference
    print_by_const_reference(values);

    std::string text = "Modern C++ is powerfull";

    bool found = constains_word(text, "powerful");

    std::cout << "\nContains words? " << found << '\n';
}