#include <iostream>
#include <cstdlib>
#include <new>
#include <string>


// ============================================
// PERSON CLASS
// ===========================================

class Person {

    public:
      std::string name;

      Person() {
        std::cout
           << "\n[CONSTRUCTOR CALLED]\n";

         name = "Tony Stark";
         
         std::cout
            << "object address : "
            << this  
            << '\n';

         std::cout
            << "name initialized : "
            << name 
            << '\n';   
      }

      ~Person() {

        std::cout
           << "\n[Destructor Called]\n";

        std::cout
           << "destroying object at : "
           << this 
           << '\n';   
      }
};

// ==============================================
// Main
// ==============================================

int main() {

    std::cout
      << "=======================================\n";

    std::cout
       << "STEP 1 : RAW MEMORY ONLY\n";
       
    std::cout
       << "=========================================\n";
       
    // -------------------------------------------
    // RAW MEMORY ALLOCATION
    // -------------------------------------------
    
    void* raw_memory = std::malloc(sizeof(Person));

    std::cout
       << "\nraw memory address       : "
       << raw_memory
       << '\n';

    // IMPORTANT:
    // NO CONSTRUCTOR CALLED YET
    // THIS IS NOT A REAL PERSON OBJECT YET
    
    std::cout
       << "\nNO OBJECT EXISTS YET\n";

    // ============================================
    // STEP 2
    // CONSTRUCTOR OBJECT INSIDE MEMORY
    // ============================================
    
    std::cout
       << "\n\n=======================================\n";

    std::cout
       << "STEP 2 : PLACEMENT NEW\n";
       
    std::cout
       << "==============================================\n";
       
    Person* person_ptr = new(raw_memory) Person(); // just as same as address return

    std::cout
       << "\nperson_ptr      : "
       << person_ptr
       << '\n';

    std::cout
       << "person name       : "
       << person_ptr->name
       << '\n';
       
    // ===========================================
    // STEP 3
    // USE OBJECT
    // ============================================
    
    std::cout
       << "\n\n====================================\n";
    std::cout
       << "STEP 3 : USING OBJECT\n";
    std::cout
       << "=========================================\n";

    person_ptr->name = "IronMan";
    
    std::cout
       << "\nmodified name      : "
       << person_ptr->name
       << '\n';


     // =========================================
     // STEP 4
     // MANUAL DESTRUCTOR
     // ==========================================
     
     std::cout
       << "\n\n===================================\n";

     std::cout
        << "STEP 4 : MANUAL DESTRUCTOR\n";
        
     std::cout
        << "========================================\n";
        
     person_ptr->~Person();
     
     std::cout
       << "\nOBJECT DESTROYED\n";

     // IMPORTANT:
     // MEMORY STILL EXITS
     // ONLY OBJECT LIFETIME ENDED
     
     // ============================================
     // STEP 5
     // FREE RAW MEMORY
     // =============================================

     std::cout
       << "\n\n=====================================\n";

     std::cout
       << "STEP 5 : FREE RAW MEMORY\n";
       
     std::cout
       << "=========================================\n";
       
     std::free(raw_memory);
     
     std::cout
       << "\nRAW MEMORY GREED\n";

}

/*
./a.out
=======================================
STEP 1 : RAW MEMORY ONLY
=========================================

raw memory address       : 0x63699e0c56c0

NO OBJECT EXISTS YET


=======================================
STEP 2 : PLACEMENT NEW
==============================================

[CONSTRUCTOR CALLED]
object address : 0x63699e0c56c0
name initialized : Tony Stark

person_ptr      : 0x63699e0c56c0
person name       : Tony Stark


====================================
STEP 3 : USING OBJECT
=========================================

modified name      : IronMan


===================================
STEP 4 : MANUAL DESTRUCTOR
========================================

[Destructor Called]
destroying object at : 0x63699e0c56c0

OBJECT DESTROYED


=====================================
STEP 5 : FREE RAW MEMORY
=========================================

RAW MEMORY GREED
*/