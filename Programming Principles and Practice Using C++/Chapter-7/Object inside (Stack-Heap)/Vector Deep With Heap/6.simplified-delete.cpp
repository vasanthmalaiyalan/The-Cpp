#include <iostream>
#include <cstdlib>

// ================================================
// CUSTOM OBJECT
// =================================================

class Person {
    public:
      Person() {
        std::cout
           << "Person constructor\n";
      }

      ~Person() {
        std::cout
           << "Person destructor\n";
      }
};

// ===========================================
// FAKE DELETE[] IMPLEMENTATION
// =============================================

template<typename T>
void fake_delete_array(
    T* ptr,
    size_t count 
) {
    std::cout
       << "\n==========================================\n";

    std::cout
       << "FAKE DELETE[] START\n";   

    std::cout
       << "==========================================\n";
       
    // -------------------------------------------
    // STEP 1
    // CALL DESTRUCTOR
    // -------------------------------------------
    
    std::cout
       << "\n[CALLING DESTRUCTOR]\n";

    for (size_t i = 0; i < count; ++i)   {

        std::cout
           << "destorying object at     : "
           << &ptr[i] 
           << '\n';

       // manual destructor call
       ptr[i].~T();    
    }

    // ---------------------------------------
    // STEP 2
    // FREE RAW MEMORY
    // ----------------------------------------

    std::cout
       << "\n[FREEING HEAP MEMORY]\n";

    std::cout
       << "heap block address      : "
       << ptr 
       << '\n';
       
    //  raw memory release
    std::free(ptr);

    std::cout
       << "\nMEMORY FREED\n";
}

// ===============================================
// MAIN
// ==============================================

int main() {
    std::cout
       << "\nAllOCATED MEMORY\n";

       // --------------------------------------------
       // RAW HEAP ALLOCATION
       // ------------------------------------------- 

       Person* people = (Person*)std::malloc(sizeof(Person) * 3);

       std::cout
          << "heap address         : "
          << people
          << '\n';

      // ---------------------------------------------
      // MANUAL CONSTRUCTION
      // --------------------------------------------
      
      std::cout
         << "\n[MANUAL CONSTRUCTION]\n";

       for (int i = 0; i < 3; ++i) {
         new (&people[i]) Person();
       } 
       
       // ----------------------------------------
       // FAKE delete[]
       // ----------------------------------------

       fake_delete_array(people, 3);
}  

/*
 ./a.out

AllOCATED MEMORY
heap address         : 0x5e4eb486f6c0

[MANUAL CONSTRUCTION]
Person constructor
Person constructor
Person constructor

==========================================
FAKE DELETE[] START
==========================================

[CALLING DESTRUCTOR]
destorying object at     : 0x5e4eb486f6c0
Person destructor
destorying object at     : 0x5e4eb486f6c1
Person destructor
destorying object at     : 0x5e4eb486f6c2
Person destructor

[FREEING HEAP MEMORY]
heap block address      : 0x5e4eb486f6c0

MEMORY FREED
*/