#include <iostream>

struct Date {

    int y;
    int m;
    int d;
};

int main() {

    Date today;

    today.y = 2025;
    today.m = 12;
    today.d = 31;

    Date tomorrow;

    tomorrow.y = today.y;
    tomorrow.m = today.m;
    tomorrow.d = today.d + 1;

    std::cout << tomorrow.d << '/' << tomorrow.m << '/' << tomorrow.y << '\n';
}