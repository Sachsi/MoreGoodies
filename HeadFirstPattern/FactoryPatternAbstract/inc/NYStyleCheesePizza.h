#pragma once
#include "Pizza.h"
#include <iostream>

class NYStyleCheesePizza : public Pizza {
    public:
        NYStyleCheesePizza() {
            name = "NY Style Cheese Pizza";
            dough = "Thin Crust Dough";
            souce = "Marinara Souce";

            toppings.push_back("Grated Reggiano Cheese");
        }

};