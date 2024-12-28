#include "Integer.h"
#include <iostream>

Integer::Integer()
{
	std::cout << "Integer()" << std::endl;
	m_pInt = new int(0);
}
Integer::Integer(const Integer &obj)
{
	std::cout << "Integer(const Integer&)" << std::endl;
	m_pInt = new int(*obj.m_pInt);
}

Integer::Integer(int value)
{
	std::cout << "Integer(Int)" << std::endl;
	m_pInt = new int(value);
}
//Move Constractor 
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

Integer & Integer::operator=(const Integer &obj)
{
		std::cout << "Integer::operator=(const Integer&)" << std::endl;
	if(this != &obj)
	{
		delete m_pInt; 
		m_pInt = new int(*obj.m_pInt);
	}
	return *this;
}
//Move Assignment 
Integer & Integer::operator=(Integer &&obj)
{
		std::cout << "Integer::operator=( Integer&&)" << std::endl;
	if(this != &obj)
	{
		delete m_pInt; 
		m_pInt = obj.m_pInt;
		obj.m_pInt = nullptr;
	}
	return *this;
}

void Integer::SetValue(int value)
{
	if(m_pInt == nullptr)
		m_pInt = new int{};
	*m_pInt = value;
}

int Integer::GetValue(void) const
{
	//if(m_pInt)
	{
		return *m_pInt;
	}
}

Integer Integer::operator+(const Integer &a)const
{
	Integer temp;
	*temp.m_pInt = *m_pInt + *a.m_pInt;
	return temp;
}

Integer & Integer::operator++()
{
	++(*m_pInt);
	return *this;
}

Integer Integer::operator++(int)
{
	Integer temp(*this);
	++(*m_pInt);
	return temp;
}

bool Integer::operator==(const Integer &obj)const
{
	return *m_pInt == *obj.m_pInt;
}
// function call operator 
void Integer::operator()()
{
	std::cout << *m_pInt << std::endl;
}

//
std::ostream & operator<<(std::ostream& out, const Integer &obj)
{
	out << obj.GetValue();
	return  out;
}