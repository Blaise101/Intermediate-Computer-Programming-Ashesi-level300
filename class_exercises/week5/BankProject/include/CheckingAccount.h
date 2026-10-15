#ifndef CHECKING_ACCOUNT_H
#define CHECKING_ACCOUNT_H

#include "Account.h"

class CheckingAccount : public Account {
private:
    double transactionFee;

public:
    CheckingAccount(double initialBalance, double fee);

    void credit(double amount) override;
    void debit(double amount) override;
    double getTransactionFee() const;
};

#endif
