#include <iostream>
#include <string>

int main() 
{
    int age;
    std::string name;

    std::cout << "Enter you age: ";
    std::cin >> age; // cin use operator >> so only read age like 25 not newline -> \n

    std::cin.ignore(1000, '\n'); // best practice

    std::cout << "Enter you Name: ";
    std::getline(std::cin, name); // without operator >> so read getline function way in use cin

    std::cout << "Age: " << age << "\n";
    std::cout << "Name: " << name << "\n";

    return 0;
}