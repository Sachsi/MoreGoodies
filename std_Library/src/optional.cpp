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

std::optional<const char*> GetErrorStringOp(int errorNo){
    switch (errorNo){
        case 0:
            return "Invalid input";
        case 1:
            return "Connection not established yet\n";
        case 2:
            return "Undefined Error\n";
        default:
            return std::nullopt;
    }
    
}
class ContactName{
    std::string name;
    std::optional<std::string> middle;
    std::string last;

public:
    ContactName(const std::string &f, const std::optional<std::string>& m, const std::string &la)
    : name{f}, middle{m}, last{la}{
        
    }
    void Print(){
        std::cout << name << " ";
        std::cout << middle.value_or("") << " ";
        std::cout << last << std::endl;
    }
};
int main(void) 
{
#ifdef OPTIONAL_STEP1
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

    std::optional<int> opt{3};

    opt = 4; //assign a new value to the optional value
    std::cout << "opt is not empty: " << opt.has_value() << std::endl;
    opt.reset(); //reset the optional value, it will be empty now
#endif //STEP1

#ifdef OPTIONAL_STEP2
    try
    {   
        //std::optional value is 4 and not avaiable in the GetErrorString()
        auto errorMessage = GetErrorStringOp(4);
        //Bad Exception is thrown because of unknown value
        //std::cout << errorMessage.value() << std::endl;
        //Return default value if it contain no value
        std::cout << errorMessage.value_or("Default") << std::endl;

        //Programm crashed because of the value is not available in the GetErrorStringOp()  
        if(errorMessage.has_value()){
            //Throw exception std::bad_optional_acess ifno value
            std::cout << errorMessage.value() << std::endl;
        }else{
            std::cout << "Unknown error number\n";
        }

        errorMessage = GetErrorStringOp(4);
        
        if(errorMessage){
            //Undefined behavior if the value is no 
            std::cout << *errorMessage << std::endl;
        }else{
            std::cout << "Unknown error number\n";
        }
    }
    catch(std::exception &ex)
    {
        std::cerr << "Exception: " << ex.what() << std::endl;;
    }
        
#endif //SEP 2

//#ifdef OPTIONAL_STEP3
    ContactName contact{"Tobias", std::nullopt, "Sachse"};
    ContactName Wife{"Daniela", "Mendoza", "Escobar"};
    contact.Print();
    Wife.Print();
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

    std::optional<int> opt{3};

    opt = 4; //assign a new value to the optional value
    std::cout << "opt is not empty: " << opt.has_value() << std::endl;
    opt.reset(); //reset the optional value, it will be empty now
        
//#endif //SEP 3


    return 1;
}