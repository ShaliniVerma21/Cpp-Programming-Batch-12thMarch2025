//Sensor Data Management

#include <iostream>
#include <string>
#include <vector>
#include <iomanip> // For setting precision
#include <cmath> // For mathematical functions
#include <stdexcept> // For exception handling

using namespace std;

// Enumeration for sensor types
enum class SensorType {
    TEMPERATURE,
    HUMIDITY,
    PRESSURE,
    LIGHT
};

// Structure for sensor data
struct SensorData {
    SensorType type; // Type of the sensor
    double value; // Value recorded by the sensor
    string timestamp; // Timestamp of the data recording

    // Constructor for SensorData
    SensorData(SensorType t, double v, const string& ts) 
        : type(t), value(v), timestamp(ts) {}
};

// Base class for Sensor
class Sensor {
protected:
    string name; // Name of the sensor
    vector<SensorData> data; // List of sensor data

public:
    // Constructor for Sensor
    Sensor(const string& n) : name(n) {}

    // Function to add sensor data
    void addData(const SensorData& d) {
        data.push_back(d);
    }

    // Function to display sensor information
    virtual void displayInfo() const {
        cout << "Sensor Name: " << name << endl;
        cout << "Data Recorded:\n";
        for (const auto& d : data) {
            cout << "Type: " << getSensorTypeString(d.type) 
                 << ", Value: " << fixed << setprecision(2) << d.value 
                 << ", Timestamp: " << d.timestamp << endl;
        }
    }

    // Function to get string representation of sensor type
    string getSensorTypeString(SensorType type) const {
        switch (type) {
            case SensorType::TEMPERATURE: return "Temperature";
            case SensorType::HUMIDITY: return "Humidity";
            case SensorType::PRESSURE: return "Pressure";
            case SensorType::LIGHT: return "Light";
            default: return "Unknown";
        }
    }

    // Virtual destructor
    virtual ~Sensor() {}
};

// Derived class for TemperatureSensor
class TemperatureSensor : public Sensor {
public:
    // Constructor for TemperatureSensor
    TemperatureSensor(const string& n) : Sensor(n) {}

    // Function to display temperature sensor information
    void displayInfo() const override {
        cout << "Temperature Sensor Information:\n";
        Sensor::displayInfo();
    }
};

// Derived class for HumiditySensor
class HumiditySensor : public Sensor {
public:
    // Constructor for HumiditySensor
    HumiditySensor(const string& n) : Sensor(n) {}

    // Function to display humidity sensor information
    void displayInfo() const override {
        cout << "Humidity Sensor Information:\n";
        Sensor::displayInfo();
    }
};

// Derived class for PressureSensor
class PressureSensor : public Sensor {
public:
    // Constructor for PressureSensor
    PressureSensor(const string& n) : Sensor(n) {}

    // Function to display pressure sensor information
    void displayInfo() const override {
        cout << "Pressure Sensor Information:\n";
        Sensor::displayInfo();
    }
};

// Derived class for LightSensor
class LightSensor : public Sensor {
public:
    // Constructor for LightSensor
    LightSensor(const string& n) : Sensor(n) {}

    // Function to display light sensor information
    void displayInfo() const override {
        cout << "Light Sensor Information:\n";
        Sensor::displayInfo();
    }
};

int main() {
    // Create instances of different types of sensors
    TemperatureSensor tempSensor("TempSensor1");
    HumiditySensor humiditySensor("HumiditySensor1");
    PressureSensor pressureSensor("PressureSensor1");
    LightSensor lightSensor("LightSensor1");

    // Add data to temperature sensor
    tempSensor.addData(SensorData(SensorType::TEMPERATURE, 25.5, "2023-10-01 10:00:00"));
    tempSensor.addData(SensorData(SensorType::TEMPERATURE, 26.0, "2023-10-01 11:00:00"));

    // Add data to humidity sensor
    humiditySensor.addData(SensorData(SensorType::HUMIDITY, 60.0, "2023-10-01 10:00:00"));
    humiditySensor.addData(SensorData(SensorType::HUMIDITY, 65.0, "2023-10-01 11:00:00"));

    // Add data to pressure sensor
    pressureSensor.addData(SensorData(SensorType::PRESSURE, 1013.25, "2023- 10-01 10:00:00"));
    pressureSensor.addData(SensorData(SensorType::PRESSURE, 1012.80, "2023-10-01 11:00:00"));

    // Add data to light sensor
    lightSensor.addData(SensorData(SensorType::LIGHT, 300.0, "2023-10-01 10:00:00"));
    lightSensor.addData(SensorData(SensorType::LIGHT, 350.0, "2023-10-01 11:00:00"));

    // Display information for each sensor
    tempSensor.displayInfo();
    cout << endl;

    humiditySensor.displayInfo();
    cout << endl;

    pressureSensor.displayInfo();
    cout << endl;

    lightSensor.displayInfo();
    cout << endl;

    return 0;
}