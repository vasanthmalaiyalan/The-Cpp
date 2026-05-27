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

struct Year {
    int y;
};

class Date {
    public:
      Date() {}

      Date(Year yy) : y{yy} {}

      Date(Year yy, Month mm, int dd) : y{yy}, m{mm}, d{dd} {}

      void print() const {

        std::cout << y.y << '/' << static_cast<int>(m) << '/' << d << '\n';
      }

    private:
      Year y{2001};
      
      Month m = Month::jan;

      int d = 1;
};

int main() {

    Date d1;

    Date d2{Year{2025}};

    Date d3 {
        Year{2025},
        Month::dec,
        24
    };

    d1.print();

    d2.print();

    d3.print();
}

/*
 ./a.out
2001/1/1
2025/1/1
2025/12/24
*/