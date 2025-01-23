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
//ascending function
bool Comp(int x, int y){
    return x > y;
}
//descending function
bool Comp1(int x, int y){
    return x < y;
}
// this is a member function call
// it can have a state and is maybe faster
// function objects used as callbacks
// usally implemented as structures, not classes
struct Comp2
{
    bool operator()(int x, int y){
        return x < y;
    }
};


template<typename T>
struct Unnamed{
    T operator()(T x, T y)const{
        return x + y;
    }
};
int main(void)
{
    // Comp(2, 4);     //global function
    // Comp2 comp;     //member function call
    // comp(3, 4);     // comp.operator()()

    int arr[]{1 ,3, 9 ,23, 8, 4};
    for(auto i : arr)
    {
        std::cout << i << " ";
    }
    // lambda expression can give an name. Just one line above where she is used.
    // with the lambda code, the code is better readable 
    auto comp = [](auto x, auto y){
        return x > y;
    };
    //insert one lambda expression
    sort(arr, comp);
    std::cout << std::endl;

    for(auto i : arr)
    {
        std::cout << i << ",";
    }
    return 0;
}