#include <iostream>


int main(){

    //Overflow
    unsigned char data {250};

    ++data;
    std::cout << "data value: " << static_cast<int>(data) << '\n';

    ++data;
    std::cout << "data value: " << static_cast<int>(data) << '\n';
    ++data;
    std::cout << "data value: " << static_cast<int>(data) << '\n';
    ++data;
    std::cout << "data value: " << static_cast<int>(data) << '\n';
    ++data;
    std::cout << "data value: " << std::hex << static_cast<int>(data) << '\n'; //0xff

    std::cout << "Overflow value: " << std::dec << static_cast<int>(data) << '\n'; //255
    ++data;
    std::cout << "Overflowed value: " << static_cast<int>(data) << '\n'; //0

    //Underflow
    std::cout << "------------------\n";
    data = 1;
    std::cout << "data value: " << static_cast<int>(data) << '\n';
    --data;
    std::cout << "data value: " << static_cast<int>(data) << '\n';
    --data;
    std::cout << "Underflowed value: " << static_cast<int>(data) << '\n'; //255

    return 0;
}