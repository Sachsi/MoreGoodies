#ifndef REMOTE_CONTROLE_H
#define REMOTE_CONTROLE_H

#pragma once
#include <iostream>
#include <array>
#include "..\inc\interface.h"

namespace RemoteControle
{
    using namespace Interface;

    class SimpleRemoteControle
    {
        CommandInterface *slot;
    public:
        SimpleRemoteControle();
        void setCommand(CommandInterface *command);
        void buttonWasPressed();
    };

        class RemoteControl{
        private:
            std::array<CommandInterface*, 7> onCommand;
            std::array<CommandInterface*, 7> offCommand;
        public:
            RemoteControl(){
                onCommand.fill(nullptr);
                offCommand.fill(nullptr);
            }
    };

} // namespace RemoteControle


#endif // REMOTE_CONTROLE_H
