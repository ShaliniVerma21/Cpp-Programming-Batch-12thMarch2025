//Example 3: Using this in a Constructor to Differentiate Parameters

#include <iostream>
using namespace std;

class Person {
private:
    string name;

public:
    // Constructor with a parameter named the same as the member variable
    Person(string name) {
        this->name = name; // Use 'this' to differentiate between parameter and member variable
    }

    // Function to display the name
    void displayName() {
        cout << "Name: " << this->name << endl; // Display the name
    }
};

int main() {
    Person person("Alice"); // Create a Person object with name "Alice"
    person.displayName(); // Call the display function
    return 0;
}
