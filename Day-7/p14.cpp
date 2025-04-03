//2. Temperature Conversion
#include <iostream>
using namespace std;

int main() {
    const int numDays = 7;
    float celsius[numDays], fahrenheit[numDays];

    // Input temperatures in Celsius
    cout << "Enter temperatures for " << numDays << " days in Celsius:\n";
    for (int i = 0; i < numDays; i++) {
        cout << "Day " << (i + 1) << ": ";
        cin >> celsius[i];
    }

    // Convert to Fahrenheit
    for (int i = 0; i < numDays; i++) {
        fahrenheit[i] = (celsius[i] * 9.0 / 5.0) + 32;
    }

    // Display results
    cout << "\nTemperatures in Fahrenheit:\n";
    for (int i = 0; i < numDays; i++) {
        cout << "Day " << (i + 1) << ": " << fahrenheit[i] << "°F\n";
    }

    return 0;
}