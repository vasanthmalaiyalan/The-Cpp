#include <iostream>
#include <string>

struct Member {

    std::string name;
    size_t size;
    size_t offset;
};

int main() {

    size_t current_offset = 0;

    Member age;

    age.name = "age";
    age.size = sizeof(int);
    age.offset = current_offset;

    current_offset += age.size;

    // align for double

    size_t alignment = alignof(double);

    if (current_offset % alignment != 0) {

        current_offset += alignment - (current_offset % alignment);
    }

    Member salary;

    salary.name = "salary";
    salary.size = sizeof(double);
    salary.offset = current_offset;

    current_offset += salary.size;

    Member grade;

    grade.name = "grade";
    grade.size = sizeof(char);
    grade.offset = current_offset;

    std::cout << age.name << " offset=" << age.offset << "\n";
    std::cout << salary.name << " offset=" << salary.offset << '\n';
    std::cout << grade.name << " offset=" << grade.offset << '\n'; 
}