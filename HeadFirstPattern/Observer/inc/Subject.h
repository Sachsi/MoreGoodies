#pragma once
#include <iostream>
#include "Observer.h"

class Subject //: public Observer
{
private:
    /* data */
public:
    virtual void registerObserver(Observer* obs) = 0;
    virtual void removeObserver(Observer* obs) = 0;
    virtual void notifyObservers() = 0;
};


