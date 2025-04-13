//Problem 21: Fitness Class Management

#include <iostream>
#include <string>
using namespace std;

struct FitnessClass {
    string name;
    string instructor;
    string schedule;
};

void displayClasses(FitnessClass classes[], int count) {
    cout << "Class Name\tInstructor\tSchedule\n";
    for (int i = 0; i < count; i++) {
        cout << classes[i].name << "\t\t" << classes[i].instructor << "\t\t" << classes[i].schedule << endl;
    }
}

int main() {
    int n;
    cout << "Enter number of fitness classes: ";
    cin >> n;
    FitnessClass classes[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter class name, instructor, and schedule: ";
        cin >> classes[i].name >> classes[i].instructor >> classes[i].schedule;
    }
    displayClasses(classes, n);
    return 0;
}