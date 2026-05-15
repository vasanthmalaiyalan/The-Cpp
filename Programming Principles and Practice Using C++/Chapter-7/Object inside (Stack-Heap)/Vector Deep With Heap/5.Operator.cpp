#include <iostream>
#include <string>

// ==============================================
// SIMPLE ITERATOR
// =============================================

template<typename T>
class MyIterator {

    private:
      
       T* ptr;

    public:
      
       // -----------------------------------------
       // CONSTRUCTOR
       // -----------------------------------------

       MyIterator(T* p) {

        ptr = p;

       }

       // ----------------------------------------
       // operator*
       // ----------------------------------------

       T& operator*() {

         std::cout
            << "\n[operator* CALLED]\n";

          std::cout
             << "current address      : "
             << ptr 
             << '\n';
             
          std::cout
             << "value               : "
             << *ptr 
             << '\n';
             
          return *ptr;   
       }

       // ----------------------------------------
       // operator++
       // ----------------------------------------

       MyIterator& operator++() {

          std::cout
             << "\n[operator++ CALLED] \n";

          std::cout
             << "before increment   : "
             << ptr 
             << '\n';
             
          ptr++;
          
          std::cout
             << "after increment     : "
             << ptr 
             << '\n';

          return *this;   
       }

       // ---------------------------------------
       // operator!=
       // ----------------------------------------

       bool operator!=(const MyIterator& other) {
          
          std::cout
             << "\n[operator!= CALLED]\n";

          std::cout
             << "this ptr        : "
             << ptr
             << '\n';  
             
          std::cout
             << "other  ptr      : "
             << other.ptr
             << '\n';
             
          return ptr != other.ptr;   
       }

       // ---------------------------------------
       // operator==
       // ----------------------------------------

       bool operator==(const MyIterator& other) {

          std::cout
             << "\n[operator== CALLED]\n";

          return ptr = other.ptr;   
       }

       // -----------------------------------------
       // operator+
       // -----------------------------------------

       MyIterator operator+(int n) {

           std::cout
              << "\n[operator+ CALLED]\n";

           std::cout
              << "current ptr     : "
              << ptr 
              << '\n';
              
          std::cout
             << "move by           : "
             << n 
             << '\n';
             
          std::cout
             << "new ptr           : "
             << (ptr + n)
             << '\n';
             
           return MyIterator(ptr + n);  
       }
};

// ===========================================
// PERSON CLASS
// ============================================

class Person {

    public:
      
       std::string name;

       Person() {
         
          name = "EMPTY";
       }

       Person(std::string n) {

         name = n;
       }
};

// ==============================================
// SIMPLE SMART POINTER
// ================================================

template<typename T>
class SmartPtr {
    private:
      T* ptr;

    public:
       SmartPtr(T* p) {
         
          ptr = p;
       }  

       // ----------------------------------------
       // operator->
       // ----------------------------------------

       T* operator->() {

          std::cout
             << "\n[operator-> CALLED]\n";

          std::cout
             << "returning address      : "
             << ptr 
             << '\n';
             
           return ptr;  
       }

       ~SmartPtr() {
         delete ptr;
       }
};

// ==============================================
// SIMPLE VECTOR
// ==============================================

template<typename T>
class MyVector {
    private:
      T* data;

      size_t current_size;

      size_t current_capacity;

    public:
      // --------------------------------------
      // CONSTRUCTOR
      // --------------------------------------
      
      MyVector() {

         current_size = 0;

         current_capacity = 2;

         data = new T[current_capacity];

         std::cout
            << "\n[MyVector CONSTRUCTOR]\n";

         std::cout
            << "heap address          : "
            << data 
            << '\n';   
      }

      // ---------------------------------------
      // COPY ASSIGNMENT
      // operator=
      // -----------------------------------------

      MyVector& operator=(const MyVector& other) {

        std::cout
           << "\n[operator= CALLED]\n";

        std::cout
           << "copy assignment happening\n";
           
        delete[] data;
        
        current_size = other.current_size;

        current_capacity = other.current_capacity;

        data = new T[current_capacity];

        for (size_t i = 0; i < current_size; i++) {
            data[i] = other.data[i];

        }

        return *this;
      }

      // ---------------------------------------
      // operator==
      // ----------------------------------------

