#include <iostream>

// int Max(int x, int y)
// {
//     std::cout << typeid(x).name() << std::endl;
//     return x > y ? x : y;
// }
template<typename T>
T Max(T x, T y)
{
    std::cout << "type: " << typeid(T).name() << std::endl;
    return x > y ? x : y;
}

//Explicit Instanciation
template char Max(char x, char y);

//explicite specialization
//would not this template instanziiatet, the programm invoked the Max<char> template but
// result is wrong because of compareing the pointer.
template<> const char* Max<const char*>(const char*x, const char*y)
{
    std::cout << "Max<const char*>() " << std::endl;
    return strcmp(x,y) > 0 ? x : y;
}

//#ifdef TEMPLATES_STEP1

int main(void){

    int a = Max(3, 5);
    float b = Max(3.3f, 4.6f);
    double c = Max<int>(2.2f, 3.4f);
    std::cout << "Max a: "<< a << std::endl;
    std::cout << "Max a: "<< b << std::endl;
    std::cout << "Max a: "<< c << std::endl;

    const char* s{"Z"};
    const char* d{"F"};
    const char* r = Max(s, d);
    std::cout << "char: " << r << std::endl;


    return 1;
}

//#endif