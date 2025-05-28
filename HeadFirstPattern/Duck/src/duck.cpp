
#include "duck.h"
#pragma region overwrite

namespace Duck::Natur
{
    class MallardDuck : public Duck::Base::Duck
    {
        public:
            MallardDuck(){
                std::cout << "MallardDuck created!" << std::endl;
            };
        
            ~MallardDuck(){
                std::cout << "MallardDuck destroyed!" << std::endl;
            };
    };

    class RedHeadDuck : public Duck::Base::Duck
    {
        public:
            RedHeadDuck(){
                std::cout << "RedHeadDuck created!" << std::endl;
            };
            ~RedHeadDuck(){
                std::cout << "RedHeadDuck destroyed!" << std::endl;
            };
    };

#pragma endregion
    int main(){
        std::cout << "Hello, Duck World!" << std::endl;
        MallardDuck mallard;
        RedHeadDuck redhead;
        mallard.quack();
        redhead.swin();
        
        return 0;
    }
}