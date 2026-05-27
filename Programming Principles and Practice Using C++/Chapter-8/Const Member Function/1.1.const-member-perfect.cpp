#include <iostream>

enum class Month {
    jan = 1,
    feb,
    mar,
    apr
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

      void add_day(int n) {
        d += n;
      }

    private:
      Year y;
      Month m;
      int d;  
};

void print_date(const Date& dt) {
    std::cout << dt.day() << '/' << static_cast<int>(dt.month()) << '/' << dt.year().y << '\n';
}

int main() {

    const Date today {
        Year{2025},
        Month::mar,
        10
    };

    print_date(today);
}