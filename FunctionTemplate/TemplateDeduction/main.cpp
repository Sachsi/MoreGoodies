#include <iostream>
#include <string>

template <typename T> T maximum(T a, T b)
{
    return (a > b) ? a : b;
}

int main()
{
    int x{10};
    int y{12};
    double a{12.4};
    double b{30.1};
    std::string str1{"Hello"};
    std::string str2{"World"};

    // this can be problematic if we want to compare two different types
    int result1 = maximum(x, y);
    double result2 = maximum(a, b);
    std::string result3 = maximum(str1, str2);
    //explicite template argument, so we can compare different types, 
    //but we need to make sure that the types are compatible
    double result4 = maximum<double>(x, a);

    std::cout << "maxmum is " << result4 << std::endl;
    return 0;
}