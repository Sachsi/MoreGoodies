#include <iostream>
#include "Account.h"
#include "Savings.h"
#include "Checking.h"
#include "Transaction.h"
#include <typeinfo>

//#define STEP_7_ 
//#define STEP_8_   //Object Slicing
//#define STEP_9_     //type info
#define STEP_10_    //

#ifdef STEP_10_ // dynamic caste

int main(void)
{
    Savings ch("Bob", 100,10 );
    try
    {
        Transact(ch);    
    }
    catch(const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << '\n';
    }
    
    return 1;
}

#endif 


#ifdef STEP_9_

int main(void)
{
    Checking ch("Bob", 100, 50);
    //Savings ch("Bob", 100, 0.5f);
    Account *p = &ch;
    //Transact(&ch);

    int a{};
    float f{};
    const std::type_info &ti = typeid(*p);
    if(ti == typeid(Savings))
    {
        std::cout << "p points to savings object" << std::endl;
    }else{
        std::cout << "Not point to savings object" << std::endl;
    }
    std::cout << ti.name() << std::endl;

    return 1;
}
#endif

#ifdef STEP_8_

int main(void)
{
    //Checking ch("Bob", 100, 50);
    Savings ch("Bob", 100, 0.5f);
    Transact(&ch);

    //std::cout  << "min Balance: " << ch.GetMiniumBlance();
    /*we are casting a child class to a base class. Keep in meant
    for keeping all the methods and attributs in base class, you have to do
    it by a pointer or referenc. */
    Account *pAccount = &ch;
    /*By copie the compiler will fit the child class
    in the base class.*/
    //Account Acc = ch;

    /*Down casting only when you use static_cast with the specifyte typ.*/
    //Checking *pChecking = pAccount; // not possibly
    Checking *pChecking = static_cast<Checking*>(pAccount);



    return 1;
}

#endif

#ifdef STEP_7_
int main(void)
{
    //Savings acc("Bob", 1000, 0.5f);
    //Savings *acc = new Savings("Bob", 100, 0.05f);
    /* it invoke the wrong distructor when the distructor 
       of the base class is not virtual   */
    Account *acc = new Savings("Bob", 100, 0.05f);
    //Transact(&acc);
    //std::cout << "Size of Account: " << sizeof(Account) << std::endl;
    delete acc;

    // std::cout << "Initial balance: " << acc.GetBalance() << std::endl;
    // acc.Deposit(200);
    // acc.AccumulateInterest();
    // acc.Withdraw(1190);
    // std::cout << "Balance: " << acc.GetBalance() << std::endl;
    return 1;
}
#endif