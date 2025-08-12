#include <iostream>
#include "Pizza.h"
#include "ChicagoStyle.h"
#include "PizzaStore.h"
#include "NYStyle.h"
#include <string>



int main()
{
    std::cout << "Welcome to the Pizzeria!" << std::endl;
    
    // Future implementation will go here
    std::string pizzaType = "cheese"; // Example pizza type
    std::string pizzaPepperoni = "pepperoni";

    ChicagoStyle chicagoPizzaStore; // Create a Chicago style pizza store instance  
    chicagoPizzaStore.OrderPizza(pizzaType); // Order a cheese pizza from Chicago style store
    std::cout << "------------------------" << std::endl;
    NYStyle nyStyle; // Create a factory method instance
    nyStyle.OrderPizza(pizzaType);
    std::cout << "------------------------" << std::endl;
    // chicagoPizzaStore.OrderPizza(pizzaPepperoni);
    return 0;
}