#include <iostream>
#include <string>
#include <vector>

// ===========================================
// Traditional return syntax
// ===========================================

double multiply(int a, double b) {

    return a * b;
}

// ================================================
// Trailing return syntax
// =================================================

suto divide(double x, double y) -> double {
    
    return x / y;
}

// =============================================
// Longer return type
// =============================================

auto make_names() -> std::vector<std::string> {
    return {
        "Alice",
        "Bob",
        "Charlie"
    };
}

// ==========================================
// Auto return type deduction
// ===========================================

auto square(int x) {

    return x * x;
}

// ===========================================
// Main
// ===========================================

int main() {

    double m = multiple(5, 2.5);

    double d = divide(20, 4);

    auto names = make_name();

    auto s = square(6);

    std::cout << "multiply : " << m << '\n';
    std::cout << "divide   : " << d << '\n';
    std::cout << "square   : " << s << '\n';
    std::cout << "names    : ";

    for (const auto& n : names) {
        std::cout << n << ' '\n
    }

    std::cout << '\n';
}