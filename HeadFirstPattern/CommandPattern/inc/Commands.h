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
}

#endif // COMMANDS_H