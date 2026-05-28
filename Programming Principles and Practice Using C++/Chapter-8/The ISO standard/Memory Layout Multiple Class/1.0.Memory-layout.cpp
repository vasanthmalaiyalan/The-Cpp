#include <iostream>
#include <cstddef> // offsetof
#include <cstdint> // uintptr_t

// =============================================
// Simple Classes
// ==============================================

class year {
    public:
      int value; // 4 bytes
      explicit year(int y) : value(y) {}
};

class month {
    public:
       unsigned value; // 4 bytes
       explicit month(unsigned m) : value(m) {}
};

class day {
    public:
      unsigned value; // 4 bytes
      explicit day(unsigned d) : value(d) {}
};

// =============================================
// COMPOSITE CLASS
// =============================================

class year_month_day {
    public:
       year y; // 4 bytes
       month m; // 4 bytes
       day d; // 4 bytes
       
       year_month_day(year yy, month mm, day dd) : y(yy), m(mm), d(dd) {}
};

// =============================================
// HELPER - address print
// =============================================

void printAddress(const char* name, const void* ptr) {

    std::cout << name << " address : " << ptr << '\n';
}

int main() {

    year_month_day date {
        year{2025},
        month{3},
        day{10}
    };
    

    // ==========================================
    // OBJECT SIZE
    // ==========================================

    std::cout << "================================\n";
    std::cout << "OBJECT SIZE\n";
    std::cout << "=================================\n";

    std::cout << "sizeof(year)           : " << sizeof(year) << " bytes\n";
    std::cout << "sizeof(month)          : " << sizeof(month) << " bytes\n";
    std::cout << "sizeof(day)            : " << sizeof(day) << " bytes\n";
    std::cout << "sizeof(year_month_day) : " << sizeof(year_month_day) << " bytes\n";

    // ========================================
    // ADDRESSES -  எங்கே memory-ல் உள்ளது
    // =======================================

    std::cout << "\n===================================\n";
    std::cout << "MEMORY ADDRESSES\n";
    std::cout << "======================================\n";

    printAddress("date (whole object)", &date);
    printAddress("date.y             ", &date.y);
    printAddress("date.m             ", &date.m);
    printAddress("date.d             ", &date.d);

    // ===========================================
    // OFFSET - base address-இல் இருந்து எத்தனை bytes தள்ளி?
    // =============================================

    std::cout << "====================================\n";
    std::cout << "OFFSET FROM BASE ADDRESS\n";
    std::cout << "=====================================\n";

    std::cout << "offset of y : " << offsetof(year_month_day, y) << " bytes\n";
    std::cout << "offset of m : " << offsetof(year_month_day, m) << " bytes\n";
    std::cout << "offset of d : " << offsetof(year_month_day, d) << " bytes\n";

    // ===================================================
    // MANUAL CALCULATION - Address arithmetic
    // ===================================================

    std::cout << "\n=====================================\n";
    std::cout << "MANUAL ADDRESS CALCULATION\n";
    std::cout << "=========================================\n";

    // base address
    uintptr_t base = reinterpret_cast<uintptr_t>(&date);

    std::cout << "base address  : " << base << '\n';
    std::cout << "base + 0 (y starts) : " << base << '\n';
    std::cout << "base + 4 (m starts) : " << (base + 4) << '\n';
    std::cout << "base + 8 (d starts) : " << (base + 8) << '\n';

    // ==============================================
    // VERIFY - Actual vs calculated
    // ===============================================

    std::cout << "\n=====================================\n";
    std::cout << "VERIFY - Actual vs calculated\n";
    std::cout << "=======================================\n";

    uintptr_t actual_y = reinterpret_cast<uintptr_t>(&date.y);
    uintptr_t actual_m = reinterpret_cast<uintptr_t>(&date.m);
    uintptr_t actual_d = reinterpret_cast<uintptr_t>(&date.d);

    std::cout << "date.y actual address : " << actual_y << " | base+0 : " << (base + 0) 
              << " | match : " << (actual_y == base + 0 ? "YES" : "NO") << '\n';

    std::cout << "date.m actual address : " << actual_m << " | base+4 : " << (base + 4)
              << " | match : " << (actual_m == base + 4 ? "YES" : "NO") << '\n';
              
    std::cout << "date.d actual address : " << actual_d << " | base+8 : " << (base + 8)
              << " | match : " << (actual_d == base + 8 ? "YES" : "NO") << '\n';
              
    // ============================================
    // MEMORY LAYOUT VISUAL
    // ============================================
    
    std::cout << "\n============================================\n";
    std::cout << "MEMORY LAYOUT VISUAL\n";
    std::cout << "=============================================\n";

    std::cout << R"( [ year_month_day - 12 bytes total ] 
                     |                                 |
                     | year y  | month m | day d       |
                     | [0] - [3] | [4] - [7]| [8] - [11]| 
                     |4 bytes  | 4 bytes | 4 bytes    |
)";
    std::cout << '\n';

    return 0;
}