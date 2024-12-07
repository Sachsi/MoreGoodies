#include "Integer.h"
#include <iostream>

Integer::Integer()
{
    std::cout << "Integer()" << std::endl;
    m_pInt = new int(0);
}

Integer::Integer(int value)
{
    std::cout << "Integer(int)" << std::endl;
    m_pInt = new int(value);
}

Integer::Integer(const Integer &obj)
{
    std::cout << "Integer(const Integer&)" << std::endl;
    m_pInt = new int(*obj.m_pInt);
}

Integer::Integer(Integer &&obj)
{
    std::cout << "Integer(Integer&&)" << std::endl;
    m_pInt = obj.m_pInt;
    obj.m_pInt = nullptr;
}

Integer::~Integer()
{
    std::cout << "~Integer()" << std::endl;
    delete m_pInt;
}

int Integer::GetValue(void) const{
    return *m_pInt;
}


void Integer::SetValue(int value) {
    *m_pInt = value;
}

Integer Integer::operator+(const Integer& obj)
{
    Integer temp;
    temp.SetValue(obj.GetValue() + *m_pInt);
    return temp;
}

Integer& Integer::operator=(Integer &&obj)
{
    std::cout << "Integer::operator=(Integer&&)" << std::endl;
    if(this != &obj)
    {
        delete m_pInt;
        m_pInt = obj.m_pInt;
        obj.m_pInt = nullptr;
    }
    return *this;
}