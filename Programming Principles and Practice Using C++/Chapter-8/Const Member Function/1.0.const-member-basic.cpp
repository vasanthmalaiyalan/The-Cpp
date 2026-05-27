#include <iostream>

enum class Month {

    jan = 1,
    feb,
    mar
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

int main() {

    Date d {

        Year{2000},
        Month::jan,
        20
    };

    const Date cd {

        Year{2001},
        Month::feb,
        21
    };

    std::cout << d.day() << '\n';
    std::cout << cd.day() << '\n';

    d.add_day(1);
    //cd.add_day(1);

    std::cout << d.day() << '\n';
}

/*
 ./a.out
20
21
21
*/