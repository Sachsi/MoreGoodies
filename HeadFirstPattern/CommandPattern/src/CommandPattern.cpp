#include <iostream>
#include "../inc/interface.h"
#include "../inc/Light.h"
#include "../inc/RemoteControle.h"
#include "../inc/GarageDoor.h"
#include "../inc/Stereo.h"

#define SIMPLEREMOTECONTROLE_TEST 0
#define REMOTECONTROL_TEST 1

using namespace Commands;
using namespace LightCommand;
using namespace RemoteControle;
using namespace GarageDoorCommand;

int main(){
    std::cout << "Hello, Command Pattern World!" << std::endl;

    // Create RemoteControle Teste, this as the client
    SimpleRemoteControle *remote = nullptr;
    RemoteControl *remote_2 = nullptr;
    // The remote controle is our invoker and will be assigned the command-object. It can do requests.
    if (SIMPLEREMOTECONTROLE_TEST == 1)
        remote = new SimpleRemoteControle();
    else if (REMOTECONTROL_TEST == 1)
        remote_2 = new RemoteControl();
    
    // create a light object. This is the receiver
    Light light = Commands::Light("Kitchen");
    // create a garage door object. This is the receiver
    GarageDoor garageDoor = Commands::GarageDoor();

    // create a command object and pass the receiver to it.
    LightOnCommand lightOn = LightCommand::LightOnCommand(&light);
    LightOffCommand lightOff = LightCommand::LightOffCommand(&light);
    
    GarageDoorOpenCommand garageOpen = GarageDoorCommand::GarageDoorOpenCommand(&garageDoor);

    // assign the command object to the invoker
    if (remote != nullptr){
        remote->setCommand(&lightOn);
        // simulate button press
        remote->buttonWasPressed();
        // assign the garage door command object to the invoker
        remote->setCommand(&garageOpen);
        remote->buttonWasPressed();
    }
    else if (remote_2 != nullptr){
        remote_2->setCommand(0, &lightOn, &lightOff);
        remote_2->onButtonWasPushed(0);
        remote_2->offButtonWasPushed(0);
    }

    return 1;
}


