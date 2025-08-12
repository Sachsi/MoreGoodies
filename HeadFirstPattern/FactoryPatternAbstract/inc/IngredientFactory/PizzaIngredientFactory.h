#pragma once
#include <iostream>
#include "../Pizza.h"

class PizzaIngredientFactory
{
private:
    /* data */
public:
    virtual std::string createDough() const = 0;
    virtual std::string createSauce() const = 0;
    virtual std::string createCheese() const = 0;
    virtual std::list<std::string> createVeggeis() const = 0;
    virtual std::string createPepperoni() const = 0;
    virtual std::string createClam() const = 0;
};
