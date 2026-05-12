#include <iostream>
#include <string>
#include <vector>

// =================================================
// Global Scope
// ================================================

int global_value = 100;

// ===============================================
// Function in global scope
// ==============================================

int max_value(int a, int b) {

    // local scope
    int result;

    if (a >= b) {

        result = a;
    }
    else {

        result = b;
    }

    return result;
}

// ==================================================
// Class scope
// ================================================

class Number_store {

    private:
       std::vector<int> values;

    public:
       void add(int value) {

             values.push_back(value);
       }   

       int largest() {

              int biggest = 0;

              // statement scope
              for (size_t i = 0; i < values.size(); ++i) {

                    biggest = max_value(biggest, values[i]);
              }

              // i no longer exits here

              return biggest;
       }
};

// ==================================================
// Function demonstrating shadowing
// =================================================

void scope_demo() {

          int x = 10;

          std::cout << "Outer x : "
                    << x 
                    << '\n';

          {
              int x = 20;

              std::cout << "Inner x : "
                        << x 
                        << '\n';
          }          

          std::cout << "Outer x again  : "
                    << x 
                    << '\n';

}

// ================================================
// Main
// =================================================

int main() {

    Number_store store;

    store.add(5);
    store.add(40);
    store.add(12);

    std::cout << "Largest value : "
              << store.largest()
              << '\n';

     scope_demo();
     
     std::cout << "Global value : "
               << global_value
               << '\n';
}