#include "Savings_Account.h"
#include <string>

class Trust_Account : public Savings_Account
{
private:
    int current_yrs_withdrawls;
    double interest_rate;
public:
    Trust_Account(std::string name, double balance = 0.0, int interest_rate = 5);
    ~Trust_Account();
    virtual bool deposit(double amount) override;
    virtual bool withdraw(double amount) override;
};
