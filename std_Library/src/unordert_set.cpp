#include <iostream>
#include <unordered_set>
#include <string>

void UnSet(){
    std::unordered_set<std::string> coll;
    coll.insert("HulK");
    coll.insert("Sachse");
    coll.insert("Dany");
    coll.insert("Rudolf");
    coll.insert("Hainer");
    coll.insert("Reche");
    coll.insert("Holger");
    for(const auto x : coll){
        std::cout << x << std::endl;
    }
    // the capasity of the unordert set 
    std::cout << "Bucket count: " << coll.bucket_count() << std::endl;
    // the number of the element in the set
    std::cout << "Elements : " << coll.size() << std::endl;
    std::cout << "Load factor: " << coll.load_factor() << std::endl;
}

int main(){


    UnSet();
    return 1;
}