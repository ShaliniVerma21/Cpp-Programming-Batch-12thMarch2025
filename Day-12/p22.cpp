//Robot Task Execution

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <algorithm> // For std::sort
#include <memory> // For smart pointers

using namespace std;

// Enumeration for task priority levels
enum class TaskPriority {
    LOW,
    MEDIUM,
    HIGH
};

// Structure for a task
struct Task {
    string name; // Name of the task
    TaskPriority priority; // Priority of the task
    int duration; // Duration of the task in seconds

    // Constructor for Task
    Task(const string& n, TaskPriority p, int d) 
        : name(n), priority(p), duration(d) {}
};

// Base class for Robot
class Robot {
protected:
    string name; // Name of the robot
    vector<Task> taskList; // List of tasks

public:
    // Constructor for Robot
    Robot(const string& n) : name(n) {}

    // Function to add a task to the robot's task list
    void addTask(const Task& task) {
        taskList.push_back(task);
    }

    // Function to execute tasks in order of priority
    void executeTasks() {
        // Sort tasks based on priority
        sort(taskList.begin(), taskList.end(), [](const Task& a, const Task& b) {
            return static_cast<int>(a.priority) < static_cast<int>(b.priority);
        });

        cout << "Executing tasks for " << name << ":\n";
        for (const auto& task : taskList) {
            cout << "Executing task: " << task.name 
                 << " with priority: " << getPriorityString(task.priority) 
                 << " for " << task.duration << " seconds." << endl;
            // Simulate task execution (in a real scenario, you might use sleep)
            for (int i = 0; i < task.duration; ++i) {
                cout << ".";
            }
            cout << " Done!" << endl;
        }
        taskList.clear(); // Clear the task list after execution
    }

    // Function to get string representation of task priority
    string getPriorityString(TaskPriority priority) const {
        switch (priority) {
            case TaskPriority::LOW: return "Low";
            case TaskPriority::MEDIUM: return "Medium";
            case TaskPriority::HIGH: return "High";
            default: return "Unknown";
        }
    }

    // Function to display the robot's status
    void displayStatus() const {
        cout << "Robot Name: " << name << endl;
        cout << "Number of tasks: " << taskList.size() << endl;
    }

    // Virtual destructor
    virtual ~Robot() {}
};

// Derived class for AdvancedRobot
class AdvancedRobot : public Robot {
public:
    // Constructor for AdvancedRobot
    AdvancedRobot(const string& n) : Robot(n) {}

    // Overriding executeTasks to include additional behavior
    void executeTasks() override {
        cout << "Advanced execution protocol initiated for " << name << ":\n";
        Robot::executeTasks(); // Call base class method
    }
};

// Main function to demonstrate the robot task execution system
int main() {
    // Create an advanced robot
    unique_ptr<Robot> robot = make_unique<AdvancedRobot>("TaskBot");

    // Add tasks to the robot
    robot->addTask(Task("Clean the floor", TaskPriority::MEDIUM, 5));
    robot->addTask(Task("Charge battery", TaskPriority::HIGH, 3));
    robot->addTask(Task("Check sensors", TaskPriority::LOW, 2));

    // Display robot status
    robot->displayStatus();

    // Execute tasks
    robot->executeTasks();

    return 0; // End of the program
}