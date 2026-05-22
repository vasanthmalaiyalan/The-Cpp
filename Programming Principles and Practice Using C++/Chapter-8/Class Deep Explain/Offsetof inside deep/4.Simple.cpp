#include <iostream>

struct Employee {

    char id;
    int age;
    double salary;
};

int main() {

    void* addr = &((Employee*)0)->age;

    std::cout << "As pointer (hex) : " << addr << '\n';
    std::cout << "As size_t (int) : " << (size_t)addr << "\n";
}