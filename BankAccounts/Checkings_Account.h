#include "Account.h"

class Checkings_Account : public Account
{
public:
    Checkings_Account(std::string name, double balance = 0.0);
    ~Checkings_Account();
    bool deposit(double amount);
    bool withdraw(double amount);
};