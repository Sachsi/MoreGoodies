#include <iostream>
#include <memory>
#include <vector>

class A
{
private:
    /* data */
public:
    A(void){
        std::cout << "A() constractor " << std::endl;
    };
    ~A(){
        std::cout << "~A() destractor " << std::endl;
    };
};
class B
{
private:
    /* data */
public:
    B(void){
        std::cout << "B() constractor " << std::endl;
    };
    ~B(){
        std::cout << "~B() destractor " << std::endl;
    };
};

class Test
{
private:
    std::unique_ptr<A> pA;
    B b{};
    std::unique_ptr<int> pInt;
    std::string pStr;
    std::vector<int> pArr;
    // A *pA{};
    // B b{};
    // int *pInt{};
    // int *pArr{};
    // char *pStr{};
public:
    Test(){
        std::cout << "Test(): Acquire resource" << std::endl;  
        //wenn throwing this exception, the constrator for A und B will be invoked but 
        //and for B he get deleted again (konstant object). But the object for the pointer 
        //pA will not be deleted. To avoid this we have to use smart pointer.
        pA.reset(new A);
        //throw std::runtime_error("Failed to initialize");
        
        // pA = new A;
        // pInt = new int;
        // throw std::runtime_error("Failed to initialize");
        // pStr = new char[1000];
        // pArr = new int[50000];
    };
    ~Test(){
        //Whenn we use a Exception, it should never destroy the destructor.
        //See what happens whenn its so. It throw another Exception what crash the programm.
        std::cout << "~Test(): Release resource" << std::endl;  
        throw std::runtime_error("Failed to initialize");
        // delete pA;
        // delete pInt;
        // delete[] pStr;
        // delete[] pArr;
    };
};


#ifdef ExHand_II_  //exception Handling in de- and constrator

int main(void){

    try
    {
        Test t;
        //Expection Handling in Destructor
        throw std::runtime_error("Exception");
    }
    catch(const std::runtime_error& ex)
    {
        std::cout << ex.what() << '\n';
    }
    
    return 0;
}
#endif