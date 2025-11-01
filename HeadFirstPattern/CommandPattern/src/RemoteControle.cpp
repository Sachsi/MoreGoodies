#include "..\inc\RemoteControle.h"
#include "..\inc\RemoteControle.h"

namespace RemoteControle
{

RemoteControle::RemoteControle::RemoteControle()
{
    std::cout << "setting up RemoteControle" << std::endl;
}

void RemoteControle::setCommand(CommandInterface *command)
{
    slot = command;
    std::cout << "Command has been set" << std::endl;
}
void RemoteControle::buttonWasPressed()
{
    slot->execute();
    std::cout << "Button was pressed (executed command)" << std::endl;
}
} // namespace RemoteControle