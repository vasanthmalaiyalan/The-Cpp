#include <iostream>

enum class Month {

    jan=1,
    feb,
    mar,
    apr,
    may,
    jun,
    jul,
    aug,
    sep,
    oct,
    nov,
    dec
};

class Date {
    public:
      Date(int yy, Month mm, int dd) : y{yy}, m{mm}, d{dd} {}
      void print() {
        std::cout << d << '/' << static_cast<int>(m) << '/' << y << '\n';
      }

    private:
      int y;
      Month m;
      int d;  
};

int main() {
    Date d{2025,Month::dec,24};
    d.print();
}