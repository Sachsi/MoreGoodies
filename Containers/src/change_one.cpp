#include "Integer.h"
#include <iostream>
#include <vector>

int main(void){
    std::vector<Integer> vInt;
    Integer val{1};
    //vInt.push_back(val);

    vInt.emplace_back(val);
    std::vector<std::pair<int, std::string>> data;
    data.push_back(std::pair<int, std::string>(1, "one"));
    //siehe the difference between push_back and emplace_back
    data.emplace_back(2, "two");

    return 1;
}