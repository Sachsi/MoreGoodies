#pragma once
#include "iostream"
//abstract class can not be instantiated but used by pointers or references
namespace Duck::Base
{
    class Duck
    {
    protected:
        std::string name;
    public:

        virtual void quack() const{ //no Pure virtual function
            std::cout << "Duck quacks! ";
        }
        virtual void swim() const { //no Pure virtaul function
            std::cout << "Duck swims! "; 
        }
        virtual void fly() const { // no pure virtual function
            std::cout << "Duck flies! ";
        }
        virtual void display() const {
            std::cout << "Duck is displayed! ";
        }
    };
}


