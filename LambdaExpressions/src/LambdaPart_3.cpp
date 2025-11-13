#include <iostream>

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
class Product {
    std::string name;
    float price;
public:
    Product(const std::string &n, float p) : name(n), price(p){

    }
    void AssignFinalPrice(){
        float taxes[]{12, 5, 2};
        float basePrice{price};
        //this pointer has to be capture to modify the member price
        ForEach(taxes, [basePrice, this](float tax){
            float taxedPrice = basePrice * tax / 100;
            price += taxedPrice;
        });
    }
    float GetPrice()
    {
        return price;
    }
};
int main(void)
{
    //callbacks in c functions. it will works is the capture list is emty.
    //it converts lambda expression to a function pointer
    atexit([](){
        std::cout << "Programm is exiting..." << std::endl;
    });

    Product p("watch", 500);
    p.AssignFinalPrice();
    std::cout << p.GetPrice() << std::endl;

    //using lambda expression in another lambda expression
    [](int x){
        x = 2*x;
        [](int x){
            std::cout << "x: " << x << std::endl;
        }(x);
    }(5);
    return 0;
}