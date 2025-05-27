// Program 2: Multiple Threads Running Together

#include <iostream>
#include <thread>
using namespace std;

void task1() {
    cout << "Task 1 is running..." << endl;
}

void task2() {
    cout << "Task 2 is running..." << endl;
}

int main() {
    thread t1(task1);
    thread t2(task2);

    t1.join();  // Wait for task1
    t2.join();  // Wait for task2

    cout << "Both tasks completed." << endl;

    return 0;
}
