#include <iostream>
#pragma once

class IFly
{
public:
    virtual void fly() const = 0; // Pure virtual fucntion
};

class FlyWithWings : public IFly
{
private:
    /* data */
public:
    void fly() const override;
};

class FlyNoWings : public IFly
{
private:
    /* data */
public:
    void fly() const override;
};