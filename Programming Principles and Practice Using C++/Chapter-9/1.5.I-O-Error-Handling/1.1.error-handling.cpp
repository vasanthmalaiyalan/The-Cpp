#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

std::vector<int> read_numbers(const std::string& file_name) {

    std::ifstream file;

    file.exceptions(std::ios::badbit | std::ios::failbit);

    file.open(file_name);

    std::vector<int> values {};

    int value {};

    while (file >> value) {

        values.push_back(value);
    }

    return values;
}

int main() {

    std::ofstream create_file("nmbers.txt");
    create_file << "123 2345 456 12";
    create_file.close();

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