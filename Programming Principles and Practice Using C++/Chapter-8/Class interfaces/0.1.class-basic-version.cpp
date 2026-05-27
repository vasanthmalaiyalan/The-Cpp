#include <iostream>

class Date {
    public:
      Date(int yy, int mm, int dd) : y{yy}, m{mm}, d{dd} {}

      int year() {
        return y;
      }

      int month() {
        return m;
      }

      int day() {
        return d;
      }

      private:
         int y;
         int m;
         int d;
};

int main() {

    Date d {2025,12,24};

    std::cout << d.day() << '/' << d.month() << '/' << d.year() << '\n';
}