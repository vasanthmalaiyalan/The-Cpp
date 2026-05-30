#include <iostream>
#include <sstream>
#include <string>

int main() {

    std::string input {};

    std::cout << "Enter age: ";
    std::cin  >> input; // string gather

    std::istringstream ss {input}; 

    int age {};
    ss >> age; // string to int

    if (!ss) {
        std::cerr << "Invalid Enter a number.\n";
        return 1;
    }

    std::cout << "Your age is: " << age << '\n';
    return 0;
}

/*
./a.out
Enter age: 23
Your age is: 23
*/