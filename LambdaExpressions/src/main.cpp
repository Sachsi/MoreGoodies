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
#ifdef FUNCTIONOBJECT
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
#endif

template<typename T>
struct Unnamed{
    T operator()(T x, T y)const{
        return x + y;
    }
};

#ifdef FUNCTIONOBJECT
int main(void)
{

    Comp(2, 4);     //global function
    Comp2 comp;     //member function call
    comp(3, 4);     // comp.operator()()

    int arr[]{1 ,3, 9 ,23, 8, 4};
    for(auto i : arr)
    {
        std::cout << i << " ";
    }
    sort(arr, comp);
    std::cout << std::endl;

    for(auto i : arr)
    {
        std::cout << i << ",";
    }
    return 0;
}
#endif
#ifdef LAMBDA
int main(void){

//an lambda is an nameless functions
//[](args)<Mutable Specifiactiona><excp specification>  -> <return type> {lambda body}
    [](){
        std::cout << "Welcome to Lambda expresions " << std::endl;
    }(); //<- the brackes will invoke the lambda expression
    auto fn = [](){
        std::cout << "anonther lambda expression:" << std::endl;
    };  // this lambda expression has a name fn
    fn(); //and we can invoke it like this
    //the lambda expression type is
    std::cout << "type: " << typeid(fn).name() << std::endl;
    //the return type have to be the same like the args otherise it has to define
    auto sum = [](auto x, auto y) noexcept(false) {
        return x + y;
    };
    Unnamed<int> n;
    std::cout << "sum: " << sum(5.3f, 3.3f) << std::endl;
    std::cout << "sum Unnamed: " << n(3, 8) << std::endl;
    return 1;
}
#endif //LAMBDA