#include <iostream>

class Date {
    public:
      class Invalid { };

      Date(int yy, int mm, int dd);

      void add_day(int n);

      bool is_valid();

      int year() { return y; }
      int month() { return m; }
      int day() { return d; }

    private:
       int y;
       int m;
       int d;  
};

Date::Date(int yy, int mm, int dd) : y{yy}, m{mm}, d{dd} {
    if (!is_valid()) {
        throw Invalid{};
    }
}

bool Date::is_valid() {

    return (m >= 1 && m <= 12) && (d >= 1 && d <= 31);
}

void Date::add_day(int n) {

    d += n;
}

std::ostream& operator<<(std::ostream& os, Date d) {
   
    return os << d.year() << '/' << d.month() << '/' << d.day();
}

void f(int x, int y)
try {
    Date dxy{2014,x,y};

    std::cout << dxy << '\n';

    dxy.add_day(2);

    std::cout << dxy << '\n';
}
catch(Date::Invalid) {

    std::cout << "f(): invalid date\n";
}

int main() {
    f(12,24);
    f(15,10);
}

/*
./a.out
2014/12/24
2014/12/26
f(): invalid date

*/