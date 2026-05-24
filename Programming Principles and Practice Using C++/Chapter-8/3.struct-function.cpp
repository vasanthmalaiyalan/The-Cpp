#include <iostream>

struct Date {

    int y;
    int m;
    int d;
};

bool is_valid_date(int y, int m, int d) {

    if (m < 1 || m > 12)
       return false;
}