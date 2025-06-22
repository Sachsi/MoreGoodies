#pragma once
#include "Beverage.h"
#include <iostream>

namespace StarrbuzzCoffee {

    class HouseBlend : public Beverage::Beverage {
        public:
            HouseBlend();
            double cost() const override;
            ~HouseBlend() override;
    };

} // namespace StartbuzzCoffee