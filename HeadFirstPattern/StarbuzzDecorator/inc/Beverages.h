/**
 * @file Beverages.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-06-24
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#pragma once
#include "IBeverage.h"

namespace StarrbuzzCoffee {

    class Espresso : public Beverage::Beverage {
        public:
            Espresso() {
                description = "Espresso"; // Set the description for espresso
            }
            double cost() const override {
                return 1.99; // Cost of Espresso
            }
    };

    class HouseBlend : public Beverage::Beverage {
        public:
            HouseBlend() {
                description = "House Blend Coffee"; // Set the description for House Blend
            }
            double cost() const override {
                return 0.89; // Cost of House Blend
            }
    };
}