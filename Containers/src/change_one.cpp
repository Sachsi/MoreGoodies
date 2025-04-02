#include "Integer.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <filesystem>   //C++17
#include <list>
#include <deque>
#include <set>

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

void erase(){
    std::vector<int> vInt{1,2,3,4,5};
    std::list<int> lstInt{1,2,3,4,5};
    std::deque<int> dequeInt{1,2,3,4,5};

    std::erase(vInt, 2);
    std::erase(lstInt, 2);
    std::erase(dequeInt, 2);

    Print(vInt, "vector");
    Print(lstInt, "list");
    Print(dequeInt, "deque");
}
//#ifdef CHANGE_TWO

int main(void){

    //emplace_hint() 
    std::set<int> data{1,2,6,3};
    data.emplace_hint(data.begin(), 0);

    //using function find()
    auto it = data.find(6);
    if(it != data.end()){
        std::cout << "Found: " << std::endl;
    }
    //but function function .contains() combines the steps to one
    auto found = data.contains(6);
    if(found){
        std::cout << "Found: " << std::endl;;
    }

    //try to change one character in a set of string
    std::set<std::string> names{"Tobi", "Klausi", "Hans", "Leter"};
    auto cha =names.find("Leter");
    auto name = *cha;
    name[0] = 'P';
    names.erase(cha);
    names.insert(name);
    for(auto a : names){
        std::cout << a << '\n';
    }
    //a shorter way to change one letter in a string
    auto node = names.extract("Tobi");
    node.value().append("as");
    names.insert(std::move(node));
    node = names.extract("Klausi");
    node.value()[5] = ' ';
    names.insert(std::move(node));
    for(auto a : names){
        std::cout << a << '\n';
    }

    return 1;
}

//#endif //CHANGE_TWO

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