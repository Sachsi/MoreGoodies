#pragma once
#include <iostream>
#include "Observer.h"

namespace Subject
{
    using namespace Observer;
    // one to many relationship (Composition)
    class Subject
    {
    private:
        /* data */
    public:
        
        virtual void registerObserver(Observer::Observer* obs) = 0;
        virtual void removeObserver(Observer::Observer* obs) = 0;
        virtual void notifyObservers() = 0;
    };



    class WeatherDataBase
    {
        protected:
            float temperature{0.0f};
            float humidity{0.0f};
            float pressure{0.0f};
        public:
            virtual float getTemperature() const{
                std::cout << "Getting temperature data..." << std::endl;
                return temperature; // Assuming temperature is a member variable    
            }
            virtual float getHumidity() const{
                std::cout << "Getting humidity data..." << std::endl;
                return humidity; // Assuming humidity is a member variable    
            }
            virtual float getPressure() const{
                std::cout << "Getting pressure data..." << std::endl;
                return pressure; // Assuming pressure is a member variable    
            }
    };
}