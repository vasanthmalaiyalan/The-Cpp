#include <iostream>

class Counter {

    public:
      Counter(int v) : value{v} {}

      void increase() {
        value++;
      }

      int get() {
        return value;
      }

    private:
      int value;  
};

int main() {

    Counter c1{10};
    Counter c2{100};

    c1.increase();

    std::cout << c1.get() << '\n';
    std::cout << c2.get() << '\n';
}