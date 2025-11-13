#include <iostream>
#include <vector>

int main(void)
{
    int arr[10];
    int *ptr = new int[10];
    //but thats not realy an dynamic array because of his fix size
    for(int i = 0; i < 10; ++i){
        ptr[i] = 1 * 10;
    }
    //insert more element to the vector list
    std::vector<int> data{1 ,2 ,3};
    for(int i = 0; i < 5; ++i){
        data.push_back(i * 10);
    }

    //Acess
    data[0] = 100;
    // for(int i = 0; i < data.size(); ++i){
    //     std::cout << data[i] << " ";
    // }
    for (auto x : data)
    {
        std::cout << x << " ";
    }

    auto it = data.begin();
    std::cout << *it << std::endl;
    
    ++it;   // increment the index
    --it;   // decrement the index
    it = it + 5; // add the index + 5

    //Delete
    it = data.begin();
    data.erase(it);     //delete the first element
    for (auto x : data)
    {
        std::cout << x << " ";
    }
    
    //Insert
    // insert an vector add the specified position
    it = data.begin() + 5;
    data.insert(it, 500);
    
    std::cout << std::endl;
    for (auto x : data)
    {
        std::cout << x << " ";
    }
    return 1;
}