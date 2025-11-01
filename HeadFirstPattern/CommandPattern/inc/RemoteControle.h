#ifndef REMOTE_CONTROLE_H
#define REMOTE_CONTROLE_H

#pragma once
#include <iostream>
#include "..\inc\interface.h"

namespace RemoteControle
{
    using namespace Interface;

    class RemoteControle
    {
        CommandInterface *slot;
    public:
        RemoteControle();
        void setCommand(CommandInterface *command);
        void buttonWasPressed();
    };

} // namespace RemoteControle


#endif // REMOTE_CONTROLE_H
