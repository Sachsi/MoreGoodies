#include <iostream>
#include "Pizza.h"
#include "ChicagoStyle.h"
#include "FactoryStyle.h"
#include "PizzaStore.h"
#include <string>



int main()
{
    std::cout << "Welcome to the Pizzeria!" << std::endl;
    
    // Future implementation will go here
    std::string pizzaType = "cheese"; // Example pizza type
    std::string pizzaPepperoni = "pepperoni";

    ChicagoStyle chicagoPizzaStore; // Create a Chicago style pizza store instance   
    FactoryMethod pizzaFactory; // Create a factory method instance
    
    
    pizzaFactory.OrderPizza(pizzaType);
    std::cout << "------------------------" << std::endl;
    chicagoPizzaStore.OrderPizza(pizzaPepperoni);
    return 0;
}