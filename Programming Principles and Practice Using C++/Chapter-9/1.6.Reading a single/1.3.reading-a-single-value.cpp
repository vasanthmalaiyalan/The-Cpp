#include <iostream>
#include <limits>
#include <stdexcept>

int get_number_1_to_10() {

    while (true) {
        std::cout << "Enter an integer " << "(1-10): ";

        int value {};

        if (!(std::cin >> value)) {
            if (std::cin.eof()) {
                throw std::runtime_error(
                    "Input closed by user"
                );
            }

            if (std::cin.fail()) {
                std::cout << "Not an integer. "<< "Try again.\n";

                std::cin.clear();

                std::cin.ignore(
                    std::numeric_limits<std::streamsize>::max(), '\n'
                );

                continue;
            }
        }

        if (value < 1 || value > 10) {

            std::cout << "Number must be " << "between 1 and 10.\n";

            continue;
        }

        return value;
    }
}

int main() {
    try {
        const int value = get_number_1_to_10();

        std::cout << "Accepted value: " << value << '\n';
    }
    catch (const std::exception& exception) {
        std::cerr << exception.what() << '\n';

        return 1;
    }
}