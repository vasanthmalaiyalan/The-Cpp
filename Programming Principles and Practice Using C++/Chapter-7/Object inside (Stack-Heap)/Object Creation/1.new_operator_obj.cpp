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
        std::cout << "\n[PERSON CONSTRUCTOR RUNNING]\n";
        std::cout << "this pointer      : " << this << '\n';
        std::cout << "name member address  : " << &name << '\n';
           
        name = "Tony Stark";
         
        std::cout << "name initialized     : " << name << '\n';
      }

      // -----------------------------------------
      // DESTRUCTOR
      // ----------------------------------------
      ~Person() {
        std::cout << "\n[PERSON DESTRUCTOR]\n";
        std::cout << "this : " << this << '\n';   
      }

      // =============================================
      // CLASS-SPECIFIC PLACEMENT NEW OPERATOR
      // =============================================
      void* operator new(std::size_t size, void* raw_memory) {
        std::cout << "\n==========================================\n";
        std::cout << "CUSTOM CLASS PLACEMENT Operator new CALLED\n";
        std::cout << "============================================\n";
       
        std::cout << "\nsize requested      : " << size << '\n';
        std::cout << "raw memory received     : " << raw_memory << '\n';
        std::cout << "\nNO MEMORY ALLOCATION HAPPENED\n";
        std::cout << "JUST RETURNING SAME ADDRESS\n";
      
        return raw_memory;
      }
};

// =============================================
// MAIN
// ==============================================

int main() {
    std::cout << "=============================================\n";
    std::cout << "STEP 1 : RAW MEMORY ALLOCATION\n";
    std::cout << "===================================\n";
        
    void* raw = std::malloc(sizeof(Person));

    std::cout << "\nraw memory address      : " << raw << '\n';
    std::cout << "\nNO OBJECT EXISTS YET\n";
       
    std::cout << "\n\n======================================\n";
    std::cout << "Step 2 : new(raw) Person()\n";
    std::cout << "========================================\n";
         
    // This will now successfully call your class-specific placement new
    Person* person = new(raw) Person();

    std::cout << "\n\n======================================\n";
    std::cout << "VERIFY OBJECT\n";
    std::cout << "=============================================\n";
        
    std::cout << "\nperson pointer        : " << person << '\n';
    std::cout << "person->name      : " << person->name << '\n';
    std::cout << "name member address : " << &person->name << '\n';
        
    std::cout << "\n\n======================================\n";
    std::cout << "MANUAL DESTRUCTOR\n";
    std::cout << "=========================================\n";
         
    person->~Person();
      
    std::cout << "\n\n======================================\n";
    std::cout << "FREE RAW MEMORY\n";
    std::cout << "=============================================\n";
        
    std::free(raw);  
}

/*
./a.out
=============================================
STEP 1 : RAW MEMORY ALLOCATION
===================================

raw memory address      : 0x629c797f56c0

NO OBJECT EXISTS YET


======================================
Step 2 : new(raw) Person()
========================================

==========================================
CUSTOM CLASS PLACEMENT Operator new CALLED
============================================

size requested      : 32
raw memory received     : 0x629c797f56c0

NO MEMORY ALLOCATION HAPPENED
JUST RETURNING SAME ADDRESS

[PERSON CONSTRUCTOR RUNNING]
this pointer      : 0x629c797f56c0
name member address  : 0x629c797f56c0
name initialized     : Tony Stark


======================================
VERIFY OBJECT
=============================================

person pointer        : 0x629c797f56c0
person->name      : Tony Stark
name member address : 0x629c797f56c0


======================================
MANUAL DESTRUCTOR
=========================================

[PERSON DESTRUCTOR]
this : 0x629c797f56c0


======================================
FREE RAW MEMORY
=============================================
*/