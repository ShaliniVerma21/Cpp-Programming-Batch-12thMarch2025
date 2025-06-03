// To-Do List Application using OOP, STL Containers, Iterators, Algorithms, Functors, and CRUD logic

#include <iostream>
#include <deque>
#include <algorithm>
#include <string>
#include <iomanip> // for formatting
using namespace std;

// Functor to sort tasks alphabetically
class SortByName {
public:
    bool operator()(const class Task &a, const class Task &b);
};

// Task class representing each to-do item
class Task {
private:
    string description;
    bool completed;

public:
    Task(string desc) : description(desc), completed(false) {}

    void markComplete() { completed = true; }

    bool isCompleted() const { return completed; }

    string getDescription() const { return description; }

    void display(int index) const {
        cout << setw(3) << index << ". "
             << (completed ? "[✔] " : "[ ] ")
             << description << endl;
    }

    friend class SortByName; // allow functor access
};

// Functor logic to sort by task description
bool SortByName::operator()(const Task &a, const Task &b) {
    return a.description < b.description;
}

// Display menu
void showMenu() {
    cout << "\n========== TO-DO LIST MENU ==========\n";
    cout << "1. Add Task\n";
    cout << "2. Mark Task as Complete\n";
    cout << "3. Remove Completed Tasks\n";
    cout << "4. Display All Tasks\n";
    cout << "5. Sort Tasks Alphabetically\n";
    cout << "6. Exit\n";
    cout << "=====================================\n";
    cout << "Enter your choice: ";
}

int main() {
    deque<Task> todoList;
    int choice;

    do {
        showMenu();
        cin >> choice;
        cin.ignore(); // ignore leftover newline

        switch (choice) {
            case 1: { // Create
                string desc;
                cout << "Enter task description: ";
                getline(cin, desc);
                if (!desc.empty())
                    todoList.push_back(Task(desc));
                else
                    cout << "Task cannot be empty!\n";
                break;
            }

            case 2: { // Update (Mark Complete)
                int index;
                if (todoList.empty()) {
                    cout << "No tasks available.\n";
                    break;
                }
                cout << "Enter task number to mark complete: ";
                cin >> index;
                if (index > 0 && index <= todoList.size())
                    todoList[index - 1].markComplete();
                else
                    cout << "Invalid task number.\n";
                break;
            }

            case 3: { // Delete (Remove completed)
                auto oldSize = todoList.size();
                todoList.erase(
                    remove_if(todoList.begin(), todoList.end(),
                              [](const Task &t) { return t.isCompleted(); }),
                    todoList.end());
                cout << (oldSize - todoList.size()) << " task(s) removed.\n";
                break;
            }

            case 4: { // Read (Display)
                if (todoList.empty()) {
                    cout << "No tasks to show.\n";
                } else {
                    cout << "\nCurrent Tasks:\n";
                    int i = 1;
                    for (auto it = todoList.begin(); it != todoList.end(); ++it)
                        it->display(i++);
                }
                break;
            }

            case 5: { // Sort using Functor
                if (todoList.empty()) {
                    cout << "No tasks to sort.\n";
                } else {
                    sort(todoList.begin(), todoList.end(), SortByName());
                    cout << "Tasks sorted alphabetically.\n";
                }
                break;
            }

            case 6:
                cout << "Exiting the application. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 6);

    return 0;
}
