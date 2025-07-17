#pragma once
#include <iostream>
#include <string>
#include <list>

class Pizza {
    protected:
        std::string name;
        std::string dough;
        std::string souce;
        std::list<std::string> toppings{};
    public:
        virtual void prepare() {
            std::cout << "Preparing " + name << std::endl;
            std::cout << "Tossing dough... " << std::endl;
            std::cout << "Adding sauce.. " << std::endl;
            std::cout << "Adding toppings:... " << std::endl;
            for (auto topping :  toppings){
                std::cout << "   " + topping << std::ends;
            }            
            std::cout << std::endl;
        }
        virtual void bake() {
            std::cout << "Bakeing pizza for 25 minutes at 350 " << std::endl;
        }
        virtual void cut() {
            std::cout << "Cutting pizza into diagonal slices" << std::endl;
        }
        virtual void box() {
            std::cout << "Boxing pizza in official PizzaStore box" << std::endl;
        }

};