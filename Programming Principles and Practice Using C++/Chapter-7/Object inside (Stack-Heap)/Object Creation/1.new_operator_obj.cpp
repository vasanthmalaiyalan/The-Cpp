#include <iostream>
#include <cstdlib>
#include <new>
#include <string>


// ===========================================
// PERSON CLASS
// ============================================

class Person {
    public:
      std::string name;

      // --------------------------------------
      // CONSTRUCTOR
      // ---------------------------------------

      Person() {

        std::cout
           << "\n[PERSON CONSTRUCTOR RUNNING]\n";

        std::cout
           << "this pointer      : "
           << this 
           << '\n';
           
        std::cout
           << "name memeber address  : "
           << &name 
           << '\n';
           
         name = "Tony Stark";
         
         std::cout
            << "name initialized     : "
            << name 
            << '\n';
      }

      // -----------------------------------------
      // DESTRUCTOR
      // ----------------------------------------

      ~Person() {
        std::cout
           << "\n[PERSON DESTRUCTOR]\n";

        std::cout
           << "this : "
           << this 
           << '\n';   
      }
};

// =============================================
// CUSTOM PLACEMENT NEW OPERATOR
// ==============================================

// THIS IS THE REAL SPECIAL FUNCTION
// USED BY:
//
// new(raw_memory) Person();
//
// comapiler internally calls this

void* operator new(
    std::size_t size, 
    void* raw_memory
) {
    std::cout
       << "\n==========================================\n";

    std::cout
      << "CUSTOM PLACEMENT OPerator new CALLED\n";
      
    std::cout
       << "============================================\n";
       
   // ----------------------------------------------
   // SIZE REQUESTED
   // ---------------------------------------------
   
   std::cout
     << "\nsize requested      : "
     << size 
     << '\n';

  // --------------------------------------------
  // MEMORY PROVIDED
  // --------------------------------------------
  
  std::cout
     << "raw memory received     : "
     << raw_memory
     << '\n';

  // --------------------------------------------
  // IMPORTANT
  // --------------------------------------------
  
  std::cout
     << "\nNI MEMORY ALLOCATION HAPPEN\n";

  std::cout
     << "JUST RETURNING SAME ADDRESS\n";
     
  // -------------------------------------------
  // RETURN SAME ADDRESS
  // --------------------------------------------
  
  return raw_memory;
}

// =============================================
// MAIN
// ==============================================

int main() {

    std::cout
       << "=============================================\n";

    std::cout
       << "STEP 1 : RAW MEMORY ALLOCATION\n";
       
     std::cout
        << '===================================\n';
        
    // ---------------------------------------------
    // RAW MEMEORY ONLY
    // ------------------------------------------
    
    void* raw = std::malloc(sizeof(Person));

    std::cout
       << "\nraw memory address      : "
       << raw 
       << '\n';

    std::cout
       << '\nNO OBJECT EXISTS YET\n';
       
     // =========================================
     // STEP 2
     // PLACEMENT NEW
     // =========================================
     
     std::cout
        << "\n\n======================================\n";

      std::cout
         << "Step 2 : new(raw) Person()\n";
         
      std::cout
         << "========================================\n";
         
     // --------------------------------------------
     // THIS IS THE IMPORTANT LINE
     // ========================================
     
     Person* person = new(raw) Person();

     // =========================================
     // VERIFY
     // ===========================================

     std::cout
        << "\n\n======================================\n";

     std::cout
        << "VERIFY OBJECT\n";
        
     std::cout
        << "=============================================\n";
        
     std::cout
        << "\nperson pointer       : "
        << person
        << '\n';
        
     std::cout
        << "person->name      : "
        << person->name 
        << '\n';
        
     std::cout
        << "name member address : "
        << &person->name
        << '\n';
        
     // ========================================
     // MANUAL DESTRUCTOR
     // ========================================
     
     std::cout
        << "\n\n======================================\n";

     std::cout
        << "MANUAL DESTRUCTOR\n";
        
      std::cout
         << "=========================================\n";
         
      person->~Person();
      
      // =============================================
      // FREE RAW MEMORY
      // ==============================================

      std::cout
         << "\n\n======================================\n";

     std::cout
        << "FREE RAW MEMORY\n";
        
     std::cout
        << "=============================================\n";
        
     std::free(raw);  
}