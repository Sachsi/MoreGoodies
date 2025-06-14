#pragma once
#include <iostream>

class Observer{
    public:
        //Pure virtual function for requesting for new data
        virtual void update() = 0;
};