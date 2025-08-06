#pragma once
#include "PizzaStore.h"
#include "ChicagoStyleCheesePizza.h"
#include "ChicagoStylePepperoniPizza.h"
#include <iostream>

class ChicagoStyle : public PizzaStore {
    public:
        virtual ~ChicagoStyle(){
            std::cout << "Pizza order completed!" << std::endl;
        }
        Pizza* createPizza(std::string type)const override{
            Pizza *pizza;
            if(type == "cheese")
            {
                std::cout << "Preparing cheese pizza in ChicagoStyle..." << std::endl;
                pizza = dynamic_cast<Pizza*>(new ChicagoStyleCheesePizza);
            }
            else if(type == "pepperoni")
            {
                std::cout << "Preparing pepperoni pizza in ChicagoStyle..." << std::endl;
                pizza = dynamic_cast<Pizza*>(new ChicagoStylePepperoniPizza);
            }
            else if(type == "veggie")
            {
                std::cout << "Preparing veggie pizza in ChicagoStyle..." << std::endl;
            }
            
            return pizza;
        }


};