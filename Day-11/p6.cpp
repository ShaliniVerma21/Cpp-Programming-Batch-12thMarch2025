// Real-World Example: Traffic light states.

#include <iostream>
using namespace std;

enum class TrafficLight
{
    Red,
    Yellow,
    Green
};

int main()
{
    TrafficLight light = TrafficLight::Green;
    if (light == TrafficLight::Green)
    {
        cout << "Go!" << endl;
    }
    return 0;
}