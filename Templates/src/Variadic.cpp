#include <iostream>
#include "Integer.h"
//this problem is, the type of the arguments have to be the same
// template<typename T>
// void Print(std::initializer_list<T> args)
// {
//     for(const auto &x : args)
//     {
//         std::cout << x << std::endl;
//     }
// } 

//function is needed to do the last step by reading the
//arguments of the parameter pack Print(...)
void Print()
{
    std::cout << std::endl;
}

//variadic Template parameters pack
template<typename T, typename...Params>
//Function parameter pack
void Print(T &&a, Params&&...args)
{
    //Variadic Part II, get access of the arguments
    // std::cout << sizeof...(args) << std::endl;
    // std::cout << sizeof...(Params) << std::endl;
    std::cout << a;
    if(sizeof...(args) != 0)
        std::cout << ",";
    Print(std::forward<Params>(args)...);
}

#ifdef VARIADIC
int main(void)
{
    //Template mit festen typen
    //Print({1, 3, 4, 5});
    //Variatic template
    //Print(1, 2.5, 3, "4");
    Integer val{1};
    Print(1, 3, val, Integer{3});
    return 1;
}
#endif

/*
1.Print(1, 2.4, 3, "4");
2.Print(2.4, 3, "4");
3.Print(3, "4");
4.Print("4");
5.Print();
*/