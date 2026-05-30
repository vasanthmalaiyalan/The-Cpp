#include <iostream>
#include <sstream>
#include <string>

int main() {

    std::string line {"John 25 75.5"};

    std::istringstream ss {line};

    std::string name {};
    int age {};
    double weight {};

    ss >> name >> age >> weight; // seprately 

    std::cout << "Name   : " << name << '\n'; // John
    std::cout << "Age    : " << age  << '\n'; // 25
    std::cout << "Weight : " << weight << '\n'; // 75.5
}