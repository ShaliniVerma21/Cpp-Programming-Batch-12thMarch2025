//8. Creating a Simple To-Do List
#include <iostream>
#include <string>
using namespace std;

int main() {
    const int maxTasks = 5;
    string tasks[maxTasks];

    // Input tasks
    cout << "Enter " << maxTasks << " tasks for your to-do list:\n";
    for (int i = 0; i < maxTasks; i++) {
        cout << "Task " << (i + 1) << ": ";
        cin.ignore();
        getline(cin, tasks[i]);
    }

    // Display to-do list
    cout << "\nYour To-Do List:\n";
    for (int i = 0; i < maxTasks; i++) {
        cout << (i + 1) << ". " << tasks[i] << endl;
    }

    return 0;
}