#include "..\inc\RemoteControle.h"

namespace RemoteControle
{

    SimpleRemoteControle::SimpleRemoteControle()
    {
        std::cout << "setting up RemoteControle" << std::endl;
    }

    void SimpleRemoteControle::setCommand(CommandInterface *command)
    {
        slot = command;
        std::cout << "Command has been set" << std::endl;
    }
    void SimpleRemoteControle::buttonWasPressed()
    {
        slot->execute();
        std::cout << "Button was pressed (executed command)" << std::endl;
    }
} // namespace RemoteControle