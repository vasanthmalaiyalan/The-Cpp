#include <iostream>
#include <stdexcept>

class Date {
    private:
       int day_;
       int month_;
       int year_;

       bool vaild(int d, int m) const {
         
          return d >= 1 && d <= 31 && m >= 1 && m <= 12;
    
       }

    public:
       Date(int d, int m, int y) : day_(d), month_(m), year_(y) {
          
        if (!vaild(d, m)) {

            throw std::runtime_error("Invaild date");
          }
       }   

       int day() const {
        return day_;
       }

       int month() const {
        return month_;
       }

       int year() const {
        return year_;
       }

       void add_day(int n) {
        day_ += n;
       }

       void print() const {
        std::cout << day_ << '/' << month_ << '/' << year_ << '\n';
       }
};

int main() {

    Date birthday(14, 8, 1954);

    birthday.print();

    birthday.add_day(10);

    birthday.print();
}