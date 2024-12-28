#include "Integer.h"
#include <iostream>
#include <string>

class Employee
{
private:
    std::string m_Name;
    Integer m_Id;
public:
// sometime you have to create many different constroturs
// because different kind initializiations
    // Employee(const std::string &name, const Integer &id) :
    //     m_Name{name},
    //     m_Id{id}{
    //     std::cout << "Employee( const std::string &name, const Integer &id)" << std::endl;
    //     }
//for that you can use an template as well
//this template should work for every kind of initialization
    template<typename T1, typename T2>
    Employee(T1 &&name, T2 &&id) :
        //forwarding is used to make sure the type of arg. which is used 
        //std::forward<> is used especially when internal other templates will invoked
        m_Name{std::forward<T1>(name)},
        m_Id{std::forward<T2>(id)}{
        //m_Id{id}{ //here is still used the copy Constr. when an Object is the argument
            std::cout << "Employee (std::string &name, Integer &id)" << std::endl;

        }
    //~Employee(){}
};
template<typename T1, typename T2>
Employee Create(T1 &&name, T2 &&id)
{
    return Employee(std::forward<T1>(name), std::forward<T2>(id));
}

#ifdef FORWARDING
int main(void)
{
    Employee    soft{"User", 100};
    std::string name = "User";
    // Employee emp1(name, 100);
    // Integer val{100}; 
    // Employee emp2("User", val);
    Create(name, Integer{100});
    return 1;
}

#endif