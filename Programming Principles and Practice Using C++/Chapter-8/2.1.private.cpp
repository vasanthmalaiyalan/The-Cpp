#include <iostream>

class BankAccount {

    private:
       int balance;

    public:
       void deposit(int amount) {

          if (amount > 0)
             balance += amount;
       }  
       
       int get_balance() {
          return balance;
       }

       BankAccount() {
          balance = 0;
       }
};

int main() {

    BankAccount acc;

    acc.deposit(1000);

    std::cout << "Balance = " << acc.get_balance() << '\n';
}