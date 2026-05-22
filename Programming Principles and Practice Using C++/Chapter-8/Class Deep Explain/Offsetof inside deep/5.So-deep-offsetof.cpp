#include <iostream>
#include <cstddef>

// ============================================
// Compailer symbol table
// ============================================

struct Employee {

    char id;
    int age;
    double salary;
};

int main() {

    // ====================================
    // PART 1: Real address - RAM
    // ====================================

    Employee emp;
    emp.id    = 'A';
    emp.age   = 25;
    emp.salary = 50000.0;

    std::cout << "==== PART 1: Real Address (RAM Access) ===\n\n";

    // base address
    void* base = &emp;
    std::cout << "Base address of emp : " << base << "\n";

    // age real address
    void* real_age_addr = &emp.age; // real address + offset
    std::cout << "Real address of age : " << real_age_addr << "\n";

    // base + offset = real address
    size_t base_num    = (size_t)base;
    size_t age_offset  = offsetof(Employee, age); // offset internal just fake layout track
    size_t calculated  = base_num + age_offset;

    std::cout << "Base(" << base_num << ") + " << "Offset(" << age_offset << ") = " << calculated << "\n";

    // RAM Value inside
    std::cout << "Value inside RAM   : " << emp.age << "\n";

    // ========================================
    // PART 2: FAKE Address - RAM
    // ========================================

    std::cout << "\n=== PART 2: FAKE Address (NO RAM Access) ===\n\n";

    // 0 fake address
    // compailer symbol table only access offset value
    void* fake_age_addr = &((Employee*)0)->age;

    std::cout << "Fake base address  : " << (void*)0 << "\n";
    std::cout << "Fake age address   : " << fake_age_addr << "\n";
    std::cout << "0 + offset(4)      : " << (size_t)fake_age_addr << "\n";

    // RAM didn't connect
    // *((Employee*)0) -> crash if try print 


    // =======================================
    // PART 3: Symbol table values
    // ========================================

    std::cout << "\n=== PART 3: Compailer Symbol Table ===\n\n";

    std::cout << "id  offset    : " << offsetof(Employee, id) << "\n";
    std::cout << "age offset    : " << offsetof(Employee, age) << "\n";
    std::cout << "salary offset : " << offsetof(Employee, salary) << "\n";
    std::cout << "struct size   : " << sizeof(Employee)  << "\n";

    // this value is compalie time enough
    // didn't have emp obj 
    
    // =======================================
    // PART 4: Real vs Fake - side by side
    // ========================================

    std::cout << "\n=== PART 4: Real vs Fake Comparison ===\n\n";

    // Real:
    size_t real = (size_t)&emp.age - (size_t)&emp;
    // Fake:
    size_t fake = (size_t)&((Employee*)0)->age;

    std::cout << "Real (base+" << age_offset << ") offset : " << real << "\n";
    std::cout << "Fake (0+" << age_offset << ") offset : " << fake << "\n";
    std::cout << "Both same?  : " << (real == fake ? "YES " : "NO ") << "\n";

    return 0;
}