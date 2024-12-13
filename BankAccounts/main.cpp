// Section 15
// Challenge 
#include <iostream>
#include <vector>
#include "Account.h"
#include "Savings_Account.h"
#include "Trust_Account.h"
#include "Checkings_Account.h"
#include "Account_Util.h"

using namespace std;

void clear_accounts(vector<Account*>& account_ptrs)
{
    delete [] account_ptrs.data();
    account_ptrs.clear();
}

void test_accounts(vector<Account*>& accounts, bool clear_list = true)
{
    display(accounts);
    deposit(accounts, 1000);
    withdraw(accounts, 2000);
    if(clear_list) clear_accounts(accounts);
}

int main() 
{
    cout.precision(2);
    cout << fixed;

    vector<Account*> accounts;

    // Accounts
    accounts.push_back(new Account {"Larry"});
    accounts.push_back(new Account {"Moe", 2000} );
    accounts.push_back(new Account {"Curly", 5000} );
    withdraw(accounts, 1000);

    accounts.push_back(new Savings_Account {"Superman", 0.0, 5} );
    deposit(accounts, 1000);
    deposit(accounts, 2000);
    deposit(accounts, 3000);
    clear_accounts(accounts);

    accounts.push_back(new Trust_Account {"Batman", 1} );
    deposit(accounts, 100 * 1000);
    withdraw(accounts, 50000);
    withdraw(accounts, 1000);
    withdraw(accounts, 1000);
    withdraw(accounts, 1000);
    withdraw(accounts, 1000);
    withdraw(accounts, 1000);
    withdraw(accounts, 1000);
    withdraw(accounts, 1000);
    clear_accounts(accounts);

    accounts.push_back(new Checkings_Account {"Wonderwoman", 5000 } );
    withdraw(accounts, 1000);
    withdraw(accounts, 1000);
    withdraw(accounts, 1000);
    clear_accounts(accounts);

    return 0;
}

//Notes
//Polymorphic arrays and fields only work dynamically as pointers
//Exceptions can have their constructors and destructors set to default and noexcept
//The what method returns a C style string (char*) with the error message