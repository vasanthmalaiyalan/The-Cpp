#include <iostream>

class Human {

    public:
       int age;

       void show() {
         
          std::cout << "Age = " << age << '\n';
       }
};

int main() {

    Human h;

    h.age = 25;

    h.show();
}