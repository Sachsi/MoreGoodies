#pragma once
#include <iostream>
#include "Account.h"

class Checking final : public Account
{
private:
    float m_Rate;
    float m_MinimumBalance;
public:
    //using Account::Account; // allowe to use the base constructor
    Checking(const std::string &name, float balance, float minBalance);
    ~Checking();
    //reimplementation of the base methode. The "override" key word helps
    //to be sure that one method will be override in the base class. 
    //The "final" key word say that no other child class can override this method.
    void Withdraw(float amount) final override;
    float GetMiniumBlance() const;
};

