#ifndef LIGHT_H
#define LIGHT_H

#include <iostream>
#include "../inc/interface.h"
#include "../inc/Commands.h"

namespace LightCommand
{
    using namespace Interface;
    using namespace Commands;

    class LightOnCommand : public CommandInterface
    {
        public:
            Light *light;

            LightOnCommand(Light *light){
                this->light = light;
                std::cout << "LightOnCommand created" << std::endl;
            }

            void execute() override{
                light->On();
                std::cout << "Light is On" << std::endl;
            }
    };
} // namespace LightCommand

#endif // LIGHT_H