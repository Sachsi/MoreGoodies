#include <iostream>

const int val1 {30};
constexpr int val2{34};
int val3{35}; // Run time value

constinit int age = 88; // This is initialized at compile time
const int age10 {10};
const constinit int age1 {val1}; // const and constinit can be combined
constinit int age2 {age1}; // Initializing with age would lead to a compiler error
                                 // age is not const
//constinit int age3 {val3}; // Error : val3 is evaluated at run time
                            // can't const initialize age3
const constinit double weight {33.33};
//constexpr constinit double scale_factor{3.11};// can't combine constexpr and constinit

int main(){
//constinit' can only be applied to a variable with static or thread storage duration
    //constinit double height{1.72};

    std::cout << "age : " << age << std::endl;
    std::cout << "age1 : " << age1 << std::endl;
    std::cout << "age2 : " << age2 << std::endl;

    age = 33; // Can change a constinit avariable during runtime
    std::cout << "age : " << age << std::endl;

    //Combining const and constinit
    std::cout << "weight : " << weight << std::endl;
    //weight = 44.44; // lead to a compiler error

    return 0;
}