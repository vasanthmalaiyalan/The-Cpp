#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

void print_date(const year_month_day& d) {
    cout << int(d.year()) << '/' << unsigned(d.month()) 
         << '/' << unsigned(d.day()) << '\n';
}

int main() {

    // -----------------------------------------
    // Create dates
    // -----------------------------------------

    auto birthday = December / 16 / 1770;

    auto independence_day = July / 4 / 1978;

    year_month_day today {

        year{2025},
        month{3},
        day{10}
    };

    // -----------------------------------------
    // Printing dates
    // -----------------------------------------

    cout << "Birthday:\n";
    print_date(birthday);

    cout << '\n';

    cout << "Independence day:\n";
    print_date(independence_day);

    cout << '\n';

    cout << "Today:\n";
    print_date(today);

    cout << '\n';

    // -----------------------------------------
    // Checking valid date
    // -----------------------------------------

    auto good_date = February / 29 / 2024;
    auto bad_date = February / 30 / 2024;

    cout << "2024-02-29 valid? " << good_date.ok() << '\n';
    cout << "2024-02-30 valid? " << bad_date.ok() << '\n';
    cout << '\n';

    // ---------------------------------------
    // Leap year check
    // ---------------------------------------

    year y1{2024};
    year y2{2025};

    cout << "2024 leap year? " << y1.is_leap() << '\n';
    cout << "2025 leap year? " << y2.is_leap() << '\n';
    cout << '\n';

    // ------------------------------------------
    // Date comparison
    // -----------------------------------------

    if (birthday < today) {

        cout << "Birthday is earlier than today\n";
    }

    cout << '\n';

    // ----------------------------------------
    // Adding days
    // ---------------------------------------

    sys_days day_point = today;

    day_point += days{7};

    year_month_day next_week{day_point};

    cout << "After 7 days:\n";

    print_date(next_week);

    cout << '\n';

    // ---------------------------------------
    // Current system date
    // ---------------------------------------

    auto now = floor<days>(system_clock::now());

    year_month_day current{now};

    cout << "Current system date:\n";

    print_date(current);
}