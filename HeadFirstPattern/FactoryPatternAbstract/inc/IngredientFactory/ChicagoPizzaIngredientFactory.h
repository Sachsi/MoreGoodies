#pragma once
#include <iostream>
#include "PizzaIngredientFactory.h"
#include "Ingredients.h"

class ChicagoPizzaIngredientFactory : public PizzaIngredientFactory {

    public:

        std::string createDough() const {
            auto temp = ThickCrustDough(); 
            return temp.ThickCrustDoughIn();
        }

        std::string createSauce() const override {
            auto temp = ChilliSauce();
            return temp.ChilliSauceIn();
        }

        std::string createCheese() const override{
            auto temp = CremeCheese();
            return temp.CremeCheeseIn();
        }

        std::list<std::string> createVeggeis() const override {
            auto temp = RedPepper();
            std::list<std::string> veggies;
            veggies.push_back(temp.RedPepperIn());
            return  veggies;
        }

        std::string createPepperoni() const override {
            auto temp = RedPepper();
            return temp.RedPepperIn();
        }

        std::string createClam() const override{
            auto temp = Clams();
            return temp.ClamsIn();
        }


};
