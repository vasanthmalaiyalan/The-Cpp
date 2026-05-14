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