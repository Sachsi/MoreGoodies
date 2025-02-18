#include <iostream>
#include <deque>

/**
 * deque is a double-ended queue. Is a sequence container with dynamic sizes that can be 
 * expanded or contracted on both ends. It is similar to vector, but it allows fast insertion.
 */
void deque(){
    std::deque<int> coll{1, 2, 4, 5 ,6 };
    for(int i = 0; i < 5; ++i)
    {
        coll.push_back(i);
        //std::cout << "size: " << coll.size() << std::endl;
    }
    std::cout << "edit first element: " << std::endl;
    coll[0] = 700;
    std::cout << "push_front:" << std::endl;

    for(int i = 0; i < 5; ++i)
    {
        coll.push_front(i);
        //std::cout << "size: " << coll.size() << std::endl;
    }

    auto itr = coll.begin();
    while( itr != coll.end()){
        std::cout << *itr++ << std::endl;
    }
    std::cout << "insert 2. element and erase twice the last:" << std::endl;
    coll.insert(coll.begin() + 1 , 100);
    coll.erase(coll.end()-1);
    coll.pop_back(); //remove the last element

    auto itr1 = coll.begin();
    while( itr1 != coll.end()){
        std::cout << *itr1++ << std::endl;
    }
}

int main(void)
{
    deque();;
    return 0;
}