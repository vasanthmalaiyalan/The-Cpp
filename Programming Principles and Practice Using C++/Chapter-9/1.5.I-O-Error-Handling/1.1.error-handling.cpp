#include <iostream>
#include <fstream>
#include <vector>

std::vector<int> read_numbers(const std::string& file_name) {

    std::ifstream file {file_name};

    file.exceptions(std::ios::badbit | std::ios::failbit);

    std::vector<int> values {};

    int value {};

    while (file >> value) {

        values.push_back(value);
    }

    return values;
}

int main() {
    try {
        const auto values = read_numbers("numbers.txt");

        for (int value : values) {
            std::cout << value << '\n';
        }
    }
    catch (const std::exception& ex) {
        std::cerr << ex.what() << '\n';
    }
}