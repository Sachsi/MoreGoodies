#pragma once
#include <iostream>

namespace Observer
{
    class Observer{
        public:
            //Pure virtual function for requesting for new data
            virtual void update() = 0;
    };
}