#include <iostream>
#include <functional>

/**
 * can store and invoke a function or a target
 */
int Square(int x){
    return x * x;
}

int Add(int x, int y){
    return x + y;
}
int Subtract(int x, int y){
    return x - y;
}

struct Max{
    int operator()(int x, int y){
        return x > y ? x : y;
    }
};

//for what cann I use std::function?. I can use it to store different types of function pointers
int Operation(int x, int y, std::function<int(int, int)> callback){
    return callback(x, y);
}

int main(void)
{
    try
    {   // f1 stores the address of the function Square
        std::function<int(int)> f1 = Square;
        std::cout << f1(5) << std::endl;
        //what when the placeholder of the function is empty? 
        std::function<int(int)> f2;
        //std::function is a bool type. If the traget is empty it will return false.
        if(f2)
        {   
            std::cout << f2(5) << std::endl;
        }
        else
        {
            std::cout << "f2 has no target" << std::endl;
        }
        //std::function can store an instance of a class
        Max m{};
        std::function<int(int,int)> f3 = m;
        std::cout << f3(5, 6) << std::endl;

        //std::function can store a Lmabda expression
        std::function<bool(int)> f4 = [](int x){
            return x % 2 == 0;
        };
        std::cout << "isEven?: " <<  f4(3) << std::endl;
        /*************************************************
        using the Operation function to invoke the different types of functions
        ************************************************* */
        std::cout << Operation(5, 7, Add) << std::endl;
        std::cout << Operation(2, 5, [](int x, int y){return x * y;}) << std::endl;
        f3 = Subtract;
        std::cout << Operation(5, 7, f3) << std::endl;
    }
    catch(const std::exception& ex)
    {
        std::cout << "Exception ->" << ex.what() << '\n';
    }
    
}