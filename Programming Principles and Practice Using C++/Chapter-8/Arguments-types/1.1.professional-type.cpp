#include <iostream>
#include <stdexcept>

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

struct Year {

    int y;
};

class Date {
    public:
      Date(Year yy, Month mm, int dd) : y{yy}, m{mm}, d{dd} {
        if (dd < 1 || dd > 31) {
            throw std::runtime_error("invalid day");
        }
      }

      void print() const {

        std::cout << y.y << '/' << static_cast<int>(m) << '/' << d << '\n';
      }

    private:
      Year y;
      Month m;
      int d;  
};

int main() {
    Date good {
        Year{1998},
        Month::mar,
        30
    };

    good.print();
}