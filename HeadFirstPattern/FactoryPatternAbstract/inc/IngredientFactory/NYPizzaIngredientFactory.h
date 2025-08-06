#pragma once
#include <iostream>
#include "PizzaIngredientFactory.h"
#include "Ingredients.h"

class NYPizzaIngredientFactory : public PizzaIngredientFactory {

    public:
        virtual ~NYPizzaIngredientFactory() {
            std::cout << "NY Pizza Ingredient Factory destroyed!" << std::endl;
        }

        Dough createDough() const {
            return ThickCrustDough();
        }

        Sauce createSauce() const {
            return MarinaraSauce();
        }

        Cheese createCheese() const {
            return NewYorkerCheese();
        }

        std::list<Veggies> createVeggeis() const {
            return { RedPepper(), Pepperoni()};
        }


        Clams createClam() const {
            return Clams();
        }


};
