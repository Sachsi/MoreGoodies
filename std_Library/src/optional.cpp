#include <iostream>
#include <optional>

const char * GetErrorString(int errorNo){
    switch (errorNo){
        case 0:
            return "Invalid input";
        case 1:
            return "Connection not established yet\n";
        case 2:
            return "Undefined Error\n";
        default:
            return "unknwon error\n";
    }
}

int main(void) 
{
    //std::optional value{5}; //create an optional value with value 5, the type is deduced from the value
    auto value = std::make_optional(5); //create an optional value. 
    //specifie the type of the optional value
    //std::optional<int> value;
    //check if the value is empty or not
    if(value.has_value()){
        std::cout << "value is: " << value.value() << std::endl;
    }
    //check if it is empty, and call it by refernece
    if(value){
        std::cout << "value ref is: " << *value << std::endl;
    }

    auto message = GetErrorString(1);
    if(strlen(message) != 0){
        std::cout << message << std::endl;
    }else{
        std::cout << "Unknown error number\n";
    }

    return 1;
}