#include <iostream>
#include <string>
#include <vector>

using namespace std;

// User-defined data type (struct)
struct Person {
    string name;
    int age;
};

// Function to display person details
void displayPerson(const Person& p) {
    cout << "Name: " << p.name << ", Age: " << p.age << endl;
}

int main() {
    // Fundamental data types
    int integerVar = 42;                // Integer
    float floatVar = 3.14f;             // Floating point
    double doubleVar = 2.718281828459;   // Double precision floating point
    char charVar = 'A';                  // Character
    bool boolVar = true;                 // Boolean

    // Output fundamental data types
    cout << "Integer: " << integerVar << endl;
    cout << "Float: " << floatVar << endl;
    cout << "Double: " << doubleVar << endl;
    cout << "Character: " << charVar << endl;
    cout << "Boolean: " << (boolVar ? "true" : "false") << endl;

    // Derived data types
    int arrayVar[5] = {1, 2, 3, 4, 5};  // Array
    vector<int> vectorVar = {6, 7, 8, 9, 10}; // Vector (from STL)

    // Output array
    cout << "Array: ";
    for (int i = 0; i < 5; i++) {
        cout << arrayVar[i] << " ";
    }
    cout << endl;

    // Output vector
    cout << "Vector: ";
    for (int num : vectorVar) {
        cout << num << " ";
    }
    cout << endl;

    // User-defined data type
    Person person1;
    person1.name = "Alice";
    person1.age = 30;

    Person person2;
    person2.name = "Bob";
    person2.age = 25;

    // Display person details
    cout << "Person 1: ";
    displayPerson(person1);
    cout << "Person 2: ";
    displayPerson(person2);

    return 0;
}