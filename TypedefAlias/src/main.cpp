#include <iostream>
#include <vector>
#include <list>

const char * GetErrorMessage(int errorNo){
    return "Empty";
}

//typedef declaration
//typedef const char *(*PFN)(int);
//or using Alias 
using PFN = const char *(*)(int);
//void ShowError(const char *(*pfn)(int)){
void ShowError(PFN pfn){
    
}

typedef std::vector<std::list<std::string>> Names;
//Aliase of long type declaration, lock better
using Name = std::vector<std::list<std::string>>;

int main(){
    Names namen;
    Name nname;
    PFN pfn = GetErrorMessage;
    ShowError(pfn);
    return 0;
}