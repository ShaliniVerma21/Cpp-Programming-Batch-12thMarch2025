//Example 2: Using this to Return the Current Object

#include <iostream>
using namespace std;

class Counter {
private:
    int count;

public:
    // Constructor to initialize count
    Counter() : count(0) {}

    // Function to increment count and return the current object
    Counter& increment() {
        this->count++; // Increment the count
        return *this;  // Return the current object
    }

    // Function to display the count
    void displayCount() {
        cout << "Count: " << this->count << endl; // Display the count
    }
};

int main() {
    Counter counter; // Create a Counter object
    counter.increment().increment().displayCount(); // Chain method calls
    return 0;
}
