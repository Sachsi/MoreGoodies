#include <iostream>
#include <memory>
#include <array>
#include <stdexcept>

int Calc(int a, int b)
{
    return (a + b);
}

int main(void)
{
    int v = 4;
    int *a = &v;
    int c{};
    std::array<int, 6> data{1, 2, 3, 4, 5, 6};
    std::shared_ptr<int> b(new int);
    *b = v;
    data.at(2) = 5;
    
    // std::cout << "ptr b:" << b.get() << std::endl;
    // std::cout << "value b:" << *b << std::endl;
    std::cout << "value data: " << data.at(1) << std::endl;
    std::cout << "value data: " << data.at(2) << std::endl;

    Calc(3, 5);
    return 1;
}