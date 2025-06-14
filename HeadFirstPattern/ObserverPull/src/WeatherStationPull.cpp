#include <iostream>
#include <vector>

#include "Observer.h"
#include "Subject.h"
#include "DisplayElement.h"

namespace WeatherStationPull
{
    using namespace Subject;
    using namespace Observer;
    using namespace DisplayElement;

    // this is pull model, so that the object can decide when its want to get the data
    // inherted class should implemted with public just to be public. Without public they will be private implemented
    class WeatherData : public Subject, public WeatherDataBase {
        // protected:
        // float temperature{0.0f};
        // float humidity{0.0f};
        // float pressure{0.0f};
        
        std::vector<Observer::Observer*> observers; // List of observers
        public:
            WeatherData(){
                std::cout << "WeatherData constructor called" << std::endl;
                
                observers.reserve(10); // Reserve space for 10 observers, for example
            }
            ~WeatherData(){
                std::cout << "WeatherData destructor called" << std::endl;
            }
            void registerObserver(Observer::Observer* obs) override{
                // Register the observer
                observers.emplace_back(obs);
                std::cout << "Registering observer..." << std::endl;
            }
            void removeObserver(Observer::Observer* obs) override{
                // Remove the observer
                for(auto it = observers.begin(); it != observers.end(); ++it) {
                    if (*it == obs) {
                        observers.erase(it);
                        break;
                    }
                }
                std::cout << "Removing observer..." << std::endl;
            }
            void notifyObservers() override{
                // // Notify all registered observers
                // std::cout << "Notifying observers..." << std::endl;
                // for (Observer* obs : observers) {
                //     obs->update(temperature, humidity, pressure);
                // }
            }
            void setMeasurements(float temp, float hum, float pres) {
                temperature = temp;
                humidity = hum;
                pressure = pres;
                notifyObservers();
            }

    };

    class CurrentConditionsDisplay : public Observer, DisplayElement {
        private:
            float temperature{0.0f};
            float humidity{0.0f};
            float pressure{0.0f};
            WeatherData* weatherData; // Reference to WeatherData
        public:
            CurrentConditionsDisplay(WeatherData* weatherData) : weatherData(weatherData){
                weatherData->registerObserver(this); // Register this display as an observer
                std::cout << "CurrentConditionsDisplay constructor called" << std::endl;
            }
            ~CurrentConditionsDisplay() {
                std::cout << "CurrentConditionsDisplay destructor called" << std::endl;
            }
            void update() override {
                temperature = weatherData->getTemperature(); // Pull data from WeatherData
                humidity = weatherData->getHumidity();    // Pull data from WeatherData
                pressure =  weatherData->getPressure();
                display(); // Call display to show updated conditions
            }
            void display() override {
                std::cout << "Current conditions: "
                        << "Temperature: " << temperature
                        << ", Humidity: " << humidity
                        << ", Pressure: " << pressure << std::endl;
            }
    };
    class StatisticDisplay : public Observer, DisplayElement {
        private:
            float temperature{0.0f};
            float humidity{0.0f};
            float pressure{0.0f};
        protected:
            WeatherData* weatherData; // Reference to WeatherData
        public:
            StatisticDisplay(WeatherData* weatherData) : weatherData(weatherData){
                weatherData->registerObserver(this); // Register this display as an observer
                std::cout << "StatisticDisplay constructor called" << std::endl;
            }
            ~StatisticDisplay() {
                std::cout << "StatisticDisplay destructor called" << std::endl;
            }
            void update() override {
                temperature = weatherData->getTemperature(); // Pull data from WeatherData
                humidity = weatherData->getHumidity();    // Pull data from WeatherData
                pressure =  weatherData->getPressure();
                display(); // Call display to show updated statistics
            }
            void display() override {
                std::cout << "Statistic Values: "
                        << "Temperature Max: " << temperature
                        << ", Humidity Max: " << humidity
                        << ", Pressure Max: " << pressure << std::endl;
            }
    };

    int main(void)
    {
        WeatherData weatherData;
        CurrentConditionsDisplay currentDisplay(&weatherData);
        StatisticDisplay statisticDisplay(&weatherData);

        weatherData.setMeasurements(30.0f, 65.0f, 30.4f);
        
        weatherData.setMeasurements(28.0f, 70.0f, 29.2f);
        weatherData.setMeasurements(26.0f, 90.0f, 29.2f);

        currentDisplay.update(); // Manually trigger update to pull data
        return 0;
    }
}
int main(void)
{
    return WeatherStationPull::main();
}