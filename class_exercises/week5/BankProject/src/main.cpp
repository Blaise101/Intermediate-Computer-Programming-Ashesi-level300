#include "../include/Account.h"
#include "../include/SavingsAccount.h"
#include "../include/CheckingAccount.h"

#include <iomanip>
#include <iostream>

int main() {
    std::cout << std::fixed << std::setprecision(2);

    Account regularAccount(500.00);
    SavingsAccount savingsAccount(1000.00, 3.5);
    CheckingAccount checkingAccount(800.00, 2.00);

    std::cout << "=== Bank Account Inheritance Demo ===\n\n";

    std::cout << "Regular account:\n";
    regularAccount.credit(100.00);
    regularAccount.debit(50.00);
    std::cout << "Balance: $" << regularAccount.getBalance() << "\n\n";

    std::cout << "Savings account:\n";
    std::cout << "Balance before interest: $" << savingsAccount.getBalance() << "\n";
    std::cout << "Interest earned: $" << savingsAccount.calculateInterest() << "\n";
    savingsAccount.applyInterest();
    std::cout << "Balance after interest: $" << savingsAccount.getBalance() << "\n\n";

    std::cout << "Checking account (transaction fee: $"
              << checkingAccount.getTransactionFee() << "):\n";
    checkingAccount.credit(100.00);
    std::cout << "Balance after $100.00 credit: $"
              << checkingAccount.getBalance() << "\n";
    checkingAccount.debit(50.00);
    std::cout << "Balance after $50.00 debit: $"
              << checkingAccount.getBalance() << "\n";

    std::cout << "\nTesting an invalid withdrawal:\n";
    regularAccount.debit(10000.00);
    std::cout << "Regular account balance remains: $"
              << regularAccount.getBalance() << "\n";

    return 0;
}
