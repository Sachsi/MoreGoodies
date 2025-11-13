#include "Account.h"


int Account::s_ANGenerator = 1000;

/**
 * @brief
 * @param name
 * @param balance
 */
Account::Account(const std::string &name, float balance) :
m_Name(name), m_Balance(balance)
{
    m_AccNo = ++s_ANGenerator;
    std::cout << "Account(const std::string &, float)" << std::endl;
}

/**
 * @brief
 */
Account::~Account(){
    std::cout << "~Account()" << std::endl;
}
const std::string Account::GetName() const{
    return m_Name;
}
int Account::GetAccountNo()const{
    return m_AccNo;
}
float Account::GetBalance()const{
    return m_Balance;
}
void Account::AccumulateInterest(){
    
}
void Account::Deposit(float amount){
    try
    {
        m_Balance += amount;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}
void Account::Withdraw(float amount){

    try
    {
        if (amount < m_Balance)
        {
            m_Balance -= amount;
        }          
          
    }
    catch(...)
    {
        //std::cerr << e.what() << '\n';
        std::cout << "Insufficient balance" << std::endl;
    }


}
float Account::GetInterestRate()const {
    return 0.0f;
}