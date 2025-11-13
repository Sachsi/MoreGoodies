#include <iostream>
#include <map>
#include <string>

//using a map when you want base on a key to store a value rather than an value

void MultiMap(){
    //initialize a map
    std::multimap<int, std::string> m{
        {1, "Supermanne"},
        {2, "Batman"},
        {3,"Oma"},
        {0, "Green Lantern"}
    };
    //insert a new element
    m.insert(std::make_pair(4, "Wonder"));
    m.insert(std::pair<int, std::string>(7, "Flash"));
    m.insert(std::pair<int, std::string>(6, "Flashlight"));

    //insert a new element with an exicting key, it wil not be inserted or overwrite the existing one
    m.insert(std::pair<int, std::string>(6, "Sunlight"));

    auto b = m.equal_range(6);
    while (b.first != b.second)
    {
        std::cout << b.first->first << " " << b.first->second << " " << std::ends;
        std::cout << b.second->first << " " << b.second->second  << std::endl;
        b.first++;
    }
    
    auto itr = m.begin();
    //access to the elements
    std::cout << itr->first << ":" << itr->second << std::endl;
    // earse the element with key 0;
    m.erase(0);

    //print the map
    for(const auto& elem : m){
        std::cout << elem.first << " " << elem.second << std::endl;
    }

    std::cout << "find the element with key 3: " << std::ends;
    auto itr1 = m.find(3);


    if(itr1 != m.end()){
        std::cout << "Found " << itr1->second << std::endl;
    }else
        std::cout << "Not found" << std::endl;
}

void Map(){
    //initialize a map
    std::map<int, std::string> m{
        {1, "Supermanne"},
        {2, "Batman"},
        {3,"Oma"},
        {0, "Green Lantern"}
    };
    //insert a new element
    m.insert(std::make_pair(4, "Wonder"));
    m.insert(std::pair<int, std::string>(7, "Flash"));
    m.insert(std::pair<int, std::string>(6, "Flashlight"));

    //insert a new element with an exicting key, it wil not be inserted or overwrite the existing one
    m.insert(std::pair<int, std::string>(6, "Flashlight"));

    auto itr = m.begin();
    //access to the elements
    std::cout << itr->first << ":" << itr->second << std::endl;
    // earse the element with key 0;
    m.erase(0);

    //using the [] operator to access the elements with key 10, not existing
    std::cout << "No Key 10 value: " << m[10] << std::endl;
    //print the map
    for(const auto& elem : m){
        std::cout << elem.first << " " << elem.second << std::endl;
    }
    std::cout << "No Key 10 value: " << m[10] << std::endl;

    std::cout << "find the element with key 3: " << std::ends;
    auto itr1 = m.find(3);


    if(itr1 != m.end()){
        std::cout << "Found " << itr1->second << std::endl;
    }else
        std::cout << "Not found" << std::endl;

    //using the [] operator to access the elements
    std::cout << "3 Key value: " << m[3] << std::endl;
}

int main(void)
{
    MultiMap();
    return 1;
}