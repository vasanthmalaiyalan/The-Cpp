#include <iostream>

struct Item {

    int value;
};

int main() {

    Item arr[3];

    arr[0].value = 10;
    arr[1].value = 20;
    arr[2].value = 30;

    Item* begin = &arr[0];

    Item& end = &arr[3];

    while(begin != end) {

        std::cout << begin->value << '\n';

        ++begin;
    }
}