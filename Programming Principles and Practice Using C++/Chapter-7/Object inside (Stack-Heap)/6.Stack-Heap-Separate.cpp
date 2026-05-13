#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <algorithm>
#include <map>

// ============================================
// 1. STACK-ONLY OBJECT
// ============================================

class Stack_only_data {

    private:
        
        // --------------------------------------------
        // ALL THESE LIVE DIRECTLY INSIDE OBJECT MEMORY
        // --------------------------------------------

        int id;

        double price;

        char grade;

        std::array<int, 3> values;

    public:
         
       Stack_only_data() {

              id = 101;

              price = 999.99;

              grade = 'A';

              values = {10, 20, 30};
       }

       void print_memory_layout() {

                std::cout 
                   << "\n============================================\n"
                   << "STACK-ONLY OBJECT\n"
                   << "==============================================\n";

                   // Whole object address
                   std::cout << "this object address          : "
                             << this
                             << '\n';

                   std::cout
                      << "\n----------------------- MEMBERS -------------------------\n";
                      
                      
                      std::cout << "&id                : "
                                << &id 
                                << '\n';

                      std::cout << "&price              : "
                                << &price
                                << '\n';
                                
                      std::cout << "&grade               : "
                                << static_cast<void*>(&grade)
                                << '\n';
                                
                      std::cout << "&values              : "
                                << &values
                                << '\n';   
                                
                     std::cout
                        << "\n============ ARRAY ELEMENT ===================\n";
                        
                        for (size_t i = 0; i < values.size(); ++i) {

                                std::cout 
                                   << "values[" << i << "] address        : "
                                   << &values[i]
                                   << '\n';
                        }

                        std::cout 
                           << "\n------------------- OFFSETS ---------------------------\n";


                        std::cout << "id offset                     : "
                                  << (
                                         reinterpret_cast<char*>(&id) - reinterpret_cast<char*>(this)
                                  )   
                                  << " bytes\n";

                        std::cout << "price offset                  : "
                                  << (
                                       reinterpret_cast<char*>(&price) - reinterpret_cast<char*>(this)
                                  )
                                  << " bytes\n";
                                  
                        std::cout << "grade offset                  : "
                                  << (

                                         reinterpret_cast<char*>(&grade) - reinterpret_cast<char*>(this)
                                  )
                                  << " bytes\n";
                                  
                        std::cout << "values offse                 : "
                                  << (
                                       reinterpret_cast<char*>(&values) - reinterpret_cast<char*>(this)
                                  )    
                                  << " bytes\n";      


                                 
       }
};

// ==================================================
// 2. STACK + HEAP OBJECT
// ===================================================

class Heap_based_data {

       private:
          //----------------------------------------
          // THESE OBJECT LIVE INSIDE OBJECT MEMORY
          // BUT THEIR ACTUAL DATA USES HEAP
          // ---------------------------------------

          std::vector<int> numbers;

          std::string name;

          std::map<int, std::string> students;

      public:
         
          Heap_based_data() {

                  numbers.push_back(10);
                  numbers.push_back(20);
                  numbers.push_back(30);

                  name = "Vasanth";

                  students[1] = "Kumar";
                  students[2] = "Arun";
          }

          void print_memory_layout() {

                 std::cout 
                    << "\n=================================================\n"
                    << "STACK + HEAP OBJECT\n"
                    << "====================================================\n";

                    // whole object address
                    std::cout << "this object address          : "
                              << this 
                              << '\n';

                    std::cout 
                       << "\n------------------- OBJECT MEMBERS --------------------\n";
                       
                       
                    std::cout << "&numbers                      : "
                              << &numbers
                              << '\n';
                              
                    std::cout << "&name                          : "
                              << &name 
                              << '\n';

                    std::cout
                       << "\n============ Stack Inside Heap Ref Object =========================\n";
                       
                       // vector heap address in stack ref inside
                       std::cout << "numbers.data()               : "
                                 << numbers.data()
                                 << '\n';
                      
                       // string heap inside stack ref address           
                       std::cout << "name.data()                  : "
                                 << static_cast<const void*>(name.data())
                                 << '\n'; 
                                 
                       std::cout 
                          << "\n------------------- VECTOR ELEMENTS --------------------------\n";
                          
                          
                          for (size_t i = 0; i < numbers.size(); ++i) {

                                       std::cout
                                          << "numbers[" << i << "] value            : "
                                          << numbers[i]
                                          << '\n';

                                       std::cout 
                                          << "numbers [" << i << "] address          : "
                                          << &numbers[i]
                                          << '\n';
                                          
                                       std::cout 
                                          << "offset from heap base                 : "
                                          << (
                                                 reinterpret_cast<char*>(&numbers[i]) - reinterpret_cast<char*>(numbers.data())
                                          )
                                          << " bytes\n\n";   
                                            
                          }

                          std::cout 
                             << "\n-------------------- MAP DATA -------------------------\n";

                             for (const auto& [id, student_name] : students) {
                                      
                                       std::cout 
                                          << " Key = "
                                          << id 
                                          << " | value = "
                                          << student_name
                                          << '\n';
                             }

                             std::cout 
                                << "\n----------------------OFFSETS -------------------------------\n";

                             std::cout << "numbers offset                  : "
                                       << (
                                             reinterpret_cast<char*>(&numbers) - reinterpret_cast<char*>(this)
                                       ) 
                                       << " bytes\n";
                                       
                              std::cout << "name offset                    : "
                                        << (
                                              reinterpret_cast<char*>(&name) - reinterpret_cast<char*>(this)
                                        ) 
                                        << " bytes\n";

                              std::cout << "students offset                 : "
                                        << (
                                            reinterpret_cast<char*>(&students) - reinterpret_cast<char*>(this)
                                        )          
                                        << " bytes\n";
                          
          }


};

// =========================================
// Main
// =========================================

int main() {

    Stack_only_data stack_object;

    stack_object.print_memory_layout();

    Heap_based_data heap_object;

    heap_object.print_memory_layout();
}