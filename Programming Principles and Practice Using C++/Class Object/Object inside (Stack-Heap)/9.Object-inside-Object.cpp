#include <iostream>
#include <vector>

class Demo {

    private:
        int id = 101;

        double price = 999.99;

        std::vector<int> numbers {10,20,30};

    public:
        void print() {

            std::cout
               << "\n============ NORMAL MEMBERS ===================\n";

               // normal members
               std::cout << "&id                     : "
                         << &id 
                         << '\n';

               std::cout << "id value                 : "
                         << id 
                         << '\n';

               std::cout << "\n&price                  : "
                         << &price
                         << '\n';
                         
               std::cout << "price value                : "
                         << price
                         << '\n';
                         
               std::cout
                  << "\n=============== VECTOR OBJECT (seprate) =========================\n";
                  
               // vector object address
               std::cout << "&numbers                   : "
                         << &numbers
                         << '\n';
                         
               std::cout
                  << "\n================== INTERNAL DATA POINTER ========================\n";
                  
              // INTERNAL DATA POINTER VALUES
              std::cout << "numbers.data()               : "
                        << numbers.data()
                        << '\n';    
                          
              std::cout
                 << "\n================ FIRST HEAP VALUE =========================\n";
                 
              std::cout << "*numbers.data()                 : "
                        << *numbers.data()
                        << '\n';
                        
              std::cout
                 << "\n====================== Vector Elements ===========================\n";
                 
               for (size_t i = 0; i < numbers.size(); ++i) {

                 std::cout
                    << "numbers[" << i << "] value          : "
                    << numbers[i]
                    << '\n';

                 std::cout 
                    << "numbers[" << i << "] address         : "
                    << &numbers[i]
                    << "\n\n";   
               }  
                                    
                         
        }    
};

int main() {

    Demo d;

    d.print();
}