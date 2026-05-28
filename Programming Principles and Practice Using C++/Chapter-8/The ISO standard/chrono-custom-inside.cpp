#include <iostream>
#include <string>

// =============================================
// VERY SIMPLIFIED chrono-LIKE IMPLEMENTATION
// ==============================================

// =============================================
// year
// =============================================

class year {

    private:
       int value;

    public:
       constexpr explicit year(int y) : value(y) {}
       
       constexpr bool is_leap() const {
         return (
            (value % 4 == 0 && value % 100 != 0) || (value % 400 == 0)
        );
       }

       constexpr int get() const {
         return value;
       }
};

// =============================================
// month
// ============================================

class month {

    private:
      unsigned value;

    public:
       constexpr explicit month(unsigned m) : value(m) {}
       
       constexpr bool ok() const {
          return value >= 1 && value <= 12;
       }

       constexpr unsigned get() const {
          return value;
       }
};

// ===============================================
// day
// ===============================================

class day {

    private:
      unsigned value;

    public:
       constexpr explicit day(unsigned d) : value(d) {}
       
       constexpr bool ok() const {
          return value >= 1 && value <= 31;
       }

       constexpr unsigned get() const {

          return value;
       }
};

// =================================================
// month_day
// intermediate helper
// =================================================

struct month_day {
    month m;
    day d;
};

// =================================================
// year_month_day
// =================================================

class year_month_day {
    private:
      year y;
      month m;
      day d;

    public:
      constexpr year_month_day(year yy, month mm, day dd) : y(yy), m(mm), d(dd) {}   

      bool ok() const {

        if (!m.ok() || !d.ok()) {
            return false;
        }

        unsigned max_day = 31;

        switch (m.get()) {
            
            case 2:
              max_day = y.is_leap() ? 29 : 28;
              break;

            case 4:
            case 6:
            case 9:
            case 11:
               
               max_day = 30;
               break;
        }

        return d.get() <= max_day;
      }

      void print() const {
        std::cout << y.get() << '-' << m.get() << '-' << d.get() << '\n'; 
      }

      year get_year() const {

        return y;
      }

      month get_month() const {
        return m;
      }

      day get_day() const {
        return d;
      }
};

// ===============================================
// MONTH CONSTANTS
// ==============================================

constexpr month January  {1};
constexpr month February {2};
constexpr month March    {3};
constexpr month April    {4};
constexpr month May      {5};
constexpr month June     {6};
constexpr month July     {7};
constexpr month August   {8};
constexpr month September{9};
constexpr month October  {10};
constexpr month November {11};
constexpr month December {12};

// =================================================
// operator /
// month / int
// =================================================

constexpr month_day operator/(month m, int d) {

    return {
        m, 
        day(d)
    };
}

// ===============================================
// operator /
// month_day / int
// ================================================

constexpr year_month_day operator/(month_day md, int y) {
    
    return {
        year(y),
        md.m,
        md.d
    };
}

// ============================================
// days
// ============================================

class days {

    private:
      long long value;

    public:
      constexpr explicit days(long long d) : value(d) {

      } 
      
      constexpr long long count() const {

        return value;
      }
};

// ================================================
// sys_days
// VERY SIMPLIFIED
// =================================================

class sys_days{

    private:
       long long total_day;

    public:
      explicit sys_days(long long d = 0) : total_day(d) {}
      
      sys_days& operator+=(days d) {

         total_day += d.count();
         return *this;
      }

      void print() const {
         
         std::cout << "stored days : " << total_day << '\n';
      }
};

// ==============================================
// system clock
// ==============================================

class system_clock {
    public:
      static long long now() {

        // fake timestamp
        return 1000000;
      }
};

// ================================================
// floor<days>
// ===============================================

template<typename T>
long long floor(long long value) {
    return value / 86400;
}

// ===========================================
// MAIN
// ===========================================

int main() {

    // =========================================
    // NORMAL DATE
    // ===========================================

    std::cout << "\n==================================\n";
    std::cout << "NORMAL DATE\n";
    std::cout << "=====================================\n";

    year_month_day today {
        year{2025},
        month{3},
        day{10}
    };

    today.print();

    std::cout << "valid : " << today.ok() << '\n';

    // ===========================================
    // MONTH LITERAL STYLE
    // ===========================================

    std::cout << "\n====================================\n";
    std::cout << "MONTH LITERAL STYLE\n";
    std::cout << "=======================================\n";

    auto birthday = December / 16 / 1770;

    birthday.print();

    // ============================================
    // BAD DATE
    // =============================================

    std::cout << "\n===================================\n";
    std::cout << "BAD DATE CHECK\n";
    std::cout << "=====================================\n";

    year_month_day bad_date {
        year{2025},
        February,
        day{30}
    };

    bad_date.print();

    std::cout << "vaild : " << bad_date.ok() << '\n';

    // ===========================================
    // LEAP YEAR
    // ============================================

    std::cout << "\n============================\n";
    std::cout << "LEAP YEAR\n";
    std::cout << "===============================\n";

    year y1{2024};
    std::cout << "2024 leap? : " << y1.is_leap() << '\n';

    year y2{2025};
    std::cout << "2025 leap? : " << y2.is_leap() << '\n';

    // ========================================
    // sys_days
    // =========================================

    std::cout << "\n===============================\n";
    std::cout << "sys_days\n";
    std::cout << "================================\n";

    sys_days day_point(100);
    day_point.print();
    day_point += days{7};
    day_point.print();

    // ========================================
    // system_clock
    // =======================================

    std::cout << "\n=================================\n";
    std::cout << "system_clock\n";
    std::cout << "===================================\n";

    auto now = system_clock::now();
    std::cout << "raw timestamp : " << now << '\n';

    // =======================================
    // floor<days>
    // ========================================

    std::cout << "\n=============================\n";
    std::cout << "floor<days>\n";
    std::cout << "================================\n";

    auto whole_days = floor<days>(now);

    std::cout << "whole days : " << whole_days << '\n';
}
