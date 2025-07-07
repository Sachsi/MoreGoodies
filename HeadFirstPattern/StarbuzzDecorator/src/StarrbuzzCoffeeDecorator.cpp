#include <iostream>
#include "Condiment.h"
#include "Beverages.h"
#include <memory>

int main() {

    Espresso espresso = Espresso();
    std::cout << espresso.getDescribtion() << " " << espresso.cost() << std::endl;

    //Latte
    HouseBlend houseBlend = HouseBlend();
    Mocha mocha = Mocha(&houseBlend);
    Soy soy = Soy(&mocha);
    Whip whip = Whip(&soy);
    

    std::cout << whip.getDescribtion() << " " << whip.cost() << std::endl;

    //Flat White
    
}

