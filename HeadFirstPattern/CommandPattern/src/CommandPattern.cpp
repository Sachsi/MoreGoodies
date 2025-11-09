#include <iostream>
#include "../inc/interface.h"
#include "../inc/Light.h"
#include "../inc/RemoteControle.h"
#include "../inc/GarageDoor.h"

using namespace Commands;
using namespace LightCommand;
using namespace RemoteControle;
using namespace GarageDoorCommand;

int main(){
    std::cout << "Hello, Command Pattern World!" << std::endl;

    // Create RemoteControle Teste, this as the client
    // The remote controle is our invoker and will be assigned the command-object. It can do requests.
    SimpleRemoteControle remote = SimpleRemoteControle();
    // create a light object. This is the receiver
    Light light = Commands::Light();
    // create a garage door object. This is the receiver
    GarageDoor garageDoor = Commands::GarageDoor();

    // create a command object and pass the receiver to it.
    LightOnCommand lightOn = LightCommand::LightOnCommand(&light);
    GarageDoorOpenCommand garageOpen = GarageDoorCommand::GarageDoorOpenCommand(&garageDoor);

    // assign the command object to the invoker
    remote.setCommand(&lightOn);
    // simulate button press
    remote.buttonWasPressed();
    // assign the garage door command object to the invoker
    remote.setCommand(&garageOpen);
    remote.buttonWasPressed();

    return 1;
}


