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
       Date() : y{Year{2001}}, m{Month::jan}, d{1} {}

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
    Date d;

    d.print();
}