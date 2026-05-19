#include <iostream>
#include <vector>
#include <cmath>

int main() {

    std::vector<double> values {

        1.5,
        2.5,
        3.5
    };

    double root = std::sqrt(25);

    std::cout << "sqrt(25) = " << root << '\n';
    std::cout << "values size = " << values.size() << '\n';
}