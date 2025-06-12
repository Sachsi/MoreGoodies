#include <iostream>
#pragma once

class IQuack
{
    public:
        virtual void quack() const = 0; //pure virtual function

};

class Quack : public IQuack{
    public:
        void quack() const override;
};

class Squeack : public IQuack{
    public:
        void quack() const override;
};
class MuteQuack : public IQuack{
    public:
        void quack() const override;
};
