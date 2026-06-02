#include <iostream>
#include <limits>
#include <stdexcept>

void skip_to_int() {
    if (std::cin.fail()) {
        std::cin.clear();
        char ch {};
        while (std::cin.get(ch)) {
            if (std::isdigit(
                static_cast<unsigned char>(ch)) || ch == '-') {
                    std::cin.unget();
                    return;
                }
        }
    }
    throw std::runtime_error("
        No valid input available");
}

int get_int() {
    while (true) {
        int value {};

        if (std::cin >> value) {
            return value;
        }

        std::cout << "Not an integer. " << "Try again.\n";

        skip_to_int();
    }
}

int get_int(int low, int high) {
    while (true) {
        const int value = get_int();
        if (low <= value && value <= high) {
            return value;
        }
        std::cout << value << " is outside range [" << low << ':' << high << "]\n";

    }
}

int main() {
    try {
        const int_age = get_int(1, 120);

        std::cout << "Age: " << age << '\n';

        const int score = get_int(0, 100);

        std::cout << "Score: " << score << '\n';
    }
    catch (const std::exception& exception) {
        std::cerr << exception.what() << '\n';

        return 1;
    }
}