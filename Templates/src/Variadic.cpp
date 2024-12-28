#include <iostream>

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

}

//variadic Template parameters pack
template<typename T, typename...Params>
//Function parameter pack
void Print(T a, Params...args)
{
    Print(args...);
}

#ifdef VARIADIC
int main(void)
{
    Print(1, 2, 3, 4);
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