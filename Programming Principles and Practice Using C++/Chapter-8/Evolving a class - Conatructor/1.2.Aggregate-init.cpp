#include <iostream>

// -------1. Aggregate struct -----------------------
struct Date {

    int day;
    int month;
    int year;
};

// ----------2. Partial init ------------------------
struct Point {

    int x;
    int y;
    int z;
};

int main() {

    //-------- initialization ------------------
    Date d1 {23, 5, 2026};
    std::cout << "d1: " << d1.day << "/" << d1.month << "/" << d1.year << "\n";
    // Output: 23/5/2026

    // ----- Copy-list-initialization -----------
    Date d2 = {1, 1, 2000};
    std::cout << "d2: " << d2.day << "/" << d2.month << "/" << d2.year << "\n";
    // Output: 1/1/2000

    // --------- Empty brace ---------------------
    Date d3 {};
    std::cout << "d3: " << d3.day << "/" << d3.month << "/" << d3.year << "\n";
    // Output: 0/0/0

    // ------ Partial init ---------------------
    Point p1 {10, 20};
    std::cout << "p1: " << p1.x << " " << p1.y << " " << p1.z << "\n";
    // Output: 10 20 0

    // ---------Assignment vs Initialization--------
    Date d4;
    d4.day = 15;
    d4.month = 8;
    d4.year = 1947;
    std::cout << "d4: " << d4.day << "/" << d4.month << "/" << d4.year << '\n';
    // Output: 15/8/1947

    // ------- Member direct access ------------
    Date d5 {10, 10, 2010};
    d5.year = 2025; 
    std::cout << "d5: " << d5.day << "/" << d5.month << "/" << d5.year << "\n";
    // Output: 10/10/2025

    // --------- Struct copy --------------------
    Date d6 = d5; // copy
    std::cout << "d6: " << d6.day << "/" << d6.month << "/" << d6.year << "\n";
    // output: 10/10/2025

    return 0;

}


/*
./a.out
d1: 23/5/2026
d2: 1/1/2000
d3: 0/0/0
p1: 10 20 0
d4: 15/8/1947
d5: 10/10/2025
d6: 10/10/2025
*/
