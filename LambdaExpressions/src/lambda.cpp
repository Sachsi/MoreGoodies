#include <iostream>

//ein Alais auf einen Functionszeiger
//the Alais has to commmited
//using Comparator = bool(*)(int, int);

/* to use this memember function we can define another typename 
It is still working with the global function. But global functions will still invoked.
Member function can be inlined */
template<typename T, int size, typename Comparator>
void sort(T(&arr)[size], Comparator comp){
    for(int i = 0; i < size - 1; ++i){
        for(int j = 0; j < size - 1; ++j){
            if(comp(arr[j], arr[j + 1])){       
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

template<typename T, int size, typename Callback>
void ForEach(T(&arr)[size], Callback operation){
    for(int i = 0; i <= size - 1; ++i){
        operation(arr[i]);
    }
}

template<typename T>
struct __Unnamed
{
    int offset;
    __Unnamed(int off) : offset(off){}
    //die Variable in einer Struct ist veänderbar da diese nicht mehr const ist
    void operator()(T &x)/*const*/{
        x = offset;
        ++offset;
    }
};


int main(void)
{
    __Unnamed<int> n(3);
    int x = 5;
    n(x);

    int arr[]{1 ,3, 9 ,23, 8, 4};
    ForEach(arr, [](auto x){
        std::cout << x << " ";
    });
    std::cout << std::endl;

    //offset is not accessable inside the lambda. We have to capture this variable in the capture list 
    // of the lambda expression
    int offset = 0;
    // ForEach(arr,[offset](auto &x){
    //     //offset inside is a copy
    //     x += offset;
    // });
    //to change offset inside the lambdda expression, lambda has to be mutable
    ForEach(arr,[offset](auto &x) mutable{
        //offset inside is a copy and can not changed as well
        x += offset;
        ++offset;
    });

    //print out
    ForEach(arr, [](auto x){
        std::cout << x << " ";
    });
    std::cout << std::endl;


    return 0;
}

void OldCode(){

    int arr[]{1 ,3, 9 ,23, 8, 4};
    for(auto i : arr)
    {
        std::cout << i << " ";
    }
    // lambda expression can give an name. Just one line above where she is used.
    // with the lambda code, the code is better readable 
    auto comp = [](auto x, auto y){
        return x < y;
    };
    //insert one lambda expression
    sort(arr, comp);
    std::cout << std::endl;

    for(auto i : arr)
    {
        std::cout << i << ",";
    }
}