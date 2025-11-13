#include "Savings.h"

/**
 * @brief Construtor for Savings. Here we have to invoke the base class as well
 * @param name 
 * @param balance 
 * @param rate 
 */
Savings::Savings(const std::string &name,float balance, float rate) : 
Account(name, balance), m_Rate(rate)
{
    std::cout << "Savings(const std::string &, float)" << std::endl;
}

Savings::~Savings()
{
    std::cout << "~Savings()" << std::endl;
}

float Savings::GetInterestRate() const{
    return m_Rate;
}

void Savings::AccumulateInterest(){
    m_Balance += (m_Balance * m_Rate);
}
