#include <iostream>
#include <stdexcept>

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
      Date(int yy, Month mm, int dd) : y{yy}, m{mm}, d{dd} {
        if (dd < 1 || dd > 31) {
            throw std::runtime_error("invalid day");
        }
      }

      int year() const {
        return y;
      }

      Month month() const {
        return m;
      }

      int day() const {
        return d;
      }

      void add_day(int n) {
        d += n;
      }

      private:
        int y;
        Month m;
        int d;
};

std::ostream& operator<<(std::ostream& os, const Date& dt) {
    return os << dt.day() << '/' << static_cast<int>(dt.month()) << '/' << dt.year();
}

int main() {
    Date today{20255,Month::dec,24};

    std::cout << today << '\n';

    today.add_day(1);

    std::cout << today << '\n';
}