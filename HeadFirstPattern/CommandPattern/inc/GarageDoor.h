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

    class GarageDoorOpen : public CommandInterface
    {
        private:
            GarageDoor *garageDoor;
        public:
            GarageDoorOpen(GarageDoor *pgarageDoorCommand){
                this->garageDoor = pgarageDoorCommand;
                std::clog << "GarageDoorOpen created" << std::endl;
            }
            void execute() override{
                garageDoor->Up();
                std::clog << "Garage Door is Opened" << std::endl;
            }
    };

    class GarageDoorDown : public CommandInterface
    {
        private:
            GarageDoor *garageDoor;
        public:
            GarageDoorDown(GarageDoor* pGarageDoorCommand){
                this->garageDoor = pGarageDoorCommand;
                std::clog << "GarageDoorDown command created" << std::endl;
            }

            void execute() override{
                //garage Door->Down();
                this->garageDoor->Down();
                std::cout << "Garage Door is Closed" << std::endl;
            }
    };
}

#endif // GARAGE_DOOR_H