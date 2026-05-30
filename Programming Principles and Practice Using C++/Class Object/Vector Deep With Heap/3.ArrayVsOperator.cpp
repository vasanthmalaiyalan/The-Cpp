#include <iostream>

// =============================================
// CUSTOM VECTOR CLASS
// =============================================

class My_vector {

    private:
       
       int* data;

    public:
      
       // -----------------------------------------
       // CONSTRUCTOR
       // -----------------------------------------

       My_vector() {

               // heap allocation
               data = new int[3];

               data[0] = 10; // internally comapiler handle
               data[1] = 20;
               data[2] = 30;
       }

       // ----------------------------------------
       // DESTRUCTOR
       // ----------------------------------------

       ~My_vector() {

            delete[] data;
       }


       // ---------------------------------------
       // operator []
       // ---------------------------------------

       int& operator[](size_t i) {

          std::cout
             << "\n========================================\n";

          std::cout
             << "My_vector::operator[] CALLED\n"; 
             
          std::cout
             << "==========================================\n";
             
           std::cout
              << "Requested index              : "
              << i 
              << '\n';
              
           std::cout
              << "data pointer value            : "
              << data 
              << '\n';
              
           std::cout
              << "Calculated address             : "
              << (data + i)
              << '\n';
              
            std::cout
               << "Returned value                : "
               << *(data + i)
               << '\n';
               
               
            return *(data + i);   
       }
};

// =============================================
// MAIN
// ============================================

int main() {

    // ==========================================
    // 1. NATIVE ARRAY
    // ===========================================

    int arr[3] = {100, 200, 300};

    std::cout
       << "\n\n======================================\n";

    std::cout
       << "1.NATIVE ARRAY\n";
       
    std::cout
       << "============================================\n";
       
    std::cout
       << "\nArray base address:\n";
       
    std::cout 
       << "arr                           : "
       << arr
       << '\n';
       
    std::cout
       << "\nArray element addresses:\n";
       
    for (size_t i = 0; i < 3; i++) {
        std::cout
           << "&arr[" << i << "]            : "
           << &arr[i]
           << '\n';
    }   

    std::cout
       << "\nUsing arr[2]:\n";

    std::cout
       << "arr[2]                          : "
       << arr[2]
       << '\n';
       
    std::cout
       <<"\nInternal Native-array logic:\n";
       
    std::cout
       << "*(arr + 2)                     : "
       << *(arr + 2)
       << '\n';
       
    std::cout
       << "\nAddress calculation:\n";
       
    std::cout
       << "arr + 2                        : "
       << (arr + 2)
       << '\n';
       
    // ==========================================
    // 2. CUSTOM VECTOR OBJECT
    // ==========================================
    
    My_vector numbers;


    std::cout
       << "\n\n========================================\n";

    std::cout
       << "2. CUSTOM VECTOR OBJECT\n"; 
       
    std::cout
       << "================================================\n";
       
    std::cout
       << "\nObject address:\n";
       
    std::cout
       << "&numbers                         : "
       << &numbers
       << '\n';
       
    std::cout
       << "\nUsing numbers[2]:\n";
       
    int value1 = numbers[2];
    
    std::cout
       << "\nFinal value                    : "
       << value1
       << '\n';

    std::cout
       << "\nUsing numbers.operator[](2):\n";
       
    int value2 = numbers.operator[](2);
    
    std::cout
       << "\nFinal value                    : "
       << value2
       << '\n';

}