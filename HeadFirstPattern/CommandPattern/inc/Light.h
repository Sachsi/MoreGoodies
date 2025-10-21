#ifndef LIGHT_H
#define LIGHT_H

#include <iostream>
#include "../inc/interface.h"

namespace LightCommand
{
    using namespace CommandInterface;

    class LightOnCommand : public CommandInterface
    {
        public:
            Light *light;

            LightOnCommand(Light *light){
                this->light = light;
            }

            void execute() override{
                light->on();
            }
    };
} // namespace LightCommand

#endif // LIGHT_H