#pragma once
#include "Account.h"
#include <iostream>

class Savings final : public Account
{
    float m_Rate;
private:
    /* data */
public:
    Savings(const std::string &name,float balance, float rate);
    ~Savings();
    //reimplementation of the base methode
    float GetInterestRate()const final override;
    void AccumulateInterest() final override;
};