#include "IFly.h"

void FlyWithWings::fly() const
{
    std::cout << "Flying with wings!" << std::endl;
}

void FlyNoWings::fly() const
{
    std::cout << "Cannot fly, no wings!" << std::endl;
}