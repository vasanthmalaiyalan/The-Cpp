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
      Date(Year yy, Month mm, int dd) : y{yy}, m{mm}, d{dd} {}

      void print() const {
        std::cout << y.y << '/' << static_cast<int>(m) << '/' << d << '\n';
      }

    private:
       Year y;
       Month m;
       int d;  
};

int main() {

    Date holiday {

        Year{1978},
        Month::jul,
        4
    };

    Date d2 = holiday;

    Date d3 = Date {
        Year{1978},
        Month::dec,
        24
    };

    holiday = Date {
            Year{1978},
            Month::dec,
            25
        
    };

    d2.print();
    d3.print();
    holiday.print();
}

/*
 ./a.out
1978/7/4
1978/12/24
1978/12/25
*/