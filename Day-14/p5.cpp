/*
Multithreading is a feature that allows a program to run multiple parts of code (called threads) 
at the same time. It improves performance by doing multiple tasks simultaneously.
In C++, multithreading is supported using the <thread> header, introduced in C++11.
Each thread can run a separate function. This is useful for tasks like downloading files, processing data, 
or running animations without stopping the main program.
*/

// Program 1: Basic Single Thread Example

#include <iostream>
#include <thread>
using namespace std;

void sayHello() {
    cout << "Hello from thread!" << endl;
}

int main() {
    
    // Creating a thread that runs sayHello()
    thread t1(sayHello);

    // Wait for the thread to finish
    t1.join();

    cout << "Main thread ends." << endl;

    return 0;
}
