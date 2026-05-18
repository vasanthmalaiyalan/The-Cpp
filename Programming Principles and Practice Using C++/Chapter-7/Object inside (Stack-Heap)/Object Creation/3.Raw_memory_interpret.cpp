#include <iostream>
#include <cstring>

// =================================================
// PERSON LAYOUT
// ===================================================

class Person {
    public: 
      int age;
      int salary;
};

// ==========================================
// MAIN
// ==========================================

int main() {

    std::cout << "====================================\n";
    std::cout << "RAW MEMORY\n";
    std::cout << "========================================\n";

    // -------------------------------------------
    // RAW BYTES
    // -------------------------------------------

    unsigned char memory[16];

    // clear memeory
    std::memset(memory, 0, sizeof(memory));

    // ------------------------------------
    // SHOW RAW MEMORY
    // ------------------------------------

    std::cout << "\nraw memory start address : " << (void*)memory << '\n';

    // =====================================
    // WRITE RAW BYTES MANUALLY
    // ======================================

    std::cout << "\n=================================\n";
    std::cout << "WRITING RAW BYTES\n";
    std::cout << "====================================\n";

    // -----------------------------------------
    // FIRST 4 BYTES
    // -----------------------------------------

    // int value 25
    memory[0] = 25;
    memory[1] = 0;
    memory[2] = 0;
    memory[3] = 0;

    // ------------------------------------------
    // NEXT 4 BYTES
    // ------------------------------------------

    // int value 100
    memory[4] = 100;
    memory[5] = 0;
    memory[6] = 0;
    memory[7] = 0;

    // ===========================================
    // SHOW RAW BYTES
    // ===========================================

    std::cout << "\nRAW BYTES INSIDE MEMORY\n\n";

    for (int i = 0; i < 8; ++i) {
        std::cout << "memory[" << i << "] = " << (int)memory[i] << '\n';
    }

    // ========================================
    // INTERPRET AS INT*
    // =========================================

    std::cout << "\n\n==============================\n";
    std::cout << "INTERPRET MEMORY AS int*\n";
    std::cout << "====================================\n";

    int* int_ptr = (int*)memory;

    std::cout << "\nint_ptr address   : " << int_ptr << '\n';
    std::cout << "*int_ptr             : " << *int_ptr << '\n';

    // =========================================
    // POINTER ARITHMETIC
    // ========================================

    std::cout << "\nSECOND int USING POINTER ARITHMETIC\n";
    std::cout << "int_ptr + 1 address  : " << (int_ptr + 1) << '\n';
    std::cout << "*(int_ptr + 1)       : " << *(int_ptr + 1) << '\n';

    // =========================================
    // INTERPRET SAME MEMORY AS PERSON*
    // =========================================

    std::cout << "\n\n================================\n";
    std::cout << "INTERPRET SAME MEMORY AS PERSON*\n";
    std::cout << "====================================\n";

    Person* person_ptr = (Person*)memory; // cover that interpret whole class

    std::cout << "\nperson_ptr address : " << person_ptr << '\n';
    std::cout << "person_ptr->age      : " << person_ptr->age << '\n';
    std::cout << "person_ptr->salary   : " << person_ptr->salary << '\n';

    // ==========================================
    // MANUAL OFFSET EXPLANATION
    // =========================================

    std::cout << "\n\n====================================\n";
    std::cout << "MANUAL OFFSET LOGIC\n";
    std::cout << "=======================================\n";

    char* base = (char*)memory;

    std::cout << "\nbase address  : " << (void*)base << '\n';

    // age offset = 0
    int* age_ptr = (int*)(base + 0);

    // salary offset = 4
    int* salary_ptr = (int*)(base + 4);

    std::cout << "\nage_ptr address   : " << age_ptr << '\n';
    std::cout << "salary_ptr address  : " << salary_ptr << '\n';
    std::cout << "\n*age_ptr          : " << *age_ptr << '\n';
    std::cout << "*salary_ptr         : " << *salary_ptr << '\n';


}