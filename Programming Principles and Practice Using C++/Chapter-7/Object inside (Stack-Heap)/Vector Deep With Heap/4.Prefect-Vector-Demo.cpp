#include <iostream>
#include <string>

// ==============================================
// VERY SIMPLE VECTOR IMPLEMENTATION
// ==============================================

template<typename T>
class MyVector {

    private:
      
       // ----------------------------------------
       // RAW HEAP POINTER
       // ----------------------------------------

       T* data_ptr;

       // current used elements
       size_t current_size;

       // total allocated memory
       size_t current_capacity;

    public:
     
       // ========================================
       // CONSTRUCTOR
       // ========================================

       MyVector() {
          
          current_size = 0;

          current_capacity = 2;

          // RAW HEAP ALLOCATION
          data_ptr = new T[current_capacity];

          std::cout
             << "\n[CONSTRUCTOR]\n";

          std::cout
             << "heap allocated\n";
             
          std::cout
             << "capacity : "
             << current_capacity
             << '\n';
             
          std::cout
             << "heap start address  : "
             << data_ptr
             << '\n'; 
       }

       // =======================================
       // DESTRUCTOR
       // =======================================

       ~MyVector() {

           std::cout
              << "\n[DESTRUCTOR]\n";

           std::cout
              << "deleting heap memory\n";
              
           std::cout
              << "heap address   : "
              << data_ptr
              << '\n';
              
          delete[] data_ptr;    
       }

       // ========================================
       // PUSH_BACK
       // ========================================

       void push_back(const T& value) {
          
           std::cout
              << "\n=======================================\n";

           std::cout
              << "push_back("
              << value
              << ") CALLED\n"; 
              
              
          // -----------------------------------------
          // REALLOCATION NEEDED?
          // ------------------------------------------
          
          if (current_size >= current_capacity) {
             
             std::cout
                << "\n[REALLOCATION REQUIRED]\n";

             size_t old_capacity = current_capacity;
             
             current_capacity *= 2;

             // allocate new heap
             T* new_block = new T[current_capacity];

             std::cout
                << "old heap address   : "
                << data_ptr
                << '\n';

             std::cout
                << "new heap address    : "
                << new_block
                << '\n';
                
             std::cout
                << "old capacity        : "
                << old_capacity
                << '\n';
                
             std::cout
                << "new capacity        : "
                << current_capacity
                << '\n';
                
                
            // ------------------------------------
            // COPY OLD DATA
            // ------------------------------------
            
            for (size_t i = 0; i < current_size; i++) {

                std::cout
                  << "copying element "
                  << i 
                  << '\n';

                std::cout
                   << "from address   : "
                   << &data_ptr[i]
                   << '\n';
                   
                std::cout
                   << "to address      : "
                   << &new_block[i]
                   << '\n';
                   
                new_block[i] = data_ptr[i];   
            }

            // -------------------------------
            // DELETE OLD MEMORY
            // -------------------------------

            delete[] data_ptr;

            std::cout
               << "old heap delete\n";

            // point to new memory
            data_ptr = new_block;   
          }

          // ---------------------------------
          // STORE NEW ELEMENT
          // ---------------------------------

          std::cout
             << "\n[STORING ELEMENT]\n";

          std::cout
             << "index    : "
             << current_size
             << '\n';
            
          std::cout
             <<  "target address   : "
             << &data_ptr[current_size]
             << '\n';

          data_ptr[current_size] = value;
          
          current_size++;

          std::cout
             << "size after push      : "
             << current_size
             << '\n';
       }

       // =======================================
       // OPERATOR []
       // ======================================

       T& operator[](size_t index) {
          
          std::cout
             << "\n======================================\n";

          std::cout
             << "operator[] called\n";

          std::cout
             << "requested index    : "
             << index
             << '\n';
             
          // -----------------------------------------
          // RAW POINTER
          // -----------------------------------------
          
          std::cout
             << "data_ptr value    : "
             << data_ptr
             << '\n';


          // --------------------------------------
          // POINTER ARITHMETIC
          // -------------------------------------
          
          std::cout
             << "\n[POINTER ARITHMETIC]\n";
          
          std::cout
             << "formula:\n";
          
          std::cout
             << "(data_ptr + index)\n";
             
          std::cout
             << "\nactual:\n";
             
          std::cout   
             << "("
             << data_ptr
             << " + "
             << index
             << ")\n";

          T* calculated_address = data_ptr + index;
          
          std::cout
             << "\nCalculated address    : "
             << calculated_address
             << '\n';

          std::cout
             << "value in address   : "
             << *calculated_address
             << '\n';
             
          // -----------------------------------
          // RETURN REFERNECE
          // ------------------------------------
          
          return *calculated_address;
       }

