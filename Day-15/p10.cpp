/*
Multithreading in C++ allows a program to perform multiple tasks concurrently by creating multiple threads 
of execution within a single process. Each thread can run independently, sharing the same memory space but 
having its own stack and local variables. This can lead to more efficient use of resources and improved 
performance, especially on multi-core processors.    

Key Concepts:

Thread: A lightweight process that can run concurrently with other threads.

Thread Creation: Threads can be created using the C++ Standard Library's <thread> header.

Synchronization: Mechanisms like mutexes, condition variables, and locks are used to manage access to shared 
resources and prevent data races.

Joining and Detaching: Threads can be joined (waiting for a thread to finish) or detached (running independently).    
*/

//1. Basic Thread Creation

#include <iostream>
#include <thread>

void printMessage() {
    std::cout << "Hello from thread!" << std::endl;
}

int main() {
    std::thread t(printMessage); // Create a new thread
    t.join(); // Wait for the thread to finish
    std::cout << "Thread has finished execution." << std::endl;
    return 0;
}