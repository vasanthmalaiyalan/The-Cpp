#include <iostream>
#include <stdexcept>

class Date {
    public:
      Date(int yy, int mm, int dd);

      void add_day(int n);

      int year();
      int month();
      int day();

    private:
      int y;
      int m;
      int d;  
};

Date::Date(int yy, int mm, int dd) : y{yy}, m{mm}, d{dd} {
    if (mm < 1 || mm > 12) 
       throw std::runtime_error("invalid month");

    if (dd < 1 || dd > 31) 
       throw std::runtime_error("invalid day");   
}

void Date::add_day(int n) {
    d += n;
}

int Date::year() {
    return y;
}

int Date::month() {
    return m;
}

int Date::day() {
    return d;
}

std::ostream& operator<<(std::ostream& os, Date d) { // os stream is a actual class of cout 
    
    return os << d.year() << '/' << d.month() << '/' << d.day();
}

int main() {

    Date today{2025,12,24};

    std::cout << today << '\n';

    today.add_day(1);

    std::cout << today << '\n';
}