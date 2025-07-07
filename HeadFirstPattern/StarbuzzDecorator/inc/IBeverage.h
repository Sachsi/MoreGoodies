#pragma once
#include <iostream>

class Beverage
{
    protected:
        std::string description = "Unknwon Beverage";
    public:
        virtual ~Beverage() = default;
        std::string getDescribtion() const{
            return description;
        }
        virtual double cost() const = 0; // Pure virtual function
};