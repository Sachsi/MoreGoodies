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

    // RemoteControl class implementation
    
    RemoteControl::RemoteControl()
    {
        onCommand.fill(nullptr);
        offCommand.fill(nullptr);

        CommandInterface* NoCommand = nullptr;
        for (int i = 0; i < 7; i++){
            onCommand[i] = NoCommand;
            offCommand[i] = NoCommand;
        }
        
        std::cout << "RemoteControle with 7 slots created" << std::endl;
    }

} // namespace RemoteControle