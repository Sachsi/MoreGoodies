#pragma once
#include <iostream>
#include "PizzaIngredientFactory.h"
#include "Ingredients.h"

class ChicagoPizzaIngredientFactory : public PizzaIngredientFactory {

    public:
        virtual ~ChicagoPizzaIngredientFactory() {
            std::cout << "NY Pizza Ingredient Factory destroyed!" << std::endl;
        }

        Dough createDough() const {
            return ThinCrustDough();
        }

        Sauce createSauce() const {
            return ChilliSauce();
        }

        Cheese createCheese() const {
            return CremeCheese();
        }

        std::list<Veggies> createVeggeis() const {
            return { RedPepper(), Pepperoni()};
        }


        Clams createClam() const {
            return Clams();
        }


};
