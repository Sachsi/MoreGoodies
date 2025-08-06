#pragma once
#include <iostream>
#include <string>
#include <list>
#include "IngredientFactory/Ingredients.h"

class Pizza {
    protected:
        std::string name;
        Dough dough;
        Sauce souce;
        std::list<Veggies> toppings{};
    public:
        virtual void prepare() = 0;
        
        virtual void bake() {
            std::cout << "Bakeing pizza for 25 minutes at 350 " << std::endl;
        }
        virtual void cut() {
            std::cout << "Cutting pizza into diagonal slices" << std::endl;
        }
        virtual void box() {
            std::cout << "Boxing pizza in official PizzaStore box" << std::endl;
        }

};