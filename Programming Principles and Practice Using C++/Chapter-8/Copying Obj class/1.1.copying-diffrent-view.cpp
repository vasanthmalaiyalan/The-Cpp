#include <iostream>

class Number {
    public:
      Number(int v) : value{v} {
        std::cout << "constructor\n";
      }

    void print() const {

        std::cout << value << '\n';
    }  

    private:
      int value;
};

int main() {
    Number a{10};

    Number b = a;

    b.print();

    Number c{20};

    c.print();

    c = a;

    c.print();

}