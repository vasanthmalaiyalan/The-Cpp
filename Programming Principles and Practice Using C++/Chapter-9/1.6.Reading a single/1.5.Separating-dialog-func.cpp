#include <iostream>
#include <stdexcept>

int get_int(int low, int high, std::istream& input_stream) {

    int value {};

    if (!(input_stream >> value)) {
        throw std::runtime_error(
            "Input is not an integer"
        );
    }

    if (value < low || value > high) {
        throw std::out_of_range("Value out of range");
    }

    return value;
}

int main() {
    try {
        std::cout << "Enter age [1-120]: ";

        int age = get_int(1, 120, std::cin);

        std::cout << "Age = " << age << '\n';
    }
    catch (const std::exception& ex) {
        std::cerr << ex.what() << '\n';
    }
}