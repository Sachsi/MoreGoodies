#include <iostream>
#include <string>

int main(){
bool range{true};

std::string location = "Please enter your location ";

std::string in_range = "Your are completly surrounded. Don't move";

std::string out_range = "Your're out of reach! ";

int y_user{0};

int x_user{0};

std::cout << location << "x: ";

std::cin >> x_user;

std::cout << location << "y: ";

std::cin >> y_user;

if (int x_location{20}; (x_location >= x_user )&& (0 <= x_user))
    {
    if( int y_location{10}; (y_location >= y_user) && (0 <= y_user))
    {
        range = true;
    }else
        range = false;
}else
    range = false;

if(range == true){
    std::cout << in_range << std::endl;
}else{
    std::cout << out_range << std::endl;
}

return 1;
}