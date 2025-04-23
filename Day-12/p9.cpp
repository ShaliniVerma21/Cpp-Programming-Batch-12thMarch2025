//Task Management System

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm> // For std::sort

using namespace std;

// Enumeration for task priority levels
enum class PriorityLevel {
    LOW,
    MEDIUM,
    HIGH
};

// Structure for a task
struct Task {
    string title; // Title of the task
    string description; // Description of the task
    PriorityLevel priority; // Priority level of the task
    bool isCompleted; // Completion status of the task

    // Constructor for Task
    Task(string t, string d, PriorityLevel p) 
        : title(t), description(d), priority(p), isCompleted(false) {}

    // Function to mark the task as completed
    void completeTask() {
        isCompleted = true;
    }
};

// Base class for TaskManager
class TaskManager {
protected:
    vector<Task> tasks; // List of tasks

public:
    // Function to add a task
    void addTask(const Task& task) {
        tasks.push_back(task);
    }

    // Function to display all tasks
    void displayTasks() const {
        cout << "Task List:\n";
        for (const auto& task : tasks) {
            cout << "Title: " << task.title 
                 << ", Description: " << task.description 
                 << ", Priority: " << getPriorityString(task.priority) 
                 << ", Status: " << (task.isCompleted ? "Completed" : "Pending") << endl;
        }
    }

    // Function to mark a task as completed
    void completeTask(const string& title) {
        for (auto& task : tasks) {
            if (task.title == title && !task.isCompleted) {
                task.completeTask();
                cout << "Task '" << title << "' marked as completed.\n";
                return;
            }
        }
        cout << "Task '" << title << "' not found or already completed.\n";
    }

    // Function to get string representation of priority level
    string getPriorityString(PriorityLevel level) const {
        switch (level) {
            case PriorityLevel::LOW: return "Low";
            case PriorityLevel::MEDIUM: return "Medium";
            case PriorityLevel::HIGH: return "High";
            default: return "Unknown";
        }
    }

    // Virtual destructor
    virtual ~TaskManager() {}
};

// Derived class for ExtendedTaskManager
class ExtendedTaskManager : public TaskManager {
public:
    // Function to display tasks sorted by priority
    void displayTasksByPriority() const {
        cout << "Tasks Sorted by Priority:\n";
        vector<Task> sortedTasks = tasks; // Create a copy of tasks for sorting
        sort(sortedTasks.begin(), sortedTasks.end(), [](const Task& a, const Task& b) {
            return static_cast<int>(a.priority) < static_cast<int>(b.priority);
        });

        for (const auto& task : sortedTasks) {
            cout << "Title: " << task.title 
                 << ", Description: " << task.description 
                 << ", Priority: " << getPriorityString(task.priority) 
                 << ", Status: " << (task.isCompleted ? "Completed" : "Pending") << endl;
        }
    }
};

int main() {
    // Create an instance of ExtendedTaskManager
    ExtendedTaskManager taskManager;

    // Add tasks to the task manager
    taskManager.addTask(Task("Finish report", "Complete the quarterly report", PriorityLevel::HIGH));
    taskManager.addTask(Task("Grocery shopping", "Buy groceries for the week", PriorityLevel::MEDIUM));
    taskManager.addTask(Task("Clean the house", "Do a thorough cleaning of the house", PriorityLevel::LOW));

    // Display all tasks
    taskManager.displayTasks();
    cout << endl;

    // Mark a task as completed
    taskManager.completeTask("Finish report");

    // Display all tasks after completing one
    taskManager.displayTasks();
    cout << endl;

    // Display tasks sorted by priority
    taskManager.displayTasksByPriority();

    return 0;
}