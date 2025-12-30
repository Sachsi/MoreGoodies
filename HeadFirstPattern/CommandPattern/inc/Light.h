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
        private:
            Light *light;
        public:

            LightOnCommand(Light *light){
                this->light = light;
                std::cout << std::setw(40) << "LightOnCommand created" << std::endl;
            }

            void execute() override{
                light->On();
                std::cout << std::setw(40) << "Light is On" << std::endl;
            }

            std::string GetName() override{
                return "LightOnCommand";
            }
    };

    class LightOffCommand : public CommandInterface
    {
        private:
            Light *light;
        public:
            LightOffCommand(Light *light){
                this->light = light;
                std::cout << std::setw(40) << "LightOffCommand created" << std::endl;
            }
            void execute() override{
                light->Off();
                std::cout << std::setw(40) << "Light is Off" << std::endl;
            }
            std::string GetName() override{
                return "LightOffCommand";
            }
    };
} // namespace LightCommand

#endif // LIGHT_H