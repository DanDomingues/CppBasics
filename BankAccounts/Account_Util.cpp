#include <iostream>
#include "Account_Util.h"

// Displays Account objects in a  vector of Account objects 
void display(const std::vector<Account*> &accounts) 
{
    std::cout << "\n=== Accounts ==========================================" << std::endl;
    for (const auto &acc: accounts) 
        std::cout << *acc << std::endl;
}

// Deposits supplied amount to each Account object in the vector
void deposit(std::vector<Account*> &accounts, double amount) 
{
    std::cout << "\n=== Depositing to Accounts =================================" << std::endl;
    for (auto &acc:accounts)  
    {
        std::cout << "Attempting deposit of " << amount << " to " << *acc << std::endl;
        try
        {
            acc->deposit(amount);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }        
    }
}

// Withdraw amount from each Account object in the vector
void withdraw(std::vector<Account*> &accounts, double amount) 
{
    std::cout << "\n=== Withdrawing from Accounts ==============================" <<std::endl;
    for (auto &acc:accounts)  
    {
        std::cout << "Attempting Withdrawal of " << amount << " from " << *acc << std::endl;
        try
        {
            acc->withdraw(amount);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    } 
}