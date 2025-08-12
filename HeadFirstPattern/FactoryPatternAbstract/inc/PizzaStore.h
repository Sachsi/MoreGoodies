#pragma once
#include <iostream>
#include "Pizza.h"

class PizzaStore{

    protected:
        virtual Pizza* createPizza(std::string type) const = 0;
    public:
        PizzaStore() {
            std::cout << "Pizza Store is open!" << std::endl;
        }
        virtual ~PizzaStore(){
            std::cout << "Pizza Store is closing!" << std::endl;
        }
        
        Pizza* OrderPizza(std::string type)
        {
            Pizza* pizza;

            pizza = createPizza(type);
            
            pizza->prepare();
            pizza->bake();
            pizza->cut();
            pizza->box();
            std::cout << pizza->toString() << std::endl;;
            return pizza;
        }

};