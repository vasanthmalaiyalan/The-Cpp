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

        size_t remainder = current_offset % fields.alignment;

        if (remainder != 0) {
            current_offset += fields.alignment - remainder;
        }

        fields.offset = current_offset;

        current_offset += fields.size;
    }

    for (const auto& field : fields) {

        std::cout << fields.name << " offset=" << fields.offset << " size=" << fields.size << '\n';
    }

    std::cout << "\nobject size=" << current_offset << '\n';


}