#include <fstream>
#include <iostream>
#include <string>

struct Person {
    std::string name;
    int age {};
};

bool save_person(const Person& person) {

    std::ofstream output_file {"person.txt"};

    if (!output_file) {
        std::cerr << "Failed to create file.\n";
        return false;
    }

    output_file << person.name << '\n'
                << person.age << '\n';

    return true;            
}

bool load_person(Person& person) {

    std::ifstream input_file {"person.txt"};

    if (!input_file) {
        std::cerr << "Failed to open file.\n";
        return false;
    }

    input_file >> person.name >> person.age;

    return static_cast<bool>(input_file);
}

int main() {

    Person person {};

    std::cout << "Enter name : ";
    std::cin  >> person.name;

    std::cout << "Enter age: ";
    std::cin >> person.age;

    if (!save_person(person)) {
        return 1;
    }

    Person loaded_person {};

    if (!load_person(loaded_person)) {
        return 1;
    }

    std::cout << "\nDate read from file\n";
    std::cout << "Name : " << loaded_person.name << '\n';
    std::cout << "Age  : " << loaded_person.age << '\n';
}

/*
 ./a.out
Enter name : king
Enter age: 23

Date read from file
Name : king
Age  : 23
*/