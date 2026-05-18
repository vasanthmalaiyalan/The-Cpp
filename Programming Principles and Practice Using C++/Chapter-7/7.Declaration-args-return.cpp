#include <iostream>

// ============================================
// Function declaration
// ============================================

// return a double
double multiply(int a, double b);

// return nothing
void print_message();

// no arguments
int current_power();

// unused parameter example
int find_value(std::vector<int> values, int target, int);

// ============================================
// Function definitions
// ============================================

double multiply(int a, double b) {
    return a * b;
}

void print_message() {
    std::cout << "System started\n";
}

int current_power() {
    return 900;
}

int find_value(std::vector<int> values, int target, int) {
    for (int i = 0; i < values.size(); ++i) {
        if (values[i] == target) {
            return i;
        }
    }

    return -1;
}

// ===============================================
// Main
// ===============================================

int main() {
    print_message();

    double result = multiply(5, 2.5);

    std::cout << "Multiply result : " << result << '\n';

    int power = current_power();

    std::cout << "Current power : " << power << '\n';

    std::vector<int> numbers {10, 20, 30, 40};

    int index = find_value(numbers, 30, 999);

    std::cout << "Found at index : " << index << '\n';
}