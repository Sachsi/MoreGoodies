#pragma once
#include "../Pizza.h"
#include "../IngredientFactory/PizzaIngredientFactory.h"

#include <iostream>

class CheesePizza : public Pizza {
    protected:
        PizzaIngredientFactory* ingredientsFactory;
    public:
        CheesePizza(PizzaIngredientFactory* factory) {
            ingredientsFactory = factory;            
        }

        void prepare() override {
            std::cout << "Preparing " + name  << std::endl;
            *dough = ingredientsFactory->createDough();

        }

};