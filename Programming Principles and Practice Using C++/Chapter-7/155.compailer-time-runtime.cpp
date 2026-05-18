#include <iostream>

// ======================================
// Point structure
// =======================================

struct Point {
    double x;
    double y;
};

// =========================================
// Comapile-time constants
// ==========================================

constexpr double xscale = 10;
constexpr double yscale = 0.8;

// ==========================================
// constexpr function
// ===========================================

constexpr Point scale(Point p) {

    return {
        xscale * p.x;
        yscale * p.y;
    };
}

// ===========================================
// consteval function
// ==========================================

constexpr Point scale(Point p) {

    return {
        xscale * p.x,
        yscale * p.y
    };
}

// =============================================
// consteval function
// =============================================

consteval double half(double d) {

    return d / 2;
}

// ===========================================
// Main
// ===========================================

int main() {

    int x = 5;
    int y = 8;

    // runtime object
    Point p1 {x , y};

    // compaile-time object
    constexpr Point p2 {10, 10};

    // runtime evaluation
    Point p3 = scale(p1);

    // compile-time evaluation
    constexpr Point p4 = scale(p2);

    std::cout << "p3 : " << p3.x << ", " << p3.y << '\n';
    std::cout << "p4 : " << p4.x << ", " << p4.y << '\n';

    // compailer-time only
    double h1 = half(8);

    std::cout << "half(8) = " << h1 << '\n';

    // ERROR:
    //
    // double h2 = half(x);
}