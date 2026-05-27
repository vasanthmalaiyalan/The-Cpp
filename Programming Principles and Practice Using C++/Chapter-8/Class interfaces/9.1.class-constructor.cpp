#include <iostream>
#include <stdexcept>

class Date {
    public:
      Date(int yy, int mm, int dd) : y{yy},m{mm}, d{dd} {}

      void print() {
        std::cout << d << '/' << m << '/' << y << '\n';
      }

    private:
       int y;
       int m;
       int d;  
};

int main() {
    Date d1{2025,12,24};
    Date d2 = d1;
    d2.print();
}