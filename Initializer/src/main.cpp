#include <iostream>
#include <initializer_list>
#include <cassert>

class Bag
{
    int arr[10];
    int m_Size{};
public:
    Bag(std::initializer_list<int> values){
        assert(m_Size < 10);
        auto it = values.begin();
        while (it != values.end())
            Add(*it++);
    }
    void Add(int value){
        assert(m_Size < 10);
        arr[m_Size++] = value;
    }
    void Remove(){
        --m_Size;
    }
    int operator [](int index){
        return arr[index];
    }
    int GetSize() const{
        return m_Size;
    }
};

void Print(std::initializer_list<int> values)
{
    auto it = values.begin();
    while (it != values.end())
        std::cout << *it++ << " " << std::endl;
    //or using the for range loop as well
    for (auto it : values)
    {
        std::cout << it << " " << std::endl;
    }
    
}

int main(void)
{
    int x{0};
    float{3.1f};
    int arr[5];
    std::string s{"Hello C++"};
    std::initializer_list<int> data = {1,2,3,4};
    auto values = {1,2,3,4};
    std::cout << "Initializer Exercize" << std::endl;

    //constructor with needs a initializer list
    Bag b{3, 1, 4};
    // b.Add(3);
    // b.Add(1);
    // b.Add(8);
    for(int i = 0; i < b.GetSize(); ++i){
        std::cout << b[i] << " " << std::endl;
    }

    //Print an initializer list
    Print({1,59,5,3,89});
    //or by using an for loop
    for (auto x : {23,69,3,36}){
        std::cout << x << " ";
    }
    
    return 0;
}