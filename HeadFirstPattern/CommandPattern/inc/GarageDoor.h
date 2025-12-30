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
                std::cout << std::setw(40) << "GarageDoorOpen command created" << std::endl;
            }
            void execute() override{
                garageDoor->Up();
                std::cout << std::setw(40) << "Garage Door is Opened" << std::endl;
            }
            std::string GetName() override{
                return "GarageDoorOpen";
            }
    };

    class GarageDoorDown : public CommandInterface
    {
        private:
            GarageDoor *garageDoor;
        public:
            GarageDoorDown(GarageDoor* pGarageDoorCommand){
                this->garageDoor = pGarageDoorCommand;
                std::cout << std::setw(40) << "GarageDoorDown command created" << std::endl;
            }

            void execute() override{
                //garage Door->Down();
                this->garageDoor->Down();
                std::cout << std::setw(40) << "Garage Door is Closed" << std::endl;
            }
            std::string GetName() override{
                return "GarageDoorDown";
            }
    };
}

#endif // GARAGE_DOOR_H