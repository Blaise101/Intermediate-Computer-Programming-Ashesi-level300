#include "../include/CheckingAccount.h"

#include <iostream>

CheckingAccount::CheckingAccount(double initialBalance, double fee)
    : Account(initialBalance), transactionFee(fee) {
    if (fee < 0.0) {
        std::cerr << "Error: Transaction fee cannot be negative. Fee set to 0.00.\n";
        transactionFee = 0.0;
    }
}

void CheckingAccount::credit(double amount) {
    if (amount <= 0.0) {
        std::cerr << "Error: Credit amount must be greater than 0.\n";
        return;
    }

    // A successful credit transaction incurs a fee.
    balance += amount;

    if (transactionFee > 0.0) {
        if (balance >= transactionFee) {
            balance -= transactionFee;
        } else {
            // Roll back if the fee cannot be covered.
            balance -= amount;
            std::cout << "Credit transaction fee could not be covered; transaction cancelled.\n";
        }
    }
}

void CheckingAccount::debit(double amount) {
    if (amount <= 0.0) {
        std::cerr << "Error: Debit amount must be greater than 0.\n";
        return;
    }

    const double total = amount + transactionFee;
    if (total > balance) {
        std::cout << "Debit amount plus transaction fee exceeded account balance.\n";
        return;
    }

    balance -= total;
}

double CheckingAccount::getTransactionFee() const {
    return transactionFee;
}
