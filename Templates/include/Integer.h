#pragma once
#include <iostream>

class Integer
{
	private:
		int* m_pInt;
	public:
	//Constroctor
		Integer();
	// Parameter Constractoor
		Integer(int value);
	// Copy Constractor
		Integer(const Integer &obj);
	 //Move Constractor
		Integer(Integer &&obj);
	 //Move Assignment
		Integer & operator=(Integer &&obj);
		~Integer();
		void SetValue(int value);
		int GetValue(void) const;
	    Integer operator+(const Integer &a)const;
		Integer & operator++();
		Integer operator++(int);
		bool operator==(const Integer &obj)const;
		// Copy Assignment 
		Integer & operator=(const Integer &obj);
		// function call operator
		void operator()();
		//
		
		//global operator with direct access of member 
		friend std::istream & operator>>(std::istream & input, Integer &a);
		
};
std::ostream & operator <<(std::ostream & out, const Integer &obj);