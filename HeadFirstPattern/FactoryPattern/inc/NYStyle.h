#pragma once
#include "PizzaStore.h"
#include <iostream>

class NYStyle : public PizzaStore {
    public:
        virtual ~NYStyle(){
            std::cout << "Pizza order completed!" << std::endl;
        }
        Pizza createPizza(std::string type)const override{
            Pizza *pizza;
            if(type == "cheese")
            {
                std::cout << "Preparing cheese pizza in NYStyle..." << std::endl;
                *pizza = Pizza();
            }
            else if(type == "pepperoni")
            {
                std::cout << "Preparing pepperoni pizza in NYStyle..." << std::endl;
                *pizza = Pizza();
            }
            else if(type == "veggie")
            {
                std::cout << "Preparing veggie pizza in NYStyle..." << std::endl;
                *pizza = Pizza();
            }
            
            return *pizza;
        }


};