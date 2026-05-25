#include <iostream>

class Date {

    public:
       Date(int y, int m, int d);

       void add_day(int n);

       int month();

    private:
      int y;
      int m;
      int d;   
};

Date::Date(int yy, int mm, int dd) {
    y = yy;
    m = mm;
    d = dd;
}

void Date::add_day(int n) {
    d += n;
}

int Date::month() {
    return m;
}

int main() {
    Date today{2025, 12, 24};
    std::cout << today.month() << '\n';
}