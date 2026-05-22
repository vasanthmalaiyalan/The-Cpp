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
            alignof(char),
            0
        }
    );

    fields.push_back(
        {
            "grade",
            sizeof(char),
            alignof(char),
            0
        }
    );

    size_t current_offset = 0;

    for (auto& field : fields) {

        size_t remainder = current_offset % field.alignment;

        if (remainder != 0) {
            current_offset += field.alignment - remainder;
        }

        field.offset = current_offset;

        current_offset += field.size;
    }

    for (const auto& field : fields) {

        std::cout << field.name << " offset=" << field.offset << " size=" << field.size << '\n';
    }

    std::cout << "\nobject size=" << current_offset << '\n';


}