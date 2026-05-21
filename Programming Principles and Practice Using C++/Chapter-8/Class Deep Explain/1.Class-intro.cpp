#include <iostream>

class Person {
    public:
      int age;
      int height;

      void set_age(int a) {

        age = a;

      }

      void print() {

        std::cout << age << ' ' << height << '\n';
      }
};

int main() {

    Person p;

    p.age = 20; // address + offset

    p.height = 170;

    p.set_age(25);

    p.print();

}