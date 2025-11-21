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
        RemoteControl();
        void setCommand(int slot, CommandInterface* onCommand, CommandInterface* offCommand);
        void onButtonWasPushed(int slot);
        void offButtonWasPushed(int slot);
        std::string toString();
    };
} //namespace RemoteControle


#endif // REMOTE_CONTROLE_H
