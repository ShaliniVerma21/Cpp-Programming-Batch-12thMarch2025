//5. Multithreading

#include <iostream>
#include <thread>
#include <chrono>
using namespace std;


void printMessage() {
    this_thread::sleep_for(chrono::seconds(2));
    cout << "Hello from thread!" << endl;
}

int main() {
    thread t(printMessage);
    t.join(); // Wait for the thread to finish
    cout << "Main thread finished." << endl;
    return 0;
}