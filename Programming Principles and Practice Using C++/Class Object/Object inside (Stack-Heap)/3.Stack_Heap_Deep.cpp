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
              std::cout << "this (StackHeap Class - Whole Obj Address)      : "
                        << this 
                        << '\n';
                        
                        
              std::cout
                 << "\n====================================\n"
                 << "Stack / Object Memory Members\n"
                 << "=======================================\n";

              // member addresses
              std::cout << "&id                 : "
                        << &id   // and you try this id only not &id , so why because stored in stack 
                        << '\n';
                        
               std::cout << "&price              : "
                         << &price   // same as this one 
                         << '\n';
                         
               std::cout << "&numbers (vector object) : "
                         << &numbers   // and this one is not print like `number` because stored in heap not stack (how actual data stored index)
                         << '\n';
                         
               std::cout << "&name (string)            : "
                         << &name  // same as this one but small string is consider in stack store so large string is heap stored
                         << '\n';
                         
                std::cout 
                   << "\n=====================================\n"
                   << " Stack inside data stored in Heap Address Ref calling\n"
                   << "========================================\n";
                   
                // vector heap memory inside stack
                std::cout << "numbers.data()                : "
                          << numbers.data()
                          << '\n';
                          
                // String heap memory inside stack
                std::cout << "name.data()                   : "
                          << static_cast<const void*>(name.data())
                          << '\n';    
                          
                          
                std::cout
                   << "\n=====================================\n"
                   << "Vector Element Actual Heap\n"
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

                    std::cout << "\n===================Sizeof(obj)============================\n"
                        << "Sizeof(Vector) : " << sizeof(numbers) << '\n';
                        
                        std::cout << "Sizeof(string)   : " << sizeof(name) << '\n';

        }
};

// ================================================
// Main
// ================================================

int main() {

    StackHeap d;

    d.print_memory_layout();
}

/*
| Thing           | Stored where?        |
| --------------- | -------------------- |
| int             | inside object        |
| double          | inside object        |
| vector object   | inside object        |
| vector elements | heap                 |
| string object   | inside object        |
| string chars    | usually heap         |
| `this`          | whole object address |
| `data()`        | heap address         |


 ./a.out 

=================================
OBJECT ADDRESS
===================================
this (StackHeap Class - Whole Obj Address)      : 0x7ffe1ea4a2e0

====================================
Stack / Object Memory Members
=======================================
&id                 : 0x7ffe1ea4a2e0
&price              : 0x7ffe1ea4a2e8
&numbers (vector object) : 0x7ffe1ea4a2f0
&name (string)            : 0x7ffe1ea4a308

=====================================
 Stack inside data stored in Heap Address Ref calling
========================================
numbers.data()                : 0x5ecc2938a2b0
name.data()                   : 0x7ffe1ea4a318

=====================================
Vector Element Actual Heap
=========================================
numbers[0] values      : 10
numbers [0] address     : 0x5ecc2938a2b0
offset from base                   : 0 bytes

numbers[1] values      : 20
numbers [1] address     : 0x5ecc2938a2b4
offset from base                   : 4 bytes

numbers[2] values      : 30
numbers [2] address     : 0x5ecc2938a2b8
offset from base                   : 8 bytes


========================================
Offset of members inside Object
===========================================
id offset          : 0 bytes
price offset                    : 8 bytes
numbers offset                  : 16 bytes
name offset                     : 40 bytes

===================Sizeof(obj)============================
Sizeof(Vector) : 24
Sizeof(string)   : 32
*/