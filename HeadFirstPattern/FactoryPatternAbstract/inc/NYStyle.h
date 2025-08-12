#pragma once
#include "PizzaStore.h"
#include "PizzaTypes/CheesePizza.h"
#include "IngredientFactory/NYPizzaIngredientFactory.h"
#include <iostream>

class NYStyle : public PizzaStore {
    public:
        NYStyle() {
            std::cout << "Welcome to NY Style Pizza Store!" << std::endl;
        }
        virtual ~NYStyle(){
            std::cout << "Pizza order completed!" << std::endl;
        }
        Pizza* createPizza(std::string type)const override{
            
            Pizza* pizza;
            PizzaIngredientFactory* ingredientFactory = new NYPizzaIngredientFactory(); // Assuming you have a NYPizzaIngredientFactory class

            if(type == "cheese")
            {
                std::cout << "Preparing cheese pizza in NYStyle..." << std::endl;
                pizza = new CheesePizza(*ingredientFactory);
            }
            else if(type == "pepperoni")
            {
                std::cout << "Preparing pepperoni pizza in NYStyle..." << std::endl;
            }
            else if(type == "veggie")
            {
                std::cout << "Preparing veggie pizza in NYStyle..." << std::endl;
            }
            
            return pizza;
        }


};