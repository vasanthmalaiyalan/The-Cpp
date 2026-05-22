#include <iostream>

class X {

    private:
       int m;

       int mf(int value) {

           return value * 2;
       }

    public:
       int f(int i) {

          m = i;
          return mf(i);
       }   
};

int main() {

    X x;

    int y = x.f(2);

    std::cout << y << '\n';
}