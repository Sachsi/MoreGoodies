#include "Condiment.h"


Mocha::Mocha(Beverage *bev)
{
    this->beverage2 = bev; // Initialize the beverage being devorated
}
std::string Mocha::getDescribtion() const
{
    return this->beverage2->getDescribtion() + ", Mocha"; // Append Mocha to the beverage description;
}
double Mocha::cost() const
{
    double cost = 0.0;
    if(beverage2->getSize() == Size::TALL)
    {
        cost = 0.20; // Cost for TALL size
    }
    else if(beverage2->getSize() == Size::GRANDE)
    {
        cost = 0.15; // Cost for GRANDE size
    }
    else if(beverage2->getSize() == Size::VENTI)
    {
        cost = 0.10; // Cost for VENTI size
    }
    return this->beverage2->cost() + cost; // Add the cost of Mocha;
}


Soy::Soy(Beverage *bev)
{
    this->beverage2 = bev; // Initialize the beverage being devorated
}
std::string Soy::getDescribtion() const
{
    return this->beverage2->getDescribtion() + ", Soy"; // Append Soy to the beverage description;
}
double Soy::cost() const
{
    double cost = 0.0;
    if(beverage2->getSize() == Size::TALL)
    {
        cost = 0.20; // Cost for TALL size
    }
    else if(beverage2->getSize() == Size::GRANDE)
    {
        cost = 0.15; // Cost for GRANDE size
    }
    else if(beverage2->getSize() == Size::VENTI)
    {
        cost = 0.10; // Cost for VENTI size
    }    
    return beverage2->cost() + cost; // Add the cost of Soy;
}

Whip::Whip(Beverage *bev) 
{
    this->beverage2 = bev; // Initialize the beverage being devorated
}
std::string Whip::getDescribtion() const
{
    return beverage2->getDescribtion() + ", Whip"; // Append Whip to the beverage description;
}
double Whip::cost() const
{
    double cost = 0.0;
    if(beverage2->getSize() == Size::TALL)
    {
        cost == 0.20; // Cost for TALL size
    }
    else if(beverage2->getSize() == Size::GRANDE)
    {
        cost = 0.15; // Cost for GRANDE size
    }
    else if(beverage2->getSize() == Size::VENTI)
    {
        cost = 0.10; // Cost for VENTI size
    }
    return this->beverage2->cost() + cost; // Add the cost of Whip;
}
