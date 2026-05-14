#include <iostream>


// ==================================================
// SIMPLE CUSTOM VECTOR
// ==================================================

class My_vector {

    private:
      
       // -------------------------------------
       // POINTER TO HEAP MEMORY
       // --------------------------------------

       int* data;

       size_t size;

    public:
      
       // --------------------------------------
       // CONSTRUCTOR
       // --------------------------------------

       My_vector() {

         size = 3;

         // heap allocation
         data = new int[size];

         data[0] = 10 // internally compailer do this handle it because raw pointer
         data[1] = 20;
         data[2] = 30;
       }

       //  --------------------------------------
       // OPERATOR
       // ----------------------------------------

       int& operator[](size_t i) {

         std::cout 
            << "\n==================================================\n";

         std::cout
            << "operator[] CALLED\n";
            
         std::cout
            << "index requested                   : "
            << i
            << '\n';
            
            // ---------------------------------------
            // INTERNAL POINTER
            // ---------------------------------------

            std::cout
               << "data pointer value              : "
               << data 
               << '\n';
               
            // ----------------------------------------
            // ADDRESS CALCULATION
            // ----------------------------------------
            
            std::cout
               << "calculated address               : "
               << (data + i)
               << '\n';

            // ---------------------------------------
            // VALUE
            // ---------------------------------------
            
            std::cout
               << "value at address                  : "
               << *(data + i)
               << '\n';

            // -------------------------------------------
            // RETURN REFERENCE
            // ------------------------------------------
            
            return *(data + i);
       }

       // ----------------------------------------
       // DEBUG FUNCTION
       // ----------------------------------------

       void print_internal_layout() {

          std::cout
             << "\n============================================\n";

          std::cout
             << "VECTOR OBJECT MEMORY\n";
             
          std::cout
             << "==============================================\n";
             
             
          // vector object address
          std::cout
             << "&vector first object                : "
             << this 
             << '\n';
             
          // address of pointer member
          std::cout
             << "&data member                        : "
             << &data 
             << '\n';
             
             
          // heap elements
          std::cout
             << "\n==========================================\n";
             
          std::cout
             << "HEAP ELEMENTS\n";
             
          std::cout
             << "==============================================\n";
             
          for (size_t i = 0; i < size; ++i) {

            std::cout
               << "element[" << i << "] value           : "
               << data[i] 
               << '\n';

            std::cout
               << "element[" << i << "] address         : "
               << &data[i]
               << '\n';

            std::cout
               << '\n';   
          }   
       }
};

// =============================================
// MAIN
// ============================================

int main() {

    My_vector numbers;

    // -------------------------------------------
    // SHOW INTERNAL MEMORY
    // --------------------------------------------

    numbers.print_internal_layout();

    // -----------------------------------------
    // NORMAL INDEXING
    // -----------------------------------------

    std::cout
       << "\n\n======================================\n";

    std::cout
       << "NORMAL numbers[2]\n";
       
    std::cout
       << "============================================\n";
       
    int value = numbers[2];
    
    std::cout
       << "\nFINAL RETURNED VALUE       : "
       << value
       << '\n';

    // ------------------------------------------
    // ADDRESS OF ELEMENT
    // ------------------------------------------
    
    std::cout
       << "\n\n===================================\n";

    std::cout
       << "&numbers[2]\n";
       
    std::cout
       << "========================================\n";
       
    std::cout
       << "&numbers[2]                  : "
       << &numbers[2]
       << '\n';   
}