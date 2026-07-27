#include <iostream>
#include <cassert>

struct Point{
public:
    Point(std::initializer_list<double> list){
        // is not a compile time check, but a runtime check. It will throw an exception if the condition is not met.
        //static_assert( (list_size() == 2));
        // this is a runtime check, it will throw an exception if the condition is not met.
        assert(list.size() == 2);
        /*
        std::cout << "Initializer list constructor called" << std::endl;

        std::cout << list.size() << " elements in the list" << std::endl;

        for(size_t i{}; i < list.size(); ++i){
            std::cout << "Element " << i << ": " << *(list.begin() + i) << std::endl;
        }
        */
        x = *(list.begin());
        y = *(list.begin() + 1);
    }

    void print_point()
    {
        std::cout << "Point [ x : " << x << ", y : " << y << "]" << std::endl;
    }
private:
    double x;
    double y;
};



int main()
{
    Point p1{22.4, 65.4, 3}; // Aggregate initialization
    p1.print_point();
    return 0;
}