#include <iostream>
#include "../inc/interface.h"
#include "../inc/Light.h"
#include "../inc/RemoteControle.h"


using namespace Commands;
using namespace LightCommand;
using namespace RemoteControle;

int main(){
    std::cout << "Hello, Command Pattern World!" << std::endl;

    // Create RemoteControle Teste, this as the client
    // The remote controle is our invoker and will be assigned the command-object. It can do requests.
    RemoteControle::RemoteControle remote = RemoteControle::RemoteControle();
    // create a light object. This is the receiver
    Commands::Light light = Commands::Light();
    // create a command object and pass the receiver to it.
    LightCommand::LightOnCommand lightOn = LightCommand::LightOnCommand(&light);
    
    // assign the command object to the invoker
    remote.setCommand(&lightOn);
    // simulate button press
    remote.buttonWasPressed();

    return 1;
}


