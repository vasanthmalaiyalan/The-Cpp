#include <iostream>

struct Person {

    int age;
    int height;
};

void Person_set_age(Person* this_ptr, int a) {

    this_ptr->age = a;
}

void Person_print(Person* this_ptr) {

    std::cout << this_ptr->age << ' ' << this_ptr->height << '\n';
}

int main() {

    Person p;

    p.age = 20;
    p.height = 170;

    Person_set_age(&p, 25);
    
    Person_print(&p);
}