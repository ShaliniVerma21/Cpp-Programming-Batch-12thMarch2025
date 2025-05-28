/*
2. Simple To-Do List Application
   
This program allows users to manage a simple to-do list where they can add, remove, and view tasks.    
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class ToDoList {
private:
    vector<string> tasks;

public:
    void addTask(const string& task) {
        tasks.push_back(task);
        cout << "Task added: " << task << endl;
    }

    void removeTask(int index) {
        if (index < 0 || index >= tasks.size()) {
            cout << "Invalid task index!" << endl;
        } else {
            cout << "Task removed: " << tasks[index] << endl;
            tasks.erase(tasks.begin() + index);
        }
    }

    void viewTasks() const {
        cout << "To-Do List:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i] << endl;
        }
    }
};

int main() {
    ToDoList todo;
    int choice;
    string task;

    do {
        cout << "\n1. Add Task\n2. Remove Task\n3. View Tasks\n4. Exit\nChoose an option: ";
        cin >> choice;
        cin.ignore(); // Clear the newline character from the input buffer


        switch (choice) {
            case 1:
                cout << "Enter task: ";
                getline(cin, task);
                todo.addTask(task);
                break;
            case 2:
                todo.viewTasks();
                int index;
                cout << "Enter task number to remove: ";
                cin >> index;
                todo.removeTask(index - 1); // Convert to zero-based index
                break;
            case 3:
                todo.viewTasks();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 4);

    return 0;
}