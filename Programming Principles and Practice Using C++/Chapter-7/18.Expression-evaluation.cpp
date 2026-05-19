#include <iostream>
#include <vector>

int f(int x) {

    std::cout << "f(" << x << ")\n";
    return x + 1;
}

int g(int y) {

    std::cout << "g(" << y << ")\n";

    return y * 2;
}

int main() {

    int i = 1;

    // ======================================
    // Dangerous expression
    // ======================================

    // BAD:
    // 
    // int = ++i + i;

    // BAD:
    //
    // f (++i, ++i);

    // =====================================
    // Safe version
    // =======================================

    ++i;

    int x = i + i;

    std::cout << "x = " << x << '\n';

    // ======================================
    // Function evaluation order
    // ======================================

    int fx = f(10);

    int gy = g(20);

    int z = fx + gy;

    std::cout << "z = " << z << '\n';

    // ===================================
    // Short-circuit evaluation
    // ===================================

    std::vector<int> v {1, 2, 3};

    int index = -1;

    if (0 <= index && index < v.size() && v[index] != 0) {

        std::cout << "Vaild access\n";
    }
    else {
        std::cout << "Invaild access avoided\n";
    }

    // ======================================
    // Left-to-right stream evaluation
    // ======================================

    int n = 1;

    std::cout << ++n << ' ' << ++n << '\n';
}