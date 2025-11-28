#pragma once
#ifndef __STEREO_H__
#define __STEREO_H__
#include <iostream>
#include "../inc/Commands.h"

namespace StereoCommand
{
    class StereoOnWithCDCommand : public Commands::Stereo
    {
        private:
            Stereo *stereo;
        public:
            StereoOnWithCDCommand(Stereo *stereo){
                this->stereo = stereo;
                std::cout << "StereoOnWithCDCommand created" << std::endl;
            }
            void execute(){
                stereo->On();
                stereo->SetCD();
                stereo->SetVolume(11);
                std::cout << "Stereo is ON with CD and volume set to 11 " << std::endl;
            }

    };
} // namespace StereoCommand


#endif // __STEREO_H__