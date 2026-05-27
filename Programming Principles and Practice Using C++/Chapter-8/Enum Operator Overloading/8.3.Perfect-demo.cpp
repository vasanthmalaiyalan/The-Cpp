#include <iostream>

enum class Month {

    jan = 1,
    feb = 2,
    mar = 3
};

struct Point {
    int x;
    int y;
};

int main() {

    Month m = Month::feb;

    std::cout << "Month value = " << static_cast<int>(m) << '\n';
    std::cout << "Address of object m = " << &m << '\n';

    Month m2{2};

    if (m2 == Month::feb) {
        std::cout << "Month{2} == Month::feb\n";
    }

    Point p{10, 20};

    std::cout << "Point = " << p.x << " " << p.y << '\n';
}

/*
 ./a.out
Month value = 2
Address of object m = 0x7fff231effa8
Month{2} == Month::feb
Point = 10 20
*/