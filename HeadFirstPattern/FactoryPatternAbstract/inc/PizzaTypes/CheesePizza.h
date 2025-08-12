#pragma once
#include "../Pizza.h"
#include "../IngredientFactory/PizzaIngredientFactory.h"

#include <iostream>

class CheesePizza : public Pizza {
    protected:
        PizzaIngredientFactory* ingredientsFactory;
    public:
        CheesePizza(PizzaIngredientFactory& factory) : ingredientsFactory(&factory){            
        }
        void prepare() override {
            dough = ingredientsFactory->createDough();
            souce = ingredientsFactory->createSauce();
            cheese = ingredientsFactory->createCheese();
            //toppings = ingredientsFactory->createToppings();
        }

        void cut() override {
            std::cout << "Cutting the pizza into square slices" << std::endl;
        }

};