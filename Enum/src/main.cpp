#include <iostream>
//define Enum

//#define RED 0
//const int VERDE = 1;
//enum class Color{RED, GREEN, BLUE };
//an enum class is not longer global. the standard type is int and increment by 1
 enum class Color{RED, GREEN, BLUE };

void FillColor(Color color){
    //Background Color
    if(color == Color::RED){
        std::cout << "RED " << std::endl;
    }
    else if (color == Color::GREEN)
    {
        std::cout << "GREEN " << std::endl;
    }
    else if(color == Color::BLUE ){
        std::cout << "BLUE" << std::endl;
    }
};
//TrafficLight is not possible because enum has global rights
//enum TrafficLight{RED, GREEN, BLUE };
// an enum class can have another type as well
enum class TrafficLight : char{RED = 'c', GREEN, BLUE };

int Enum(void)
{
 #ifdef Enum
    Color c = RED;
    FillColor(c);
    FillColor(GREEN);
    //int value is with static cast still possible
    FillColor(static_cast<Color>(2));
 #endif
}

int main(void)
{
    Enum();
    
    Color c = Color::RED;
    FillColor(c);
    FillColor(Color::GREEN);
    FillColor(Color::BLUE);
    int x = static_cast<int>(Color::BLUE);
    
    return 0;
}