#pragma once
#include <iostream>

class Schokoladenfabrik {

public:
    static Schokoladenfabrik& getInstance()
    {
        static Schokoladenfabrik Instance; // Guaranteed to be thread-safe in C++11 and later
        return Instance;
    }

    // delete copy constructor and assignment operator to prevent duplication
    Schokoladenfabrik(const Schokoladenfabrik&) = delete;
    Schokoladenfabrik& operator=(const Schokoladenfabrik&) = delete;

    void fill()
    {
        if(isEmty())
        {
            emty = false;
            boiled = false;
            std::cout << "Filling the boiler with a milk and chocolate mixture" << std::endl;
        }
    }
    void drain()
    {
        if(!isEmty() && isBoiled())
        {
            emty = true;
            std::cout << "Draining the boiled milk and chocolate mixture to make the boiler emty" << std::endl;
        }
}
    void boil()
    {
        if(!isEmty() && !isBoiled())
        {
            boiled = true;
            std::cout << "Boiling the mixture in the boiler" << std::endl;
        }
    }
    // Getter function
    bool isEmty()
    {
        return emty;
    }
    bool isBoiled()
    {
        return boiled;
    }

private:
    bool emty;
    bool boiled;
    //static Schokoladenfabrik Instance;

    Schokoladenfabrik()
    {
        std::cout << "Schokoladenfabrik instance created!" << std::endl;
        emty = true;
        boiled = false;
    }
};