#include <iostream>
#include <type_traits>

template<typename T>
T Divide(T a, T b){
#ifdef ASSERT
    static_assert(std::is_floating_point<T>::value, "Only floating point type supported");
#endif
    if(std::is_floating_point<T>::value == false){
        std::cout << "Use floating point types only\n";
        return 0;
    }
    return a / b;
}

template<typename T>
void Check(T&&){
    std::cout << std::boolalpha ;
    std::cout << "Is reference?" << std::is_reference<T>::value << std::endl;

    std::cout << "After removing:" <<
        std::is_reference<typename std::remove_reference<T>::type>::value << std::endl;
}

//#ifdef TRAITS
int main(void)
{
    Check(5);
    int value{};
    Check(value);

    std::cout 
    << std::boolalpha
    << "Is integer ?" << std::is_integral<int>::value << std::endl;

    std::cout << Divide(5.8, 8.8) << std::endl;
    return 0;
}
//#endif