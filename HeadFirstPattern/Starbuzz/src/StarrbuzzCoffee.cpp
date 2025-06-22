#include <iostream>
#include "StarrbuzzCoffee.h"
#include "Beverage.h"

namespace StarrbuzzCoffee {

    StarrbuzzCoffee::HouseBlend::HouseBlend(){
        description = "House Blend Coffee"; // Set the description for House Blend Coffee
    }
    StarrbuzzCoffee::HouseBlend::~HouseBlend()
    {
        std::cout << "HouseBlend Coffee is finished." << std::endl; // Override destructor for proper cleanup
    }
    
    double StarrbuzzCoffee::HouseBlend::cost() const
    {
        double totalCost = 0.00;
        double baseCost = 0.89; // Base cost for House Beverage
        totalCost = baseCost + Beverage::cost(); // Add the cost of condiments from the base class
        std::cout << getDescription() << " cost is: " << totalCost << std::endl;
        
        return totalCost;
    }


    

} // namespace StartbuzzCoffee

int main() {

    StarrbuzzCoffee::HouseBlend houseBlend;
    StarrbuzzCoffee::HouseBlend houseBlendWhite;
    houseBlend.setMilk(); // Set milk to false for the House Blend Coffee
    houseBlendWhite.setMilk(); // Set milk to true for the House Blend White Coffee
    houseBlendWhite.getDescription();
    
    houseBlendWhite.cost();
    houseBlend.cost();
    return 1;
}

