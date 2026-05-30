#include <iostream>

// ==============================================
// CUSTOM VECTOR CLASS
// ==============================================

class My_vector {

    private:
       // ----------------------------------------
       // POINTER TO HEAP MEMORY
       // ----------------------------------------

       int* data;

       size_t size;

    public:
     
       // ----------------------------------------
       // CONSTRUCTOR
       // ----------------------------------------

       My_vector() {

         std::cout
           << "\n===================================\n";

         std::cout
           << "CONSTRUCTOR CALLED\n";
           
         std::cout
           << "=======================================\n";
           
         size = 3;
        
        // heap allocation
         data = new int[size];

         data[0] = 10; // raw pointer with compailer automatic decode
         data[1] = 20;
         data[2] = 30;

         std::cout
            << "Heap memory allocator\n";

         std::cout
            << "data pointer value        : "
            << data 
            << '\n';   
       }

       // ----------------------------------------
       // DESTRUCTOR
       // ----------------------------------------

       ~My_vector() {

           delete[] data;
       }

       // ----------------------------------------
       // OPERATOR []
       // ----------------------------------------

       int& operator[](size_t i) {

          std::cout
             << "\n========================================\n";

          std::cout
             << "operator[] FUNCTION CALLED\n";
             
          std::cout
             << "=====================================\n";
             
          // index
          std::cout
             << "Request index           : "
             << i 
             << '\n';

          // internal pointer
          std::cout
             << "Stored data pointer     : "
             << data 
             << '\n';
             
          // offset calculation
          std::cout
             << "\nAddress calculation:\n";
             
          std::cout
             << "data + index            : "
             << (data + i)
             << '\n';
             
          // actual value
          std::cout
             << "\nActual Value          : "
             << *(data + i)
             << '\n';
             
          // return reference
          return *(data + i);
                
       }

       // -------------------------------------------
       // PRINT MEMORY LAYOUT
       // -------------------------------------------

       void print_layout() {

           std::cout
              << "\n=====================================\n";

           std::cout
              << "VECTOR OBJECT LAYOUT\n";
              
           std::cout
              << "========================================\n";
              
           // vector object address
           std::cout
              << "&vector object (first address)             : "
              << this   
              << '\n';
              
           // address of pointer member
           std::cout
              << "&data member (seperate)                   : "
              << &data 
              << '\n';

          // pointer value
          std::cout
             << "data pointer value (inside stack ref)      : "
             << data 
             << '\n';
             
          // size member address
          std::cout
             << "&size member                               : "
             << &size 
             << '\n';   

          // size value
          std::cout
             << "size value                                 : "
             << size 
             << '\n';

          std::cout
             << "\n=======================================\n";
             
          std::cout
             << "HEAP ELEMENTS\n";
             
          std::cout
             << "=========================================\n";
             
          for (size_t i = 0; i < size; i++) {

              std::cout
                 << "data[" << i << "] value         : "
                 << data[i] // compailer itself print
                 << '\n';

              std::cout
                 << "data[" << i << "] address       : "
                 << &data[i]
                 << '\n';
                 
              std::cout
                 << '\n';   
          }   
       }
};

// ==============================================
// MAIN
// ==============================================

int main() {

    // -----------------------------------------
    // CREATE VECTOR OBJECT
    // ------------------------------------------

    My_vector numbers;

    // ------------------------------------------
    // PRINT INTERNAL MEMORY
    // ------------------------------------------

    numbers.print_layout();

    // -----------------------------------------
    // NORMAL [] SYNTAX
    // -----------------------------------------

    std::cout
       << "\n\n===================================\n";

    std::cout
       << "USING numbers[2]\n";
       
    std::cout
       << "========================================\n";
       
    int value = numbers[2];
    
    std::cout
       << "\nFinal returned values   : "
       << value
       << '\n';

    // --------------------------------------------
    // EXPLICIT FUNCTION CALL
    // --------------------------------------------
    
    std::cout
       << "\n\n=========================================\n";

    std::cout
       << "USING numbers.operator[](2)\n";
       
    std::cout
       << "===============================================\n";
       
     int values2 = numbers.operator[](2);
     
     std::cout
        << "\nFinal returned value            : "
        << values2
        << '\n';

    // ----------------------------------------------
    // ADDRESS OF HEAP ELEMENT
    // ---------------------------------------------
    
    std::cout
       << "\n\n========================================\n";

    std::cout
       << "&numbers[2]\n";
       
    std::cout
       << "=============================================\n";
       
    std::cout
       << "&numbers[2]                       : "
       << &numbers[2]
       << '\n';    
}

/*
 ./a.out 

===================================
CONSTRUCTOR CALLED
=======================================
Heap memory allocator
data pointer value        : 0x5b3a46b586c0

=====================================
VECTOR OBJECT LAYOUT
========================================
&vector object (first address)             : 0x7fff0384f6a0      
&data member (seperate)                   : 0x7fff0384f6a0       
data pointer value (inside stack ref)      : 0x5b3a46b586c0      
&size member                               : 0x7fff0384f6a8      
size value                                 : 3

=======================================
HEAP ELEMENTS
=========================================
data[0] value         : 10
data[0] address       : 0x5b3a46b586c0

data[1] value         : 20
data[1] address       : 0x5b3a46b586c4

data[2] value         : 30
data[2] address       : 0x5b3a46b586c8



===================================
USING numbers[2]
========================================

========================================
operator[] FUNCTION CALLED
=====================================
Request index           : 2
Stored data pointer     : 0x5b3a46b586c0

Address calculation:
data + index            : 0x5b3a46b586c8

Actual Value          : 30

Final returned values   : 30


=========================================
USING numbers.operator[](2)
===============================================

========================================
operator[] FUNCTION CALLED
=====================================
Request index           : 2
Stored data pointer     : 0x5b3a46b586c0

Address calculation:
data + index            : 0x5b3a46b586c8

Actual Value          : 30

Final returned value            : 30


========================================
&numbers[2]
=============================================
&numbers[2]                       :
========================================
operator[] FUNCTION CALLED
=====================================
Request index           : 2
Stored data pointer     : 0x5b3a46b586c0

Address calculation:
data + index            : 0x5b3a46b586c8

Actual Value          : 30
0x5b3a46b586c8

*/