#pragma once
#include "../Pizza.h"
#include "../IngredientFactory/PizzaIngredientFactory.h"
#include <iostream>

class PepperoniPizza : public Pizza {
    protected:
        PizzaIngredientFactory* ingredientsFactory;    
    public:
        PepperoniPizza(PizzaIngredientFactory& factory) {
             ingredientsFactory = &factory;
        }

        void prepare() override {
            std::cout << "Preparing " + name << std::endl;
        }
        void cut() override {
            std::cout << "Cutting the pizza into square slices" << std::endl;
        }

};