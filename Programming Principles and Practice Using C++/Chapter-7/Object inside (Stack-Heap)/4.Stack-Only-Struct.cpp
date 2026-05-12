#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <map>
#include <cstddef>
#include <algorithm>

struct Stack_only {

    int id;

    double price;

    char grade;

    std::array<int, 3> values;
};

int main() {

    Stack_only s {

        101,
        999.99,
        'A',
        {10, 20 , 30}
    };

    std::cout 
       << "\n====================== OBJECT ADDRESS ==================\n";

    std::cout << "&s          : "
              << &s 
              << '\n';
              
    std::cout 
       << "\n==================== MEMBERS ===============\n";
       
    std::cout << "&s.id          : "
              << &s.id
              << '\n';
              
    std::cout << "&s.price       : "
              << &s.price
              << '\n';
              
    std::cout << "&s.grade       : "
              << static_cast<void*>(&s.grade)
              << '\n';
              
    std::cout << "&s.values       : "
              << &s.values
              << '\n';
              
              
    std::cout 
       << "\n===================== ARRAY ELEMENTS ======================\n";
       
       for (size_t i = 0; i < s.values.size(); ++i) {

               std::cout 
                  << "Values[" << i << "] address: "
                  << &s.values[i]
                  << '\n';
       }
}

/*
./a.out 

====================== OBJECT ADDRESS ==================
&s          : 0x7fffb9843e40

==================== MEMBERS ===============
&s.id          : 0x7fffb9843e40
&s.price       : 0x7fffb9843e48
&s.grade       : 0x7fffb9843e50
&s.values       : 0x7fffb9843e54

===================== ARRAY ELEMENTS ======================
Values[0] address: 0x7fffb9843e54
Values[1] address: 0x7fffb9843e58
Values[2] address: 0x7fffb9843e5c
*/