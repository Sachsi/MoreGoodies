/**
 * @file variant.cpp
 */
#include <iostream>
#include <variant>

int main(void)
{
    try
    {
        std::variant<std::string, int> v{5};
        auto val = std::get<int>(v);
        val = std::get<1>(v);

        auto activeindex = v.index();
        //it returns a pointer to the actuel value
        auto p = std::get_if<int>(&v);

        std::cout << activeindex << std::endl;
    }
    catch(std::exception& ex)
    {
        std::cout << "Exception: " << ex.what() << std::endl;
    }
    


    return 1;
}