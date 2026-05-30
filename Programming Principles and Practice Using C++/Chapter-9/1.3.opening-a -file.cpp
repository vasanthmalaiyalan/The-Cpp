#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::vector<int> read_numbers(const std::string& file_name) {

    std::ifstream input_file {file_name};

    if (!input_file) {
        throw std::runtime_error("Failed to open file");
    }

    std::vector<int> numbers {};

    int value {};

    while (input_file >> value) {
        numbers.push_back(value);
    }

    return numbers;
}

int main() {

    try {

        const auto numbers = read_numbers("numbers.txt");

        for (int value : numbers) {

            std::cout << value << '\n';
        }
    }

    catch (const std::exception& exception) {

        std::cerr << exception.what() << '\n';
        return 1;
    }
}