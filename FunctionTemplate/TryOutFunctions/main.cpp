#include <iostream>

template <typename T>
T maximum(T a, T b)
{
    return (a > b) ? a : b;
}

template <typename T>
T multiply(T a, T b)
{
    return a * b;
}

/* 
std::string maximum(const std::string &a, const std::string &b)
{
    return (a > b) ? a : b;
}

long long int maximum(long long a, long long b)
{
    return (a > b) ? a : b;
} */

int main()
{
    int x{10};
    int y{12};
    double a{12.4};
    double b{30.1};
    std::string str1{"Hello"};
    std::string str2{"World"};

    int result = maximum(x, y);
    double result2 = maximum(a, b);
    std::string result3 = maximum(str1, str2);

    std::cout << "maximum int is " << result << std::endl;
    std::cout << "maximum double is " << result2 << std::endl;
    std::cout << "maximum string is " << result3 << std::endl;

    int result5 = multiply(x, y);
    double result6 = multiply(a, b);
    //std::string result7 = multiply(str1, str2);

    std::cout << "multiply int is " << result5 << std::endl;
    std::cout << "multiply double is " << result6 << std::endl;
    //std::cout << "multiply string is " << result7 << std::endl;

    // is not working because the function template is not defined for mixed types
    //double result8 = multiply(x, b);
    //std::cout << "multiply int and double is " << result8 << std::endl;

    return 0;
}