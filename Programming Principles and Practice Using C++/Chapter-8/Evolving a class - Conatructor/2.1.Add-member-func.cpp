#include <iostream>

class Date {
    private:
      int day;
      int month;
      int year;

    public:
       Date(int d, int m, int y) : day(d), month(m), year(y) {}
       
       int get_day() const {
        return day;
       }

       int get_month() const {
        return month;
       }

       int get_year() const {
        return year;
       }

       void print() const {

        std::cout << day << '/' << month << '/' << year << '\n';
       }

       void add_day(int n) {

          day += n;
       }
};

int main() {

    Date today(23, 5, 2026);

    today.print();

    today.add_day(5);

    today.print();
}