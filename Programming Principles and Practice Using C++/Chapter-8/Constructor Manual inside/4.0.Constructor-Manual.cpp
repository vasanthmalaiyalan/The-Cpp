#include <iostream>
#include <stdexcept>

struct Date {

    int y;
    int m;
    int d;

    Date(int year, int month, int day) {

        if (month < 1 || month > 12) {
            throw std::runtime_error("invalid month");
        }

        if (day < 1 || day > 31) {
            throw std::runtime_error("invalid day");
        }

        y = year;
        m = month;
        d = day;
    }

    void add_day(int n) {
        d += n;
    }
};

int main() {

    Date today(2025,12,13); // direct initialization

    today.add_day(1);

    std::cout << today.d << '/' << today.m << '/' << today.y << '\n';
}