#pragma once
#include <iostream>
#include "Pizza.h"

class PizzaStore{

    public:

        virtual ~PizzaStore(){
            std::cout << "Pizza Store is closing!" << std::endl;
        }
        virtual Pizza createPizza(std::string type) const = 0;

        Pizza OrderPizza(std::string type)
        {
            Pizza pizza;

            pizza = createPizza(type);
            
            pizza.prepare();
            pizza.bake();
            pizza.cut();
            pizza.box();

            return pizza;
        }

};