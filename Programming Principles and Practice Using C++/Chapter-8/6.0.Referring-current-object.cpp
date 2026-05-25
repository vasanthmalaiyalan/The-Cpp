#include <iostream>

class Date {
    public:
       Date(int yy, int mm, int dd) : y{yy}, m{mm}, d{dd} {

       }

       int month() {
          return m;
       }

    private:
       int y;
       int m;
       int d;   
};

void f(Date d1, Date d2) {
    std::cout << d1.month() << ' ' << d2.month() << '\n';
}

int main() {

    Date christmas{2025, 12, 25};
    Date independence{1947, 8, 15};

    f(christmas, independence);
}