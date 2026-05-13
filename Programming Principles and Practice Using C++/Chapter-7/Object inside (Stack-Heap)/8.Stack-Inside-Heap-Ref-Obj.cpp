#include <iostream>
#include <vector>

int main() {

    std::vector<int> numbers {10, 20 , 30};

    std::cout 
       << "\n====================== VECTOR OBJECT (Seperate) ========================\n";

    std::cout << "&numbers                 : "
              << &numbers
              << '\n';
              
    std::cout 
       << "\n============== Stack Inside INTERNAL Ref DATA POINTER =======================\n";
       
       
    std::cout << "numbers.data()          : "
              << numbers.data()
              << '\n';

    std::cout 
       << "\n============================= FIRST ELEMENT ADDRESS =============================\n";
       
    std::cout << "&numbers[0]                : "
              << &numbers[0]
              << '\n';
              
    std::cout
       << "\n================ VALUES ==================\n";
       
    std::cout << "numbers[0]                   : "
              << numbers[0]
              << '\n';
              
    std::cout << "*(numbers.data())             : "
              << *(numbers.data())
              << '\n';          
              
}

/*
./a.out 

====================== VECTOR OBJECT (Seperate) ========================
&numbers                 : 0x7fff925cb980

============== Stack Inside INTERNAL Ref DATA POINTER =======================
numbers.data()          : 0x57a8ea6522b0

============================= FIRST ELEMENT ADDRESS =============================
&numbers[0]                : 0x57a8ea6522b0

================ VALUES ==================
numbers[0]                   : 10
*(numbers.data())             : 10
*/
