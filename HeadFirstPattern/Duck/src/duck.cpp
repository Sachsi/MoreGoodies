#include <vector>
#include "duck.h"
#include "DecoyDuck.h"
#include "IFly.h"

#pragma region overwrite
//das verwenden von Vererbung funktiniert nicht immer gut auf Unterklassen das 
//sich diese ständig verändern können und es aber nicht immer für jede angemesen ist
namespace Duck::Natur
{
    class MallardDuck : public Duck::Base::Duck
    {
        public:
            MallardDuck(){
                std::cout << "MallardDuck created! " << std::endl;
            };
        
            ~MallardDuck(){
                std::cout << "MallardDuck destroyed! ";
            };
            void display() const override{
                std::cout << "MallardDuck is displayed! ";
            }
    };
    // Die Benutzung von Interface ermöglicht es, dass die Duck-Klasse nicht ständig verändert werden muss
    // aber bei jeder neuen Entität, die fliegen kann, das Interface implementiert werden muss.
    class RedHeadDuck : public Duck::Base::Duck, Duck::Fly::IFly
    {
        public:
            RedHeadDuck(){
                std::cout << "RedHeadDuck created! " << std::endl;
            };
            ~RedHeadDuck(){
                std::cout << "RedHeadDuck destroyed! ";
            };
            void display() const override{
                std::cout << "RedHeadDuck is displayed! ";
            }
            void fly() const override{ 
                std::cout << "ReadHeadDuck flies! ";
            }
    };

}
#pragma endregion
    int main(){
        std::cout << "Hello, Duck World!" << std::endl;
        Duck::Base::Duck duck{};
        Duck::Natur::MallardDuck mallard;
        Duck::Natur::RedHeadDuck redhead;
        Duck::Decoy::RubberDuck rubber;
        Duck::Decoy::DecoyDuck decoy;
        std::vector<Duck::Base::Duck*> ducks;
        ducks.push_back(&mallard);
        ducks.push_back(&redhead);
        ducks.push_back(&rubber);
        ducks.push_back(&decoy);
        
        for(const auto& duck : ducks){
            duck->display();
            duck->quack();
            duck->swim();
            duck->fly();
            std::cout << std::endl;
        }
        
        return 0;
    }
