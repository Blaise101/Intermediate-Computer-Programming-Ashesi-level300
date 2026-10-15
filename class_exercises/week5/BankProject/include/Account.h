#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account {
protected:
    double balance;

public:
    explicit Account(double initialBalance);
    virtual ~Account() = default;

    virtual void credit(double amount);
    virtual void debit(double amount);
    double getBalance() const;
};

#endif
