#include "Integer.h"
#include <iostream>
#include <vector>

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

int main(void){

    //Emplace();
    std::vector<Integer> vInt;
    vInt.push_back(1);
    vInt.push_back(2);
    vInt.push_back(5);

    return 1;
}