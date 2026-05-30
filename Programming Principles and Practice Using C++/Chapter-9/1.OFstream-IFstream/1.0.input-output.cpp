#include <fstream>
#include <iostream>
#include <string>

namespace {
    constexpr const char* kFileName {"person.txt"};
}

struct Person {
    std::string name;
    int age {};
};

bool save_person(const Person& person) {

    std::ofstream output_file {kFileName}; // output inside fd,buffer,true or false

    if (!output_file) {
        std::cerr << "Failed to create file : " 
                  << kFileName << '\n';
        return false;          
    }

    output_file << person.name << '\n' << person.age << '\n';

    return true;
}

bool load_person(Person& person) {

    std::ifstream input_file {kFileName};

    if (!input_file) {
        std::cerr << "Failed to open file: " << kFileName << '\n';
        return false;
    }

    input_file >> person.name >> person.age;

    return static_cast<bool>(input_file);
}

int main() {

    Person person {};

    std::cout << "Enter name: ";
    std::cin >> person.name;

    std::cout << "Enter age: ";
    std::cin >> person.age;

    if (!std::cin) {

        std::cerr << "Invalid age entered.\n";
        return 1;
    }

    if (!save_person(person)) {
        return 1;
    }

    std::cout << "\nData saved successfully.\n";

    Person loaded_person {};

    if (!load_person(loaded_person)) {
        return 1;
    }

    std::cout << "\nReading from file:\n";
    std::cout << "Name : " << loaded_person.name << '\n';
    std::cout << "Age  : " << loaded_person.age << '\n';

    return 0;
}