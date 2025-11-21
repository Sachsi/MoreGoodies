#ifndef COMMANDPATTERN_INTERFACE_H
#define COMMANDPATTERN_INTERFACE_H

#include <iostream>

namespace Interface
{
    class CommandInterface{
        public:
            //virtual ~Command() = default;
            virtual void execute() = 0;
            //virtual void noCommand() = 0;
    };
    
} // namespace CommandInterface

#endif // COMMANDPATTERN_INTERFACE_H