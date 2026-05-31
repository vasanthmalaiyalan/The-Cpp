#include <fstream>
#include <iostream>
#include <string>
#include <vector>

void fill_vector(
    std::istream& input_stream,
    std::vector<int>& values,
    char terminator
) {

   for (int value {}; input_stream >> values;) {
        values.push_back(values);
   }

   if (input_stream.eof()) {
      std::cout << "[INFO] End of file reached\n";

      return;
   }

   if (input_stream.fail()) {
      input_stream.clear(); // failbit ஐ அழி

      char character {};

      input_stream >> character; // அடுத்த character படி

      if (character == terminator) {

        std::cout << "[INFO] Terminator found: " << character << '\n';

        return;
      }

      input_stream.unget();

      input_stream.clear(std::ios::failbit);

      throw std::runtime_error(
          "Unexpected character in input");
   }
}

int main() {

    std::ofstream create_file("intnumbers.txt"); // file create
    create_file << "34,234,1235,567,11111111"; // file write
    create_file.close();

    try {

        std::ifstream input_file {"numbers.txt"};

        if (!input_file) {
            throw std::runtime_error(
                "Cannot open file");
        }

        input_file.exceptions(
            input_file.exceptions() 
            | std::ios::badbit);

        std::vector<int> numbers {};
        
        fill_vector(
            input_file,
            numbers,
            '*');

        std::cout << "\nNumbers read:\n";
        
        for (int value : numbers) {

            std::cout << value << '\n';
        }

        std::cout << "\nFinal stream state:\n";

        std::cout << "good(): " << input_file.good() << '\n';
        std::cout << "eof(): " << input_file.of() << '\n';
        std::cout << "fail(): " << input_file.fail() << '\n';
        std::cout << "bad(): " << input_file.bad() << '\n';
    }
    catch (const std::exception& exception) {
        std::cerr << "Error: " << exception.what() << '\n';
        return 1;
    }
}