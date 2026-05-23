#include <iostream>

struct Date {

    int day;
    int month;
    int year;
};

int main() {

    Date today;

    today.day = 23;
    today.month = 5;
    today.year = 2026;

    std::cout << today.day << '/' << today.month << '/' << today.year << '\n';
}