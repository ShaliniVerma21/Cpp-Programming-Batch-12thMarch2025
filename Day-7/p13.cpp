//Real World Examples

//1. Average of Student Grades
#include <iostream>
using namespace std;

int main() {
    const int numStudents = 5;
    float grades[numStudents];
    float sum = 0.0;

    // Input grades
    cout << "Enter grades for " << numStudents << " students:\n";
    for (int i = 0; i < numStudents; i++) {
        cout << "Student " << (i + 1) << ": ";
        cin >> grades[i];
        sum += grades[i];
    }

    // Calculate average
    float average = sum / numStudents;
    cout << "Average grade: " << average << endl;

    return 0;
}