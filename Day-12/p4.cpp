//Weather Forecasting System

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cmath> // For mathematical functions

using namespace std;

// Enumeration for weather conditions
enum class WeatherCondition {
    SUNNY,
    CLOUDY,
    RAINY,
    SNOWY,
    WINDY
};

// Structure for daily weather data
struct DailyWeather {
    string date; // Date of the weather report
    double temperature; // Temperature in Celsius
    double humidity; // Humidity percentage
    WeatherCondition condition; // Weather condition

    // Constructor for DailyWeather
    DailyWeather(string d, double t, double h, WeatherCondition c)
        : date(d), temperature(t), humidity(h), condition(c) {}
};

// Base class for WeatherForecast
class WeatherForecast {
protected:
    vector<DailyWeather> forecasts; // Vector to store daily weather forecasts

public:
    // Function to add a daily weather forecast
    void addForecast(const DailyWeather& forecast) {
        forecasts.push_back(forecast);
    }

    // Function to calculate average temperature
    double calculateAverageTemperature() const {
        if (forecasts.empty()) return 0.0;
        double totalTemp = 0.0;
        for (const auto& forecast : forecasts) {
            totalTemp += forecast.temperature;
        }
        return totalTemp / forecasts.size();
    }

    // Function to display all forecasts
    void displayForecasts() const {
        cout << "Weather Forecasts:\n";
        for (const auto& forecast : forecasts) {
            cout << "Date: " << forecast.date
                 << ", Temperature: " << forecast.temperature << "°C"
                 << ", Humidity: " << forecast.humidity << "%"
                 << ", Condition: " << getWeatherConditionString(forecast.condition) << endl;
        }
    }

    // Function to get string representation of weather condition
    string getWeatherConditionString(WeatherCondition condition) const {
        switch (condition) {
            case WeatherCondition::SUNNY: return "Sunny";
            case WeatherCondition::CLOUDY: return "Cloudy";
            case WeatherCondition::RAINY: return "Rainy";
            case WeatherCondition::SNOWY: return "Snowy";
            case WeatherCondition::WINDY: return "Windy";
            default: return "Unknown";
        }
    }

    // Virtual destructor
    virtual ~WeatherForecast() {}
};

// Derived class for ExtendedWeatherForecast
class ExtendedWeatherForecast : public WeatherForecast {
public:
    // Function to display extended forecast summary
    void displayExtendedSummary() const {
        cout << "=== Extended Weather Summary ===\n";
        cout << "Average Temperature: " << fixed << setprecision(2) << calculateAverageTemperature() << "°C\n";
        cout << "Total Forecasts: " << forecasts.size() << endl;
    }
};

int main() {
    // Create an instance of ExtendedWeatherForecast
    ExtendedWeatherForecast myForecast;

    // Add daily weather forecasts
    myForecast.addForecast(DailyWeather("2023-10-01", 25.0, 60.0, WeatherCondition::SUNNY));
    myForecast.addForecast(DailyWeather("2023-10-02", 22.0, 70.0, WeatherCondition::CLOUDY));
    myForecast.addForecast(DailyWeather("2023-10-03", 18.0, 80.0, WeatherCondition::RAINY));
    myForecast.addForecast(DailyWeather("2023-10-04", -2.0, 90.0, WeatherCondition::SNOWY));
    myForecast.addForecast(DailyWeather("2023-10-05", 20.0, 50.0, WeatherCondition::WINDY));

    // Display all forecasts
    myForecast.displayForecasts();
    cout << endl;

    // Display extended summary
    myForecast.displayExtendedSummary();

    return 0;
}