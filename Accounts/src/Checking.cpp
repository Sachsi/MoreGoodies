#include "Checking.h"

Checking::Checking(const std::string &name, float balance, float minBalance) : 
Account(name, balance), m_MinimumBalance(minBalance)
{
}

Checking::~Checking()
{
}

void Checking::Withdraw(float amount)
{
    if((m_Balance - amount) > m_MinimumBalance)
    {   //A childclass can call any base class
        Account::Withdraw(amount);
    }
    else{
        std::cout << "Invalid amount" << std::endl;
    }
}

float Checking::GetMiniumBlance() const{
    return m_MinimumBalance;
}