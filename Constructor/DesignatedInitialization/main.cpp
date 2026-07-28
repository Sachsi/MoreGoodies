#include <iostream>

struct point{
    double x;
    double y;
    double z;
};

void print_point(const point& p){
    std::cout << "x : " << p.x << std::endl;
    std::cout << "y : " << p.y << std::endl;
    std::cout << "z : " << p.z << std::endl;
}

int main(){
    point p1{.x = 5.7, .y = 8.2, .z = 5.2};
    point p2{.x = 1.0, .z = 5.6};
    point p3{.y = 2.6, .z = 3.1};

    // Designated initialization is a C++20 feature
    // The order of the members does not matter, but the names must match
    // point p4{.z = 4.9, .y = 7.4, .x = 2.5}; //

    print_point(p1);
    print_point(p2);
    print_point(p3);
    
    return 0;
}