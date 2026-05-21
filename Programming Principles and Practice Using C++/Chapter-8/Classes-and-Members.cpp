#include <iostream>
#include <string>

class BankAccount {
    public:
      std::string owner; // data member
      int balance; // data member

      // member function
      void deposit(int money) {
        balance += money;
      }

      // memeber function
      void withdraw(int money) {
        balance  -= money;
      }

      // member function
      void show() {
        std::cout << "Owner   : " << owner << '\n';
        std::cout << "Balance : " << balance << '\n';
      }
};

int main() {

    // object creation
    BankAccount acc;

    // accessing data members
    acc.owner = "Vasanth";
    acc.balance = 1000;

    // calling member functions
    acc.deposit(500);  // like inside acc.deposit(&acc, 500)
    acc.withdraw(200);

    // display final state
    acc.show();
}