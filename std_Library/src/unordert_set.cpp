#include <iostream>
#include <unordered_set>
//#include <unordered_map>
#include <string>

/**
 * unordert multiply set offers duplicats of entries.
 */
void UnordertMulSet(){
    std::unordered_multiset<std::string> coll;
    coll.insert("HulK");
    coll.insert("Sachse");
    coll.insert("Dany");
    coll.insert("Rudolf");
    coll.insert("Hainer");
    coll.insert("Hainer");
    coll.insert("Reche");
    coll.insert("Holger");
    coll.insert("Peschetor");
    coll.insert("Wolle");
    for(const auto x : coll){
        std::cout << "Bucket #:"<< coll.bucket(x) << " contains " << x << std::endl;
    }
    // the capasity of the unordert set 
    std::cout << "Bucket count: " << coll.bucket_count() << std::endl;
    // the number of the element in the set
    std::cout << "Elements : " << coll.size() << std::endl;
    //loadfactor knows as entries or capacity
    std::cout << "Load factor: " << coll.load_factor() << std::endl;
}


void UnSet(){
    std::unordered_set<std::string> coll;
    coll.insert("HulK");
    coll.insert("Sachse");
    coll.insert("Dany");
    coll.insert("Rudolf");
    coll.insert("Hainer");
    coll.insert("Hainer");
    coll.insert("Reche");
    coll.insert("Holger");
    coll.insert("Peschetor");
    coll.insert("Wolle");
    for(const auto x : coll){
        std::cout << "Bucket #:"<< coll.bucket(x) << " contains " << x << std::endl;
    }
    // the capasity of the unordert set 
    std::cout << "Bucket count: " << coll.bucket_count() << std::endl;
    // the number of the element in the set
    std::cout << "Elements : " << coll.size() << std::endl;
    //loadfactor knows as entries or capacity
    std::cout << "Load factor: " << coll.load_factor() << std::endl;
}

int main(){


    UnSet();
    UnordertMulSet();
    return 1;
}