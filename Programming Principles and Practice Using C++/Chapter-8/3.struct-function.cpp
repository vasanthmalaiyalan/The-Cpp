#include <iostream>

struct Date {

    int y;
    int m;
    int d;
};

bool is_valid_date(int y, int m, int d) {

    if (m < 1 || m > 12)
       return false;

    if (d < 1 || m > 31)
       return false;
       
    return true;   
}

void init_day(Date& dd, int y, int m, int d) {

    if (!is_valid_date(y, m, d)) {
        std::cout << "Invalid date\n";
        return;
    }

    dd.y = y;
    dd.m = m;
    dd.d = d;
}

void add_day(Date& dd, int n) {

    dd.d += n;
}

void print_date(const Date& dd) {

    std::cout << dd.d << '/' << dd.m << '/' << dd.y << '\n';
}

int main() {

    Date today;

    init_day(today, 2025, 12, 24);

    print_date(today);

    add_day(today, 1);

    print_date(today);
}