       // =========================================
       // PRINT INTERNAL MEMORY
       // =========================================

       void debug_memory() {

          std::cout
             << "\n\n================================\n";

          std::cout
             << "VECTOR INTERNAL MEMORY\n";
             
          std::cout
             << "\n====================================\n";
             
          std::cout
             << "vector object address  : "
             << this 
             << '\n';

          std::cout
             << "data_ptr member addr   : "
             <<  &data_ptr
             << '\n';
             
          std::cout
             << "heap start address      : "
             << data_ptr
             << '\n';
             
          std::cout
             << "current size            : "
             << current_size
             << '\n';
             
          std::cout
             << "current capacity        : "
             << current_capacity
             << '\n';
             
          // -------------------------------------
          // HEAP ELEMENTS
          // --------------------------------------
          
          std::cout
             << "\n=========================================\n";

          std::cout
             << "HEAP ELEMENTS\n";   

          std::cout
             << "==================================================\n";
             
          for (size_t i = 0; i < current_size; i++) {
             
              std::cout
                 << "\nindex    : "
                 << '\n';

              std::cout
                 << "value      : "
                 << data_ptr[i]
                 << '\n';
                 
              std::cout
                 << "address    : "
                 << &data_ptr[i]
                 << '\n';   
          }   
       }

       // ========================================
       // SIZE 
       // ========================================

       size_t size() {

             return current_size;
       }

       // ========================================
       // CAPACITY
       // =======================================

       size_t capacity() {
          
           return current_capacity;
       }

       // =======================================
       // BEGIN
       // ========================================

       T* begin() {

             return data_ptr;
       }

       // ========================================
       // END
       // =======================================

       T* end() {
          
          return data_ptr + current_size;
       }
};

// =============================================
// MAIN
// ===============================================

int main() {

      MyVector<int> numbers;

      // ============================================
      // PUSH ELEMENTS
      // =============================================

      numbers.push_back(10);

      numbers.push_back(20);

      numbers.push_back(30);

      numbers.push_back(40);

      numbers.push_back(50);

      // ========================================
      // SHOW MEMORY
      // =======================================

      numbers.debug_memory();

      // ========================================
      // VECTOR INDEXING
      // ========================================

      std::cout
         << "\n\n======================================\n";

      std::cout
         << "numbers[2]\n";
         
      std::cout
         << "=============================================\n";
         
      int value = numbers[2];
      
      std::cout
         << "\nFINAL VALUE     : "
         << value
         << '\n';
         
         

     // ==========================================
     // MODIFY USING []
     // ==========================================
     
     std::cout
        << "\n\n======================================\n";

     std::cout
        << "numbers[2] = 999\n";
        
     std::cout
        << "=============================================\n";
        
     numbers[2] = 999; 
     
     // =============================================
     // VERIFY
     // =============================================

     numbers.debug_memory();

     // ==============================================
     // ITERATOR STYLE ACCESS
     // ==============================================

     std::cout
        << "\n\n======================================\n";

     std::cout
        << "ITERATOR WALK\n";
        
     std::cout
        << "=========================================\n";
        
     for (int* it = numbers.begin(); it != numbers.end(); it++) {

        std::cout
           <<"\niteration address     : "
           << it 
           << '\n';

        std::cout
           << "value                   : "
           << *it 
           << '\n';   
     }   

     // ==========================================
     // POINTER DIFFERENCE
     // ==========================================

     std::cout
        << "\n\n=========================================\n";

     std::cout
        << "POINTER DIFFERENCE\n";
        
     std::cout
        << "=============================================\n";
        
     int* start = numbers.begin();
     
     int* finish = numbers.end();

     std::cout
        << "start address       : "
        << start 
        << '\n';

     std::cout
        << "finish address       : "
        << finish
        << '\n';  
        
     std::ptrdiff_t diff = finish - start;
     
     std::cout
        << "element difference   : "
        << diff
        << '\n';
}
