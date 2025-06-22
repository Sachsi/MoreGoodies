#include "Beverage.h"

namespace Beverage
{
    std::string Beverage::getDescription() const
    {
        return description; // Return the description of the beverage
    }

    double Beverage::cost() const
    {
        double condimentCost = 0.00; // Base cost for the beverage
        if (hasMilk() == true)
        {
            condimentCost += 0.10; // Cost for milk
        }
        if(hasSoy())
        {
            condimentCost += 0.15; // Cost for soy
        }
        if (hasMocha())
        {
            condimentCost += 0.20; // Cost for mocha
        }
        if (hasShip())
        {
            condimentCost += 0.25; // Cost for ship
        }
        
        return condimentCost; // Return the total cost
    }

}