#include "../include/Account.h"

#include <iostream>

Account::Account(double initialBalance) : balance(initialBalance) {
    if (initialBalance < 0.0) {
        std::cerr << "Error: Initial balance is invalid. Balance set to 0.00.\n";
        balance = 0.0;
    }
}

void Account::credit(double amount) {
    if (amount <= 0.0) {
        std::cerr << "Error: Credit amount must be greater than 0.\n";
        return;
    }

    balance += amount;
}

void Account::debit(double amount) {
    if (amount <= 0.0) {
        std::cerr << "Error: Debit amount must be greater than 0.\n";
        return;
    }

    if (amount > balance) {
        std::cout << "Debit amount exceeded account balance.\n";
        return;
    }

    balance -= amount;
}

double Account::getBalance() const {
    return balance;
}
