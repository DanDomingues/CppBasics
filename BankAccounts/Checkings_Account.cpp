#include "Checkings_Account.h"

const double withdraw_fee {1.50};

Checkings_Account::Checkings_Account(std::string name, double balance) :
Account(name, balance)
{

}

Checkings_Account::~Checkings_Account() {}

bool Checkings_Account::deposit(double amount)
{
    return Account::deposit(amount);
}

bool Checkings_Account::withdraw(double amount)
{
    return Account::withdraw(amount + withdraw_fee);
}
