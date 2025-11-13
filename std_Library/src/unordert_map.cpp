#include <iostream>
#include <unordered_map>

#include <iostream>
#include <unordered_set>
//#include <unordered_map>
#include <string>

/**
 * unordert multiply map offers duplicats of entries.
 * other behavourse are the like in map and / set
 */
void UnordertMulMap(){
    std::unordered_multimap<std::string, std::string> coll;
    coll.insert(std::make_pair("HulK","Matze"));
    coll.insert(std::make_pair("Sachse", "Tobi"));
    coll.insert(std::make_pair("Dany","Olaf"));
    coll.insert(std::make_pair("Rudolf", "Rehntier"));
    coll.insert(std::make_pair("Rudolf", "Rehntier"));
    coll.insert(std::make_pair("Rudolf", "Rehntier"));
    for(const auto x : coll){
        std::cout << "Bucket #:"<< x.first << " contains " << x.second << std::endl;
    }
    // the capasity of the unordert set 
    std::cout << "Bucket count: " << coll.bucket_count() << std::endl;
    // the number of the element in the set
    std::cout << "Elements : " << coll.size() << std::endl;
    //loadfactor knows as entries or capacity
    std::cout << "Load factor: " << coll.load_factor() << std::endl;
}


void UnMap(){
    std::unordered_map<std::string, std::string> coll;
    coll["HulK"] = "Matze";
    coll["Sachse"] = "Tobi";
    coll["Dany"] = "Olaf";
    coll["Rudolf"] = "Rehntier";
    for(const auto x : coll){
        std::cout << "Bucket #:"<< x.first << " contains " << x.second << std::endl;
    }
    // the capasity of the unordert set 
    std::cout << "Bucket count: " << coll.bucket_count() << std::endl;
    // the number of the element in the set
    std::cout << "Elements : " << coll.size() << std::endl;
    //loadfactor knows as entries or capacity
    std::cout << "Load factor: " << coll.load_factor() << std::endl;
}

int main(){
    
    UnMap();
    UnordertMulMap();
    return 1;
}