#include <iostream>
#include <stdexcept>

struct Date {

    int y;
    int m;
    int d;

    Date (int year, int month, int day);

    void add_day(int n);
};

Date::Date(int year, int month, int day) {
    if (month < 1 || month > 12) {
        throw std::runtime_error("invaild month");
    }

    if (day < 1 || day > 31) {
        throw std::runtime_error("invaild day");
    }

    y = year;
    m = month;
    d = day;
}

void Date::add_day(int n) {
    d += n;
}

int main() {

    Date last{2025, 12, 31};

    last.add_day(1);

    std::cout << last.d << '/' << last.m << '/' << last.y << '\n';
}