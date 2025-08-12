#pragma once
#include <iostream>
#include <string>
#include <list>
#include "IngredientFactory/Ingredients.h"

class Pizza {
    protected:
        std::string name;
        std::string dough;
        std::string souce;
        std::string cheese;
        std::list<std::string> toppings{};
    public:
        virtual void prepare() = 0;
        
        virtual void bake() {
            std::cout << "Bakeing pizza for 25 minutes at 350 " << std::endl;
        }
        virtual void cut() {
            std::cout << "Cutting pizza into diagonal slices" << std::endl;
        }
        virtual void box() {
            std::cout << "Boxing pizza in official PizzaStore box" << std::endl;
        }

        void setName(const std::string& pizzaName) {
            this->name = pizzaName;
        }

        std::string getName() const {
            return this->name;
        }

        std::string toString() const {
            std::string result = "Pizza: " + name + "\nDough: " + dough + "\nSauce: " + souce + "\nCheese: " + cheese;
            if (!toppings.empty()) {
                result += "\nToppings: ";
                for (const auto& topping : toppings) {
                    result += topping + ", ";
                }
                result.pop_back(); // Remove last comma
                result.pop_back(); // Remove last space
            }
            return result;
        }

};