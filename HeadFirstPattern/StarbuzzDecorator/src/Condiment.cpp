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
    return this->beverage2->cost() + 0.20; // Add the cost of Mocha;
}


Soy::Soy(Beverage *bev)
{
    this->beverage2 = bev; // Initialize the beverage being devorated
}
std::string Soy::getDescribtion() const
{
    return beverage2->getDescribtion() + ", Soy"; // Append Soy to the beverage description;
}
double Soy::cost() const
{
    return this->beverage2->cost() + 0.15; // Add the cost of Soy;
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
    return this->beverage2->cost() + 0.10; // Add the cost of Whip;
}
