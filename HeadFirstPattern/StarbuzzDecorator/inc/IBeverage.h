#pragma once
#include <iostream>

enum class Size{
            TALL,
            GRANDE,
            VENTI
};

class Beverage
{
    protected:
        Size size = Size::TALL; // Default size        
        std::string description = "Unknwon Beverage";
    public:
        virtual ~Beverage() = default;
        virtual double cost() const = 0; // Pure virtual function
        virtual std::string getDescribtion() const{
            return description;
        }
        void setSize(Size size) {
            this->size = size;
            description += ", ";
            switch (size) {
                case Size::TALL:
                    description += "(TALL)";
                    break;
                case Size::GRANDE:
                    description += "(GRANDE)";
                    break;
                case Size::VENTI:
                    description += "(VENTI)";
                    break;
            }
        }
        virtual Size getSize(void) const {
            return this->size;
        }
        
};