//2. Using <cstdlib> for Random Number Generation

#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed for random number generation
    int randomNum = rand() % 100; // Random number between 0 and 99
    cout << "Random number: " << randomNum << endl;

    return 0;
}