#include <iostream>

class X {

    private:
       int m; // private member

    public:
       void set_m(int value) {

           m = value;
       }  
       
       int get_m() {

           return m;
       }
};

int main() {

    X x;

    x.set_m(10);

    std::cout << x.get_m() << '\n';

    // x.m = 20; // ERROR: m is private

    return 0;
}