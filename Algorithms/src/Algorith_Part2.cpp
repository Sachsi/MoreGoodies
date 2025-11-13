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

struct EmpIds{
    std::vector<int> m_Ids;
    void operator()(const Employee &emp){
        if(emp.GetProgrammingLanguage() == "C++")
            m_Ids.push_back(emp.GetId());
    }
};


void UserDefined() {
    std::vector<Employee> employees{
        Employee("Umar", 1, "C++"),
        Employee("Ali", 23, "Python"),
        Employee("Ursula", 4, "Java"),
        Employee("Robin", 11, "C++")
    };
    //with this Mamda function it is not necessary to define the operator < for the class
    auto sortName = [](const auto & e1 , const auto &e2){
        return e1.GetName() < e2.GetName();
    };
    //when no operatr (<) is defined for the class Employee then the following algorithm will not work
    std::sort(employees.begin(), employees.end(), sortName);

    for(const auto& emp : employees)
        std::cout << "Employees list: " << emp.GetName() << " " << emp.GetId() << " " << emp.GetProgrammingLanguage() << std::endl;

    //avoid hand written for loop, use std.. for eeach loop or counters
    int cppCount{};
    //---this hand written loop is difficult to read and takes many lines
    // for(const auto &e : employees){
    //     if(e.GetProgrammingLanguage() == "C++")
    //         ++cppCount;
    // }
    
    //---use std::count_if or other function where you can use Lambda function
    //---with using the callbacks, makes you more flexible and easy to read
    cppCount = std::count_if(employees.begin(), employees.end(), [](const auto &e){
        return e.GetProgrammingLanguage() == "C++";});
    std::cout << "Number of C++ programmer: " << cppCount << std::endl;
    
    auto a = std::find_if(employees.begin(), employees.end(), [](const auto &e){
        return e.GetProgrammingLanguage() == "Java";
    });
    
    if(a != employees.end())
        std::cout << "Find: " << a->GetName() << " is a Java programmer" << std::endl;
    
    std::for_each(employees.begin(), employees.end(), [](const auto &e){
        std::cout << "Employee: " << e.GetName() << " " << e.GetId() << " " << e.GetProgrammingLanguage() << std::endl;
    });
    //this functionaliety is just posible with function objects, not with function pointers
    auto emplyIds = std::for_each(employees.begin(), employees.end(), EmpIds());
    for(int &id : emplyIds.m_Ids)
        std::cout << "C++ programmer ID: " << id << std::endl;
}

int main(void)
{
    UserDefined();
    return 1;
}