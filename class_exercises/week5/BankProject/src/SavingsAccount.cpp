#include "../include/SavingsAccount.h"

#include <iostream>

SavingsAccount::SavingsAccount(double initialBalance, double rate)
    : Account(initialBalance), interestRate(rate) {
    if (rate < 0.0) {
        std::cerr << "Error: Interest rate cannot be negative. Rate set to 0.00%.\n";
        interestRate = 0.0;
    }
}

double SavingsAccount::calculateInterest() const {
    return getBalance() * interestRate / 100.0;
}

void SavingsAccount::applyInterest() {
    credit(calculateInterest());
}

double SavingsAccount::getInterestRate() const {
    return interestRate;
}
