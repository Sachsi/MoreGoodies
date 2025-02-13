#include <iostream>
#include <array>

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

int main(void)
{
    Array();
    return 0;
}