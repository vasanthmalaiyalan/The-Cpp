#include <iostream>
#include <cstdint>

class year {
    public:
      int value;
      explicit year(int y) : value(y) {}
};

class month {
    public:
      unsigned value;
      explicit month(unsigned m) : value(m) {}
};

class year_month_day {
    public:
      year y;
      month m;

   year_month_day(year yy, month mm) :: y(yy), m(mm) {}   
};

int main() {

    year_month_day date { year{2025}, month{3} };

    // ==========================================
    // char* 
    // ===========================================

    // char* = 1byte move 
    char* base_char = reinterpret_cast<char*>(&date);

    std::cout << "=== char* ====\n";
    
    std::cout << "base   : " << (void*)base_char << '\n';
    std::cout << "base + 4 (m) : " << (void*)(base_char + 4) << '\n';

    // ================================
    // unintptr_t
    // ==================================

    uintptr_t base_unit = reinterpret_cast<uintptr_t>(&date);

    std::cout << "\n=== uintptr_t ====\n";

    std::cout << "base   : " << base_uint << '\n';
    std::cout << "base + 4 (m) : " << (base_uint + 4) << '\n';

    // =====================================
    // same result
    // =====================================

    std::cout << "\n=== Same result char used ===\n";

    bool same = (reinterpret_cast<uintptr_t>(base_char + 4) == (base_uint + 4));

    std::cout << "match : " << (same ? "YES" : "NO") << '\n';

    return 0;

}