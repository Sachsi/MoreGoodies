#include <iostream>
#include "Condiment.h"
#include "Beverages.h"
#include <memory>

int main() {

    StarrbuzzCoffee::Espresso espresso = StarrbuzzCoffee::Espresso();
    std::cout << espresso.getDescribtion() << " " << espresso.cost() << std::endl;

    //Latte
    StarrbuzzCoffee::HouseBlend houseBlend = StarrbuzzCoffee::HouseBlend();
    std::cout << houseBlend.getDescribtion() << " " << houseBlend.cost() << std::endl;
}

