#include <iostream>
#include "duck.h"
#pragma once

namespace Duck::Decoy
{
    class DecoyDuck : public Duck::Base::Duck
    {
        public:
            DecoyDuck() {
                std::cout << "DecoyDuck created! " << std::endl;
            }
            ~DecoyDuck() {
                std::cout << "DecoyDuck destroyed! ";
            }
            void quack() const override {
                std::cout << "DecoyDuck does not quack! ";
            }
            void display() const override {
                std::cout << "DecoyDuck is displayed! ";
            }
            void fly() const override {
                std::cout << "DecoyDuck doen't fly! ";
            }
    };

        class RubberDuck : public Duck::Base::Duck
    {
        public:
            RubberDuck(){
                std::cout << "RubberDuck created! " << std::endl;
            };
            ~RubberDuck(){
                std::cout << "RubberDuck destroyed! ";
            };
            void quack() const override {
                std::cout << "RubberDuck squeaks! ";
            }
            void display() const override {
                std::cout << "RubberDuck is displayed! ";
            }
    };
}