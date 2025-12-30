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
    
    //--- creating all the devices (receivers) in their proper locations ---//
    std::cout << "\n--- Creating Receivers (devices) ---\n" << std::endl;
    // create a light object. This is the receiver
    Light kitchenLight = Commands::Light("Kitchen");
    Light livingRoomLight = Commands::Light("Living Room");
    // create a garage door object. This is the receiver
    GarageDoor garageDoor = Commands::GarageDoor("CarPort");
    // Create a stereo object. This is the receiver
    Stereo stereoCD = Commands::Stereo("Living Room Stereo");

    //--- creating all the Light command objects ---//
    std::cout << "\n--- Creating Command Objects for Lights ---\n" << std::endl;
    // create a command object and pass the receiver to it.
    LightOnCommand lightOn = LightCommand::LightOnCommand(&kitchenLight);
    LightOffCommand lightOff = LightCommand::LightOffCommand(&kitchenLight);
    LightOnCommand livingRoomLightOn = LightCommand::LightOnCommand(&livingRoomLight);
    LightOffCommand livingRoomLightOff = LightCommand::LightOffCommand(&livingRoomLight);
    
    //--- creating all the garage door command objects ---//
    std::cout << "\n--- Creating Command Objects ---\n" << std::endl;
    GarageDoorOpen garageOpen = GarageDoorCommand::GarageDoorOpen(&garageDoor);
    GarageDoorDown garageDown = GarageDoorCommand::GarageDoorDown(&garageDoor);

    //--- creating all the stereo command objects ---//
    std::cout << "\n--- Creating Command Objects for Stereo ---\n" << std::endl;
    StereoCommand::StereoOnWithCD stereoOn = StereoCommand::StereoOnWithCD(&stereoCD);
    StereoCommand::StereoOff stereoOff = StereoCommand::StereoOff(&stereoCD);

    //--- load all the commands objects into the remote controle slots ---//
    std::clog << "\n--- Assigning Command Objects to the Invoker ---\n" << std::endl;
    if (remote != nullptr){
        remote->setCommand(&lightOn);
        remote->setCommand(&garageOpen);
        remote->setCommand(&stereoOn);
        // simulate button press
        remote->buttonWasPressed();

        remote->buttonWasPressed();
    }
    else if (remote_2 != nullptr){
        remote_2->setCommand(0, &lightOn, &lightOff);
        remote_2->onButtonWasPushed(0);
        std::cout << remote_2->toString();
        remote_2->offButtonWasPushed(0);
        std::cout << remote_2->toString();
    }

    return 1;
}


