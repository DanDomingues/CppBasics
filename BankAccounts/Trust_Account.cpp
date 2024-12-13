#include "Trust_Account.h"
#include "InvalidOperationException.h"

const int reward_threshold {5000};
const double reward_perc {0.01};
const int withdraw_times_limit {3};
const double withdraw_perc_limit {0.2};

Trust_Account::Trust_Account(std::string name, double balance, int interest_rate) :
Savings_Account(name, balance, interest_rate)
{
    current_yrs_withdrawls = 0;
}

Trust_Account::~Trust_Account() {}

bool Trust_Account::deposit(double amount)
{
    if(amount >= reward_threshold)
    {
        double reward = reward_threshold * reward_perc;
        amount += reward;
    }
    return Savings_Account::deposit(amount);
}

bool Trust_Account::withdraw(double amount)
{
    if(current_yrs_withdrawls > withdraw_times_limit)
    {
        throw Invalid_Operation_Exception("Yearly withdrawals exceeded");
        return false;
    }

    if(amount >= balance * withdraw_perc_limit)
    {
        throw Invalid_Operation_Exception("Withdrawal exceeds account limit");
        return false;
    }

    current_yrs_withdrawls++;
    return Savings_Account::withdraw(amount);
}
