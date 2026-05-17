#include <iostream>
#include <cstdlib>
#include <new>
#include <string>


// ==============================================
// PERSON LAYOUT
// ===============================================

class Person {
    public:
      int age;
      std::string name;

    Person() {
        std::cout << "\n[CONSTRUCTOR START]\n";

        // -------------------------------------
        // THIS POINTER
        // -------------------------------------

        std::cout
          << "this pointer  : " << this << '\n';

        // ---------------------------------------
        // MEMBER ADDRESSES
        // ---------------------------------------
        std::cout << "&age member  : " << &age << '\n';
        std::cout << "&name member : " << &name << '\n';
        
        // -----------------------------------------
        // GARBAGE VALUES
        // -----------------------------------------
        std::cout << "\nGARBAGE VALUES\n";

        std::cout << "age        : " << age << '\n';
        std::cout << "name       : " << name << '\n';

        // ------------------------------------------
        // MEMBER INITIALIAZATION
        // ------------------------------------------

        age = 25;

        name = "Tony Stark";

        std::cout << "\nAFTER VALUE INITIALIZED\n";

        std::cout << "age        : " << age << '\n';
        std::cout << "name       : " << name << '\n';

        std::cout << "\n[CONSTRUCTOR END]\n";
    }  

    ~Person() {
        std::cout << "\n[DESTRUCTOR]\n";

        std::cout << "this pointer  : " << this << '\n';
    }
};

// =============================================
// CUSTOM PLACEMENT NEW
// =============================================

void* operator new(std::size_t size, void* raw_memory) {

    std::cout << "\n===============================\n";
    std::cout << "PLACEMENT OPERATOR NEW CALLED\n";
    std::cout << "==================================\n";

    // ==========================================
    // SIZE
    // =========================================

    std::cout << "\nsize requested         : " << size << '\n';

    // -------------------------------------------
    // RAW MEMEORY
    // ------------------------------------------

    std::cout << "raw memory received     : " << raw_memory << '\n';
    
    // ---------------------------------------
    // IMPORTANT
    // ----------------------------------------

    std::cout << "\nRETURNING SAME ADDRESS\n";

    return raw_memory;
}

// =============================================
// MAIN
// =============================================

int main() {

    std::cout << "============================================\n";
    std::cout << "STEP 1 : RAW MEMORY ONLY\n";
    std::cout << "=============================================\n";

    std::cout << "FIRST CHECK SIZE OF PERSON IN CLASS\n";
    std::cout << "WHY BECUASE MALLOC ALLOCATED MEMORY CLASS OF PERSON SIZE BASED RIGHT\n";
    std::cout << "Sizeof(Person) is : " << sizeof(Person) << '\n';


    // -----------------------------------------
    // RAW MEMORY
    // -------------------------------------------

    void* raw = std::malloc(sizeof(size(Person)));

    std::cout << "\nraw memory address    : " << raw << '\n';

    std::cout << "\nNO PERSON OBJECT YET\n";

    // =========================================
    // IMPORTANT VISUALIZATION
    // =========================================

    std::cout << "\n\n=================================\n";
    std::cout << "STEP 2 : PLACEMENT NEW\n";
    std::cout << "====================================\n";

    // -----------------------------------------
    // THIS IS THE ENTIRE MAGIC
    // -----------------------------------------

    Person* person = new(raw) Person();

    // ==========================================
    // VERIFY
    // ==========================================

    std::cout << "\n\n===================================\n";
    std::cout << "STEP 3 : VERIFY OBJECT \n";
    std::cout << "======================================\n";

    std::cout << "person pointer      : " << person << '\n';
    std::cout << "person->age         : " << person->age << '\n';
    std::cout << "person->name        : " << person->name << '\n';

    // =========================================
    // MEMBER ADDRESS CALCULATION
    // =========================================

    std::cout << "\n\n=======================================\n";
    std::cout << "STEP 4 : INTERNAL MEMBER LOGIC\n";
    std::cout << "========================================\n";

    // -----------------------------------------
    // BASE ADDRESS
    // ----------------------------------------
    char* base = (char*)person;

    std::cout << "\nbase object address   : " << (void*)base << '\n';

    // ------------------------------------------
    // MANUAL OFFET CALCULATION 
    // -------------------------------------------

    std::cout << "\nCompiler internal knows:\n";
    std::cout << "age offset  = 0\n";
    std::cout << "name offset = sizeof(int)\n";

    // age address
    int* age_ptr = (int*)(base + 0);

    // name address
    std::string* name_ptr = (std::string*)(base + sizeof(int));

    std::cout << "\nMANUAL MEMBER ADDRESS CALCUALTION\n";
    std::cout << "\nage_ptr      : " << age_ptr << '\n';
    std::cout << "name_ptr       : " << name_ptr << '\n';

    std::cout << "\nVALUES THROUGH MANUAL POINTER\n";
    std::cout << "(*age_ptr)      : " << *age_ptr << '\n';
    std::cout << "(*name_ptr)     : " << *name_ptr << '\n';

    // ========================================
    // CLEANUP
    // =======================================

    std::cout << "\n\n============================\n";
    std::cout << "STEP 5 : CLEANUP\n";
    std::cout << "================================\n";

    person->~Person();

    std::free(raw);
}