#include <iostream>
#include <stdexcept>

class Date {

    private:
      int y;
      int m;
      int d;

    public:
       Date(int year, int month, int day) {
         if (month < 1 || month > 12) 
            throw std::runtime_error("invaild month");

         if (day < 1 || day > 31)
            throw std::runtime_error("invaild day");    

       y = year;
       m = month;
       d = day;
}

int year() {
    return y;
}

int month() {
    return m;
}

int day() {
    return d;
}

void add_day(int n) {
    d += n;
}
};

int main() {

    Date birthday{1970, 12, 30};

    std::cout << birthday.day() << '/' << birthday.month() << '/' << birthday.year() << '\n';
}