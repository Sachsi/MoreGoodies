#pragma once
#include "PizzaStore.h"
#include <iostream>

class FactoryMethod : public PizzaStore{
    public:
        virtual ~FactoryMethod(){
            std::cout << "Pizza order completed!" << std::endl;
        }
        Pizza* createPizza(std::string type) const override{
            Pizza *pizza;
            if(type == "cheese")
            {
                std::cout << "Preparing cheese pizza in FactoryStyle..." << std::endl;
            }
            else if(type == "pepperoni")
            {
                std::cout << "Preparing pepperoni pizza in FactoryStyle..." << std::endl;
            }
            else if(type == "veggie")
            {
                std::cout << "Preparing veggie pizza in FactoryStyle..." << std::endl;
            }
            
            return pizza;
        }


};