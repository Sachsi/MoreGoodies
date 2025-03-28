#include "Integer.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <filesystem>   //C++17
#include <list>
#include <deque>

void Emplace()
{
    std::vector<Integer> vInt;
    Integer val{1};
    //vInt.push_back(val);

    vInt.emplace_back(val);
    std::vector<std::pair<int, std::string>> data;
    data.push_back(std::pair<int, std::string>(1, "one"));
    //siehe the difference between push_back and emplace_back
    data.emplace_back(2, "two");
}


void Shrink()
{
    std::vector<int> vInt;
    for(size_t i = 0; i < 100 ; ++i){
        vInt.push_back(i);
    }

    std::cout << "Size: " << vInt.size() << std::endl;
    std::cout << "Capacity: " << vInt.capacity() << std::endl;

    vInt.erase(vInt.begin(), vInt.end()-10);
    std::cout << "after erase Size" << std::endl;
    
    std::cout << "Size: " << vInt.size() << std::endl;
    std::cout << "Capacity: " << vInt.capacity() << std::endl;

    vInt.shrink_to_fit();
    std::cout << "after shrink_to_fit" << std::endl;
    std::cout << "Size: " << vInt.size() << std::endl;
    std::cout << "Capacity: " << vInt.capacity() << std::endl;
}

int VectorFunction(){
    std::string path = "C:/Users/tobis/Documents/Software/Weiterbildung/CppProjects/MoreGoodies/Containers/src/change_one.cpp";

    std::ifstream input{path};
    if(!input){
        std::cout << "Could not open file \n";
        return -1;
    }
    auto size = std::filesystem::file_size(path);
    //with vector we can use resize to allocate memory, with don't have to maanager memory
    std::vector<char> buff;
    buff.resize(size);
    //char *buff = new char[size]{};
    //char buff[1024];    //fix size buffer
    input.read(buff.data(), size);
    std::cout << buff.data() << '\n';
    //delete []buff;
}


template<typename Container>
void Print(const Container &cont, const char *msg=""){
    std::cout << msg << '\n';
    for(auto a : cont){
        std::cout << a << '\n';
    }
}

#ifdef CHANGE_TWO

int main(void){

    std::vector<int> vInt{1,2,3,4,5};
    std::list<int> lstInt{1,2,3,4,5};
    std::deque<int> dequeInt{1,2,3,4,5};

    return 1;
}

#endif //CHANGE_TWO

#ifdef CHANGE_ONE

int main(void){

    //Emplace();
    std::vector<Integer> vInt;
    vInt.push_back(1);
    vInt.push_back(2);
    vInt.push_back(5);

    return 1;
}

#endif //CHANGE_ONE