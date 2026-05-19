#include <iostream>
#include <string>

// ================================================
// Dangerous global initialization
// ================================================

int x1 = 1;

int y1 = x1 + 2;

// ==========================================
// Simulated Date class
// ===========================================

struct Date {

    std::string value;
};

// ===========================================
// Simulated clock function
// ===========================================

Date get_date_from_clock() { // if you use return type of struct or class names so retrun only object

    std::cout << "Getting current data\n";

    return {"2026-05-19"};
}

// ==========================================
// Safe function-local static
// ==========================================

const Date& today() { // if you use return type of struct or class use this & one ref address return

    static const Date today = get_date_from_clock();

    return today;
}

// =========================================
// Main
// =========================================

int main() {

    std::cout << "x1 = " << x1 << '\n';
    std::cout << "y1 = " << y1 << '\n';

    const Date& d1 = today();
    const Date& d2 = today();

    std::cout << "Today : " << d1.value << '\n';
    std::cout << "Today again : " << d2.value << '\n';
}