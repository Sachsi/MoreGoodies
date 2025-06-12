#pragma once
#include <iostream>

class Observer{
    public:
        virtual void update(float temp, float hum, float pres) = 0;
};