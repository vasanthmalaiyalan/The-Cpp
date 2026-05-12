#include <iostream>
#include <vector>

int main() {

    std::vector<int> numbers {10, 20, 30};

    // heap starting address(inside stack)
    int* ptr = numbers.data();

    std::cout << "Heap first address(inside stack obj) : " // this address is inside object stack reference stored in inside first address only
              << ptr 
              << '\n';

    std::cout << "First value        : "
              << *ptr 
              << '\n';
              
    std::cout << "Second value       : "
              <<  *(ptr + 1)
              << '\n';
              
    std::cout << "Third value        : "
              << *(ptr + 2)
              << '\n';          
}