#pragma once
#include "PizzaStore.h"
#include "PizzaTypes/CheesePizza.h"
#include "PizzaTypes/PepperoniPizza.h"
#include "IngredientFactory/ChicagoPizzaIngredientFactory.h"
#include <iostream>

class ChicagoStyle : public PizzaStore {
        
    public:
        ChicagoStyle() {
            std::cout << "Welcome to Chicago Style Pizza Store!" << std::endl;
        }
        virtual ~ChicagoStyle(){
            std::cout << "Pizza order completed!" << std::endl;
        }
        Pizza* createPizza(std::string type)const override{
            Pizza *pizza;
        
            PizzaIngredientFactory* ingredientFactory = new ChicagoPizzaIngredientFactory(); // Assuming you have a ChicagoPizzaIngredientFactory class

            if(type == "cheese")
            {
                std::cout << "Preparing cheese pizza in ChicagoStyle..." << std::endl;
                pizza = new CheesePizza(*ingredientFactory);
                pizza->setName("Chicago Style Cheese Pizza");
            }
            else if(type == "pepperoni")
            {
                std::cout << "Preparing pepperoni pizza in ChicagoStyle..." << std::endl;
                pizza = new PepperoniPizza(*ingredientFactory);
                pizza->setName("Chicago Style Pepperoni Pizza");
            }
            else if(type == "veggie")
            {
                std::cout << "Preparing veggie pizza in ChicagoStyle..." << std::endl;
            }
            
            return pizza;
        }


};