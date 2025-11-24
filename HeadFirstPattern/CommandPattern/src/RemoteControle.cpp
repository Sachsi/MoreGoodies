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
    void RemoteControl::setCommand(int slot, CommandInterface* onCommand, CommandInterface* offCommand)
    {
        this->onCommand[slot] = onCommand;
        this->offCommand[slot] = offCommand;
    }
    void RemoteControl::onButtonWasPushed(int slot)
    {
        this->onCommand[slot]->execute();
    }
    void RemoteControl::offButtonWasPushed(int slot)
    {
        this->offCommand[slot]->execute();
    }
    std::string RemoteControl::toString()
    {
        std::string stringBuffer;
        stringBuffer.append("\n------ Remote Control -------\n");
        for (int i = 0; i < 7; i ++){
            stringBuffer.append("[slot " + std::to_string(i) + "] ");
            stringBuffer.append(typeid(onCommand[i]).name());
            stringBuffer.append("   ");
            stringBuffer.append(typeid(offCommand[i]).name());
            stringBuffer.append("\n");
        }
        return stringBuffer;
    }

} // namespace RemoteControle