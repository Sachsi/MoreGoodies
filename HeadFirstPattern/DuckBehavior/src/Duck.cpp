#include <iostream>
#include <memory>
#include <vector>
#include "duck.h"

class Duck
{
    protected:
        IFly* p_flyBehavior;
        IQuack* p_quackBehavior;
    public:
        virtual void swim() const {
            std::cout << "Duck swims" << std::endl;
        }
        virtual void display() const {
            std::cout << "Duck displays" << std::endl;
        }
        void performFly() const {
            p_flyBehavior->fly();
        }
        void performQuack() const{
            p_quackBehavior->quack();
        }
        void setFlyBehavior(IFly* flyBehavior){
            p_flyBehavior = flyBehavior;
        }
        void setQuackBeahavior(IQuack* quackBehavior){
            p_quackBehavior = quackBehavior;
        }
};


class MallardDuck : public Duck{
    public:
        MallardDuck(/*IFly* flyBehavior, IQuack* quack*/){
            p_flyBehavior = new FlyWithWings();// flyBehavior;
            p_quackBehavior = new Quack(); // quack;
            std::cout << "MallardDuck constructor called" << std::endl;
        }
        ~MallardDuck(){
            std::cout << "MallardDuck destructor called" << std::endl;
        }
        void display() const override {
            std::cout << "MallardDuck displays" << std::endl;
        }
};

class ModelDuck : public Duck{
    public:
        ModelDuck(){
            std::cout << "ModelDuck constructor called" << std::endl;
        }
        ~ModelDuck(){
            std::cout << "ModelDuck destructor called" << std::endl;
        }
        void display() const override {
            std::cout << "ModelDuck displays" << std::endl;
        }
};

int main(){

    FlyWithWings flyWithWings;
    FlyNoWings flyNoWings;
    Quack quack;
    Squeack squeack;
    MallardDuck mallard;
    
    ModelDuck rubber;
    rubber.setFlyBehavior(&flyNoWings);
    rubber.setQuackBeahavior(&squeack);
    
    std::cout << " ------------------ " << std::endl;

    std::vector<Duck*> ducks;
    ducks.push_back(&mallard);
    ducks.push_back(&rubber);

    for(const auto& duck : ducks){
        duck->display();
        duck->swim();
        duck->performFly();
        duck->setFlyBehavior(&flyNoWings);
        duck->performFly();
        duck->performQuack();
        std::cout << std::endl;
    }
    
    
    return 0;
}