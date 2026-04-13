#include <iostream>
#include <string>

int main() {
    // Prompt
    std::cout << "Please enter your first name:\n";
    
    // Variable (object)
    std::string first_name;

    // Input
    std::cin >> first_name;

    // Output
    std::cout << "Hello, " << first_name << "!\n";

    return 0;
}
