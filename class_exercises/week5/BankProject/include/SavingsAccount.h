#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H

#include "Account.h"

class SavingsAccount : public Account {
private:
    double interestRate; // Percentage rate, e.g. 3.5 means 3.5%

public:
    SavingsAccount(double initialBalance, double rate);

    double calculateInterest() const;
    void applyInterest();
    double getInterestRate() const;
};

#endif
