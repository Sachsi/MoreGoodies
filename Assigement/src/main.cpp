#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

std::string ToUpper(const std::string &str) ;
std::string ToLower(const std::string &str) ;


std::string ToUpper(const std::string &str) 
{
    char *temp= new char(str.length() +1); 
    strcpy(temp, str.c_str());
   while(*temp)
     {
        *temp = toupper((unsigned char) *temp);
        temp++;
    }
    //strcat(temp, "\n");
    temp -= str.length();
    std::cout << temp << std::endl;
    
    return temp;
}
std::string ToLower(const std::string &str) 
{
    char *temp = new char(str.length() + 1);
    strcpy(temp, str.c_str());
    while(*temp){
        *temp = tolower((unsigned char)*temp);
        temp++;
    }
    temp -= str.length();
    std::cout << temp << std::endl;
    return temp;
}

/*The find function in std::string uses a case-sensitive search. 
Write a function that also performs a case insensitive search. 
Use an enum to decide between case-sensitive and case-insensitive search. 

The prototype of the function is:*/

enum class Case{SENSITIVE, INSENSITIVE};
 
size_t Find(
 const std::string &source,             //Source string to be searched
 const std::string &search_string,      //The string to search for
 Case searchCase = Case::INSENSITIVE,   //Choose case sensitive/insensitive search
 size_t offset = 0 ) {                  //Start the search from this offset
    size_t x = 0;
     //Implementation

    if(searchCase == Case::SENSITIVE){
        x = source.find(search_string);
    }else
        x = std::string::npos;
    
    return x;
     /*
     return position of the first character 
     of the substring, else std::string::npos
     */
}
//Note that, we don't have direct write access to the raw string inside std::string.

//Add one more function called FindAll, 
//that returns the starting indices of all the found
//substrings in a target string. Return the indices in a vector. 
//Support case sensitive/insensitive search.
 
std::vector<int>
FindAll(
 const std::string &target,              //Target string to be searched
 const std::string &search_string,       //The string to search for
 Case searchCase = Case::INSENSITIVE,    //Choose case sensitive/insensitive search
 size_t offset = 0) {                    //Start the search from this offset
     //Implementation
    std::vector<int> a;
    /*
    Return indices of found strings,
    else an empty vector
    */
   return a;
}

int main(void)
{
    std::string source;
    std::string search;
    std::cout << "Please enter an source line: " << std::endl;
    std::getline(std::cin, source);

    std::cout << "Please enter an search word:" << std::endl;
    std::getline(std::cin, search);
    auto pos = Find(source, search, Case::SENSITIVE);

    std::cout << "The search please is: " << pos << std::endl;
    return 1;
}