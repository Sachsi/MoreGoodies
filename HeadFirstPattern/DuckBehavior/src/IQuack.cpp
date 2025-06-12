#include "IQuack.h"

void Quack::quack() const  {
    std::cout << "Quack" << std::endl;
};

void Squeack::quack() const {
    std::cout << "Squeack" << std::endl;
};
void MuteQuack::quack() const {
    std::cout << "MuteQuack" << std::endl;
};