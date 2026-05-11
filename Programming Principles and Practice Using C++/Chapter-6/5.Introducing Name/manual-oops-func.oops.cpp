#include <iostream>

class Human {

    public:
        int age;
};

// normal function

void show(Human* this_ptr) {

    std::cout << "Age = "
              << this_ptr->age
              << '\n';
}

int main() {

    Human h;

    h.age = 25;

    // Manually passing object address

    show(&h);
}