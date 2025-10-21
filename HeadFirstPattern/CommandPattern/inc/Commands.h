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
}

#endif // COMMANDS_H