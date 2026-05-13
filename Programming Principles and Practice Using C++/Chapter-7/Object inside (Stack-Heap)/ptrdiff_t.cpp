#include <iostream>

int main() {

    int numbers[5] = {10,20,30,40,50};

    int* start = &numbers[1];

    int* end = &numbers[4];

    std::cout << "start address : "
              << start 
              << '\n';

    std::cout << "end address   : "
              << end
              << '\n';
              
    // element difference
    ptrdiff_t elements_diff = end - start;
    
    std::cout << "\nElement difference   : "
              << elements_diff
              << '\n';

    // byte difference
    ptrdiff_t byte_diff = reinterpret_cast<char*>(end) - reinterpret_cast<char*>(start);
    
    std::cout << "Byte diffrence        : "
              << byte_diff
              << '\n';
}