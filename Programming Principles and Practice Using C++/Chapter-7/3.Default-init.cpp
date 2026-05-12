#include <iostream>
#include <vector>
#include <string>

int main() {

    // =============================================
    // Built - in types (dnagerous)
    // ==============================================

    int  x;

    double d;

    std::cout << "Unintialized int x        : "
              << x
              << '\n';

    std::cout << "Unitialized double d      : " 
              << d
              << '\n';
              
    // =========================================
    // Class Type with initialization
    // ==========================================
    
    std::string name;

    std::vector<int> numbers;

    std::cout << "\nDefault initialized string:\n";

    std::cout << "name = ["
              << name 
              << "]\n";

    std::cout << "\nDefault initialization vector:\n";
    
    std::cout << "numbers.size() = "
              << numbers.size()
              << '\n';

    // =========================================
    // Adding values
    // =======================================
    
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);

    name = "Vasanth";

    std::cout << "\nAfter assigning values:\n";

    std::cout << "name = "
              << name 
              << '\n';

    std::cout << "numbers = ";
    
    for (int value : numbers)
    {
        std::cout << value << ' ';
    }

    std::cout << '\n';
              
}