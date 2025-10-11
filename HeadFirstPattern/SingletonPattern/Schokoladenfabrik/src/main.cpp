#include <iostream>
#include "Schokoladenfabrik.h"

enum class SchokoladenfabrikSingleton {
    UNIQUE_INSTANCE = {Schokoladenfabrik fabrik = Schokoladenfabrik::getInstance();}
};

int main() {
    std::cout << "Hello, Singleton Pattern!" << std::endl;

    SchokoladenfabrikSingleton singleton = SchokoladenfabrikSingleton::UNIQUE_INSTANCE;
    
    Schokoladenfabrik& fabrik = Schokoladenfabrik::getInstance();
    fabrik.fill();

    return 0;
}