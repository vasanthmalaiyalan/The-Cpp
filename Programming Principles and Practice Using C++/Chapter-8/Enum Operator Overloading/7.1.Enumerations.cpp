#include <iostream>
#include <stdexcept>

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

Month int_to_month(int x) {

    if (x < to_int(Month::jan) || x > to_int(Month::dec)) {

        throw std::runtime_error("bad month");
    }

    return Month{x};
}

int main() {
    try {
        Month m = int_to_month(7);

        std::cout << to_int(m) << '\n';
    }
    catch(const std::exception& e) {
        std::cout << e.what() << '\n';
    }
}