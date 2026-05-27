#include <iostream>

enum class Month {

    jan = 1,
    feb,
    mar,
    apr,
    may,
    jun,
    jul
};

struct Year {

    int y;
};

class Date {
    public:
      Date(Year yy, Month mm, int dd) : y{yy}, m{mm}, d{dd} {}

      int day() const {
        return d;
      }

      Month month() const {
        return m;
      }

      Year year() const {
        return y;
      }

    private:
       Year y;
       Month m;
       int d;  
};

bool operator==(const Date& a, const Date& b) {
    return a.year().y == b.year().y && a.month() == b.month() && a.day() == b.day();
}

bool operator!=(const Date& a, const Date& b) {
    return !(a == b);
}

int main() {

    Date d1 {
        Year{2025},
        Month::mar,
        10
    };

    Date d2 {
        Year{2025},
        Month::mar,
        10
    };

    if(d1 == d2) {
        std::cout << "same date\n";
    }
}