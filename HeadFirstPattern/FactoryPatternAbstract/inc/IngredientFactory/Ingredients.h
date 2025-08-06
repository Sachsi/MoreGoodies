#pragma once
#include <iostream>

class Dough
{
    public:
    virtual ~Dough(){};
};

class ThickCrustDough : public Dough
{
private:
    /* data */
public:
    ThickCrustDough(){
        std::cout << "add ThickCrustDough" << std::endl;
    }
    ~ThickCrustDough();
};

class ThinCrustDough : public Dough
{
private:
    /* data */
public:
    ThinCrustDough(){
        std::cout << "add ThinCrustDough" << std::endl;
    }
    ~ThinCrustDough();
};

class Sauce
{
    public:
    virtual ~Sauce(){};
};

class ChilliSauce : public Sauce
{
    public:
    ChilliSauce(){
        std::cout << "add ChilliSauce" << std::endl;
    }
    ~ChilliSauce();
};

class MarinaraSauce : public Sauce
{
    public:
    MarinaraSauce(){
        std::cout << "add MarinaraSauce" << std::endl;
    }
    ~MarinaraSauce();
};

class Cheese
{
    public:
    virtual ~Cheese(){};
};

class CremeCheese : public Cheese
{
public:
    CremeCheese(){
        std::cout << "add CremeCheese" << std::endl;
    }
    ~CremeCheese();
};

class NewYorkerCheese : public Cheese
{
public:
    NewYorkerCheese(){
        std::cout << "add NewYorkerCheese" << std::endl;
    }
    ~NewYorkerCheese();
};

class Veggies
{
    public:
    virtual ~Veggies(){};
};

class RedPepper : public Veggies
{
public:
    RedPepper(){
        std::cout << "add RedPepper" << std::endl;
    }
    ~RedPepper();
};

class Pepperoni : public Veggies
{
public:
    Pepperoni(){
        std::cout << "add Pepperoni" << std::endl;
    }
    ~Pepperoni();
};

class Clams
{
public:
    Clams(){
        std::cout << "add Clams" << std::endl;
    }
    ~Clams();
};

