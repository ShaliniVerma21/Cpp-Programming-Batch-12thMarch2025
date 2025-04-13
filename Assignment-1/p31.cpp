//5.Implement a Simple To-Do List

#include <iostream>
#include <string>
using namespace std;

int main() {
    const int MAX_TASKS = 100;
    string tasks[MAX_TASKS];
    int taskCount = 0, choice;

    do {
        cout << "\nTo-Do List\n1. Add Task\n2. View Tasks\n3. Remove Task\n4. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (taskCount < MAX_TASKS) {
                    cout << "Enter task: ";
                    cin.ignore();
                    getline(cin, tasks[taskCount++]);
                } else {
                    cout << "Task list is full." << endl;
                }
                break;
            case 2:
                cout << "Tasks:\n";
                for (int i = 0; i < taskCount; i++) {
                    cout << i + 1 << ". " << tasks[i] << endl;
                }
                break;
            case 3:
                int taskNumber;
                cout << "Enter task number to remove: ";
                cin >> taskNumber;
                if (taskNumber > 0 && taskNumber <= taskCount) {
                    for (int i = taskNumber - 1; i < taskCount - 1; i++) {
                        tasks[i] = tasks[i + 1];
                    }
                    taskCount--;
                    cout << "Task removed." << endl;
                } else {
                    cout << "Invalid task number." << endl;
                }
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
        }
    } while (choice != 4);
    return 0;
}