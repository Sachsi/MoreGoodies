#include <iostream>

//the size of the union is the largest type in the union
union Test
{
    int x;
    char ch;
    double d;
    Test(): ch{'a'}{
        std::cout << "__FUNCSIG__" << std::endl;
    }
    ~Test(){
        std::cout << "__FUNCSIG__" << std::endl;
    }
};

int main(void){
    std::cout << sizeof(Test) << std::endl;

    Test t;
    std::cout << t.ch << std::endl;

    t.x = 100;

    std::cout << t.ch << std::endl;
}
