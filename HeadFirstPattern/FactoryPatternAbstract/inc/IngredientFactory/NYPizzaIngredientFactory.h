#pragma once
#include <iostream>
#include "PizzaIngredientFactory.h"
#include "Ingredients.h"

class NYPizzaIngredientFactory : public PizzaIngredientFactory {

    public:


        std::string createDough() const {
            auto temp = ThinCrustDough(); 
            return temp.ThinCrustDoughIn();
        }

        std::string createSauce() const override {
            auto temp = MarinaraSauce();
            return temp.MarinaraSauceIn();
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
            auto temp = Pepperoni();
            return temp.PepperoniIn();
        }

        std::string createClam() const override{
            auto temp = Clams();
            return temp.ClamsIn();
        }
};
