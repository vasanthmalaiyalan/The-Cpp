#include <iostream>
#include <string>
#include <unordered_map>

struct MemberInfo {
    std::string name;
    size_t offset;
};

struct Person {

    int age;
    int height;
    int weight;
};

int main() {

    std::unordered_map<std::string,size_t> person_layout;

    person_layout["age"] = 0;
    person_layout["height"] = 4;
    person_layout["weight"] = 8;

    std::string member_name = "height";

    std::cout << "Compiler sees member : " << member_name << "\n";

    size_t offset = person_layout[member_name];

    std::cout << "Lookup offset  : " << offset << "\n";

    Person p;

    char* base = reinterpret_cast<char*>(&p);
    void* address = static_cast<void*>(base + offset);

    std::cout << "Object base address : " << static_cast<void*>(base) << "\n";
    std::cout << "Member address  : " << address << "\n";
}