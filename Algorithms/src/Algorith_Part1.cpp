#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>
/**
 * include algorithm header is for the global sort function
 */

class Employee {
    std::string m_Name;
    int m_Id;
    std::string m_ProgLang;
public:
    Employee(const std::string& name, int id, const std::string& progLang)
        : m_Name(name), m_Id(id), m_ProgLang(progLang){}
    
    const std::string& GetName()const{
        return m_Name;
    }
    int GetId()const{
        return m_Id;
    }
    const std::string& GetProgrammingLanguage()const{
        return m_ProgLang;
    }
    // bool operator<(const Employee& other)const{
    //     return m_Id  < other.m_Id;
    // }
};

void UserDefined() {
    std::vector<Employee> employees{
        Employee("Umar", 1, "C++"),
        Employee("Ali", 23, "Python"),
        Employee("Ursula", 4, "Java"),
        Employee("Robin", 11, "CSS")
    };
    //with this Mamda function it is not necessary to define the operator < for the class
    auto sortName = [](const auto & e1 , const auto &e2){
        return e1.GetName() < e2.GetName();
    };
    //when no operatr (<) is defined for the class Employee then the following algorithm will not work
    std::sort(employees.begin(), employees.end(), sortName);

    for(const auto& emp : employees)
        std::cout << "Employees list: " << emp.GetName() << " " << emp.GetId() << " " << emp.GetProgrammingLanguage() << std::endl;
}

struct EmpCompare{
    bool operator()(const Employee &e1, const Employee &e2)const{
        return e1.GetId() < e2.GetId();
    }
};

void Set(){
    std::set<Employee, EmpCompare>  employees{
        Employee("Hilde", 101, "C++"),
        Employee("Karls", 201, "Python"),
        Employee("Walter", 99, "HTML")
    };

    for(const auto &e : employees)
    {
        std::cout << "Employees ID: " << e.GetId() << " "
                    << "Name: " << e.GetName() << " "
                    << "Programming Language: " << e.GetProgrammingLanguage() << std::endl;
    }

}


int main(void)
{
    UserDefined();
    Set();
    return 1;
}