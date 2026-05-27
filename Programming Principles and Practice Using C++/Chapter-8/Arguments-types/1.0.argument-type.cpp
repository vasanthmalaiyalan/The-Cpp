#include <iostream>

enum class Month {

    jan = 1,
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

      void print() const {
        std::cout << y << '/' << static_cast<int>(m) << '/' << d << '\n';
      }

    private:
      int y;
      Month m;
      int d;
};

int main() {
    Date d{1998, Month::mar, 30};

    d.print();
}