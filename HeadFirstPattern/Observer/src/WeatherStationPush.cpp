#include <iostream>
#include <vector>

#include "Observer.h"
#include "Subject.h"
#include "DisplayElement.h"

// not a good pattern which is not easy to maintain
// class CurrentConditionsDisplay
// {
//     private:
//         // Private members can be added here, such as temperature, humidity, pressure, etc.
//         // For example:
//         float temperature{0.0f};
//         float humidity{0.0f};
//         float pressure{0.0f};
//     public:
//         void update(float temp, float hum, float pres){
//             temperature = temp;
//             humidity = hum;
//             pressure = pres;
//         }
// };

// class WeatherData
// {
// private:
//     // Private members can be added here, such as temperature, humidity, pressure, etc.
//     // For example:
//     float temperature;
//     float humidity;
//     float pressure;
//     CurrentConditionsDisplay* display; // Observer object as a member variable
// public:
//     WeatherData(CurrentConditionsDisplay* obs){
//         display = obs;
//         std::cout << "WeatherData constructor called" << std::endl;
//     }
//     ~WeatherData()
//     {
//         std::cout << "WeatherData destructor called" << std::endl;
//     }
//     float getTemperature() const{
//         std::cout << "Getting temperature data..." << std::endl;
//         return temperature; // Assuming temperature is a member variable
//     }
//     float getHunidity() const{
//         std::cout << "Getting humidity data..." << std::endl;
//         return humidity; // Assuming humidity is a member variable
//     }
//     float getPressure() const{
//         std::cout << "Getting pressure data..." << std::endl;
//         return pressure; // Assuming pressure is a member variable
//     }
//     void measurementsChanged() const{
//         float temp = getTemperature();
//         float gum = getHunidity();
//         float pres = getPressure();
//         // Notify observers with the new measurements        
//         display->update(temp, gum, pres);
//         std::cout << "Measurements changed, notifying observers..." << std::endl;
//     }
// };
class WeatherData : public Subject{
    float temperature{0.0f};
    float humidity{0.0f};
    float pressure{0.0f};
    std::vector<Observer*> observers; // List of observers
    public:
        WeatherData(){
            std::cout << "WeatherData constructor called" << std::endl;
            
            observers.reserve(10); // Reserve space for 10 observers, for example
        }
        ~WeatherData(){
            std::cout << "WeatherData destructor called" << std::endl;
        }
        float getTemperature() const{
            std::cout << "Getting temperature data..." << std::endl;
            return temperature; // Assuming temperature is a member variable
        }
        float getHumidity() const{
            std::cout << "Getting humidity data..." << std::endl;
            return humidity; // Assuming humidity is a member variable
        }
        float getPressure() const{
            std::cout << "Getting pressure data..." << std::endl;
            return pressure; // Assuming pressure is a member variable
        }
        void registerObserver(Observer* obs) override{
            // Register the observer
            observers.emplace_back(obs);
            std::cout << "Registering observer..." << std::endl;
        }
        void removeObserver(Observer* obs) override{
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
            // Notify all registered observers
            std::cout << "Notifying observers..." << std::endl;
            for (Observer* obs : observers) {
                obs->update(temperature, humidity, pressure);
            }
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
        void update(float temp, float hum, float pres) override {
            temperature = temp;
            humidity = hum;
            pressure = pres;
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
        WeatherData* weatherData; // Reference to WeatherData
    public:
        StatisticDisplay(WeatherData* weatherData) : weatherData(weatherData){
            weatherData->registerObserver(this); // Register this display as an observer
            std::cout << "StatisticDisplay constructor called" << std::endl;
        }
        ~StatisticDisplay() {
            std::cout << "StatisticDisplay destructor called" << std::endl;
        }
        void update(float temp, float hum, float pres) override {
            temperature = temp;
            humidity = hum;
            pressure = pres;
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
    return 0;
}