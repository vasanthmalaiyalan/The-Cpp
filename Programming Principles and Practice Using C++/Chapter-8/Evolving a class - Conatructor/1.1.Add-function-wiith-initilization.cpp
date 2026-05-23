#include <iostream>

struct Date {

    int day;
    int month;
    int year;
};

void print(const Date& d) {

    std::cout << d.day << '/' << d.month << '/' << d.year << '\n';
}

int main() {

    Date today {23, 5, 2026};

    print(today);
}