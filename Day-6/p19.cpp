//4. Using <ctime> for Date and Time
#include <iostream>
#include <ctime> // For time functions
using namespace std;

int main() {
    time_t now = time(0); // Get current time
    char* dt = ctime(&now); // Convert to string

    cout << "The current local time is: " << dt << endl;

    return 0;
}