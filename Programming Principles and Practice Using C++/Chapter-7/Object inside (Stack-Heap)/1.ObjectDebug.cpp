#include <iostream>
#include <vector>
#include <string>

// ===============================================
// CLASS
// ================================================

class Number_store {

    private:
       
        // member variable inside object
        std::vector<int> values;

    public:
       
        // member function
        void add(int value) {

            values.push_back(value);
        }

        void print_debug() {

             std::cout << "\n================= Object Info ====================\n";

             // ----------------------------------------
             // Object Address
             // ----------------------------------------

             std::cout << "this (object address)         :"
                       << this
                       << '\n';


             // ------------------------------------------
             // Member Variable Address
             // ------------------------------------------
             
             std::cout << "values member address          : "
                       << &values
                       << '\n';


             // ------------------------------------------
             // Vector Internal Data Pointer
             // ------------------------------------------
             
             std::cout << "Vector heap data 1st address(inside stack)   : "
                       << values.data() // &values[o]
                       << '\n';

            // -------------------------------------------
            // Vector Elements
            // -------------------------------------------
            
            std::cout << "\n==================================== Vector Elements ================================\n";

            for (size_t i = 0; i < values.size(); ++i) {

                   std::cout 
                      << "Index [" << i << "]\n"

                      << " value                        : "
                      << values[i] << '\n'

                      << " element address              : "
                      << &values[i] << '\n'

                      << "  calculated offset from base : "
                      << (
                              reinterpret_cast<char*>(&values[i]) - reinterpret_cast<char*>(values.data()) 
                      )
                      << " byte\n\n";
            }
        }
};

// ===============================================
// Main
// ==============================================

int main() {

        Number_store store;

        store.add(10);
        store.add(20);
        store.add(30);

        store.print_debug();
}