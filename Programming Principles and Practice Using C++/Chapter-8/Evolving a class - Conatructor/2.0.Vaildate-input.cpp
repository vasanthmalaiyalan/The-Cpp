#include <iostream>
#include <stdexcept>

class Date {

    private:
      int dev;
      int month;
      int year;

    public:
      Date(int d, int m, int y) {

        if (d < 1 || d > 31)
           throw std::runtime_error("Invaild day");

        if (m < 1 || m > 12)
           throw std::runtime_error("Invaild month");
           
        day = d;
        month = m;
        year = y;   
      }   

      void print() const {

        std::cout << day << '/' << month << '/' << year << '\n';
      }
};

int main() 
{
    try {
        Date today(23, 5, 2026);

        today.print();
    }
    catch(const std::exception& e) {
        std::cout << e.what() << '\n';
    }
}