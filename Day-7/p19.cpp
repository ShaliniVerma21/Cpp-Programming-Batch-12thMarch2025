//7. Storing and Displaying Employee Salaries
#include <iostream>
#include <string>
using namespace std;

int main() {
    const int numEmployees = 3;
    string names[numEmployees];
    float salaries[numEmployees];

    // Input employee names and salaries
    for (int i = 0; i < numEmployees; i++) {
        cout << "Enter name of employee " << (i + 1) << ": ";
        cin >> names[i];
        cout << "Enter salary for " << names[i] << ": ";
        cin >> salaries[i];
    }

    // Display employee details
    cout << "\nEmployee Salaries:\n";
    for (int i = 0; i < numEmployees; i++) {
        cout << "Employee: " << names[i] << ", Salary: $" << salaries[i] << endl;
    }

    return 0;
}