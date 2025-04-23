
// Real-World Example: Days of the week.
#include <iostream>
using namespace std;

enum Day
{
    Sunday,
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday
};

int main()
{
    Day today = Wednesday;
    cout << "Day number: " << today << endl; // Output: 3
    return 0;
}
