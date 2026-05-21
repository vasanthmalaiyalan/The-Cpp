#include <iostream>
#include <cstddef> // offsetof lives here

// =============================================
// Simple struct
// =============================================

struct Employee {

    char id; // 1 byte
    // padding here (3 bytes typically)
    int age; // 4 bytes
    double salary; // 8 bytes
    char grade; // 1 byte
};

// ===============================================
// Manual offsetof (how it works inside)
// ===============================================

#define MY_OFFSETOF(type, member) \
   (size_t)((char*)&((type*)0)->member - (char*)0)

// ===============================================
// main
// ===============================================

int main() {

    std::cout << "=== struct Employee Layout ===" << "\n\n";

    // Using standard offsetof
    std::cout << "offsetof(Employee, id) = " << offsetof(Employee, id) << " bytes\n";
    std::cout << "offsetof(Employee, age) = " << offsetof(Employee, age) << " bytes\n";
    std::cout << "offsetof(Employee, salary) = " << offsetof(Employee, salary) << " bytes\n";
    std::cout << "offsetof(Employee, grade) = " << offsetof(Employee, grade) << " bytes\n";

    std::cout << "\nTotal struct size = " << sizeof(Employee) << " bytes\n";

    std::cout << "\n=== Manual offset (internal trick) ===\n\n";

    std::cout << "MY_OFFSETOF(Employee, id) = " << MY_OFFSETOF(Employee, id) << " bytes\n";
    std::cout << "MY_OFFSETOF(Employee, age) = " << MY_OFFSETOF(Employee, age) << " bytes\n";
    std::cout << "MY_OFFSETOF(Employee, salary) = " << MY_OFFSETOF(Employee, salary) << " bytes\n";
    std::cout << "MY_OFFSETOF(Employee, grade) = " << MY_OFFSETOF(Employee, grade) << " bytes\n";

    return 0;
}

/*
 ./a.out
=== struct Employee Layout ===

offsetof(Employee, id) = 0 bytes
offsetof(Employee, age) = 4 bytes
offsetof(Employee, salary) = 8 bytes
offsetof(Employee, grade) = 16 bytes

Total struct size = 24 bytes

=== Manual offset (internal trick) ===

MY_OFFSETOF(Employee, id) = 0 bytes
MY_OFFSETOF(Employee, age) = 4 bytes
MY_OFFSETOF(Employee, salary) = 8 bytes
*/