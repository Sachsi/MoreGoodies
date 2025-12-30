#pragma once
#ifndef __STEREO_H__
#define __STEREO_H__
#include <iostream>
#include "../inc/Commands.h"

namespace StereoCommand
{
    using namespace Commands;
    using namespace Interface;

    class StereoOnWithCD : public CommandInterface
    {
        private:
            Stereo *pStereo;
        public:
            StereoOnWithCD(Stereo *pStereoCommand){
                this->pStereo = pStereoCommand;
                std::cout << std::setw(40) << "StereoOnWithCD command created" << std::endl;
            }

            void execute(){
                pStereo->On();
                pStereo->SetCD();
                pStereo->SetVolume(11);
                std::cout << std::setw(40) << "Stereo is ON with CD and volume set to 11 " << std::endl;
            }
            std::string GetName() override{
                return "StereoOnWithCD Command";
            }

    };

    class StereoOff : public CommandInterface
    {
        private:
            Stereo* pStereo;
        public:
            StereoOff(Stereo* pStereoCommand){
                this->pStereo = pStereoCommand;
                std::cout << std::setw(40) << "StereoOff command created" << std::endl;
            }
            void execute() override{
                this->pStereo->Off();
                std::cout << std::setw(40) << "Stereo is Off" << std::endl;
            }
            std::string GetName() override{
                return "StereoOff Command";
            }
    };
} // namespace StereoCommand


#endif // __STEREO_H__