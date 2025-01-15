#include <iostream>

#ifdef FUNCTIONPOINTER

//ein Alais auf einen Functionszeiger
using Comparator = bool(*)(int, int);

template<typename T, int size>
void sort(T(&arr)[size], Comparator comp){
    for(int i = 0; i < size - 1; ++i){
        for(int j = 0; j < size - 1; ++j){
            //Nachteil bei Funktionszeigern ist, dass diese global sind und somit keine lokalen 
            //Variablen haben können
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
#endif FUNCTIONPOINTER

int main(void)
{
    int arr[]{1 ,3, 9 ,23, 8, 4};
    for(auto i : arr)
    {
        std::cout << i << " ";
    }
    sort(arr, Comp1);
    std::cout << std::endl;

    for(auto i : arr)
    {
        std::cout << i << ",";
    }
    return 0;
}