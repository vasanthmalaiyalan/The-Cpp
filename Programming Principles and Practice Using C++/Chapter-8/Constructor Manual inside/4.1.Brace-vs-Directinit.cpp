#include <iostream>

// ============================================
// 1. Constructor struct (Aggregate)
// ============================================

struct Point {

    int x;
    int y;
    int z;
};

// =============================================
// 2. Constructor struct
// ============================================

struct Person {

    std::string name;
    int age;

    Person(std::string n, int a) {
        name = n;
        age = a;
        std::cout << "Person constructor called\n";
    }
};

int main() {

    std::cout << "=== Constructor don't have struct (Point) ===\n\n";

    std::cout << "=== Braces {} only work in (Point) because don't have Constructor in (Point) ====\n";

    Point p1{10, 20, 30};
    std::cout << "p1 (aggregate init {}): " << p1.x << ", " << p1.y << ", " << p1.z << "\n";

    std::cout << "If you use p2 like p2(10, 20, 30) didn't work because don't have constructor" << "\n";

    std::cout << "\n=== Constructor inside struct ====\n";

    // Constructor call inside
    Person person1{"Arun", 25}; // {} -> constructor call
    Person person2("Priya", 30); // () -> constructor call

    std::cout << "person1: " << person1.name << ", " << person1.age << "\n";
    std::cout << "person2: " << person2.name << ", " << person2.age << "\n";

    std::cout << "\n==== Narrowing conversion =====\n";

    int a(3.9);
    std::cout << "int a(3.9) = " << a << "  <- truncate warning\n";

    // int b{3.9}; // ERROR - {} narrowing 
    std::cout << "int b{3.9} - ERROR , Compile \n";

    return 0;
}