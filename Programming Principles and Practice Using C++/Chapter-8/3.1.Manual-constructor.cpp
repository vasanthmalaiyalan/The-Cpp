#include <iostream>

struct Date {

    int y;
    int m;
    int d;
};

void init_day(Date& dd, int year, int month, int day) {

    dd.y = year;
    dd.m = month;
    dd.d = day;
}

int main() {

    Date today;     // uninitialized

    std::cout << today.d << '\n'; // BUG

    init_day(today, 2025, 12, 24);
}