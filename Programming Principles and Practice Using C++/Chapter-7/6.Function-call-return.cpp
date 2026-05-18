#include <iostream>
#include <string>

// =============================================
// Function declaration
// =============================================

double calculate_area(double radius);

void print_result(const std::string& label, double value);

// =================================
// Function definitions
// =================================

double calculate_area(double radius) {
    const double pi = 3.1415926535;

    return pi * radius * radius;
}

void print_result(const std::string& label, double value) {

    std::cout << label << " : " << value << '\n';
}

// ============================================
// Main
// ============================================

int main() {

    // function arguments
    double radius = 5.0;

    // function call + return value
    double area = calculate_area(radius);

    // another function call
    print_result("Circle area", area);
}
