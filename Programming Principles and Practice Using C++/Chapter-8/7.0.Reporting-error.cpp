#include <iostream>

class Date {
    public:
      class Invalid { };

      Date(int yy, int mm, int dd);

      bool is_valid();

    private:
       int y;
       int m;
       int d;  
};

Date::Date(int yy, int mm, int dd) : y{yy}, m{mm}, d{dd} {
    if (!is_valid()) {
        throw Invalid{};
    }
}

bool Date::is_valid() {
    return 0 < m && m < 13;
}