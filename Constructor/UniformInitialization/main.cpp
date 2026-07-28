#include <iostream>

class Point{
    public:
        Point(int x, int y) : x(x), y(y) {}
        Point() : x(0), y(0) {}
        int getX() const { return x; }
        int getY() const { return y; }

        void print_point() const {
            std::cout << "x : " << x << std::endl;
            std::cout << "y : " << y << std::endl;
        }
    private:
        int x;
        int y;
};

struct Point2D{
    int x;
    int y;
};

void print_point(const Point2D& p){
    std::cout << "x : " << p.x << std::endl;
    std::cout << "y : " << p.y << std::endl;
}


int main(){
    
    Point p1{5, 10};
    Point p2(5.3, 10.3); // narrow conversion from double to int
    p1.print_point();
    p2.print_point();

    Point2D p3{5, 10};
    Point2D p4(5.3, 10.3); // narrow conversion from double to int
    print_point(p3);
    print_point(p4);

    
    int x[] (1, 3, 5.4, 5); // narrow conversion from double to int
    int b[] {1, 3, 7, 5}; // uniform initialization prevents narrowing conversions


    return 0;
}