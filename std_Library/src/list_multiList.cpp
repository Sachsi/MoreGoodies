#include <iostream>
#include <list>
#include <forward_list>
/**
 * the list is a doubly linked list. It is a sequence container that allows constant time insert and erase operations 
 * anywhere within the sequence, and iteration in both directions.
 */
void list(){
    std::list<int> coll{1, 2, 4, 5 ,6 };
    for(int i = 0; i < 5; ++i)
    {
        coll.push_back(i);
        //std::cout << "size: " << coll.size() << std::endl;
    }
    std::cout << "edit first element: " << std::endl;
    coll.front() = 700;

    auto itr = coll.begin();
    while (itr != coll.end())
    {
        std::cout << *itr++ << ",";
    }
    std::cout << std::endl;
    std::cout << "push_front:" << std::endl;

    for(int i = 0; i < 5; ++i)
    {
        coll.push_front(i);
        //std::cout << "size: " << coll.size() << std::endl;
    }

    itr = coll.begin();
    while( itr != coll.end()){
        std::cout << *itr++ << ",";
    }
    std::cout << "\n" << "insert 2. element and erase the secend:" << std::endl;
    itr = coll.begin();
    coll.insert(itr, 100);
    coll.erase(++itr);
    coll.pop_back(); //remove the last element

    auto itr1 = coll.begin();
    while( itr1 != coll.end()){
        std::cout << *itr1++ << ",";
    }
}
/**
 * Forward list is a single linked list. It is a sequence container that allows constant time insert and 
 * erase operations anywhere within the sequence, and iteration in one direction.
 */
void forward_list()
{
    std::forward_list<int> coll;
    for(int i = 0; i < 10; ++i)
    {
        coll.push_front(i);
    }
    for(auto x : coll)
    {
        std::cout << x << ",";
    }
    coll.insert_after(coll.begin(), 100);
    auto itr = coll.begin();
    coll.erase_after(++itr);

    std::cout << "\n" << "After insert and erase: " << std::endl;
    for(auto x : coll)
    {
        std::cout << x << ",";
    }
}

int main(void)
{
    list();
    std::cout << "\n" << "Forward list: " << std::endl;
    forward_list();;
    return 0;
}