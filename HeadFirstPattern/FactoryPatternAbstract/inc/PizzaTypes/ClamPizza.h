#pragma once
#include "../Pizza.h"
#include "../IngredientFactory/PizzaIngredientFactory.h"
#include <iostream>

class ClamPizza : public Pizza {
    protected:
        PizzaIngredientFactory* ingredientsFactory;
    public:
        ClamPizza(PizzaIngredientFactory& factory) {
            ingredientsFactory = &factory;
        }

        void prepare() override {
            std::cout << "Preparing " + name  << std::endl;
            dough = ingredientsFactory->createDough();
        }

        void cut() override {
            std::cout << "Cutting the pizza into square slices" << std::endl;
        }

};