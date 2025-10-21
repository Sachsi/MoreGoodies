#include <iostream>
#pragma once


namespace Duck::Fly 
{
    class IFly
    {
        public:
            virtual void fly() const = 0; // pure virtual function
    };
}