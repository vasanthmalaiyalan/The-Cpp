#include <iostream>
#include <string>

int main() {

    std::string name;
    int age;

    std::cout << "Enter you name: ";
    std::getline(std::cin, name);
    
    std::cout << "Enter your age: ";
    std::cin >> age;

    std::cout << "Name: " << name << " Age: " << age << "\n";
}