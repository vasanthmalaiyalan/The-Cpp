#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

int main() {

    int keyboard_age {};
    int file_age {};
    int string_age {};

    // Keyboard stream
    std::cout << "Enter age: ";
    std::cin  >> keyboard_age;

    // File stream
    std::ifstream input_file {"age.txt"};

    if (input_file) {

        input_file >> file_age;
    }

    // String stream
    std::istringstream input_string {"99"};

    input_string >> string_age;

    std::cout << "\nResults\n";
    std::cout << "keyboard age : " << keyboard_age << '\n';
    std::cout << "File age     : " << file_age << '\n';
    std::cout << "String age   : " << string_age   << '\n';
}

/*
 ./a.out
Enter age: 23

Results
keyboard age : 23
File age     : 0
String age   : 99
*/