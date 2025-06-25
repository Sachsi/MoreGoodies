#pragma once
#include <iostream>


namespace Beverage
{
    class Beverage
    {
        protected:
            std::string description = "Unknwon Beverage";
        public:
            virtual ~Beverage() = default;
            virtual std::string getDescribtion() const{
                return description;
            }
            virtual double cost() const = 0; // Pure virtual function
    };
}   