#pragma once
#include <iostream>
#include "Pizza.h"
#include "Ingredients.h"

class PizzaIngredientFactory
{
private:
    /* data */
public:
    virtual ~PizzaIngredientFactory();

    Dough createDough() const;
    Sauce createSauce() const;
    Cheese createCheese() const ;
    std::list<Veggies> createVeggeis() const;
    Pepperoni createPepperoni() const;
    Clams createClam() const;
};
