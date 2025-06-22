#pragma once
#include <iostream>


namespace Beverage
{
    class Beverage
    {
    protected:
        std::string description = "Unknwon Beverage" ; // Default description
        bool milk = false; // flag for milk
        bool soy = false; // flag for soy
        bool mocha = false; // flag for mocha
        bool ship = false; // flag for ship

    public:
        virtual ~Beverage() = default; // Virtual destructor for proper cleanup
        virtual std::string getDescription() const; // Pure virtual function for getting description
        virtual double cost() const; // Pure virtual function for calculating cost
        virtual void setMilk(void) { this->milk = true; } // Set milk flag
        virtual void setSoy(void) { this->soy = true; } // Set soy flag
        virtual void setMocha(void) { this->mocha = true; } // Set mocha flag
        virtual void setShip(void) { this->ship = true; } // Set ship flag
        virtual bool hasMilk() const { return milk; } // Check if milk is added
        virtual bool hasSoy() const { return soy; } // Check if soy is added
        virtual bool hasMocha() const { return mocha; } // Check if mocha is added
        virtual bool hasShip() const { return ship; } // Check if ship is added
    };
}   