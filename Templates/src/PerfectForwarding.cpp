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
        m_Name{name},
        m_Id{id}{
            std::cout << "Employee (std::string &name, Integer &id)" << std::endl;

        }
    //~Employee(){}
};

#ifdef FORWARDING
int main(void)
{
    Employee    soft{"User", 100};
    std::string name = "User";
    Employee emp1(name, 100);
    Integer val{100};
    Employee emp2("User", val);
    return 1;
}

#endif