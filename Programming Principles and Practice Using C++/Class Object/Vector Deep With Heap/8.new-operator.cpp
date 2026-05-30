#include <iostream>
#include <cstdlib>
#include <new>
#include <string>

// ===============================================
// PERSON
// ===============================================

class Person {
    public:
      std::string name;

      Person() {
        std::cout
           << "\n[Person CONSTRUCTOR]\n";

        std::cout
           << "this pointer      : "
           << this 
           << '\n';
           
        std::cout
           << "name member address   : "
           << &name 
           << '\n';
           
        name = "Tony Stark";
        
        std::cout
           << "name value         : "
           << name 
           << '\n';
      }

      ~Person() {

        std::cout
           << "\n[PERSON DESTRUCTOR]\n";

        std::cout
           << "destroying object at      : "
           << this 
           << '\n';   
      }
};

// ===============================================
// CUSTOM PLACEMENT NEW
// ===============================================

Person* custom_placement_new(void* raw_memory) {

    std::cout
       << "\n========================================\n";

    std::cout
       << "CUSTOM PLACEMENT NEW\n";   

    std::cout
       << "============================================\n";
       
    // -------------------------------------------
    // STEP 1
    // CAST RAW MEMORY
    // -------------------------------------------
    
    std::cout
       << "\n[STEP 1]\n";

    std::cout
       << "raw memoery address     : "
       << '\n';
       
    Person* object_ptr = (Person*)raw_memory;
    
    std::cout
       << "casted to Person*      : "
       << object_ptr
       << '\n';


    // ------------------------------------------
    // STEP 2
    // CONSTRUCTOR CALL
    // -------------------------------------------
    
    std::cout
       << "\n[STEP 2]\n";

    std::cout
       << "calling constructor manually\n";
       
    // ------------------------------------------
    // THIS IS THE IMPORTANT PART
    // -------------------------------------------
    
    // compailer internally does something similar
    // when placement new happens

    new(object_ptr) Person();

    // -----------------------------------------
    // RETURN OBEJCT
    // -----------------------------------------

    return object_ptr;
}

// =============================================
// MAIN
// ============================================

int main() {

    std::cout
       << "================================================\n";

    std::cout
       << "STEP 1 : RAW MEMORY\n";
       
    std::cout 
       << "====================================================\n";
       
       
    // -----------------------------------------
    // RAW MEMORY ONLY
    // ----------------------------------------
    
    void* raw = std::malloc(sizeof(Person));

    std::cout
       << "\nraw memory address         : "
       << raw
       << '\n';

    std::cout
       << "\nNO OBJECT YET\n";
       
    // ==========================================
    // CONSTRUCTOR OBJECT INSIDE MEMORY
    // =========================================
    
    Person* person = custom_placement_new(raw);

    // ========================================
    // VERIFY
    // ========================================

    std::cout
       << "\n\n=========================================\n";

    std::cout
       << "VERIFY OBJECT\n";
       
    std::cout
      << "==================================================\n";
      
    std::cout
       << "\nperson pointer       : "
       << person
       << '\n';
       
    std::cout
       << "person->name           : "
       << person->name
       << '\n';
       
    std::cout
       << "address of name member  : "
       << &person->name
       << '\n';
       
    // ===========================================
    // MANUAL DESTRUCTION
    // ===========================================
    
    std::cout
       << "\n\n=====================================\n";

    std::cout
       << "MANUAL DESTRUCTOR\n";
       
    std::cout
       << "==============================================\n";
       
    person->~Person();
    
    // =========================================
    // FREE RAW MEMEORY
    // ==========================================

    std::cout
       << "\n\n======================================\n";

    std::cout
       <<  "FREE RAW MEMEORY\n";

    std::cout
       << "==============================================\n";
       
     std::free(raw);  
}

/*
 ./a.out
================================================
STEP 1 : RAW MEMORY
====================================================

raw memory address         : 0x64de286206c0

NO OBJECT YET

========================================
CUSTOM PLACEMENT NEW
============================================

[STEP 1]
raw memoery address     :
casted to Person*      : 0x64de286206c0

[STEP 2]
calling constructor manually

[Person CONSTRUCTOR]
this pointer      : 0x64de286206c0
name member address   : 0x64de286206c0
name value         : Tony Stark


=========================================
VERIFY OBJECT
==================================================

person pointer       : 0x64de286206c0
person->name           : Tony Stark
address of name member  : 0x64de286206c0


=====================================
MANUAL DESTRUCTOR
==============================================

[PERSON DESTRUCTOR]
destroying object at      : 0x64de286206c0


======================================
FREE RAW MEMEORY
==============================================

*/