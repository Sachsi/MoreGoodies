#pragma once
#include "iostream"
//abstract class can not be instantiated but used by pointers or references
namespace Duck::Base
{
    class Duck
    {
    public:

        virtual void quack() const{ //no Pure virtual function
            std::cout << "Duck quacks!" << std::endl;
        }
        virtual void swin() const { //no Pure virtaul function
            std::cout << "Duck swims!" << std::endl; 
        }
        virtual void fly() const { // no pure virtual function
            std::cout << "Duck flies!" << std::endl;
        }
    };
}