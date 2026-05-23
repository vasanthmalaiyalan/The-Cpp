#include <iostream>

class Date {

    private:
       int day;
       int month;
       int year;

    public:
       Date(int d, int m, int y) { // constructor
         
         day = d;
         month = m;
         year = y;
       }   

       void print() {

          std::cout << day << '/' << month << '/' << year << '\n';
       }
};

int main() {

    Date today(23, 5, 2026);

    today.print();
}