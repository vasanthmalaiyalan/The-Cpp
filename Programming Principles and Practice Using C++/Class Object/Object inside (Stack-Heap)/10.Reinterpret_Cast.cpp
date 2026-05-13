#include <iostream>
#include <iomanip>

int main() {

    double price = 9.99;
    char endl = '\n';

    std::cout << "======== double price = 9.99 ========" << endl;
    std::cout << "Normal print       : " << price << endl;
    std::cout << "Address (void*)    : " << static_cast<void*>(&price) << endl;

    // reinterpret_cast - raw bytes
    char* bytes = reinterpret_cast<char*>(&price);

    std::cout << "\n======= Raw bytes (hex) point to first address =======" << endl;
    for (int i = 0; i < (int)sizeof(double); i++) {
        std::cout << "byte[" << i << "] address: " << static_cast<void*>(&bytes[i])
                  << " value: 0x"
                  << std::hex << std::setw(2) << std::setfill('0')
                  << (int)(unsigned char)bytes[i]
                  << std::dec << '\n';
    }

    double* back = reinterpret_cast<double*>(bytes);
    std::cout << "\n==== bytes -> double* -> dereference ====" << endl;
    std::cout << "Value : " << *back << endl;

    return 0;
}
