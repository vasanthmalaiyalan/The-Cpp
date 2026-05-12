#include <iostream>
#include <vector>
#include <string>

int main() {

    // =========================================
   //  Uninitialized variable (BAD)
   // ==========================================

   /*int garbage_value;

   std::cout << "Uninitialized value (dangerous): ";
             << garbage_value
             << '\n';*/

    // ===============================================
    // Initialized variable (Good)
    // ============================================
    
    int age = 21;

    double price = 199.99;

    std::string name {"Vasanth"};

    // ============================================
    // Constant declarations
    // =============================================

    const double pi = 3.1415926535;

    const int max_users {100};

    // ==========================================
    // Vector initilization
    // ========================================

    std::vector<int> numbers(5);

    std::vector<int> scores {95, 88, 76, 100};

    // =========================================
    // Output
    // ==========================================

    std::cout << "\nInitialized variable:\n";

    std::cout << "Age       :"
              << age
              << '\n';

     std::cout << "Price    :"
               << price
               << '\n';
               
    std::cout << "Name      :"
              << name 
              << '\n';

    std::cout << "\nConstants:\n";
    
    std::cout << "Pi        :"
              << pi 
              << '\n';

    std::cout << "Max users  :  "
              << max_users
              << '\n';
              
              
    std::cout << "\nVector with size constructor:\n";
    
    for (int value : numbers) {

        std::cout << value << ' ';
    }

    std::cout << "\n\nVector with initializer list:\n";

    for (int value : scores) {

        std::cout << value << ' ';
    }

    std::cout << '\n';
}

/*
| Concept                  | Example                      |
| ------------------------ | ---------------------------- |
| Uninitialized variable   | `int garbage_value;`         |
| `=` initialization       | `int age = 21;`              |
| `{}` initialization      | `string name {"Vasanth"};`   |
| const variable           | `const double pi`            |
| `( )` constructor syntax | `vector<int> numbers(5)`     |
| `{}` initializer list    | `vector<int> scores {95,88}` |

*/