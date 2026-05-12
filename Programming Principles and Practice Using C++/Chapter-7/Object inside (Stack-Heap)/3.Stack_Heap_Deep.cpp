#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <map>
#include <cstddef>
#include <algorithm>


// ==============================================
// Simple  Class
// ==============================================

class StackHeap {

     private:
        
         // --------------------------------------
         // Stored Directly inside object
         // --------------------------------------

         int id;

         double price;

         // --------------------------------------
         // Vector object strored inside object
         // BUt vector elements stored in Heap
         // --------------------------------------

         std::vector<int> numbers;

         // ----------------------------------------
         // string object stored inside object
         // string characters usually stored in Heap
         // ----------------------------------------

         std::string name;

    public:
         
        StackHeap() {

              id = 101;

              price = 999.99;

              name = "Vasanth";

              numbers.push_back(10); // first address + offset
              numbers.push_back(20);
              numbers.push_back(30);
        }

        void print_memory_layout() {
              
              std::cout
                 << "\n=================================\n"
                 << "OBJECT ADDRESS\n"
                 << "===================================\n";

              // whole object address
              std::cout << "this (Stack_Heap - Whole Obj Address)      : "
                        << this 
                        << '\n';
                        
                        
              std::cout
                 << "\n====================================\n"
                 << "Stack / Object Memory Members\n"
                 << "=======================================\n";

              // member addresses
              std::cout << "&id                 : "
                        << &id 
                        << '\n';
                        
               std::cout << "&price              : "
                         << &price
                         << '\n';
                         
               std::cout << "&numbers (vector object) : "
                         << &numbers 
                         << '\n';
                         
               std::cout << "&name (string)            : "
                         << &name 
                         << '\n';
                         
                std::cout 
                   << "\n=====================================\n"
                   << "Heap Memory\n"
                   << "========================================\n";
                   
                // vector heap memory
                std::cout << "numbers.data()                : "
                          << numbers.data()
                          << '\n';
                          
                // String heap memory
                std::cout << "name.data()                   : "
                          << static_cast<const void*>(name.data())
                          << '\n';    
                          
                          
                std::cout
                   << "\n=====================================\n"
                   << "Vector Element\n"
                   << "=========================================\n";
                   
                 for (size_t i = 0; i < numbers.size(); ++i) {

                       std::cout 
                          << "numbers[" << i << "] values      : "
                          << numbers[i]
                          << '\n';

                       std::cout 
                          << "numbers [" << i << "] address     : "
                          << &numbers[i]
                          << '\n';
                          
                       std::cout
                          << "offset from base                   : "
                          << (
                               reinterpret_cast<char*>(&numbers[i]) - reinterpret_cast<char*>(numbers.data())
                          )   
                          << " bytes\n\n";
                 }  

                 std::cout 
                    << "\n========================================\n"
                    << "Offset of members inside Object\n"
                    << "===========================================\n";

                    std::cout 
                       << "id offset          : "
                       << (
                               reinterpret_cast<char*>(&id) - reinterpret_cast<char*>(this)
                       )
                       << " bytes\n";

                    std::cout
                       << "price offset                    : "
                       << (
                             reinterpret_cast<char*>(&price) - reinterpret_cast<char*>(this)
                       )   
                       << " bytes\n";

                    std::cout 
                       << "numbers offset                  : "
                       << (
                              reinterpret_cast<char*>(&numbers) - reinterpret_cast<char*>(this)
                       )   
                       << " bytes\n";

                    std::cout 
                       << "name offset                     : "
                       << (
                               reinterpret_cast<char*>(&name) - reinterpret_cast<char*>(this)
                       )    
                       << " bytes\n";

        }
};

// ================================================
// Main
// ================================================

int main() {

    StackHeap d;

    d.print_memory_layout();
}