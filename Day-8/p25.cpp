//Student Grade Calculator

#include <iostream>
using namespace std;

int main() {
    int marks[5];
    int total = 0;

    cout << "Enter marks for 5 subjects: \n";
    for (int i = 0; i < 5; i++) {
        cin >> marks[i];
        total += marks[i];
    }

    float average = total / 5.0;

    cout << "Total Marks: " << total << endl;
    cout << "Average: " << average << endl;

    if (average >= 90) cout << "Grade: A\n";
    else if (average >= 75) cout << "Grade: B\n";
    else if (average >= 50) cout << "Grade: C\n";
    else cout << "Grade: F\n";

    return 0;
}
