#include <iostream>

#define MY_OFFSETOF(TYPE, MEMBER) \
    ((size_t)&(((TYPE*)0)->MEMBER))

struct Person {

    int age;
    int height;
    int weight;
};

int main() {

    std::cout << MY_OFFSETOF(Person, age) << '\n';
    std::cout << MY_OFFSETOF(Person, height) << '\n';
    std::cout << MY_OFFSETOF(Person, weight) << '\n';
}