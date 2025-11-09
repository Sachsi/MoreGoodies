#pragma once
#ifndef GARAGE_DOOR_H
#define GARAGE_DOOR_H

#include <iostream>
#include "../inc/interface.h"
#include "../inc/Commands.h"

namespace GarageDoorCommand
{
    using namespace Interface;
    using namespace Commands;

    class GarageDoorOpenCommand : public CommandInterface
    {
        private:
            GarageDoor *garageDoor;
        public:
            GarageDoorOpenCommand(GarageDoor *garageDoor){
                this->garageDoor = garageDoor;
                std::clog << "GarageDoorOpenCommand created" << std::endl;
            }
            void execute() override{
                garageDoor->Up();
                std::clog << "Garage Door is Opened" << std::endl;
            }
    };
}

#endif // GARAGE_DOOR_H