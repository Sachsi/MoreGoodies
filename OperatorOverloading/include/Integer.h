#pragma once
#include <iostream>
#include <optional>

class Integer
{
    private:
        int* m_pInt;
    public:
        struct IntegerProporties
        {
            int value;
            std::optional<float> siz;
            IntegerProporties(int Value, float b) : value(Value), siz(b)
            {
                std::cout << "IntProp(int, float)" << std::endl;
            }
            IntegerProporties(){
                std::cout << "IntProp()" << std::endl;
            };
        };
        
        //Constructor
        Integer();
        //Destrator;
        ~Integer();
        //Parameter Constractor
        Integer(int value);
        //Copy Constructor
        Integer(const Integer &obj);
        //Move Constractor
        Integer(Integer &&obj);
        int GetValue(void) const;
        void SetValue(int value);
        //Move Assigment()
        Integer& operator=(Integer &&obj);

        Integer operator+(const Integer& obj);  

        IntegerProporties IntProp;
        IntegerProporties *pIntProp = nullptr;
};