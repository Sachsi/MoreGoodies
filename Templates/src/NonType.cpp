#include <iostream>


//no type template. Non type arguments are used for classes
template<int size>
void Print()
{
    //non type argumente are alwayse konstant arguments. not modifable.
    //size++;
    //non type arg are used for array. 
    char buffer[size];
    std::cout << size << std::endl;;
}

template<typename T>
T Sum(T *parr, int size){
    T sum{};
    for(int i = 0; i < size; ++i){
        sum += parr[i];
    }
    return sum;
}

template<typename T, int size>
T Sum(T (&parr)[size]){
    T sum{};
    for(int i = 0; i < size; ++i){
        sum += parr[i];
    }
    return sum;
}

//#ifdef NON_TYPE_ARG
int main(void)
{
    int i = 4;
    int arr[]{23, 34 ,54, 56};
    //a refereze to an array keeps the pointer and size as well
    int (&ref)[4] = arr;
    std::cout << ref[1] << std::endl;
    //can not use as a non type arguemnt because is not static
    //Print<i>();
    //mit sizeof() würde zur kompile Zeit eine statischer 
    //Wert berechnet der akzeptiert wird
    Print<sizeof(i)>();
    Print<3>();

    int sum = Sum(arr, 4);
    std::cout << sum << std::endl;
    sum = Sum(arr);
    std::cout << sum << std::endl;
    return 1;
}
//#endif