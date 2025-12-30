#ifndef COMMANDS_H
#define COMMANDS_H

#include "../inc/interface.h"

namespace Commands{

    class Light{
        public:
            Light(std::string name)
            {
                this->name = name;
                std::cout << std::setw(20) << "Light is " << std::setw(20)  << name << std::endl;
            }
            bool On(){
                on = true;
                off = false;
                return on;
            }
            bool Off(){
                off = true;
                on = false;
                return off;
            }
        private:
            std::string name;
            bool on = false;
            bool off = true;
    };
    // class for GarageDoor
    class GarageDoor{
        private:
            bool open = false;
            bool close = true;
            bool light = false;
            bool stop = true;
            std::string name;
        public:
            GarageDoor(std::string name){
                this->name = name;
                std::cout << std::setw(20) << "GarageDoor is " << std::setw(20) << name << std::endl;
            }
            bool Up(){
                std::cout << std::setw(40) << "GarageDoor Up executed" <<  std::endl;
                open = true;
                close = false;
                stop = false;
                return open;
            }
            bool Down(){
                std::cout << std::setw(40) << "GarageDoor Down executed" << std::endl;
                close = true;
                open = false;
                stop = false;
                return close;
            }
            bool Stop(){
                stop = true;
                open = false;
                close = false;
                return stop;
            }
            bool LightOn(){
                light = true;
                return light;
            }
            bool LightOff(){
                light = false;
                return light;
            }
    };
    // class for Stereo
    class Stereo{
        private:
            bool on = false;
            bool off = true;
            std::string name;
        public:
            Stereo(std::string name){
                this->name = name;
                std::cout << std::setw(20) << "Stereo is " << std::setw(20) << name << std::endl;
            }
            bool On(){
                std::cout << std::setw(40) << "Steroe On executed" << std::endl;
                this->on = true;
                this->off = false;
                return on;
            }
            bool SetCD(){
                //std::cout << "Stereo is set for CD input" << std::endl;
                return true;
            }
            bool SetVolume(int volume){
                //std::cout << "Stereo volume set to " << volume << std::endl;
                return true;
            }
            bool Off(){
                std::cout << std::setw(40) << "Stereo Off executed" << std::endl;
                this->off = true;
                this->on = false;
                return off;;
            }

    };
}

#endif // COMMANDS_H