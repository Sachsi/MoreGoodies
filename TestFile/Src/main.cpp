#include <iostream>
#include <memory>
#include <array>
#include <stdexcept>
#include <map>

void UsingArray()
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
}


int Calc(int a, int b)
{
    return (a + b);
}

void print_map(std::string msg, std::map<std::string, int> temp)
{
    std::cout << "map: " << temp.count("CPU") << std::endl;
    std::cout << msg << std::endl;
    //Iterate using C++
    for(const auto& [key, value] : temp)
    {
        std::cout << "der key: " << key << " der Wert: " << value << std::endl;
    }
}

int main(void)
{
    typedef std::map<std::string, int> maps;

    maps a{{"CPU", 10},{"GPU", 15},{"RAM", 20}};
    maps b;
    
    print_map("1) Inittial map: ", a);
    a.insert(std::pair<std::string, int>("CPP", 23));

    print_map("2) insirt key map: ", a);
        
    Calc(3, 5);
    return 1;
}