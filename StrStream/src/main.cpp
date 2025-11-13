#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>


int main(void)
{
    int a{8}, b{4};
    int sum = a +  b;
    std::string s{"Hello"};
    std::stringstream ss;
    ss << "Hallo " << a << " & " << b <<"is:" << sum;
    std::string out = ss.str();
    std::cout << out << std::endl;
    ss.str("");
    ss << sum;
    // convert string in into
    out = std::to_string(sum);
    std::cout << out << std::endl;

    std::string num{"82 23 45"};
    int x;
    ss.clear();
    ss.str(num);
    
    while(ss >> x){
        std::cout << x << std::endl;
    }
    int h = std::stoi("56");
    
    return 1;
}