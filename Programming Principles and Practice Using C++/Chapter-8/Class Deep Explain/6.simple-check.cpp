#include <iostream>
#include <string>

struct FieldInfo {

    std::string name;
    size_t size;
    size_t alignment;
    size_t offset;
};

int main() {

    std::cout << sizeof(std::string) << '\n';
    std::cout << sizeof(FieldInfo) << "\n";
}