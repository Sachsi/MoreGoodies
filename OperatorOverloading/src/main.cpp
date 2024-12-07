#include <iostream>
#include "Integer.h"

int main(void)
{
    Integer a(2), b(3);
    a.IntProp.siz = 3.5f;
    a.IntProp.value = 10;
    Integer::IntegerProporties prp(3, 10);

    std::cout << "size of int is: " << a.IntProp.siz.value() << std::endl;

    //a.IntProp.siz = prp.siz;
    //*b.pIntProp->siz = b.IntProp.siz.operator->();
    b.pIntProp = &prp;
    b.pIntProp->siz = a.IntProp.siz;

    Integer sum = a + b;
    std::cout << "sum ist: " << sum.GetValue() << std::endl;

    a = 4;

    return 1;
}