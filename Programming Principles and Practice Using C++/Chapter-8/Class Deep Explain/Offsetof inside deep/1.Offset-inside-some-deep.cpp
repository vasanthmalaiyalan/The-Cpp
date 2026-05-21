#include <iostream>
#include <cstddef> // offset

struct Person {

    int age;
    int height;
};

void Person_set_age(Person* this_ptr, int a) {

    std::cout << "\n[Person_set_age]\n";

    std::cout << "this_ptr      : " << this_ptr << '\n';
    std::cout << "age offset    : " << offsetof(Person, age) << '\n';
    std::cout << "height offset : " << offsetof(Person, height) << '\n';

    // compailer conception knows:
    // age offset = 0

    this_ptr->age = a;
}

int main() {

    Person p;

    p.age = 20;
    p.height = 170;

    std::cout << "[Object Layout]\n";
    std::cout << "object address  : " << &p << '\n';
    std::cout << "age address     : " << &p.age << '\n';
    std::cout << "height address  : " << &p.height << '\n';
    
    std::cout << "\nOffsets\n";
    std::cout << "age offset      : " << offsetof(Person, age) << '\n';
    std::cout << "height offset   : " << offsetof(Person, height) << '\n';

    Person_set_age(&p, 25);

    std::cout << "\nAfter update\n";
    std::cout << "age   : " << p.age << '\n';
    std::cout << "height : " << p.height << '\n';
}

/*
 ./a.out
[Object Layout]
object address  : 0x7ffefd18d930
age address     : 0x7ffefd18d930
height address  : 0x7ffefd18d934

Offsets
age offset      : 0
height offset   : 4

[Person_set_age]
this_ptr      : 0x7ffefd18d930
age offset    : 0
height offset : 4

After update
age   : 25
height : 170
*/