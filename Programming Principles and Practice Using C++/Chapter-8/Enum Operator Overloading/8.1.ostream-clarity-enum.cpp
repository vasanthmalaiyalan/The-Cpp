#include <iostream>
#include <vector>

enum class Month {

    jan = 1,
    feb,
    mar,
    apr,
    may,
    jun,
    jul,
    aug,
    sep,
    oct,
    nov,
    dec
};

int to_int(Month m) {

    return static_cast<int>(m);
}

std::vector<std::string> month_tbl {

    "Not a month",
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
};

std::ostream& operator<<(std::ostream& os, Month m) {

    return os << month_tbl[to_int(m)];
}

int main() {

    Month m = Month::mar;

    std::cout << m << '\n';
}

/*
 ./a.out
March
*/