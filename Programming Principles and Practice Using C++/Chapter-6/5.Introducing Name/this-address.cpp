#include <iostream>

class Dog {

    public:
       
        int weight;

        void print_address() {

            std::cout << "this = "
                      << this
                      << '\n';
        }
};

int main() {

    Dog d1;
    Dog d2;

    d1.print_address();
    d2.print_address();
}