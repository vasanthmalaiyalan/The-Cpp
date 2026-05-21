#include <iostream>

struct Employee {

    char id;
    int age;
    double salary;
};

int main() {

    // ========================================
    // STEP 1 : CAST
    // ========================================

    int x = 65;
    std::cout << "(int)   x = " << x       << "\n"; // 65
    std::cout << "(char)  x = " << (char)x << "\n"; // A
    std::cout << "(float) x = " << (float)x << "\n"; // 65.0

    // ======================================
    // STEP 2 : Pointer cast
    // ======================================

    int num = 42;
    void* p1 = (void*)&num; // address only
    int* p2 = (int*)&num; // int inside label (adddress and value)

    std::cout << "\nvoid* address = " << p1 << "\n";
    std::cout << "int* address = " << p2 << "\n";
    std::cout << "*p1 void* p1 = (void*)&num = " << *p1 << "\n";
    std::cout << "*p2 int* p2 = (int*)&num = " << *p2 << "\n";

    // ======================================
    // STEP 3: (Employee*)0
    // ======================================

    Employee* e = (Employee*)0;

    std::cout << "\nEmployee* e = " << e << "\n"; // "0 is Employee label only address no memory access"
    
    // =======================================
    // STEP 4: -> member 
    // =======================================

    void* age_addr = (void*)&(e->age);
    std::cout << "\n&e->age address = " << age_addr << "\n";
    std::cout << "\nonly access addr not value = " << *age_addr << "\n";

    // ======================================
    // STEP 5 : Offset
    // =====================================

    size_t offset = (size_t)((char*)&((Empolyee*)0)->age);
    std::cout << "\noffset of age = " << offset << "\n"; // 4


    // standard offsetof:
    std::cout << "offsetof macro = " << offsetof(Employee, age) << "\n"; // 4

    // offset members
    std::cout << "\nEmployee layout:\n";
    std::cout << "id  offset = " << offsetof(Employee, id) << "\n";
    std::cout << "age offset = " << offsetof(Employee, age) << "\n";
    std::cout << "salary offset = " << offsetof(Employee, salary) << "\n";

    return 0;
}