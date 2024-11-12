#include <iostream>
#include <limits>
#include <stdio.h>

int ProcessRecords(int count){
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
    return 0;
}

#define anyEx

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
        //ProcessRecords(std::numeric_limits<int>::max());
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
    
    std::cout << "Hello World" << std::endl;
    std::cin >> a;
    return 1;
}