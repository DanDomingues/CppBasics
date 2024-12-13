#include "Account.h"
#include <iostream>
#include <ostream>
#include <string>
#include "NoBalanceException.h"

Account::Account(std::string name, double balance) 
    : name{name}, balance{balance} 
{

}

Account::~Account() {}

bool Account::deposit(double amount) 
{
    if (amount < 0) 
        return false;
    else {
        balance += amount;
        return true;
    }
}

bool Account::withdraw(double amount) 
{
    if (balance - amount  < 0) 
    {
        throw No_Balance_Exception();
        return false;
    } 

    balance-= amount;
    return true;
}

std::string Account::get_details() const
{
    return "[Account: " + name + ": " + std::to_string(balance) + "]";
}

double Account::get_balance() const
{
    return balance;
}

std::ostream &operator<<(std::ostream &os, const Account &account) 
{
    os << account.get_details();
    return os;
}
