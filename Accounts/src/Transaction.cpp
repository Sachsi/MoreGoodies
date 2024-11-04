#include "Transaction.h"
#include "Checking.h"
#include <iostream>

/* - But the problem is by using a argument like Checking, we
can not use this function to transact money to the saving account.
To do that, we use the base class. With the base class we have 
access to all child classes as well.
- When using the base class there is now another problem. This function
will always use the pointer to the base class because it doesn't know
if its a saving or checking class. By using the method AccumulateInterest()
we have to give the base methode the key word "virtual" so the base class knows
knows it excits an methode in the child class.
- This form is called polymorphism*/
void Transact(Account *pAccount){
    std::cout << "Transaction started" << std::endl;
    std::cout << "Initial balance: " << pAccount->GetBalance() << std::endl;
    pAccount->Deposit(100);
    pAccount->AccumulateInterest();
    
    //Before we use down casting, we have to check if the pointer points on the corret class
    // with help of typeinfo
#ifdef  STEP_9_
    if(typeid(*pAccount) == typeid(Checking))
    {
        Checking *pChecking = static_cast<Checking*>(pAccount);
        std::cout << "Minimum balance of Checking: " << pChecking->GetMiniumBlance() << std::endl;
    }
#endif

    //or with the hlp of dynamic cast. It returns nullptr if it's the wrong class
    Checking *pChecking = dynamic_cast<Checking*>(pAccount);
    if(pChecking != nullptr)
    {
        std::cout << "Minimum balance of Checking: " << pChecking->GetMiniumBlance() << std::endl;
    }

    pAccount->Withdraw(170);
    std::cout << "Interest rate:" << pAccount->GetInterestRate() << std::endl;
    std::cout << "Final balance: " << pAccount->GetBalance() << std::endl;
}

void Transact(Account &pAccount){
    std::cout << "Transaction started" << std::endl;
    std::cout << "Initial balance: " << pAccount.GetBalance() << std::endl;
    pAccount.Deposit(100);
    pAccount.AccumulateInterest();
    
    //Before we use down casting, we have to check if the pointer points on the corret class
    // with help of typeinfo
#ifdef  STEP_9_
    if(typeid(*pAccount) == typeid(Checking))
    {
        Checking *pChecking = static_cast<Checking*>(pAccount);
        std::cout << "Minimum balance of Checking: " << pChecking->GetMiniumBlance() << std::endl;
    }
#endif

    //or with the help of dynamic cast. It returns not a nullptr if it's the wrong class, we have to
    // to use the try and catch function to catch the error message. And its slower than typeid
    Checking &pChecking = dynamic_cast<Checking&>(pAccount);
    std::cout << "Minimum balance of Checking: " << pChecking.GetMiniumBlance() << std::endl;

    pAccount.Withdraw(170);
    std::cout << "Interest rate:" << pAccount.GetInterestRate() << std::endl;
    std::cout << "Final balance: " << pAccount.GetBalance() << std::endl;
}