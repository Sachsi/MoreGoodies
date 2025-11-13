#include <iostream>
#include <array>
#include <vector>

void Array(){
    std::array<int, 5> arr = {1, 3 ,5 ,6, 7};
    for(int i = 0; i < arr.size(); i++){
        arr[i] = i;
    }
    //iterator of the first element and last element
    auto itr = arr.begin();
    auto end = arr.end();
    int a = end - itr;

    for(auto x : arr){
        std::cout << x << std::endl;
    }
    std::cout << "Size: " << a << std::endl;
    std::cout << "itr nr 2: " << *(++itr) << std::endl;

}

void Vecoter(){
    std::vector<int> coll{1, 2, 4, 5 ,6 };
    for(int i = 0; i < 5; ++i)
    {
        coll.push_back(i);
        std::cout << "size: " << coll.size() << std::endl;
    }
    coll[0] = 700;

    auto itr = coll.begin();
    while( itr != coll.end()){
        std::cout << *itr++ << std::endl;
    }

    coll.insert(coll.begin() + 1 , 100);
    coll.erase(coll.end() - 7);
    coll.pop_back(); //remove the last element

    auto itr1 = coll.begin();
    while( itr1 != coll.end()){
        std::cout << *itr1++ << std::endl;
    }
}

int main(void)
{
    Array();
    Vecoter();
    return 0;
}