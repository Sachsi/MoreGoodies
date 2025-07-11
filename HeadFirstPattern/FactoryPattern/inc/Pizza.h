#pragma once
#include <iostream>

class Pizza {
    public:
        void prepare() {
            std::cout << "Preparing pizza.. " << std::endl;
        }
        void bake() {
            std::cout << "Bakeing pizza.. " << std::endl;
        }
        void cut() {
            std::cout << "Cutting pizza.. " << std::endl;
        }
        void box() {
            std::cout << "Boxing pizza.. " << std::endl;
        }

};