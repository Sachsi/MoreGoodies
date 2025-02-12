#include <iostream>
#include <functional>

//#define PART_2
#define PART_3

int Subtract(int x, int y){
    return x - y;
}

void Print(const char *msg){
    std::cout << msg << std::endl;
}

struct GreaterThan{
    bool operator()(int x, int y)const{
        return x > y;
    }
};
int Operation(int x, int y, std::function<int(int, int)> callback){
    return callback(x, y);
}
int Accumulate(int x, int y, int z){
    return x + y + z;
}
//std::bind can bind same arguments to a function
//the arguments are represented by placeholders or diretly bound to 
//specific values
//can be used to invoke a function that acceptes n arguemnts as
//a function with n-m argumnets
//std::bind returns a function object

int main(void){

    using namespace std::placeholders; //shorten the placeholders
    //placeholder _1 and _2 are used to bind the arguments to function in a specific order
#ifdef PART_2
    std::function<int(int, int)> f1 = std::bind(Subtract, std::placeholders::_1, std::placeholders::_2);
    std::cout << "Order _1 - _2: " << f1(5, 3) << std::endl;
    f1 = std::bind(Subtract, _2, _1);
    std::cout << "Order _2 - _1: " << f1(5, 3) << std::endl;

    //if you want to pass just one argument to the function, you can bind the second value to a constant value
    auto f2 = std::bind(Subtract, _1, 10);
    std::cout << "Subtract 10 from: " << f2(2) << std::endl;

    //taking another function to bind 
    std::function<bool(int, int)> f3 = std::bind(GreaterThan{}, _1, _2);
    std::cout << "Is greater than?: " << f3(32, 12) << std::endl;

    //for what is std::bind useful? To use Accumulate function with only 2 arguments instead of 3
    //we have to bind the third argument to a constant value
    auto acc = std::bind(Accumulate, _1, _2, 0);
    std::cout << "Accumulate: " << Operation(1, 2, acc) << std::endl;
#else /**
    Lambda expressions can be used instead of std::bind. Is more readable and easier to understand.
    */
    //std::function<int(int, int)> f1 = std::bind(Subtract, std::placeholders::_1, std::placeholders::_2);
    //std::cout << "Order _1 - _2: " << f1(5, 3) << std::endl;
    auto f1 = [](int x, int y){ //std::bind(Subtract, _2, _1);
        return Subtract(x , y);
    };
    std::cout << "Order _2 - _1: " << f1(5, 3) << std::endl;

    //if you want to pass just one argument to the function, you can bind the second value to a constant value
    auto f2 = [](auto && x){ //std::bind(Subtract, _1, 10);
        return Subtract(std::forward<decltype(x)>(x), 10); 
    };
    std::cout << "Subtract 10 from: " << f2(2) << std::endl;

    //taking another function to bind 
    //std::function<bool(int, int)> f3 = std::bind(GreaterThan{}, _1, _2);
    //typname T is just with C++20 possible
    auto f3 = []<typename T>(T&& x, T&& y){
        return GreaterThan{}(std::forward<T>(y), std::forward<T>(x));
    };
    std::cout << "Is greater than?: " << f3(32, 12) << std::endl;

    //for what is std::bind useful? To use Accumulate function with only 2 arguments instead of 3
    //we have to bind the third argument to a constant value
    //auto acc = std::bind(Accumulate, _1, _2, 0);
    auto acc = [](int x, int y){
        return Accumulate(x, y, 0);
    };
    std::cout << "Accumulate: " << Operation(1, 2, acc) << std::endl;
#endif
    return 0;
}