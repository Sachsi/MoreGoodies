/**
 * @file Condiment.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-06-24
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#pragma once
#include "ICondiments.h"

namespace StarrbuzzCoffee {

    class Mocha : public Condiments::CondimentDecorator {
        public:
            Mocha(Beverage *bev);
            std::string getDescribtion() const override;
            double cost() const override;
    };

    class Soy : public Condiments::CondimentDecorator {
        public:
            Soy(Beverage* bev);
            std::string getDescribtion() const override;
            double cost() const override;
    };

    class Whip : public Condiments::CondimentDecorator {
        public:
            Whip(Beverage* bev);
            std::string getDescribtion() const override;
            double cost() const override;
    };

}