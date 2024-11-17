#include <iostream>
#include <memory>
#include <vector>
#include <limits>
#include <stdio.h>
#include <random>

//#define anyEx
#define STEP_3_ //with smart pointer

class Test{
public:
    Test(){std::cout << "Test():Acquire resources" << std::endl;}
    ~Test(){std::cout << "~Test():Release resources" << std::endl;}

};

int ProcessRecords(int count){
    // with an pointer intanciation, the Instractor will be invoke normaly but
    // the destractor will not invoke when the function get interrupted by an exception
#ifndef STEP_3_
    Test *t = new Test;

    if(count < 5)
    {
        throw std::out_of_range("Count should be greater than 5");
    }
    int *p = new int[count];
    int *pArray = (int*)malloc(count * sizeof(int));
    if(pArray == nullptr){
        //The programm crashed when the int value is to big for the malloc
        //std::cout << "Failed to allocate memory" << std::endl;
        //to throw an exception error we have to throw an error
        throw std::runtime_error("Failed to allocate memory");
    }
    for(int i = 0; i < count ; ++i){
        pArray[i] = i;
    }
    free(pArray);
    delete[] p;
    delete t;
#else
    std::unique_ptr<Test> t(new Test);

    if(count < 5)
    {
        throw std::out_of_range("Count should be greater than 5");
    }
    
    std::vector<int> p;
    p.reserve(count);
    std::vector<int> pArray;
    pArray.reserve(count);

    for(int i = 0; i < count; ++i){
        pArray.push_back(i);
    }

    std::default_random_engine eng;
    std::bernoulli_distribution dist;
    int errors{};
    //we will show that some boolean values can not process
    //if it is not true, we will throw an exception
    for(int i = 0; i < count; ++i){
        try
        {
            std::cout << "Processing record # : " << i << " ";
            if(!dist(eng)){
                ++errors;
                throw std::runtime_error("Coudl not process the record");
            }
            std::cout << std::endl;
        }   
        catch(std::runtime_error& ex)
        {
            std::cout << "[ERROR " << ex.what() << "]" << std::endl;
            if(errors > 4){
                //this error exception will thrown outside of this try catch block to interrupt the function
                std::runtime_error err("Too many errors, Abanding operation");
                ex = err;   //standard error message get replace by a new message
                throw;
            }
        }
        
    }

#endif

    return 0;
}



int main(void)
{

    std::string a;
    int value = 0;

    std::cin >> a;
    char b = a[0];
    value = atoi(const_cast<char*>(&b));

    std::cout << "Entered " << a << "and " << value << std::endl;

    try
    {
        ProcessRecords(std::numeric_limits<int>::max());
        ProcessRecords(value);
    }
#ifndef anyEx
    catch(std::runtime_error& ex)
    {
        std::cout << ex.what() << std::endl;
    }catch(std::out_of_range& ex)
    {
        std::cout << ex.what() << std::endl;
    }catch(std::bad_alloc& ex)
    {
        std::cout << ex.what() << std::endl;
    }catch(std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
    }
#endif
    catch(...)
    {
        std::cout << "any Exception " << std::endl;
    }
    
    std::cout << "Finish Program" << std::endl;
    std::cin >> a;
    return 1;
}