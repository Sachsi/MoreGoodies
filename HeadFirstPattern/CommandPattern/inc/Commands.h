#ifndef COMMANDS_H
#define COMMANDS_H

#include "../inc/interface.h"

namespace Commands{

    class Light{
        public:
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
        public:
            bool Up(){
                open = true;
                close = false,
                stop = false;
                return open;
            }
            bool Down(){
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
        public:
            bool On(){
                this->on = true;
                this->off = false;
                return on;
            }
            bool SetCD(){
                std::cout << "Stereo is set for CD input" << std::endl;
                return true;
            }
            bool SetVolume(int volume){
                std::cout << "Stereo volume set to " << volume << std::endl;
                return true;
            }

    };
}

#endif // COMMANDS_H