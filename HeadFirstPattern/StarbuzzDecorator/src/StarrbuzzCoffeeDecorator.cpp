#include <iostream>
#include "Condiment.h"
#include "Beverages.h"
#include <memory>

int main() {

    Espresso espresso = Espresso();
    std::cout << espresso.getDescribtion() << " " << espresso.cost() << std::endl;

    //Latte
    HouseBlend houseBlend = HouseBlend();

    houseBlend.setSize(Size::GRANDE);
    Mocha mocha = Mocha(&houseBlend);
    Soy soy = Soy(&mocha);

    std::cout << soy.getDescribtion() << " " << soy.cost() << std::endl;

    //Flat White TALL
    HouseBlend houseBlend2 = HouseBlend();;
    houseBlend2.setSize(Size::TALL);
    Mocha mocha2 = Mocha(&houseBlend2);
    Soy soy2 = Soy(&mocha2);
    
    std::cout << soy2.getDescribtion() << " " << soy2.cost() << std::endl;
    
}

