#include <iostream>
/*
Set and multiset are assocaitive containers that store unique keys.
The elements are always sorted by their key following a specific strict weak ordering 
cirteria indicated by its internal comparation object. 
Set is good for fast search but no random access. The elements can not be modified directly.
*/

#include <set>
#include <functional> //std::greater


void MultSet(){
    //multiset allows duplicates
    std::multiset<int, std::greater<int>> s{2, 4, 6, 8, 10};
    s.insert(11);
    s.insert(1);
    s.insert(19);
    //duplicates are saved in the multiset
    s.insert(19);
    s.insert(4);
    s.insert(4);
    s.insert(20);

    auto itr = s.begin();
    while(itr != s.end()){
        std::cout << *itr++ << ",";
    }
    std::cout << std::endl;;
    s.erase(10);    //removed element(value) 10
    s.erase(++s.begin()); //removed element 1
    std::cout << "Erased 10 and first ++element" << std::endl;
    itr = s.begin();
    while(itr != s.end()){
        std::cout << *itr++ << ",";
    }
    std::cout << std::endl;
    itr = s.find(19);
    if(itr != s.end()){
        std::cout << "Element was found: " << *itr << std::endl;
    }else
        std::cout << "Element was not found" << std::endl;

    //the range.second is the element which is less than the key
    auto range = s.equal_range(4);

    while(range.first != range.second)
    {
        std::cout << *range.first++ << ",";
    }
}

void SetGreater()
{
    //std::greater is a compare function that sorts the elements in descenting order
    std::set<int, std::greater<int>> s{2, 4, 6, 8, 10};
    s.insert(11);
    s.insert(1);
    s.insert(19);
    //duplicates are not saved in the set
    s.insert(19);
    s.insert(19);

    auto itr = s.begin();
    while(itr != s.end()){
        std::cout << *itr++ << ",";
    }
    std::cout << std::endl;

    s.erase(10);    //removed element(value) 10
    s.erase(s.begin()); //removed element 1
    itr =s.find(19);
    if(itr != s.end())
    {
        std::cout << "Element was found: " << *itr << std::endl;
    }else
        std::cout << "Element was not found" << std::endl;

    itr = s.begin();
    while (itr != s.end())
    {   
        std::cout << *itr++ << ",";
    }
    std::cout << std::endl;
}

//seet as default compare function std::less
void Set(){
    //by default is used compare function std::less
    //the access to the elements is always const
    std::set<int> s{6, 4, 1, 7, 8, 9};
    s.insert(5);
    s.insert(2);

    auto itr = s.begin();

    //*itr = 100; //error: assignment of read-only location

    while(itr != s.end())
    {
        std::cout << *itr++ << ",";
    }

    std::cout << std::endl; 
    s.erase(0);
    s.erase(s.begin());
    itr = s.find(9);
    if(itr != s.end())
    {
        std::cout << "Element was found: " << *itr << std::endl;
    }else{
        std::cout << "Element was not found" << std::endl;
    }
}

int main(void)
{
    Set();
    SetGreater();
    MultSet();
    return 0;
}