#pragma once
#include "Pizza.h"
#include <iostream>

class ChicagoStyleCheesePizza : public Pizza {
    public:
        ChicagoStyleCheesePizza() {
            name = "Chicago Style Cheese Pizza";
            dough = "Extra thick Crust Dough";
            souce = "Plum Tomato Souce";

            toppings.push_back("Grated Reggiano Cheese");
            toppings.push_back("Spicy Sauce");
        }

        void cut() override {
            std::cout << "Cutting the pizza into square slices" << std::endl;
        }

};