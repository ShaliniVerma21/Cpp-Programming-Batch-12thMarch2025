/*
3. Simple Weather Application (Mock Data)
   
This program simulates a weather application that provides weather information for a specific city. 
It uses mock data for demonstration purposes.    
*/

#include <iostream>
#include <string>
#include <map>
using namespace std;

class WeatherApp {
private:
    map<string, string> weatherData;

public:
    WeatherApp() {
        // Mock weather data
        weatherData["New York"] = "Sunny, 25°C";
        weatherData["Los Angeles"] = "Cloudy, 22°C";
        weatherData["Chicago"] = "Rainy, 18°C";
        weatherData["Houston"] = "Sunny, 30°C";
    }

    void getWeather(const string& city) const {
        auto it = weatherData.find(city);
        if (it != weatherData.end()) {
            cout << "Weather in " << city << ": " << it->second << endl;
        } else {
            cout << "Weather data not available for " << city << "." << endl;
        }
    }
};

int main() {
    WeatherApp app;
    string city;

    cout << "Enter city name to get weather information: ";
    getline(cin, city);
    app.getWeather(city);

    return 0;
}