      bool operator==(const MyVector& other) {

          std::cout
             << "\n[operator== CALLED]\n";

          if (current_size != other.current_size) {

            return false;
          }   

          for (size_t i = 0; i < current_size; i++) {
            if (data[i] != other.data[i]) {
                return false;
            }
          }

          return true;
      }

      // -------------------------------------------
      // operator!=
      // --------------------------------------------

      bool operator!=(const MyVector& other) {

        std::cout
           << "\n[operator!= CALLED]\n";

        return !(*this == other);   
      }

      // -----------------------------------------
      // push_back
      // ------------------------------------------

      void push_back(const T& value) {

         if (current_size >= current_capacity) {
            current_capacity *= 2;

            T* new_block = new T[current_capacity];

            for (size_t i = 0; i < current_size; i++) {
                new_block[i] = data[i];
            }

            delete[] data;

            data = new_block;
         }

         data[current_size] = value;

         current_size++;
      }

      // ---------------------------------------
      // operator[]
      // -----------------------------------------

      T& operator[](size_t index) {

         std::cout
            << "\n[operator[] CALLED]\n";

         std::cout
            << "request index       : "
            << index
            << '\n';
            
         std::cout
            << "base address        : "
            << data 
            << '\n';
            
         std::cout
           << "calculated address    : "
           << (data + index)
           << '\n';
           
         return *(data + index);  
      }

      // -----------------------------------------
      // begin
      // -----------------------------------------

      MyIterator<T> begin() {

        return MyIterator<T>(data);
      }

      // -----------------------------------------
      // end
      // ------------------------------------------

      MyIterator<T> end() {

        return MyIterator<T> (
            data + current_size
        );
      }

      // -----------------------------------------
      // destructor
      // ------------------------------------------

      ~MyVector() {
        delete[] data;
      }
};

int main() {

    MyVector<int> numbers;

    numbers.push_back(10);

    numbers.push_back(20);

    numbers.push_back(30);

    // ==========================================
    // operator[]
    // ==========================================

    std::cout
       << "\n\n====================================\n";

     std::cout
        << "numbers[1]\n";
        
     std::cout
        << "==========================================\n";
        
     std::cout
        << numbers[1]
        << '\n';
        
    // ============================================
    // operator=
    // =============================================
    
    std::cout
       << "\n\n===========================================\n";

    std::cout
       << "COPY ASSIGNMENT\n";
       
    std::cout
       << "==========================================\n";

    MyVector<int> other;
    
    other = numbers;

    // ===========================================
    // operator==
    // ============================================

    std::cout
       << "\n\n====================================\n";

    std::cout
       << "COMPARISION ==\n";
       
    std::cout
       << "============================================\n";
       
    if (numbers == other) {

        std::cout
           << "same vectors\n";
    }   

    // ========================================
    // operator!=
    // ========================================

    std::cout
       << "\n\n====================================\n";

    std::cout
       << "COMPARISION !=\n";
       
    std::cout
       << " ========================================\n";
       
    if (numbers != other) {
        std::cout
           << "not same\n";
    }   
    else {
        std::cout
           << "vector are equal\n";
    }

    // =======================================
    // ITERATOR
    // =======================================

    std::cout
       << "\n\n===================================\n";

    std::cout
       << "ITERATOR WALK\n";
       
    for (MyIterator<int> it = numbers.begin(); it != numbers.end(); ++it) {

        std::cout
           << "\nVALUE FROM ITERATOR  : "
           << *it 
           << '\n';
    }   

    // =====================================
    // operator+
    // ====================================

    std::cout
       << "\n\n====================================\n";

    std::cout
       << "ITERATOR +\n";
       
    std::cout
       << "==========================================\n";
       
    MyIterator<int> it = numbers.begin();
    
    MyIterator<int> moved = it + 2;

    std::cout
       << "\nVALUE AFTER +2       : "
       << *moved
       << '\n';

    // ========================================
    // operator->
    // ========================================
    
    std::cout
      << "\n\n=========================================\n";

    std::cout
       << "SMART POINTER -> \n";
       
    std::cout
       << "=============================================\n";
       
    SmartPtr<Person> person(
        new Person("Tony Stark")
    );
    
    std::cout
       << "person name  : "
       << person-> name
       << '\n';

}