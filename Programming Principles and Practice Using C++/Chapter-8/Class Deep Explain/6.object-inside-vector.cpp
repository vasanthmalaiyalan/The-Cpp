#include <iostream>
#include <vector>
#include <string>

struct FieldInfo {

    std::string name;
    size_t size;
    size_t alignment;
    size_t offset;
};

int main() {

    std::vector<FieldInfo> fields;

    fields.push_back(
        {
            "age",
            sizeof(int),
            alignof(int),
            0
        }
    );

    fields.push_back(
        {
            "salary",
            sizeof(double),
            alignof(double),
            8
        }
    );

    fields.push_back(
        {
            "grade",
            sizeof(char),
            alignof(char),
            16
        }
    );

    std::cout << "sizeof(FieldInfo) = " << sizeof(FieldInfo) << "\n\n";

    FieldInfo* begin = fields.data();
    FieldInfo* end = begin + fields.size();

    std::cout << "begin = " << begin << '\n';
    std::cout << "end = " << end << "\n\n";

    while(begin != end) {

        std::cout << "Object Address : " << begin << '\n';
        std::cout << "name    = " << begin->name << '\n';
        std::cout << "size    = " << begin->size << '\n';
        std::cout << "alignment = " << begin->alignment << "\n";
        std::cout << "offset    = " << begin->offset << '\n';

        std::cout << "-------------------------------------\n";

        ++begin;
    }

    /*
     ./a.out
sizeof(FieldInfo) = 56

begin = 0x619450459370
end = 0x619450459418

Object Address : 0x619450459370
name    = age
size    = 4
alignment = 4
offset    = 0
-------------------------------------
Object Address : 0x6194504593a8
name    = salary
size    = 8
alignment = 8
offset    = 8
-------------------------------------
Object Address : 0x6194504593e0
name    = grade
size    = 1
alignment = 1
offset    = 16
-------------------------------------
    */
}