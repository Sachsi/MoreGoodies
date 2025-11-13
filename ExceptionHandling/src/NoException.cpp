#include <iostream>

//in a library you never know its noexcept true  or false

void Test(int x)noexcept(false){
    std::cout << x << std::endl;
    //throw x;
}


//- Function with throw excep. Hand. will terminate because 
//function assumend there was no exception comming but it did.
//- In this case we have to do noexcept(false). So the function may can throw or not.

int Sum(int x, int y)noexcept(noexcept(Test(x))) {
    //you get still a warning from the compiler but you can run the programm -> crash
    //throw 3;
    //you don't get a warning from the compiler as well, but programm crashs.
    Test(3);
    return x + y;
}

class A{
    public:
    ~A(){
        //destructor is alwayse used to noexcept(true)
        throw 3;
    };
};

#ifdef NoExHand_I_
// all function that are sure that they not throw an exception should mark with 
// with an noexcept(true) specifier
int main(void){
    A a;

    //- the noexcept is just an operator and except boolean values. So we can use the
    // return value of the function (nexcept(Test(x))) to tell this operator if its throw or not.
    //std::cout << std::boolalpha << noexcept(Test(5)) << std::endl;

    //destructor is alwayse used to noexcept(true)
    std::cout << std::boolalpha << noexcept(a.~A()) << std::endl;
    try
    {
        Sum(3, 5);
        //other statments
    }
    catch(int x)
    {
        std::cout << x << std::endl;
    }
    

    return 0;
}

#endif