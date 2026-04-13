#include <iostream>
#include <string>

int main() 
{
    std::cout << "Enter name and age: ";

    std::string first_name = "???";
    int age = -1;

    std::cin >> first_name >> age;

    std::cout << "Hello, " << first_name << " (age " << age << ")\n";

    return 0;
}