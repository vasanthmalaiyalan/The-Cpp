#include <iostream>
#include <vector>
#include <string>

// =====================================================
// CLASS FOR MEMORY / CAST DEMO
// ================================================

class Memory_Demo {

        private:
            
           int id;

           double price;

           char grade;

           std::string name;

        public:
           
            Memory_Demo() {

                id = 101;

                price = 999.99;

                grade = 'A';

                name = "Vasanth";
            }

            void demonstrate_reinterpret_cast() {

                std::cout 
                   << "\n===============================================\n"
                   << "1. reinterpret_cast<char*>\n"
                   << "==================================================\n";

                   // -------------------------------------------
                   // OBJECT ADDRESS
                   // --------------------------------------------

                   std::cout << "this objet address            : "
                             << this
                             << '\n';

                  // -----------------------------------------
                  // MEMBER ADDRESS
                  // -----------------------------------------
                  
                  std::cout << "&id                          : "
                            << &id 
                            << '\n';

                  std::cout << "&price                        : "
                            << &price
                            << '\n';
                            
                  std::cout << "&grade                         : "
                            << static_cast<void*>(&grade) // void* -> means no type only raw
                            << '\n';
                            
                 // -----------------------------------------
                 // OFFSET CALCULATION
                 // -------------------------------------------
                 
                 std::cout 
                    << "\n---------------------------- OFFSETS -----------------------\n";

                 // convert address into char*
                 // so substraction becomes BYTES subtraction
                 
                 ptrdiff_t id_offset = reinterpret_cast<char*>(&id) - reinterpret_cast<char*>(this);

                 ptrdiff_t price_offset = reinterpret_cast<char*>(&price) - reinterpret_cast<char*>(this);

                 ptrdiff_t grade_offset = reinterpret_cast<char*>(&grade) - reinterpret_cast<char*>(this);

                 std::cout << "if offset                         : "
                           << id_offset
                           << " bytes\n";

                 std::cout << "price offset                    : "
                           << price_offset
                           << " bytes\n" ;   
                           
                 std::cout << "grade offset                    : "
                           << grade_offset
                           << " bytes\n";
                           
                // ------------------------------------------
                // RAW MEMORY VIEW
                // -------------------------------------------
                
                std::cout 
                   << "\n---------------------- RAW BYTES OF id --------------------------\n";

                   char* raw_bytes = reinterpret_cast<char*>(&id);

                   for (size_t i = 0; i < sizeof(id); ++i) {

                           std::cout
                              << "bytes[" << i << "] = "
                              << static_cast<int>(
                                     static_cast<unsigned char>(raw_bytes[i])
                              )
                              << '\n';
                   }
            }

            void demonstrate_static_cast() {

                std::cout 
                   << "\n==========================================\n"
                   << "2. static_cast<const void*>\n"
                   << "=============================================\n";

                   // ------------------------------------------
                   // WITHOUT CAST
                   // ------------------------------------------

                   std::cout 
                      << "\nWITHOUT static_cast:\n";


                    std::cout << "name.data() prints string        : "
                              << name.data()
                              << '\n';
                              
                   // -------------------------------------
                   // WITH CAST
                   // -------------------------------------
                   
                   std::cout 
                      << "\nWITH static_cast<const void*>:\n";

                   std::cout << "Actual heap address           : "
                             << static_cast<const void*>(name.data())
                             << '\n';
                             
                    // ------------------------------------------
                    // Firstt Charater Address
                    // -------------------------------------

                    std::cout 
                       << "\nFIRST CHARACTER:\n";

                    std::cout << "*name.data()         : "
                              << *name.data()
                              << '\n';
                              
                    // -------------------------------------------
                    // POINTER ARITHMATIC
                    // ------------------------------------------
                    
                    std::cout 
                       << "\nCHARACTER ADDRESS:\n";

                    for (size_t i = 0; i < name.size(); ++i) {
                        
                        std::cout
                           << "name[" << i << "] = "
                           << name[i]
                           << " | address = "
                           << static_cast<const void*>(name.data() + i)
                           << '\n';
                    }   

            }
};

// ==============================================
// MAIN
// ================================================

int main() {

    Memory_Demo demo;

    demo.demonstrate_reinterpret_cast();

    demo.demonstrate_static_cast();
}