#pragma once
#include <string>
#include <iostream>
#include <exception>

class Account{
    std::string m_Name;
    int m_AccNo;
    static int s_ANGenerator;
protected:  //as protected in the base class 
            //its available in the child class
    float m_Balance;
public:
    Account(const std::string &name, float balance);
    virtual ~Account();
    const std::string GetName() const;
    float GetBalance() const;
    int GetAccountNo() const;
    //This form is called polymorphic functions and can just invoked only
    // through a pointer or reference
    // greates a virtual table and pointer for the child classes
    virtual void AccumulateInterest();
    virtual void Withdraw(float amount);
    void Deposit(float amount);
    virtual float GetInterestRate()const;
};

