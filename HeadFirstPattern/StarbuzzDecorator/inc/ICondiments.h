/**
 * @file contiments.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-06-22
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#pragma once
#include <iostream>
#include "IBeverage.h"


class CondimentDecorator : public Beverage
{
    public:
        Beverage *beverage2; // Pointer to the beverage being decorated
    public:
        virtual ~CondimentDecorator() = default;
        virtual std::string getDescribtion() const = 0; // Pure virtual function to get description
};

