#include <iostream>
#include <cstdlib>
#include <new>
#include <string>
#include <cstddef>

// =============================================
// SIMPLE PERSON CLASS
// ============================================

class Person {
    public:
      int age;
      std::string name;

      // --------------------------------------
      // CONSTRUCTOR
      // --------------------------------------
      Person() {
        std::cout << "\n[CONSTRUCTOR RUNNING]\n";

        // ---------------------------------
        // THIS POINTER
        // ---------------------------------

        std::cout << "this pointer   : " << this << '\n';

        // ----------------------------------
        // MEMEBER ADDRESSES
        // ----------------------------------

        std::cout << "&age memeber   : " << &age << '\n';
        std::cout << "&name memeber  : " << &name << '\n';

        // -----------------------------------
        // INITIALIZATION
        // ----------------------------------

        age = 25;

        name = "Tony Stark";

        std::cout << "\nVALUES INITIALIZED\n";

        std::cout << "age     : " << age << '\n';
        std::cout << "name    : " << name << '\n';
      }

      // ------------------------------------------
      // DESTRUCTOR
      // ------------------------------------------

      ~Person() {
        std::cout << "\n[DESTRUCTOR RUNNING]\n";
        std::cout << "destroying object at   : " << this << '\n';
      }
};

// ===============================================
// CUSTOM OBJECT CREATOR
// ===============================================

Person* create_person_object() {
    std::cout << "\n\n=====================================\n";
    std::cout << "STEP 1 : ALLOCTE RAW MEMORY\n";
    std::cout << "========================================\n";

    // ---------------------------------------
    // RAW MEMORY ONLY
    // ----------------------------------------

    void* raw_memory = std::malloc(sizeof(Person));

    std::cout << "\nraw memory address   : " << raw_memory << '\n';
    std::cout << "\nIMPORTANT:\n";
    std::cout << "NO OBJECT EXISTS YET\n";

    // ========================================
    // CAST RAW MEMORY
    // =========================================

    std::cout << "\n\n================================\n";
    std::cout << "STEP 2 : CAST MEMORY\n";
    std::cout << "====================================\n";

    Person* object_ptr = (Person*)raw_memory;

    std::cout << "\nobject_ptr value   : " << object_ptr << '\n';
    std::cout << "\nIMPORTANT:\n";
    std::cout << "still NO REAL OBJECT\n";

    // =========================================
    // CONSTRUCTOR CALL
    // =========================================

    std::cout << "\n\n=================================\n";
    std::cout << "STEP 3 : CONSTRUCTOR CALL\n";
    std::cout << "=================================\n";

    // -----------------------------------------
    // THIS IS THE ACTUAL MAGIC
    // -----------------------------------------

    new(object_ptr) Person();

    std::cout << "\nIMPORTANT:\n";
    std::cout << "NOW OBJECT LIFETIME STARTED\n";

    // ==========================================
    // RETURN OBJECT
    // ===========================================

    return object_ptr;
}

// ==============================================
// INTERNAL MEMBER ACCESS VISUALIZATION
// ==============================================

void show_internal_layout(Person* person) {
    
    std::cout << "\n\n=============================\n";
    std::cout << "STEP 4 : INTERNAL MEMBER LOGIC\n";
    std::cout << "================================\n";
    
    // ----------------------------------------
    // BASE ADDRESS
    // ----------------------------------------

    char* base = (char*)person;

    size_t age_offset = offsetof(Person, age);
    size_t name_offset = offsetof(Person, name);

    std::cout << "\nbase object address  : " << (void*)base << '\n';

    // ---------------------------------------
    // OFFSETS
    // --------------------------------------

    std::cout << "\nCompailer internal know:\n";
    std::cout << "age offset = 0\n";
    std::cout << "name offset = depends on layout\n";

    // -------------------------------------------
    // MANUAL ADDRESS CALCUALTION
    // ------------------------------------------

    int* age_ptr = (int*)(base + age_offset);

    std::string* name_ptr = (std::string*)(base + name_offset);

    std::cout << "\nage_ptr     : " << age_ptr << '\n';
    std::cout << "name_ptr      : " << name_ptr << '\n';

    // ------------------------------------------
    // VALUES
    // ------------------------------------------

    std::cout << "\n*age_ptr   : " << *age_ptr << '\n';
    std::cout << "*name_ptr    : " << *name_ptr << '\n';
}

// =============================================
// DESTORY OBJECT
// =============================================

void destroy_person(Person* person) {
    
    std::cout << "\n\n================================\n";
    std::cout << "STEP 5 : DESTORY OBJECT\n";
    std::cout << "==================================\n";

    // -----------------------------------------
    // MANUAL DESTRUCTOR
    // -----------------------------------------

    person->~Person();

    std::cout << "\nOBJECT LEFTTIME ENDED\n";

    // -------------------------------------------
    // FREE RAW MEMORY
    // -----------------------------------------

    std::free(person);

    std::cout << "RAW MEMORY FREED\n";
}

// ============================================
// MAIN
// ============================================

int main() {
    // --------------------------------------
    // CREATE OBJECT
    // ---------------------------------------

    Person* person = create_person_object();

    // --------------------------------------
    // VERIFY OBJECT
    // ---------------------------------------

    std::cout << "\n\n================================\n";
    std::cout << "VERIFY OBJECT\n";
    std::cout << "===================================\n";

    std::cout << "\nperson pointer     : " << person << '\n';
    std::cout << "person->age          : " << person->age << '\n';
    std::cout << "person->name         : " << person->name << '\n';

    // ----------------------------------------
    // SHOW INTERNAL FLOW
    // ---------------------------------------

    show_internal_layout(person);

    // ------------------------------------
    // DESTORY
    // -----------------------------------

    destroy_person(person);
}

/*
 ./a.out


=====================================
STEP 1 : ALLOCTE RAW MEMORY
========================================

raw memory address   : 0x5ad4a0a876c0

IMPORTANT:
NO OBJECT EXISTS YET


================================
STEP 2 : CAST MEMORY
====================================

object_ptr value   : 0x5ad4a0a876c0

IMPORTANT:
still NO REAL OBJECT


=================================
STEP 3 : CONSTRUCTOR CALL
=================================

[CONSTRUCTOR RUNNING]
this pointer   : 0x5ad4a0a876c0
&age memeber   : 0x5ad4a0a876c0
&name memeber  : 0x5ad4a0a876c8

VALUES INITIALIZED
age     : 25
name    : Tony Stark

IMPORTANT:
NOW OBJECT LIFETIME STARTED


================================
VERIFY OBJECT
===================================

person pointer     : 0x5ad4a0a876c0
person->age          : 25
person->name         : Tony Stark


=============================
STEP 4 : INTERNAL MEMBER LOGIC
================================

base object address  : 0x5ad4a0a876c0

Compailer internal know:
age offset = 0
name offset = depends on layout

age_ptr     : 0x5ad4a0a876c0
name_ptr      : 0x5ad4a0a876c8

*age_ptr   : 25
*name_ptr    : Tony Stark


================================
STEP 5 : DESTORY OBJECT
==================================

[DESTRUCTOR RUNNING]
destroying object at   : 0x5ad4a0a876c0

OBJECT LEFTTIME ENDED
RAW MEMORY FREED
*/